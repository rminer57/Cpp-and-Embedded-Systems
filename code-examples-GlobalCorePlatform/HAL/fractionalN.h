// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::lvfractn::fractionalN'

#ifndef fractionalN_H
#define fractionalN_H

#ifdef PRAGMA
#pragma interface "fractionalN.h"
#endif

#include <HALtestLib_win32.h>
#include <discreteDeviceControl.h>
#include <generalPurposeOutputManager.h>
#include <modulationBalanceAttenuator.h>
#include <modulator.h>
#include <rf_audio_std_types.h>
#include <synthesizer.h>
#include <synthesizerAdjust.h>
class bitfield;
class dataPoint;
class fractionalNDefault;
class generalPurposeOutput;
class prescalerData;
class rfSpiBuffer;
class units;
class utility;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#define FRACTN_IMAGE_SIZE         4   // uint32_t's
#define NUM_OF_REF_FREQS          4
#define NUM_OF_FRACTN_GPOS        4

//
// Enumerated type defining the possible PHASE_DETECTOR_CURRENT_SELECT SPI register options
//
	enum phaseDetectorCurrentSelect_t
	{
	    PBIAS1 		= 0
	  , PBIAS2 		= 1
	  , REF_50uA	= 2
	  , PHASE_OFF 	= 3
	};

// }}}USR
// }}}RME
// {{{RME classifier 'fractnRfMode_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'supportedRefFreqs_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class fractionalN : public generalPurposeOutputManager, public synthesizerAdjust, public synthesizer, public modulator, public modulationBalanceAttenuator, public discreteDeviceControl
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
	// {{{RME classifier 'fractnRfMode_t'
	enum fractnRfMode_t
	{
		FRACTN_RF_MODE_RX = 0
	  , FRACTN_RF_MODE_TX
	};
	// }}}RME
	// {{{RME classifier 'supportedRefFreqs_t'
	enum supportedRefFreqs_t
	{
		REFERENCE_2_1_MHZ = 0
	  , REFERENCE_2_4_MHZ
	  , REFERENCE_2_225_MHZ
	  , REFERENCE_16_8_MHZ
	};
	// }}}RME
	// {{{RME classAttribute 'defaultData'
	fractionalNDefault * defaultData;
	// }}}RME
	// {{{RME classAttribute 'error'
	Integer * error;
	// }}}RME
	// {{{RME classAttribute 'prescaler'
	prescalerData * prescaler;
	// }}}RME
	// {{{RME classAttribute 'spi'
	rfSpiBuffer * * spi;
	// }}}RME
	// {{{RME classAttribute 'prescalerDataTbl'
	dataPoint * * prescalerDataTbl;
	// }}}RME
	// {{{RME classAttribute 'PRESCALER_DATA_SIZE'
	static const Integer PRESCALER_DATA_SIZE;
	// }}}RME

public:
	// {{{RME operation 'commitGPO(Integer,Integer)'
	void commitGPO( Integer portNumber, Integer rfState );
	// }}}RME
	// {{{RME operation 'fractionalN(fractionalNDefault*,rfSpiBuffer**,Integer)'
	fractionalN( fractionalNDefault * init, rfSpiBuffer * * spiBuffers, Integer numOfRfStates );
	// }}}RME
	// {{{RME operation 'getError(Integer)'
	Integer getError( Integer rfState );
	// }}}RME

private:
	// {{{RME operation 'setFreqParams(Integer,Integer,Integer,Integer)'
	void setFreqParams( Integer frequency, Integer refFreq, Integer resolution, Integer rfState );
	// }}}RME

public:
	// {{{RME operation 'setSynthFrequency(Integer,Integer,Integer,Integer)'
	Integer setSynthFrequency( Integer freq, Integer rfState, Integer res, Integer fref );
	// }}}RME
	// {{{RME operation 'setGPO(Integer,Integer,Integer)'
	void setGPO( Integer portNumber, Integer outputState, Integer rfState );
	// }}}RME
	// {{{RME operation 'setModBalance(Integer,Integer)'
	Integer setModBalance( Integer attenuation, Integer rfState );
	// }}}RME
	// {{{RME operation 'setModSensitivity(Integer,Integer)'
	Integer setModSensitivity( Integer dev, Integer rfState );
	// }}}RME
	// {{{RME operation 'setRFState(Integer)'
	Integer setRFState( Integer rfState );
	// }}}RME
	// {{{RME operation 'setWarp(Integer,Integer)'
	Integer setWarp( Integer warp, Integer rfState );
	// }}}RME
	// {{{RME operation '~fractionalN()'
	~fractionalN( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'fractnRfMode_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'supportedRefFreqs_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* fractionalN_H */

// }}}RME
