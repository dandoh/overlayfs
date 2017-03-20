#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/namei.h>
#include <linux/file.h>
#include <linux/xattr.h>
#include <linux/rbtree.h>
#include <linux/security.h>
#include <linux/sched.h>
#include <linux/cred.h>
#include "overlayfs.h"

char *concat(const char *s1, const char *s2) {
	char *result = kmalloc(strlen(s1)+strlen(s2)+1, GFP_KERNEL);//+1 for the zero-terminator
	strcpy(result, s1);
	strcat(result, s2);
	return result;
}

struct inode *an_inode;

void print_functor_inode(struct inode *inode) {
	printk("Inode operation pointer : read: %p write: %p read_iter %p write_iter %p\n", inode->i_fop->read,
			inode->i_fop->write, 
			inode->i_fop->read_iter,
			inode->i_fop->write_iter);
}
void print_dentry_info(struct dentry *dentry) {
	if (dentry) {
		struct dentry *parent = dentry->d_parent;
		struct dentry *grand_parent = parent->d_parent;
		struct dentry *grand_grand_parent = grand_parent->d_parent;
		const char *grand_grand_parent_name = grand_grand_parent->d_name.name;
		const char *grand_parent_name = grand_parent->d_name.name;
		const char *parent_name = parent->d_name.name;
		const char *name = dentry->d_name.name;
	
		printk("Entry path = %s/%s/%s/%s \n", grand_grand_parent_name, grand_parent_name, 
				parent_name, name);

	} else {
		printk("NULL \n");
	}
}

void print_path_info(struct path *path) {
	if (path) {
		print_dentry_info(path->dentry);
	}
}
