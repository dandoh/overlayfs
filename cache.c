
#include <linux/fs.h>
#include <linux/namei.h>
#include <linux/xattr.h>
#include <linux/security.h>
#include <linux/splice.h>
#include <linux/file.h>
#include <linux/uaccess.h>
#include <linux/cred.h>
#include <linux/sched.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h> 
#include <linux/mount.h>
#include <linux/path.h>
#include <linux/slab.h>
#include "overlayfs.h"

#define OVL_COPY_UP_CHUNK_SIZE (1 << 20)

char *path_name = "/cache/cache.tmp";
char *cache_dir = "/cache/";
char *path_test = "/cache/hhuhuhunonexist";

struct cache_filename {
	struct qstr name;
	struct list_head list;
};

int copy_data_cache(struct path *upper, struct path *cache, loff_t len) {
	struct file *upper_file;
	struct file *cache_file;
	loff_t upper_pos = 0;
	loff_t cache_pos = 0;
	int error = 0;

	printk("upper path:\n");
	print_path_info(upper);
	printk("cache path:\n");
	print_path_info(cache);
	if (len == 0)
		return 0;

	upper_file = dentry_open(upper, O_LARGEFILE | O_RDONLY, current_cred());
	if (IS_ERR(upper_file))
		return PTR_ERR(upper_file);

	cache_file = dentry_open(cache, O_LARGEFILE | O_WRONLY, current_cred());
	if (IS_ERR(cache_file)) {
		error = PTR_ERR(cache_file);
		goto out_fput;
	}

	while (len) {
		size_t this_len = OVL_COPY_UP_CHUNK_SIZE;
		long bytes;

		if (len < this_len)
			this_len = len;

		if (signal_pending_state(TASK_KILLABLE, current)) {
			error = -EINTR;
			break;
		}

		bytes = do_splice_direct(upper_file, &upper_pos,
					 cache_file, &cache_pos,
					 this_len, SPLICE_F_MOVE);
		if (bytes <= 0) {
			error = bytes;
			break;
		}
		WARN_ON(upper_pos != cache_pos);

		len -= bytes;
	}

	fput(cache_file);
out_fput:
	fput(upper_file);
	return error;
}

int copy_upper_cache(struct dentry *parent_cache, 
		struct dentry *parent_upper, const unsigned char *name) {

	struct inode *parent_cache_inode = parent_cache->d_inode;
	struct dentry *upper_dentry;
	struct dentry *cache_dentry;
	int err = 0;
	printk("Name: %s \n", name);

	upper_dentry = lookup_one_len(name, parent_upper, strlen(name));
	cache_dentry = lookup_one_len(name, parent_cache, strlen(name));

	if (cache_dentry->d_inode) {
		printk("Exist before !!!!\n");
		return 0;
	} else {

		struct path upper_path;
		struct path cache_path;
		struct kstat stat;

		if (!upper_dentry->d_inode) {
			printk("Some errors occurred\n");
			return 1;
		}
		
		ovl_path_upper(upper_dentry, &upper_path);
		err = vfs_getattr(&upper_path, &stat);
		if (err) {
			return err;
		}
		// COPY HERE - already had upper path
		switch (stat.mode & S_IFMT) {
			case S_IFREG: {
				int buff_len = 200;
				char buff[buff_len];
				char *cache_path_str;

				printk("FILE HERE: \n");
				err = vfs_create(parent_cache_inode, cache_dentry, stat.mode, true);
				if (err) {
					printk("Error calling vfs create file\n");
					return err;
				}

 				cache_path_str = dentry_path_raw(cache_dentry, buff, buff_len);
				kern_path(cache_path_str, LOOKUP_FOLLOW, &cache_path);

				copy_data_cache(&upper_path, &cache_path, stat.size);
				
				break;
			}
			case S_IFDIR:
				err = vfs_mkdir(parent_cache_inode, cache_dentry, stat.mode);
				if (err) {
					printk("Error calling vfs make dir\n");
					return err;
				}
				break;
				
			default:
				return 1;
		}
	}

	return err;
}

/**
 * Copy file to cache
 * dentry: dentry of folder in the upper layer
 */
struct dentry *copy_to_cache(struct dentry *dentry) {
	// list of name
	struct list_head *pos;
	struct cache_filename *entry;
	LIST_HEAD(cache_filename_list);

	// dentry, path and inode of cache directory
	struct dentry *cache_dentry;
	struct inode *cache_inode;
	struct path cache_path;

	// cache dentry
	struct dentry *current_cache;

	// upper dentry
	struct dentry *current_upper;

	printk("\n");
	while (dentry->d_parent != dentry) {
		// create new cache_filename
		struct cache_filename *fn = kmalloc(sizeof(struct cache_filename), GFP_KERNEL);
		fn->name = dentry->d_name;
		INIT_LIST_HEAD(&fn->list);

		// append front
		list_add(&fn->list, &cache_filename_list);
		dentry = dentry->d_parent;
	}

	kern_path(cache_dir, LOOKUP_FOLLOW, &cache_path);
	cache_dentry = cache_path.dentry;
	cache_inode = cache_dentry->d_inode;

	current_cache = cache_dentry;
	current_upper = dentry;

	list_for_each(pos, &cache_filename_list) {
		const unsigned char *name;
		int err;
		entry = list_entry(pos, struct cache_filename, list);
		name = entry->name.name;

		err = copy_upper_cache(current_cache, current_upper, entry->name.name);
		if (err) {
			printk("Error copying to cache");
			return NULL;
		}

		current_cache = lookup_one_len(name, current_cache, strlen(name));
		current_upper = lookup_one_len(name, current_upper, strlen(name));
	}

	return current_cache;
}



struct inode *get_cache_inode(struct dentry *dentry) {
	struct dentry *result_dentry; // result after copy to cache 
	result_dentry = copy_to_cache(dentry);

	if (result_dentry) {
		return result_dentry->d_inode;
	} else {
		return NULL;
	}
}




