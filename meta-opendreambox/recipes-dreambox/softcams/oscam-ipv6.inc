SUMMARY_${PN}_append = " (IPv4/IPv6 Dual-Stack support)"

DESCRIPTION_${PN} += "\n \
- IPv6 support\nThis version can connect to servers using IPv4 and/or IPv6."

RPROVIDES_${PN}  += "${OSCAMNAME}"

EXTRA_OECMAKE += "\
	-DIPV6SUPPORT=1 \
	"
