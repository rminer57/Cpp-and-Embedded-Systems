// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::lvfractn::fractionalN'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "fractionalN.h"
#endif

#include <HALtestLib_win32.h>
#include <fractionalN.h>
#include <bitfield.h>
#include <dataPoint.h>
#include <fractionalNDefault.h>
#include <generalPurposeOutput.h>
#include <prescalerData.h>
#include <rfSpiBuffer.h>
#include <units.h>
#include <utility.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
// The following are the bitfield definitions for the FRACTN image 
// defined by: name, type, offset, start bit, and length
// UINT 0
// BYTE 0
// SPI IC ID
// BYTE 1 
defineBitFieldRev(REF_OSC_WARP,uint32_t,0,8,8);
// BYTE 2
defineBitFieldRev(MOD_ATTEN_ENABLE,uint32_t,0,16,1);
defineBitFieldRev(VMULT_ENABLE,uint32_t,0,17,1);
defineBitFieldRev(AUX3_ENABLE,uint32_t,0,18,1);
defineBitFieldRev(MOD_MODE_SELECT,uint32_t,0,19,2);
defineBitFieldRev(BAND_SELECT,uint32_t,0,21,3);
// BYTE 3
defineBitFieldRev(LOOP_DIV_BY_PASS,uint32_t,0,24,1);
defineBitFieldRev(FN_ACCUM_ENABLE,uint32_t,0,25,2);
defineBitFieldRev(A_DIVIDER_MODULUS,uint32_t,0,27,5);
// UINT 1
// BYTE 4
defineBitFieldRev(B_DIVIDER_MODULUS,uint32_t,4,0,4);
defineBitFieldRev(TEST_OUTPUT_ENABLE,uint32_t,4,4,1);
defineBitFieldRev(TEST_OUTPUT_MODE,uint32_t,4,5,2);
defineBitFieldRev(TEST_ENABLE,uint32_t,4,7,1);
// BYTE 5
defineBitFieldRev(REFERENCE_DIVIDER,uint32_t,4,8,4);
defineBitFieldRev(ADAPT_TIMER,uint32_t,4,12,4);
// BYTE 6
defineBitFieldRev(PHASE_DET_CURRENT_SELECT,uint32_t,4,16,3);
defineBitFieldRev(MULT_BUF_SELECT,uint32_t,4,19,1);
defineBitFieldRev(ADDITIONAL_REF_DIV_MODE_SELECT,uint32_t,4,20,1);
// BYTE 7 
defineBitFieldRev(FRACTIONAL_NUMERATOR,uint32_t,4,21,10); 
defineBitFieldRev(INFLECT_RNG_EN,uint32_t,4,31,1);
// UINT 2
// BYTE 8
defineBitFieldRev(INFLECT_LSB,uint32_t,8,0,1); 
defineBitFieldRev(AUX1,uint32_t,8,1,1);
defineBitFieldRev(AUX2,uint32_t,8,2,1);
defineBitFieldRev(AUX3,uint32_t,8,3,1);
defineBitFieldRev(AUX4,uint32_t,8,4,1);
defineBitFieldRev(WARP_LSB,uint32_t,8,5,1);
// BYTE 9 
defineBitFieldRev(MODULATION_ATTENUATOR,uint32_t,8,6,6); 
defineBitFieldRev(FRACTIONAL_DENOMINATOR,uint32_t,8,12,10);
// BYTE 10
defineBitFieldRev(FRACTIONAL_OFFSET,uint32_t,8,22,10);
// BYTE 11
// UINT 3
// BYTE 12
defineBitFieldRev(VMULT_OUT_ENABLE,uint32_t,12,0,1);
defineBitFieldRev(IND_MULT_ENABLE,uint32_t,12,1,1);
defineBitFieldRev(FREQ_REF_OUT_ENABLE,uint32_t,12,2,1);
defineBitFieldRev(REF_OSC_TC_INFL,uint32_t,12,3,6);
// BYTE 13
defineBitFieldRev(REF_OSC_TC_COLD,uint32_t,12,9,7);
// BYTE 14
defineBitFieldRev(REF_OSC_TC_HOT,uint32_t,12,16,7);
defineBitFieldRev(REF_OSC_ENABLE,uint32_t,12,23,1);
// BYTE 15
defineBitFieldRev(REF_OSC_TC_LIN,uint32_t,12,24,6);
defineBitFieldRev(REF_OSC_TEST_MODE,uint32_t,12,30,2);

