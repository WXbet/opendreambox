FILESEXTRAPATHS_prepend := "${THISDIR}/enigma2-plugin-softcams-oscam:"
FILESEXTRAPATHS_prepend := "${THISDIR}/enigma2-plugin-softcams-oscam/${OSCAMNAME}:"

CONFFILES_${PN} ?= "${OSCAMCONF}"

do_configure_prepend () {
	sed -i -e 's:DEFAULT_HTTP_PORT[ \t]*?8888:DEFAULT_HTTP_PORT ${OSCAMPORT}:g' ${S}/oscam-config-global.c
}

inherit cmake

SRC_URI += " \
            file://oscam.service.template \
            file://${OSCAMNAME}/ \
"

LICENSE = "GPL-3.0"
LIC_FILES_CHKSUM = "file://${S}/COPYING;md5=d32239bcb673463ab874e80d47fae504"

DEPENDS += "libusb openssl libdvbcsa"
RDEPENDS_${PN} += "libdvbcsa libusb1"

LDFLAGS_prepend = "-ldvbcsa -ldl "


EXTRA_OECMAKE += "\
	-DWEBIF=1 \
	-DWEBIF_LIVELOG=1 \
	-DWEBIF_JQUERY=1 \
	-DWITH_COMPRESS_WEBIF=0 \
	-DWITH_SSL=1 \
	-DWITH_STAPI=0 \
	-DHAVE_LIBUSB=1 \
	-DSTATIC_LIBUSB=0 \
	-DMODULE_CONSTCW=1 \
	-DMODULE_STREAMRELAY=1 \
	-DHAVE_LIBDVBCSA=1 \
	${@bb.utils.contains_any("TUNE_FEATURES", "neon simd", "-DWITH_ARM_NEON=1", "", d)} \
"

do_install () {
	install -d ${D}/${bindir}
	install -m 0755 ${B}/oscam${BINSUFFIX} ${D}${bindir}/${OSCAMNAME}
	install -d ${D}/${OSCAMCONF}
	[ -e ${WORKDIR}/${OSCAMNAME} ] && install -m 0644 ${WORKDIR}/${OSCAMNAME}/* ${D}/${OSCAMCONF} || true
}

require softcam-build.inc
