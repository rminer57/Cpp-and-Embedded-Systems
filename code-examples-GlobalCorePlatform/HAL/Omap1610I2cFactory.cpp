// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OMAP::I2c::OMAP1610I2c::Omap1610I2cFactory'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Omap1610I2cFactory.h"
#endif

#include <serial_comp.h>
#include <Omap1610I2cFactory.h>
#include <IOVirtualSerial.h>
#include <Omap1610I2c.h>
#include <Omap1610I2cConfig.h>
#include <bitfield.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
// OMAP1610 I2C Serial Peripheral Interface   reference OMAP1610 TRM Nov 2003

//
// Definition for the OMAP1610 Registers that allow the I2C to be connected to the external pins (balls).
//


#define	STANDARD			0
#define FAST				1
#define HIGH_DATA_RATE	0.4	// 400 kbps
#define LOW_DATA_RATE	0.1	// 100 kbps

#define ENABLE		1
#define DISABLE		0

#define SLAVE		0
#define MASTER		1

#define LITTLE_ENDIAN	0
#define BIG_ENDIAN		1

#define START_STOP		3

#define REG_OFFSET				0x04		// register offset (32 bits)

// The I2C register addresses are: START_ADDRESS + OFFSET
// All register are 32 bit wide, offset is 4 bytes/each
// Access supported is 16 bits or 32 bits.

//
//  OMAP1610 Registers
//

// Mnemonic  		Name
//	REV			Identification Register			 0
//	IE			Interrupt Enable Register		 4
//	STAT		Status Register					 8
//	SYSS		System Status Register			10
//	BUFF		Buffr Configuration Register	14
//	CNT			Data Counter Register			18
//	DATA		Data Access Register			1C
//	SYSC		System Configuration Register	20
//	CON			Configuration  Register			24
//	OA			Own Address Register			28
//	SA			Slave Address Register			2C
//	PSC			Clock Prescaler Register		30
//	LTC			Low Time Control Register 		34
//	HTC			High Time Control Register		38
//	SYSTEST		System Test Register			3C

#define REVISION_REG	REG_OFFSET *  0	//	0
#define IE_REG			REG_OFFSET *  1	//	4
#define STAT_REG		REG_OFFSET *  2	//	8
//      RSRVD_REG		REG_OFFSET *  3	//  C

#define SYSS_REG		REG_OFFSET *  4 // 10
#define BUFF_REG		REG_OFFSET *  5 // 14
#define CNT_REG			REG_OFFSET *  6 // 18
#define DATA_REG		REG_OFFSET *  7 // 1C
#define SYSC_REG		REG_OFFSET *  8 // 20
#define CON_REG			REG_OFFSET *  9 // 24
#define OADDRESS_REG	REG_OFFSET * 10 // 28
#define SA_REG			REG_OFFSET * 11 // 2C
#define PSC_REG			REG_OFFSET * 12 // 30
#define LTC_REG  		REG_OFFSET * 13 // 34
#define HTC_REG			REG_OFFSET * 14 // 38
#define SYSTEST_REG		REG_OFFSET * 15 // 3C


//
//  OMAP1610 I2C Bit descriptions
//

// REV  Revision Register
//			Bits 15 - 8 			Reserved
//			Bits  7 - 0 			Revision
defineBitField(REV,unsigned short,REVISION_REG,0,8);


// IE Register Interrup Enable
//									0 Disable
//									1 Enable
//          Bits 15 - 6				Reserved
//			Bit   5    		GC_IE	General Call
//			Bit   4    		XRDY_IE Transmit Data Ready
//			Bit   3    		RRDY_IE Receive Ready
//			Bit   2    		ARDY_IE Register Access Ready
//			Bit   1    		NACK_IE No acknoledgement
//			Bit   0	   		AL_IE	Arbitration Lost
defineBitField(GC_IE,unsigned short,IE_REG,5,1);
defineBitField(XRDY_IE,unsigned short,IE_REG,4,1);
defineBitField(RRDY_IE,unsigned short,IE_REG,3,1);
defineBitField(ARDY_IE,unsigned short,IE_REG,2,1);
defineBitField(NACK_IE,unsigned short,IE_REG,1,1);
defineBitField(AL_IE,unsigned short,IE_REG,0,1);

