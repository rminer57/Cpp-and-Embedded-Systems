// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OneWire_Interface::DeviceDrivers::Device-specific drivers::DeviceDS2406'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "DeviceDS2406.h"
#endif

#include <serial_comp.h>
#include <DeviceDS2406.h>
#include <IOVirtual.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'CMD_WRITE_MEMORY'
const unsigned char DeviceDS2406::CMD_WRITE_MEMORY( 0x0F );
// }}}RME

// {{{RME classAttribute 'CMD_WRITE_MEMORY_SIZE'
const unsigned int DeviceDS2406::CMD_WRITE_MEMORY_SIZE( 3 );
// }}}RME

// {{{RME classAttribute 'CMD_READ_STATUS'
const unsigned char DeviceDS2406::CMD_READ_STATUS( 0xAA );
// }}}RME

// {{{RME classAttribute 'CMD_READ_STATUS_SIZE'
unsigned int DeviceDS2406::CMD_READ_STATUS_SIZE( 3 );
// }}}RME

// {{{RME classAttribute 'CMD_COPY_SCRATCHPAD_TO_RAM'
const unsigned char DeviceDS2406::CMD_COPY_SCRATCHPAD_TO_RAM( 0xFF );
// }}}RME

// {{{RME classAttribute 'CMD_COPY_SCRATCHPAD_TO_RAM_SIZE'
const unsigned int DeviceDS2406::CMD_COPY_SCRATCHPAD_TO_RAM_SIZE( 1 );
// }}}RME

// {{{RME classAttribute 'CMD_READ_EPROM'
const unsigned char DeviceDS2406::CMD_READ_EPROM( 0xF0 );
// }}}RME

// {{{RME classAttribute 'CMD_READ_EPROM_SIZE'
const unsigned int DeviceDS2406::CMD_READ_EPROM_SIZE( 3 );
// }}}RME

// {{{RME classAttribute 'DS2406_MEMORY_SIZE'
const unsigned int DeviceDS2406::DS2406_MEMORY_SIZE( 128 );
// }}}RME

// {{{RME classAttribute 'OPEN_A_OPEN_B'
const unsigned int DeviceDS2406::OPEN_A_OPEN_B( 0 );
// }}}RME

// {{{RME classAttribute 'OPEN_A_CLOSE_B'
const unsigned int DeviceDS2406::OPEN_A_CLOSE_B( 1 );
// }}}RME

// {{{RME classAttribute 'CLOSE_A_OPEN_B'
const unsigned int DeviceDS2406::CLOSE_A_OPEN_B( 2 );
// }}}RME

// {{{RME classAttribute 'CLOSE_A_CLOSE_B'
const unsigned int DeviceDS2406::CLOSE_A_CLOSE_B( 3 );
// }}}RME

// {{{RME classAttribute 'CMD_CHANNEL_ACCESS'
const unsigned char DeviceDS2406::CMD_CHANNEL_ACCESS( 0xF5 );
// }}}RME

// {{{RME classAttribute 'CMD_CHANNEL_ACCESS_SIZE'
const unsigned int DeviceDS2406::CMD_CHANNEL_ACCESS_SIZE( 3 );
// }}}RME

// {{{RME classAttribute 'DS2406_SCRATCHPAD_SIZE'
const unsigned int DeviceDS2406::DS2406_SCRATCHPAD_SIZE( 1 );
// }}}RME

// {{{RME classAttribute 'CMD_WRITE_STATUS'
const unsigned char DeviceDS2406::CMD_WRITE_STATUS( 0x55 );
// }}}RME

// {{{RME classAttribute 'CMD_WRITE_STATUS_SIZE'
const unsigned int DeviceDS2406::CMD_WRITE_STATUS_SIZE( 4 );
// }}}RME

// {{{RME classAttribute 'CMD_EXTENDED_READ_MEMORY'
const unsigned char DeviceDS2406::CMD_EXTENDED_READ_MEMORY( 0xA5 );
// }}}RME

// {{{RME classAttribute 'DS2406_PAGE_SIZE'
const unsigned int DeviceDS2406::DS2406_PAGE_SIZE( 32 );
// }}}RME

// {{{RME classAttribute 'DS2406_STATUS_BASE_ADDRESS'
const uint16_t DeviceDS2406::DS2406_STATUS_BASE_ADDRESS( 0x0000 );
// }}}RME

// {{{RME classAttribute 'DS2406_STATUS_REDIRECT_OFFSET'
const uint16_t DeviceDS2406::DS2406_STATUS_REDIRECT_OFFSET( 0x0001 );
// }}}RME

// {{{RME classAttribute 'DS2406_PAGE_NUMBER_SHIFT'
const unsigned int DeviceDS2406::DS2406_PAGE_NUMBER_SHIFT( 5 );
// }}}RME

