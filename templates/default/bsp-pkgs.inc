IMAGE_INSTALL += "iucode-tool"
IMAGE_INSTALL += "intel-microcode"
IMAGE_INSTALL += "rtl8723bs-bt"

IMAGE_INSTALL += "${@bb.utils.contains('INCOMPATIBLE_LICENSE', 'GPLv3', '', 'grub-efi', d)}"
