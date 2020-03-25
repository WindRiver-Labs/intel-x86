#
# Copyright (C) 2017 Wind River Systems, Inc.
#
SUMMARY = "A Monitoring and Testing Tool for Linux kernel thermal subsystem"

DESCRIPTION = "TMON is conceived as a tool to help visualize, tune, and \
test the complex thermal subsystem"

LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=e6a75371ba4d16749254a51215d13f97"

PR = "r0"

COMPATIBLE_HOST = '(x86_64.*|i.86.*)-linux'

DEPENDS = "virtual/kernel ncurses"

do_fetch[noexec] = "1"
do_unpack[noexec] = "1"
do_patch[noexec] = "1"
do_configure[depends] += "virtual/kernel:do_shared_workdir"

# This looks in S, so we better make sure there's
# something in the directory.
#
do_populate_lic[depends] += "${PN}:do_configure"


EXTRA_OEMAKE = '\
                CC="${CC}" \
                -I${STAGING_KERNEL_DIR}/tools/thermal/tmon \
               '

# If we build under STAGING_KERNEL_DIR, source will not be put
# into the dbg rpm.  STAGING_KERNEL_DIR will exist by the time
# do_configure() is invoked so we can safely copy from it.
#
do_configure_prepend() {
	mkdir -p ${S}
	cp -r ${STAGING_KERNEL_DIR}/tools/thermal/tmon/* ${S}
	cp ${STAGING_KERNEL_DIR}/LICENSES/preferred/GPL-2.0 ${S}/COPYING
        # Fix compile error when pkg-config is on the dependency chain:
        # tmon.h:42:17: error: field 'tv' has incomplete type 
        sed -i '/PKG_CONFIG.*--cflags.*ncurses/d' ${S}/Makefile
}

do_compile() {
	oe_runmake STAGING_KERNEL_DIR=${STAGING_KERNEL_DIR}
}

do_install() {
	oe_runmake INSTALL_ROOT="${D}" install
}
