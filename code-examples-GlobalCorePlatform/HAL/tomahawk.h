// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::tomahawk::tomahawk'

#ifndef tomahawk_H
#define tomahawk_H

#ifdef PRAGMA
#pragma interface "tomahawk.h"
#endif

#include <HALtestLib_win32.h>
#include <bbpControl.h>
#include <bitfield.h>
#include <dataPoint.h>
#include <discreteDeviceControl.h>
#include <gainControl.h>
#include <generalPurposeOutput.h>
#include <generalPurposeOutputManager.h>
#include <interpolationData.h>
#include <rfSpiBuffer.h>
#include <rf_audio_std_types.h>
#include <synthesizer.h>
#include <tomahawkDefault.h>
#include <units.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h> 

// BYTE size  of the Tomahawk (version 2) SPI image, 1 byte address header + 128 registers
#define TOMAHAWK_IMAGE_SIZE_BYTES     129
#define TOMAHAWK_IMAGE_SIZE_UINT32     33

// Number of partial SPI image snippets
#define NUM_TOMAHAWK_SNIPPETS	((TOMAHAWK_IMAGE_SIZE_BYTES/TOMAHAWK_SNIPPET_SIZE) + 1)

// Size in bytes of the Tomahawk SPI buffe Header
#define	TOMAHWK_SPI_HEADER_SIZE	1

// Tomahawk SPI mode options
#define TOMAHAWK_SPI_MODE_WRITE 0
#define TOMAHAWK_SPI_MODE_ACE1 1
#define TOMAHAWK_SPI_MODE_ACE2 2
#define TOMAHAWK_SPI_MODE_READ 3



// Crystal Oscillator Frequency     (TBD - is there a global hardware define somewhere else???????)
#define CO_FREQ				1680

// Define discrete setting values
#define ENABLE	1
#define DISABLE	0


// Element size of the BW baseband table
#define BW_DATA_SIZE			64


//
// Data structure defining the status variables for managing partial SPI transmissions
//
struct SnippetStatus_s {
	bool	modified;
	bool	reset;
};

typedef SnippetStatus_s SnippetStatus_t[NUM_TOMAHAWK_SNIPPETS];


// Macro that checks boundary conditions of the specified variable.
// Sets input value beyond defined min/max to the specified default value. 
#define checkBounds(min, max, value, default)  \
	((((value < min) ? default:value) > max) ? default:value)

//
// Enumerated type defining the possible SSI_MODE SPI register options
//
	enum regSsiModeEnum_t
	{
	    SSI_MODE_IDEN = 0
	  , SSI_MODE_TETRA = 1
	  , SSI_MODE_CGISS = 2
	  , SSI_MODE_SAM_50 = 3
	  , SSI_MODE_SAM_100 = 4
	  , SSI_MODE_SAM_150 = 5
	  , SSI_MODE_IDEN_CEFM_24 = 6
	  , SSI_MODE_IDEN_CEFM_48 = 7
	  , SSI_MODE_SAM_50_CEFM = 8
	  , SSI_MODE_SAM_100_CEFM = 9 
	  , SSI_MODE_SAM_150_CEFM = 10
	};

//
// Enumerated type defining the possible ES_SEL2 SPI register options
//
	enum regEsSel2Enum_t
	{
	    ES_SEL2_REFIN = 0
	  , ES_SEL2_VCOIN = 1
	};

//
// Enumerated type defining the possible AGC_DAC_MODE SPI register options
//
	enum regAgcDacModeEnum_t
	{
	    AGC_DAC_MODE_INCREASE = 0
	  , AGC_DAC_MODE_DECREASE = 1
	};
// }}}USR
// }}}RME
// {{{RME classifier 'tomahawkDiscreteRegEnum_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'tomahawkGainRegEnum_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'tomahawkGpoRegEnum_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class tomahawk : public discreteDeviceControl, public generalPurposeOutputManager, public gainControl, public bbpControl, public synthesizer
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

protected:
	// {{{RME classifier 'tomahawkDiscreteRegEnum_t'
	enum tomahawkDiscreteRegEnum_t
	{
		DISC_WFG_REF = 0
	  , DISC_STEP_THRESH
	  , DISC_SEQMGR_EN
	  , DISC_AGCFLAGEN
	  , DISC_FBC_TMR
	  , DISC_MREF_DIV
	  , DISC_MACC
	  , DISC_CLK_R
	  , DISC_BUFGAIN
	  , DISC_RX_BS
	  , DISC_AUX_DAC
	  , DISC_ADAPTEN
	  , DISC_FAST_AGC
	  , DISC_RF_STEP
	  , DISC_SSI_MODE
	  , DISC_BSAVE_MAIN_SYN
	  , DISC_BSAVE_SYN_ALL
	  , DISC_SYN_ADAPTEN
	  , DISC_NUD
	  , DISC_ES_SEL2
	  , DISC_BSAVE_ESCORT
	  , DISC_BSAVE_TX
	  , DISC_ATTEN_Q
	  , DISC_ATTEN_I
	  , DISC_EF_DC_UPDATE
	  , DISC_BSAVE_TXR
	  , DISC_A2_ENV
	  , DISC_RX_EVENT2
	  , DISC_RX_EVENT1
	  , DISC_BSAVE_EF
	  , DISC_HP_SEL
	  , DISC_AGC_DAC_MODE
	  , DISC_AGC_DAC_VREF
	  , NUM_TOMAHAWK_DISCRETES
	};
	// }}}RME
	// {{{RME classifier 'tomahawkGainRegEnum_t'
	enum tomahawkGainRegEnum_t
	{
		GAIN_AMP_AGC
	  , GAIN_BUFGAIN
	  , GAIN_STATT_IQ
	  , NUM_TOMAHAWK_GAINS
	};
	// }}}RME
	// {{{RME classifier 'tomahawkGpoRegEnum_t'
	enum tomahawkGpoRegEnum_t
	{
		GPO_GPO1 = 0
	  , GPO_GPO2
	  , GPO_GPO3
	  , GPO_GPO4
	  , GPO_GPO5
	  , GPO_GPO6
	  , NUM_TOMAHAWK_GPOS
	};
	// }}}RME

