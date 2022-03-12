// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoAudioOutputCtrl'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "MakoAudioOutputCtrl.h"
#endif

#include <HALtestLib_win32.h>
#include <MakoAudioOutputCtrl.h>
#include <Mako.h>
#include <MakoPrivateBitfieldsReg3.h>
#include <bitfield.h>
#include <rf_audio_std_types.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'DIGITAL_GAIN_STEPSIZE'
const int MakoAudioOutputCtrl::DIGITAL_GAIN_STEPSIZE( 1 );
// }}}RME

// {{{RME classAttribute 'DIGITAL_GAIN_MIN'
const int MakoAudioOutputCtrl::DIGITAL_GAIN_MIN( 0 );
// }}}RME

// {{{RME classAttribute 'DIGITAL_GAIN_MAX'
const int MakoAudioOutputCtrl::DIGITAL_GAIN_MAX( 6 );
// }}}RME

// {{{RME classAttribute 'ANALOG_G5_GAIN_MAX'
const int MakoAudioOutputCtrl::ANALOG_G5_GAIN_MAX( 0 );
// }}}RME

// {{{RME classAttribute 'ANALOG_G5_GAIN_MIN'
const int MakoAudioOutputCtrl::ANALOG_G5_GAIN_MIN( -52 );
// }}}RME

// {{{RME classAttribute 'PREAMP_G3_GAIN_MAX'
const int MakoAudioOutputCtrl::PREAMP_G3_GAIN_MAX( 10 );
// }}}RME

// {{{RME classAttribute 'PREAMP_G3_GAIN_MIN'
const int MakoAudioOutputCtrl::PREAMP_G3_GAIN_MIN( 0 );
// }}}RME

// {{{RME classAttribute 'PREAMP_G3_GAIN_STEPSIZE'
const int MakoAudioOutputCtrl::PREAMP_G3_GAIN_STEPSIZE( 2 );
// }}}RME

// {{{RME classAttribute 'PWRAMP_G4_GAIN_MAX'
const int MakoAudioOutputCtrl::PWRAMP_G4_GAIN_MAX( 26 );
// }}}RME

// {{{RME classAttribute 'PWRAMP_G4_GAIN_MIN'
const int MakoAudioOutputCtrl::PWRAMP_G4_GAIN_MIN( 20 );
// }}}RME

// {{{RME classAttribute 'PWRAMP_G4_GAIN_STEPSIZE'
const int MakoAudioOutputCtrl::PWRAMP_G4_GAIN_STEPSIZE( 2 );
// }}}RME

// {{{RME classAttribute 'PA_STANDBY'
const int MakoAudioOutputCtrl::PA_STANDBY( 0 );
// }}}RME

// {{{RME classAttribute 'PA_ONUNMUTE'
const int MakoAudioOutputCtrl::PA_ONUNMUTE( 1 );
// }}}RME

// {{{RME classAttribute 'PA_INTAUDIOON'
const int MakoAudioOutputCtrl::PA_INTAUDIOON( 2 );
// }}}RME

// {{{RME classAttribute 'PA_EXTAUDIOON'
const int MakoAudioOutputCtrl::PA_EXTAUDIOON( 3 );
// }}}RME

// {{{RME operation 'MakoAudioOutputCtrl(Mako *,uint32_t,uint32_t,uint32_t)'
MakoAudioOutputCtrl::MakoAudioOutputCtrl( Mako * parent, uint32_t sreg123, uint32_t sreg45, uint32_t sregPA )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_MakoParent(parent)
	// }}}USR
	// }}}RME
{
	// {{{USR

	    // write the initial register values to the Mako register images
	    m_MakoParent->m_imageArrayAudioReg[0] = sreg123;

	    m_MakoParent->m_imageArrayAudioReg[1] = sreg45;    
	   
	    m_MakoParent->m_imageArrayAudioReg[2] = sregPA;
	   

	    // update the IC, (spi write with PRG field set)
	    m_MakoParent->syncAudio();
	 
	  
	// }}}USR
}
// }}}RME

