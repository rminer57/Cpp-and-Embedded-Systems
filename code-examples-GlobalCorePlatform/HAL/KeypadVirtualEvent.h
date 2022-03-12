// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Keypad::KeypadVirtualEvent'

#ifndef KeypadVirtualEvent_H
#define KeypadVirtualEvent_H

#ifdef PRAGMA
#pragma interface "KeypadVirtualEvent.h"
#endif

#include <hal.h>
#include <EventBase.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class KeypadVirtualEvent : public EventBase
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
	// {{{RME classAttribute 'KEYPADVIRTUAL_BASIC_EVENT'
	static const unsigned int KEYPADVIRTUAL_BASIC_EVENT;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~KeypadVirtualEvent( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	KeypadVirtualEvent( const KeypadVirtualEvent & rtg_arg );
	// }}}RME
	// {{{RME operation 'isType(ClassType)'
	virtual bool isType( ClassType type ) const;
	// }}}RME
	// {{{RME operation 'getType()'
	virtual ClassType getType( void ) const;
	// }}}RME
	// {{{RME operation 'KeypadVirtualEvent()'
	KeypadVirtualEvent( void );
	// }}}RME
	// {{{RME operation 'getEvent()'
	virtual unsigned int getEvent( void ) const;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* KeypadVirtualEvent_H */

// }}}RME
