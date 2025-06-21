inherit git-project

SRCREV = "${AUTOREV}"
PV = "${@ '1.40+svn' if 'svn:' in '${OSCAMREPO}' else '2.2x+git'}"

SRC_URI += "${OSCAMREPO}"

SUMMARY_${PN} = "${OSCAMNAME} ${PKGV}"
DESCRIPTION_${PN} = "OSCam Open Source Softcam\n \
- latest"

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
