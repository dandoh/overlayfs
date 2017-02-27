/*
 *
 * Copyright (C) 2011 Novell Inc.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by
 * the Free Software Foundation.
 */

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




ssize_t ovl_read(struct file *file, char __user *user, size_t size, loff_t *loff_t) {
	printk("calling read file\n");
	return vfs_read(file, user, size, loff_t);	
}

ssize_t ovl_write(struct file *file, const char __user *user, size_t size, loff_t *loff_t) {
	printk("Calling write\n");
	return vfs_write(file, user, size, loff_t);
}


int ovl_open(struct inode *inode, struct file *file) {
	printk("Calling open file\n");
	return generic_file_open(inode, file);
}

const struct file_operations ovl_file_operations = {
	.read		= ovl_read,
	.write = ovl_write,
	.open = ovl_open,
};
//ssize_t ovl_read_iter(struct kiocb *kiocb, struct iov_iter *iov_iter){
//	printk("Calling read iter\n");
//	return vfs_read_iter(kiocb, iov_iter);
//}
//ssize_t ovl_write_iter(struct kiocb *kiocb, struct iov_iter *iov_iter){
//	printk("Calling write iter\n");
//	return vfs_write_iter(kiocb, iov_iter);
//}
// ssize_t (*write) (struct file *, const char __user *, size_t, loff_t *);
// ssize_t ovl_read(struct file *, char __user *, size_t, loff_t *);
//ssize_t ovl_read_iter(struct kiocb *, struct iov_iter *);
//ssize_t ovl_write_iter(struct kiocb *, struct iov_iter *);
