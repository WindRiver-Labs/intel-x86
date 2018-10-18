COMPATIBLE_MACHINE_intel-x86-64 = "intel-x86-64"
COMPATIBLE_MACHINE_intel-x86-32 = "intel-x86-32"
COMPATIBLE_MACHINE_intel-broadwell-64 = "intel-broadwell-64"
COMPATIBLE_MACHINE_intel-broadwell-32 = "intel-broadwell-32"
COMPATIBLE_MACHINE_intel-haswell-64 = "intel-haswell-64"
COMPATIBLE_MACHINE_intel-haswell-32 = "intel-haswell-32"
COMPATIBLE_MACHINE_intel-kabylake-64 = "intel-kabylake-64"
COMPATIBLE_MACHINE_intel-kabylake-32 = "intel-kabylake-32"
COMPATIBLE_MACHINE_intel-skylake-64 = "intel-skylake-64"
COMPATIBLE_MACHINE_intel-skylake-32 = "intel-skylake-32"
COMPATIBLE_MACHINE_intel-skylake-avx512-64 = "intel-skylake-avx512-64"
COMPATIBLE_MACHINE_intel-skylake-avx512-32 = "intel-skylake-avx512-32"
COMPATIBLE_MACHINE_intel-vmware-guest-64 = "intel-vmware-guest-64"
COMPATIBLE_MACHINE_intel-vmware-guest-32 = "intel-vmware-guest-32"

#
#
#add the depends of cdrtools-native to make sure it is
#always built to support the usb-image & iso-image UEFI
#booting by default  without explicitly add the configure
#option of "--enable-bootimage=iso"

DEPENDS_append_intel-x86-64 = " cdrtools-native"
DEPENDS_append_intel-x86-32 = " cdrtools-native"

# A method to install/update for bzImage on a deployed target
KERNELLOADEREXTENSION_append_intel-x86-64 = " kernel-grub"
KERNELLOADEREXTENSION_append_intel-x86-32 = " kernel-grub"

do_install_append_intel-x86() {
	rm -rf ${D}/lib/modules/${KERNEL_VERSION}/kernel/drivers/crypto
}

