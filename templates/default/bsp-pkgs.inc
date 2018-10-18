IMAGE_INSTALL += "microcode-ctl"
IMAGE_INSTALL += "rtl8723bs-bt"

IMAGE_INSTALL += "${@bb.utils.contains('INCOMPATIBLE_LICENSE', 'GPLv3', '', 'grub-efi', d)}"
