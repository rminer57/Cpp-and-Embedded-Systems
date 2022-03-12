// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoAudioInputCtrl'

#ifndef MakoAudioInputCtrl_H
#define MakoAudioInputCtrl_H

#ifdef PRAGMA
#pragma interface "MakoAudioInputCtrl.h"
#endif

#include <HALtestLib_win32.h>
class Mako;
class MakoPrivateBitfieldsReg3;
class bitfield;
class rf_audio_std_types;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>


// }}}USR
// }}}RME

class MakoAudioInputCtrl
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
	// {{{RME classAttribute 'm_MakoParent'
	Mako * m_MakoParent;
	// }}}RME

public:
	// {{{RME classAttribute 'DIGITAL_GAIN_MAX'
	static const int DIGITAL_GAIN_MAX;
	// }}}RME
	// {{{RME classAttribute 'DIGITAL_GAIN_MIN'
	static const int DIGITAL_GAIN_MIN;
	// }}}RME
	// {{{RME classAttribute 'DIGITAL_GAIN_STEPSIZE'
	static const int DIGITAL_GAIN_STEPSIZE;
	// }}}RME
	// {{{RME classAttribute 'ANALOG_G1_GAIN_MAX'
	static const int ANALOG_G1_GAIN_MAX;
	// }}}RME
	// {{{RME classAttribute 'ANALOG_G1_GAIN_MIN'
	static const int ANALOG_G1_GAIN_MIN;
	// }}}RME
	// {{{RME classAttribute 'ANALOG_G1_GAIN_STEPSIZE'
	static const int ANALOG_G1_GAIN_STEPSIZE;
	// }}}RME
	// {{{RME classAttribute 'ANALOG_G2_GAIN_MAX'
	static const int ANALOG_G2_GAIN_MAX;
	// }}}RME
	// {{{RME classAttribute 'ANALOG_G2_GAIN_MIN'
	static const int ANALOG_G2_GAIN_MIN;
	// }}}RME
	// {{{RME classAttribute 'ANALOG_G2_GAIN_STEPSIZE'
	static const int ANALOG_G2_GAIN_STEPSIZE;
	// }}}RME
	// {{{RME classAttribute 'G1G2_MUTE_CONSTANT'
	static const int G1G2_MUTE_CONSTANT;
	// }}}RME
	// {{{RME operation '~MakoAudioInputCtrl()'
	~MakoAudioInputCtrl( void );
	// }}}RME
	// {{{RME operation 'MakoAudioInputCtrl(Mako *,uint32_t,uint32_t,uint32_t)'
	MakoAudioInputCtrl( Mako * parent, uint32_t sreg123, uint32_t sreg45, uint32_t sregPA );
	// }}}RME
	// {{{RME operation 'getDigitalGain()'
	int getDigitalGain( void );
	// }}}RME
	// {{{RME operation 'setMicSelected(bool)'
	void setMicSelected( bool device );
	// }}}RME
	// {{{RME operation 'getMicSelected()'
	bool getMicSelected( void );
	// }}}RME
	// {{{RME operation 'getG2Gain()'
	int getG2Gain( void );
	// }}}RME
	// {{{RME operation 'getG1Gain()'
	int getG1Gain( void );
	// }}}RME
	// {{{RME operation 'setG1Gain(int)'
	void setG1Gain( int gain );
	// }}}RME
	// {{{RME operation 'setG2Gain(int)'
	void setG2Gain( int gain );
	// }}}RME
	// {{{RME operation 'setFilterType(bool)'
	void setFilterType( bool type );
	// }}}RME
	// {{{RME operation 'setDigitalGain(int)'
	void setDigitalGain( int gain );
	// }}}RME
	// {{{RME operation 'getFilterType()'
	bool getFilterType( void );
	// }}}RME
	// {{{RME operation 'setMicBias(bool)'
	void setMicBias( bool state );
	// }}}RME
	// {{{RME operation 'MakoAudioInputCtrl(Mako *)'
	MakoAudioInputCtrl( Mako * parent );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* MakoAudioInputCtrl_H */

// }}}RME
