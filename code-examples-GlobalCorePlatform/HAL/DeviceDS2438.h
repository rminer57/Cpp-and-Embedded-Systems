// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OneWire_Interface::DeviceDrivers::Device-specific drivers::DeviceDS2438'

#ifndef DeviceDS2438_H
#define DeviceDS2438_H

#ifdef PRAGMA
#pragma interface "DeviceDS2438.h"
#endif

#include <serial_comp.h>
#include <OneWireMemoryDevice.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class DeviceDS2438 : public OneWireMemoryDevice
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
	// {{{RME classAttribute 'CMD_WRITE_SCRATCHPAD'
	static const unsigned char CMD_WRITE_SCRATCHPAD;
	// }}}RME
	// {{{RME classAttribute 'CMD_WRITE_SCRATCHPAD_SIZE'
	static const unsigned int CMD_WRITE_SCRATCHPAD_SIZE;
	// }}}RME
	// {{{RME classAttribute 'CMD_READ_SCRATCHPAD'
	static const unsigned char CMD_READ_SCRATCHPAD;
	// }}}RME
	// {{{RME classAttribute 'CMD_READ_SCRATCHPAD_SIZE'
	static const unsigned int CMD_READ_SCRATCHPAD_SIZE;
	// }}}RME
	// {{{RME classAttribute 'CMD_COPY_SCRATCHPAD_TO_EEPROM'
	static const unsigned char CMD_COPY_SCRATCHPAD_TO_EEPROM;
	// }}}RME
	// {{{RME classAttribute 'CMD_COPY_SCRATCHPAD_TO_EEPROM_SIZE'
	static const unsigned int CMD_COPY_SCRATCHPAD_TO_EEPROM_SIZE;
	// }}}RME
	// {{{RME classAttribute 'CMD_RECALL_SCRATCHPAD_FROM_EEPROM'
	static const unsigned char CMD_RECALL_SCRATCHPAD_FROM_EEPROM;
	// }}}RME
	// {{{RME classAttribute 'CMD_RECALL_SCRATCHPAD_FROM_EEPROM_SIZE'
	static const unsigned int CMD_RECALL_SCRATCHPAD_FROM_EEPROM_SIZE;
	// }}}RME
	// {{{RME classAttribute 'DS2438_PAGE_SIZE_WITH_CRC'
	static const unsigned int DS2438_PAGE_SIZE_WITH_CRC;
	// }}}RME
	// {{{RME classAttribute 'DS2438_MEMORY_SIZE'
	static const unsigned int DS2438_MEMORY_SIZE;
	// }}}RME
	// {{{RME classAttribute 'DS2438_PAGE_SIZE'
	static const unsigned int DS2438_PAGE_SIZE;
	// }}}RME
	// {{{RME classAttribute 'DS2438_PAGE_NUMBER_SHIFT'
	static const unsigned int DS2438_PAGE_NUMBER_SHIFT;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	DeviceDS2438( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~DeviceDS2438( void );
	// }}}RME
	// {{{RME operation 'readMemory(unsigned int,unsigned int)'
	virtual unsigned char * readMemory( unsigned int address, unsigned int length );
	// }}}RME
	// {{{RME operation 'writeMemory(unsigned int,unsigned char*,unsigned int)'
	virtual bool writeMemory( unsigned int address, unsigned char * block, unsigned int length );
	// }}}RME

private:
	// {{{RME operation 'dallasOneWireCalculateCRC8(unsigned char*,unsigned int)'
	unsigned char dallasOneWireCalculateCRC8( unsigned char * byteArray, unsigned int size );
	// }}}RME

public:
	// {{{RME operation 'DeviceDS2438(OneWireConnection*)'
	DeviceDS2438( OneWireConnection * connection );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* DeviceDS2438_H */

// }}}RME
