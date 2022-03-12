// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Serial IO::UART::RXThresholdEvent'

#ifndef RXThresholdEvent_H
#define RXThresholdEvent_H

#ifdef PRAGMA
#pragma interface "RXThresholdEvent.h"
#endif

#include <hal.h>
#include <Connection.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class RXThresholdEvent : public Connection::Status::Event
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
	// {{{RME classAttribute 'RX_THRESHOLD_EVENT'
	static const unsigned int RX_THRESHOLD_EVENT;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~RXThresholdEvent( void );
	// }}}RME
	// {{{RME operation 'getType()'
	virtual ClassType getType( void ) const;
	// }}}RME
	// {{{RME operation 'isType(ClassType)'
	virtual bool isType( ClassType type ) const;
	// }}}RME
	// {{{RME operation 'RXThresholdEvent()'
	RXThresholdEvent( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* RXThresholdEvent_H */

// }}}RME
