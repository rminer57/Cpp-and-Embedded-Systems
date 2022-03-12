// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::Mako'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Mako.h"
#endif

#include <HALtestLib_win32.h>
#include <Mako.h>
#include <Connection.h>
#include <Mako1WireCtrl.h>
#include <MakoADC.h>
#include <MakoAudioInputCtrl.h>
#include <MakoAudioOutputCtrl.h>
#include <MakoDCPwrCtrl.h>
#include <MakoFrontEndFilter.h>
#include <MakoIGNSenseCtrl.h>
#include <MakoIntrCtrl.h>
#include <MakoOPTCTRL.h>
#include <MakoPrivateBitfieldsReg2.h>
#include <MakoPrivateBitfieldsReg3.h>
#include <MakoPrivateBitfieldsReg6.h>
#include <MakoRFPA.h>
#include <MakoRFPowerControl.h>
#include <MakoUSBCtrl.h>
#include <MakoWatchdogCtrl.h>
#include <PowerConfiguration.h>
#include <SIntArray.h>
#include <rfSpiBuffer.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'MAKO_DAC_1'
const unsigned int Mako::MAKO_DAC_1( 0 );
// }}}RME

// {{{RME classAttribute 'MAKO_DAC_2'
const unsigned int Mako::MAKO_DAC_2( 1 );
// }}}RME

// {{{RME classAttribute 'MAKO_DAC_3'
const unsigned int Mako::MAKO_DAC_3( 2 );
// }}}RME

// {{{RME classAttribute 'LUT_SIZE'
const unsigned int Mako::LUT_SIZE( 32 );
// }}}RME

// {{{RME classAttribute 'DAC_POWER_DOWN'
const unsigned int Mako::DAC_POWER_DOWN( 0xFFFF );
// }}}RME

// {{{RME classAttribute 'MAKO_NO_ERROR'
const unsigned int Mako::MAKO_NO_ERROR( 0 );
// }}}RME

// {{{RME classAttribute 'MAKO_ALLOCATION_ERROR_ADC'
const unsigned int Mako::MAKO_ALLOCATION_ERROR_ADC( 10 );
// }}}RME

// {{{RME classAttribute 'MAKO_ADC_CH_RANGE_ERROR'
const unsigned int Mako::MAKO_ADC_CH_RANGE_ERROR( 11 );
// }}}RME

// {{{RME classAttribute 'MAKO_ALLOCATION_ERROR_OPTCTRL'
const unsigned int Mako::MAKO_ALLOCATION_ERROR_OPTCTRL( 20 );
// }}}RME

// {{{RME classAttribute 'MAKO_ALLOCATION_ERROR_AUDIO_SPKR'
const unsigned int Mako::MAKO_ALLOCATION_ERROR_AUDIO_SPKR( 31 );
// }}}RME

// {{{RME classAttribute 'MAKO_ALLOCATION_ERROR_AUDIO_MIC'
const unsigned int Mako::MAKO_ALLOCATION_ERROR_AUDIO_MIC( 32 );
// }}}RME

// {{{RME classAttribute 'MAKO_ALLOCATION_ERROR_DCPWR'
const unsigned int Mako::MAKO_ALLOCATION_ERROR_DCPWR( 41 );
// }}}RME

// {{{RME classAttribute 'MAKO_ALLOCATION_ERROR_IGNSENSE'
const unsigned int Mako::MAKO_ALLOCATION_ERROR_IGNSENSE( 51 );
// }}}RME

// {{{RME classAttribute 'MAKO_ALLOCATION_ERROR_1WIRECTRL'
const unsigned int Mako::MAKO_ALLOCATION_ERROR_1WIRECTRL( 61 );
// }}}RME

// {{{RME classAttribute 'MAKO_ALLOCATION_ERROR_INTRCTRL'
const unsigned int Mako::MAKO_ALLOCATION_ERROR_INTRCTRL( 71 );
// }}}RME

// {{{RME classAttribute 'MAKO_ALLOCATION_ERROR_WATCHDOG'
const unsigned int Mako::MAKO_ALLOCATION_ERROR_WATCHDOG( 81 );
// }}}RME

