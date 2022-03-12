// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::LAN::Ethernet::Smsc::LAN91C96I::EthernetTxEmptyEvent'

#ifndef EthernetTxEmptyEvent_H
#define EthernetTxEmptyEvent_H

#ifdef PRAGMA
#pragma interface "EthernetTxEmptyEvent.h"
#endif

#include <serial_comp.h>
#include <EventBase.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class EthernetTxEmptyEvent : public EventBase
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
	// {{{RME classAttribute 'ETHERNET_TX_EMPTY_EVENT'
	static const unsigned int ETHERNET_TX_EMPTY_EVENT;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~EthernetTxEmptyEvent( void );
	// }}}RME
	// {{{RME operation 'EthernetTxEmptyEvent()'
	EthernetTxEmptyEvent( void );
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

#endif /* EthernetTxEmptyEvent_H */

// }}}RME
