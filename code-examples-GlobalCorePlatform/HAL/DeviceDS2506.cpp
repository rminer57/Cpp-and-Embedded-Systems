// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OneWire_Interface::DeviceDrivers::Device-specific drivers::DeviceDS2506'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "DeviceDS2506.h"
#endif

#include <serial_comp.h>
#include <DeviceDS2506.h>
#include <IOVirtual.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'CMD_WRITE_MEMORY'
const unsigned char DeviceDS2506::CMD_WRITE_MEMORY( 0x0F );
// }}}RME

// {{{RME classAttribute 'CMD_WRITE_MEMORY_SIZE'
const unsigned int DeviceDS2506::CMD_WRITE_MEMORY_SIZE( 3 );
// }}}RME

// {{{RME classAttribute 'CMD_READ_STATUS'
const unsigned char DeviceDS2506::CMD_READ_STATUS( 0xAA );
// }}}RME

// {{{RME classAttribute 'CMD_READ_STATUS_SIZE'
unsigned int DeviceDS2506::CMD_READ_STATUS_SIZE( 3 );
// }}}RME

// {{{RME classAttribute 'CMD_READ_EPROM'
const unsigned char DeviceDS2506::CMD_READ_EPROM( 0xF0 );
// }}}RME

// {{{RME classAttribute 'CMD_READ_EPROM_SIZE'
const unsigned int DeviceDS2506::CMD_READ_EPROM_SIZE( 3 );
// }}}RME

// {{{RME classAttribute 'DS2506_MEMORY_SIZE'
const unsigned int DeviceDS2506::DS2506_MEMORY_SIZE( 8192 );
// }}}RME

// {{{RME classAttribute 'DS2506_SCRATCHPAD_SIZE'
const unsigned int DeviceDS2506::DS2506_SCRATCHPAD_SIZE( 1 );
// }}}RME

// {{{RME classAttribute 'CMD_WRITE_STATUS'
const unsigned char DeviceDS2506::CMD_WRITE_STATUS( 0x55 );
// }}}RME

// {{{RME classAttribute 'CMD_WRITE_STATUS_SIZE'
const unsigned int DeviceDS2506::CMD_WRITE_STATUS_SIZE( 4 );
// }}}RME

// {{{RME classAttribute 'DS2506_PAGE_SIZE'
const unsigned int DeviceDS2506::DS2506_PAGE_SIZE( 32 );
// }}}RME

// {{{RME classAttribute 'DS2506_STATUS_BASE_ADDRESS'
const uint16_t DeviceDS2506::DS2506_STATUS_BASE_ADDRESS( 0x0000 );
// }}}RME

// {{{RME classAttribute 'DS2506_STATUS_REDIRECT_OFFSET'
const uint16_t DeviceDS2506::DS2506_STATUS_REDIRECT_OFFSET( 0x0100 );
// }}}RME

