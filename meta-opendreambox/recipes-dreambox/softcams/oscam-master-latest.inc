inherit git-project

SRCREV = "${AUTOREV}"
PV = "2.2x+git"
SRC_URI += "${OSCAMREPO}"

SUMMARY_${PN} = "${OSCAMNAME} ${PKGV}"
DESCRIPTION_${PN} = "OSCam Open Source Softcam\n \
- latest master"

DEPENDS += "openssl-native"
EXTRA_OECMAKE += "\
	-DWITH_SIGNING=1 \
	-DUSE_COMPRESS=1 \
	-DCOMP_LEVEL="--best" \
"

do_configure_prepend () {
	rm -rf ${S}/certs
	${S}/config.sh --create-cert ecdsa prime256v1 ca "${OSCAMAUTH}"
}
