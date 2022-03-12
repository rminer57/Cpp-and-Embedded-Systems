// {{{RME classifier 'Logical View::Usb::UsbDevice::UsbManager'

#ifndef UsbManager_H
#define UsbManager_H

#ifdef PRAGMA
#pragma interface "UsbManager.h"
#endif

#include <usbimp.h>
class IOVirtualSerial;
class USBConfigMgr;
class UartConfig;
class UsbDevice;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class UsbManager
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
	// {{{RME operation 'UsbManager()'
	UsbManager( void );
	// }}}RME
	// {{{RME operation 'getIOVirtualSerial(USBConfigMgr *,UartConfig*)'
	IOVirtualSerial * getIOVirtualSerial( USBConfigMgr * ConfigMgrPtr, UartConfig * config );
	// }}}RME
	// {{{RME operation '~UsbManager()'
	~UsbManager( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* UsbManager_H */

// }}}RME