// {{{RME classAttribute 'PATTERN_OPEN_A_OPEN_B'
const unsigned char DeviceDS2406::PATTERN_OPEN_A_OPEN_B( 0x00 );
// }}}RME

// {{{RME classAttribute 'PATTERN_OPEN_A_CLOSE_B'
unsigned char DeviceDS2406::PATTERN_OPEN_A_CLOSE_B( 0x55 );
// }}}RME

// {{{RME classAttribute 'PATTERN_CLOSE_A_OPEN_B'
const unsigned char DeviceDS2406::PATTERN_CLOSE_A_OPEN_B( 0xAA );
// }}}RME

// {{{RME classAttribute 'PATTERN_CLOSE_A_CLOSE_B'
const unsigned char DeviceDS2406::PATTERN_CLOSE_A_CLOSE_B( 0xFF );
// }}}RME

// {{{RME classAttribute 'CTRL_WRITE_SWITCHES'
const unsigned char DeviceDS2406::CTRL_WRITE_SWITCHES( 0x1C );
// }}}RME

// {{{RME classAttribute 'CTRL_READ_SWITCHES'
const unsigned char DeviceDS2406::CTRL_READ_SWITCHES( 0x5C );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
DeviceDS2406::DeviceDS2406( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
DeviceDS2406::~DeviceDS2406( void )
{
}
// }}}RME

// {{{RME operation 'readMemory(unsigned int,unsigned int)'
unsigned char * DeviceDS2406::readMemory( unsigned int address, unsigned int length )
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
	unsigned int blockLength = length; // define and initialize local variable to be decremented in while loop
	unsigned int pageNumber;
	bool finished = false;

	// First validate the length

	if ( (length > 0) && ((address + length) <= DS2406_MEMORY_SIZE) )
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

			pageOffset = (offset & (DS2406_PAGE_SIZE - 1));
			pageNumber = (offset & (~(DS2406_PAGE_SIZE - 1)));

			pageNumber >>= DS2406_PAGE_NUMBER_SHIFT;
			
			availablePageSize = DS2406_PAGE_SIZE - pageOffset;

			lengthToRead = (blockLength >= availablePageSize)?availablePageSize:blockLength;

			// First send the read status command to obtain the redirection byte.
			txBuffer = new char[CMD_READ_STATUS_SIZE];
			
			// First byte to send is the read command, followed by the LSB and MSB
			// of the target address, respectively

			txBuffer[0] = (char)CMD_READ_STATUS;

			statusRegisterAddress = DS2406_STATUS_BASE_ADDRESS +
									DS2406_STATUS_REDIRECT_OFFSET +
									(uint16_t)pageNumber;

			txBuffer[1] = (char)(statusRegisterAddress & 0xFF);
			txBuffer[2] = (char)(statusRegisterAddress >> 8);

			OneWireMemoryDevice::m_txBuffer = new SCharArray(CMD_READ_EPROM_SIZE,txBuffer,true);

			bool status = OneWireMemoryDevice::m_oneWireConnection->send(OneWireMemoryDevice::m_txBuffer);

	        if( status == false ) // send failed, that's fatal.
	        {
	          delete OneWireMemoryDevice::m_txBuffer;
	          delete [] retVal;
	          retVal = 0;
	          OneWireMemoryDevice::m_oneWireConnection->releaseBus();
	          break; // fatal error so break out and quit
	        }

			OneWireMemoryDevice::m_rxBuffer = (SCharArray*)OneWireMemoryDevice::m_oneWireConnection->receive();
	        
	        if( OneWireMemoryDevice::m_rxBuffer != 0 )
	        {
			  redirectionByte = (unsigned char)((*OneWireMemoryDevice::m_rxBuffer)[0]);
			  delete OneWireMemoryDevice::m_rxBuffer;
	        }
	        else
	        {
	          delete [] retVal;
	          retVal = 0;
	          OneWireMemoryDevice::m_oneWireConnection->releaseBus();
	          break; // fatal error so break out and quit        
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
				redirectionByte <<= DS2406_PAGE_NUMBER_SHIFT;
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
	        if( status == false ) 
	        {
	          delete OneWireMemoryDevice::m_txBuffer;
	          delete [] retVal;
	          retVal = 0;
	          OneWireMemoryDevice::m_oneWireConnection->releaseBus();
	          break; // fatal error so break out and quit        
	        }

			// Start reading
			for (i=0;i<lengthToRead;i++)
			{
				OneWireMemoryDevice::m_rxBuffer = (SCharArray*)OneWireMemoryDevice::m_oneWireConnection->receive();

	            if( OneWireMemoryDevice::m_rxBuffer != 0 )
	            {
				   retVal[(offset-address)+i] = (unsigned char)((*OneWireMemoryDevice::m_rxBuffer)[0]);
				   delete OneWireMemoryDevice::m_rxBuffer;
	            }
	            else
	            {
			      OneWireMemoryDevice::m_oneWireConnection->releaseBus();
	              break; // if receive returns null then its fatal so break out of while loop
	            }
			}

			// The memory read has completed, so the bus may be released.
			OneWireMemoryDevice::m_oneWireConnection->releaseBus();

			offset += lengthToRead;
			blockLength -= lengthToRead;

			finished = (blockLength != 0)?false:true;
		}
	}
	return retVal;
	// }}}USR
}
// }}}RME

