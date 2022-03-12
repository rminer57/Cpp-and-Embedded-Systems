// {{{RME classifier 'Logical View::EventManagement::EventBase'

#ifndef EventBase_H
#define EventBase_H

#ifdef PRAGMA
#pragma interface "EventBase.h"
#endif

#include <event_mgmt.h>
#include <TypedBaseClass.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class EventBase : public TypedBaseClass
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
	// {{{RME classAttribute 'BASIC_EVENT'
	static const unsigned int BASIC_EVENT;
	// }}}RME

protected:
	// {{{RME classAttribute 'm_event'
	unsigned int m_event;
	// }}}RME

public:
	// {{{RME classAttribute 'UNKNOWN'
	static const unsigned int UNKNOWN;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~EventBase( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	EventBase( const EventBase & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	EventBase & operator=( const EventBase & rtg_arg );
	// }}}RME
	// {{{RME operation 'isType(ClassType)'
	virtual bool isType( ClassType type ) const;
	// }}}RME
	// {{{RME operation 'getType()'
	virtual ClassType getType( void ) const;
	// }}}RME
	// {{{RME operation 'getEvent()'
	virtual unsigned int getEvent( void ) const;
	// }}}RME
	// {{{RME operation 'isEvent(unsigned int)'
	virtual bool isEvent( unsigned int event ) const;
	// }}}RME
	// {{{RME operation 'EventBase(unsigned int)'
	EventBase( unsigned int event = 0 );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* EventBase_H */

// }}}RME
