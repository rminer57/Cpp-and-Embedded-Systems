// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::LAN::Ethernet::Smsc::LAN91C96I::Lan91c96iIntSource'

#ifndef Lan91c96iIntSource_H
#define Lan91c96iIntSource_H

#ifdef PRAGMA
#pragma interface "Lan91c96iIntSource.h"
#endif

#include <serial_comp.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'TX_IDLE_INT'
#define TX_IDLE_INT 0x80
// }}}RME

// {{{RME classAttribute 'ERCV_INT'
#define ERCV_INT 0x40
// }}}RME

// {{{RME classAttribute 'EPH_INT'
#define EPH_INT 0x20
// }}}RME

// {{{RME classAttribute 'RX_OVRN_INT'
#define RX_OVRN_INT 0x10
// }}}RME

// {{{RME classAttribute 'ALLOC_INT'
#define ALLOC_INT 0x08
// }}}RME

// {{{RME classAttribute 'TX_EMPTY_INT'
#define TX_EMPTY_INT 0x04
// }}}RME

// {{{RME classAttribute 'TX_INT'
#define TX_INT 0x02
// }}}RME

// {{{RME classAttribute 'RCV_INT'
#define RCV_INT 0x01
// }}}RME

// {{{RME classAttribute 'ALLOCATE_MEMORY'
#define ALLOCATE_MEMORY 0x02
// }}}RME

class Lan91c96iIntSource
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
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	Lan91c96iIntSource( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~Lan91c96iIntSource( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Lan91c96iIntSource_H */

// }}}RME
