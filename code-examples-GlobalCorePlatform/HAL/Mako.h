// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::Mako'

#ifndef Mako_H
#define Mako_H

#ifdef PRAGMA
#pragma interface "Mako.h"
#endif

#include <HALtestLib_win32.h>
class Connection;
class Mako1WireCtrl;
class MakoADC;
class MakoAudioInputCtrl;
class MakoAudioOutputCtrl;
class MakoDCPwrCtrl;
class MakoFrontEndFilter;
class MakoIGNSenseCtrl;
class MakoIntrCtrl;
class MakoOPTCTRL;
class MakoPrivateBitfieldsReg2;
class MakoPrivateBitfieldsReg3;
class MakoPrivateBitfieldsReg6;
class MakoRFPA;
class MakoRFPowerControl;
class MakoUSBCtrl;
class MakoWatchdogCtrl;
class PowerConfiguration;
class SIntArray;
class rfSpiBuffer;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>

// size of the SIntArray in 16 bit words, required to allocate
// space for one Mako register.  Mako registers are 32 bits wide
// and the SIntArray object contains an array of 16 bit integers.
// SIntArray is the container used to pass data to the IOVirtualSerial
// send method.  Used by the Mako driver to send register data
// onto the spi bus to the Mako IC.
#define MAKO_SINTARRAY_ALLOCATION_SIZE 2
#define NUMBER_OF_DACS 3
#define NUMBER_OF_ADCS 11      // 11 channels ATOD_0 - ATOD_8,ADC, VREF, VMES
// }}}USR
// }}}RME

class Mako
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR
	friend class MakoFrontEndFilter;
	friend class MakoRFPA;
	friend class MakoRFPowerControl;
	friend class MakoADC;
	friend class MakoOPTCTRL;
	friend class MakoAudioOutputCtrl;
	friend class MakoAudioInputCtrl;
	friend class MakoDCPwrCtrl;
	friend class MakoIGNSenseCtrl;
	friend class Mako1WireCtrl;
	friend class MakoIntrCtrl; 
	friend class MakoWatchdogCtrl;
	friend class MakoUSBCtrl;

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
	// {{{RME classAttribute 'MAKO_DAC_1'
	static const unsigned int MAKO_DAC_1;
	// }}}RME
	// {{{RME classAttribute 'MAKO_DAC_2'
	static const unsigned int MAKO_DAC_2;
	// }}}RME
	// {{{RME classAttribute 'MAKO_DAC_3'
	static const unsigned int MAKO_DAC_3;
	// }}}RME
	// {{{RME classAttribute 'LUT_SIZE'
	static const unsigned int LUT_SIZE;
	// }}}RME
	// {{{RME classAttribute 'DAC_POWER_DOWN'
	static const unsigned int DAC_POWER_DOWN;
	// }}}RME

private:
	// {{{RME classAttribute 'm_numDACBuffers'
	int m_numDACBuffers;
	// }}}RME
	// {{{RME classAttribute 'm_dacAvailable'
	bool m_dacAvailable[ NUMBER_OF_DACS ];
	// }}}RME
	// {{{RME classAttribute 'm_adcAvailable'
	bool m_adcAvailable[ NUMBER_OF_ADCS ];
	// }}}RME

public:
	// {{{RME classAttribute 'm_error'
	int m_error;
	// }}}RME
	// {{{RME classAttribute 'MAKO_NO_ERROR'
	static const unsigned int MAKO_NO_ERROR;
	// }}}RME
	// {{{RME classAttribute 'MAKO_ALLOCATION_ERROR_ADC'
	static const unsigned int MAKO_ALLOCATION_ERROR_ADC;
	// }}}RME
	// {{{RME classAttribute 'MAKO_ADC_CH_RANGE_ERROR'
	static const unsigned int MAKO_ADC_CH_RANGE_ERROR;
	// }}}RME

private:
	// {{{RME classAttribute 'm_ResourceAvailableOPT'
	bool m_ResourceAvailableOPT;
	// }}}RME

public:
	// {{{RME classAttribute 'MAKO_ALLOCATION_ERROR_OPTCTRL'
	static const unsigned int MAKO_ALLOCATION_ERROR_OPTCTRL;
	// }}}RME

