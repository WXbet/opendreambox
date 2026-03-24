SRC_URI = "https://alioth-archive.debian.org/releases/pcsclite/pcsclite/${PV}/pcsc-lite-${PV}.tar.bz2"

EXTRA_OECONF += "--enable-static"
PACKAGES =+ "${PN}-staticdev"
FILES_${PN}-staticdev = "${libdir}/*.a"
