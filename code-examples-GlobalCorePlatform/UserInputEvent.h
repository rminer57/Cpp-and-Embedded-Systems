// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::User IO::UserInputEvent'

#ifndef UserInputEvent_H
#define UserInputEvent_H

#ifdef PRAGMA
#pragma interface "UserInputEvent.h"
#endif

#include <hal.h>
#include <EventBase.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class UserInputEvent : public EventBase
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

protected:
	// {{{RME classAttribute 'm_inputCode'
	unsigned int m_inputCode;
	// }}}RME
	// {{{RME classAttribute 'm_inputStatus'
	unsigned int m_inputStatus;
	// }}}RME

public:
	// {{{RME classAttribute 'INPUT_EVENT'
	static const unsigned int INPUT_EVENT;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~UserInputEvent( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	UserInputEvent( const UserInputEvent & rtg_arg );
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
	// {{{RME operation 'UserInputEvent(unsigned int,unsigned int)'
	UserInputEvent( unsigned int inputCode = 0, unsigned int inputStatus = 0 );
	// }}}RME
	// {{{RME operation 'getInputCode()'
	virtual unsigned int getInputCode( void ) const;
	// }}}RME
	// {{{RME operation 'getInputStatus()'
	virtual unsigned int getInputStatus( void ) const;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* UserInputEvent_H */

// }}}RME
