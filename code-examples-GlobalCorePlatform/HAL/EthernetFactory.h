// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::LAN::Ethernet::Smsc::LAN91C96I::EthernetFactory'

#ifndef EthernetFactory_H
#define EthernetFactory_H

#ifdef PRAGMA
#pragma interface "EthernetFactory.h"
#endif

#include <serial_comp.h>
class IOVirtualSerial;
class Lan91c96i;
class Lan91c96iConfig;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class EthernetFactory
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
	// {{{RME operation 'EthernetFactory()'
	EthernetFactory( void );
	// }}}RME
	// {{{RME operation 'getIOVirtualSerial(Lan91c96iConfig*)'
	IOVirtualSerial * getIOVirtualSerial( Lan91c96iConfig * config );
	// }}}RME
	// {{{RME operation '~EthernetFactory()'
	~EthernetFactory( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* EthernetFactory_H */

// }}}RME
