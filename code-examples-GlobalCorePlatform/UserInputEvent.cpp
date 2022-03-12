// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::User IO::UserInputEvent'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "UserInputEvent.h"
#endif

#include <hal.h>
#include <UserInputEvent.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'INPUT_EVENT'
const unsigned int UserInputEvent::INPUT_EVENT( 32 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
UserInputEvent::~UserInputEvent( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
UserInputEvent::UserInputEvent( const UserInputEvent & rtg_arg )
	: EventBase( rtg_arg )
	, m_inputCode( rtg_arg.m_inputCode )
	, m_inputStatus( rtg_arg.m_inputStatus )
{
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool UserInputEvent::isType( ClassType type ) const
{
	// {{{USR
	return ((type == INPUT_EVENT)?true:EventBase::isType(type));
	// }}}USR
}
// }}}RME

// {{{RME operation 'getType()'
ClassType UserInputEvent::getType( void ) const
{
	// {{{USR
	return INPUT_EVENT;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getEvent()'
unsigned int UserInputEvent::getEvent( void ) const
{
	// {{{USR
	return INPUT_EVENT;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isEvent(unsigned int)'
bool UserInputEvent::isEvent( unsigned int event ) const
{
	// {{{USR
	return ((event == INPUT_EVENT)?true:EventBase::isEvent(event));
	// }}}USR
}
// }}}RME

// {{{RME operation 'UserInputEvent(unsigned int,unsigned int)'
UserInputEvent::UserInputEvent( unsigned int inputCode, unsigned int inputStatus )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: EventBase(INPUT_EVENT), m_inputCode(inputCode), m_inputStatus(inputStatus)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'getInputCode()'
unsigned int UserInputEvent::getInputCode( void ) const
{
	// {{{USR
	return m_inputCode;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getInputStatus()'
unsigned int UserInputEvent::getInputStatus( void ) const
{
	// {{{USR
	return m_inputStatus;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
