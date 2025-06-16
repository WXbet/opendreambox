SUMMARY = "PCSC tools"
HOMEPAGE = "http://ludovic.rousseau.free.fr/softwares/pcsc-tools/"
LICENSE = "GPL-2.0"
LIC_FILES_CHKSUM = "file://LICENCE;md5=94d55d512a9ba36caa9b7df079bae19f"

DEPENDS = "pcsc-lite autoconf-archive"
RDEPENDS_${PN} = "pcsc-lite"

inherit git-project

SRCREV = "${AUTOREV}"
PV = "1.6.2+git"

SRC_URI = "git://github.com/LudovicRousseau/pcsc-tools.git;protocol=https;branch=master"

S = "${WORKDIR}/git"

inherit autotools gettext pkgconfig

FILES_${PN} += "${datadir}"