#define ENABLE_INT	1
#define DISABLE_INT	0

// STAT	Status Register		Provide core status information for interrupt
//									handling and other I2C control management
//			Bit  15     	SBD		Single Byte Data  Read Only
//					   				1 When last byte read from DATA register
//									  contains a single valid byte
//			Bit  14 - 13			Reserved
//			Bit  12			BB		Bus Busy - Indicate state of the serial Bus
//									0 Bus is free
//									1 Bus is occupied Master - Software controls
//			Bit  11			ROVR	Receive Overrun
//									0 Normal
//									1 Overrun
//			Bit  10			XUDF	Transmit underflow
//									0 Normal
//									1 Transmit underflow
//			Bit   9			AAS		Address As Slave
//									0 Normal
//									1 Address As Slave
//			Bit   8 -  6			Reserved
//			Bit	5			GC		General Call
//									0 No action
//									1 General Call
//			Bit   4			XRDY	Transmit Data Ready
//									0 Transmit buffer full(or receiver mode)
//									1 Transmit data ready (for write) and byte is
//									  needed
//			Bit   3			RRDY	Receive Data Ready
//									0 Receive buffer is empty
//									1 Receive data ready (for read)
//			Bit   2			ARDY	Register Access Ready
//									0 Normal/no action required
//									1 Access ready
//			Bit   1			NACK	No ACKnowledgement
//									0 Normal/no action required
//									1 NACK
//			Bit   0			AL		Arbitration Lost Interrupt Enable
//									0 Normal/No action required
//									1 NACK
defineBitField(SBD,unsigned short,STAT_REG,15,1);
defineBitField(BB,unsigned short,STAT_REG,12,1);
defineBitField(ROVR,unsigned short,STAT_REG,11,1);
defineBitField(XUDF,unsigned short,STAT_REG,10,1);
defineBitField(AAS,unsigned short,STAT_REG,9,1);
defineBitField(GC,unsigned short,STAT_REG,5,1);
defineBitField(XRDY,unsigned short,STAT_REG,4,1);
defineBitField(RRDY,unsigned short,STAT_REG,3,1);
defineBitField(ARDY,unsigned short,STAT_REG,2,1);
defineBitField(NACK,unsigned short,STAT_REG,1,1);
defineBitField(AL,unsigned short,STAT_REG,0,1);


// SYSS Register  	System Status Register
//			Bits 15 - 1				Reserved
//			Bit   0			RDONE	Reset Done
//									0  Internal module reset is ongoing or
//								   	   partially held in reset
//                              	1  Reset completed

defineBitField(RDONE,unsigned short,SYSS_REG,0,1);

//  BUFF	Buffer Configuration Regitser
//			Bit  15			RDMA_EN	Receive DMA channel enable
//									0  Receive DMA channel disable
//                              	1  Receive DMA channel enable
//			Bits 14 - 8				Reserved
//			Bit   7			XDMA_EN	Transmit DMA channel enable
//									0  Transmit DMA channel disable
//                              	1  Transmit DMA channel enable
//			Bits 6 - 0				Reserved

defineBitField(RDMA_EN,unsigned short,BUFF_REG,15,1);
defineBitField(XDMA_EN,unsigned short,BUFF_REG,7,1);

//   CNT   Regiter    Data count register
//                           		Counts the number of bytes receive or sent
//
defineBitField(DCOUNT,unsigned short,CNT_REG,0,15);


//   DATA Register
//			Bits 15 -  0			Data
//									Entry point for the local host to read
//									from or write to the FIFO buffer
//									FIFO size is 2 x 16 bits (4 bytes)
//
defineBitField(DATA,unsigned short,DATA_REG,0,15);

//   SYSC     System Configuration Register
//									Module is reset when this bit is set
//									0 Normal Mode
//									1 Soft Reset
//			Bits 15 -  2         	Reserved
//			Bit   1			SRST
//			Bit	  0					Reserved
defineBitField(SRST,unsigned short,SYSC_REG,1,1);

