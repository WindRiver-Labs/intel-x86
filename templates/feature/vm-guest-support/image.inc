IMAGE_INSTALL_append = " ${@bb.utils.contains('DISTRO_FEATURES', 'x11', 'xf86-video-vmware xf86-input-vmmouse', '', d)}"
