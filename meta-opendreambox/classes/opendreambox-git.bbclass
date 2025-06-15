OPENDREAMBOX_PROJECT ?= "${BPN}"

OPENDREAMBOX_URI ?= "git://github.com/OpenDMM/${OPENDREAMBOX_PROJECT}.git;protocol=https;branch=master"
SRC_URI += "${OPENDREAMBOX_URI}"

inherit git-project opendreambox-srcrev
