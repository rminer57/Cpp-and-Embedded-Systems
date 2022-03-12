// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OMAP::Spi::OMAP1610Spi::Omap1610SpiFactory'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Omap1610SpiFactory.h"
#endif

#include <serial_comp.h>
#include <Omap1610SpiFactory.h>
#include <Omap1610Spi.h>
#include <SIntArray.h>
#include <bitfield.h>
#include <peripheral_access.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
/************************************************************************************/
// OMAP1610 SPI Serial Periferal Interface   reference OMAP1610 Nov 2003 
// The SPI register addresses are: SPI_START_ADDRESS + OFFSET
// All register are 32 bit wide, offset is 4 bytes/each
// Access supported is 16 bits or 32 bits.
// SPI uses little-endian addressing scheme

//
//  OMAP1610 Registers (Table 14-2)
//

// Mnemonic  Name                                       
// SPI_REV   Identification Register                    
// SPI_SCR   System Configuration Register              
// SPI_SSR   System Status Register                     
// SPI_ISR   Interrupt Status Register                  
// SPI_IER   Interrupt Enable Register                  
// SPI_SET1  Setup 1 Register: Serial Port Configuration
// SPI_SET2  Setup 2 Register: Serial Port Configuration
// SPI_CTRL  Control Register
// SPI_DSR   Shift Status Register
// SPI_TX    Data Tx register
// SPI_RX    Data Rx register
// SPI_TEST  Test register

#ifdef OMAP_HALI_C55
	#define RO 2
#else
	#define RO 2
#endif

#define SPI_REV   0x00*RO
//      SPI_RSVD1 0x02*RO
//      SPI_RSVD2 0x04*RO
//      SPI_RSVD3 0x06*RO
#define SPI_SCR   0x08*RO
#define SPI_SSR   0x0A*RO
#define SPI_ISR   0x0C*RO
#define SPI_IER   0x0E*RO
//      SPI_RSVD4 0x10*RO
#define SPI_SET1  0x12*RO
#define SPI_SET2  0x14*RO
#define SPI_CTRL  0x16*RO
#define SPI_DSR   0x18*RO
#define SPI_TX    0x1A*RO
#define SPI_RX    0x1C*RO
#define SPI_TEST  0x1E*RO

//
//  OMAP1610 Registers bit description
//

// SPI_REV
defineBitField(REV,unsigned int,SPI_REV,0,8);
defineBitField(REV_maj,unsigned int,SPI_REV,4,4);
defineBitField(REV_min,unsigned int,SPI_REV,0,4);

// SPI_SCR Register   
defineBitField(IDLEMODE,unsigned int,SPI_SCR,3,2);
defineBitField(EN_AWAKEUP,unsigned int,SPI_SCR,2,1);
defineBitField(SOFTRESET,unsigned int,SPI_SCR,1,1);
defineBitField(AUTOIDLE,unsigned int,SPI_SCR,0,1);

#define FORCE_IDLE_ACK     0 
#define NO_IDLE            1 
#define SMART_IDLE         2

#define WAKEUP_DISABLE     0
#define WAKEUP_ENABLE      1

#define NORMAL_MODE        0
#define TRIGGER_SOFT_RESET 1

#define OCP_FREE_RUNNING   0
#define OCP_AUTO           1 

// SPI_SSR
defineBitField(RESET_DONE,unsigned int,SPI_SSR,0,1);

// SPI_ISR Register
defineBitField(WAKEUP,unsigned int,SPI_ISR,4,1);
defineBitField(TX_UNDERFLOW,unsigned int,SPI_ISR,3,1);
defineBitField(RX_OVERFLOW, unsigned int,SPI_ISR,2,1);
defineBitField(WE,unsigned int,SPI_ISR,1,1);
defineBitField(RE,unsigned int,SPI_ISR,0,1);

//  SPI_IER Regitser
defineBitField(MSK4,unsigned int,SPI_IER,4,1);
defineBitField(MSK3,unsigned int,SPI_IER,3,1);
defineBitField(MSK2,unsigned int,SPI_IER,2,1);
defineBitField(MSK1,unsigned int,SPI_IER,1,1);
defineBitField(MSK0,unsigned int,SPI_IER,0,1);


