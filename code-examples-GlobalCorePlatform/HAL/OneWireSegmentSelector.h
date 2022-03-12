// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OneWire_Interface::BusInterface::OneWireSegmentSelector'

#ifndef OneWireSegmentSelector_H
#define OneWireSegmentSelector_H

#ifdef PRAGMA
#pragma interface "OneWireSegmentSelector.h"
#endif

#include <serial_comp.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class OneWireSegmentSelector
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
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	OneWireSegmentSelector( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~OneWireSegmentSelector( void );
	// }}}RME
	// {{{RME operation 'enableSegment()'
	virtual bool enableSegment( void ) = 0;
	// }}}RME
	// {{{RME operation 'disableSegment()'
	virtual bool disableSegment( void ) = 0;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* OneWireSegmentSelector_H */

// }}}RME