// {{{RME operation '~MakoAudioOutputCtrl()'
MakoAudioOutputCtrl::~MakoAudioOutputCtrl( void )
{
	// {{{USR

	m_MakoParent->m_ResourceAvailableAudioOutput = true;

	// }}}USR
}
// }}}RME

// {{{RME operation 'setG5AnalogGain(int)'
void MakoAudioOutputCtrl::setG5AnalogGain( int gain )
{
	// {{{USR


	switch (gain)
	{
	  case 0:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXA_BITFIELD, 22);

	     m_MakoParent->syncAudio();

	  break;

	  case -2:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXA_BITFIELD, 21);

	     m_MakoParent->syncAudio();

	  break;

	  case -4:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXA_BITFIELD, 20);

	     m_MakoParent->syncAudio();

	  break;

	  case -6:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXA_BITFIELD, 19);

	     m_MakoParent->syncAudio();

	  break;

	  case -8:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXA_BITFIELD, 18);

	     m_MakoParent->syncAudio();

	  break;

	   case -10:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXA_BITFIELD, 17);

	     m_MakoParent->syncAudio();

	  break;  

	 case -12:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXA_BITFIELD, 16);

	     m_MakoParent->syncAudio();

	  break;

	  case -14:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXA_BITFIELD, 15);

	     m_MakoParent->syncAudio();

	  break;

	  case -16:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXA_BITFIELD, 14);

	     m_MakoParent->syncAudio();

	  break;

	  case -18:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXA_BITFIELD, 13);

	     m_MakoParent->syncAudio();

	  break;

	  case -20:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXA_BITFIELD, 12);

	     m_MakoParent->syncAudio();

	  break;

	   case -22:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXA_BITFIELD, 11);

	     m_MakoParent->syncAudio();

	  break;   

	  case -24:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXA_BITFIELD, 10);

	     m_MakoParent->syncAudio();

	  break;

	  case -26:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXA_BITFIELD, 9);

	     m_MakoParent->syncAudio();

	  break;

	  case -28:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXA_BITFIELD, 8);

	     m_MakoParent->syncAudio();

	  break;

	  case -30:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXA_BITFIELD, 7);

	     m_MakoParent->syncAudio();

	  break;

	   case -32:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXA_BITFIELD, 6);

	     m_MakoParent->syncAudio();

	  break;  

	 case -34:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXA_BITFIELD, 5);

	     m_MakoParent->syncAudio();

	  break;

	  case -36:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXA_BITFIELD, 4);

	     m_MakoParent->syncAudio();

	  break;

	 case -38:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXA_BITFIELD, 3);

	     m_MakoParent->syncAudio();

	  break;

	   case -40:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXA_BITFIELD, 2);

	     m_MakoParent->syncAudio();

	  break;  

	 case -46:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXA_BITFIELD, 1);

	     m_MakoParent->syncAudio();

	  break;

	  case -52:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXA_BITFIELD, 0);

	     m_MakoParent->syncAudio();

	  break;
	 
	  default:

	 
	  break;
	};


	// }}}USR
}
// }}}RME

// {{{RME operation 'getDeemphasisMode()'
bool MakoAudioOutputCtrl::getDeemphasisMode( void )
{
	// {{{USR

	return( getBitField(&m_MakoParent->m_imageArrayAudioReg[SREG4_5], MAKO_AUDIO_DEEMPH_BITFIELD ) );
	// }}}USR
}
// }}}RME

// {{{RME operation 'getG4PAGain()'
int MakoAudioOutputCtrl::getG4PAGain( void )
{
	// {{{USR

	unsigned int gainbits = 0;
	int gain = 0;

	// 1 = external, 0 = internal
	if ( getSpkrSelected() )
	{
	  gainbits = getBitField(&m_MakoParent->m_imageArrayAudioReg[SREG_PA], MAKO_AUDIO_G_SEL_E_BITFIELD );
	}
	else
	{
	  gainbits = getBitField(&m_MakoParent->m_imageArrayAudioReg[SREG_PA], MAKO_AUDIO_G_SEL_I_BITFIELD );
	}




	switch (gainbits)
	{
	  case 0:
	 
	     gain = 20;

	  break;

	  case 1:
	 
	     gain = 22;

	  break;

	  case 2:
	 
	     gain = 24;

	  break;

	  case 3:
	 
	     gain = 26;

	  break;

	 
	 
	  default:

	     gain = INVALID_VALUE_ERROR; // return invalid value, should never happen.
	 
	  break;
	};

	return gain;



	// }}}USR
}
// }}}RME

