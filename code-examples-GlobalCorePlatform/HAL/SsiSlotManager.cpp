// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OMAP::Ssi::OmapSsiIOVirtualSerial::SsiSlotManager'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "SsiSlotManager.h"
#endif

#include <serial_comp.h>
#include <SsiSlotManager.h>
#include <HALiNucleusNotifier.h>
#include <IOVirtualSerial.h>
#include <McBsp.h>
#include <OmapAsyncSsiIOVirtualSerial.h>
#include <OmapRawSsiIOVirtualSerial.h>
#include <OmapSsiCommon.h>
#include <bitfield.h>
#include <peripheral_access.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
#ifndef OMAP_HALI_C55
   #define BASE_ADDRESS 0xFFFED800
   #define DMARO 2
   #define BLOCK_START 0x00
#else
   #define BASE_ADDRESS 0x0
   #define DMARO 1
   #define BLOCK_START 0xC00
#endif

#define DMA_CSDP(n)       *(peripheral_address_short)(BASE_ADDRESS + BLOCK_START + 0x00 + (n*0x20*DMARO))
#define DMA_CCR(n)		*(peripheral_address_short)(BASE_ADDRESS + BLOCK_START + 0x01*DMARO + (n*0x20*DMARO))
#define DMA_CICR(n) 	*(peripheral_address_short)(BASE_ADDRESS + BLOCK_START + 0x02*DMARO + (n*0x20*DMARO))
#define DMA_CSR(n)		*(peripheral_address_short)(BASE_ADDRESS + BLOCK_START + 0x03*DMARO + (n*0x20*DMARO))
#define DMA_CSSAL(n)	*(peripheral_address_short)(BASE_ADDRESS + BLOCK_START + 0x04*DMARO + (n*0x20*DMARO))
#define DMA_CSSAU(n)	*(peripheral_address_short)(BASE_ADDRESS + BLOCK_START + 0x05*DMARO + (n*0x20*DMARO))
#define DMA_CDSAL(n)	*(peripheral_address_short)(BASE_ADDRESS + BLOCK_START + 0x06*DMARO + (n*0x20*DMARO))
#define DMA_CDSAU(n)    *(peripheral_address_short)(BASE_ADDRESS + BLOCK_START + 0x07*DMARO + (n*0x20*DMARO))
#define DMA_CEN(n)		*(peripheral_address_short)(BASE_ADDRESS + BLOCK_START + 0x8*DMARO + (n*0x20*DMARO))
#define DMA_CFN(n)		*(peripheral_address_short)(BASE_ADDRESS + BLOCK_START + 0x9*DMARO + (n*0x20*DMARO))
#define DMA_CFI(n)		*(peripheral_address_short)(BASE_ADDRESS + BLOCK_START + 0xA*DMARO + (n*0x20*DMARO))
#define DMA_CEI(n)		*(peripheral_address_short)(BASE_ADDRESS + BLOCK_START + 0xB*DMARO + (n*0x20*DMARO))

// }}}USR
// }}}RME
// {{{RME classifier 'Config' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classifier 'Config'

