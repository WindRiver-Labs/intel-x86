WKS_FILE = "intel-x86-mkefidisk.wks"

# We need rootfs.img as the source of rootfs.
do_add_rootfs_img () {
    install -m 0644 ${ROOTFS} ${IMAGE_ROOTFS}/rootfs.img
}
addtask add_rootfs_img after do_bootimg before do_image_wic

# Remove rootfs.img after packing it into wic image.
# Don't contaminate the original rootfs.
do_delete_rootfs_img () {
    rm -f ${IMAGE_ROOTFS}/rootfs.img
}
addtask delete_rootfs_img after do_image_wic before do_image_complete

IMAGE_BOOT_FILES = "bzImage \
                    ${INITRD_IMAGE_LIVE}-${MACHINE}.${INITRAMFS_FSTYPES};initrd \
                    grub.cfg;EFI/BOOT/grub.cfg"

IMAGE_BOOT_FILES_append_intel-x86-32 = " grub-efi-bootia32.efi;EFI/BOOT/bootia32.efi"
IMAGE_BOOT_FILES_append_intel-x86-64 = " grub-efi-bootx64.efi;EFI/BOOT/bootx64.efi"
