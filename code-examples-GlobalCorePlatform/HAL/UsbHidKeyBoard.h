// {{{RME classifier 'Logical View::Usb::UsbHost::UsbHID::UsbHidKeyBoard'

#ifndef UsbHidKeyBoard_H
#define UsbHidKeyBoard_H

#ifdef PRAGMA
#pragma interface "UsbHidKeyBoard.h"
#endif

#include <usbimp.h>
#include <UsbHidDevice.h>
class GenericHidKeyboard;
class SECT;
class UserInputEvent;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class UsbHidKeyBoard : public UsbHidDevice
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
	// {{{RME associationEnd 'm_GenericKeyboardPtr'
	static GenericHidKeyboard * m_GenericKeyboardPtr;
	// }}}RME
	// {{{RME operation 'UsbHidKeyBoard(uint16_t,uint16_t,uint16_t,uint16_t)'
	UsbHidKeyBoard( uint16_t vendorID, uint16_t productID, uint16_t deviceClass, uint16_t usagePage );
	// }}}RME
	// {{{RME operation 'receive()'
	int receive( void );
	// }}}RME
	// {{{RME operation 'inform()'
	void inform( void );
	// }}}RME
	// {{{RME operation '~UsbHidKeyBoard()'
	~UsbHidKeyBoard( void );
	// }}}RME
	// {{{RME operation 'sethidReportPtr(uint32_t *)'
	inline void sethidReportPtr( uint32_t * newVal )
	{
		// {{{USR
		// do nothing.
		// }}}USR
	}
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* UsbHidKeyBoard_H */

// }}}RME
