
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
			printk("ERRRRRRRRRRRRRRRORRRRRRRRRRRRRRRRRRRRR\n");
			return 1;
		}

		int err;
		struct path upper_path;
		struct kstat stat;
		
		ovl_path_upper(upper_dentry, &upper_path);
	//	upper_path_name = dentry_path_raw(upper_dentry, buff, 200);
	//	printk("name of path: %s\n", path_name);
	//	kern_path(upper_path_name, LOOKUP_FOLLOW, &upper_path);

		printk("here here here den day roi \n");
		// COPY HERE - already had upper path
		err = vfs_getattr(&upper_path, &stat);
	}

	return 0;
}

/**
 * Copy folder to cache
 * dentry: dentry of folder in the upper layer
 */
int test(struct dentry *dentry) {
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
		entry = list_entry(pos, struct cache_filename, list);
		name = entry->name.name;

		copy_upper_cache(current_parent_cache, current_parent_upper, entry->name.name);

		current_parent_cache = lookup_one_len(name, current_parent_cache, strlen(name));
		current_parent_upper = lookup_one_len(name, current_parent_upper, strlen(name));
	}


	return 0;
}



struct inode *get_cache_inode(struct dentry *dentry, struct path *upper_path) {
	// copy the file in upper path to cache foler
	struct dentry *cache_dentry;
	struct path path;

	kern_path(path_name, LOOKUP_FOLLOW, &path);
	cache_dentry = path.dentry;
	test(dentry->d_parent);

	return d_backing_inode(cache_dentry);
}


