// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Connections::Connection'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Connection.h"
#endif

#include <conn.h>
#include <Connection.h>
#include <Array.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Status' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Connections::Connection::Status::Event' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'ConnectionOption' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classifier 'Status'

// {{{RME classifier 'Event'

// {{{RME classAttribute 'AVAILABLE'
const unsigned int Connection::Status::Event::AVAILABLE( 1 );
// }}}RME

// {{{RME classAttribute 'DATA_AVAILABLE'
const unsigned int Connection::Status::Event::DATA_AVAILABLE( 3 );
// }}}RME

// {{{RME classAttribute 'UNAVAILABLE'
const unsigned int Connection::Status::Event::UNAVAILABLE( 2 );
// }}}RME

// {{{RME classAttribute 'CONNECTION_EVENT'
const unsigned int Connection::Status::Event::CONNECTION_EVENT( 2 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
Connection::Status::Event::~Event( void )
{
}
// }}}RME

// {{{RME operation 'getType()'
ClassType Connection::Status::Event::getType( void ) const
{
	// {{{USR
	return CONNECTION_EVENT;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool Connection::Status::Event::isType( ClassType type ) const
{
	// {{{USR
	return (type == CONNECTION_EVENT?true:EventBase::isType(type));
	// }}}USR
}
// }}}RME

// {{{RME operation 'Event(unsigned int)'
Connection::Status::Event::Event( unsigned int event )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: EventBase(event)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME classAttribute 'CONNECTION_STATUS'
const unsigned int Connection::Status::CONNECTION_STATUS( 1 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
Connection::Status::~Status( void )
{
}
// }}}RME

// {{{RME operation 'getType()'
ClassType Connection::Status::getType( void ) const
{
	// {{{USR
	return CONNECTION_STATUS;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool Connection::Status::isType( ClassType type ) const
{
	// {{{USR
	if (type == CONNECTION_STATUS)
	{
		return true;
	}
	else
	{
		return TypedBaseClass::isType(type);
	}
	// }}}USR
}
// }}}RME

// {{{RME operation 'isDataAvailable()'
bool Connection::Status::isDataAvailable( void ) const
{
	// {{{USR
	return true;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isAvailable()'
bool Connection::Status::isAvailable( void ) const
{
	// {{{USR
	return true;
	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME classifier 'ConnectionOption'

// {{{RME classAttribute 'CONNECTION_OPTION'
const unsigned int Connection::ConnectionOption::CONNECTION_OPTION( 3 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
Connection::ConnectionOption::ConnectionOption( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
Connection::ConnectionOption::~ConnectionOption( void )
{
}
// }}}RME

// {{{RME operation 'getType()'
ClassType Connection::ConnectionOption::getType( void ) const
{
	// {{{USR
	return CONNECTION_OPTION;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool Connection::ConnectionOption::isType( ClassType type ) const
{
	// {{{USR
	return (type == CONNECTION_OPTION)?true:Option::isType(type);
	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
Connection::~Connection( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Status' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Connections::Connection::Status::Event' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'ConnectionOption' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