// {{{RME operation 'setG4PAGain(int)'
void MakoAudioOutputCtrl::setG4PAGain( int gain )
{
	// {{{USR
	unsigned int gainbits;

	switch (gain) // gain in db
	{
	  case 20:
	 
	     gainbits = 0;

	  break;

	  case 22:
	 
	     gainbits = 1;

	  break;

	  case 24:
	 
	     gainbits = 2;

	  break;

	  case 26:
	 
	     gainbits = 3;

	  break;

	 
	 
	  default:

	 
	  break;
	};


	// 1 = external, 0 = internal
	if ( getSpkrSelected() )
	{
	  setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG_PA], MAKO_AUDIO_G_SEL_E_BITFIELD, gainbits);
	}
	else
	{
	  setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG_PA], MAKO_AUDIO_G_SEL_I_BITFIELD, gainbits);
	}


	m_MakoParent->syncAudio();


	// }}}USR
}
// }}}RME

// {{{RME operation 'getG5AnalogGain()'
int MakoAudioOutputCtrl::getG5AnalogGain( void )
{
	// {{{USR
	int gainbits = 0;
	int gaindb = 0;

	gainbits = getBitField(&m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXA_BITFIELD );

	switch (gainbits)
	{
	  case 0:
	 
	     gaindb = -52;

	  break;

	  case 1:

	     gaindb = -46;
	  break;

	  case 2:

	     gaindb = -40;
	  break;

	  case 3:

	     gaindb = -38;

	  break;

	  case 4:

	     gaindb = -36;

	  break;

	   case 5:

	     gaindb = -34;

	  break;  

	 case 6:

	     gaindb = -32;

	  break;

	  case 7:

	     gaindb = -30;

	  break;

	  case 8:

	     gaindb = -28;

	  break;

	  case 9:

	     gaindb = -26;

	  break;

	  case 10:

	     gaindb = -24;

	  break;

	   case 11:

	     gaindb = -22;

	  break;   

	  case 12:

	     gaindb = -20;

	  break;

	  case 13:

	     gaindb = -18;

	  break;

	  case 14:

	     gaindb = -16;

	  break;

	  case 15:

	     gaindb = -14;

	  break;

	   case 16:

	     gaindb = -12;

	  break;  

	 case 17:

	     gaindb = -10;

	  break;

	  case 18:

	     gaindb = -8;

	  break;

	 case 19:

	     gaindb = -6;

	  break;

	   case 20:

	     gaindb = -4;

	  break;  

	 case 21:

	     gaindb = -2;

	  break;

	  case 22:

	     gaindb = 0;

	  break;
	 
	  default:

	     gaindb = INVALID_VALUE_ERROR; // return an invalid value
	 
	  break;
	};

	return gaindb;


	// }}}USR
}
// }}}RME

// {{{RME operation 'getMasterOnMode()'
bool MakoAudioOutputCtrl::getMasterOnMode( void )
{
	// {{{USR

	return( getBitField(&m_MakoParent->m_imageArrayAudioReg[SREG4_5], MAKO_AUDIO_MASTERON_BITFIELD ) );
	// }}}USR
}
// }}}RME

// {{{RME operation 'setMasterOnMode(bool)'
void MakoAudioOutputCtrl::setMasterOnMode( bool mode )
{
	// {{{USR

	setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG4_5], MAKO_AUDIO_MASTERON_BITFIELD, mode);


	m_MakoParent->syncAudio();
	   
	// }}}USR
}
// }}}RME

// {{{RME operation 'setStandbyMode(bool)'
void MakoAudioOutputCtrl::setStandbyMode( bool mode )
{
	// {{{USR



	setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG4_5], MAKO_AUDIO_STBY_BITFIELD, mode);


	m_MakoParent->syncAudio();

	// }}}USR
}
// }}}RME

