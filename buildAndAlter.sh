echo "Calling build"
make -C /lib/modules/$(uname -r)/build M=$(pwd) modules
#alter the module
cp overlay.ko /lib/modules/4.4.0-64-generic/kernel/fs/overlayfs/
ls -l /lib/modules/4.4.0-64-generic/kernel/fs/overlayfs/
