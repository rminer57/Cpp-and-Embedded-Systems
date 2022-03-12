// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OneWire_Interface::DeviceDrivers::Device-specific drivers::DeviceDS2406'

#ifndef DeviceDS2406_H
#define DeviceDS2406_H

#ifdef PRAGMA
#pragma interface "DeviceDS2406.h"
#endif

#include <serial_comp.h>
#include <OneWireIODevice.h>
#include <OneWireMemoryDevice.h>
class IOVirtual;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class DeviceDS2406 : public OneWireMemoryDevice, public OneWireIODevice
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
	// {{{RME classAttribute 'CMD_WRITE_MEMORY'
	static const unsigned char CMD_WRITE_MEMORY;
	// }}}RME
	// {{{RME classAttribute 'CMD_WRITE_MEMORY_SIZE'
	static const unsigned int CMD_WRITE_MEMORY_SIZE;
	// }}}RME
	// {{{RME classAttribute 'CMD_READ_STATUS'
	static const unsigned char CMD_READ_STATUS;
	// }}}RME
	// {{{RME classAttribute 'CMD_READ_STATUS_SIZE'
	static unsigned int CMD_READ_STATUS_SIZE;
	// }}}RME
	// {{{RME classAttribute 'CMD_COPY_SCRATCHPAD_TO_RAM'
	static const unsigned char CMD_COPY_SCRATCHPAD_TO_RAM;
	// }}}RME
	// {{{RME classAttribute 'CMD_COPY_SCRATCHPAD_TO_RAM_SIZE'
	static const unsigned int CMD_COPY_SCRATCHPAD_TO_RAM_SIZE;
	// }}}RME
	// {{{RME classAttribute 'CMD_READ_EPROM'
	static const unsigned char CMD_READ_EPROM;
	// }}}RME
	// {{{RME classAttribute 'CMD_READ_EPROM_SIZE'
	static const unsigned int CMD_READ_EPROM_SIZE;
	// }}}RME
	// {{{RME classAttribute 'DS2406_MEMORY_SIZE'
	static const unsigned int DS2406_MEMORY_SIZE;
	// }}}RME

public:
	// {{{RME classAttribute 'OPEN_A_OPEN_B'
	static const unsigned int OPEN_A_OPEN_B;
	// }}}RME
	// {{{RME classAttribute 'OPEN_A_CLOSE_B'
	static const unsigned int OPEN_A_CLOSE_B;
	// }}}RME
	// {{{RME classAttribute 'CLOSE_A_OPEN_B'
	static const unsigned int CLOSE_A_OPEN_B;
	// }}}RME
	// {{{RME classAttribute 'CLOSE_A_CLOSE_B'
	static const unsigned int CLOSE_A_CLOSE_B;
	// }}}RME

protected:
	// {{{RME classAttribute 'CMD_CHANNEL_ACCESS'
	static const unsigned char CMD_CHANNEL_ACCESS;
	// }}}RME
	// {{{RME classAttribute 'CMD_CHANNEL_ACCESS_SIZE'
	static const unsigned int CMD_CHANNEL_ACCESS_SIZE;
	// }}}RME
	// {{{RME classAttribute 'DS2406_SCRATCHPAD_SIZE'
	static const unsigned int DS2406_SCRATCHPAD_SIZE;
	// }}}RME
	// {{{RME classAttribute 'CMD_WRITE_STATUS'
	static const unsigned char CMD_WRITE_STATUS;
	// }}}RME
	// {{{RME classAttribute 'CMD_WRITE_STATUS_SIZE'
	static const unsigned int CMD_WRITE_STATUS_SIZE;
	// }}}RME
	// {{{RME classAttribute 'CMD_EXTENDED_READ_MEMORY'
	static const unsigned char CMD_EXTENDED_READ_MEMORY;
	// }}}RME
	// {{{RME classAttribute 'DS2406_PAGE_SIZE'
	static const unsigned int DS2406_PAGE_SIZE;
	// }}}RME
	// {{{RME classAttribute 'DS2406_STATUS_BASE_ADDRESS'
	static const uint16_t DS2406_STATUS_BASE_ADDRESS;
	// }}}RME
	// {{{RME classAttribute 'DS2406_STATUS_REDIRECT_OFFSET'
	static const uint16_t DS2406_STATUS_REDIRECT_OFFSET;
	// }}}RME
	// {{{RME classAttribute 'DS2406_PAGE_NUMBER_SHIFT'
	static const unsigned int DS2406_PAGE_NUMBER_SHIFT;
	// }}}RME
	// {{{RME classAttribute 'PATTERN_OPEN_A_OPEN_B'
	static const unsigned char PATTERN_OPEN_A_OPEN_B;
	// }}}RME
	// {{{RME classAttribute 'PATTERN_OPEN_A_CLOSE_B'
	static unsigned char PATTERN_OPEN_A_CLOSE_B;
	// }}}RME
	// {{{RME classAttribute 'PATTERN_CLOSE_A_OPEN_B'
	static const unsigned char PATTERN_CLOSE_A_OPEN_B;
	// }}}RME
	// {{{RME classAttribute 'PATTERN_CLOSE_A_CLOSE_B'
	static const unsigned char PATTERN_CLOSE_A_CLOSE_B;
	// }}}RME
	// {{{RME classAttribute 'CTRL_WRITE_SWITCHES'
	static const unsigned char CTRL_WRITE_SWITCHES;
	// }}}RME
	// {{{RME classAttribute 'CTRL_READ_SWITCHES'
	static const unsigned char CTRL_READ_SWITCHES;
	// }}}RME
	// {{{RME associationEnd 'm_progPulse'
	IOVirtual * m_progPulse;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	DeviceDS2406( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~DeviceDS2406( void );
	// }}}RME
	// {{{RME operation 'readMemory(unsigned int,unsigned int)'
	virtual unsigned char * readMemory( unsigned int address, unsigned int length );
	// }}}RME
	// {{{RME operation 'writeMemory(unsigned int,unsigned char*,unsigned int)'
	virtual bool writeMemory( unsigned int address, unsigned char * block, unsigned int length );
	// }}}RME
	// {{{RME operation 'DeviceDS2406(OneWireConnection*,IOVirtual*)'
	DeviceDS2406( OneWireConnection * connection, IOVirtual * progPulse = 0 );
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

#endif /* DeviceDS2406_H */

// }}}RME