public:
	// {{{RME classAttribute 'spi'
	rfSpiBuffer * * spi;
	// }}}RME
	// {{{RME classAttribute 'defaultData'
	tomahawkDefault * defaultData;
	// }}}RME

private:
	// {{{RME classAttribute 'error'
	int * error;
	// }}}RME
	// {{{RME classAttribute 'bwBB'
	interpolationData * bwBB;
	// }}}RME
	// {{{RME classAttribute 'bwDataTbl'
	dataPoint * * bwDataTbl;
	// }}}RME

public:
	// {{{RME classAttribute 'ModifiedImage'
	bool * ModifiedImage;
	// }}}RME
	// {{{RME classAttribute 'ResetImage'
	bool * ResetImage;
	// }}}RME
	// {{{RME classAttribute 'LastSyncState'
	int LastSyncState;
	// }}}RME
	// {{{RME classAttribute 'SnippetStatus'
	SnippetStatus_t * SnippetStatus;
	// }}}RME

private:
	// {{{RME classAttribute 'SnippetSpiIndex'
	int SnippetSpiIndex;
	// }}}RME

public:
	// {{{RME operation 'tomahawk(tomahawkDefault*,rfSpiBuffer**,int,int,int,int)'
	tomahawk( tomahawkDefault * init, rfSpiBuffer * * spiBuffers, int numberOfRfStates, int numberOfDiscretes, int numberOfGPOs, int numberOfGains );
	// }}}RME
	// {{{RME operation 'tomahawk(tomahawkDefault*,rfSpiBuffer**,int)'
	tomahawk( tomahawkDefault * init, rfSpiBuffer * * spiBuffers, int numberOfRfStates );
	// }}}RME

private:
	// {{{RME operation 'cmnTomahawkConstructor(tomahawkDefault*,rfSpiBuffer**,int)'
	void cmnTomahawkConstructor( tomahawkDefault * init, rfSpiBuffer * * spiBuffers, int numberOfRfStates );
	// }}}RME

public:
	// {{{RME operation '~tomahawk()'
	~tomahawk( void );
	// }}}RME
	// {{{RME operation 'setRFState(int32_t)'
	int32_t setRFState( int32_t rfState );
	// }}}RME
	// {{{RME operation 'setGPO(int16_t,int16_t,int16_t)'
	void setGPO( int16_t portNumber, int16_t outputState, int16_t rfState );
	// }}}RME
	// {{{RME operation 'setDeviceState(int,int,int)'
	int setDeviceState( int setting, int deviceId, int rfState );
	// }}}RME
	// {{{RME operation 'setGain(int,int,int)'
	virtual int setGain( int gainNumber, int gain, int rfState );
	// }}}RME
	// {{{RME operation 'setBBPFrequency(int,int)'
	int setBBPFrequency( int frequency, int rfState );
	// }}}RME
	// {{{RME operation 'setSynthFrequency(int32_t,int16_t,int32_t,int32_t)'
	int32_t setSynthFrequency( int32_t freq, int16_t rfState, int32_t res, int32_t fref );
	// }}}RME
	// {{{RME operation 'setFreqParams(int32_t,int32_t,int32_t,int16_t)'
	void setFreqParams( int32_t synthFrequency, int32_t refFrequency, int32_t resolution, int16_t rfState );
	// }}}RME
	// {{{RME operation 'LogSnippetMod(int,int)'
	void LogSnippetMod( int RfState, int SnippetID );
	// }}}RME
	// {{{RME operation 'ResetRFState(int)'
	void ResetRFState( int rfState );
	// }}}RME
	// {{{RME operation 'commitGPO(Integer,Integer)'
	void commitGPO( Integer portNumber, Integer rfState );
	// }}}RME
	// {{{RME operation 'writeImage(int,int,int)'
	void writeImage( int rfState, int deviceId, int setting );
	// }}}RME
	// {{{RME operation 'wrRegister(uint16_t,uint16_t,int)'
	void wrRegister( uint16_t addr, uint16_t data, int rfState = 0 );
	// }}}RME
	// {{{RME operation 'ResetCompImage(int)'
	void ResetCompImage( int rfState );
	// }}}RME
	// {{{RME operation 'readImage(int,int)'
	int32_t readImage( int deviceId, int rfState = 0 );
	// }}}RME
	// {{{RME operation 'rdRegister(uint16_t,int)'
	uint16_t rdRegister( uint16_t addr, int rfState = 0 );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'tomahawkDiscreteRegEnum_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'tomahawkGainRegEnum_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'tomahawkGpoRegEnum_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* tomahawk_H */

// }}}RME
