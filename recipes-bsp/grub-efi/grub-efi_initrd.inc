#
# Copyright (C) 2016-2019 Wind River Systems, Inc.
#

FILESEXTRAPATHS_prepend := "${THISDIR}/files:"
SRC_URI += "file://grub-initrd.cfg"

do_deploy_append_class-target () {
	install -m 0600 ${WORKDIR}/grub-initrd.cfg  ${DEPLOYDIR}/grub.cfg
}
