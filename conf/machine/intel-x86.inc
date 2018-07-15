#
# Copyright (C) 2017 Wind River Systems, Inc.
#

MACHINE_FEATURES += "x86 pci usbhost ext2 keyboard screen alsa acpi vfat serial"
MACHINE_FEATURES += "efi pcbios"
MACHINE_FEATURES += "parser shell-tools filesystem profile network"
DISTRO_FEATURES_append = " vfat wifi bluetooth pci"

MACHINE_EXTRA_RRECOMMENDS += "linux-firmware-iwlwifi-6000g2a-6"
MACHINE_EXTRA_RRECOMMENDS += "linux-firmware-iwlwifi-6000g2b-6"
MACHINE_EXTRA_RRECOMMENDS += "linux-firmware-iwlwifi-135-6"
MACHINE_EXTRA_RRECOMMENDS += "linux-firmware-bnx2-mips"
MACHINE_EXTRA_RRECOMMENDS += "linux-firmware-iwlwifi-8000c"
MACHINE_EXTRA_RRECOMMENDS += "linux-firmware-iwlwifi-8265"
MACHINE_EXTRA_RRECOMMENDS += "linux-firmware-radeon"
MACHINE_EXTRA_RRECOMMENDS += "linux-firmware-pcie8897"
MACHINE_EXTRA_RRECOMMENDS += "linux-firmware-iwlwifi-7265d"
MACHINE_EXTRA_RRECOMMENDS += "linux-firmware-i915"
MACHINE_EXTRA_RRECOMMENDS += "linux-firmware-ibt-12-16"
MACHINE_EXTRA_RRECOMMENDS += "linux-firmware-rtl8723"

# The diffutils which is runtime depended by grub needs
# eglibc to enable the following options.
DISTRO_FEATURES_LIBC_TINY_append = " libc-posix-clang-wchar \
                                     libc-locales \
                                     libc-locale-code \
"

KERNEL_IMAGETYPE = "bzImage"

SERIAL_CONSOLES = "115200;ttyS0 115200;ttyUSB0"

MACHINEOVERRIDES_append = ":intel-x86"

# xserver-common, xserver-nodm-init
VIRTUAL-RUNTIME_xserver_common ?= "xserver-nodm-init"

# xserver-nodm-init, anaconda-init
VIRTUAL-RUNTIME_graphical_init_manager ?= "xserver-nodm-init"

XSERVER ?= "xserver-xorg \
	   xserver-xorg-extension-dri \
	   xserver-xorg-extension-dri2 \
	   xserver-xorg-extension-glx \
	   xserver-xorg-extension-extmod \
	   xserver-xorg-extension-dbe \
	   xserver-xorg-module-libint10 \
	   ${VIRTUAL-RUNTIME_graphical_init_manager} \
	   xf86-input-mouse \
	   xf86-input-keyboard \
	   xf86-input-evdev \
	   xf86-input-synaptics \
	   xf86-video-vesa \
	   xf86-video-fbdev \
	   xf86-video-intel \
	   xf86-video-mga \
	   xf86-video-modesetting \
	   xf86-video-ati \
	   mesa \
	   mesa-driver-i915 \
	   mesa-driver-i965 \
	   mesa-driver-swrast \
	   mesa-demos \
	   ${VIRTUAL-RUNTIME_xserver_common} \
	   matchbox-wm"

PREFERRED_PROVIDER_libglu = "libglu"
PREFERRED_VERSION_virtual/mesa = "17.1.5"

PREFERRED_VERSION_linux-yocto ?= "4.12%"
PREFERRED_VERSION_grub-efi ?= "2.02"

PREFERRED_VERSION_autoconf-archive ?= "2016.09.16"

TARGET_QEMU_BIN = "qemu-system-x86_64"
TARGET_QEMU_KERNEL="bzImage"
TARGET_QEMU_KERNEL_OPTS="selinux=0 enforcing=0"
TARGET_QEMU_ENET_MODEL="i82557b"
TARGET_QEMU_BOOT_CONSOLE="ttyS0,115200"
TARGET_QEMU_OPTS="-show-cursor -usb -usbdevice wacom-tablet -vga vmware"
TARGET_QEMU_CPU="Nehalem"

IMAGE_FSTYPES += "wic wic.bmap live"
WKS_FILE ?= "mkefidisk.wks"
do_image_wic[depends] += "gptfdisk-native:do_populate_sysroot"
do_image_wic[recrdeptask] += "do_bootimg"