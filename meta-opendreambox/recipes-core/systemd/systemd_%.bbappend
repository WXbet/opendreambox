SRC_URI_remove = "git://github.com/systemd/systemd.git;protocol=git"
SRC_URI += "git://github.com/systemd/systemd.git;protocol=https;branch=main"

EXTRA_OECONF += "--with-time-epoch=0"

do_install_append() {
    rm ${D}${sysconfdir}/systemd/system/getty.target.wants/getty@tty1.service
}