private:
	// {{{RME classAttribute 'm_ResourceAvailableAudioOutput'
	bool m_ResourceAvailableAudioOutput;
	// }}}RME
	// {{{RME classAttribute 'm_ResourceAvailableAudioInput'
	bool m_ResourceAvailableAudioInput;
	// }}}RME

protected:
	// {{{RME classAttribute 'm_imageArrayAudioReg'
	uint32_t * m_imageArrayAudioReg;
	// }}}RME

public:
	// {{{RME classAttribute 'MAKO_ALLOCATION_ERROR_AUDIO_SPKR'
	static const unsigned int MAKO_ALLOCATION_ERROR_AUDIO_SPKR;
	// }}}RME
	// {{{RME classAttribute 'MAKO_ALLOCATION_ERROR_AUDIO_MIC'
	static const unsigned int MAKO_ALLOCATION_ERROR_AUDIO_MIC;
	// }}}RME
	// {{{RME classAttribute 'MAKO_ALLOCATION_ERROR_DCPWR'
	static const unsigned int MAKO_ALLOCATION_ERROR_DCPWR;
	// }}}RME
	// {{{RME classAttribute 'MAKO_ALLOCATION_ERROR_IGNSENSE'
	static const unsigned int MAKO_ALLOCATION_ERROR_IGNSENSE;
	// }}}RME
	// {{{RME classAttribute 'MAKO_ALLOCATION_ERROR_1WIRECTRL'
	static const unsigned int MAKO_ALLOCATION_ERROR_1WIRECTRL;
	// }}}RME
	// {{{RME classAttribute 'MAKO_ALLOCATION_ERROR_INTRCTRL'
	static const unsigned int MAKO_ALLOCATION_ERROR_INTRCTRL;
	// }}}RME

private:
	// {{{RME classAttribute 'm_ResourceAvailableDCPwrCtrl'
	bool m_ResourceAvailableDCPwrCtrl;
	// }}}RME
	// {{{RME classAttribute 'm_ResourceAvailableIGNSenseCtrl'
	bool m_ResourceAvailableIGNSenseCtrl;
	// }}}RME
	// {{{RME classAttribute 'm_ResourceAvailable1Wire'
	bool m_ResourceAvailable1Wire;
	// }}}RME
	// {{{RME classAttribute 'm_ResourceAvailableIntrCtrl'
	bool m_ResourceAvailableIntrCtrl;
	// }}}RME
	// {{{RME classAttribute 'm_ResourceAvailableWatchdogCtrl'
	bool m_ResourceAvailableWatchdogCtrl;
	// }}}RME

public:
	// {{{RME classAttribute 'MAKO_ALLOCATION_ERROR_WATCHDOG'
	static const unsigned int MAKO_ALLOCATION_ERROR_WATCHDOG;
	// }}}RME

protected:
	// {{{RME classAttribute 'm_imageDCRegulatorReg'
	uint32_t m_imageDCRegulatorReg;
	// }}}RME
	// {{{RME classAttribute 'm_imageArrayIDCtrlReg'
	uint32_t * m_imageArrayIDCtrlReg;
	// }}}RME

private:
	// {{{RME classAttribute 'm_ResourceAvailableUsb'
	bool m_ResourceAvailableUsb;
	// }}}RME
	// {{{RME classAttribute 'MAKO_ALLOCATION_ERROR_USB'
	unsigned int MAKO_ALLOCATION_ERROR_USB;
	// }}}RME

protected:
	// {{{RME classAttribute 'm_MakoICVersion'
	int m_MakoICVersion;
	// }}}RME

private:
	// {{{RME associationEnd 'm_dacCommonBuffers'
	rfSpiBuffer ** m_dacCommonBuffers;
	// }}}RME

public:
	// {{{RME associationEnd 'm_connection'
	Connection * m_connection;
	// }}}RME
	// {{{RME operation 'getNumDACBuffers()'
	virtual unsigned int getNumDACBuffers( void ) const;
	// }}}RME

protected:
	// {{{RME operation 'getDAC(unsigned int)'
	virtual bool getDAC( unsigned int dacSelect );
	// }}}RME