//   SPI_SET1
defineBitField(DMA_EN,unsigned int,SPI_SET1,5,1);
defineBitField(PTV,unsigned int,SPI_SET1,1,4);
defineBitField(EN_CLK,unsigned int,SPI_SET1,0,1);

#define MCU_DSP 0
#define DMA     1

//   SPI_SET2 Register
defineBitField(MODE,unsigned int,SPI_SET2,15,1);
defineBitField(CP,unsigned int,SPI_SET2,10,5);
 defineBitField(CP5,unsigned int,SPI_SET2,14,1);
 defineBitField(CP4,unsigned int,SPI_SET2,13,1);
 defineBitField(CP3,unsigned int,SPI_SET2,12,1);
 defineBitField(CP2,unsigned int,SPI_SET2,11,1);
 defineBitField(CP1,unsigned int,SPI_SET2,10,1);
defineBitField(CE,unsigned int,SPI_SET2,5,5);
 defineBitField(CE5,unsigned int,SPI_SET2,9,1);
 defineBitField(CE4,unsigned int,SPI_SET2,8,1);
 defineBitField(CE3,unsigned int,SPI_SET2,7,1);
 defineBitField(CE2,unsigned int,SPI_SET2,6,1);
 defineBitField(CE1,unsigned int,SPI_SET2,5,1);
defineBitField(CI,unsigned int,SPI_SET2,0,5);
 defineBitField(CI5,unsigned int,SPI_SET2,4,1);
 defineBitField(CI4,unsigned int,SPI_SET2,3,1);
 defineBitField(CI3,unsigned int,SPI_SET2,2,1);
 defineBitField(CI2,unsigned int,SPI_SET2,1,1);
 defineBitField(CI1,unsigned int,SPI_SET2,0,1);

//   SPI_CTRL
defineBitField(AD,unsigned int,SPI_CTRL,7,3);
defineBitField(NB,unsigned int,SPI_CTRL,2,5);
defineBitField(WR,unsigned int,SPI_CTRL,1,1);
defineBitField(RD,unsigned int,SPI_CTRL,0,1);

//   SPI_DSR
defineBitField(TX_EMPTY,unsigned int,SPI_DSR,1,1);
defineBitField(RX_FULL,unsigned int,SPI_DSR,0,1);

//   SPI_TX                              Transmit Register
//   SPI_RX                              Receive Register

