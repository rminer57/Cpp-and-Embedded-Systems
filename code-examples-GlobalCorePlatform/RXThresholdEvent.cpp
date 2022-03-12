// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Serial IO::UART::RXThresholdEvent'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "RXThresholdEvent.h"
#endif

#include <hal.h>
#include <RXThresholdEvent.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'RX_THRESHOLD_EVENT'
const unsigned int RXThresholdEvent::RX_THRESHOLD_EVENT( 11 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
RXThresholdEvent::~RXThresholdEvent( void )
{
}
// }}}RME

// {{{RME operation 'getType()'
ClassType RXThresholdEvent::getType( void ) const
{
	// {{{USR
	return RX_THRESHOLD_EVENT;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool RXThresholdEvent::isType( ClassType type ) const
{
	// {{{USR
	return (type == RX_THRESHOLD_EVENT?true:EventBase::isType(type));

	// }}}USR
}
// }}}RME

// {{{RME operation 'RXThresholdEvent()'
RXThresholdEvent::RXThresholdEvent( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: Event(RX_THRESHOLD_EVENT)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
