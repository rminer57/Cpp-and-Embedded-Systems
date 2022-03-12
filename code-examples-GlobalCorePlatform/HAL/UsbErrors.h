// {{{RME classifier 'Logical View::Usb::UsbConfigMgr::UsbErrors'

#ifndef UsbErrors_H
#define UsbErrors_H

#ifdef PRAGMA
#pragma interface "UsbErrors.h"
#endif

#include <usbimp.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class UsbErrors
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
	// {{{RME classAttribute 'PG0_Overcurrent'
	static const uint16_t PG0_Overcurrent;
	// }}}RME
	// {{{RME classAttribute 'PG1_Overcurrent'
	static const uint16_t PG1_Overcurrent;
	// }}}RME
	// {{{RME classAttribute 'PG2_Overcurrent'
	static const uint16_t PG2_Overcurrent;
	// }}}RME
	// {{{RME classAttribute 'PG2A_Overcurrent'
	static const uint16_t PG2A_Overcurrent;
	// }}}RME
	// {{{RME classAttribute 'PG0_InsufficientCurrent'
	static const uint16_t PG0_InsufficientCurrent;
	// }}}RME
	// {{{RME classAttribute 'PG1_InsufficientCurrent'
	static const uint16_t PG1_InsufficientCurrent;
	// }}}RME
	// {{{RME classAttribute 'PG2_InsufficientCurrent'
	static const uint16_t PG2_InsufficientCurrent;
	// }}}RME
	// {{{RME classAttribute 'PG2A_InsufficientCurrent'
	static const uint16_t PG2A_InsufficientCurrent;
	// }}}RME
	// {{{RME classAttribute 'PG0_UnknownDevice'
	static const uint16_t PG0_UnknownDevice;
	// }}}RME
	// {{{RME classAttribute 'PG1_UnknownDevice'
	static const uint16_t PG1_UnknownDevice;
	// }}}RME
	// {{{RME classAttribute 'PG2_UnknownDevice'
	static const uint16_t PG2_UnknownDevice;
	// }}}RME
	// {{{RME classAttribute 'PG2A_UnknownDevice'
	static const uint16_t PG2A_UnknownDevice;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	UsbErrors( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~UsbErrors( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* UsbErrors_H */

// }}}RME
