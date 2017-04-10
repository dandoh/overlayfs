
#include <linux/fs.h>
#include <linux/namei.h>
#include <linux/xattr.h>
#include <linux/security.h>
#include <linux/cred.h>
#include <linux/sched.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h> 
#include <linux/mount.h>
#include <linux/path.h>
#include "overlayfs.h"

char *path_name = "/cache/cache.tmp";
char *cache_dir = "/cache/";
char *path_test = "/cache/hhuhuhunonexist";

struct cache_filename {
	struct qstr name;
	struct list_head list;
};

int copy_upper_cache(struct dentry *parent_cache, 
		struct dentry *parent_upper, const unsigned char *name) {

	struct inode *parent_cache_inode = parent_cache->d_inode;
	struct dentry *upper_dentry;
	struct dentry *cache_dentry;
	printk("Name: %s \n", name);

	upper_dentry = lookup_one_len(name, parent_upper, strlen(name));
	cache_dentry = lookup_one_len(name, parent_cache, strlen(name));

	if (cache_dentry->d_inode) {
		printk("Exist before !!!!\n");
		return 0;
	} else {
		if (!upper_dentry->d_inode) {
			printk("Some errors occurred\n");
			return 1;
		}

		int err;
		struct path upper_path;
		struct kstat stat;
		
		ovl_path_upper(upper_dentry, &upper_path);
		err = vfs_getattr(&upper_path, &stat);
		if (err) {
			return err;
		}
		// COPY HERE - already had upper path
		switch (stat.mode & S_IFMT) {
			case S_IFREG:
				printk("FILE HERE: \n");
				err = vfs_create(parent_cache_inode, cache_dentry, stat.mode, true);
				if (err) {
					printk("Error calling vfs create file\n");
					return err;
				}
				break;

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

	return 0;
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
	struct dentry *current_parent_cache;
	struct dentry *cache_temp;

	// upper dentry
	struct dentry *current_parent_upper;
	struct dentry *upper_temp;

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

	current_parent_cache = cache_dentry;
	current_parent_upper = dentry;

	list_for_each(pos, &cache_filename_list) {
		const unsigned char *name;
		int err;
		entry = list_entry(pos, struct cache_filename, list);
		name = entry->name.name;

		err = copy_upper_cache(current_parent_cache, current_parent_upper, entry->name.name);
		if (err) {
			printk("Error copying to cache");
			return NULL;
		}

		current_parent_cache = lookup_one_len(name, current_parent_cache, strlen(name));
		current_parent_upper = lookup_one_len(name, current_parent_upper, strlen(name));
	}

	return 0;
}



struct inode *get_cache_inode(struct dentry *dentry, struct path *upper_path) {
	// copy the file in upper path to cache foler
	struct dentry *cache_dentry;
	struct dentry *result_dentry; // result after copy to cache 
	struct path path;
	int err;

	kern_path(path_name, LOOKUP_FOLLOW, &path);
	cache_dentry = path.dentry;

	result_dentry = copy_to_cache(dentry);
//	if (!result_dentry) {
//		return d_backing_inode(result_dentry);
//	} else {
//		return NULL;
//	}

	return d_backing_inode(cache_dentry);
}


