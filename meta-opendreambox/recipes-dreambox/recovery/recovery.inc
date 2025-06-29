SUMMARY = "Command-line tools to flash and recover your Dreambox"
HOMEPAGE = "http://dreamboxupdate.com/"
LICENSE = "CLOSED"
DEPENDS = "coreutils-native udev"

inherit pkgconfig update-rc.d

SRC_URI_append = ";branch=${BRANCH}"

S = "${WORKDIR}/git"

do_compile_prepend() {
    if [ "${PACKAGE_FEED_SIGN}" = "1" -a -n "${PACKAGE_FEED_GPG_NAME}" -a -n "${DISTRO_FEED_URI}" ]; then
        # inject base64 encoded gpg public key into create_keyring_for_uri function of librecovery
        echo "\tKEY_CUSTOM=\"" > "${WORKDIR}/librecovery.tmp"
        gpg --export "${PACKAGE_FEED_GPG_NAME}" | base64 | sed 's/^/\t\t/' >> "${WORKDIR}/librecovery.tmp"
        echo "\t\"" >> "${WORKDIR}/librecovery.tmp"

        sed -i '626 {p;}' "${S}/librecovery"
        sed -i '627i\\t\t*${@d.getVar('DISTRO_FEED_URI', True).split('://',1)[1].replace('${MACHINE}', '${MACHINE')}\}/*)\n\t\t\tcreate_keyring \"\${KEY_CUSTOM}\"' "${S}/librecovery"
        sed -i '615r ${WORKDIR}/librecovery.tmp' "${S}/librecovery"
    fi
}

do_install() {
    oe_runmake install DESTDIR=${D}
}

PACKAGES =+ "flash-scripts"

PACKAGE_ARCH = "${MACHINE_ARCH}"

EMMCRDEPENDS_recovery = " \
    e2fsprogs-mke2fs \
    gptfdisk-sgdisk \
"
EMMCRDEPENDS_flash-scripts = " \
    util-linux-sfdisk \
"
NANDRDEPENDS_recovery = " \
    mtd-utils-mkfs.ubifs \
    mtd-utils-ubiattach \
    mtd-utils-ubimkvol \
    mtd-utils-ubirmvol \
    mtd-utils-ubiformat \
"
NANDRDEPENDS_flash-scripts = " \
    mtd-utils-flash-erase \
    mtd-utils-nandwrite \
"
FASTBOOTRDEPENDS_flash-scripts = " \
    fastboot \
    mkbootblob \
"

RDEPENDS_${PN} = " \
    flash-scripts \
    gpgv \
    pigz \
    util-linux-blkid \
    util-linux-mount \
"
RDEPENDS_${PN}_append_bcm7435 = " \
    ${EMMCRDEPENDS_recovery} \
"
RDEPENDS_${PN}_append_bcm7439 = " \
    ${EMMCRDEPENDS_recovery} \
"
RDEPENDS_${PN}_append_bcm73625 = " \
    ${NANDRDEPENDS_recovery} \
"
RRECOMMENDS_${PN} = " \
    recovery-ui \
"

RDEPENDS_flash-scripts = " \
    coreutils-realpath \
    tpm-ca \
"
RDEPENDS_flash-scripts_append_bcm7435 = " \
    ${EMMCRDEPENDS_flash-scripts} \
    ${FASTBOOTRDEPENDS_flash-scripts} \
"
RDEPENDS_flash-scripts_append_bcm7439 = " \
    ${EMMCRDEPENDS_flash-scripts} \
"
RDEPENDS_flash-scripts_append_bcm73625 = " \
    ${NANDRDEPENDS_flash-scripts} \
"

FILES_flash-scripts = " \
    ${sbindir}/flash-fsbl \
    ${sbindir}/flash-rescue \
    ${sbindir}/flash-kernel \
    ${sbindir}/flash-ssbl \
    ${sbindir}/librecovery \
    ${sbindir}/readspi \
    ${sbindir}/select-boot-source \
    ${sbindir}/to-the-rescue \
    ${sbindir}/update-rescue \
    ${sbindir}/writespi \
"

INITSCRIPT_NAME = "autoflashd"
