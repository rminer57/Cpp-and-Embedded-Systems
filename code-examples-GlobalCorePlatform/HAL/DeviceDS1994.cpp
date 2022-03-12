// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OneWire_Interface::DeviceDrivers::Device-specific drivers::DeviceDS1994'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "DeviceDS1994.h"
#endif

#include <serial_comp.h>
#include <DeviceDS1994.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'CMD_WRITE_SCRATCHPAD'
const unsigned char DeviceDS1994::CMD_WRITE_SCRATCHPAD( 0x0F );
// }}}RME

// {{{RME classAttribute 'CMD_WRITE_SCRATCHPAD_SIZE'
const unsigned int DeviceDS1994::CMD_WRITE_SCRATCHPAD_SIZE( 3 );
// }}}RME

// {{{RME classAttribute 'CMD_READ_SCRATCHPAD'
const unsigned char DeviceDS1994::CMD_READ_SCRATCHPAD( 0xAA );
// }}}RME

// {{{RME classAttribute 'CMD_READ_SCRATCHPAD_SIZE'
unsigned int DeviceDS1994::CMD_READ_SCRATCHPAD_SIZE( 1 );
// }}}RME

// {{{RME classAttribute 'CMD_COPY_SCRATCHPAD_TO_EEPROM'
const unsigned char DeviceDS1994::CMD_COPY_SCRATCHPAD_TO_EEPROM( 0x55 );
// }}}RME

// {{{RME classAttribute 'CMD_COPY_SCRATCHPAD_TO_EEPROM_SIZE'
const unsigned int DeviceDS1994::CMD_COPY_SCRATCHPAD_TO_EEPROM_SIZE( 4 );
// }}}RME

// {{{RME classAttribute 'CMD_READ_EEPROM'
const unsigned char DeviceDS1994::CMD_READ_EEPROM( 0xF0 );
// }}}RME

// {{{RME classAttribute 'CMD_READ_EEPROM_SIZE'
const unsigned int DeviceDS1994::CMD_READ_EEPROM_SIZE( 3 );
// }}}RME

// {{{RME classAttribute 'DS1994_SCRATCHPAD_SIZE'
const unsigned int DeviceDS1994::DS1994_SCRATCHPAD_SIZE( 32 );
// }}}RME

// {{{RME classAttribute 'DS1994_MEMORY_SIZE'
const unsigned int DeviceDS1994::DS1994_MEMORY_SIZE( 544 );
// }}}RME

// {{{RME classAttribute 'DS1994_RTC_BASE_ADDR'
const uint16_t DeviceDS1994::DS1994_RTC_BASE_ADDR( 0x0200 );
// }}}RME

// {{{RME classAttribute 'RTC_STATUS'
const uint16_t DeviceDS1994::RTC_STATUS( 0x0000 );
// }}}RME

// {{{RME classAttribute 'RTC_CTRL'
const uint16_t DeviceDS1994::RTC_CTRL( 0x0001 );
// }}}RME

// {{{RME classAttribute 'RTC_COUNTER'
const uint16_t DeviceDS1994::RTC_COUNTER( 0x0002 );
// }}}RME

