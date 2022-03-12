// {{{RME classifier 'Logical View::Usb::UsbConfigMgr::USBConfigMgr'

#ifndef USBConfigMgr_H
#define USBConfigMgr_H

#ifdef PRAGMA
#pragma interface "USBConfigMgr.h"
#endif

#include <usbimp.h>
#include <Thread.h>
class GlobalUSBConfiguration;
class HmcTable;
class KeyBoardSupport;
class PortConfiguration;
class USBPort;
class UsbHidFactory;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class USBConfigMgr : public Thread
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
	// {{{RME associationEnd 'm_port1Config'
	PortConfiguration * m_port1Config;
	// }}}RME
	// {{{RME associationEnd 'm_port2Config'
	PortConfiguration * m_port2Config;
	// }}}RME
	// {{{RME associationEnd 'm_port0Config'
	PortConfiguration * m_port0Config;
	// }}}RME
	// {{{RME associationEnd 'm_port2aConfig'
	PortConfiguration * m_port2aConfig;
	// }}}RME
	// {{{RME associationEnd 'm_globalConfig'
	GlobalUSBConfiguration * m_globalConfig;
	// }}}RME
	// {{{RME associationEnd 'm_Port0'
	USBPort * m_Port0;
	// }}}RME
	// {{{RME associationEnd 'm_Port2'
	USBPort * m_Port2;
	// }}}RME
	// {{{RME associationEnd 'm_Port2a'
	USBPort * m_Port2a;
	// }}}RME
	// {{{RME associationEnd 'm_Port1'
	USBPort * m_Port1;
	// }}}RME
	// {{{RME operation 'USBConfigMgr(GlobalUSBConfiguration *,PortConfiguration *,PortConfiguration *,PortConfiguration *,PortConfiguration *)'
	USBConfigMgr( GlobalUSBConfiguration * globalConfig, PortConfiguration * port0Config, PortConfiguration * port1Config, PortConfiguration * port2Config, PortConfiguration * port2aConfig );
	// }}}RME
	// {{{RME operation 'setHmcMode(uint32_t)'
	bool setHmcMode( uint32_t requestedHmcMode );
	// }}}RME
	// {{{RME operation 'manageVbusPower(bool)'
	void manageVbusPower( bool manage );
	// }}}RME

private:
	// {{{RME operation 'configOmapUSB()'
	void configOmapUSB( void );
	// }}}RME

public:
	// {{{RME operation 'checkConfiguration()'
	bool checkConfiguration( void );
	// }}}RME
};

// {{{RME classAttribute 'USBConfigPtr'
extern USBConfigMgr * USBConfigPtr;
// }}}RME

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* USBConfigMgr_H */

// }}}RME
