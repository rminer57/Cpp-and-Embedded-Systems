// {{{RME classifier 'Logical View::EventManagement::EventBase'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "EventBase.h"
#endif

#include <event_mgmt.h>
#include <EventBase.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'BASIC_EVENT'
const unsigned int EventBase::BASIC_EVENT( 1 );
// }}}RME

// {{{RME classAttribute 'UNKNOWN'
const unsigned int EventBase::UNKNOWN( 0 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
EventBase::~EventBase( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
EventBase::EventBase( const EventBase & rtg_arg )
	: TypedBaseClass( rtg_arg )
	, m_event( rtg_arg.m_event )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
EventBase & EventBase::operator=( const EventBase & rtg_arg )
{
	if( this != &rtg_arg )
	{
		TypedBaseClass::operator=( rtg_arg );
		m_event = rtg_arg.m_event;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool EventBase::isType( ClassType type ) const
{
	// {{{USR
	return (type == BASIC_EVENT?true:TypedBaseClass::isType(type));
	// }}}USR
}
// }}}RME

// {{{RME operation 'getType()'
ClassType EventBase::getType( void ) const
{
	// {{{USR
	return BASIC_EVENT;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getEvent()'
unsigned int EventBase::getEvent( void ) const
{
	// {{{USR
	return m_event;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isEvent(unsigned int)'
bool EventBase::isEvent( unsigned int event ) const
{
	// {{{USR
	return (event == m_event);
	// }}}USR
}
// }}}RME

// {{{RME operation 'EventBase(unsigned int)'
EventBase::EventBase( unsigned int event )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_event(event)
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
