// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoUSBSubsystem::VBUSmanager::MakoVbusEvent'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "MakoVbusEvent.h"
#endif

#include <rf_sequencer_comp.h>
#include <MakoVbusEvent.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
MakoVbusEvent::MakoVbusEvent( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
MakoVbusEvent::~MakoVbusEvent( void )
{
}
// }}}RME

// {{{RME operation 'setEvent(unsigned int)'
void MakoVbusEvent::setEvent( unsigned int event )
{
	// {{{USR

	m_event = event;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