//   SPI_TEST
defineBitField(RTSPEN,unsigned int,SPI_TEST,10,5);
defineBitField(RCV,unsigned int,SPI_TEST,5,1);
defineBitField(WCV,unsigned int,SPI_TEST,4,1);
defineBitField(RTV,unsigned int,SPI_TEST,3,1);
defineBitField(WTV,unsigned int,SPI_TEST,2,1);
defineBitField(FDO,unsigned int,SPI_TEST,1,1);
defineBitField(TMODE,unsigned int,SPI_TEST,0,1);

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
Omap1610SpiFactory::Omap1610SpiFactory( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
Omap1610SpiFactory::~Omap1610SpiFactory( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
Omap1610SpiFactory::Omap1610SpiFactory( const Omap1610SpiFactory & rtg_arg )
	: IrqHandler( rtg_arg )
	, m_baseAddress( rtg_arg.m_baseAddress )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
Omap1610SpiFactory & Omap1610SpiFactory::operator=( const Omap1610SpiFactory & rtg_arg )
{
	if( this != &rtg_arg )
	{
		IrqHandler::operator=( rtg_arg );
		m_baseAddress = rtg_arg.m_baseAddress;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'getIOVirtualSerial(OMAPSpiConfig*)'
IOVirtualSerial * Omap1610SpiFactory::getIOVirtualSerial( OMAPSpiConfig * config )
{
	// {{{USR
	// Instantiate spi object based in the SPI configuration and type of control to be used.
	return new Omap1610Spi(config,this);

	// }}}USR
}
// }}}RME

// {{{RME operation 'Omap1610SpiFactory(unsigned int)'
Omap1610SpiFactory::Omap1610SpiFactory( unsigned int spiBaseAddr )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_baseAddress(spiBaseAddr)
	// }}}USR
	// }}}RME
{
	// {{{USR
	peripheral_address baseAddress = (peripheral_address)m_baseAddress;	//Use local to allow compiler optimization

	//Reset the peripheral core
	setBitField(baseAddress,SOFTRESET,TRIGGER_SOFT_RESET);
	//while(!testBitField(baseAddress,SPI_SSR_RESET_DONE)){ };

	//Setup global configuration
	setBitField(baseAddress,IDLEMODE,NO_IDLE);
	setBitField(baseAddress,EN_AWAKEUP,WAKEUP_DISABLE);
	setBitField(baseAddress,AUTOIDLE,OCP_FREE_RUNNING);

	// Program the SPI to be accessed by the MCU-DSP processors. No DMA operation
	setBitField(baseAddress,DMA_EN,MCU_DSP);

	// Enable the proper device and bit size for transfers
	setBitField(baseAddress,AD,0);						//device 0
	setBitField(baseAddress,NB,15);						//15 bits

	// Program the SPI mode to MASTER
	setBitField(baseAddress,MODE,1);

	//Enable device 1 shift register active level 
	setBitField(baseAddress,CE1,0);

	// Program clock enable
	setBitField(baseAddress,EN_CLK,1);

	// }}}USR
}
// }}}RME

// {{{RME operation 'configure(OMAPSpiConfig*)'
void Omap1610SpiFactory::configure( OMAPSpiConfig * config )
{
	// {{{USR
	peripheral_address baseAddress = (peripheral_address)m_baseAddress;	//Use local to allow compiler optimization

	//Setup clock divisor, phase and polarity
	setBitField(baseAddress,PTV,config->m_clockDivisor);
	setBitField(baseAddress,CP1,config->m_clockPhase);
	setBitField(baseAddress,CI1,config->m_clockPolarity);

	// }}}USR
}
// }}}RME

// {{{RME operation 'handler()'
void Omap1610SpiFactory::handler( void )
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'sendAndReceive(SIntArray *,bool,bool)'
void Omap1610SpiFactory::sendAndReceive( SIntArray * buffer, bool skipFirstByte, bool skipLastByte )
{
	// {{{USR
	// Get buffer size
	peripheral_address baseAddress = (peripheral_address)m_baseAddress;				//Use local to allow compiler optimization

	//If the first or last byte is to be skipped, reduce count
	int size = buffer->getLength() - (skipLastByte?1:0) - (skipFirstByte?1:0);		//length in words
	int count = 0;

	//The following sections are intentionally inlined as a performance optimization....
	//If the last byte has been skipped, handle it here...
	if (skipFirstByte)
	{
		setBitField(baseAddress,NB,7);									//8 bits

		//Put data in shift register and begin transmit
		*(combineAddr(baseAddress,SPI_TX)) = (*buffer)[count];  
		setBitField(baseAddress,RD,1);

		//Wait for completion
		while(testBitField(baseAddress,TX_EMPTY) == 0);

		 //Get received data (LSB)
		(*buffer)[count++] = (*(combineAddr(baseAddress,SPI_RX))) & 0xFF;

		setBitField(baseAddress,NB,15);									//restore to 16 bits
	}

	//repeat for all whole words
	while(size > 0)
	{
		//Put data in shift register and begin transmit
		*(combineAddr(baseAddress,SPI_TX)) = (*buffer)[count];  
		setBitField(baseAddress,RD,1);

		size--;															//reduce counter

		//Wait for completion
		while(testBitField(baseAddress,TX_EMPTY) == 0);

		 //Get received data
		(*buffer)[count++] = *(combineAddr(baseAddress,SPI_RX));
	}

	//If the last byte has been skipped, handle it here...
	if (skipLastByte)
	{
		setBitField(baseAddress,NB,7);									//8 bits

		//Put data in shift register and begin transmit
		*(combineAddr(baseAddress,SPI_TX)) = ((*buffer)[count] >> 8);  
		setBitField(baseAddress,RD,1);

		//Wait for completion
		while(testBitField(baseAddress,TX_EMPTY) == 0);

		 //Get received data
		(*buffer)[count++] = *(combineAddr(baseAddress,SPI_RX)) << 8;

		setBitField(baseAddress,NB,15);									//restore to 16 bits
	}
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
