// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OneWire_Interface::DeviceDrivers::Device-specific drivers::DeviceDS2423'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "DeviceDS2423.h"
#endif

#include <serial_comp.h>
#include <DeviceDS2423.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'CMD_WRITE_SCRATCHPAD'
const unsigned char DeviceDS2423::CMD_WRITE_SCRATCHPAD( 0x0F );
// }}}RME

// {{{RME classAttribute 'CMD_WRITE_SCRATCHPAD_SIZE'
const unsigned int DeviceDS2423::CMD_WRITE_SCRATCHPAD_SIZE( 3 );
// }}}RME

// {{{RME classAttribute 'CMD_READ_SCRATCHPAD'
const unsigned char DeviceDS2423::CMD_READ_SCRATCHPAD( 0xAA );
// }}}RME

// {{{RME classAttribute 'CMD_READ_SCRATCHPAD_SIZE'
unsigned int DeviceDS2423::CMD_READ_SCRATCHPAD_SIZE( 1 );
// }}}RME

// {{{RME classAttribute 'CMD_COPY_SCRATCHPAD_TO_EEPROM'
const unsigned char DeviceDS2423::CMD_COPY_SCRATCHPAD_TO_EEPROM( 0x55 );
// }}}RME

// {{{RME classAttribute 'CMD_COPY_SCRATCHPAD_TO_EEPROM_SIZE'
const unsigned int DeviceDS2423::CMD_COPY_SCRATCHPAD_TO_EEPROM_SIZE( 4 );
// }}}RME

// {{{RME classAttribute 'CMD_READ_EEPROM'
const unsigned char DeviceDS2423::CMD_READ_EEPROM( 0xF0 );
// }}}RME

// {{{RME classAttribute 'CMD_READ_EEPROM_SIZE'
const unsigned int DeviceDS2423::CMD_READ_EEPROM_SIZE( 3 );
// }}}RME

// {{{RME classAttribute 'DS2423_SCRATCHPAD_SIZE'
const unsigned int DeviceDS2423::DS2423_SCRATCHPAD_SIZE( 32 );
// }}}RME

// {{{RME classAttribute 'DS2423_MEMORY_SIZE'
const unsigned int DeviceDS2423::DS2423_MEMORY_SIZE( 512 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
DeviceDS2423::DeviceDS2423( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
DeviceDS2423::~DeviceDS2423( void )
{
}
// }}}RME

// {{{RME operation 'readMemory(unsigned int,unsigned int)'
unsigned char * DeviceDS2423::readMemory( unsigned int address, unsigned int length )
{
	// {{{USR
	unsigned char* retVal = 0;
	char* txBuffer = 0;
	unsigned int i;

	// First validate the length

	if ( (length > 0) && ((address + length) <= DS2423_MEMORY_SIZE) )
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

	    if( status == false )
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
	        else
	        {
	          delete [] retVal;
	          retVal = 0;
	          break; // if receive returned null then quit
	        }
		  }

	    }

		// The memory read has completed, so the bus may be released.
		m_oneWireConnection->releaseBus();
	}

	return retVal;
	// }}}USR
}
// }}}RME

// {{{RME operation 'writeMemory(unsigned int,unsigned char*,unsigned int)'
bool DeviceDS2423::writeMemory( unsigned int address, unsigned char * block, unsigned int length )
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

	if ( (length > 0) && ((address + length) <= DS2423_MEMORY_SIZE) )
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

			scratchpadOffset = (offset & (DS2423_SCRATCHPAD_SIZE - 1));
			availableScratchpadSize = DS2423_SCRATCHPAD_SIZE - scratchpadOffset;

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

			m_txBuffer = new SCharArray(CMD_WRITE_SCRATCHPAD_SIZE+lengthToWrite, txBuffer,true);

			bool status = m_oneWireConnection->send(m_txBuffer);

	        if( status == false ) 
	        {
	          delete m_txBuffer;
	          fatalError = true;
	          break;
	        }

			m_oneWireConnection->releaseBus();

			m_oneWireConnection->acquireBus();

			// Read the scratchpad contents. The first three bytes will be used
			// for the copy command later.
			
			txBuffer = new char[CMD_READ_SCRATCHPAD_SIZE];

			txBuffer[0] = (char)CMD_READ_SCRATCHPAD;
			
			m_txBuffer = new SCharArray(CMD_READ_SCRATCHPAD_SIZE,txBuffer,true);

			status = m_oneWireConnection->send(m_txBuffer);

	        if( status == false ) 
	        {
	          delete m_txBuffer;
	          fatalError = true;
	          break;
	        }
			// Since we are about to read data that will be used in the copy
			// scratchpad command, go ahead and begin building that command now.

			txBuffer = new char[CMD_COPY_SCRATCHPAD_TO_EEPROM_SIZE];
			txBuffer[0] = (char)CMD_COPY_SCRATCHPAD_TO_EEPROM;
			
			m_rxBuffer = (SCharArray*)m_oneWireConnection->receive();
	        if( m_rxBuffer != 0 )
	        {
			  txBuffer[1] = (unsigned char)((*m_rxBuffer)[0]);
			  delete m_rxBuffer;
	        }
	        else
	        {
	          fatalError = true;
	          break;
	        }

			m_rxBuffer = (SCharArray*)m_oneWireConnection->receive();
	        if( m_rxBuffer != 0 )
	        {
			  txBuffer[2] = (unsigned char)((*m_rxBuffer)[0]);
			  delete m_rxBuffer;
	        }
	        else
	        {
	          fatalError = true;
	          break;
	        }

			m_rxBuffer = (SCharArray*)m_oneWireConnection->receive();
	        if( m_rxBuffer != 0 )
	        {
			  txBuffer[3] = (unsigned char)((*m_rxBuffer)[0]);
			  delete m_rxBuffer;
	        }
	        else
	        {
	          fatalError = true;
	          break;
	        }

			for (i=0;i<lengthToWrite;i++)
			{
				m_rxBuffer = (SCharArray*)m_oneWireConnection->receive();

	            if( m_rxBuffer != 0 )
	            {
				 delete m_rxBuffer;
	            }
	            else
	            {
	              fatalError = true;
	              break;
	            }
			}

			m_oneWireConnection->releaseBus();

			m_oneWireConnection->acquireBus();

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

// {{{RME operation 'DeviceDS2423(OneWireConnection*)'
DeviceDS2423::DeviceDS2423( OneWireConnection * connection )
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

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
