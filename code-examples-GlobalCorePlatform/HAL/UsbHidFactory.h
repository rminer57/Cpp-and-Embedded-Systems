// {{{RME classifier 'Logical View::Usb::UsbHost::UsbHID::UsbHidFactory'

#ifndef UsbHidFactory_H
#define UsbHidFactory_H

#ifdef PRAGMA
#pragma interface "UsbHidFactory.h"
#endif

#include <usbimp.h>
class GenericHidKeyboard;
class GenericHidMicrophone;
class UsbHidDevice;
class UsbHidKeyBoard;
class UsbHidMicrophone;
class UsbMot;
class UsbUnsupportedDevice;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class UsbHidFactory
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
	// {{{RME classAttribute 'm_hidObjectArray'
	static UsbHidDevice * m_hidObjectArray[ 16 ];
	// }}}RME
	// {{{RME classAttribute 'HID_MAX_DEVICES'
	static const uint32_t HID_MAX_DEVICES;
	// }}}RME

private:
	// {{{RME classAttribute 'm_currentHidCount'
	static uint32_t m_currentHidCount;
	// }}}RME

public:
	// {{{RME associationEnd 'm_GenericHidKeyboard'
	GenericHidKeyboard * m_GenericHidKeyboard;
	// }}}RME
	// {{{RME associationEnd 'm_GenericHidMicrophone'
	static GenericHidMicrophone * m_GenericHidMicrophone;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	UsbHidFactory( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~UsbHidFactory( void );
	// }}}RME
	// {{{RME operation 'removeHidDevice(UsbHidDevice *)'
	static bool removeHidDevice( UsbHidDevice * hidDevPtr );
	// }}}RME
	// {{{RME operation 'UsbHidFactoryInit()'
	static void UsbHidFactoryInit( void );
	// }}}RME
	// {{{RME operation 'getHidDevice(uint16_t,uint16_t,uint16_t,uint16_t)'
	static UsbHidDevice * getHidDevice( uint16_t usbVID, uint16_t usbPID, uint16_t usbDevClass, uint16_t usbHidUsagePage );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* UsbHidFactory_H */

// }}}RME
