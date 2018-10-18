#
# Copyright (C) 2017 Wind River Systems, Inc.
#
SUMMARY = "Shows and sets processor power related values"

DESCRIPTION = "cpupower is a collection of tools to examine and tune \
power saving related features of your processor."

LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=d7810fab7487fb0aad327b76f1be7cd7"


#PR = "r0"

COMPATIBLE_HOST = '(x86_64.*|i.86.*)-linux'

DEPENDS = "virtual/kernel pciutils"
RDEPENDS_${PN} = "pciutils bash"

do_fetch[noexec] = "1"
do_unpack[noexec] = "1"
do_patch[noexec] = "1"

# This looks in S, so we better make sure there's
# something in the directory.
#
do_populate_lic[depends] = "${PN}:do_configure"


EXTRA_OEMAKE = '\
                CC="${CC}" \
		CROSS="${TARGET_PREFIX}" \
               '

# If we build under STAGING_KERNEL_DIR, source will not be put
# into the dbg rpm.  STAGING_KERNEL_DIR will exist by the time
# do_configure() is invoked so we can safely copy from it.
#
do_configure_prepend() {
	mkdir -p ${S}
	cp -r ${STAGING_KERNEL_DIR}/tools/power/cpupower/* ${S}
	cp -r ${STAGING_KERNEL_DIR}/COPYING ${S}
}

do_compile() {
	sed -i "s#../../..#${STAGING_KERNEL_DIR}#g" utils/version-gen.sh
	sed -i "s#fpR#fR#g" Makefile
	sed -i 's#-shared $(CFLAGS)#$(CFLAGS) -shared#' Makefile
	oe_runmake STAGING_KERNEL_DIR=${STAGING_KERNEL_DIR}
}

do_install() {
	oe_runmake DESTDIR="${D}" install
}
