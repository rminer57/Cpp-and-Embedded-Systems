// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OneWire_Interface::DeviceDrivers::Device-specific drivers::DeviceDS2405'

#ifndef DeviceDS2405_H
#define DeviceDS2405_H

#ifdef PRAGMA
#pragma interface "DeviceDS2405.h"
#endif

#include <serial_comp.h>
#include <OneWireIODevice.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class DeviceDS2405 : public OneWireIODevice
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

protected:
	// {{{RME classAttribute 'm_pioState'
	unsigned int m_pioState;
	// }}}RME
	// {{{RME classAttribute 'm_activeHigh'
	bool m_activeHigh;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	DeviceDS2405( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~DeviceDS2405( void );
	// }}}RME
	// {{{RME operation 'send(unsigned int)'
	virtual void send( unsigned int data );
	// }}}RME
	// {{{RME operation 'DeviceDS2405(OneWireConnection*,bool)'
	DeviceDS2405( OneWireConnection * connection, bool activeHigh );
	// }}}RME
	// {{{RME operation 'receive()'
	virtual unsigned int receive( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* DeviceDS2405_H */

// }}}RME