// }}}USR
// }}}RME
// {{{RME classifier 'fractnRfMode_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'supportedRefFreqs_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'PRESCALER_DATA_SIZE'
const Integer fractionalN::PRESCALER_DATA_SIZE( 14 );
// }}}RME

// {{{RME operation 'commitGPO(Integer,Integer)'
void fractionalN::commitGPO( Integer portNumber, Integer rfState )
{
	// {{{USR
	  spi[rfState]->sync();

	// }}}USR
}
// }}}RME

// {{{RME operation 'fractionalN(fractionalNDefault*,rfSpiBuffer**,Integer)'
fractionalN::fractionalN( fractionalNDefault * init, rfSpiBuffer * * spiBuffers, Integer numOfRfStates )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	  : generalPurposeOutputManager(NUM_OF_FRACTN_GPOS),
	    synthesizerAdjust(numOfRfStates),
	    synthesizer(numOfRfStates),
	    modulator(numOfRfStates),
	    modulationBalanceAttenuator(numOfRfStates),
	    discreteDeviceControl(1,numOfRfStates)

	// }}}USR
	// }}}RME
{
	// {{{USR
	  //----------------------------- LOCAL VARIABLES ------------------------------
	  int i, j;
	  
	  //---------------------------------- CODE ------------------------------------  
	  
	  // set default data
	  spi = spiBuffers;
	  defaultData = init;
	  prescalerDataTbl = new dataPoint*[PRESCALER_DATA_SIZE];
	  
	  prescalerDataTbl[0]  = new dataPoint(0,0);        // Disabled start
	  prescalerDataTbl[1]  = new dataPoint(1*KHZ,0);    // Disabled end
	  prescalerDataTbl[2]  = new dataPoint(1*KHZ,5);    // Low band start
	  prescalerDataTbl[3]  = new dataPoint(46*KHZ,5);   // Low band end
	  prescalerDataTbl[4]  = new dataPoint(46*MHZ,1);   // Mid band start
	  prescalerDataTbl[5]  = new dataPoint(167*MHZ,1);  // Mid band end
	  prescalerDataTbl[6]  = new dataPoint(167*MHZ,2);  // UHF/VHF band start
	  prescalerDataTbl[7]  = new dataPoint(380*MHZ,2);  // UHF/VHF band end
	  prescalerDataTbl[8]  = new dataPoint(380*MHZ,3);  // UHF band start
	  prescalerDataTbl[9]  = new dataPoint(570*MHZ,3);  // UHF band end
	  prescalerDataTbl[10] = new dataPoint(570*MHZ,4);  // 800/900 start        
	  prescalerDataTbl[11] = new dataPoint(960*MHZ,4);  // 800/900 end          
	  prescalerDataTbl[12] = new dataPoint(960*MHZ,6);  // 1GHz start           
	  prescalerDataTbl[13] = new dataPoint(2000*MHZ,6); // 1GHz end             

	  prescaler = new prescalerData((dataPoint**)prescalerDataTbl, PRESCALER_DATA_SIZE);
	  error = new Integer[numOfRfStates];
	  
	  // set images to default and initialize error array
	  for(i = 0; i < numOfRfStates; i++)
	  {
	    for(j = 0; j < FRACTN_IMAGE_SIZE; j++)
	    {
	      (*spi[i])[j] = defaultData->defaultImages[i][j];
	    }
	    error[i] = 0;
	  } 

	// }}}USR
}
// }}}RME

// {{{RME operation 'getError(Integer)'
Integer fractionalN::getError( Integer rfState )
{
	// {{{USR
	  return error[rfState];  

	// }}}USR
}
// }}}RME