// {{{RME classAttribute 'DS2506_PAGE_NUMBER_SHIFT'
const unsigned int DeviceDS2506::DS2506_PAGE_NUMBER_SHIFT( 5 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
DeviceDS2506::DeviceDS2506( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
DeviceDS2506::~DeviceDS2506( void )
{
}
// }}}RME

// {{{RME operation 'readMemory(unsigned int,unsigned int)'
unsigned char * DeviceDS2506::readMemory( unsigned int address, unsigned int length )
{
	// {{{USR
	unsigned char* retVal = 0;
	unsigned char redirectionByte;
	uint16_t offset;
	uint16_t adjustedOffset;
	uint16_t statusRegisterAddress;
	char* txBuffer = 0;
	unsigned int i;
	unsigned int pageOffset = 0;
	unsigned int availablePageSize;
	unsigned int lengthToRead;
	unsigned int blockLength = length;
	unsigned int pageNumber;
	bool finished = false;

	// First validate the length

	if ( (length > 0) && ((address + length) <= DS2506_MEMORY_SIZE) )
	{
		offset = (uint16_t)address;

		// Given valid input, a valid buffer will be returned.
		retVal = new unsigned char[length];

		// If the requested data spans multiple memory pages, then the pages will be read
		// one at a time. Before data from any page is read, the redirection byte corresponding
		// to that page will be read.  If the redirection byte is anything other than 0xFF,
		// then its value is the one's complement of the number of the page that contains
		// the requested data.  Data will be read from that page instead.

		while (!finished)
		{
			OneWireMemoryDevice::m_oneWireConnection->acquireBus();

			pageOffset = (offset & (DS2506_PAGE_SIZE - 1));
			pageNumber = (offset & (~(DS2506_PAGE_SIZE - 1)));

			pageNumber >>= DS2506_PAGE_NUMBER_SHIFT;
			
			availablePageSize = DS2506_PAGE_SIZE - pageOffset;

			lengthToRead = (blockLength >= availablePageSize)?availablePageSize:blockLength;

			// First send the read status command to obtain the redirection byte.
			txBuffer = new char[CMD_READ_STATUS_SIZE];
			
			// First byte to send is the read command, followed by the LSB and MSB
			// of the target address, respectively

			txBuffer[0] = (char)CMD_READ_STATUS;

			statusRegisterAddress = DS2506_STATUS_BASE_ADDRESS +
									DS2506_STATUS_REDIRECT_OFFSET +
									(uint16_t)pageNumber;

			txBuffer[1] = (char)(statusRegisterAddress & 0xFF);
			txBuffer[2] = (char)(statusRegisterAddress >> 8);

			OneWireMemoryDevice::m_txBuffer = new SCharArray(CMD_READ_EPROM_SIZE,txBuffer,true);

			bool status = OneWireMemoryDevice::m_oneWireConnection->send(OneWireMemoryDevice::m_txBuffer);

	        if( status == false ) // send failed, that's fatal 
	        {
	         delete OneWireMemoryDevice::m_txBuffer;
	         delete [] retVal;
	         retVal = 0;
	         break;
	        }

			OneWireMemoryDevice::m_rxBuffer = (SCharArray*)OneWireMemoryDevice::m_oneWireConnection->receive();
	        if( OneWireMemoryDevice::m_rxBuffer != 0 )
	        {
			  redirectionByte = (unsigned char)((*OneWireMemoryDevice::m_rxBuffer)[0]);
			  delete OneWireMemoryDevice::m_rxBuffer;
	        }
	        else // receive failed, thats fatal
	        {
	          delete [] retVal;
	          retVal = 0;
	          break; // if receive returned null then error is fatal so break out of while loop
	        }

			// Now decide which page to read from
			if (redirectionByte == 0xFF)
			{
				// The original page contains the desired data. Continue as normal.
				adjustedOffset = offset;
			}
			else
			{
				// The data originally in the requested page is now in the redirected page.
				// Change the target address accordingly.
				redirectionByte = ~redirectionByte;
				redirectionByte <<= DS2506_PAGE_NUMBER_SHIFT;
				adjustedOffset = redirectionByte | pageOffset;
			}

			txBuffer = new char[CMD_READ_EPROM_SIZE];

			// First byte to send is the read command, followed by the LSB and MSB
			// of the target address, respectively

			txBuffer[0] = (char)CMD_READ_EPROM;
			txBuffer[1] = (char)(adjustedOffset & 0xFF);
			txBuffer[2] = (char)(adjustedOffset >> 8);

			OneWireMemoryDevice::m_txBuffer = new SCharArray(CMD_READ_EPROM_SIZE,txBuffer,true);

			status = OneWireMemoryDevice::m_oneWireConnection->send(OneWireMemoryDevice::m_txBuffer);

	        if( status == false ) // send failed, that's fatal 
	        {
	          delete OneWireMemoryDevice::m_txBuffer;
	          delete [] retVal;
	          retVal = 0;
	        }
	        else
	        {

			  // Start reading
			  for (i=0;i<lengthToRead;i++)
			  {
				OneWireMemoryDevice::m_rxBuffer = (SCharArray*)OneWireMemoryDevice::m_oneWireConnection->receive();
	            
	            if( OneWireMemoryDevice::m_rxBuffer != 0 )
	            {
				  retVal[(offset-address)+i] = (unsigned char)((*OneWireMemoryDevice::m_rxBuffer)[0]);
				  delete OneWireMemoryDevice::m_rxBuffer;
	            }
	            else // receive failed, thats fatal
	            {
	              retVal = 0;
	              break; // if null pointer returned from receive then quit and return null.
	            }
			  }

			  // The memory read has completed, so the bus may be released.
			  OneWireMemoryDevice::m_oneWireConnection->releaseBus();

			  offset += lengthToRead;
			  blockLength -= lengthToRead;

			  finished = (blockLength != 0)?false:true;
	        }
		} // end while
	}
	return retVal;
	// }}}USR
}
// }}}RME

// {{{RME operation 'writeMemory(unsigned int,unsigned char*,unsigned int)'
bool DeviceDS2506::writeMemory( unsigned int address, unsigned char * block, unsigned int length )
{
	// {{{USR
	bool retVal = false;
	bool finished = false;
	char* txBuffer = 0;
	unsigned int i;
	unsigned int blockLength = length; // define and init local counter decremented in while loop
	unsigned int lengthToWrite;
	unsigned int scratchpadOffset = 0;
	unsigned int availableScratchpadSize;
	uint16_t offset;
	TimeSpec memoryWriteDelay(0,480000);
	bool fatalError = false;

	// Note the usage of scope resolution operators (::) throughout this function.
	// This was required due to the multiple inheritance paths to OneWireDevice,
	// so that the references would be unambiguous to the compiler.

	// First validate the address and length

	if ( (length > 0) && ((address + length) <= DS2506_MEMORY_SIZE) )
	{
		offset = (uint16_t)address;

		// Data must be written to the scratchpad first and then copied to memory.
		// If the amount of data to be written is greater than the scratchpad size,
		// then the memory write will require several iterations of filling the
		// scratchpad and copying the scratchpad to EPROM.

		OneWireMemoryDevice::m_oneWireConnection->acquireBus();

		// Send the write memory command, followed by the LSB and MSB of the
		// target address, respectively.

		txBuffer = new char[CMD_WRITE_MEMORY_SIZE];

		txBuffer[0] = (char)CMD_WRITE_MEMORY;
		txBuffer[1] = (char)(offset & 0xFF);
		txBuffer[2] = (char)(offset >> 8);

		OneWireMemoryDevice::m_txBuffer = new SCharArray(CMD_WRITE_MEMORY_SIZE,	txBuffer,true);

		bool status = OneWireMemoryDevice::m_oneWireConnection->send(OneWireMemoryDevice::m_txBuffer);
	    if( status == false ) 
	    {
	      delete OneWireMemoryDevice::m_txBuffer;
	      finished = true; // fatal error if send does not work - this will cause while loop to be skipped
	    }

		while(!finished)
		{
			scratchpadOffset = (offset & (DS2506_SCRATCHPAD_SIZE - 1));
			availableScratchpadSize = DS2506_SCRATCHPAD_SIZE - scratchpadOffset;

			lengthToWrite = (blockLength >= availableScratchpadSize)?availableScratchpadSize:blockLength;
			
			txBuffer = new char[lengthToWrite];

			for (i=0;i<lengthToWrite;i++)
			{
				txBuffer[i] = (char)block[(offset-address)+i];
			}

			OneWireMemoryDevice::m_txBuffer = new SCharArray(lengthToWrite,txBuffer,true);

			status = OneWireMemoryDevice::m_oneWireConnection->send(OneWireMemoryDevice::m_txBuffer);

	        if( status == false ) // send failed, thats fatal
	        { 
	          delete OneWireMemoryDevice::m_txBuffer;
	          fatalError = true;
	          break;
	        }

			// Receive the CRC16 of the sent data. This is not used in this implementation.

			OneWireMemoryDevice::m_rxBuffer = (SCharArray*)OneWireMemoryDevice::m_oneWireConnection->receive();
	        if( OneWireMemoryDevice::m_rxBuffer != 0 )
	        {
			  delete OneWireMemoryDevice::m_rxBuffer;
	        }
	        else // receive failed, thats fatal
	        {
	          fatalError = true;
	          break;
	        }

			OneWireMemoryDevice::m_rxBuffer = (SCharArray*)OneWireMemoryDevice::m_oneWireConnection->receive();
	        if( OneWireMemoryDevice::m_rxBuffer != 0 )
	        {
			  delete OneWireMemoryDevice::m_rxBuffer;
	        }
	        else // receive failed, thats fatal
	        {
	          fatalError = true;
	          break;
	        }

			// Copy the scratchpad to EPROM.
			// EPROM requires a 12V programming pulse at least 480us in duration.

			if (m_progPulse != 0)
			{
				m_progPulse->send(1);
			}
			
			Thread::nanosleep(memoryWriteDelay);

			if (m_progPulse != 0)
			{
				m_progPulse->send(0);
			}

			// Receive the sent byte. This is not used in this implementation.

			OneWireMemoryDevice::m_rxBuffer = (SCharArray*)OneWireMemoryDevice::m_oneWireConnection->receive();

	        if( OneWireMemoryDevice::m_rxBuffer != 0 )
	        {
			  delete OneWireMemoryDevice::m_rxBuffer;
	        }
	        else // receive failed, thats fatal
	        {
	          fatalError = true;
	          break;
	        }

			offset += lengthToWrite;
			blockLength -= lengthToWrite;

			finished = (blockLength != 0)?false:true;

		} // end while

		OneWireMemoryDevice::m_oneWireConnection->releaseBus();

		delete[] block;
		if(fatalError == false) retVal = true;
	}

	return retVal;
	// }}}USR
}
// }}}RME

// {{{RME operation 'DeviceDS2506(OneWireConnection*,IOVirtual*)'
DeviceDS2506::DeviceDS2506( OneWireConnection * connection, IOVirtual * progPulse )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: OneWireMemoryDevice(connection), m_progPulse(progPulse)
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
