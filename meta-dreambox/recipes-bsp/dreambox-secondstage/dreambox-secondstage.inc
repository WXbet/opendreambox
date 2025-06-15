PRECOMPILED_ARCH = "${@d.getVar('PV', True).split('-')[1]}"
PRECOMPILED_VERSION = "${@d.getVar('PV', True).split('-')[0]}"

SRC_URI = "https://source.mynonpublic.com/dreambox/secondstage-${PRECOMPILED_ARCH}-${PRECOMPILED_VERSION}.bin"

S = "${WORKDIR}"

require dreambox-secondstage-base.inc
