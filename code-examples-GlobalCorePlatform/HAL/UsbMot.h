// {{{RME classifier 'Logical View::Usb::UsbHost::UsbHID::UsbMot'

#ifndef UsbMot_H
#define UsbMot_H

#ifdef PRAGMA
#pragma interface "UsbMot.h"
#endif

#include <usbimp.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class UsbMot
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
	// {{{RME classAttribute 'VID'
	static const uint16_t VID;
	// }}}RME
	// {{{RME classAttribute 'USBMicUsagePage'
	static const uint16_t USBMicUsagePage;
	// }}}RME
	// {{{RME classAttribute 'USBMicTestUsagePage'
	static const uint16_t USBMicTestUsagePage;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	UsbMot( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~UsbMot( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* UsbMot_H */

// }}}RME
