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
	printk("Inode operation pointer : Read: %p Write: %p\n", inode->i_fop->read,
			inode->i_fop->read);
}
void print_dentry_info(struct dentry *dentry) {
	const char *parent_name = dentry->d_parent->d_name.name;
	const char *name = dentry->d_name.name;

	printk("Entry path = %s/%s \n", parent_name, name);
}
