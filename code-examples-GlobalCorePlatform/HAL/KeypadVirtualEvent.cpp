// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Keypad::KeypadVirtualEvent'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "KeypadVirtualEvent.h"
#endif

#include <hal.h>
#include <KeypadVirtualEvent.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'KEYPADVIRTUAL_BASIC_EVENT'
const unsigned int KeypadVirtualEvent::KEYPADVIRTUAL_BASIC_EVENT( 2 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
KeypadVirtualEvent::~KeypadVirtualEvent( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
KeypadVirtualEvent::KeypadVirtualEvent( const KeypadVirtualEvent & rtg_arg )
	: EventBase( rtg_arg )
{
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool KeypadVirtualEvent::isType( ClassType type ) const
{
	// {{{USR
	return (type == KEYPADVIRTUAL_BASIC_EVENT?true:EventBase::isType(type));
	// }}}USR
}
// }}}RME

// {{{RME operation 'getType()'
ClassType KeypadVirtualEvent::getType( void ) const
{
	// {{{USR
	return KEYPADVIRTUAL_BASIC_EVENT;
	// }}}USR
}
// }}}RME

// {{{RME operation 'KeypadVirtualEvent()'
KeypadVirtualEvent::KeypadVirtualEvent( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: EventBase(KEYPADVIRTUAL_BASIC_EVENT)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'getEvent()'
unsigned int KeypadVirtualEvent::getEvent( void ) const
{
	// {{{USR
	return KEYPADVIRTUAL_BASIC_EVENT;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
