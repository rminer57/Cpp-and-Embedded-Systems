// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OneWire_Interface::DeviceDrivers::Device-specific drivers::DeviceDS2438'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "DeviceDS2438.h"
#endif

#include <serial_comp.h>
#include <DeviceDS2438.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'CMD_WRITE_SCRATCHPAD'
const unsigned char DeviceDS2438::CMD_WRITE_SCRATCHPAD( 0x4E );
// }}}RME

// {{{RME classAttribute 'CMD_WRITE_SCRATCHPAD_SIZE'
const unsigned int DeviceDS2438::CMD_WRITE_SCRATCHPAD_SIZE( 2 );
// }}}RME

// {{{RME classAttribute 'CMD_READ_SCRATCHPAD'
const unsigned char DeviceDS2438::CMD_READ_SCRATCHPAD( 0xBE );
// }}}RME

// {{{RME classAttribute 'CMD_READ_SCRATCHPAD_SIZE'
const unsigned int DeviceDS2438::CMD_READ_SCRATCHPAD_SIZE( 2 );
// }}}RME

// {{{RME classAttribute 'CMD_COPY_SCRATCHPAD_TO_EEPROM'
const unsigned char DeviceDS2438::CMD_COPY_SCRATCHPAD_TO_EEPROM( 0x48 );
// }}}RME

// {{{RME classAttribute 'CMD_COPY_SCRATCHPAD_TO_EEPROM_SIZE'
const unsigned int DeviceDS2438::CMD_COPY_SCRATCHPAD_TO_EEPROM_SIZE( 2 );
// }}}RME

// {{{RME classAttribute 'CMD_RECALL_SCRATCHPAD_FROM_EEPROM'
const unsigned char DeviceDS2438::CMD_RECALL_SCRATCHPAD_FROM_EEPROM( 0xB8 );
// }}}RME

// {{{RME classAttribute 'CMD_RECALL_SCRATCHPAD_FROM_EEPROM_SIZE'
const unsigned int DeviceDS2438::CMD_RECALL_SCRATCHPAD_FROM_EEPROM_SIZE( 2 );
// }}}RME

// {{{RME classAttribute 'DS2438_PAGE_SIZE_WITH_CRC'
const unsigned int DeviceDS2438::DS2438_PAGE_SIZE_WITH_CRC( 9 );
// }}}RME

// {{{RME classAttribute 'DS2438_MEMORY_SIZE'
const unsigned int DeviceDS2438::DS2438_MEMORY_SIZE( 64 );
// }}}RME

// {{{RME classAttribute 'DS2438_PAGE_SIZE'
const unsigned int DeviceDS2438::DS2438_PAGE_SIZE( 8 );
// }}}RME

