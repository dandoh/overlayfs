echo "Calling build"
make -C /lib/modules/$(uname -r)/build M=$(pwd) modules
#alter the module
cp overlay.ko /lib/modules/$(uname -r)/kernel/fs/overlayfs/
ls -l /lib/modules/$(uname -r)/kernel/fs/overlayfs/