//   CON       Configuration Register
//			Bit  15      	EN		I2C module enable
//						   			0   I2C controller is reset
//						   			1   I2C module enabled
//			Bit  14			BE		Big endian mode
//									0   FIFO accessed in little-endian format
//									1   FIFO accessed in big-endian format
//			Bit  13 - 12			Reserved
//			Bit  11			STB		Start Byte
//									0   Normal mode
//									1   Start byte mode
//			Bit  10			MST		Master/Slave Mode
//									0   Slave
//									1   Master
//			Bit   9			TRX		Transmitter/Receiver Mode
//									0   Receiver
//									1   Transmitter
//			Bit   8			XA		Expand Address
//									0   7-bit address mode
//									1   10-bit address mode
//			Bit   7 -  2			Reserved
//			Bit	  1			STP		Stop condition
//									0   No action or stop condition detected
//									1   Stop condition queried
//			Bit   0			STT		Start Condition
//									0   No action or start condition detected
//									1   Start

defineBitField(EN,unsigned short,CON_REG,15,1);
defineBitField(BE,unsigned short,CON_REG,14,1);
defineBitField(STB,unsigned short,CON_REG,11,1);
defineBitField(MST,unsigned short,CON_REG,10,1);
defineBitField(TRX,unsigned short,CON_REG,9,1);
defineBitField(XA,unsigned short,CON_REG,8,1);
defineBitField(STP,unsigned short,CON_REG,1,1);
defineBitField(STT,unsigned short,CON_REG,0,1);
defineBitField(STT_STP,unsigned short,CON_REG,0,2);

#define RX_MODE	0
#define TX_MODE	1

#define SLAVE		0
#define MASTER		1

#define RESET		0

#define START_STOP	3

//   OADDRESS		Own Address Register
//			Bits 15 - 10			Reserved
//			Bits  9 -  0	OA      Own Address
//									If CON_XA = 1
//									   Bits 9 - 0 represent 10-bit address
//									  else
//									   Bits 9 - 7 000
//									   Bits 6 - 0 7-bit address
//									  endif
//									Reset = 0000000000
defineBitField(OA,unsigned short,OADDRESS_REG,0,10);

//  SA      Slave Address Register
//			Bits 15 - 10			Reserved
//			Bits  9 -  0	SA      Slave Address
//									   If CON_XA = 1
//									      Bits 9 - 0 represent 10-bit address
//                                     else
//									      Bits 9 - 7 000
//									      Bits 6 - 0 7-bit address
//                                     endif
//									   Reset = 0000000000
defineBitField(SA,unsigned short,SA_REG,0,10);


//  CP      Clock Prescaler Register
//			Bits 15 -  8			Reserved
//			Bits  7 -  0	PSC     Prescaler sampling clock divider value
//									Core uses PSC to divide the system clock
//									(SCLK) and generate its own internal sampling clock
//									Core I2C logic is sampled at a rate of the system
//									clock divided by (PSC+1)
//									0x00  Divide by 1 (PSC + 1)
//									0x01  Divide by 2
//									 ..    ...
//									0xFF  Divide by 256
//									Reset = 0000000000
defineBitField(PSC,unsigned short,PSC_REG,0,8);


//  LTC      Low Time Control Register
//			Bits 15 -  8			Reserved
//			Bits  7 -  0	SCLL    SCL Low-time value when Module is in Master Mode
//									SCL Low-time depends on the CP_PSC value
//									and the ICLK time period (Internal sampling
//									Clock rate)
//
//									If (PC_PSC == 0)
//
//									  tlow = (LTC_SCLL + 7)* ICLK; // time period
//
//									else if (PC_PSC == 1)
//
//									  tlow = (LTC_SCLL + 6)* ICLK; // time period
//
//									else  // PC_PSC > 1
//
//									  tlow = (LTC_SCLL + 5)* ICLK; // time period
//
//									endif
//									Reset = 0000000000
defineBitField(SCLL,unsigned short,LTC_REG,0,8);

//  HTC      Low Time Control Register
//			Bits 15 -  8			Reserved

//			Bits  7 -  0	SCLH    SCL High-time value when Module is in Master Mode
//									SCL High-time depends on the CP_PSC value
//									and the ICLK time period (Internal sampling
//									Clock rate)
//
//									If (PC_PSC == 0)
//
//									  tlow = (HTC_SCLH + 7)* ICLK; // time period
//
//									else if (PC_PSC == 1)
//
//									  tlow = (HTC_SCLH + 6)* ICLK; // time period
//
//									else  // PC_PSC > 1
//
//									  tlow = (HTC_SCLH + 5)* ICLK; // time period
//
//									endif
//									Reset = 0000000000
defineBitField(SCLH,unsigned short,HTC_REG,0,8);


