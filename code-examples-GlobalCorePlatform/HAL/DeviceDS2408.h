// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OneWire_Interface::DeviceDrivers::Device-specific drivers::DeviceDS2408'

#ifndef DeviceDS2408_H
#define DeviceDS2408_H

#ifdef PRAGMA
#pragma interface "DeviceDS2408.h"
#endif

#include <serial_comp.h>
#include <OneWireIODevice.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class DeviceDS2408 : public OneWireIODevice
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
	// {{{RME classAttribute 'CMD_CHANNEL_ACCESS_WRITE'
	static const unsigned char CMD_CHANNEL_ACCESS_WRITE;
	// }}}RME
	// {{{RME classAttribute 'CMD_CHANNEL_ACCESS_WRITE_SIZE'
	static const unsigned int CMD_CHANNEL_ACCESS_WRITE_SIZE;
	// }}}RME
	// {{{RME classAttribute 'CMD_CHANNEL_ACCESS_READ'
	static const unsigned char CMD_CHANNEL_ACCESS_READ;
	// }}}RME
	// {{{RME classAttribute 'CMD_CHANNEL_ACCESS_READ_SIZE'
	static const unsigned int CMD_CHANNEL_ACCESS_READ_SIZE;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	DeviceDS2408( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~DeviceDS2408( void );
	// }}}RME
	// {{{RME operation 'DeviceDS2408(OneWireConnection*)'
	DeviceDS2408( OneWireConnection * connection );
	// }}}RME
	// {{{RME operation 'send(unsigned int)'
	virtual void send( unsigned int data );
	// }}}RME
	// {{{RME operation 'receive()'
	virtual unsigned int receive( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* DeviceDS2408_H */

// }}}RME