// {{{RME operation 'setFreqParams(Integer,Integer,Integer,Integer)'
void fractionalN::setFreqParams( Integer frequency, Integer refFreq, Integer resolution, Integer rfState )
{
	// {{{USR
	  //----------------------------- LOCAL VARIABLES ------------------------------
	  UInteger div_modulus;            // caculated divider modulus value             
	  Integer A_mod;                   // caculated A  counter values                 
	  Integer B_mod;                   // caculated B counter values                  
	  UInteger modulus_freq;
	  UInteger numerator;
	  UInteger denominator;
	  UInteger prescalerIndex;
	  UInteger prescalerModulus;
	  UInteger refFreqBitPattern;
	  UInteger refFreqFrequency;
	  uint32_t* image;
	  
	  //---------------------------------- CODE ------------------------------------  
	  
	  // get prescaler data object, frequency, and image base on rfState
	  image = *spi[rfState];
	  
	  // get prescaler index (ie. bit pattern) and modulus
	  prescalerIndex = prescaler->interpolate(frequency);
	  prescalerModulus = prescaler->getPrescalerModulus(prescalerIndex);
	  
	  // get reference frequency frequency value and bitpattern to program
	  refFreqFrequency = refFreq;

	  switch(refFreq)
	  {
	    case (2100000):
	      refFreqBitPattern = defaultData->clockControl[REFERENCE_2_1_MHZ];
	      break;
	    case (2400000):
	      refFreqBitPattern = defaultData->clockControl[REFERENCE_2_4_MHZ];
	      break;
	    default: 
	      refFreqBitPattern = defaultData->clockControl[REFERENCE_2_225_MHZ];
	      break;
	  }

	  // synthesizer A & B divider modulus calc: 
	  div_modulus = (frequency)/(refFreqFrequency);
	  modulus_freq = div_modulus*(refFreqFrequency);
	  
	  // calculate numerator and denominator
	  numerator = (frequency-modulus_freq)/resolution;
	  denominator = (refFreqFrequency)/resolution;
	  
	  // set numerator in image
	  setBitField(image, FRACTIONAL_NUMERATOR, numerator);
	  
	  // set denominator in image (first invert and reverse bits)
	  setBitField(image, FRACTIONAL_DENOMINATOR, utility::rev_bits(~denominator, 10));
	  
	  // set prescaler in image
	  setBitField(image, BAND_SELECT, prescalerIndex);
	  
	  // program reference frequency
	  // set bits 32-35
	  setBitField(image, REFERENCE_DIVIDER, refFreqBitPattern & 0xF);
	  
	  // set bit 44 (ie. additional reference divider mode select)
	  setBitField(image, ADDITIONAL_REF_DIV_MODE_SELECT,(refFreqBitPattern & 0x10)?1:0);
	  
	  // set bit 90 (ie. fref_out enable/disable)
	  setBitField(image, FREQ_REF_OUT_ENABLE, refFreqBitPattern>>5); 
	  
	  // calculate A & B counter values:
	  if(frequency > (60*MHZ))              //If frequency above Low Band
	  {
	    A_mod = 33 - ((div_modulus + 6) / prescalerModulus);
	    B_mod = 16 - ((div_modulus + 6) % prescalerModulus);
	    
	    // Test for overflow of B
	    if (B_mod == 16)
	    {
	      ++A_mod;
	      B_mod -= prescalerModulus;
	    }
	  }
	  else                 // Low Band 
	  { 
	    A_mod = 28 - div_modulus;
	    B_mod = 0;
	  }
	  
	  // set A_mod and B_mod in image
	  setBitField(image, A_DIVIDER_MODULUS, A_mod);
	  setBitField(image, B_DIVIDER_MODULUS, B_mod);  

	// }}}USR
}
// }}}RME

// {{{RME operation 'setSynthFrequency(Integer,Integer,Integer,Integer)'
Integer fractionalN::setSynthFrequency( Integer freq, Integer rfState, Integer res, Integer fref )
{
	// {{{USR
	  error[rfState] = fref;
	  setFreqParams(freq, fref, res, rfState);
	  return synthesizer::setSynthFrequency(freq, rfState, 0, 0);

	// }}}USR
}
// }}}RME

