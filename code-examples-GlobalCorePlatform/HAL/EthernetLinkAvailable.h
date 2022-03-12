// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::LAN::Ethernet::Smsc::LAN91C96I::EthernetLinkAvailable'

#ifndef EthernetLinkAvailable_H
#define EthernetLinkAvailable_H

#ifdef PRAGMA
#pragma interface "EthernetLinkAvailable.h"
#endif

#include <serial_comp.h>
#include <EventBase.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class EthernetLinkAvailable : public EventBase
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
	// {{{RME classAttribute 'ETHERNET_LINK_AVAILABLE'
	static unsigned int ETHERNET_LINK_AVAILABLE;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~EthernetLinkAvailable( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	EthernetLinkAvailable( const EthernetLinkAvailable & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	EthernetLinkAvailable & operator=( const EthernetLinkAvailable & rtg_arg );
	// }}}RME
	// {{{RME operation 'EthernetLinkAvailable()'
	EthernetLinkAvailable( void );
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

#endif /* EthernetLinkAvailable_H */

// }}}RME
