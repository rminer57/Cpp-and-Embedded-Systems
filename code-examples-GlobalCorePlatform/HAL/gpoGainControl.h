// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::gpo_gain_control::gpoGainControl'

#ifndef gpoGainControl_H
#define gpoGainControl_H

#ifdef PRAGMA
#pragma interface "gpoGainControl.h"
#endif

#include <HALtestLib_win32.h>
#include <gainControl.h>
#include <rf_audio_std_types.h>
class generalPurposeOutput;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class gpoGainControl : public gainControl
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
	// {{{RME classAttribute 'gains'
	generalPurposeOutput * * gains;
	// }}}RME

public:
	// {{{RME operation 'gpoGainControl(generalPurposeOutput**,Integer,Integer,Integer)'
	gpoGainControl( generalPurposeOutput * * gainTable, Integer numOfGains, Integer numOfRfStates, Integer initialGain );
	// }}}RME
	// {{{RME operation 'setGain(Integer,Integer,Integer)'
	Integer setGain( Integer gainNumber, Integer gain, Integer rfState );
	// }}}RME
	// {{{RME operation '~gpoGainControl()'
	~gpoGainControl( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* gpoGainControl_H */

// }}}RME
