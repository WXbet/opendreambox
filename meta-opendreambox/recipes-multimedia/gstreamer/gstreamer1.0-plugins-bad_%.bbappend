FILESEXTRAPATHS_prepend := "${THISDIR}/${BPN}:"

SRC_URI += " \
    file://dvdspu-dts-timestamps.patch \
    file://assrender-overlay-caps.patch \
    file://rtmpsrc-interruption.patch \
    file://backport-mpegtspacketizer.patch \
"
# this patches needs to be backported to version 1.7.2
#    file://dvdspu-overlay-composition.patch
#    file://dvdspu-forced-mode-property.patch

EXTRA_OECONF += "--disable-dvb"
