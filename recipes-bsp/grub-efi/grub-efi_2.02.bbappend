#
# Copyright (C) 2016-2019 Wind River Systems, Inc.
#

require ${@bb.utils.contains('DISTRO_FEATURES', 'wic-installer', '${BPN}_initrd.inc', '', d)}
