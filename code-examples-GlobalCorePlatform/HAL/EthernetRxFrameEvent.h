// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::LAN::Ethernet::Smsc::LAN91C96I::EthernetRxFrameEvent'

#ifndef EthernetRxFrameEvent_H
#define EthernetRxFrameEvent_H

#ifdef PRAGMA
#pragma interface "EthernetRxFrameEvent.h"
#endif

#include <serial_comp.h>
#include <EventBase.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class EthernetRxFrameEvent : public EventBase
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
	// {{{RME classAttribute 'ETHERNET_RX_FULL_EVENT'
	static const unsigned int ETHERNET_RX_FULL_EVENT;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~EthernetRxFrameEvent( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	EthernetRxFrameEvent( const EthernetRxFrameEvent & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	EthernetRxFrameEvent & operator=( const EthernetRxFrameEvent & rtg_arg );
	// }}}RME
	// {{{RME operation 'EthernetRxFrameEvent()'
	EthernetRxFrameEvent( void );
	// }}}RME
	// {{{RME operation 'getEvent()'
	virtual unsigned int getEvent( void ) const;
	// }}}RME
	// {{{RME operation 'isType(ClassType)'
	virtual bool isType( ClassType type ) const;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* EthernetRxFrameEvent_H */

// }}}RME
