PACKAGES = "${PN}"
PACKAGE_ARCH = "${TUNE_PKGARCH}"
PR = "r1"

inherit systemd

SYSTEMD_SERVICE_${PN} = "oscam.service"
FILES_${PN} += "${bindir} ${OSCAMCONF} ${systemd_system_unitdir}"

do_install_append() {
	install -d ${D}${systemd_system_unitdir}
	DESC="${SUMMARY_${PN}}" BIN="${OSCAMNAME}" CONF="${OSCAMCONF}" \
	envsubst < ${WORKDIR}/oscam.service.template > ${WORKDIR}/oscam.service
	install -m 644 ${WORKDIR}/oscam.service ${D}${systemd_system_unitdir}
}

INSANE_SKIP_${PN} += "already-stripped license-checksum"
