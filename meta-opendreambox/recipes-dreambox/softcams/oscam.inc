OSCAMTPL = "oscam"

OSCAMREPO ?= "git://git.streamboard.tv/common/oscam.git;protocol=https;branch=master"
OSCAMNAME ?= "oscam-master"
OSCAMCONF ?= "${sysconfdir}/tuxbox/config"
OSCAMPORT ?= "8888"
OSCAMAUTH ?= "DreamOS OSCam Distribution"
OSCAMOPTS ?= ""

require oscam-common.inc

S = "${WORKDIR}/${@ 'trunk' if 'svn:' in '${OSCAMREPO}' else 'git'}"

DEPENDS += "pcsc-lite"
RDEPENDS_${PN} += "pcsc-lite pcsc-tools"

EXTRA_OECMAKE += "\
    -DOSCAM_SYSTEM_NAME=${OSCAMNAME} \
    -DDEFAULT_CS_CONFDIR=${OSCAMCONF} \
    -DHAVE_PCSC=1 \
"