public:
	// {{{RME operation 'getFrontEndFilter(unsigned int,uint32_t *,unsigned int)'
	virtual MakoFrontEndFilter * getFrontEndFilter( unsigned int dacSelect, uint32_t * dacData, unsigned int numRFStates );
	// }}}RME
	// {{{RME operation 'getRFPA(unsigned int,uint32_t *,unsigned int)'
	virtual MakoRFPA * getRFPA( unsigned int dacSelect, uint32_t * dacData, unsigned int numRFStates );
	// }}}RME
	// {{{RME operation 'getRFPowerControl(unsigned int,PowerConfiguration**,rfSpiBuffer*,unsigned int)'
	virtual MakoRFPowerControl * getRFPowerControl( unsigned int dacSelect, PowerConfiguration * * dacConfig, rfSpiBuffer * dac3Buffer, unsigned int numRFStates );
	// }}}RME
	// {{{RME operation 'Mako(rfSpiBuffer**,unsigned int,Connection *)'
	Mako( rfSpiBuffer * * dacBuffers, unsigned int numDACBuffers, Connection * connection = 0 );
	// }}}RME
	// {{{RME operation 'getOPT(uint32_t,uint32_t,uint32_t)'
	virtual MakoOPTCTRL * getOPT( uint32_t opt1init = 0, uint32_t opt2init = 0, uint32_t opt3init = 0 );
	// }}}RME
	// {{{RME operation 'wrRegister(unsigned int,uint32_t)'
	void wrRegister( unsigned int mako_reg_addr, uint32_t reg_data );
	// }}}RME
	// {{{RME operation 'rdRegister(unsigned int,uint32_t)'
	uint32_t rdRegister( unsigned int mako_reg_addr, uint32_t reg_data );
	// }}}RME
	// {{{RME operation 'getIGNSenseCtrl(uint32_t)'
	virtual MakoIGNSenseCtrl * getIGNSenseCtrl( uint32_t ignmode = 0 );
	// }}}RME
	// {{{RME operation 'getAudioInputCtrl(uint32_t,uint32_t,uint32_t)'
	MakoAudioInputCtrl * getAudioInputCtrl( uint32_t sreg123, uint32_t sreg45, uint32_t sregPA );
	// }}}RME
	// {{{RME operation 'getAudioOutputCtrl(uint32_t,uint32_t,uint32_t)'
	MakoAudioOutputCtrl * getAudioOutputCtrl( uint32_t sreg123, uint32_t sreg45, uint32_t sregPA );
	// }}}RME
	// {{{RME operation 'syncAudio()'
	void syncAudio( void );
	// }}}RME
	// {{{RME operation '~Mako()'
	~Mako( void );
	// }}}RME
	// {{{RME operation 'getADC(unsigned int,uint32_t)'
	virtual MakoADC * getADC( unsigned int adcSelect, uint32_t adcConfig = 0 );
	// }}}RME
	// {{{RME operation 'getIntrCtrl(uint32_t)'
	virtual MakoIntrCtrl * getIntrCtrl( uint32_t reginit );
	// }}}RME
	// {{{RME operation 'getDCPwrCtrl(uint32_t)'
	virtual MakoDCPwrCtrl * getDCPwrCtrl( uint32_t reginit = 0 );
	// }}}RME
	// {{{RME operation 'getWatchdogCtrl()'
	virtual MakoWatchdogCtrl * getWatchdogCtrl( void );
	// }}}RME
	// {{{RME operation 'getMakoID()'
	uint32_t getMakoID( void );
	// }}}RME
	// {{{RME operation 'get1WireCtrl()'
	virtual Mako1WireCtrl * get1WireCtrl( void );
	// }}}RME
	// {{{RME operation 'getUSB(uint32_t,uint32_t)'
	MakoUSBCtrl * getUSB( uint32_t usb1_int_en = 0, uint32_t usb2_int_en = 0 );
	// }}}RME
	// {{{RME operation 'getICVersion()'
	int getICVersion( void );
	// }}}RME
	// {{{RME operation 'setICVersion(unsigned int)'
	void setICVersion( unsigned int version );
	// }}}RME

protected:
	// {{{RME operation 'endianSwap32(uint32_t)'
	static uint32_t endianSwap32( uint32_t data32 );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Mako_H */

// }}}RME