// {{{RME operation 'Config(bool,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int)'
SsiSlotManager::Config::Config( bool mode, unsigned int unit, unsigned int slots, unsigned int frameFrequency, unsigned int mcbspInputClockFrequency, unsigned int maxReceiveBufferSize )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_ssiMaster(mode), m_mcbspUnit(unit), m_slotsPerFrame(slots), m_frameFrequency(frameFrequency), m_mcbspInputClockFrequency(mcbspInputClockFrequency), m_maxReceiveBufferSize(maxReceiveBufferSize)
	// }}}USR
	// }}}RME
{
	// {{{USR
	if( (m_mcbspUnit < 1)|| ( m_mcbspUnit > 3) )
	{
	   m_mcbspUnit=2;
	}

	if( m_slotsPerFrame > 32 )
	{
	   m_slotsPerFrame=4;
	}

	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME classAttribute 'm_baseAddressArray'
unsigned short * const SsiSlotManager::m_baseAddressArray[] = { (unsigned short*)0xE1011800, (unsigned short*)0xFFFB1000, (unsigned short*)0xE1017000 };
// }}}RME

// {{{RME classAttribute 'm_mcBspIrqArray'
const unsigned int SsiSlotManager::m_mcBspIrqArray[][ 3 ] = { { 42, 43 }, { 4, 5 },  { 44, 45 } };
// }}}RME

// {{{RME classAttribute 'IDLE_HIGH'
const unsigned short int SsiSlotManager::IDLE_HIGH( 0xFFFF );
// }}}RME

// {{{RME classAttribute 'IDLE_LOW'
const unsigned short int SsiSlotManager::IDLE_LOW( 0x0000 );
// }}}RME

// {{{RME classAttribute 'EVENT_ISR_BUFFER_FULL'
const unsigned int SsiSlotManager::EVENT_ISR_BUFFER_FULL( 2400 );
// }}}RME

// {{{RME operation 'SsiSlotManager(SsiSlotManager::Config*,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,uint16_t*,uint16_t*,unsigned int,unsigned int)'
SsiSlotManager::SsiSlotManager( Config * cfg, unsigned int baseAddr, unsigned int irq, unsigned int dmachan, unsigned int dmareq, unsigned int dmaBufferFrames, uint16_t * tx_DmaBuffer, uint16_t * rx_DmaBuffer, unsigned int rxDMATransferDestinationPort, unsigned int txDMATransferDestinationPort )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_managerConfig(cfg),m_slotMask(0), m_serialWordSize(16), 
	m_slotsPerFrame(m_managerConfig->m_slotsPerFrame), m_lowerHalf(true), m_resync(false),
	m_baseAddress(baseAddr), m_irq(irq), m_dmachan(dmachan), m_dmareq(dmareq),
	m_dmaNumFrames(dmaBufferFrames), m_autoEvent(EVENT_ISR_BUFFER_FULL)
	// }}}USR
	// }}}RME
{
	// {{{USR
	unsigned int i;

	volatile unsigned int clkgDivisor;

	//setup slot connection array with default, non-connected configuration
	for(i = 0; i < 32; i++)
	{
	   m_ssiConnectionArray[i] = 0;
	}

	//setup DMA buffer sizes and control
	m_dmaNumFrames = m_dmaNumFrames==0?1:m_dmaNumFrames;			//minimum size is 1
	m_dmaBufferSize = m_dmaNumFrames * cfg->m_slotsPerFrame;

	// Create dma buffers for transmit and receive (double buffered), setup flags to allow cleanup of buffers
	txDmaLocal = (tx_DmaBuffer == 0);
	rxDmaLocal = (rx_DmaBuffer == 0);
	txDmaBuffer = tx_DmaBuffer != 0?tx_DmaBuffer:new uint16_t[m_dmaBufferSize * 2];
	rxDmaBuffer = rx_DmaBuffer != 0?rx_DmaBuffer:new uint16_t[m_dmaBufferSize * 2];



	// Initialize dma buffers
	for(i = 0; i < m_dmaBufferSize * 2; i++)
	{
	   rxDmaBuffer[i] = IDLE_HIGH;
	   txDmaBuffer[i] = IDLE_HIGH;
	}


	// Set baseAddress of mcbsp
	peripheral_address_short baseAddress = (peripheral_address_short)m_baseAddress;	//Use local to allow compiler optimization

	// Step 1. Place transmitter, receiver and sample rate generator in reset

	// Reset Receiver
	setBitField(baseAddress, RRST, 0);

	// Reset Transmitter
	setBitField(baseAddress, XRST, 0);

	// Reset frame synchronization logic
	setBitField(baseAddress, FRST, 0);

	// Reset Sample Rate Generator
	setBitField(baseAddress, GRST, 0);

	// Disable digital loopback mode
	setBitField(baseAddress, DLB, 0);

	// Allow McBSP transmit and receive clocks to 
	// run when a breakpoint is encountered in the 
	// high-level language debugger.
	setBitField(baseAddress, FREE, 1);

	// Disable Clock Stop Mode
	setBitField(baseAddress, CLKSTP, 0);

	// Set frame-synchronization pulse width
	setBitField(baseAddress, FWID, 0);

	// Set sample rate generator output frequency - CLKG
	clkgDivisor = ((m_managerConfig->m_mcbspInputClockFrequency)/(m_managerConfig->m_slotsPerFrame * m_serialWordSize * m_managerConfig->m_frameFrequency)) - 1 ;

	setBitField(baseAddress, CLKGDV, clkgDivisor);

	// Use internal clock syncronization
	setBitField(baseAddress, GSYNC, 0);

	// Transmitter uses frame-synchronization pulses generated by the sample rate generator.
	setBitField(baseAddress, FSGM, 1);

	// Set frame sync period
	setBitField(baseAddress, FPER, (m_managerConfig->m_slotsPerFrame * m_serialWordSize) - 1);

	// Receive frame synchronization is supplied by the FSX pin that is tied to the 
	// FSR pin externally. FSR is an input pin reflecting internal FSR.
	setBitField(baseAddress, FSRM, 0x0);

	// The CLKR pin is an input driven by an external clock.
	setBitField(baseAddress, CLKRM, 0x0);


	// CLKSM in conjunction with SCLKME selects the source of 
	// input clock for the sample rate generator

	// Ssi master mode
	if(m_managerConfig->m_ssiMaster)
	{

	   // Sample rate generator clock derived from CPU clock
	   setBitField(baseAddress, SCLKME, 0x0);
	   setBitField(baseAddress, CLKSM,  0x1);

	   // CLKX is an output pin
	   setBitField(baseAddress, CLKXM,  0x1);

	   // Transmit frame synchronization is supplied by the McBSP,
	   setBitField(baseAddress, FSXM,  0x1);

	}
	else // Ssi slave mode
	{

	   // Sample rate generator clock derived from CLKX pin.
	   // The transmitter gets its clock signal from
	   // an external source via the CLKX pin.
	   setBitField(baseAddress, SCLKME, 0x1);
	   setBitField(baseAddress, CLKSM,  0x1);

	   // CLKX is an input pin
	   setBitField(baseAddress, CLKXM,  0x0);

	   // Transmit frame synchronization is supplied externally,
	   setBitField(baseAddress, FSXM,  0x0);
	}


	// -------------------------
	// Step 2.Configure receiver
	// -------------------------

	// Set the receiver Pins to Operate as McBSP Pins
	setBitField(baseAddress, RIOEN, 0);

	// Ignore receive sync errors
	setBitField(baseAddress, RSYNCERR, 0);

	// Set receive frame length  i.e logical time slots per frame 
	setBitField(baseAddress, RFRLEN1, m_managerConfig->m_slotsPerFrame - 1);

	// Serial Word Size
	setBitField(baseAddress, RWDLEN1,m_serialWordSize == 32?5:(m_serialWordSize/4) - 2);

	// Set receive phase to one
	setBitField(baseAddress, RPHASE, 0x0);

	// No companding
	setBitField(baseAddress, RCOMPAND, 0x0);

	// Do not ignore unexpected revceive frame sync pulses
	setBitField(baseAddress, RFIG, 0); // do not ignore

	// Receive data delay of 1 bit.
	setBitField(baseAddress, RDATDLY, 1); // 1-bit data delay

	// Config receive interrupt mode to
	// interrupt on every serial word
	setBitField(baseAddress, RINTM, 0x0);

	// -----------------------------
	// Step 3. Configure transmitter
	// -----------------------------

	// Set the Transmitter Pins to Operate as McBSP Pins
	setBitField(baseAddress, XIOEN, 0);

	// Config transmit interrupt mode - interrupt generated by new transmit frame sync
	setBitField(baseAddress, XINTM, 0x2);

	// Ignore transmit sync errors
	setBitField(baseAddress, XSYNCERR, 0);

	// Set transmit frame length  i.e logical time slots per frame 
	setBitField(baseAddress, XFRLEN1, m_managerConfig->m_slotsPerFrame - 1 );

	// Set transmit word size
	setBitField(baseAddress, XWDLEN1,m_serialWordSize == 32?5:(m_serialWordSize/4) - 2);


	// Set transmit phase to one
	setBitField(baseAddress, XPHASE, 0);

	// No companding
	setBitField(baseAddress, XCOMPAND, 0);

	// Do not ignore unexpected transmit frame sync pulses
	setBitField(baseAddress, XFIG, 0); // do not ignore

	// Transmit data delay of 1 bit.
	setBitField(baseAddress, XDATDLY, 1); // 1-bit data delay


	// Set multichannel selection modes 

	// Symmetric transmission and reception.
	setBitField(baseAddress, XMCM,  0x3);
	setBitField(baseAddress, RMCM,  0x1);

	// Select 2 partition mode for transmit and receive
	setBitField(baseAddress, XMCME,  0x0);
	setBitField(baseAddress, RMCME,  0x0);

	// Assign block 0 to partition A and block 1 to partition B
	setBitField(baseAddress, RPABLK,  0x0);
	setBitField(baseAddress, RPBBLK,  0x0);

	// Enable receive channels
	for(i = 0; i < cfg->m_slotsPerFrame; i++)
	{
	   setBit(combineAddr(baseAddress, RCERA), i, 1);
	}

	// Step 3. Enable Frame Synchronization logic and sample rate generator

	// Enable frame sync and sample rate generator only if master.
	if(m_managerConfig->m_ssiMaster)
	{
	   // Enable Sample Rate Generator
	   setBitField(baseAddress, GRST, 1);

	   // Enable Frame Synchronization logic
	   setBitField(baseAddress, FRST, 1);
	}

	//Register for events from ISR
	registerListener(this,EVENT_ISR_BUFFER_FULL);

	//Set-up this instance for event notification propagation
	HALiNucleusNotifier::registerIrq(this, m_irq, this);

	// Initialize dma channels used for transmit and receive
	initTxDmaChannel(txDMATransferDestinationPort);
	initRxDmaChannel(rxDMATransferDestinationPort);

	// Enable Transmitter.
	setBitField(baseAddress, XRST, 1);

	// Enable Receiver.
	setBitField(baseAddress, RRST, 1);


	// }}}USR
}
// }}}RME

// {{{RME operation 'getIOVirtualSerial(unsigned int,bool,bool)'
IOVirtualSerial * SsiSlotManager::getIOVirtualSerial( unsigned int slotRequest, bool asyncMode, bool transmitOnly )
{
	// {{{USR
	unsigned int i;
	unsigned short mask;
	OmapSsiCommon* omapSsiCommonRef;
	IOVirtualSerial* retValue;
	peripheral_address_short baseAddress = (peripheral_address_short)m_baseAddress;	//Use local to allow compiler optimization

	// Check if any of the requested slots are in use.
	if( !((slotRequest==0) || (m_slotMask & slotRequest) != 0 ))
	{
	   m_slotMask = m_slotMask | slotRequest;

	   if(asyncMode)
	   {
	      OmapAsyncSsiIOVirtualSerial *temp = new OmapAsyncSsiIOVirtualSerial(this);
	      omapSsiCommonRef = temp;
		  retValue = temp;
	   }
	   else
	   {
	      OmapRawSsiIOVirtualSerial *temp = new OmapRawSsiIOVirtualSerial(this,transmitOnly,m_managerConfig->m_maxReceiveBufferSize);
	      omapSsiCommonRef = temp;
		  retValue = temp;
	   }
	   
	   for(i = 0; i < 32; i++)
	   {
	      if(testBit(&slotRequest, i) != 0)
	      {	
	         m_ssiConnectionArray[i] = omapSsiCommonRef;
	      }
	   }

	   // Enable the transmit channel registers A and B that correspond to mask

	   mask = slotRequest & 0xFFFF;
	   *(combineAddr(baseAddress, XCERA)) |= mask;

	   mask = slotRequest >> 16;
	   *(combineAddr(baseAddress, XCERB)) |= mask;
	}

	// Return serial instance
	return retValue;
	// }}}USR
}
// }}}RME

// {{{RME operation 'unRegisterSlots(OmapSsiCommon*)'
void SsiSlotManager::unRegisterSlots( OmapSsiCommon * omapSsiCon )
{
	// {{{USR
	unsigned int i;

	for(i = 0; i < 32; i++)
	{
	   if(m_ssiConnectionArray[i] == omapSsiCon)   
	   {
	      setBit(&m_slotMask, i, 0);
	      m_ssiConnectionArray[i] = 0;
	   }
	}
	// }}}USR
}
// }}}RME

// {{{RME operation 'handler()'
void SsiSlotManager::handler( void )
{
	// {{{USR
	peripheral_address_short baseAddress = (peripheral_address_short)m_baseAddress;	//Use local to allow compiler optimization

	//Trigger handling of this buffer
	informListeners(&m_autoEvent);
	m_lowerHalf= !m_lowerHalf;

	//clear the status bits and re-enable DMA interrupt
	int ret = DMA_CSR(m_dmachan);

	// }}}USR
}
// }}}RME

// {{{RME operation 'initTxDmaChannel(unsigned int)'
void SsiSlotManager::initTxDmaChannel( unsigned int txDMATransferPort )
{
	// {{{USR
	unsigned int chan = m_dmachan;

	//Tx DmaBuffer address
	unsigned short tx_src_high=(unsigned short)(((unsigned long)txDmaBuffer)>>16);
	unsigned short tx_src_low=(unsigned short)((unsigned long)(txDmaBuffer));

	//Mcbsp tx register address
	unsigned int destinationAddress = m_baseAddress + DXR1;

	unsigned short tx_dst_high = (unsigned short)(((unsigned long)destinationAddress)>>16);
	unsigned short tx_dst_low=(unsigned short)((unsigned int)(destinationAddress));

	unsigned int CSDPval = (((txDMATransferPort) & 0xF) << 2) | 0x601;	//reference Table 8.52 (port->TIPB,16bit)
	unsigned int CCRval = 0x1BC0 + m_dmareq;							//reference Table 8.54 (AUTO_INIT,REPEAT,PRIROITY,ENABLE)
	unsigned int CICRval = 0x0009;										//FRAME and TOUT interrupts enabled.

#ifdef OMAP_HALI_C55
	tx_dst_high <<= 1;
	tx_dst_low <<= 1;
	tx_src_high <<= 1;
	tx_src_low <<= 1;
	CSDPval = 0x609;
#endif


	DMA_CCR(chan)     = 0 ;						//ensure DMA channel is reset
	while ((DMA_CCR(chan) & 0x0080) != 0);
	//clear the status bits and re-enable DMA interrupt

	DMA_CSDP(chan)    = CSDPval; 
	DMA_CICR(chan)    = CICRval;
	DMA_CSSAL(chan)   = tx_src_low;
	DMA_CSSAU(chan)   = tx_src_high;
	DMA_CDSAL(chan)   = tx_dst_low;
	DMA_CDSAU(chan)   = tx_dst_high;
	DMA_CEN(chan)     = m_dmaBufferSize;
	DMA_CFN(chan)	  = 2;						//double buffered
	DMA_CFI(chan)	  = 0x0;					//No skip
	DMA_CEI(chan)	  = 0x0;					//No skip

	DMA_CCR(chan)     = CCRval ;
	// }}}USR
}
// }}}RME

// {{{RME operation 'initRxDmaChannel(unsigned int)'
void SsiSlotManager::initRxDmaChannel( unsigned int rxDMATransferPort )
{
	// {{{USR
	//Mcbsp rx register address
	unsigned int sourceAddress = m_baseAddress + DRR1;
	unsigned int chan = m_dmachan + 1;

	unsigned short rx_dst_high=	(unsigned short)(((unsigned long)rxDmaBuffer)>>16);
	unsigned short rx_dst_low=(unsigned short)((unsigned long)(rxDmaBuffer));
	unsigned short rx_src_high = (unsigned short)(((unsigned long)sourceAddress)>>16);
	unsigned short rx_src_low=(unsigned short)((unsigned long)(sourceAddress));

	unsigned int CSDPval = ((rxDMATransferPort & 0xF) << 9) | 0xD;	//reference Table 8.52 (TIPB->port,16bit)
	unsigned int CCRval = 0x4BC0 + m_dmareq + 1;					//reference Table 8.54 (AUTO_INIT,REPEAT,PRIROITY,ENABLE)
	unsigned int CICRval = 0x0009;									//FRAME and TOUT interrupts enabled.

#ifdef OMAP_HALI_C55
	rx_dst_high <<= 1;
	rx_dst_low <<= 1;
	rx_src_high <<= 1;
	rx_src_low <<= 1;
	CSDPval = 0x40D;
#endif


	DMA_CCR(chan)     = 0 ;						//ensure DMA channel is reset
	while ((DMA_CCR(chan) & 0x0080) != 0);
	//clear the status bits and re-enable DMA interrupt

	DMA_CSDP(chan)   = CSDPval;
	DMA_CICR(chan)   = CICRval;
	DMA_CSSAL(chan)  = rx_src_low;
	DMA_CSSAU(chan)  = rx_src_high;
	DMA_CDSAL(chan)  = rx_dst_low;
	DMA_CDSAU(chan)  = rx_dst_high;
	DMA_CEN(chan)    = m_dmaBufferSize;
	DMA_CFN(chan)	 = 2;						//double buffered
	DMA_CFI(chan)	 = 0x0;						//No skip
	DMA_CEI(chan)	 = 0x0;						//No skip

	DMA_CCR(chan)    = CCRval;
	// }}}USR
}
// }}}RME

// {{{RME operation '~SsiSlotManager()'
SsiSlotManager::~SsiSlotManager( void )
{
	// {{{USR
	unregisterListener(this,EVENT_ISR_BUFFER_FULL);

	delete m_managerConfig;
	m_managerConfig=0;
	peripheral_address_short baseAddress = (peripheral_address_short)m_baseAddress;	//Use local to allow compiler optimization

	//Reset mcbsp peripheral

	// Reset Receiver
	setBitField(baseAddress, RRST, 0);

	// Reset Transmitter
	setBitField(baseAddress, XRST, 0);

	// Reset frame synchronization logic
	setBitField(baseAddress, FRST, 0);

	//destroy the DMA buffers if locally allocated.
	if (rxDmaLocal) delete [] rxDmaBuffer;
	if (txDmaLocal) delete [] txDmaBuffer;
	// }}}USR
}
// }}}RME

// {{{RME operation 'eventOccurred(const EventBase * const)'
void SsiSlotManager::eventOccurred( const EventBase * const event )
{
	// {{{USR
	//Setup local rx and tx buffer pointers (note, the opposite buffer is used, if DMA is on LOWER, use UPPER here)
	uint16_t *l_txDmaBuffer = txDmaBuffer + (!m_lowerHalf?0:m_dmaBufferSize);
	uint16_t *l_rxDmaBuffer = rxDmaBuffer + (!m_lowerHalf?0:m_dmaBufferSize);

	unsigned int frames = m_dmaNumFrames;
	unsigned int slots = m_slotsPerFrame;
	int count = slots;
	OmapSsiCommon **slotConnArray = m_ssiConnectionArray;

	//iterrate for all slots
	while (count-- > 0)
	{
		if (*slotConnArray != 0)
		{
			(*slotConnArray)->transferData(l_txDmaBuffer,l_rxDmaBuffer,slots,frames);
		}
		slotConnArray++;
		l_txDmaBuffer++;
		l_rxDmaBuffer++;
	}

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Config' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
