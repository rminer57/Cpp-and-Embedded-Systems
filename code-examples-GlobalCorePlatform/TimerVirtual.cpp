// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Timer::TimerVirtual'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "TimerVirtual.h"
#endif

#include <hal.h>
#include <TimerVirtual.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Event' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classifier 'Event'

// {{{RME classAttribute 'TIMER_EVENT'
const unsigned int TimerVirtual::Event::TIMER_EVENT( 12 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
TimerVirtual::Event::~Event( void )
{
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool TimerVirtual::Event::isType( ClassType type ) const
{
	// {{{USR
	return (type == TIMER_EVENT?true:EventBase::isType(type));
	// }}}USR
}
// }}}RME

// {{{RME operation 'getType()'
ClassType TimerVirtual::Event::getType( void ) const
{
	// {{{USR
	return TIMER_EVENT;
	// }}}USR
}
// }}}RME

// {{{RME operation 'Event(unsigned int)'
TimerVirtual::Event::Event( unsigned int evt )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: EventBase(evt)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
TimerVirtual::~TimerVirtual( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Event' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
