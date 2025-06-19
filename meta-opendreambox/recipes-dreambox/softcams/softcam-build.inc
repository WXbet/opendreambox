PACKAGES = "${PN}"
PACKAGE_ARCH = "${TUNE_PKGARCH}"
PR = "r1"

inherit systemd

SYSTEMD_SERVICE_${PN} = "oscam.service"
FILES_${PN} += "${bindir} ${OSCAMCONF} ${systemd_system_unitdir}"

do_install_append() {
	sed -i -e 's|${PORT}|${OSCAMPORT}|g' -i ${D}${OSCAMCONF}/oscam.conf

	sed -e 's|${DESC}|${SUMMARY_${PN}}|g' \
		-e 's|${BIN}|${OSCAMNAME}|g' \
		-e 's|${CONF}|${OSCAMCONF}|g' \
		-i ${D}${systemd_system_unitdir}/oscam.service
}

INSANE_SKIP_${PN} += "already-stripped license-checksum"