// {{{RME classAttribute 'ENABLE_OSCILLATOR'
const unsigned char DeviceDS1994::ENABLE_OSCILLATOR( 0x10 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
DeviceDS1994::DeviceDS1994( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
DeviceDS1994::~DeviceDS1994( void )
{
}
// }}}RME

// {{{RME operation 'DeviceDS1994(OneWireConnection*)'
DeviceDS1994::DeviceDS1994( OneWireConnection * connection )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: OneWireMemoryDevice(connection)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// Need to enable the oscillator, if it isn't already enabled.

	unsigned char * commandByte = new unsigned char[1];

	commandByte[0] = ENABLE_OSCILLATOR;

	writeMemory(DS1994_RTC_BASE_ADDR+RTC_CTRL,commandByte,1);
	// }}}USR
}
// }}}RME

// {{{RME operation 'readMemory(unsigned int,unsigned int)'
unsigned char * DeviceDS1994::readMemory( unsigned int address, unsigned int length )
{
	// {{{USR
	unsigned char* retVal = 0;
	char* txBuffer = 0;
	unsigned int i;

	// Note the usage of scope resolution operators (::) throughout this function.
	// This was required due to the multiple inheritance paths to OneWireDevice,
	// so that the references would be unambiguous to the compiler.

	// First validate the length

	if ( (length > 0) && ((address + length) <= DS1994_MEMORY_SIZE) )
	{
		OneWireMemoryDevice::m_oneWireConnection->acquireBus();

		// Given valid input, a valid buffer will be returned.
		retVal = new unsigned char[length];

		txBuffer = new char[CMD_READ_EEPROM_SIZE];

		// First byte to send the the read command, followed by the LSB and MSB
		// of the target address, respectively

		txBuffer[0] = (char)CMD_READ_EEPROM;
		txBuffer[1] = (char)(address & 0xFF);
		txBuffer[2] = (char)(address >> 8);

	    OneWireMemoryDevice::m_txBuffer = new SCharArray(CMD_READ_EEPROM_SIZE,txBuffer,true);
	    
	    bool status = OneWireMemoryDevice::m_oneWireConnection->send(OneWireMemoryDevice::m_txBuffer);
	    
	    if( status == false ) // indicates the send didn't work. This is fatal.
	    {
	    	 delete OneWireMemoryDevice::m_txBuffer;
	    	 delete [] retVal;
	    	 retVal = 0;
	    }
	    else
	    {

		  // Start reading
		  for (i=0;i<length;i++)
		  {
			  OneWireMemoryDevice::m_rxBuffer = (SCharArray*)OneWireMemoryDevice::m_oneWireConnection->receive();

	          if( OneWireMemoryDevice::m_rxBuffer != 0 )
	          {
			  retVal[i] = (unsigned char)((*OneWireMemoryDevice::m_rxBuffer)[0]);
			  delete OneWireMemoryDevice::m_rxBuffer;
	          }
	          else // indicates receive didn't work, this is fatal.
	          {
	             delete [] retVal;
	    	     retVal = 0;
	             break; // exit if receive returned a null - its a fatal error.
	          }
	      }

	    }


	} // end if ( (length > 0) ...

	// The memory read has completed, so the bus may be released.
	OneWireMemoryDevice::m_oneWireConnection->releaseBus();


	return retVal;
	// }}}USR
}
// }}}RME

// {{{RME operation 'writeMemory(unsigned int,unsigned char*,unsigned int)'
bool DeviceDS1994::writeMemory( unsigned int address, unsigned char * block, unsigned int length )
{
	// {{{USR
	bool retVal = false;
	bool finished = false;
	char* txBuffer = 0;
	unsigned int i;
	unsigned int blockLength = length; // define and initialize local variable that will be decremented by while loop.
	unsigned int lengthToWrite;
	unsigned int scratchpadOffset = 0;
	unsigned int availableScratchpadSize;
	uint16_t offset;
	TimeSpec memoryWriteDelay(0,5000000);
	bool fatalError = false;

	// Note the usage of scope resolution operators (::) throughout this function.
	// This was required due to the multiple inheritance paths to OneWireDevice,
	// so that the references would be unambiguous to the compiler.

	// First validate the address and length

	if ( (length > 0) && ((address + length) <= DS1994_MEMORY_SIZE) )
	{
		offset = (uint16_t)address;

		// Data must be written to the scratchpad first and then copied to memory.
		// If the amount of data to be written is greater than the scratchpad size,
		// then the memory write will require several iterations of filling the
		// scratchpad and copying the scratchpad to EEPROM.  The lower five bits of
		// the target address for each write to the scratchpad determine the offset
		// into the scratchpad where the device will begin writing data.

		while(!finished)
		{
			OneWireMemoryDevice::m_oneWireConnection->acquireBus();

			scratchpadOffset = (offset & 0x1F);
			availableScratchpadSize = DS1994_SCRATCHPAD_SIZE - scratchpadOffset;

			lengthToWrite = (blockLength >= availableScratchpadSize)?availableScratchpadSize:blockLength;

			txBuffer = new char[CMD_WRITE_SCRATCHPAD_SIZE+lengthToWrite];

			// Send the write scratchpad command, followed by the LSB and MSB of the
			// target address, respectively, then the data

			txBuffer[0] = (char)CMD_WRITE_SCRATCHPAD;
			txBuffer[1] = (char)(offset & 0xFF);
			txBuffer[2] = (char)(offset >> 8);

			for (i=0;i<lengthToWrite;i++)
			{
				txBuffer[i+3] = (char)block[(offset-address)+i];
			}

			OneWireMemoryDevice::m_txBuffer = new SCharArray(CMD_WRITE_SCRATCHPAD_SIZE+lengthToWrite,
										txBuffer,true);

			bool status = OneWireMemoryDevice::m_oneWireConnection->send(OneWireMemoryDevice::m_txBuffer);
	                if( status == false ) 
	                {
	                   delete OneWireMemoryDevice::m_txBuffer;
	                   fatalError = true;
	                   break;
	                }

			OneWireMemoryDevice::m_oneWireConnection->releaseBus();

			OneWireMemoryDevice::m_oneWireConnection->acquireBus();

			// Copy the scratchpad to EEPROM.
			// Note that the block address and the least significant 5 bits of the ending
			// address are considered the "authorization code" for copying the data.

			txBuffer = new char[CMD_COPY_SCRATCHPAD_TO_EEPROM_SIZE];

			txBuffer[0] = (char)CMD_COPY_SCRATCHPAD_TO_EEPROM;
			txBuffer[1] = (char)(offset & 0xFF);
			txBuffer[2] = (char)(offset >> 8);
			txBuffer[3] = (char)( (offset + (lengthToWrite - 1)) & 0x1F );

			OneWireMemoryDevice::m_txBuffer = new SCharArray(CMD_COPY_SCRATCHPAD_TO_EEPROM_SIZE,txBuffer,true);

			status = OneWireMemoryDevice::m_oneWireConnection->send(OneWireMemoryDevice::m_txBuffer);
			if( status == false ) 
			{
			   delete OneWireMemoryDevice::m_txBuffer;
			   fatalError = true;
			   break;
			}

			// It takes 5 ms to copy the scratchpad to EEPROM, so we must wait this long.
			Thread::nanosleep(memoryWriteDelay);

			// Release the bus. This is acceptable, since only this device driver
			// may communicate with the target DS2433 device. Thus, there is no
			// risk of anyone else modifying this DS2433's memory during this call.
			// Moreover, releasing the bus sends out a reset pulse.

			OneWireMemoryDevice::m_oneWireConnection->releaseBus();

			offset += lengthToWrite;
			blockLength -= lengthToWrite;

			finished = (blockLength != 0)?false:true;
			
		} // end while

		delete[] block;

		if(fatalError == false) retVal = true;
	}

	return retVal;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setAlarm(const RTCVirtual::RTCTimeSpec*)'
void DeviceDS1994::setAlarm( const RTCVirtual::RTCTimeSpec * time )
{
	// {{{USR
	return;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setTime(RTCVirtual::RTCTimeSpec*)'
void DeviceDS1994::setTime( RTCVirtual::RTCTimeSpec * time )
{
	// {{{USR
	tm timeToSet;
	uint32_t secondsToSet;
	unsigned char* timeString;
	unsigned int i;

	// First populate a tm structure with the passed-in date/time information.
	// The tm structure is used by the time.h functions.

	timeToSet.tm_hour = time->m_hours;
	timeToSet.tm_mday = time->m_day;
	timeToSet.tm_min = time->m_minutes;
	timeToSet.tm_mon = time->m_month-1;
	timeToSet.tm_sec = time->m_seconds;
	timeToSet.tm_year = time->m_year-1900;
	timeToSet.tm_isdst = 0;

	secondsToSet = (uint32_t)mktime(&timeToSet);
	timeString = new unsigned char[5];

	// LSB is fractional seconds, which we won't use

	timeString[0] = 0;

	for (i=0;i<4;i++)
	{
		timeString[i+1] = secondsToSet & 0xFF;
		secondsToSet >>= 8;
	}

	// Write the desired seconds to the clock register
	writeMemory(DS1994_RTC_BASE_ADDR+RTC_COUNTER,timeString,5);
	// }}}USR
}
// }}}RME

// {{{RME operation 'readTime()'
RTCVirtual::RTCTimeSpec * DeviceDS1994::readTime( void )
{
	// {{{USR
	RTCVirtual::RTCTimeSpec* retVal = 0;
	struct tm* timeToGet;
	time_t seconds;
	uint32_t secondsToGet = 0;
	unsigned char* timeString = 0;
	unsigned int i;

	// First read the clock register
	timeString = readMemory(DS1994_RTC_BASE_ADDR+RTC_COUNTER,5);

	// Convert the received array into a number

	for (i=0;i<4;i++)
	{
		secondsToGet |= ((uint32_t)timeString[i+1]) << i*8;
	}


	// Convert the received seconds to a tm structure, then
	// populate the return value.

	seconds = (time_t)secondsToGet;

	timeToGet = localtime(&seconds);

	retVal = new RTCVirtual::RTCTimeSpec();


	retVal->m_hours = timeToGet->tm_hour;
	retVal->m_day = timeToGet->tm_mday;
	retVal->m_minutes = timeToGet->tm_min;
	retVal->m_month = timeToGet->tm_mon+1;
	retVal->m_seconds = timeToGet->tm_sec;
	retVal->m_year = timeToGet->tm_year+1900;

	delete timeString;

	return retVal;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
