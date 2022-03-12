// {{{RME classifier 'Logical View::Usb::UsbConfigMgr::USBPort'

#ifndef USBPort_H
#define USBPort_H

#ifdef PRAGMA
#pragma interface "USBPort.h"
#endif

#include <usbimp.h>
class GlobalUSBConfiguration;
class HmcTable;
class PG0_Mako2UsbXcvr;
class PG0_OMAP1610UsbXcvr;
class PG1_ISP1105UsbXcvr;
class PG1_Mako1UsbXcvr;
class PG2_ISP1105UsbXcvr;
class PortConfiguration;
class UsbTransceiver;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class USBPort
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

protected:
	// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

private:
	// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

public:
	// {{{RME classAttribute 'PORT_SLOW_SPEED'
	static const uint32_t PORT_SLOW_SPEED;
	// }}}RME
	// {{{RME classAttribute 'PORT_FULL_SPEED'
	static const uint32_t PORT_FULL_SPEED;
	// }}}RME

private:
	// {{{RME classAttribute 'm_portState'
	uint32_t m_portState;
	// }}}RME

public:
	// {{{RME classAttribute 'HOST_STATE'
	static const uint32_t HOST_STATE;
	// }}}RME
	// {{{RME classAttribute 'DEVICE_STATE'
	static const uint32_t DEVICE_STATE;
	// }}}RME
	// {{{RME classAttribute 'DISABLED_STATE'
	static const uint32_t DISABLED_STATE;
	// }}}RME
	// {{{RME classAttribute 'NOT_REALIZED'
	static const uint32_t NOT_REALIZED;
	// }}}RME

private:
	// {{{RME classAttribute 'm_portConfigPtr'
	PortConfiguration * m_portConfigPtr;
	// }}}RME
	// {{{RME classAttribute 'm_globalUSBConfigPtr'
	GlobalUSBConfiguration * m_globalUSBConfigPtr;
	// }}}RME
	// {{{RME classAttribute 'm_portNum'
	uint32_t m_portNum;
	// }}}RME

public:
	// {{{RME associationEnd 'm_Transceiver'
	UsbTransceiver * m_Transceiver;
	// }}}RME
	// {{{RME operation 'USBPort(uint32_t,PortConfiguration *,GlobalUSBConfiguration *)'
	USBPort( uint32_t portNum, PortConfiguration * portConfigPtr, GlobalUSBConfiguration * globalUSBConfigPtr );
	// }}}RME
	// {{{RME operation 'getPortState()'
	uint32_t getPortState( void ) const;
	// }}}RME
	// {{{RME operation 'setPortState(uint32_t)'
	bool setPortState( uint32_t newPortType );
	// }}}RME
	// {{{RME operation 'disconnectPort()'
	bool disconnectPort( void );
	// }}}RME
	// {{{RME operation 'connectPort()'
	bool connectPort( void );
	// }}}RME
	// {{{RME operation 'setPortSpeed(uint32_t)'
	bool setPortSpeed( uint32_t portSpeed );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* USBPort_H */

// }}}RME
