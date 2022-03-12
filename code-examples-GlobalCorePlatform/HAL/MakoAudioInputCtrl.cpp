// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoAudioInputCtrl'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "MakoAudioInputCtrl.h"
#endif

#include <HALtestLib_win32.h>
#include <MakoAudioInputCtrl.h>
#include <Mako.h>
#include <MakoPrivateBitfieldsReg3.h>
#include <bitfield.h>
#include <rf_audio_std_types.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'DIGITAL_GAIN_MAX'
const int MakoAudioInputCtrl::DIGITAL_GAIN_MAX( 1 );
// }}}RME

// {{{RME classAttribute 'DIGITAL_GAIN_MIN'
const int MakoAudioInputCtrl::DIGITAL_GAIN_MIN( 0 );
// }}}RME

// {{{RME classAttribute 'DIGITAL_GAIN_STEPSIZE'
const int MakoAudioInputCtrl::DIGITAL_GAIN_STEPSIZE( 1 );
// }}}RME

// {{{RME classAttribute 'ANALOG_G1_GAIN_MAX'
const int MakoAudioInputCtrl::ANALOG_G1_GAIN_MAX( 45 );
// }}}RME

// {{{RME classAttribute 'ANALOG_G1_GAIN_MIN'
const int MakoAudioInputCtrl::ANALOG_G1_GAIN_MIN( 0 );
// }}}RME

// {{{RME classAttribute 'ANALOG_G1_GAIN_STEPSIZE'
const int MakoAudioInputCtrl::ANALOG_G1_GAIN_STEPSIZE( 15 );
// }}}RME

// {{{RME classAttribute 'ANALOG_G2_GAIN_MAX'
const int MakoAudioInputCtrl::ANALOG_G2_GAIN_MAX( 0 );
// }}}RME

// {{{RME classAttribute 'ANALOG_G2_GAIN_MIN'
const int MakoAudioInputCtrl::ANALOG_G2_GAIN_MIN( -30 );
// }}}RME

// {{{RME classAttribute 'ANALOG_G2_GAIN_STEPSIZE'
const int MakoAudioInputCtrl::ANALOG_G2_GAIN_STEPSIZE( 2 );
// }}}RME

// {{{RME classAttribute 'G1G2_MUTE_CONSTANT'
const int MakoAudioInputCtrl::G1G2_MUTE_CONSTANT( -9999 );
// }}}RME

// {{{RME operation '~MakoAudioInputCtrl()'
MakoAudioInputCtrl::~MakoAudioInputCtrl( void )
{
	// {{{USR

	m_MakoParent->m_ResourceAvailableAudioInput = true;

	// }}}USR
}
// }}}RME

// {{{RME operation 'MakoAudioInputCtrl(Mako *,uint32_t,uint32_t,uint32_t)'
MakoAudioInputCtrl::MakoAudioInputCtrl( Mako * parent, uint32_t sreg123, uint32_t sreg45, uint32_t sregPA )
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

// {{{RME operation 'getDigitalGain()'
int MakoAudioInputCtrl::getDigitalGain( void )
{
	// {{{USR

	uint32_t tempData = 0;

	// Digital gain (TXD<2:0>) of the Mic is located in Mako register SREG 3
	// Read register raw image.  
	tempData = m_MakoParent->m_imageArrayAudioReg[SREG1_3];

	// Extract the bits of interest.
	tempData = getBitField( &tempData, MAKO_AUDIO_TXD_BITFIELD);

	// to convert the bits to db, no extra work needs to be done because
	// the Mako TXD values are binary: 000 = 0dB, 001 = 1db

	return tempData;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setMicSelected(bool)'
void MakoAudioInputCtrl::setMicSelected( bool device )
{
	// {{{USR
	setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_MAINAUX_MIC_BITFIELD, device);

	m_MakoParent->syncAudio();
	// }}}USR
}
// }}}RME

// {{{RME operation 'getMicSelected()'
bool MakoAudioInputCtrl::getMicSelected( void )
{
	// {{{USR

	// Main/Aux setting of the mic is located in Mako register SREG 3
	return( getBitField(&m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_MAINAUX_MIC_BITFIELD ) );
	// }}}USR
}
// }}}RME

