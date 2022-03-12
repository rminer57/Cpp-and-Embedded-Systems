// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::LAN::Ethernet::Smsc::LAN91C96I::EthernetLinkUnavailable'

#ifndef EthernetLinkUnavailable_H
#define EthernetLinkUnavailable_H

#ifdef PRAGMA
#pragma interface "EthernetLinkUnavailable.h"
#endif

#include <serial_comp.h>
#include <EventBase.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class EthernetLinkUnavailable : public EventBase
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
	// {{{RME classAttribute 'ETHERNET_LINK_UNAVAILABLE'
	static unsigned int ETHERNET_LINK_UNAVAILABLE;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~EthernetLinkUnavailable( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	EthernetLinkUnavailable( const EthernetLinkUnavailable & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	EthernetLinkUnavailable & operator=( const EthernetLinkUnavailable & rtg_arg );
	// }}}RME
	// {{{RME operation 'EthernetLinkUnavailable()'
	EthernetLinkUnavailable( void );
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

#endif /* EthernetLinkUnavailable_H */

// }}}RME
