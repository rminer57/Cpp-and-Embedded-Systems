// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoAudioOutputCtrl'

#ifndef MakoAudioOutputCtrl_H
#define MakoAudioOutputCtrl_H

#ifdef PRAGMA
#pragma interface "MakoAudioOutputCtrl.h"
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

class MakoAudioOutputCtrl
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
	// {{{RME classAttribute 'DIGITAL_GAIN_STEPSIZE'
	static const int DIGITAL_GAIN_STEPSIZE;
	// }}}RME
	// {{{RME classAttribute 'DIGITAL_GAIN_MIN'
	static const int DIGITAL_GAIN_MIN;
	// }}}RME
	// {{{RME classAttribute 'DIGITAL_GAIN_MAX'
	static const int DIGITAL_GAIN_MAX;
	// }}}RME
	// {{{RME classAttribute 'ANALOG_G5_GAIN_MAX'
	static const int ANALOG_G5_GAIN_MAX;
	// }}}RME
	// {{{RME classAttribute 'ANALOG_G5_GAIN_MIN'
	static const int ANALOG_G5_GAIN_MIN;
	// }}}RME
	// {{{RME classAttribute 'PREAMP_G3_GAIN_MAX'
	static const int PREAMP_G3_GAIN_MAX;
	// }}}RME
	// {{{RME classAttribute 'PREAMP_G3_GAIN_MIN'
	static const int PREAMP_G3_GAIN_MIN;
	// }}}RME
	// {{{RME classAttribute 'PREAMP_G3_GAIN_STEPSIZE'
	static const int PREAMP_G3_GAIN_STEPSIZE;
	// }}}RME
	// {{{RME classAttribute 'PWRAMP_G4_GAIN_MAX'
	static const int PWRAMP_G4_GAIN_MAX;
	// }}}RME
	// {{{RME classAttribute 'PWRAMP_G4_GAIN_MIN'
	static const int PWRAMP_G4_GAIN_MIN;
	// }}}RME
	// {{{RME classAttribute 'PWRAMP_G4_GAIN_STEPSIZE'
	static const int PWRAMP_G4_GAIN_STEPSIZE;
	// }}}RME
	// {{{RME classAttribute 'PA_STANDBY'
	static const int PA_STANDBY;
	// }}}RME
	// {{{RME classAttribute 'PA_ONUNMUTE'
	static const int PA_ONUNMUTE;
	// }}}RME
	// {{{RME classAttribute 'PA_INTAUDIOON'
	static const int PA_INTAUDIOON;
	// }}}RME
	// {{{RME classAttribute 'PA_EXTAUDIOON'
	static const int PA_EXTAUDIOON;
	// }}}RME
	// {{{RME operation 'MakoAudioOutputCtrl(Mako *,uint32_t,uint32_t,uint32_t)'
	MakoAudioOutputCtrl( Mako * parent, uint32_t sreg123, uint32_t sreg45, uint32_t sregPA );
	// }}}RME
	// {{{RME operation '~MakoAudioOutputCtrl()'
	~MakoAudioOutputCtrl( void );
	// }}}RME
	// {{{RME operation 'setG5AnalogGain(int)'
	void setG5AnalogGain( int gain );
	// }}}RME
	// {{{RME operation 'getDeemphasisMode()'
	bool getDeemphasisMode( void );
	// }}}RME
	// {{{RME operation 'getG4PAGain()'
	int getG4PAGain( void );
	// }}}RME
	// {{{RME operation 'setG4PAGain(int)'
	void setG4PAGain( int gain );
	// }}}RME
	// {{{RME operation 'getG5AnalogGain()'
	int getG5AnalogGain( void );
	// }}}RME
	// {{{RME operation 'getMasterOnMode()'
	bool getMasterOnMode( void );
	// }}}RME
	// {{{RME operation 'setMasterOnMode(bool)'
	void setMasterOnMode( bool mode );
	// }}}RME
	// {{{RME operation 'setStandbyMode(bool)'
	void setStandbyMode( bool mode );
	// }}}RME
	// {{{RME operation 'setDeemphasisMode(bool)'
	void setDeemphasisMode( bool mode );
	// }}}RME
	// {{{RME operation 'getDigitalGain()'
	int getDigitalGain( void );
	// }}}RME
	// {{{RME operation 'setSpkrSelected(bool)'
	void setSpkrSelected( bool device );
	// }}}RME
	// {{{RME operation 'getSpkrSelected()'
	bool getSpkrSelected( void );
	// }}}RME
	// {{{RME operation 'getG3PreampGain()'
	int getG3PreampGain( void );
	// }}}RME
	// {{{RME operation 'setG3PreampGain(int)'
	void setG3PreampGain( int gain );
	// }}}RME
	// {{{RME operation 'getLoopbackMode()'
	bool getLoopbackMode( void );
	// }}}RME
	// {{{RME operation 'setLoopbackMode(bool)'
	void setLoopbackMode( bool mode );
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
	// {{{RME operation 'getStandbyMode()'
	bool getStandbyMode( void );
	// }}}RME
	// {{{RME operation 'setPAPowerState(int)'
	void setPAPowerState( int state );
	// }}}RME
	// {{{RME operation 'setCodecPowerState(int)'
	void setCodecPowerState( int mode );
	// }}}RME
	// {{{RME operation 'MakoAudioOutputCtrl(Mako *)'
	MakoAudioOutputCtrl( Mako * parent );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* MakoAudioOutputCtrl_H */

// }}}RME
