require oscam-common.inc

S = "${WORKDIR}/git"

DEPENDS += "pcsc-lite"
RDEPENDS_${PN} += "pcsc-lite pcsc-tools"

EXTRA_OECMAKE += "\
    -DOSCAM_SYSTEM_NAME=${OSCAMNAME} \
    -DDEFAULT_CS_CONFDIR=${OSCAMCONF} \
    -DHAVE_PCSC=0 \
	-DCLOCKFIX=1 \
"
