// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OneWire_Interface::DeviceDrivers::Device-specific drivers::DeviceDS1994'

#ifndef DeviceDS1994_H
#define DeviceDS1994_H

#ifdef PRAGMA
#pragma interface "DeviceDS1994.h"
#endif

#include <serial_comp.h>
#include <OneWireMemoryDevice.h>
#include <OneWireRTC.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class DeviceDS1994 : public OneWireRTC, public OneWireMemoryDevice
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
	static unsigned int CMD_READ_SCRATCHPAD_SIZE;
	// }}}RME
	// {{{RME classAttribute 'CMD_COPY_SCRATCHPAD_TO_EEPROM'
	static const unsigned char CMD_COPY_SCRATCHPAD_TO_EEPROM;
	// }}}RME
	// {{{RME classAttribute 'CMD_COPY_SCRATCHPAD_TO_EEPROM_SIZE'
	static const unsigned int CMD_COPY_SCRATCHPAD_TO_EEPROM_SIZE;
	// }}}RME
	// {{{RME classAttribute 'CMD_READ_EEPROM'
	static const unsigned char CMD_READ_EEPROM;
	// }}}RME
	// {{{RME classAttribute 'CMD_READ_EEPROM_SIZE'
	static const unsigned int CMD_READ_EEPROM_SIZE;
	// }}}RME
	// {{{RME classAttribute 'DS1994_SCRATCHPAD_SIZE'
	static const unsigned int DS1994_SCRATCHPAD_SIZE;
	// }}}RME
	// {{{RME classAttribute 'DS1994_MEMORY_SIZE'
	static const unsigned int DS1994_MEMORY_SIZE;
	// }}}RME
	// {{{RME classAttribute 'DS1994_RTC_BASE_ADDR'
	static const uint16_t DS1994_RTC_BASE_ADDR;
	// }}}RME
	// {{{RME classAttribute 'RTC_STATUS'
	static const uint16_t RTC_STATUS;
	// }}}RME
	// {{{RME classAttribute 'RTC_CTRL'
	static const uint16_t RTC_CTRL;
	// }}}RME
	// {{{RME classAttribute 'RTC_COUNTER'
	static const uint16_t RTC_COUNTER;
	// }}}RME
	// {{{RME classAttribute 'ENABLE_OSCILLATOR'
	static const unsigned char ENABLE_OSCILLATOR;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	DeviceDS1994( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~DeviceDS1994( void );
	// }}}RME
	// {{{RME operation 'DeviceDS1994(OneWireConnection*)'
	DeviceDS1994( OneWireConnection * connection );
	// }}}RME
	// {{{RME operation 'readMemory(unsigned int,unsigned int)'
	virtual unsigned char * readMemory( unsigned int address, unsigned int length );
	// }}}RME
	// {{{RME operation 'writeMemory(unsigned int,unsigned char*,unsigned int)'
	virtual bool writeMemory( unsigned int address, unsigned char * block, unsigned int length );
	// }}}RME
	// {{{RME operation 'setAlarm(const RTCVirtual::RTCTimeSpec*)'
	virtual void setAlarm( const RTCVirtual::RTCTimeSpec * time );
	// }}}RME
	// {{{RME operation 'setTime(RTCVirtual::RTCTimeSpec*)'
	virtual void setTime( RTCVirtual::RTCTimeSpec * time );
	// }}}RME
	// {{{RME operation 'readTime()'
	virtual RTCVirtual::RTCTimeSpec * readTime( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* DeviceDS1994_H */

// }}}RME
