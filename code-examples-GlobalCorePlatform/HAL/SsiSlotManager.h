// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OMAP::Ssi::OmapSsiIOVirtualSerial::SsiSlotManager'

#ifndef SsiSlotManager_H
#define SsiSlotManager_H

#ifdef PRAGMA
#pragma interface "SsiSlotManager.h"
#endif

#include <serial_comp.h>
#include <EventBase.h>
#include <IrqHandler.h>
#include <ListenerBase.h>
#include <NotifierBase.h>
class HALiNucleusNotifier;
class IOVirtualSerial;
class McBsp;
class OmapAsyncSsiIOVirtualSerial;
class OmapRawSsiIOVirtualSerial;
class OmapSsiCommon;
class bitfield;
class peripheral_access;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Config' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class SsiSlotManager : public IrqHandler, public ListenerBase, public NotifierBase
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

protected:
	// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

private:
	// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

public:
	// {{{RME classifier 'Config'
	class Config
	{
	public:
		// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
		// {{{USR

		// }}}USR
		// }}}RME

	protected:
		// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
		// {{{USR

		// }}}USR
		// }}}RME

	private:
		// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
		// {{{USR

		// }}}USR
		// }}}RME

	public:
		// {{{RME classAttribute 'm_ssiMaster'
		bool m_ssiMaster;
		// }}}RME
		// {{{RME classAttribute 'm_mcbspUnit'
		unsigned int m_mcbspUnit;
		// }}}RME
		// {{{RME classAttribute 'm_slotsPerFrame'
		unsigned int m_slotsPerFrame;
		// }}}RME
		// {{{RME classAttribute 'm_frameFrequency'
		unsigned int m_frameFrequency;
		// }}}RME
		// {{{RME classAttribute 'm_mcbspInputClockFrequency'
		unsigned int m_mcbspInputClockFrequency;
		// }}}RME
		// {{{RME classAttribute 'm_maxReceiveBufferSize'
		unsigned int m_maxReceiveBufferSize;
		// }}}RME
		// {{{RME operation 'Config(bool,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int)'
		Config( bool mode = false, unsigned int unit = 2, unsigned int slots = 4, unsigned int frameFrequency = 0, unsigned int mcbspInputClockFrequency = 0, unsigned int maxReceiveBufferSize = 1024 );
		// }}}RME
	};
	// }}}RME

private:
	// {{{RME classAttribute 'm_slotMask'
	unsigned int m_slotMask;
	// }}}RME
	// {{{RME classAttribute 'm_baseAddressArray'
	static unsigned short * const m_baseAddressArray[];
	// }}}RME
	// {{{RME classAttribute 'm_baseAddress'
	unsigned int m_baseAddress;
	// }}}RME
	// {{{RME classAttribute 'm_serialWordSize'
	unsigned int m_serialWordSize;
	// }}}RME

public:
	// {{{RME classAttribute 'm_managerConfig'
	Config * m_managerConfig;
	// }}}RME
	// {{{RME classAttribute 'm_mcBspIrqArray'
	static const unsigned int m_mcBspIrqArray[][ 3 ];
	// }}}RME

private:
	// {{{RME classAttribute 'm_slotsPerFrame'
	unsigned int m_slotsPerFrame;
	// }}}RME
	// {{{RME classAttribute 'm_lowerHalf'
	bool m_lowerHalf;
	// }}}RME
	// {{{RME classAttribute 'txDmaBuffer'
	uint16_t * txDmaBuffer;
	// }}}RME
	// {{{RME classAttribute 'rxDmaBuffer'
	uint16_t * rxDmaBuffer;
	// }}}RME
	// {{{RME classAttribute 'm_resync'
	bool m_resync;
	// }}}RME
	// {{{RME classAttribute 'IDLE_HIGH'
	static const unsigned short int IDLE_HIGH;
	// }}}RME
	// {{{RME classAttribute 'IDLE_LOW'
	static const unsigned short int IDLE_LOW;
	// }}}RME
	// {{{RME classAttribute 'm_irq'
	unsigned int m_irq;
	// }}}RME
	// {{{RME classAttribute 'm_dmachan'
	unsigned int m_dmachan;
	// }}}RME
	// {{{RME classAttribute 'm_dmaBufferSize'
	unsigned int m_dmaBufferSize;
	// }}}RME
	// {{{RME classAttribute 'm_dmaNumFrames'
	unsigned int m_dmaNumFrames;
	// }}}RME
	// {{{RME classAttribute 'm_dmareq'
	unsigned int m_dmareq;
	// }}}RME
	// {{{RME classAttribute 'EVENT_ISR_BUFFER_FULL'
	static const unsigned int EVENT_ISR_BUFFER_FULL;
	// }}}RME
	// {{{RME classAttribute 'rxDmaLocal'
	bool rxDmaLocal;
	// }}}RME
	// {{{RME classAttribute 'txDmaLocal'
	bool txDmaLocal;
	// }}}RME

public:
	// {{{RME associationEnd 'm_ssiConnectionArray'
	OmapSsiCommon * m_ssiConnectionArray[ 32 ];
	// }}}RME
	// {{{RME associationEnd 'm_autoEvent'
	EventBase m_autoEvent;
	// }}}RME
	// {{{RME operation 'SsiSlotManager(SsiSlotManager::Config*,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,uint16_t*,uint16_t*,unsigned int,unsigned int)'
	SsiSlotManager( Config * cfg, unsigned int baseAddr, unsigned int irq, unsigned int dmachan, unsigned int dmareq, unsigned int dmaBufferFrames = 0, uint16_t * tx_DmaBuffer = 0, uint16_t * rx_DmaBuffer = 0, unsigned int rxDMATransferDestinationPort = 0, unsigned int txDMATransferDestinationPort = 0 );
	// }}}RME
	// {{{RME operation 'getIOVirtualSerial(unsigned int,bool,bool)'
	IOVirtualSerial * getIOVirtualSerial( unsigned int slotRequest, bool asyncMode, bool transmitOnly );
	// }}}RME
	// {{{RME operation 'unRegisterSlots(OmapSsiCommon*)'
	void unRegisterSlots( OmapSsiCommon * omapSsiCon );
	// }}}RME
	// {{{RME operation 'handler()'
	virtual void handler( void );
	// }}}RME
	// {{{RME operation 'initTxDmaChannel(unsigned int)'
	void initTxDmaChannel( unsigned int txDMATransferPort );
	// }}}RME
	// {{{RME operation 'initRxDmaChannel(unsigned int)'
	void initRxDmaChannel( unsigned int rxDMATransferPort );
	// }}}RME
	// {{{RME operation '~SsiSlotManager()'
	~SsiSlotManager( void );
	// }}}RME
	// {{{RME operation 'eventOccurred(const EventBase * const)'
	virtual void eventOccurred( const EventBase * const event );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Config' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* SsiSlotManager_H */

// }}}RME
