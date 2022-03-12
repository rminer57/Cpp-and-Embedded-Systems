// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoUSBSubsystem::MakoUSBEvents'

#ifndef MakoUSBEvents_H
#define MakoUSBEvents_H

#ifdef PRAGMA
#pragma interface "MakoUSBEvents.h"
#endif

#include <HALtestLib_win32.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>
// }}}USR
// }}}RME

class MakoUSBEvents
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
	// {{{RME classAttribute 'USB1_INTR_EVENT2_VBUS_5V'
	static const int USB1_INTR_EVENT2_VBUS_5V;
	// }}}RME
	// {{{RME classAttribute 'USB2_INTR_EVENT4_VBUS_5V'
	static const int USB2_INTR_EVENT4_VBUS_5V;
	// }}}RME
	// {{{RME classAttribute 'TEST_DEBUG_EVENT0'
	static const int TEST_DEBUG_EVENT0;
	// }}}RME
	// {{{RME classAttribute 'USB1_INTR_EVENT1_VBUS_0V'
	static const int USB1_INTR_EVENT1_VBUS_0V;
	// }}}RME
	// {{{RME classAttribute 'USB2_INTR_EVENT3_VBUS_0V'
	static const int USB2_INTR_EVENT3_VBUS_0V;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	MakoUSBEvents( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~MakoUSBEvents( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	MakoUSBEvents( const MakoUSBEvents & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	MakoUSBEvents & operator=( const MakoUSBEvents & rtg_arg );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* MakoUSBEvents_H */

// }}}RME
