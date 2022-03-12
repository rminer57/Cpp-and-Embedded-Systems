// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::LAN::Ethernet::Smsc::LAN91C96I::Lan91c96i'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Lan91c96i.h"
#endif

#include <serial_comp.h>
#include <Lan91c96i.h>
#include <Configurable.h>
#include <Lan91c96iBitFields.h>
#include <Lan91c96iConfig.h>
#include <Lan91c96iIntSource.h>
#include <SCharArray.h>
#include <peripheral_access.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'MAX_FRAME_LENGTH'
const unsigned int Lan91c96i::MAX_FRAME_LENGTH( 1514 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
Lan91c96i::Lan91c96i( void )
{
}
// }}}RME

// {{{RME operation 'Lan91c96i(Lan91c96iConfig*)'
Lan91c96i::Lan91c96i( Lan91c96iConfig * config )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	:Lan91c96iCommon(config)
	// }}}USR
	// }}}RME
{
	// {{{USR



	// }}}USR
}
// }}}RME

// {{{RME operation 'activate()'
bool Lan91c96i::activate( void )
{
	// {{{USR
	// Not implemented

	return true;
	// }}}USR
}
// }}}RME

// {{{RME operation 'send(Array*)'
bool Lan91c96i::send( Array * payLoad )
{
	// {{{USR
	peripheral_address_short baseAddress = (peripheral_address_short)m_lan91c96iBaseAddress;	//Use local to allow compiler optimization
	bool retValue = false;
	unsigned int numPages = 0;
	unsigned int freeMemoryAvailable = 0;

	m_mutex->lock();

	if ((!(m_frameAllocationPending)) && (payLoad->isType(SCharArray::SIGNED_CHAR_ARRAY)) && ((m_payLoadLength = payLoad->getLength()) <= MAX_FRAME_LENGTH))
	{
		// Select Bank 2
		setBitField(baseAddress,BANK,BANK2);

		// Disable All INT 
		setBitField(baseAddress,INT_MASK,0);

		m_currentSendFrameBuffer = (SCharArray*)payLoad;

		// Select Bank 0
		setBitField(baseAddress,BANK,BANK0);

		// Whether the frame was allocated immediately or at a later time
		// return to the client true.
		retValue = true;

		freeMemoryAvailable = getBitField(baseAddress,FREE_MEM_AVAIL) * 256;

		// Select Bank 2
		setBitField(baseAddress,BANK,BANK2);

		// Calculate the number of pages
		numPages = (m_payLoadLength / 256);

		if (m_payLoadLength <= freeMemoryAvailable)
		{

			// Issue an Allocate Memory for Transmit Command
			sendMMUCommand(ALLOCATE_MEMORY,numPages);

			while(testBitField(baseAddress,ALLOC_INT) != 0)
				break;			
		
			// Allocation succeeded send the frame and leave
			// Send the buffer to lower layer
			sendFrame(m_currentSendFrameBuffer);

			// allow the client to perform the next send operation
			m_frameAllocationPending = 0;
		}
		else
		{
			
			// Issue an Allocate Memory for Transmit Command
			sendMMUCommand(ALLOCATE_MEMORY,numPages);

			// Buffer is going to be sent later when it could be allocated
			// Enable interrupt to allow to finally send the frame when allocation is 
			// accomplished

			m_intMask |= ALLOC_INT_MASK;
		
			// Do not allow that the client sent any more frames.
			m_frameAllocationPending = 1;

		}

		// Enable All allowed INT
		setBitField(baseAddress,INT_MASK,m_intMask);
	}

	m_mutex->unlock();

	return retValue;
	// }}}USR
}
// }}}RME

// {{{RME operation 'receive()'
Array * Lan91c96i::receive( void )
{
	// {{{USR
	peripheral_address_short baseAddress = (peripheral_address_short)m_lan91c96iBaseAddress;	//Use local to allow compiler optimization

	m_mutex->lock();

	// Select Bank 2
	setBitField(baseAddress,BANK,BANK2);

	// Disable All INT 
	setBitField(baseAddress,INT_MASK,0);

	SCharArray *retPayLoad = 0;

	// Set Data Available to false
	m_status->setDataAvailable(false);

	// Get the frame
	retPayLoad = receiveFrame();

	// Restore the INT mask. This will enable interrupts
	setBitField(baseAddress,INT_MASK,m_intMask);

	m_mutex->unlock();

	// Return the frame
	return retPayLoad;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getOption(ClassType)'
Configurable::Option * Lan91c96i::getOption( ClassType optionType ) const
{
	// {{{USR
	// Not implemented
	return 0;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getStatus()'
Connection::Status * Lan91c96i::getStatus( void )
{
	// {{{USR
	return m_status;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setOption(Configurable::Option *)'
bool Lan91c96i::setOption( Configurable::Option * option )
{
	// {{{USR
	// Not implemented
	return 0;
	// }}}USR
}
// }}}RME

// {{{RME operation 'deactivate()'
bool Lan91c96i::deactivate( void )
{
	// {{{USR
	return true;
	// }}}USR
}
// }}}RME

// {{{RME operation '~Lan91c96i()'
Lan91c96i::~Lan91c96i( void )
{
	// {{{USR
	delete m_status;
	delete m_option;

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
