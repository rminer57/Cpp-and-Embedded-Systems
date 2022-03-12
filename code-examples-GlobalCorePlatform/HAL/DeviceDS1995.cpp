// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OneWire_Interface::DeviceDrivers::Device-specific drivers::DeviceDS1995'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "DeviceDS1995.h"
#endif

#include <serial_comp.h>
#include <DeviceDS1995.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'CMD_WRITE_SCRATCHPAD'
const unsigned char DeviceDS1995::CMD_WRITE_SCRATCHPAD( 0x0F );
// }}}RME

// {{{RME classAttribute 'CMD_WRITE_SCRATCHPAD_SIZE'
const unsigned int DeviceDS1995::CMD_WRITE_SCRATCHPAD_SIZE( 3 );
// }}}RME

// {{{RME classAttribute 'CMD_READ_SCRATCHPAD'
const unsigned char DeviceDS1995::CMD_READ_SCRATCHPAD( 0xAA );
// }}}RME

// {{{RME classAttribute 'CMD_READ_SCRATCHPAD_SIZE'
unsigned int DeviceDS1995::CMD_READ_SCRATCHPAD_SIZE( 1 );
// }}}RME

// {{{RME classAttribute 'CMD_COPY_SCRATCHPAD_TO_EEPROM'
const unsigned char DeviceDS1995::CMD_COPY_SCRATCHPAD_TO_EEPROM( 0x55 );
// }}}RME

// {{{RME classAttribute 'CMD_COPY_SCRATCHPAD_TO_EEPROM_SIZE'
const unsigned int DeviceDS1995::CMD_COPY_SCRATCHPAD_TO_EEPROM_SIZE( 4 );
// }}}RME

// {{{RME classAttribute 'CMD_READ_EEPROM'
const unsigned char DeviceDS1995::CMD_READ_EEPROM( 0xF0 );
// }}}RME

// {{{RME classAttribute 'CMD_READ_EEPROM_SIZE'
const unsigned int DeviceDS1995::CMD_READ_EEPROM_SIZE( 3 );
// }}}RME

// {{{RME classAttribute 'DS1995_SCRATCHPAD_SIZE'
const unsigned int DeviceDS1995::DS1995_SCRATCHPAD_SIZE( 32 );
// }}}RME

// {{{RME classAttribute 'DS1995_MEMORY_SIZE'
const unsigned int DeviceDS1995::DS1995_MEMORY_SIZE( 2048 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
DeviceDS1995::DeviceDS1995( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
DeviceDS1995::~DeviceDS1995( void )
{
}
// }}}RME

// {{{RME operation 'DeviceDS1995(OneWireConnection*)'
DeviceDS1995::DeviceDS1995( OneWireConnection * connection )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: OneWireMemoryDevice(connection)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'readMemory(unsigned int,unsigned int)'
unsigned char * DeviceDS1995::readMemory( unsigned int address, unsigned int length )
{
	// {{{USR
	unsigned char* retVal = 0;
	char* txBuffer = 0;
	unsigned int i;

	// First validate the length

	if ( (length > 0) && ((address + length) <= DS1995_MEMORY_SIZE) )
	{
		m_oneWireConnection->acquireBus();

		// Given valid input, a valid buffer will be returned.
		retVal = new unsigned char[length];

		txBuffer = new char[CMD_READ_EEPROM_SIZE];

		// First byte to send the the read command, followed by the LSB and MSB
		// of the target address, respectively

		txBuffer[0] = (char)CMD_READ_EEPROM;
		txBuffer[1] = (char)(address & 0xFF);
		txBuffer[2] = (char)(address >> 8);

		m_txBuffer = new SCharArray(CMD_READ_EEPROM_SIZE,txBuffer,true);
		
		bool status = m_oneWireConnection->send(m_txBuffer);
		
	     if( status == false ) // send failed, that's fatal
	     { 
	     	delete m_txBuffer;
	     	delete [] retVal;
	        retVal = 0;	
	     }
	     else
	     {

		// Start reading
		for (i=0;i<length;i++)
		{
		   m_rxBuffer = (SCharArray*)m_oneWireConnection->receive();

	           if( m_rxBuffer != 0 )
	           {
			  retVal[i] = (unsigned char)((*m_rxBuffer)[0]);
			  delete m_rxBuffer;
	           }
	           else // receive failed, that's fatal
	           {
	             delete [] retVal;
	             retVal = 0;	
	             break; // if receive returned null then its a fatal error so quit
	           }
		}

		// The memory read has completed, so the bus may be released.
		m_oneWireConnection->releaseBus();
		
	     }
	}

	return retVal;
	// }}}USR
}
// }}}RME

// {{{RME operation 'writeMemory(unsigned int,unsigned char*,unsigned int)'
bool DeviceDS1995::writeMemory( unsigned int address, unsigned char * block, unsigned int length )
{
	// {{{USR
	bool retVal = false;
	bool finished = false;
	char* txBuffer = 0;
	unsigned int i;
	unsigned int blockLength = length;
	unsigned int lengthToWrite;
	unsigned int scratchpadOffset = 0;
	unsigned int availableScratchpadSize;
	uint16_t offset;
	TimeSpec memoryWriteDelay(0,5000000);
	bool fatalError = false;

	// First validate the address and length

	if ( (length > 0) && ((address + length) <= DS1995_MEMORY_SIZE) )
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
			m_oneWireConnection->acquireBus();

			scratchpadOffset = (offset & 0x1F);
			availableScratchpadSize = DS1995_SCRATCHPAD_SIZE - scratchpadOffset;

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

			m_txBuffer = new SCharArray(CMD_WRITE_SCRATCHPAD_SIZE+lengthToWrite,
										txBuffer,true);

			bool status = m_oneWireConnection->send(m_txBuffer);

	        if( status == false )
	        { 
	          delete m_txBuffer;
	          fatalError = true;
	          break;
	        }

			m_oneWireConnection->releaseBus();

			m_oneWireConnection->acquireBus();

			// Copy the scratchpad to EEPROM.
			// Note that the block address and the least significant 5 bits of the ending
			// address are considered the "authorization code" for copying the data.

			txBuffer = new char[CMD_COPY_SCRATCHPAD_TO_EEPROM_SIZE];

			txBuffer[0] = (char)CMD_COPY_SCRATCHPAD_TO_EEPROM;
			txBuffer[1] = (char)(offset & 0xFF);
			txBuffer[2] = (char)(offset >> 8);
			txBuffer[3] = (char)( (offset + (lengthToWrite - 1)) & 0x1F );

			m_txBuffer = new SCharArray(CMD_COPY_SCRATCHPAD_TO_EEPROM_SIZE,txBuffer,true);

			status = m_oneWireConnection->send(m_txBuffer);
	        if( status == false )
	        {
	           delete m_txBuffer;
	           fatalError = true;
	           break;
	        }

			// It takes 5 ms to copy the scratchpad to EEPROM, so we must wait this long.
			Thread::nanosleep(memoryWriteDelay);

			// Release the bus. This is acceptable, since only this device driver
			// may communicate with the target DS2433 device. Thus, there is no
			// risk of anyone else modifying this DS2433's memory during this call.
			// Moreover, releasing the bus sends out a reset pulse.

			m_oneWireConnection->releaseBus();

			offset += lengthToWrite;
			blockLength -= lengthToWrite;

			finished = (blockLength != 0)?false:true;
		}

		delete[] block;

		if(fatalError == false) retVal = true;
	}

	return retVal;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
