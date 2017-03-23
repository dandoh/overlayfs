#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x9d35aeec, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xe3b958da, __VMLINUX_SYMBOL_STR(vfs_create) },
	{ 0x3356b90b, __VMLINUX_SYMBOL_STR(cpu_tss) },
	{ 0x8a9809d6, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0xd5cb3294, __VMLINUX_SYMBOL_STR(d_invalidate) },
	{ 0x349cba85, __VMLINUX_SYMBOL_STR(strchr) },
	{ 0xa6533a8e, __VMLINUX_SYMBOL_STR(inode_permission) },
	{ 0x754d539c, __VMLINUX_SYMBOL_STR(strlen) },
	{ 0xdb63fede, __VMLINUX_SYMBOL_STR(kill_anon_super) },
	{ 0x6d2a62c5, __VMLINUX_SYMBOL_STR(dget_parent) },
	{ 0xb73df048, __VMLINUX_SYMBOL_STR(vfs_link) },
	{ 0x19f462ab, __VMLINUX_SYMBOL_STR(kfree_call_rcu) },
	{ 0x2adb3a2, __VMLINUX_SYMBOL_STR(seq_escape) },
	{ 0x19e9ef91, __VMLINUX_SYMBOL_STR(generic_file_open) },
	{ 0xacf4d843, __VMLINUX_SYMBOL_STR(match_strdup) },
	{ 0xa8a6e6b3, __VMLINUX_SYMBOL_STR(vfs_llseek) },
	{ 0x18a778e7, __VMLINUX_SYMBOL_STR(touch_atime) },
	{ 0x555f6938, __VMLINUX_SYMBOL_STR(lockref_get) },
	{ 0x43a99fa, __VMLINUX_SYMBOL_STR(dput) },
	{ 0x44b1d426, __VMLINUX_SYMBOL_STR(__dynamic_pr_debug) },
	{ 0x44e9a829, __VMLINUX_SYMBOL_STR(match_token) },
	{ 0x7a360ad8, __VMLINUX_SYMBOL_STR(dentry_open) },
	{ 0x1551f51e, __VMLINUX_SYMBOL_STR(vfs_mknod) },
	{ 0x347cd1b3, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0x1de7a8c1, __VMLINUX_SYMBOL_STR(generic_read_dir) },
	{ 0xd869ebdf, __VMLINUX_SYMBOL_STR(vfs_symlink) },
	{ 0xca5dbd74, __VMLINUX_SYMBOL_STR(mount_nodev) },
	{ 0xbc2f321, __VMLINUX_SYMBOL_STR(override_creds) },
	{ 0xc499ae1e, __VMLINUX_SYMBOL_STR(kstrdup) },
	{ 0xf70bd105, __VMLINUX_SYMBOL_STR(mnt_drop_write) },
	{ 0xc915e44, __VMLINUX_SYMBOL_STR(mutex_lock_killable) },
	{ 0x5dbc5bab, __VMLINUX_SYMBOL_STR(vfs_rmdir) },
	{ 0x53c53395, __VMLINUX_SYMBOL_STR(unlock_rename) },
	{ 0xa516fe25, __VMLINUX_SYMBOL_STR(vfs_read) },
	{ 0x406eaf61, __VMLINUX_SYMBOL_STR(kern_path) },
	{ 0x298f5f9, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xde8fc64e, __VMLINUX_SYMBOL_STR(d_rehash) },
	{ 0xc9e7bd28, __VMLINUX_SYMBOL_STR(vfs_getxattr) },
	{ 0x293bf018, __VMLINUX_SYMBOL_STR(seq_putc) },
	{ 0x5a921311, __VMLINUX_SYMBOL_STR(strncmp) },
	{ 0x1d0a4cc5, __VMLINUX_SYMBOL_STR(lock_rename) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0x11761f56, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0xff192af5, __VMLINUX_SYMBOL_STR(vfs_whiteout) },
	{ 0x5b27c950, __VMLINUX_SYMBOL_STR(fput) },
	{ 0x270b54e4, __VMLINUX_SYMBOL_STR(prepare_creds) },
	{ 0x61651be, __VMLINUX_SYMBOL_STR(strcat) },
	{ 0x68f28ee3, __VMLINUX_SYMBOL_STR(mntput) },
	{ 0x26cff1af, __VMLINUX_SYMBOL_STR(__check_sticky) },
	{ 0x9f2ef8d3, __VMLINUX_SYMBOL_STR(mnt_want_write) },
	{ 0x93fca811, __VMLINUX_SYMBOL_STR(__get_free_pages) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x7233ff8c, __VMLINUX_SYMBOL_STR(d_drop) },
	{ 0xb829ad49, __VMLINUX_SYMBOL_STR(vfs_statfs) },
	{ 0x73b1d978, __VMLINUX_SYMBOL_STR(vfs_mkdir) },
	{ 0xbb827957, __VMLINUX_SYMBOL_STR(__put_cred) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0x4196425b, __VMLINUX_SYMBOL_STR(inode_change_ok) },
	{ 0xcdbc8c90, __VMLINUX_SYMBOL_STR(path_put) },
	{ 0x2142697b, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xa5526619, __VMLINUX_SYMBOL_STR(rb_insert_color) },
	{ 0x8c0e156d, __VMLINUX_SYMBOL_STR(vfs_unlink) },
	{ 0x7a5682ba, __VMLINUX_SYMBOL_STR(register_filesystem) },
	{ 0x4302d0eb, __VMLINUX_SYMBOL_STR(free_pages) },
	{ 0x5cb7b1f9, __VMLINUX_SYMBOL_STR(do_splice_direct) },
	{ 0x1e047854, __VMLINUX_SYMBOL_STR(warn_slowpath_fmt) },
	{ 0xe953b21f, __VMLINUX_SYMBOL_STR(get_next_ino) },
	{ 0x8e598014, __VMLINUX_SYMBOL_STR(iput) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xbf63a21b, __VMLINUX_SYMBOL_STR(d_find_any_alias) },
	{ 0x69acdf38, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0xcbdd854e, __VMLINUX_SYMBOL_STR(__inode_permission) },
	{ 0x12852158, __VMLINUX_SYMBOL_STR(clone_cred) },
	{ 0x6f9df6d3, __VMLINUX_SYMBOL_STR(d_make_root) },
	{ 0x1d9e013, __VMLINUX_SYMBOL_STR(iterate_dir) },
	{ 0x55e8908c, __VMLINUX_SYMBOL_STR(unregister_filesystem) },
	{ 0x28318305, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0x3480fd6e, __VMLINUX_SYMBOL_STR(new_inode) },
	{ 0xb0e602eb, __VMLINUX_SYMBOL_STR(memmove) },
	{ 0xcfad3126, __VMLINUX_SYMBOL_STR(lookup_one_len) },
	{ 0x2780cc19, __VMLINUX_SYMBOL_STR(clone_private_mount) },
	{ 0x495f17d7, __VMLINUX_SYMBOL_STR(vfs_rename) },
	{ 0x5bd9080d, __VMLINUX_SYMBOL_STR(vfs_getattr) },
	{ 0xb16bf486, __VMLINUX_SYMBOL_STR(notify_change) },
	{ 0xdbf2c531, __VMLINUX_SYMBOL_STR(vfs_setxattr) },
	{ 0x99800ef2, __VMLINUX_SYMBOL_STR(d_instantiate) },
	{ 0xcca10cd, __VMLINUX_SYMBOL_STR(revert_creds) },
	{ 0xef89a24b, __VMLINUX_SYMBOL_STR(vfs_listxattr) },
	{ 0x4f6ec3fe, __VMLINUX_SYMBOL_STR(vfs_removexattr) },
	{ 0xffaa0d10, __VMLINUX_SYMBOL_STR(vfs_write) },
	{ 0xb49d850c, __VMLINUX_SYMBOL_STR(vfs_fsync_range) },
	{ 0x7c2d098f, __VMLINUX_SYMBOL_STR(krealloc) },
	{ 0xe914e41e, __VMLINUX_SYMBOL_STR(strcpy) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "B00B8FFD8AC95BC69B45245");