// {{{RME operation 'writeMemory(unsigned int,unsigned char*,unsigned int)'
bool DeviceDS2406::writeMemory( unsigned int address, unsigned char * block, unsigned int length )
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
	TimeSpec memoryWriteDelay(0,480000);
	bool fatalError = false;

	// Note the usage of scope resolution operators (::) throughout this function.
	// This was required due to the multiple inheritance paths to OneWireDevice,
	// so that the references would be unambiguous to the compiler.

	// First validate the address and length

	if ( (length > 0) && ((address + length) <= DS2406_MEMORY_SIZE) )
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

		OneWireMemoryDevice::m_txBuffer = new SCharArray(CMD_WRITE_MEMORY_SIZE,
										txBuffer,true);

		bool status = OneWireMemoryDevice::m_oneWireConnection->send(OneWireMemoryDevice::m_txBuffer);
	    if( status == false ) delete OneWireMemoryDevice::m_txBuffer;

		while(!finished)
		{
			scratchpadOffset = (offset & (DS2406_SCRATCHPAD_SIZE - 1));
			availableScratchpadSize = DS2406_SCRATCHPAD_SIZE - scratchpadOffset;

			lengthToWrite = (blockLength >= availableScratchpadSize)?availableScratchpadSize:blockLength;
			
			txBuffer = new char[lengthToWrite];

			for (i=0;i<lengthToWrite;i++)
			{
				txBuffer[i] = (char)block[(offset-address)+i];
			}

			OneWireMemoryDevice::m_txBuffer = new SCharArray(lengthToWrite,
										txBuffer,true);

			status = OneWireMemoryDevice::m_oneWireConnection->send(OneWireMemoryDevice::m_txBuffer);
	        if( status == false ) delete OneWireMemoryDevice::m_txBuffer;

			// Receive the CRC16 of the sent data. This is not used in this implementation.

			OneWireMemoryDevice::m_rxBuffer = (SCharArray*)OneWireMemoryDevice::m_oneWireConnection->receive();
	        if( OneWireMemoryDevice::m_rxBuffer != 0 )
	        {
			  delete OneWireMemoryDevice::m_rxBuffer;
	        }
	        else
	        {
	          fatalError = true;
	          break;
	        }

			OneWireMemoryDevice::m_rxBuffer = (SCharArray*)OneWireMemoryDevice::m_oneWireConnection->receive();
	        if( OneWireMemoryDevice::m_rxBuffer != 0 )
	        {
			  delete OneWireMemoryDevice::m_rxBuffer;
	        }
	        else
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
	        else
	        {
	          fatalError = true;
	          break;
	        }

			offset += lengthToWrite;
			blockLength -= lengthToWrite;

			finished = (blockLength != 0)?false:true;
		}

		OneWireMemoryDevice::m_oneWireConnection->releaseBus();

		delete[] block;
		if(fatalError == false) retVal = true;
	}

	return retVal;
	// }}}USR
}
// }}}RME

// {{{RME operation 'DeviceDS2406(OneWireConnection*,IOVirtual*)'
DeviceDS2406::DeviceDS2406( OneWireConnection * connection, IOVirtual * progPulse )
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