// {{{RME operation 'setDeemphasisMode(bool)'
void MakoAudioOutputCtrl::setDeemphasisMode( bool mode )
{
	// {{{USR

	setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG4_5], MAKO_AUDIO_DEEMPH_BITFIELD, mode);

	m_MakoParent->syncAudio();
	// }}}USR
}
// }}}RME

// {{{RME operation 'getDigitalGain()'
int MakoAudioOutputCtrl::getDigitalGain( void )
{
	// {{{USR

	// Digital gain (RXD<2:0>) of the speaker is located in Mako register SREG 3
	// to convert the bits to db no extra work needs to be done since:
	// the Mako RXD values are binary: 000 = 0dB, 001 = 1db ... 110 = 6dB

	return ( getBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXD_BITFIELD) );
	// }}}USR
}
// }}}RME

// {{{RME operation 'setSpkrSelected(bool)'
void MakoAudioOutputCtrl::setSpkrSelected( bool device )
{
	// {{{USR


	// 1 = external, 0 = internal
	setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG_PA], MAKO_AUDIO_PA_SEL_BITFIELD, device);

	m_MakoParent->syncAudio();

	// }}}USR
}
// }}}RME

// {{{RME operation 'getSpkrSelected()'
bool MakoAudioOutputCtrl::getSpkrSelected( void )
{
	// {{{USR

	return( getBitField(&m_MakoParent->m_imageArrayAudioReg[SREG_PA], MAKO_AUDIO_PA_SEL_BITFIELD ) );
	// }}}USR
}
// }}}RME

// {{{RME operation 'getG3PreampGain()'
int MakoAudioOutputCtrl::getG3PreampGain( void )
{
	// {{{USR
	int gainbits = 0;

	int gaindb = 0;

	gainbits = getBitField(&m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXPA_BITFIELD );

	switch (gainbits)
	{
	  case 0:
	 
	     gaindb = 0;

	  break;

	  case 1:
	 
	     gaindb = 2;

	  break;

	  case 2:
	 
	     gaindb = 4;

	  break;

	  case 3:
	 
	     gaindb = 6;

	  break;

	  case 4:
	 
	     gaindb = 8;

	  break;

	   case 5:
	 
	     gaindb = 10;

	  break;  

	  
	  default:

	     gaindb = INVALID_VALUE_ERROR; // return an invalid value. this should never happen
	   
	  break;
	};

	return gaindb;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setG3PreampGain(int)'
void MakoAudioOutputCtrl::setG3PreampGain( int gain )
{
	// {{{USR

	switch (gain)
	{
	  case 0:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXPA_BITFIELD, 0);

	     m_MakoParent->syncAudio();

	  break;

	  case 2:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXPA_BITFIELD, 1);

	     m_MakoParent->syncAudio();

	  break;

	  case 4:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXPA_BITFIELD, 2);

	     m_MakoParent->syncAudio();

	  break;

	  case 6:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXPA_BITFIELD, 3);

	     m_MakoParent->syncAudio();

	  break;

	  case 8:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXPA_BITFIELD, 4);

	     m_MakoParent->syncAudio();

	  break;

	   case 10:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXPA_BITFIELD, 5);

	     m_MakoParent->syncAudio();

	  break;  

	 
	  default:

	 
	  break;
	};


	// }}}USR
}
// }}}RME

// {{{RME operation 'getLoopbackMode()'
bool MakoAudioOutputCtrl::getLoopbackMode( void )
{
	// {{{USR


	return( getBitField(&m_MakoParent->m_imageArrayAudioReg[SREG4_5], MAKO_AUDIO_CTR0_BITFIELD ) );
	// }}}USR
}
// }}}RME

// {{{RME operation 'setLoopbackMode(bool)'
void MakoAudioOutputCtrl::setLoopbackMode( bool mode )
{
	// {{{USR

	setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG4_5], MAKO_AUDIO_CTR0_BITFIELD, mode);

	m_MakoParent->syncAudio();
	// }}}USR
}
// }}}RME

// {{{RME operation 'setFilterType(bool)'
void MakoAudioOutputCtrl::setFilterType( bool type )
{
	// {{{USR


	setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG4_5], MAKO_AUDIO_RXBPLP_BITFIELD, type);

	m_MakoParent->syncAudio();
	// }}}USR
}
// }}}RME