// {{{RME operation 'setGPO(Integer,Integer,Integer)'
void fractionalN::setGPO( Integer portNumber, Integer outputState, Integer rfState )
{
	// {{{USR
	  
	  //----------------------------- LOCAL VARIABLES ------------------------------
	   const Integer gpoEnabled = 1;
	   const Integer gpoDisabled = 0; 
	   const Integer gpoTriState = -1;  

	  //---------------------------------- CODE ------------------------------------  

	  // get image based on rfState
	  uint32_t *image = *spi[rfState];
	  
	  //GPO 3 has 0,1,-1 (tri-state) state options
	  //GPO 1,2,4 have 0,1 state options
	  switch(portNumber)
	  {
	  case 1:
	    {
	      // write port 1
	      setBitField(image, AUX1, (outputState == gpoEnabled)?gpoEnabled:gpoDisabled);
	      break;
	    }
	  case 2:
	    {
	      // write port 2
	      setBitField(image, AUX2, (outputState == gpoEnabled)?gpoEnabled:gpoDisabled);
	      break;
	    }
	  case 3:
	    {
	      Integer auxEnableBit = gpoDisabled;  // default tri-state mode
	      
	      // write port 3 output and set aux enable bit only if not tri-state
	      if (outputState != gpoTriState)
	      {
	        setBitField(image, AUX3, outputState);
	        auxEnableBit = gpoEnabled;
	      }
	      
	      // write aux enable bit
	      setBitField(image, AUX3_ENABLE, auxEnableBit);
	      break;
	    }
	  case 4:
	    {
	      // write port 4
	      setBitField(image, AUX4, (outputState == gpoEnabled)?gpoEnabled:gpoDisabled);
	      break;
	    }
	  default:
	    break;
	  }

	// }}}USR
}
// }}}RME

// {{{RME operation 'setModBalance(Integer,Integer)'
Integer fractionalN::setModBalance( Integer attenuation, Integer rfState )
{
	// {{{USR
	  // update mod balance in image
	  setBitField((*spi[rfState]), MODULATION_ATTENUATOR, attenuation);
	  
	  // store new mod balance and return old value
	  return modulationBalanceAttenuator::setModBalance(attenuation, rfState);  

	// }}}USR
}
// }}}RME

// {{{RME operation 'setModSensitivity(Integer,Integer)'
Integer fractionalN::setModSensitivity( Integer dev, Integer rfState )
{
	// {{{USR
	  //----------------------------- LOCAL VARIABLES ------------------------------

	  //---------------------------------- CODE ------------------------------------  
	  
	  if(dev <= 0)
	  {
	    // Disable the modulation select bits (ADC)   
	    setBitField(*spi[rfState], MOD_MODE_SELECT, 0);
	    // Disable Modulation Attentuator 
	    setBitField(*spi[rfState], MOD_ATTEN_ENABLE, 0);
	  }
	  else if(dev <= 2.5*KHZ)
	  {
	    //set fracn tx buffer image = 2.5KHz
	    setBitField(*spi[rfState], MOD_MODE_SELECT, 3); 
	    // Default the Modulation Attenuator as enabled.      
	    setBitField(*spi[rfState], MOD_ATTEN_ENABLE, 1);
	  }
	  else
	  {
	    // Default the ADC to a 4KHz/5KHz system deviation.   
	    setBitField(*spi[rfState], MOD_MODE_SELECT, 2);
	    // Default the Modulation Attenuator as enabled.      
	    setBitField(*spi[rfState], MOD_ATTEN_ENABLE, 1);
	  }
	  // store new modulation value and return previous one
	  return modulator::setModSensitivity(dev, rfState);  

	// }}}USR
}
// }}}RME

// {{{RME operation 'setRFState(Integer)'
Integer fractionalN::setRFState( Integer rfState )
{
	// {{{USR
	  //----------------------------- LOCAL VARIABLES ------------------------------
	  
	  //---------------------------------- CODE ------------------------------------  
	  // write the image
	  spi[rfState]->sync();
	  // set the RF state and return previous
	  return synthesizer::setRFState(rfState);  

	// }}}USR
}
// }}}RME

// {{{RME operation 'setWarp(Integer,Integer)'
Integer fractionalN::setWarp( Integer warp, Integer rfState )
{
	// {{{USR
	  // get image based on rfState
	  uint32_t *image = *spi[rfState];
	  
	  // write warp to images: LSB is stored seperately and bits 1-8 reversed order
	  setBitField(image,REF_OSC_WARP, utility::rev_bits((warp >> 1), 8));
	  setBitField(image,WARP_LSB, (warp & 0x1));
	  
	  // set currentWarp value and return previous warp value
	  return synthesizerAdjust::setWarp(warp, rfState);

	// }}}USR
}
// }}}RME

// {{{RME operation '~fractionalN()'
fractionalN::~fractionalN( void )
{
	// {{{USR
	  delete prescaler;
	  delete [] error;
	  for(Integer i = 0; i < PRESCALER_DATA_SIZE; i++)
	  {
	    delete prescalerDataTbl[i];
	  }
	  delete prescalerDataTbl;

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'fractnRfMode_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'supportedRefFreqs_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