// {{{RME operation 'send(unsigned int)'
void DeviceDS2406::send( unsigned int data )
{
	// {{{USR
	bool validInput = false;
	char* txBuffer = 0;
	unsigned char patternToSend;

	// First ensure that the passed-in value is valid
	if (data == OPEN_A_OPEN_B)
	{
		patternToSend = PATTERN_OPEN_A_OPEN_B;
		validInput = true;
	}
	else if (data == OPEN_A_CLOSE_B)
	{
		patternToSend = PATTERN_OPEN_A_CLOSE_B;
		validInput = true;
	}
	else if (data == CLOSE_A_OPEN_B)
	{
		patternToSend = PATTERN_CLOSE_A_OPEN_B;
		validInput = true;
	}
	else if (data == CLOSE_A_CLOSE_B)
	{
		patternToSend = PATTERN_CLOSE_A_CLOSE_B;
		validInput = true;
	}

	if (validInput)
	{
		// Both channels will be accessed at the same time.
		// The channel access command byte will be sent first,
		// followed by the control byte necessary to select sending
		// data to the switches, followed by the pattern needed
		// to put the switches in the requested state.

		OneWireMemoryDevice::m_oneWireConnection->acquireBus();

		txBuffer = new char[CMD_CHANNEL_ACCESS_SIZE];

		txBuffer[0] = (char)CMD_CHANNEL_ACCESS;
		txBuffer[1] = (char)CTRL_WRITE_SWITCHES;
		txBuffer[2] = (char)0xFF;

		OneWireMemoryDevice::m_txBuffer = new SCharArray(CMD_CHANNEL_ACCESS_SIZE, txBuffer,true);

		bool status = OneWireMemoryDevice::m_oneWireConnection->send(OneWireMemoryDevice::m_txBuffer);
	    if(status == false) delete OneWireMemoryDevice::m_txBuffer;

		// Receive the channel info byte. We will not use this while performing the send.
		// It will just keep the protocol going.

		OneWireMemoryDevice::m_rxBuffer = (SCharArray*)OneWireMemoryDevice::m_oneWireConnection->receive();
	    if( OneWireMemoryDevice::m_rxBuffer != 0 )
	    {
		   delete OneWireMemoryDevice::m_rxBuffer;

		   // Now send the requested pattern
		   txBuffer = new char[1];

		   txBuffer[0] = (char)patternToSend;

		   OneWireMemoryDevice::m_txBuffer = new SCharArray(CMD_CHANNEL_ACCESS_SIZE, txBuffer,true);

		   status = OneWireMemoryDevice::m_oneWireConnection->send(OneWireMemoryDevice::m_txBuffer);
	       if(status == false) delete OneWireMemoryDevice::m_txBuffer;

		   OneWireMemoryDevice::m_oneWireConnection->releaseBus();

	       // else if receive failed then its fatal - nothing more we can do here.
	    }


	}
	// }}}USR
}
// }}}RME

// {{{RME operation 'receive()'
unsigned int DeviceDS2406::receive( void )
{
	// {{{USR
	char* txBuffer = 0;
	unsigned char receivedPattern;
	unsigned int retVal = 0;
	bool fatalError = false;

	// Both channels will be accessed at the same time.
	// The channel access command byte will be sent first,
	// followed by the control byte necessary to select reading
	// data from the switches. Then the state of the switches
	// will be read.

	OneWireMemoryDevice::m_oneWireConnection->acquireBus();

	txBuffer = new char[CMD_CHANNEL_ACCESS_SIZE];

	txBuffer[0] = (char)CMD_CHANNEL_ACCESS;
	txBuffer[1] = (char)CTRL_READ_SWITCHES;
	txBuffer[2] = (char)0xFF;

	OneWireMemoryDevice::m_txBuffer = new SCharArray(CMD_CHANNEL_ACCESS_SIZE,
									txBuffer,true);

	bool status = OneWireMemoryDevice::m_oneWireConnection->send(OneWireMemoryDevice::m_txBuffer);
	if( status == false ) delete OneWireMemoryDevice::m_txBuffer;

	// Receive the channel info byte. We will not use this while performing the send.
	// It will just keep the protocol going.

	OneWireMemoryDevice::m_rxBuffer = (SCharArray*)OneWireMemoryDevice::m_oneWireConnection->receive();
	if( OneWireMemoryDevice::m_rxBuffer != 0 )
	{
	  delete OneWireMemoryDevice::m_rxBuffer;
	}
	else
	{
	   fatalError = true;
	}

	if( (fatalError == false) )
	{
		// Now receive the pattern
		OneWireMemoryDevice::m_rxBuffer = (SCharArray*)OneWireMemoryDevice::m_oneWireConnection->receive();
		if( OneWireMemoryDevice::m_rxBuffer != 0 )
		{
	  		receivedPattern = (unsigned char)((*OneWireMemoryDevice::m_rxBuffer)[0]);
	  		delete OneWireMemoryDevice::m_rxBuffer;
		}
		else
		{
	   		fatalError = true;
		}
	}

	OneWireMemoryDevice::m_oneWireConnection->releaseBus();

	if( (fatalError == false) )
	{

		// Convert the received pattern to a value that the client will recognize
		if (receivedPattern == PATTERN_OPEN_A_OPEN_B)
		{
			retVal = OPEN_A_OPEN_B;
		}	
		else if (receivedPattern == PATTERN_OPEN_A_CLOSE_B)
		{
			retVal = OPEN_A_CLOSE_B;
		}
		else if (receivedPattern == PATTERN_CLOSE_A_OPEN_B)
		{
			retVal = CLOSE_A_OPEN_B;
		}
		else if (receivedPattern == PATTERN_CLOSE_A_CLOSE_B)
		{
			retVal = CLOSE_A_CLOSE_B;
		}

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