//  SYSTEST  System Test Register
//			Bits 15			ST_EN   System Test Enable
//			Bits 14			FREE    Free running mode (on breakpoint)
//			Bits 13 - 12	TMODE   Test mode select
//			Bits 11			SSB		Set status bits
//			Bits 10 -  4			Reserved
//			Bit   3			CL_I	SCL line sense input value
//			Bit   2			SCL_O   SCL line drive output value
//			Bit   1			SDA_I   SDA line sense input value
//			Bit   0			SDA_O   SDA line drive output value
//									Reset = 0000000000
//			   WARNING!!! Never use this register in normal I2C operation
defineBitField(ST_EN,unsigned short,SYSTEST_REG,15,1);
defineBitField(FREE,unsigned short,SYSTEST_REG,14,1);
defineBitField(TMODE,unsigned short,SYSTEST_REG,12,2);
defineBitField(SSB,unsigned short,SYSTEST_REG,11,2);
defineBitField(SCL_I,unsigned short,SYSTEST_REG,3,1);
defineBitField(SCL_O,unsigned short,SYSTEST_REG,2,1);
defineBitField(SDA_I,unsigned short,SYSTEST_REG,1,1);
defineBitField(SDA_O,unsigned short,SYSTEST_REG,0,1);
// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
Omap1610I2cFactory::Omap1610I2cFactory( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
Omap1610I2cFactory::~Omap1610I2cFactory( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
Omap1610I2cFactory::Omap1610I2cFactory( const Omap1610I2cFactory & rtg_arg )
	: m_baseAddress( rtg_arg.m_baseAddress )
	, m_prescaler( rtg_arg.m_prescaler )
	, m_ownAddress( rtg_arg.m_ownAddress )
	, m_slowSpeed( rtg_arg.m_slowSpeed )
	, m_numTimesToPollRDYFlags( rtg_arg.m_numTimesToPollRDYFlags )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
Omap1610I2cFactory & Omap1610I2cFactory::operator=( const Omap1610I2cFactory & rtg_arg )
{
	if( this != &rtg_arg )
	{
		m_baseAddress = rtg_arg.m_baseAddress;
		m_prescaler = rtg_arg.m_prescaler;
		m_ownAddress = rtg_arg.m_ownAddress;
		m_slowSpeed = rtg_arg.m_slowSpeed;
		m_numTimesToPollRDYFlags = rtg_arg.m_numTimesToPollRDYFlags;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'getIOVirtualSerial(Omap1610I2cConfig*)'
IOVirtualSerial * Omap1610I2cFactory::getIOVirtualSerial( Omap1610I2cConfig * config )
{
	// {{{USR
	// Instantiate I2C object based in the I2C configuration to be used.
	return new Omap1610I2c(config,this);
	// }}}USR
}
// }}}RME

// {{{RME operation 'Omap1610I2cFactory(volatile unsigned short*,unsigned int,unsigned int,bool,unsigned int)'
Omap1610I2cFactory::Omap1610I2cFactory( volatile unsigned short * i2cBaseAddress, unsigned int prescaler, unsigned int ownAddress, bool slowSpeed, unsigned int numTimesToPollRDYFlags )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	:m_baseAddress(i2cBaseAddress), m_prescaler(prescaler), m_ownAddress(ownAddress), m_slowSpeed(slowSpeed), m_numTimesToPollRDYFlags(numTimesToPollRDYFlags)
	// }}}USR
	// }}}RME
{
	// {{{USR
	// Reset the peripheral.
	i2cReset();

	// }}}USR
}
// }}}RME

// {{{RME operation 'send(Omap1610I2cConfig*,unsigned char *,unsigned int)'
bool Omap1610I2cFactory::send( Omap1610I2cConfig * config, unsigned char * buffer, unsigned int size )
{
	// {{{USR
	bool ret = true;
	unsigned short word;
	unsigned int slaveAddress = config->m_slaveAddress;
	unsigned int i,j;


	//Wait for the bus to become available
	for (j=0; j<m_numTimesToPollRDYFlags; j++)
	{
	   if ( testBitField(m_baseAddress,BB) == 0 )
	   {
	      break;
	   }
	}

	//Disable the I2C bus ( not the registers ) for updating
	setBitField(m_baseAddress,EN,0);

	if ( j == m_numTimesToPollRDYFlags )
	{
	   ret = false;

	   //Re-enable the I2C bus to clear the BB bit
	   setBitField(m_baseAddress,EN,1);
	}
	else
	{
	   // Program the I2C as a Master
	   setBitField(m_baseAddress,MST,MASTER);

	   // Set the I2C in transmit mode
	   setBitField(m_baseAddress,TRX,1);

	   // Program the number of bytes to be transmitted
	   setBitField(m_baseAddress,DCOUNT,size);

	   // Program the Slave Address
	   setBitField(m_baseAddress,SA,slaveAddress);

	   // Program the I2C to the following transfer mode (this initiates the transfer):
	   // Start - Address - Data - ... - (n) ... - Data - STP
	   //
	   // STT bit = 1
	   // STP bit = 1
	   //
	   setBitField(m_baseAddress,STT_STP,3);

	   //Re-enable the I2C bus after register update
	   setBitField(m_baseAddress,EN,1);

	   //
	   // Main loop to send the data
	   //

	   for (i = 0; (i<size); i += 2) // 2 bytes == 1 word at a time
	   {
	      if (testBitField(m_baseAddress,NACK) == 0)
	      {
	         // Try sending for a while...
	         for (j=0; j<m_numTimesToPollRDYFlags; j++)
	         {
	            if (testBitField(m_baseAddress,XRDY) != 0)
	            {
	               //prepare data
	               word = (*buffer++ << 8);
	               word |= *buffer++;                        //on last byte, this may be garbage data...
	               *(combineAddr(m_baseAddress,DATA_REG)) = word;

	               // Clear the Tx bit for the next buffer data to transmit
	               setBitField(m_baseAddress,XRDY,1);

	               break;
	            }
	         }

	         // If we failed to send after a while, quit and return false.
	         if (j==m_numTimesToPollRDYFlags)
	         {
	            setBitField(m_baseAddress,STT,1);   // Send Stop to release the bus
	            ret = false;

	            // Reset the peripheral.
	            i2cReset();

	            break;
	         }
	      }
	      else // NACK = 1  No ACK received
	      {
	         setBitField(m_baseAddress,NACK,1);
	         setBitField(m_baseAddress,STT,1);   // Send Stop to release the bus
	         ret = false;
	         break;
	      }
	   }

	   setBitField(m_baseAddress,XRDY,1);
	   setBitField(m_baseAddress,ARDY,1);
	}

	return ret;

	// }}}USR
}
// }}}RME

// {{{RME operation 'receive(Omap1610I2cConfig*,unsigned int)'
unsigned char * Omap1610I2cFactory::receive( Omap1610I2cConfig * config, unsigned int size )
{
	// {{{USR
	unsigned short word;
	unsigned char *bufferStart;
	unsigned char *buffer = new unsigned char[size + size%2];                  //receive buffer (make next largest even)
	bufferStart = buffer;
	unsigned int slaveAddress = config->m_slaveAddress;
	unsigned int i,j;

	//Wait for the bus to become available
	for (j=0; j<m_numTimesToPollRDYFlags; j++)
	{
	   if ( testBitField(m_baseAddress,BB) == 0 )
	   {
	      break;
	   }
	}

	//Disable the I2C bus ( not the registers ) for updating
	setBitField(m_baseAddress,EN,0);

	if ( j == m_numTimesToPollRDYFlags )
	{
	   delete bufferStart;
	   bufferStart = 0;

	   //Re-enable the I2C bus to clear the BB bit
	   setBitField(m_baseAddress,EN,1);
	}
	else
	{

	   // Program the I2C as a Master
	   setBitField(m_baseAddress,MST,MASTER);

	   // Set the I2C in receive mode
	   setBitField(m_baseAddress,TRX,0);

	   // Program the number of bytes to be transmitted
	   setBitField(m_baseAddress,DCOUNT,size);

	   // Program the Slave Address
	   setBitField(m_baseAddress,SA,slaveAddress);

	   // Program the I2C to the following transfer mode:
	   // Start - Address - Data - ... - (n) ... - Data - STP
	   //
	   // STT bit = 1
	   // STP bit = 1
	   //
	   setBitField(m_baseAddress,STT_STP,3);

	   //Re-enable the I2C bus after register update
	   setBitField(m_baseAddress,EN,1);

	   //
	   // Main loop to receive data
	   //

	   for (i=0; (i<size); i+=2) // 2 bytes == 1 word at a time
	   {
	      if (testBitField(m_baseAddress,NACK) == 0)
	      {
	         // Try receiving for a while...
	         for (j=0; j<m_numTimesToPollRDYFlags; j++)
	         {
	            if (testBitField(m_baseAddress,RRDY) != 0)
	            {
	               // Receive word
	               word = *(combineAddr(m_baseAddress,DATA_REG));
	               *buffer++ = (word >> 8);
	               *buffer++ = word;

	               // Clear the Rx bit for the next byte transmission
	               setBitField(m_baseAddress,RRDY,1);

	               break;
	            }
	         }

	         // If we failed to receive after a while, quit.
	         if (j==m_numTimesToPollRDYFlags)
	         {
	            delete bufferStart;
	            bufferStart = 0;

	            setBitField(m_baseAddress,STT_STP,1); // Send Stop to release the bus

	            // Reset the peripheral.
	            i2cReset();

	            break;
	         }
	      }
	      else // NACK = 1
	      {
	         setBitField(m_baseAddress,NACK,1);
	         delete bufferStart;
	         bufferStart = 0;
	         break;
	      }
	   }

	   setBitField(m_baseAddress,RRDY,1);
	   setBitField(m_baseAddress,ARDY,1);
	}

	return bufferStart;

	// }}}USR
}
// }}}RME

// {{{RME operation 'i2cReset()'
void Omap1610I2cFactory::i2cReset( void )
{
	// {{{USR
	unsigned int i2cClockRatio = 30;
	unsigned int m_scl;

	// Disable the I2C Module
	setBitField(m_baseAddress,EN,DISABLE);

	// Perform a soft reset to the I2C Port
	setBitField(m_baseAddress,SRST,1);

	// Enable the I2C Module
	setBitField(m_baseAddress,EN,ENABLE);

	// Wait for reset to complete
	while ( testBitField(m_baseAddress,RDONE) == 0 );

	// Disable the I2C Module for setup
	setBitField(m_baseAddress,EN,DISABLE);

	//
	//	To set up the SCLL and SCLH register, the client
	//  must input the data bit rate at which the I2C
	//  will operate: 100 kbps or 400 kbps (default)
	//
	//  Based on this input the values for the SCLL and SCLH
	//  are calculated. The calculation method is as follows:
	//
	//	if PCS = 0 then SCLL = SCLH = [ICLOCK (MHz) / (2*SCL) (MHz)] - 7
	//  if PCS = 1 then SCLL = SCLH = [ICLOCK (MHz) / (2*SCL) (MHz)] - 6
	//  if PCS > 1 then SCLL = SCLH = [ICLOCK (MHz) / (2*SCL) (MHz)] - 5
	//
	switch (m_prescaler)
	{
		case 0:
			m_scl = (i2cClockRatio * (m_slowSpeed?1:4)) - 7;
			break;
		case 1:
			m_scl = (i2cClockRatio * (m_slowSpeed?1:4)) - 6;
			break;
		default:
			m_scl = (i2cClockRatio * (m_slowSpeed?1:4)) - 5;
			break;
	}


	// Program the SCLL register for tLow
	setBitField(m_baseAddress,SCLL,m_scl);

	// Program the SCLH register for tHigh
	setBitField(m_baseAddress,SCLH,m_scl);

	// Program the PSC register
	setBitField(m_baseAddress,PSC,m_prescaler);

	// Set the I2C own address
	setBitField(m_baseAddress,OA,m_ownAddress);

	// Program the I2C to 7 bit addressing
	setBitField(m_baseAddress,XA,0);

	// Program the I2C to Normal Mode
	setBitField(m_baseAddress,STB,0);

	// Enable the I2C Module
	setBitField(m_baseAddress,EN,ENABLE);

	// Program the I2C to send/receive in Big Endian Mode
	setBitField(m_baseAddress,BE,BIG_ENDIAN);

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