// {{{RME classAttribute 'DS2438_PAGE_NUMBER_SHIFT'
const unsigned int DeviceDS2438::DS2438_PAGE_NUMBER_SHIFT( 3 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
DeviceDS2438::DeviceDS2438( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
DeviceDS2438::~DeviceDS2438( void )
{
}
// }}}RME

// {{{RME operation 'readMemory(unsigned int,unsigned int)'
unsigned char * DeviceDS2438::readMemory( unsigned int address, unsigned int length )
{
	// {{{USR
	unsigned char* retVal = 0;
	unsigned char readPage[DS2438_PAGE_SIZE_WITH_CRC];
	uint16_t offset;
	char* txBuffer = 0;
	unsigned int i;
	unsigned int pageOffset = 0;
	unsigned int availablePageSize;
	unsigned int lengthToRead;
	unsigned int blockLength = length;
	unsigned int pageNumber;
	bool finished = false;

	// First validate the length

	if ( (length > 0) && ((address + length) <= DS2438_MEMORY_SIZE) )
	{
		offset = (uint16_t)address;

		// Data can only be read from the scratchpad, and only entire memory pages
		// can be copied to the scratchpad. Therefore, if the requested data spans
		// multiple pages, multiple iterations of copying memory pages to scratchpad
		// and reading from the scratchpad must be performed.

		// Given valid input, a valid buffer will be returned.
		retVal = new unsigned char[length];

		while (!finished)
		{
			OneWireMemoryDevice::m_oneWireConnection->acquireBus();

			pageOffset = (offset & (DS2438_PAGE_SIZE - 1));

			pageNumber = offset >> DS2438_PAGE_NUMBER_SHIFT;
			
			availablePageSize = DS2438_PAGE_SIZE - pageOffset;

			lengthToRead = (blockLength >= availablePageSize)?availablePageSize:blockLength;

			txBuffer = new char[CMD_RECALL_SCRATCHPAD_FROM_EEPROM_SIZE];

			// First byte to send is the recall scratchpad command, followed by the page number

			txBuffer[0] = (char)CMD_RECALL_SCRATCHPAD_FROM_EEPROM;
			txBuffer[1] = (char)(pageNumber);

			OneWireMemoryDevice::m_txBuffer = new SCharArray(CMD_RECALL_SCRATCHPAD_FROM_EEPROM_SIZE,txBuffer,true);

			bool status = OneWireMemoryDevice::m_oneWireConnection->send(OneWireMemoryDevice::m_txBuffer);

	        if( status == false )
	        { 
	          // send failed - fatal error
			  OneWireMemoryDevice::m_oneWireConnection->releaseBus();
	          delete OneWireMemoryDevice::m_txBuffer;
	          delete [] retVal;
	          retVal = 0;
	          break;
	        }

			OneWireMemoryDevice::m_oneWireConnection->releaseBus();
			OneWireMemoryDevice::m_oneWireConnection->acquireBus();

			// Now send the command to read the scratchpad.

			txBuffer = new char[CMD_READ_SCRATCHPAD_SIZE];

			// First byte to send is the recall scratchpad command, followed by the page number

			txBuffer[0] = (char)CMD_READ_SCRATCHPAD;
			txBuffer[1] = (char)(pageNumber);

			OneWireMemoryDevice::m_txBuffer = new SCharArray(CMD_READ_SCRATCHPAD_SIZE,txBuffer,true);

			status = OneWireMemoryDevice::m_oneWireConnection->send(OneWireMemoryDevice::m_txBuffer);

	        if( status == false )
	        { 
	          // send failed - fatal error
			  OneWireMemoryDevice::m_oneWireConnection->releaseBus();
	          delete OneWireMemoryDevice::m_txBuffer;
	          delete [] retVal;
	          retVal = 0;
	          break;
	        }

			// Start reading
			for (i=0;i<DS2438_PAGE_SIZE_WITH_CRC;i++)
			{
				OneWireMemoryDevice::m_rxBuffer = (SCharArray*)OneWireMemoryDevice::m_oneWireConnection->receive();

	            if( OneWireMemoryDevice::m_rxBuffer != 0 )
	            {
				  readPage[i] = (unsigned char)((*OneWireMemoryDevice::m_rxBuffer)[0]);
				  delete OneWireMemoryDevice::m_rxBuffer;
	            }
	            else
	            {
			      OneWireMemoryDevice::m_oneWireConnection->releaseBus();
	              delete [] retVal;
	              retVal = 0;
	              break; // if receive returned null then error is fatal so break out of while loop
	            }
			}

			// Check the CRC. If it is OK, then copy the received page into the buffer to be
			// returned. If not, return zero.

			if (dallasOneWireCalculateCRC8(readPage,DS2438_PAGE_SIZE_WITH_CRC) != 0)
			{
				delete [] retVal;
				retVal = 0;
				break;
			}

			// Start reading
			for (i=0;i<lengthToRead;i++)
			{
				retVal[(offset-address)+i] = (unsigned char)(readPage[pageOffset+i]);
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
bool DeviceDS2438::writeMemory( unsigned int address, unsigned char * block, unsigned int length )
{
	// {{{USR
	bool retVal = false;
	bool finished = false;
	char* txBuffer = 0;
	unsigned int i;
	int blockLength = length;
	unsigned int lengthToWrite;
	unsigned int scratchpadOffset = 0;
	unsigned int availableScratchpadSize;
	unsigned int availablePageSize;
	unsigned int pageOffset = 0;
	unsigned int pageNumber;
	unsigned char readByte;
	unsigned char* readPage;
	uint16_t offset;
	TimeSpec memoryWriteDelay(0,5000000);
	bool fatalError = false;

	// First validate the address and length

	if ( (length > 0) && ((address + length) <= DS2438_MEMORY_SIZE) && (block != 0) )
	{
		offset = (uint16_t)address;

		// Data must be written to the scratchpad first and then copied to memory.
		// Since only complete pages can be copied between the scratchpad and memory,
		// We must read a page from memory, modify it, and then write it back to memory.

		while(!finished)
		{
			// Determine the page number and read the desired page from memory
			pageOffset = (offset & (DS2438_PAGE_SIZE - 1));

			pageNumber = offset >> DS2438_PAGE_NUMBER_SHIFT;

			availablePageSize = DS2438_PAGE_SIZE - pageOffset;

			readPage = readMemory((pageNumber << DS2438_PAGE_NUMBER_SHIFT),DS2438_PAGE_SIZE);

	        if( readPage == 0 ) // fatal error
	        {
			  OneWireMemoryDevice::m_oneWireConnection->releaseBus();
	          fatalError = true;
	          break;
	        }

			lengthToWrite = (blockLength >= availablePageSize)?availablePageSize:blockLength;

			for (i=0;i<lengthToWrite;i++)
			{
				readPage[pageOffset+i] = block[(offset-address)+i];
			}

			// Now that the page has the new data, write it back to the scratchpad before
			// copying to memory.

			txBuffer = new char[ CMD_WRITE_SCRATCHPAD_SIZE + DS2438_PAGE_SIZE ];

			txBuffer[0] = (char)CMD_WRITE_SCRATCHPAD;
			txBuffer[1] = (char)(pageNumber);

			for (i=0;i<DS2438_PAGE_SIZE;i++)
			{
				txBuffer[i+CMD_WRITE_SCRATCHPAD_SIZE] = (char)readPage[i];
			}

			delete[] readPage;

			m_txBuffer = new SCharArray(CMD_WRITE_SCRATCHPAD_SIZE + DS2438_PAGE_SIZE, txBuffer,true);

			m_oneWireConnection->acquireBus();  
			bool status = m_oneWireConnection->send(m_txBuffer);

	        if( status == false )
	        { 
	          // send failed - fatal error
			  OneWireMemoryDevice::m_oneWireConnection->releaseBus();
	          delete OneWireMemoryDevice::m_txBuffer;
	          fatalError = true;
	          break;
	        }

			m_oneWireConnection->releaseBus();

			m_oneWireConnection->acquireBus();

			txBuffer = new char[CMD_COPY_SCRATCHPAD_TO_EEPROM_SIZE];
			txBuffer[0] = (char)CMD_COPY_SCRATCHPAD_TO_EEPROM;
			txBuffer[1] = pageNumber;

			m_txBuffer = new SCharArray(CMD_COPY_SCRATCHPAD_TO_EEPROM_SIZE,txBuffer,true);

			status = m_oneWireConnection->send(m_txBuffer);

	        if( status == false )
	        { 
	          // send failed - fatal error
			  OneWireMemoryDevice::m_oneWireConnection->releaseBus();
	          delete OneWireMemoryDevice::m_txBuffer;
	          fatalError = true;
	          break;
	        }

			// It takes 5 ms to copy the scratchpad to EEPROM, so we must wait this long.
			Thread::nanosleep(memoryWriteDelay);

			m_oneWireConnection->releaseBus();

			offset += lengthToWrite;
			blockLength -= lengthToWrite;

			finished = (blockLength != 0)?false:true;
		}

		if( block != 0 ) delete[] block;

		if(fatalError == false) retVal = true;
	}

	return retVal;
	// }}}USR
}
// }}}RME

// {{{RME operation 'dallasOneWireCalculateCRC8(unsigned char*,unsigned int)'
unsigned char DeviceDS2438::dallasOneWireCalculateCRC8( unsigned char * byteArray, unsigned int size )
{
	// {{{USR
	unsigned int i;
	unsigned int j;
	unsigned char scratch;
	unsigned char crc = 0;

	for( j = 0; j < size; j++)
	{
		scratch = byteArray[j];

		for( i = 0; i < 8; i++)
		{
			if(((crc ^=(scratch & 1)) & 1) == 1)
			{
				crc ^= 0x18;
			}

			// Rotate right by 1 bit
			crc = ( (crc >> 1) | ( (crc & 1) << 7 ));
			scratch = ( (scratch >> 1) | ( (scratch & 1) << 7 ));
		}
	}

	return(crc);
	// }}}USR
}
// }}}RME

// {{{RME operation 'DeviceDS2438(OneWireConnection*)'
DeviceDS2438::DeviceDS2438( OneWireConnection * connection )
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