// {{{RME operation 'setDigitalGain(int)'
void MakoAudioOutputCtrl::setDigitalGain( int gain )
{
	// {{{USR

	//integer gain values are same as bit settings, no translation necessary.
	setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_RXD_BITFIELD, gain);

	m_MakoParent->syncAudio();


	// }}}USR
}
// }}}RME

// {{{RME operation 'getFilterType()'
bool MakoAudioOutputCtrl::getFilterType( void )
{
	// {{{USR

	return( getBitField(&m_MakoParent->m_imageArrayAudioReg[SREG4_5], MAKO_AUDIO_RXBPLP_BITFIELD ) );
	// }}}USR
}
// }}}RME

// {{{RME operation 'getStandbyMode()'
bool MakoAudioOutputCtrl::getStandbyMode( void )
{
	// {{{USR


	return( getBitField(&m_MakoParent->m_imageArrayAudioReg[SREG4_5], MAKO_AUDIO_STBY_BITFIELD ) );
	// }}}USR
}
// }}}RME

// {{{RME operation 'setPAPowerState(int)'
void MakoAudioOutputCtrl::setPAPowerState( int state )
{
	// {{{USR

	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG_PA], MAKO_AUDIO_PA_MODE1_BITFIELD, 1);

	     switch (state)
	     {
	       case PA_STANDBY: // Standby mode, set PA_MODE1:1 and PA_MODE2:1 PA_SELECT:dont care

	         //this is done for MAKO P2 IC change

	         /*
	         When PA MODE is:
	         00 PA is in STBY mode.
	         01 PA stays in STBY (old MUTE mode)
	         10 PA is turned ON
	         11 PA stays ON.
	         */ 

	         setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG_PA], MAKO_AUDIO_PA_MODE1_BITFIELD, 0);

	         setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG_PA], MAKO_AUDIO_PA_MODE2_BITFIELD, 0);

	         m_MakoParent->syncAudio();

	       break;

	       case PA_ONUNMUTE: // On-unmute mode, set PA_MODE1:1 and PA_MODE2:0  PA_SELECT:dont care 

	         setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG_PA], MAKO_AUDIO_PA_MODE2_BITFIELD, 0);

	         m_MakoParent->syncAudio();
	   
	       break;

	       case PA_INTAUDIOON: // Internal audio path enabled mode, set PA_MODE1:dont care and PA_MODE2:dont care  PA_SELECT:0

	         setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG_PA], MAKO_AUDIO_PA_SEL_BITFIELD, 0);

	         m_MakoParent->syncAudio();
	   
	       break;

	       case PA_EXTAUDIOON: // External audio path enabled mode, set PA_MODE1:dont care and PA_MODE2:dont care  PA_SELECT:1

	         setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG_PA], MAKO_AUDIO_PA_SEL_BITFIELD, 1);

	         m_MakoParent->syncAudio();
	   
	       break;

	       default:
	                // ignore any other value
	       break;


	     }
	// }}}USR
}
// }}}RME

// {{{RME operation 'setCodecPowerState(int)'
void MakoAudioOutputCtrl::setCodecPowerState( int mode )
{
	// {{{USR
	     // the device in standby mode.
	     if( mode > 1 )
	     {
	     	setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG4_5], MAKO_AUDIO_STBY_BITFIELD, 0);
	        setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG4_5], MAKO_AUDIO_MASTERON_BITFIELD, 1);      
	     }
	     else
	     {
	        setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG4_5], MAKO_AUDIO_STBY_BITFIELD, mode);
	        setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG4_5], MAKO_AUDIO_MASTERON_BITFIELD, mode);      
	     }

		 m_MakoParent->syncAudio();

	// }}}USR
}
// }}}RME

// {{{RME operation 'MakoAudioOutputCtrl(Mako *)'
MakoAudioOutputCtrl::MakoAudioOutputCtrl( Mako * parent )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_MakoParent(parent)
	// }}}USR
	// }}}RME
{
	// {{{USR

	 
	  
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
