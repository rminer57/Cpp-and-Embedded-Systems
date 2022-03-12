// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::LAN::Ethernet::Smsc::LAN91C96I::EthernetFactory'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "EthernetFactory.h"
#endif

#include <serial_comp.h>
#include <EthernetFactory.h>
#include <IOVirtualSerial.h>
#include <Lan91c96i.h>
#include <Lan91c96iConfig.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'EthernetFactory()'
EthernetFactory::EthernetFactory( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'getIOVirtualSerial(Lan91c96iConfig*)'
IOVirtualSerial * EthernetFactory::getIOVirtualSerial( Lan91c96iConfig * config )
{
	// {{{USR
	return (new Lan91c96i(config));
	// }}}USR
}
// }}}RME

// {{{RME operation '~EthernetFactory()'
EthernetFactory::~EthernetFactory( void )
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
