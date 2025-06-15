LIC_FILES_CHKSUM = "file://etc/default/enigma2;md5=4ec41c7a12d97d6164a2607413764b8b"

DEPENDS += " \
    boost \
    freetype \
    fribidi \
    giflib \
    glib-2.0 \
    gstreamer1.0 \
    gstreamer1.0-plugins-base \
    libaio \
    libav \
    libbluray \
    libconnman-qt5 \
    libdlsym \
    libdreamdvd \
    libdvbsi++ \
    libdvdnav \
    libdvdread \
    libjpeg-turbo \
    libpng \
    libsigc++-2.0 \
    libunwind \
    libwebp \
    libxml2 \
    openssl \
    python \
    qtbase \
    qtwebkit \
    qtsvg \
    sqlite3 \
    systemd \
    zlib \
"

SRC_URI += "file://${PN}_${PV}_${PACKAGE_ARCH}.tar.xz;subdir=${P}"

#inherit opendreambox-precompiled-binary

RDEPENDS_${PN} += " \
    libegl \
    libgles2 \
    qtbase-plugin-platforms-qoffscreen \
"

require enigma2-common.inc
