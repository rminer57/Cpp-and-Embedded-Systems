// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::LAN::Ethernet::Smsc::LAN91C96I::Lan91c96iConfig'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Lan91c96iConfig.h"
#endif

#include <serial_comp.h>
#include <Lan91c96iConfig.h>
#include <IOVirtual.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
Lan91c96iConfig::Lan91c96iConfig( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
Lan91c96iConfig::~Lan91c96iConfig( void )
{
}
// }}}RME

// {{{RME operation 'Lan91c96iConfig(IOVirtual*,signed char*,unsigned int)'
Lan91c96iConfig::Lan91c96iConfig( IOVirtual * ioVirtual, signed char * ethernetMACSourceAddress, unsigned int lanBaseAddress )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	:m_lan91c96iBaseAddress(lanBaseAddress),m_ioVirtual(ioVirtual)
	// }}}USR
	// }}}RME
{
	// {{{USR
	unsigned int i;

	for(i = 0; i < 3; i++)
	   m_lan91C96IMacAddress[i] = ((ethernetMACSourceAddress[2*i]) & 0x00FF) | (((ethernetMACSourceAddress[2*i + 1]) & 0x00FF) << 8);

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
