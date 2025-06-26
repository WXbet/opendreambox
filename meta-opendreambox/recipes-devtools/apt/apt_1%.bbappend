do_install_append_class-target() {
    #Write the correct apt-architecture to apt.conf
    echo 'APT::Architecture "${DPKG_ARCH}";' > ${D}${sysconfdir}/apt/apt.conf
    echo 'Acquire::http::Timeout "5";' >> ${D}${sysconfdir}/apt/apt.conf
    echo 'APT::Get::AllowUnauthenticated "true";' >> ${D}${sysconfdir}/apt/apt.conf
    echo 'Acquire::https {' >> ${D}${sysconfdir}/apt/apt.conf
    echo 'Verify-Peer "false";' >> ${D}${sysconfdir}/apt/apt.conf
    echo 'Verify-Host "false";' >> ${D}${sysconfdir}/apt/apt.conf
    echo '}' >> ${D}${sysconfdir}/apt/apt.conf
}
