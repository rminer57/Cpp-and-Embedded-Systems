// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::LAN::Ethernet::Smsc::LAN91C96I::Lan91c96iCommon'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Lan91c96iCommon.h"
#endif

#include <serial_comp.h>
#include <Lan91c96iCommon.h>
#include <IOVirtual.h>
#include <Lan91c96iBitFields.h>
#include <Lan91c96iConfig.h>
#include <Lan91c96iIntSource.h>
#include <SCharArray.h>
#include <bitfield.h>
#include <peripheral_access.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Status' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classifier 'Status'

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
Lan91c96iCommon::Status::~Status( void )
{
}
// }}}RME

// {{{RME operation 'Status()'
Lan91c96iCommon::Status::Status( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_isDataAvailable(false),m_actualLinkAvailability(true),m_dataAvailableEvent(Connection::Status::Event::DATA_AVAILABLE),m_linkUnavailable(Connection::Status::Event::UNAVAILABLE),m_linkAvailable(Connection::Status::Event::AVAILABLE)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'isDataAvailable()'
bool Lan91c96iCommon::Status::isDataAvailable( void ) const
{
	// {{{USR
	return m_isDataAvailable;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setDataAvailable(bool)'
void Lan91c96iCommon::Status::setDataAvailable( bool dataAvailable )
{
	// {{{USR
	//if data is now available, and previously was unavailable, generate event
	if (dataAvailable && !m_isDataAvailable)
	{
		m_isDataAvailable = dataAvailable;				//set to correct value prior to message dispatch
	   	informListeners(&m_dataAvailableEvent);
	}
	else
	{
		m_isDataAvailable = dataAvailable;
	}
	// }}}USR
}
// }}}RME

// {{{RME operation 'setAvailable(bool)'
void Lan91c96iCommon::Status::setAvailable( bool availability )
{
	// {{{USR
	// Detect whether there is a change in the state of the LINK or no change in the LINK
	// by comparing the actual state with the previous state.

	if((availability ^ m_actualLinkAvailability))
	{
		informListeners(((availability)?&m_linkAvailable:&m_linkUnavailable));
		m_actualLinkAvailability = availability; 
	}

	// }}}USR
}
// }}}RME

// {{{RME operation 'isAvailable()'
bool Lan91c96iCommon::Status::isAvailable( void ) const
{
	// {{{USR
	return m_actualLinkAvailability;
	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
Lan91c96iCommon::Lan91c96iCommon( void )
{
}
// }}}RME

// {{{RME operation 'Lan91c96iCommon(Lan91c96iConfig*)'
Lan91c96iCommon::Lan91c96iCommon( Lan91c96iConfig * config )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_lan91c96iConfig(config),m_currentSendFrameBuffer(0),m_frameAllocationPending(false),m_rxOvrnCounter(0)
	// }}}USR
	// }}}RME
{
	// {{{USR
	// Use local to allow compiler optimization
	peripheral_address_short baseAddress = (peripheral_address_short)config->m_lan91c96iBaseAddress;

	m_lan91c96iBaseAddress = m_lan91c96iConfig->m_lan91c96iBaseAddress;

	registerListener(this,EthernetTxEmptyEvent::ETHERNET_TX_EMPTY_EVENT);

	// Register the LAN91C96I to handle the interrupts
	m_lan91c96iConfig->m_ioVirtual->registerListener(this,IOVirtual::Event::EVENT_IO_LEVEL_CHANGE);

	//Create the Lan91c96i status object
	m_status = new Lan91c96iCommon::Status();

	// Select Bank 2
	setBitField(baseAddress,BANK,BANK2);

	// Reset MMU to initial state
	sendMMUCommand(RESET_MMU,PAGES_NOT_REQUIRED);

	// Disable all interrupts
	setBitField(baseAddress,INT_MASK,0);

	// Select Bank 0
	setBitField(baseAddress,BANK,BANK0);

	// Reset the Lan91c96i by setting the SOFT_RST bit in RCR to 1, wait and then clear it
	setBitField(baseAddress,SOFT_RST,1);

	// Do a delay to settle
	delay();

	setBitField(baseAddress,SOFT_RST,0);

	// ENCDEC Loopback for Testing purposes
	// Set FDUPLX to 1
	// Set LOOP to 1
	// Normal operation both set to 0 (Cleared)

	setBitField(baseAddress,FDUPLX,0);
	setBitField(baseAddress,LOOP,0);

	// Determine the if the Twisted Pair Cable is connected and the Ethernet Link is OK
	// Based on the state of the link notify the status of the Link
	// This detection at initialization allows the client to find out the status of the Link at power up when the 
	// Ethernet object still has not been register as a listener for changes in the status of the link  
	//

	(testBitField(baseAddress,LINK_OK))?m_status->setAvailable(true) : m_status->setAvailable(false);

	// Reserved 1 frame size in bytes of memory for Tx only 
	setBitField(baseAddress,MEM_RSVD_FOR_TX,TX_MEM_ONE_FRAME);
	 
	// Select BANK1
	setBitField(baseAddress,BANK,BANK1);

	// Although interrupts are not yet enabled, force clear LE enable interrupt 
	setBitField(baseAddress,LE_ENABLE,0);

	// MAC Address given by the configuration agent will be programmed into the IC

	*(combineAddr(baseAddress,IA0_REG)) = m_lan91c96iConfig->m_lan91C96IMacAddress[0];	// Write IA1 IA0
	*(combineAddr(baseAddress,IA2_REG)) = m_lan91c96iConfig->m_lan91C96IMacAddress[1];	// Write IA3 IA2
	*(combineAddr(baseAddress,IA4_REG)) = m_lan91c96iConfig->m_lan91C96IMacAddress[2];	// Write IA5 IA4

	// LAN91C96I Configured to
	// - 10BASET
	// - Squelch level = 400 mV
	// - Auto Release the Tx buffer after a successful TX

	//// Set the Auto-release bit to automatically release successfully transmitted packets 
	setBitField(baseAddress,AUTO_RELEASE,1);

	// Control Register

	// Enable the Lan91c96i IC to perform Link test Functions
	// Enable the Link Error condition 
	// Disable the Counter Rollover error condition
	// Enable the Transmit error condition 

	setBitField(baseAddress,DIS_LINK,0);
	setBitField(baseAddress,LE_ENABLE,1);
	setBitField(baseAddress,CR_ENABLE,0);
	setBitField(baseAddress,TE_ENABLE,1);

	// Enable the LAN91C96I to operate
	// Enable Rx
	// Enable INT

	// Select Bank 0
	setBitField(baseAddress,BANK,BANK0);

	//  Set the transmit and receive configuration registers to default values */
	// RCR:
	// - Remove CRC from incoming packet
	// - Accept all multicast
	// - Enable Rx
	setBitField(baseAddress,STRIP_CRC,1);
	setBitField(baseAddress,ALMUL,1);
	setBitField(baseAddress,RX_EN,1);

	// TCR: 
	// - Insert CRC, 
	// - Add Padding 
	setBitField(baseAddress,PAD_EN,1);//  Set the transmit and receive configuration registers to default values */
	setBitField(baseAddress,TXENA,1);

	// Enable INT
	// Select Bank 2
	setBitField(baseAddress,BANK,BANK2);

	// Enable EPH Int, Tx, Rx Overrun Int and Rx interrupts
	m_intMask = ENABLED_INTERRUPTS;
	setBitField(baseAddress,INT_MASK,m_intMask);

	m_mutex = Mutex::createMutex();


	// }}}USR
}
// }}}RME

// {{{RME operation 'handler()'
void Lan91c96iCommon::handler( void )
{
	// {{{USR
	//Use local to allow compiler optimization
	peripheral_address_short baseAddress = (peripheral_address_short)m_lan91c96iBaseAddress;

	unsigned int tempPreserveBank, intStatus = 0;
	unsigned int packetNumber = 0;
	unsigned int txEphStatus = 0;

	// Preserve Bank
	m_preservedBank = getBitField(baseAddress,BANK);

	// Select Bank 2
	setBitField(baseAddress,BANK,BANK2);

	// Disable INT
	setBitField(baseAddress,INT_MASK,0);

	// Preserve the Pointer register
	m_preserveAddressPointer = *(combineAddr(baseAddress,PTR_REG));

	// Service all INT
	intStatus = getBitField(baseAddress,IST) & m_intMask;

	if (intStatus & TX_EMPTY_INT_MASK)
	{
	    tempPreserveBank = getBitField(baseAddress,BANK);	

	    // Select Bank 2 
	    setBitField(baseAddress,BANK,BANK2);

	    setBitField(baseAddress,ACK_TX_EMPTY_INT,1);

	    unsigned int tempIntStatus = getBitField(baseAddress,IST) & (TX_EMPTY_INT_MASK | TX_INT_MASK);
	    
	    if (tempIntStatus & TX_INT_MASK)
	    {
	    	// Read packet from PNR
			packetNumber = getBitField(baseAddress,TX_PACKET_NUMBER);
		
			// Remove the Tx frame from the Tx FIFO 
			sendMMUCommand(RELEASE_SPECIFIC_PACKET,PAGES_NOT_REQUIRED);
		
			setBitField(baseAddress,ACK_TX_INT,1);

			setBitField(baseAddress, BANK, BANK0);
		
			setBitField(baseAddress,TXENA,1);
		
			setBitField(baseAddress, BANK, BANK2);
		
			setBitField(baseAddress,TX_PACKET_NUMBER,packetNumber);
	    }

		setBitField(baseAddress,TX_MASK,0);
		setBitField(baseAddress,TX_EMPTY_MASK,0);
		m_intMask &= ~(TX_INT | TX_EMPTY_INT);
	}

	if (intStatus & ALLOC_INT_MASK)
	{
		// Allocation Int
		// Tx requested
	    // Find out where the frame is located.

		setInterrupt(ALLOC_INT,false);
		m_intMask &= ~ALLOC_INT;

		if (m_currentSendFrameBuffer != 0) informListeners(&m_txEmptyEvent);
	}

	if (intStatus & RCV_INT_MASK)
	{
		// Packet received
		// Listener should be informed
		m_status->setDataAvailable(true);
			
		// Testing Only "pseudo-Tx". Although the IC will Rx the packets sent from the
	    // computer it will drop them immediately when the ISR is serviced.
		// Remove the Rx frame from the Rx FIFO in either case (error frame or correct frame)
		//sendMMUCommand(REMOVE_AND_RELEASE_TOP_OF_RX_FIFO,PAGES_NOT_REQUIRED);
	}

	if (intStatus & RX_OVRN_INT_MASK)
	{
		// Rx Overrun Int
		// Bit set because of the following conditions:
		// - due to failed memory allocation -  receive allocation failure
		// - packet length greater than 2k
		// - RCV DISC bit in the ERCV register set
		// 

		// Disable Rx
		tempPreserveBank = getBitField(baseAddress,BANK);	

		// Select Bank 0 
		setBitField(baseAddress,BANK,BANK0);

		// Disable the receiver
		setBitField(baseAddress,RX_EN,0);

		setBitField(baseAddress,TXENA,0);	

		// Select Bank 2 
		setBitField(baseAddress,BANK,BANK2);

		// Clear the Rx Ovrn Interrupt
		setBitField(baseAddress,ACK_RX_OVRN_INT,1);

		sendMMUCommand(RESET_MMU,PAGES_NOT_REQUIRED);

		// Set DataAvailable to False
		m_status->setDataAvailable(false);

		// Select Bank 0 
		setBitField(baseAddress,BANK,BANK0);

		// Re-enable Rx
		setBitField(baseAddress,RX_EN,1);

		setBitField(baseAddress,TXENA,1);

		// Restore BANK
		setBitField(baseAddress,BANK,tempPreserveBank);
	}

	if (intStatus & EPH_INT_MASK)
	{
		// Ethernet Protocol Handler event

		tempPreserveBank = getBitField(baseAddress,BANK);

		// Select Bank 0
		setBitField(baseAddress,BANK,BANK0);
		txEphStatus = *(combineAddr(baseAddress,EPH_STATUS_REG));
		setBitField(baseAddress,BANK,BANK1);

		if (txEphStatus & FATAL_TX_ERROR)
		{
			// Any fatal Tx error will be cleared when the TXENA bit is set 
			setBitField(baseAddress,TXENA,1);
		}

		if (txEphStatus & COUNTER_ROLLOVER)
		{
			// Reading the counterRegister will clear the Counter Rollover Error
			volatile unsigned int counterRegister = *(combineAddr(baseAddress,RCR_REG));
		}

		// Check the status of the link
		if (txEphStatus & LINK_OK_ERROR)
		{
			// Link is available inform listeners and allow transmission or re-enable transmission
			m_status->setAvailable(true);
			setBitField(baseAddress,TXENA,1);
		}
		else
		{
			// Link is un-available inform the listeners and stop transmissions
			m_status->setAvailable(false);
		}

		setBitField(baseAddress,LE_ENABLE,0);
		setBitField(baseAddress,LE_ENABLE,1);
			
		setBitField(baseAddress,BANK,tempPreserveBank);
	}

	// Select Bank 2
	setBitField(baseAddress,BANK,BANK2);

	// Restore Address Pointer
	*(combineAddr(baseAddress,PTR_REG)) = m_preserveAddressPointer;

	// Enable All allowed INT
	setBitField(baseAddress,INT_MASK,m_intMask);

	// Restore bank
	setBitField(baseAddress,BANK,m_preservedBank);

	// }}}USR
}
// }}}RME

// {{{RME operation 'sendFrame(SCharArray*)'
void Lan91c96iCommon::sendFrame( SCharArray * currentBuffer )
{
	// {{{USR
	peripheral_address_short baseAddress = (peripheral_address_short)m_lan91c96iBaseAddress;	//Use local to allow compiler optimization
	unsigned short i = 0;

	unsigned short byteCount = 0;
	unsigned short packetLength = 0;
	unsigned short packetNumber = 0;
	unsigned short controlByteWord = 0x1000;

	// Select Bank 2
	setBitField(baseAddress,BANK,BANK2);

	byteCount = packetLength = currentBuffer->getLength();
	char * packet = *(*currentBuffer);

	// Delete the SCharArray transferred by the client
	delete currentBuffer; 
	currentBuffer = 0;

	// Clear the flag that prevents the client to send
	m_frameAllocationPending = 0;

	// Preserve the Pointer Register
	unsigned short preservedPointerRegister = *(combineAddr(baseAddress,PTR_REG));

	// Make sure that the registers are in Tx mode by clearing the Receive and Read bits
	// Then RCV bit = 0 and READ bit = 0 in the Pointer Register
	*(combineAddr(baseAddress,PTR_REG)) = (preservedPointerRegister & (~(RCV | READ)));

	// Get allocated Packet Number
	packetNumber = getBitField(baseAddress,ALLOCATED_PACKET_NUMBER);

	// The LAN91C96I has a packet number. Place it into the TX PACKET NUMBER field in 
	// the PNR register
	setBitField(baseAddress,TX_PACKET_NUMBER,packetNumber); 

	// Increment Pointer by setting the Autoincrement Pointer bit to 1
	setBitField(baseAddress,AUTO_INCR,1);

	// Do a delay to settle
	delay();
		
	// Set the packet length
	// The length parameter contains the size of the data field that is going to be given to 
	// the LAN91C96I to be transmitted. The data field is formed as follows:
	// 
	//	16 Bits
	// |-------|
	// 15  |   0
	//
	// DA1  DA0 -\
	// DA3  DA2	  |
	// DA5  DA4	  |
	// SA1  SA0	  |
	// SA3  SA2   |- Data Field
	// SA5  SA4   |
	// ETH  TYP   |
	// PAY  LOA -/
	//  .	.
	//	.	.
	//	.	.
	//
	// To this data field, six more bytes must be added as follow
	//
	// Status Word	(2 Bytes)	<- Status Word controlled by the LAN91C96I (set to 0x0000)
	// Byte Count	(2 Bytes)	<- Byte Count = 11 bits that indicate the total length (ALWAYS EVEN)
	// Data Field				<- Above Data Field
	// Control Byte Last Byte	<- If amount of bytes is odd Last Byte is the last byte of data
	//      					 - If amount of bytes is even this byte will not be transmitted
	//							 - Control Byte always added 

	*(combineAddr(baseAddress,DATA_HIGH)) = 0x0000;

	//
	//	Check whether packet length is odd or even
	// If even do nothing
	// If odd get the larger even number of bytes that the frame contains
	//

	if (packetLength & 0x01)
	{
		byteCount = packetLength & 0x7FE;	
	}

	// Set even Packet length + 6 bytes
		
	*(combineAddr(baseAddress,DATA_HIGH)) = byteCount + 6;

	unsigned int bytesRemaining = byteCount;
	i = 0;

	while(bytesRemaining >= 2)
	{
	   	*(combineAddr(baseAddress,DATA_HIGH)) = (unsigned char)(packet[i]) | ((unsigned char)packet[i+1] << 8);

	   	i += 2;
	   	bytesRemaining -= 2;
	}

	//
	// Up to this point the data may be odd
	// If odd 
	// 		Write the control byte: Control Byte Bit 5 ODD If set ODD number of bytes   = CLEAR (EVEN number)
	// 										     Bit 4 CRC If set append CRC to the frame (LAN91C96I calculated) = SET	
			
	if(packetLength & 0x01)
	{
		// Set the ODD bit in the control byte
		controlByteWord |= 0x2000;

		// Number of bytes is odd write last byte
		controlByteWord |= (unsigned char)(packet[i]);
	}

	// Write the control byte
	*(combineAddr(baseAddress,DATA_HIGH)) = controlByteWord;

	delete [] packet;

	// Let the LAN91C96I deal with the Tx
	sendMMUCommand(ENQUEUE_PACKET_NUMBER_INTO_TX_FIFO,PAGES_NOT_REQUIRED);

	m_intMask |= (TX_INT_MASK | TX_EMPTY_INT_MASK);
	setBitField(baseAddress,TX_MASK,1);
	setBitField(baseAddress,TX_EMPTY_MASK,1);

	// Restore the address pointer register
	*(combineAddr(baseAddress,PTR_REG)) = preservedPointerRegister;


	// }}}USR
}
// }}}RME

// {{{RME operation 'receiveFrame()'
SCharArray * Lan91c96iCommon::receiveFrame( void )
{
	// {{{USR
	peripheral_address_short baseAddress = (peripheral_address_short)m_lan91c96iBaseAddress;	//Use local to allow compiler optimization	
	unsigned int i;
	unsigned short rxPacketStatus, rxPacketLength;
	SCharArray *retBufferArray = 0;
	unsigned short temp;
	bool oddByte = false;

#ifdef TX_FRAME_REMOVED

	unsigned short count;
	unsigned int ethernetHeaderDetection = 0;
	unsigned int rxFrameHeader[] = {0,0,0,0,0,0,0};

#endif

	// Select Bank 2
	setBitField(baseAddress,BANK,BANK2);

	if(testBitField(baseAddress,REMPTY) != 0)
	{
		return retBufferArray;
	}

	unsigned short tempAddressPointerRegister = *(combineAddr(baseAddress,PTR_REG));

	// Set the READ, RECEIVE and AUTO_INCREMENT to start the reading process
	*(combineAddr(baseAddress,PTR_REG)) = (tempAddressPointerRegister | RCV | AUTO_INCR | READ );

	// Delay to settle
	delay();

	// The packet in the rex buffer is as follows
	// Status Word	(2 Bytes)	<- Status Word controlled by the LAN91C96I 
	// Byte Count	(2 Bytes)	<- Byte Count = 11 bits that indicate the total length (ALWAYS EVEN)
	//  DA1  DA0 -\
	//  DA3  DA2   |
	//  DA5  DA4   |
	//  SA1  SA0   |
	//  SA3  SA2   |- Data Field
	//  SA5  SA4   |
	//  ETH  TYP   |
	//  PAY  LOA -/
	// Control Byte Last Byte	<- If amount of bytes is odd Last Byte is the last byte of data
	//							 - Control Byte always added 	
		
	// Read the status and the length

	rxPacketStatus = *(combineAddr(baseAddress,DATA_HIGH));
	rxPacketLength = *(combineAddr(baseAddress,DATA_HIGH));

	// Mask the Top Part of the Length

	rxPacketLength &= 0x07FF;
		
	// Subtract 6 bytes from the length. It contains three extra words:

	rxPacketLength -= 6;

	// Check for Rx errors
			
	if (!(rxPacketStatus & RX_ERRORS))
	{
		//
		// Check if the received frame is either broadcast or multicast
		// If it is either of them, disable the mechanism to check the Tx / Rx header
		//

		if(rxPacketStatus & RX_FRAME_ODD_BYTES)
		{
			rxPacketLength++;
			oddByte = true;
		}

		// The frame shall be as follows
	   	// DA1  DA0 -\
	   	// DA3  DA2   |
	   	// DA5  DA4   |
	   	// SA1  SA0   |
	   	// SA3  SA2   |- Data Field
	   	// SA5  SA4   |
	   	// ETH  TYP   |
	   	// PAY  LOA -/
	   	// Last Byte	<- 		If amount of bytes is odd Last Byte is the last byte of data

#ifdef TX_FRAME_REMOVED

		unsigned int bytesRemaining = rxPacketLength;
		count = i = ethernetHeaderDetection = 0;

		// Filter to detect own MAC address in the Source Address Field
		// This avoid a Tx frame to be given to the client as a proper Rx frame.

		while(count < 7)
		{
			rxFrameHeader[count] = (unsigned short)(*(combineAddr(baseAddress,DATA_HIGH)));
			bytesRemaining -= 2;

			if ((count >= 3) && (count <= 5))
			{
				if(rxFrameHeader[count] == m_lan91c96iConfig->m_lan91C96IMacAddress[i])
					ethernetHeaderDetection++;
				i++;
			}		
			count++;
		}
		
		// If the Source Address of the rceived frame correspond with the Source Address assigned to the HOST remove frame and return
		// a null to the client 

		if(ethernetHeaderDetection != 3)
		{
			// Get the data field
			retBufferArray = new SCharArray(rxPacketLength);

			i = 0;
			unsigned int j = 0;

			while(count--)
			{
	   			(*retBufferArray)[i] = rxFrameHeader[j];
	   			(*retBufferArray)[i+1] = rxFrameHeader[j]>>8;
	   			i += 2;		
				j++;
			}

			while (bytesRemaining >= 2)
			{
	   			temp = (unsigned short)(*(combineAddr(baseAddress,DATA_HIGH)));

	   			(*retBufferArray)[i] = temp;
	   			(*retBufferArray)[i+1] = temp>>8;

	   			bytesRemaining -= 2;
	   			i += 2;
			}

			if (oddByte)
				(*retBufferArray)[i] = (signed char)(*(combineAddr(baseAddress,DATA_HIGH)) & 0x00FF);
		}

#else

		// Get the data field
		retBufferArray = new SCharArray(rxPacketLength);

		unsigned int bytesRemaining = rxPacketLength;
		i = 0;

		while (bytesRemaining >= 2)
		{
			temp = (unsigned short)(*(combineAddr(baseAddress,DATA_HIGH)));

			(*retBufferArray)[i] = temp;
			(*retBufferArray)[i+1] = temp>>8;

			bytesRemaining -= 2;
			i += 2;
		}
			
		if (oddByte)
			(*retBufferArray)[i] = (signed char)(*(combineAddr(baseAddress,DATA_HIGH)) & 0x00FF);

#endif

	}

	// Remove the Rx frame from the Rx FIFO in either case (error frame or correct frame)
	sendMMUCommand(REMOVE_AND_RELEASE_TOP_OF_RX_FIFO,PAGES_NOT_REQUIRED);

	// Restore the address pointer that the IC had at the beginning to preserve the initial conditions.
	*(combineAddr(baseAddress,PTR_REG)) = tempAddressPointerRegister;

	return retBufferArray;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setInterrupt(unsigned int,bool)'
void Lan91c96iCommon::setInterrupt( unsigned int intValue, bool functionality )
{
	// {{{USR
	//Use local to allow compiler optimization
	peripheral_address_short baseAddress = (peripheral_address_short)m_lan91c96iBaseAddress;

	/* state registers */
	unsigned int preservedBank;
	unsigned int preservedPointer;

	preservedBank = getBitField(baseAddress,BANK);

	// Select Bank 2
	setBitField(baseAddress,BANK,BANK2);

	preservedPointer = *(combineAddr(baseAddress,PTR_REG));

	switch(intValue)
	{
		case TX_IDLE_INT:
			setBitField(baseAddress,TX_IDLE_MASK,0);
			if (functionality)
				setBitField(baseAddress,TX_IDLE_MASK,1);
			break;

		case ERCV_INT:
			setBitField(baseAddress,ERCV_MASK,0);
			if (functionality)
				setBitField(baseAddress,ERCV_MASK,1);
			break;

		case EPH_INT:
			setBitField(baseAddress,EPH_MASK,0);
			if (functionality)
				setBitField(baseAddress,EPH_MASK,1);
			break;

		case RX_OVRN_INT:
			setBitField(baseAddress,RX_OVRN_MASK,0);
			if (functionality)
				setBitField(baseAddress,RX_OVRN_MASK,1);
			break;

		case ALLOC_INT:
			setBitField(baseAddress,ALLOC_MASK,0);
			if (functionality)
				setBitField(baseAddress,ALLOC_MASK,1);
			break;

		case TX_EMPTY_INT:
			setBitField(baseAddress,TX_EMPTY_MASK,0);
			if (functionality)
				setBitField(baseAddress,TX_EMPTY_MASK,1);
			break;

		case TX_INT:
			setBitField(baseAddress,TX_MASK,0);
			if (functionality)
				setBitField(baseAddress,TX_MASK,1);
			break;

		case RCV_INT:
			setBitField(baseAddress,RCV_MASK,0);
			if (functionality)
				setBitField(baseAddress,RCV_MASK,1);
			break;

		default:
			break;

	}

	// Preserve Bank and Pointer

	setBitField(baseAddress,BANK,(unsigned short)preservedBank);

	*(combineAddr(baseAddress,PTR_REG)) = (unsigned short)preservedPointer;

	// }}}USR
}
// }}}RME

// {{{RME operation 'sendMMUCommand(unsigned int,unsigned int)'
void Lan91c96iCommon::sendMMUCommand( unsigned int mmuCommand, unsigned int numberOfPages )
{
	// {{{USR
	peripheral_address_short baseAddress = (peripheral_address_short)m_lan91c96iBaseAddress;
	unsigned int temp;
	unsigned int pages = numberOfPages;

	temp = (mmuCommand << 4) | pages;

	setBitField(baseAddress,MMUCR,(unsigned short)temp);

	//	Wait for MMU to settle.
	do 
	{
		temp = getBitField(baseAddress,MMUCR);
	} while (temp & MMUCMD_BUSY);
	// }}}USR
}
// }}}RME

// {{{RME operation 'eventOccurred(const EventBase * const)'
void Lan91c96iCommon::eventOccurred( const EventBase * const event )
{
	// {{{USR
	peripheral_address_short baseAddress = (peripheral_address_short)m_lan91c96iBaseAddress;	//Use local to allow compiler optimization

	if (event->isEvent(IOVirtual::Event::EVENT_IO_LEVEL_CHANGE))
	{
		handler();
	}
	else if (event->isEvent(EthernetTxEmptyEvent::ETHERNET_TX_EMPTY_EVENT))
	{
		unsigned int preservedBank = getBitField(baseAddress,BANK); 

		// Select Bank 2
		setBitField(baseAddress,BANK,BANK2);

		// Disable All INT 
		setBitField(baseAddress,INT_MASK,0);

		// The ownership of the SChArray is passed to the low level method
		sendFrame(m_currentSendFrameBuffer);

		// Restore the INT mask. This will enable interrupts
		setBitField(baseAddress,INT_MASK,m_intMask);

		// Restore the Bank to initial setting
		setBitField(baseAddress,BANK,preservedBank);
	}
	// }}}USR
}
// }}}RME

// {{{RME operation '~Lan91c96iCommon()'
Lan91c96iCommon::~Lan91c96iCommon( void )
{
	// {{{USR
	delete m_currentSendFrameBuffer;
	delete m_lan91c96iConfig;
	delete m_mutex;
	// }}}USR
}
// }}}RME

// {{{RME operation 'delay()'
void Lan91c96iCommon::delay( void )
{
	// {{{USR
	peripheral_address_short baseAddress = (peripheral_address_short)m_lan91c96iBaseAddress;	//Use local to allow compiler optimization
	unsigned int count = PTR_WAIT;
	volatile unsigned int temp = 0;
	unsigned int savedBank = getBitField(baseAddress,BANK);

	// Preserve the Bank
	setBitField(baseAddress,BANK,BANK2);

	// Read the pointer register a PTR_WAIT amount of time
	while(count--)
		temp = getBitField(baseAddress,POINTER);

	// Restore bank
	setBitField(baseAddress,BANK,savedBank);
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Status' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
