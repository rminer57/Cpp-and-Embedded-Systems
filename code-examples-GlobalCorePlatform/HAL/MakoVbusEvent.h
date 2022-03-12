// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoUSBSubsystem::VBUSmanager::MakoVbusEvent'

#ifndef MakoVbusEvent_H
#define MakoVbusEvent_H

#ifdef PRAGMA
#pragma interface "MakoVbusEvent.h"
#endif

#include <rf_sequencer_comp.h>
#include <IOVirtual.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class MakoVbusEvent : public IOVirtual::Event
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
	MakoVbusEvent( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~MakoVbusEvent( void );
	// }}}RME
	// {{{RME operation 'setEvent(unsigned int)'
	void setEvent( unsigned int event );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* MakoVbusEvent_H */

// }}}RME
