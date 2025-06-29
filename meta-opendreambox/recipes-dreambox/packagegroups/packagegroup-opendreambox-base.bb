SUMMARY = "OpenDreambox: Base Task for the OpenDreambox Distribution"
SECTION = "opendreambox/base"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${OPENDREAMBOX_BASE}/LICENSE;md5=8f242b441da515e30c7b07f2cc6f4d5c"

inherit packagegroup

RDEPENDS_${PN} += " \
  killall \
  parted \
  procps \
  tpmd \
  tuxbox-common \
  tzdata \
  tzdata-europe \
  xfsprogs-mkfs \
  libssl3 \
  libusb1 \
  ${@base_version_less_or_equal('OLDEST_KERNEL', '3.9', '', 'kernel-module-wireguard wireguard-tools', d)} \
"

RRECOMMENDS_${PN} += " \
  autofs \
  avahi-daemon \
  bash \
  bash-completion \
  bash-completion-extra \
  dccamd \
  dreambox-compat \
  dropbear \
  e2fsprogs-e2fsck \
  hdstandby \
  htop \
  joe \
  less \
  mc \
  nano \
  samba-base \
  vsftpd \
  zeroconf \
"
