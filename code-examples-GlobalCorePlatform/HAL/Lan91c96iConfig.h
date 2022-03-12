// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::LAN::Ethernet::Smsc::LAN91C96I::Lan91c96iConfig'

#ifndef Lan91c96iConfig_H
#define Lan91c96iConfig_H

#ifdef PRAGMA
#pragma interface "Lan91c96iConfig.h"
#endif

#include <serial_comp.h>
class IOVirtual;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>
// }}}USR
// }}}RME

class Lan91c96iConfig
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
	// {{{RME classAttribute 'm_lan91C96IMacAddress'
	unsigned short m_lan91C96IMacAddress[ 3 ];
	// }}}RME
	// {{{RME classAttribute 'm_lan91c96iBaseAddress'
	unsigned int m_lan91c96iBaseAddress;
	// }}}RME
	// {{{RME classAttribute 'm_ioVirtual'
	IOVirtual * m_ioVirtual;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	Lan91c96iConfig( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~Lan91c96iConfig( void );
	// }}}RME
	// {{{RME operation 'Lan91c96iConfig(IOVirtual*,signed char*,unsigned int)'
	Lan91c96iConfig( IOVirtual * ioVirtual, signed char * ethernetMACSourceAddress, unsigned int lanBaseAddress );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Lan91c96iConfig_H */

// }}}RME
