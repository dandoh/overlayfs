
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


int test(struct dentry *dentry) {
	// list of name
	struct list_head *pos;
	struct cache_filename *entry;
	LIST_HEAD(cache_filename_list);

	// dentry, path and inode of cache directory
	struct dentry *cache_dentry;
	struct inode *cache_inode;
	struct path cache_path;

	struct dentry *current_parent_dir;
	struct dentry *temp;

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

	current_parent_dir = cache_dentry;

	list_for_each(pos, &cache_filename_list) {
		entry = list_entry(pos, struct cache_filename, list);
		printk("File name: %s \n", entry->name.name);
	}


	return 0;
}



struct inode *get_cache_inode(struct dentry *dentry, struct path *upper_path) {
	// copy the file in upper path to cache foler
	struct dentry *cache_dentry;
	struct path path;

	kern_path(path_name, LOOKUP_FOLLOW, &path);
	cache_dentry = path.dentry;
	test(dentry);

	return d_backing_inode(cache_dentry);
}



int ovl_cache_existed(struct dentry *dentry) {
	return 0;
}
//
//static int ovl_copy_cache_truncate(struct path *upper_path)
//{
//	int err;
//	struct dentry *parent;
//	struct kstat stat;
//	struct path lowerpath;
//	struct dentry *dentry;
//
//	dentry = path->dentry;
//
//	printk("--------Start ovl_copy_cache_truncate-------\n");
//	print_dentry_info(dentry);
//	parent = dget_parent(dentry);
//	err = ovl_copy_cache(parent);
//	if (err)
//		goto out_dput_parent;
//
//	ovl_path_lower(dentry, &lowerpath);
//	err = vfs_getattr(&lowerpath, &stat);
//	if (err)
//		goto out_dput_parent;
//
//	stat.size = 0;
//	err = ovl_copy_up_one(parent, dentry, &lowerpath, &stat);
//
//	printk("--------End ovl_copy_up_truncate-------\n");
//out_dput_parent:
//	dput(parent);
//	return err;
//}
//
//
//int ovl_copy_cache(struct dentry *dentry)
//{
//	
//	int err;
//
//	err = 0;
//	while (!err) {
//		struct dentry *next;
//		struct dentry *parent;
//		struct path lowerpath;
//		struct kstat stat;
//		enum ovl_path_type type = ovl_path_type(dentry);
//
//		if (OVL_TYPE_UPPER(type))
//			break;
//
//		next = dget(dentry);
//		printk("Next dentry info: \n");
//		print_dentry_info(next);
//		/* find the topmost dentry not yet copied up */
//		for (;;) {
//			parent = dget_parent(next);
//
//			type = ovl_path_type(parent);
//			if (OVL_TYPE_UPPER(type))
//				break;
//
//			dput(next);
//			next = parent;
//		}
//
//		printk("Next after the for loop: \n");
//		print_dentry_info(next);
//		printk("Parent after the for loop: \n");
//		print_dentry_info(parent);
//
//		ovl_path_lower(next, &lowerpath);
//		printk("Lower path: \n");
//		print_path_info(&lowerpath);
//		err = vfs_getattr(&lowerpath, &stat);
//		if (!err)
//			err = ovl_copy_up_one(parent, next, &lowerpath, &stat);
//		
//		dput(parent);
//		dput(next);
//	}
//
//	printk("---------------End calling copy_up ----------------\n");
//	return err;
//}