// {{{RME operation 'getG2Gain()'
int MakoAudioInputCtrl::getG2Gain( void )
{
	// {{{USR
	uint32_t tempData = 0;

	int retval =  INVALID_VALUE_ERROR;

	int binToGaindB[] = {G1G2_MUTE_CONSTANT, -30, -28, -26, -24, -22, -20, -18, -16, -14, -12, -10, -8, -6, -4, -2, 0 } ;

	// Digital gain (TXA<4:0>) of the mic is located in Mako register SREG 3
	// Read register raw image.  
	tempData = m_MakoParent->m_imageArrayAudioReg[SREG1_3];

	// Extract the bits of interest.
	tempData = getBitField( &tempData, MAKO_AUDIO_TXA_BITFIELD);

	if( tempData <= 16 ) // max valid indice in binToGaindB array
	{
	  // to convert the bit value to db
	  retval = binToGaindB[ tempData ];
	}

	return retval;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getG1Gain()'
int MakoAudioInputCtrl::getG1Gain( void )
{
	// {{{USR

	uint32_t tempData = 0;

	int retval =  INVALID_VALUE_ERROR;

	int binToGaindB[] = {G1G2_MUTE_CONSTANT, 0, 15, 30, 45 } ;

	// Digital gain (TXG<2:0>) of the mic is located in Mako register SREG 3
	// Read register raw image.  
	tempData = m_MakoParent->m_imageArrayAudioReg[SREG1_3];

	// Extract the bits of interest.
	tempData = getBitField( &tempData, MAKO_AUDIO_TXG_BITFIELD);

	if( tempData <= 4 ) // max valid indice in binToGaindB array
	{
	  // to convert the bits to db
	  retval = binToGaindB[ tempData ];
	}

	return retval;



	// }}}USR
}
// }}}RME

// {{{RME operation 'setG1Gain(int)'
void MakoAudioInputCtrl::setG1Gain( int gain )
{
	// {{{USR


	switch (gain)
	{

	   case G1G2_MUTE_CONSTANT:

	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_TXG_BITFIELD, 0);

	     m_MakoParent->syncAudio();

	   break;

	   case 0:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_TXG_BITFIELD, 1);

	     m_MakoParent->syncAudio();

	   break;

	   case 15:

	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_TXG_BITFIELD, 2);

	     m_MakoParent->syncAudio();

	   break;

	   case 30:

	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_TXG_BITFIELD, 3);

	     m_MakoParent->syncAudio();

	   break;

	   case 45:

	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_TXG_BITFIELD, 4);

	     m_MakoParent->syncAudio();

	   break;


	   default:

	   break;

	};

	// }}}USR
}
// }}}RME

// {{{RME operation 'setG2Gain(int)'
void MakoAudioInputCtrl::setG2Gain( int gain )
{
	// {{{USR
	switch (gain)
	{
	   case G1G2_MUTE_CONSTANT:

	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_TXA_BITFIELD, 0);

	     m_MakoParent->syncAudio();

	   break;
	 
	  case -30:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_TXA_BITFIELD, 1);

	     m_MakoParent->syncAudio();

	  break;

	  case -28:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_TXA_BITFIELD, 2);

	     m_MakoParent->syncAudio();

	  break;

	  case -26:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_TXA_BITFIELD, 3);

	     m_MakoParent->syncAudio();

	  break;

	  case -24:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_TXA_BITFIELD, 4);

	     m_MakoParent->syncAudio();

	  break;

	  case -22:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_TXA_BITFIELD, 5);

	     m_MakoParent->syncAudio();

	  break;

	   case -20:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_TXA_BITFIELD, 6);

	     m_MakoParent->syncAudio();

	  break;  

	  case -18:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_TXA_BITFIELD, 7);

	     m_MakoParent->syncAudio();

	  break;  

	  case -16:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_TXA_BITFIELD, 8);

	     m_MakoParent->syncAudio();

	  break;  

	  case -14:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_TXA_BITFIELD, 9);

	     m_MakoParent->syncAudio();

	  break;  

	  case -12:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_TXA_BITFIELD, 10);

	     m_MakoParent->syncAudio();

	  break;  

	  case -10:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_TXA_BITFIELD, 11);

	     m_MakoParent->syncAudio();

	  break;  

	  case -8:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_TXA_BITFIELD, 12);

	     m_MakoParent->syncAudio();

	  break;  

	 
	  case -6:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_TXA_BITFIELD, 13);

	     m_MakoParent->syncAudio();

	  break;  

	  case -4:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_TXA_BITFIELD, 14);

	     m_MakoParent->syncAudio();

	  break;  

	  case -2:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_TXA_BITFIELD, 15);

	     m_MakoParent->syncAudio();

	  break;  

	  case 0:
	 
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_TXA_BITFIELD, 16);

	     m_MakoParent->syncAudio();

	  break;  

	 
	  default:

	  break;
	};


	// }}}USR
}
// }}}RME

// {{{RME operation 'setFilterType(bool)'
void MakoAudioInputCtrl::setFilterType( bool type )
{
	// {{{USR


	setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG4_5], MAKO_AUDIO_TXBPLP_BITFIELD, type);


	m_MakoParent->syncAudio();

	// }}}USR
}
// }}}RME

// {{{RME operation 'setDigitalGain(int)'
void MakoAudioInputCtrl::setDigitalGain( int gain )
{
	// {{{USR

	//integer gain values are same as bit settings, no translation necessary.
	setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG1_3], MAKO_AUDIO_TXD_BITFIELD, gain);


	m_MakoParent->syncAudio();


	// }}}USR
}
// }}}RME

// {{{RME operation 'getFilterType()'
bool MakoAudioInputCtrl::getFilterType( void )
{
	// {{{USR

	return( getBitField(&m_MakoParent->m_imageArrayAudioReg[SREG4_5], MAKO_AUDIO_TXBPLP_BITFIELD ) );
	// }}}USR
}
// }}}RME

// {{{RME operation 'setMicBias(bool)'
void MakoAudioInputCtrl::setMicBias( bool state )
{
	// {{{USR

	     // the mic bias bit (D16 MIC_SET) is located in the PA register - write to this bit in the register image
	     setBitField( &m_MakoParent->m_imageArrayAudioReg[SREG_PA], MAKO_AUDIO_MIC_SET_BITFIELD, state);

		 m_MakoParent->syncAudio();
	// }}}USR
}
// }}}RME

// {{{RME operation 'MakoAudioInputCtrl(Mako *)'
MakoAudioInputCtrl::MakoAudioInputCtrl( Mako * parent )
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