// {{{RME operation 'getNumDACBuffers()'
unsigned int Mako::getNumDACBuffers( void ) const
{
	// {{{USR
	return m_numDACBuffers;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getDAC(unsigned int)'
bool Mako::getDAC( unsigned int dacSelect )
{
	// {{{USR
	bool returnStatus = false;

	if (dacSelect < NUMBER_OF_DACS)
	   {
	   if (m_dacAvailable[dacSelect])
	      {
	      m_dacAvailable[dacSelect] = false;                          // Reserve the DAC.
	      returnStatus = true;
	      }
	   }

	return returnStatus;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getFrontEndFilter(unsigned int,uint32_t *,unsigned int)'
MakoFrontEndFilter * Mako::getFrontEndFilter( unsigned int dacSelect, uint32_t * dacData, unsigned int numRFStates )
{
	// {{{USR
	MakoFrontEndFilter *frontEndFilter=0;

	// Ensure the requested DAC is available and correct number of RF states have been defined:
	if ( (getDAC(dacSelect)) && (numRFStates == m_numDACBuffers) )
	   {
	   frontEndFilter = new MakoFrontEndFilter(dacData, m_dacCommonBuffers, dacSelect, m_numDACBuffers);
	   }

	return frontEndFilter;

	// }}}USR
}
// }}}RME

// {{{RME operation 'getRFPA(unsigned int,uint32_t *,unsigned int)'
MakoRFPA * Mako::getRFPA( unsigned int dacSelect, uint32_t * dacData, unsigned int numRFStates )
{
	// {{{USR
	MakoRFPA *RFPA=0;

	// Ensure the requested DAC is available and correct number of RF states have been defined:
	if ( (getDAC(dacSelect)) && (numRFStates == m_numDACBuffers) )
	   {
	      RFPA = new MakoRFPA(dacData, m_dacCommonBuffers, dacSelect, m_numDACBuffers);
	   }

	return RFPA;

	// }}}USR
}
// }}}RME

// {{{RME operation 'getRFPowerControl(unsigned int,PowerConfiguration**,rfSpiBuffer*,unsigned int)'
MakoRFPowerControl * Mako::getRFPowerControl( unsigned int dacSelect, PowerConfiguration * * dacConfig, rfSpiBuffer * dac3Buffer, unsigned int numRFStates )
{
	// {{{USR
	MakoRFPowerControl *makoPowerControl=0;

	// Ensure the requested DAC is DAC3 and DAC3 is available and number of RF states...
	// ...is equal to the number of RF states given to Mako's class constructor:
	if ( (dacSelect == Mako::MAKO_DAC_3) && (getDAC(dacSelect)) && (numRFStates == m_numDACBuffers) )
	   {
	   makoPowerControl = new MakoRFPowerControl(dacConfig, m_dacCommonBuffers, dac3Buffer, m_numDACBuffers);
	   }

	return makoPowerControl;

	// }}}USR
}
// }}}RME

// {{{RME operation 'Mako(rfSpiBuffer**,unsigned int,Connection *)'
Mako::Mako( rfSpiBuffer * * dacBuffers, unsigned int numDACBuffers, Connection * connection )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_dacCommonBuffers(dacBuffers), m_numDACBuffers(numDACBuffers), m_connection(connection), m_ResourceAvailableAudioInput( true ),  m_ResourceAvailableAudioOutput( true ), m_imageArrayAudioReg(0), m_ResourceAvailableDCPwrCtrl(true), m_ResourceAvailableIGNSenseCtrl(true), m_ResourceAvailable1Wire(true), m_ResourceAvailableIntrCtrl(true), m_ResourceAvailableWatchdogCtrl(true), m_imageArrayIDCtrlReg(0), m_imageDCRegulatorReg(0), m_ResourceAvailableUsb(true), m_MakoICVersion(2) 

	// }}}USR
	// }}}RME
{
	// {{{USR
	   int i;

	   uint32_t rdvalue = 0;

	   // All DACs available upon Mako construction.
	   for (i = 0; i < NUMBER_OF_DACS; i++)
	   {
	   m_dacAvailable[i]=true;
	   }

	  // All ADCs available upon Mako construction.
	   for (i = 0; i < NUMBER_OF_ADCS; i++)
	   {
	   m_adcAvailable[i]=true;
	   }

	   // Initialize the buffer to the reset state
	   for(i = 0; i < m_numDACBuffers; i++)
	   {
	      (*m_dacCommonBuffers[i])[0] = 0;         // DAC1, DAC2, DAC3 in power down; DAC data 0; DAC3 not triggered to load.
	      setBitField((*m_dacCommonBuffers[i]), READ_WRITE_CNTRL, MAKO_WRITE);                  // Enable write.
	      setBitField((*m_dacCommonBuffers[i]), DAC_ADDRESS, DAC_REGISTER_ADDR);                // DAC Address.
	   }

	   // register image initialization
	   m_imageArrayAudioReg  = new uint32_t [MAKO_NUMBER_OF_AUDIO_REGISTER_GROUPS];  // 3 registers
	   m_imageArrayIDCtrlReg = new uint32_t [MAKO_NUMBER_OF_IDCTRL_REGISTER_GROUPS]; // 3 registers

	   // READ DEFAULT AUDIO REGISTER VALUES FROM FROM IC INTO IMAGES

	   // set mako subcomponent audio register address (bits D27 - D26 )
	   setBitField( &rdvalue, MAKO_AUDIO_SEL_BITFIELD, MAKO_AUDIO_SREG123_SEL);
	   m_imageArrayAudioReg[MAKO_AUDIO_SREG123_SEL] = rdRegister(MAKO_AUDIO_REGISTER_ADDR,rdvalue);

	   // set mako subcomponent audio register address (bits D27 - D26 )
	   setBitField( &rdvalue, MAKO_AUDIO_SEL_BITFIELD, MAKO_AUDIO_SREG45_SEL);
	   m_imageArrayAudioReg[MAKO_AUDIO_SREG45_SEL] = rdRegister(MAKO_AUDIO_REGISTER_ADDR,rdvalue);

	   // set mako subcomponent audio register address (bits D27 - D26 )
	   setBitField( &rdvalue, MAKO_AUDIO_SEL_BITFIELD, MAKO_AUDIO_PA_SEL);
	   m_imageArrayAudioReg[MAKO_AUDIO_PA_SEL] = rdRegister(MAKO_AUDIO_REGISTER_ADDR,rdvalue);

	   // READ DEFAULT ID/CONTROL REGISTER VALUES FROM FROM IC INTO IMAGES

	  // set mako subcomponent audio register address (bits D27 - D26 )
	   setBitField( &rdvalue, MAKO_ID_CTRL_REGSEL_BITFIELD, MAKO_ID_CTRL_DAT0_ADDR);
	   m_imageArrayAudioReg[MAKO_ID_CTRL_DAT0_ADDR] = rdRegister(MAKO_ID_CTRL_REGISTER_ADDR,rdvalue);

	   // set mako subcomponent audio register address (bits D27 - D26 )
	   setBitField( &rdvalue, MAKO_ID_CTRL_REGSEL_BITFIELD, MAKO_ID_CTRL_DAT1_ADDR);
	   m_imageArrayAudioReg[MAKO_ID_CTRL_DAT1_ADDR] = rdRegister(MAKO_ID_CTRL_REGISTER_ADDR,rdvalue);

	   // set mako subcomponent audio register address (bits D27 - D26 )
	   setBitField( &rdvalue, MAKO_ID_CTRL_REGSEL_BITFIELD, MAKO_ID_CTRL_DAT2_ADDR);
	   m_imageArrayAudioReg[MAKO_ID_CTRL_DAT2_ADDR] = rdRegister(MAKO_ID_CTRL_REGISTER_ADDR,rdvalue); 

	   for ( i=0; i<MAKO_NUMBER_OF_IDCTRL_REGISTER_GROUPS; i++ )
	   {
	      m_imageArrayIDCtrlReg[i] = 0;
	   }
	   

	   


	// }}}USR
}
// }}}RME

// {{{RME operation 'getOPT(uint32_t,uint32_t,uint32_t)'
MakoOPTCTRL * Mako::getOPT( uint32_t opt1init, uint32_t opt2init, uint32_t opt3init )
{
	// {{{USR
	     MakoOPTCTRL * OPTCTRL = 0;

	     
	     // initialize to error state in event that if statement not executed
	     m_error = MAKO_ALLOCATION_ERROR_OPTCTRL;

	     if ( !m_ResourceAvailableOPT )
	     {
	           m_ResourceAvailableOPT = false;    // Reserve the ADC.
	 
	           m_error = MAKO_NO_ERROR;
	     	 
	     	   OPTCTRL = new MakoOPTCTRL( this, opt1init, opt2init, opt3init);     
	     }


	     return OPTCTRL;
	// }}}USR
}
// }}}RME

// {{{RME operation 'wrRegister(unsigned int,uint32_t)'
void Mako::wrRegister( unsigned int mako_reg_addr, uint32_t reg_data )
{
	// {{{USR
	  uint32_t wrData = 0;
	  SIntArray * db = 0;

	  if ( mako_reg_addr <= MAKO_HIGHEST_REG_ADDR )
	  {   

	    // store the user specified mako subcomponent data (bits D27 - D0)
	    wrData = reg_data;

	    // set bit D31 Mako rd~/Wr to write
	    setBitField( &wrData, MAKO_READ_WRITE_CNTRL, MAKO_WRITE );

	    // set mako subcomponent register address (bits D30 - D28 )
	    setBitField( &wrData, MAKO_REG_ADDRESS, mako_reg_addr);

	    // ENDIAN-NESS notes.
	    // First,  the SPI driver sends data as BIG-ENDIAN - meaning it first sends the 16 bit word at
	    // SIntArray element zero, followed by 1, etc.  
	    // Second, C55 is BIG-ENDIAN, meaning that the most significant word is written to the lowest address.
	    // Thus, when executing on BIG-ENDIAN, no swap is needed.
	    // The TI ARM9 (as is Intel) is LITTLE-ENDIAN, and a swap is needed, both of the two int16_t's AND
	    // of the bytes within each int16_t.

#ifndef OMAP_HALI_C55 // arm9 or windows

	    wrData = endianSwap32(wrData);

	    // create the data array. LITTLE to BIG ENDIAN adjustment of bytes be made below
	    db = new SIntArray( MAKO_SINTARRAY_ALLOCATION_SIZE, (int16_t *)&wrData); 

#else // BIG ENDIAN C55

	    // create the data array. no ENDIAN adjustment is necessary
	    db = new SIntArray( MAKO_SINTARRAY_ALLOCATION_SIZE, (int16_t *)&wrData);   

#endif  


	    // Send 4 bytes of data over the connection in order to clock in the receive data
	    // the spi peripheral always sends MSB first. MAKO_SINTARRAY_ALLOCATION_SIZE = 2
	    // Mako registers are 32 bits wide. SIntArray elements are 16 bits wide.
	    // Hence, an SIntArray size of 2 is required. 
		m_connection->send( db );

	  }
	// }}}USR
}
// }}}RME

// {{{RME operation 'rdRegister(unsigned int,uint32_t)'
uint32_t Mako::rdRegister( unsigned int mako_reg_addr, uint32_t reg_data )
{
	// {{{USR
	 
	 	  volatile uint32_t retval = 0;

		  uint32_t wrData = 0;
	      int16_t * int16_t_ptr = 0;    
	   	  SIntArray * db = 0; // array reference used as the return value for receive

	      // check range of register address argument, must be 0 to 7.
	      // if value is out of range, ignore and do nothing.
		  if ( mako_reg_addr <= MAKO_HIGHEST_REG_ADDR)
		  {   
		    // store the user specified mako subcomponent data (bits D27 - D0)
		    wrData = reg_data;

		    // set bit D31 Mako rd~/Wr to read
		    setBitField( &wrData, MAKO_READ_WRITE_CNTRL, MAKO_READ );

		    // set mako register address (0 - 7 ) (bits D30 - D28 )
		    setBitField( &wrData, MAKO_REG_ADDRESS, mako_reg_addr);

	        // ENDIAN-NESS notes.
	        // First,  the SPI driver sends data as BIG-ENDIAN - meaning it first sends the 16 bit word at
	        // SIntArray element zero, followed by 1, etc.  
	        // Second, C55 is BIG-ENDIAN, meaning that the most significant word is written to the lowest address.
	        // Thus, when executing on BIG-ENDIAN, no swap is needed.
	        //
	        // The TI ARM9 (as is Intel) is LITTLE-ENDIAN, and a swap is needed.   

#ifndef OMAP_HALI_C55 // arm9 or windows
	 
	    wrData = endianSwap32(wrData);

	    // create the data array. LITTLE to BIG ENDIAN adjustment of bytes be made below
	    db = new SIntArray( MAKO_SINTARRAY_ALLOCATION_SIZE, (int16_t *)&wrData); 

	  
#else // BIG ENDIAN C55

	    // create the data array. no ENDIAN adjustment is necessary for C55
	    db = new SIntArray( MAKO_SINTARRAY_ALLOCATION_SIZE, (int16_t *)&wrData);   

#endif   	  
		    // Send 4 bytes of data over the connection in order to clock in the receive data
	        // the spi peripheral always sends MSB first. MAKO_SINTARRAY_ALLOCATION_SIZE = 2
	        // Mako registers are 32 bits wide. SIntArray elements are 16 bits wide.
	        // Hence, an SIntArray size of 2 is required. 
		    m_connection->send( db );

		    db =  (SIntArray *)m_connection->receive( );

#ifndef OMAP_HALI_C55 // arm9 or windows

	    // transfer int16_t values to the int32_t 
	    int16_t_ptr = (int16_t *)&retval;

	    *int16_t_ptr++ = (*db)[0];
	    *int16_t_ptr   = (*db)[1];

	    retval = endianSwap32(retval);
	 

#else // BIG ENDIAN C55

	        retval = (*db)[0];
	        retval = (retval  << 16) &0xffff0000 | (((*db)[1]) & 0xffff);   

#endif  

		    delete db;

		  }
	  
		  return retval;

	// }}}USR
}
// }}}RME

// {{{RME operation 'getIGNSenseCtrl(uint32_t)'
MakoIGNSenseCtrl * Mako::getIGNSenseCtrl( uint32_t ignmode )
{
	// {{{USR
	  	     MakoIGNSenseCtrl * retobj_ptr = 0;
		     
		     // initialize to error state in event that if statement not executed
		     m_error = MAKO_ALLOCATION_ERROR_IGNSENSE;

		     if ( m_ResourceAvailableIGNSenseCtrl )
		     {
		           m_ResourceAvailableIGNSenseCtrl = false;    // Reserve the resource.
		 
		           m_error = MAKO_NO_ERROR;
		     	 
		     	   retobj_ptr = new MakoIGNSenseCtrl( this, ignmode );     
		     }

		     return retobj_ptr;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getAudioInputCtrl(uint32_t,uint32_t,uint32_t)'
MakoAudioInputCtrl * Mako::getAudioInputCtrl( uint32_t sreg123, uint32_t sreg45, uint32_t sregPA )
{
	// {{{USR
	   MakoAudioInputCtrl * RetObject = 0;


	   // initialize to error state in event that if statement not executed  
	   m_error = MAKO_ALLOCATION_ERROR_AUDIO_MIC;

	   if ( m_ResourceAvailableAudioInput )
	   {
	       m_ResourceAvailableAudioInput = false;    // Reserve the resource.
	 
	       m_error = MAKO_NO_ERROR;
	     	 
	       RetObject = new MakoAudioInputCtrl( this, sreg123, sreg45, sregPA );     
	   }       
	   

	   return RetObject;
	  
	// }}}USR
}
// }}}RME

// {{{RME operation 'getAudioOutputCtrl(uint32_t,uint32_t,uint32_t)'
MakoAudioOutputCtrl * Mako::getAudioOutputCtrl( uint32_t sreg123, uint32_t sreg45, uint32_t sregPA )
{
	// {{{USR
	   MakoAudioOutputCtrl * RetObject = 0;


	 
	   // initialize to error state in event that if statement not executed  
	   m_error = MAKO_ALLOCATION_ERROR_AUDIO_SPKR;

	   if ( m_ResourceAvailableAudioOutput )
	   {
	     m_ResourceAvailableAudioOutput = false;    // Reserve the resource.
	 
	     m_error = MAKO_NO_ERROR;
	     	 
	     RetObject = new MakoAudioOutputCtrl( this, sreg123, sreg45, sregPA );     
	   }

	   return RetObject;
	  
	// }}}USR
}
// }}}RME

// {{{RME operation 'syncAudio()'
void Mako::syncAudio( void )
{
	// {{{USR
		     // registers containing settings are in registers 1 - 5 and PA
		     // write the address to the bitfield
		     // YT : This has been restored.
		     setBitField( &m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_SEL_BITFIELD, MAKO_AUDIO_SREG123_SEL);

		     // set the program bit - this updates the actual hardware with the settings of
		     // the Mako spi register, upon completion of the spi write

		     // note: the following change was requested by the LTD China team. This does not agree with
		     // the Mako spec (is it in error).
		     // YT : This supposed to be the register need to change. Instead of the previous one.
		     setBitField( &m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_PRG_BITFIELD, 1 );
		     //setBitField( &m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_PRG_BITFIELD, MAKO_AUDIO_SREG123_SEL);

		     // write register 1 - 3 images to the IC 
		     wrRegister( MAKO_AUDIO_REGISTER_ADDR, m_imageArrayAudioReg[SREG1_3] );

		     setBitField( &m_imageArrayAudioReg[SREG4_5], MAKO_AUDIO_SEL_BITFIELD, MAKO_AUDIO_SREG45_SEL);

		     // set the program bit - this updates the actual hardware with the settings of
		     // the Mako spi register, upon completion of the spi write
		     //setBitField( &m_imageArrayAudioReg[SREG4_5], MAKO_AUDIO_PRG_BITFIELD, MAKO_AUDIO_SREG45_SEL);
			 setBitField( &m_imageArrayAudioReg[SREG4_5], MAKO_AUDIO_PRG_BITFIELD, 1 );

		     // write register 4 - 5 images to the IC 
		     wrRegister( MAKO_AUDIO_REGISTER_ADDR, m_imageArrayAudioReg[SREG4_5] );
		 
		     setBitField( &m_imageArrayAudioReg[SREG_PA],MAKO_AUDIO_SEL_BITFIELD, MAKO_AUDIO_PA_SEL);

		     // set the program bit - this updates the actual hardware with the settings of
		     // the Mako spi register, upon completion of the spi write

		     // note: the following change was requested by the LTD China team. This does not agree with
		     // the Mako spec (is it in error).
		     setBitField( &m_imageArrayAudioReg[SREG_PA], MAKO_AUDIO_PRG_BITFIELD, 1 );
		     //setBitField( &m_imageArrayAudioReg[SREG_PA], MAKO_AUDIO_PRG_BITFIELD, MAKO_AUDIO_PA_SEL);
		     
		     // write register PA_REG and PA_SCP images to the IC 
		     wrRegister( MAKO_AUDIO_REGISTER_ADDR, m_imageArrayAudioReg[SREG_PA] );
	// }}}USR
}
// }}}RME

// {{{RME operation '~Mako()'
Mako::~Mako( void )
{
	// {{{USR

	delete [] m_imageArrayAudioReg;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getADC(unsigned int,uint32_t)'
MakoADC * Mako::getADC( unsigned int adcSelect, uint32_t adcConfig )
{
	// {{{USR
	     MakoADC * ADC = 0;

	     // initialize to error state in event that if statement not executed
	     m_error = MAKO_ADC_CH_RANGE_ERROR;

	     // range check the channel select parameter, values of 0 to 10 are valid.
	     if ( adcSelect < NUMBER_OF_ADCS )
	     {
	        // initialize to error state in event that if statement not executed
	        m_error = MAKO_ALLOCATION_ERROR_ADC;

	        if (m_adcAvailable[adcSelect])
	        {
	           m_adcAvailable[adcSelect] = false;    // Reserve the ADC.
	 
	           m_error = MAKO_NO_ERROR;
	     	 
	     	   ADC = new MakoADC( this, adcSelect, adcConfig);     
	        }
	     }


	     return ADC;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getIntrCtrl(uint32_t)'
MakoIntrCtrl * Mako::getIntrCtrl( uint32_t reginit )
{
	// {{{USR
	  	     MakoIntrCtrl * retobj_ptr = 0;
		     
		     // initialize to error state in event that if statement not executed
		     m_error = MAKO_ALLOCATION_ERROR_INTRCTRL;

		     if ( m_ResourceAvailableIntrCtrl )
		     {
		           m_ResourceAvailableIntrCtrl = false;    // Reserve the resource.
		 
		           m_error = MAKO_NO_ERROR;
		     	 
		     	   retobj_ptr = new MakoIntrCtrl( this, reginit );     
		     }

		     return retobj_ptr;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getDCPwrCtrl(uint32_t)'
MakoDCPwrCtrl * Mako::getDCPwrCtrl( uint32_t reginit )
{
	// {{{USR
	  	MakoDCPwrCtrl * retobj_ptr = 0;
		     
		// initialize to error state in event that if statement not executed
		m_error = MAKO_ALLOCATION_ERROR_DCPWR;

		if ( m_ResourceAvailableDCPwrCtrl )
		{
		   m_ResourceAvailableDCPwrCtrl = false;    // Reserve the resource.
		 
		   m_error = MAKO_NO_ERROR;
		     	 
		   retobj_ptr = new MakoDCPwrCtrl( this, reginit );     
		}

		return retobj_ptr;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getWatchdogCtrl()'
MakoWatchdogCtrl * Mako::getWatchdogCtrl( void )
{
	// {{{USR
	  	     MakoWatchdogCtrl * retobj_ptr = 0;
		     
		     // initialize to error state in event that if statement not executed
		     m_error = MAKO_ALLOCATION_ERROR_WATCHDOG;

		     if ( m_ResourceAvailableWatchdogCtrl )
		     {
		           m_ResourceAvailableWatchdogCtrl = false;    // Reserve the resource.
		 
		           m_error = MAKO_NO_ERROR;
		     	 
		     	   retobj_ptr = new MakoWatchdogCtrl( this );     
		     }

		     return retobj_ptr;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getMakoID()'
uint32_t Mako::getMakoID( void )
{
	// {{{USR
	    uint32_t rdData = 0;
	         
	    rdData = rdRegister( MAKO_ID_CTRL_DAT0_ADDR, rdData);

	    rdData = getBitField( &rdData, MAKO_ID_CTRL_ID0_BITFIELD);

		
	    return rdData;
	// }}}USR
}
// }}}RME

// {{{RME operation 'get1WireCtrl()'
Mako1WireCtrl * Mako::get1WireCtrl( void )
{
	// {{{USR
	  	     Mako1WireCtrl * retobj_ptr = 0;
		     
		     // initialize to error state in event that if statement not executed
		     m_error = MAKO_ALLOCATION_ERROR_1WIRECTRL;

		     if ( m_ResourceAvailable1Wire )
		     {
		           m_ResourceAvailable1Wire = false;    // Reserve the resource.
		 
		           m_error = MAKO_NO_ERROR;
		     	 
		     	   retobj_ptr = new Mako1WireCtrl( this );     
		     }

		     return retobj_ptr;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getUSB(uint32_t,uint32_t)'
MakoUSBCtrl * Mako::getUSB( uint32_t usb1_int_en, uint32_t usb2_int_en )
{
	// {{{USR
	  MakoUSBCtrl * USB = 0;

	     // initialize to error state in event that if statement not executed
	     m_error = MAKO_ALLOCATION_ERROR_USB;

	     if (m_ResourceAvailableUsb)
	     {
	        m_ResourceAvailableUsb = false;    // Reserve the usb resource.
	 
	        m_error = MAKO_NO_ERROR;
	     	 
	     	USB = new MakoUSBCtrl( this, usb1_int_en, usb2_int_en);     
	        
	     }


	     return USB;


	// }}}USR
}
// }}}RME

// {{{RME operation 'getICVersion()'
int Mako::getICVersion( void )
{
	// {{{USR

	return m_MakoICVersion ;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setICVersion(unsigned int)'
void Mako::setICVersion( unsigned int version )
{
	// {{{USR

	m_MakoICVersion = version;
	// }}}USR
}
// }}}RME

// {{{RME operation 'endianSwap32(uint32_t)'
uint32_t Mako::endianSwap32( uint32_t data32 )
{
	// {{{USR

	// Little Endian
	//*************************
	//* 0   *  1  *  2  *  3  *
	//*************************

	// Big Endian
	//*************************
	//* 3   *  2  *  1  *  0  *
	//*************************

	volatile uint32_t srcData32 = 0;
	volatile uint32_t tmpData32 = 0;
	volatile uint32_t retval32  = 0;

	srcData32 = data32;

	// ************
	// swap 0 and 3
	// ************
	tmpData32  = srcData32 << 24;
	tmpData32 &= 0xFF000000;
	retval32 = tmpData32; 

	tmpData32  = srcData32 >> 24;
	tmpData32 &= 0x000000FF;
	retval32 = retval32 | tmpData32;

	// ************
	// swap 1 and 2
	// ************
	tmpData32 = srcData32 << 8;
	tmpData32 &= 0x00FF0000;
	retval32 = retval32 | tmpData32;

	tmpData32 = srcData32 >> 8;
	tmpData32 &= 0x0000FF00;
	retval32 = retval32 | tmpData32;    

	return retval32;

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
