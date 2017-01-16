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
	{ 0xc6c01fa, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x374c18ab, __VMLINUX_SYMBOL_STR(vfs_create) },
	{ 0x3356b90b, __VMLINUX_SYMBOL_STR(cpu_tss) },
	{ 0x92a94ad2, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0xbf556e26, __VMLINUX_SYMBOL_STR(d_invalidate) },
	{ 0x349cba85, __VMLINUX_SYMBOL_STR(strchr) },
	{ 0x4cdbe1d3, __VMLINUX_SYMBOL_STR(inode_permission) },
	{ 0x754d539c, __VMLINUX_SYMBOL_STR(strlen) },
	{ 0xa31137d5, __VMLINUX_SYMBOL_STR(kill_anon_super) },
	{ 0x71c575f9, __VMLINUX_SYMBOL_STR(dget_parent) },
	{ 0x4516a674, __VMLINUX_SYMBOL_STR(vfs_link) },
	{ 0x19f462ab, __VMLINUX_SYMBOL_STR(kfree_call_rcu) },
	{ 0x2adb3a2, __VMLINUX_SYMBOL_STR(seq_escape) },
	{ 0xacf4d843, __VMLINUX_SYMBOL_STR(match_strdup) },
	{ 0xfc825863, __VMLINUX_SYMBOL_STR(vfs_llseek) },
	{ 0xbe2f9314, __VMLINUX_SYMBOL_STR(touch_atime) },
	{ 0x555f6938, __VMLINUX_SYMBOL_STR(lockref_get) },
	{ 0x8119ae28, __VMLINUX_SYMBOL_STR(dput) },
	{ 0x44b1d426, __VMLINUX_SYMBOL_STR(__dynamic_pr_debug) },
	{ 0x44e9a829, __VMLINUX_SYMBOL_STR(match_token) },
	{ 0x55daa0d7, __VMLINUX_SYMBOL_STR(dentry_open) },
	{ 0xa6fb6dd8, __VMLINUX_SYMBOL_STR(vfs_mknod) },
	{ 0x7d9cc03b, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0xae0b907, __VMLINUX_SYMBOL_STR(generic_read_dir) },
	{ 0x400b9254, __VMLINUX_SYMBOL_STR(vfs_symlink) },
	{ 0x8dbcd607, __VMLINUX_SYMBOL_STR(mount_nodev) },
	{ 0x7851fbda, __VMLINUX_SYMBOL_STR(override_creds) },
	{ 0xc499ae1e, __VMLINUX_SYMBOL_STR(kstrdup) },
	{ 0x547d3bf8, __VMLINUX_SYMBOL_STR(mnt_drop_write) },
	{ 0x352842aa, __VMLINUX_SYMBOL_STR(mutex_lock_killable) },
	{ 0x2c7e0dad, __VMLINUX_SYMBOL_STR(vfs_rmdir) },
	{ 0x88bc711d, __VMLINUX_SYMBOL_STR(unlock_rename) },
	{ 0xd0dfa012, __VMLINUX_SYMBOL_STR(kern_path) },
	{ 0x391afe42, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xb07b10bb, __VMLINUX_SYMBOL_STR(d_rehash) },
	{ 0x7cc82317, __VMLINUX_SYMBOL_STR(vfs_getxattr) },
	{ 0x293bf018, __VMLINUX_SYMBOL_STR(seq_putc) },
	{ 0x5a921311, __VMLINUX_SYMBOL_STR(strncmp) },
	{ 0x69636a52, __VMLINUX_SYMBOL_STR(lock_rename) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0xbf97e500, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x55bf8d94, __VMLINUX_SYMBOL_STR(vfs_whiteout) },
	{ 0x9e2c81e8, __VMLINUX_SYMBOL_STR(fput) },
	{ 0x721db075, __VMLINUX_SYMBOL_STR(prepare_creds) },
	{ 0xdc56ec04, __VMLINUX_SYMBOL_STR(mntput) },
	{ 0xca7a05a1, __VMLINUX_SYMBOL_STR(__check_sticky) },
	{ 0x6bf3b471, __VMLINUX_SYMBOL_STR(mnt_want_write) },
	{ 0x93fca811, __VMLINUX_SYMBOL_STR(__get_free_pages) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0xf129bace, __VMLINUX_SYMBOL_STR(d_drop) },
	{ 0x62b17a5b, __VMLINUX_SYMBOL_STR(vfs_statfs) },
	{ 0x1f499769, __VMLINUX_SYMBOL_STR(vfs_mkdir) },
	{ 0xf7dd658, __VMLINUX_SYMBOL_STR(__put_cred) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0x9c5c9ea7, __VMLINUX_SYMBOL_STR(inode_change_ok) },
	{ 0x2fb290d3, __VMLINUX_SYMBOL_STR(path_put) },
	{ 0x81fcd7c8, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xa5526619, __VMLINUX_SYMBOL_STR(rb_insert_color) },
	{ 0xdcc424d8, __VMLINUX_SYMBOL_STR(vfs_unlink) },
	{ 0x62d96dc6, __VMLINUX_SYMBOL_STR(register_filesystem) },
	{ 0x4302d0eb, __VMLINUX_SYMBOL_STR(free_pages) },
	{ 0xb1e85022, __VMLINUX_SYMBOL_STR(do_splice_direct) },
	{ 0x1e047854, __VMLINUX_SYMBOL_STR(warn_slowpath_fmt) },
	{ 0xe953b21f, __VMLINUX_SYMBOL_STR(get_next_ino) },
	{ 0x5a72c214, __VMLINUX_SYMBOL_STR(iput) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xd110e39b, __VMLINUX_SYMBOL_STR(d_find_any_alias) },
	{ 0x69acdf38, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0xe8b1855a, __VMLINUX_SYMBOL_STR(__inode_permission) },
	{ 0x6066ca98, __VMLINUX_SYMBOL_STR(clone_cred) },
	{ 0xeceba882, __VMLINUX_SYMBOL_STR(d_make_root) },
	{ 0xddff0378, __VMLINUX_SYMBOL_STR(iterate_dir) },
	{ 0x920623bd, __VMLINUX_SYMBOL_STR(unregister_filesystem) },
	{ 0x28318305, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0xabc7ed6, __VMLINUX_SYMBOL_STR(new_inode) },
	{ 0xb0e602eb, __VMLINUX_SYMBOL_STR(memmove) },
	{ 0x9499b57c, __VMLINUX_SYMBOL_STR(lookup_one_len) },
	{ 0x25113712, __VMLINUX_SYMBOL_STR(clone_private_mount) },
	{ 0x73a36b46, __VMLINUX_SYMBOL_STR(vfs_rename) },
	{ 0x59328e79, __VMLINUX_SYMBOL_STR(vfs_getattr) },
	{ 0x86e18539, __VMLINUX_SYMBOL_STR(notify_change) },
	{ 0x6f420714, __VMLINUX_SYMBOL_STR(vfs_setxattr) },
	{ 0xe716c351, __VMLINUX_SYMBOL_STR(d_instantiate) },
	{ 0x9c6ad395, __VMLINUX_SYMBOL_STR(revert_creds) },
	{ 0xdcb84fcc, __VMLINUX_SYMBOL_STR(vfs_listxattr) },
	{ 0x8ddc7ee1, __VMLINUX_SYMBOL_STR(vfs_removexattr) },
	{ 0x4c101f8b, __VMLINUX_SYMBOL_STR(vfs_fsync_range) },
	{ 0x7c2d098f, __VMLINUX_SYMBOL_STR(krealloc) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "0B3D6723476322D2ADDC9B2");
