// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer_subcomponents::gain_control::gainControl'

#ifndef gainControl_H
#define gainControl_H

#ifdef PRAGMA
#pragma interface "gainControl.h"
#endif

#include <HALtestLib_win32.h>
#include <rfBaseClass.h>
#include <rf_audio_std_types.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'gainControlInterface_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class gainControl : public rfBaseClass
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

public:
	// {{{RME classifier 'gainControlInterface_t'
	enum gainControlInterface_t
	{
		OP_SET_RFSTATE = 0
	  , OP_SET_GAIN
	};
	// }}}RME

private:
	// {{{RME classAttribute 'numberOfGains'
	Integer numberOfGains;
	// }}}RME
	// {{{RME classAttribute 'currentGains'
	Integer * * currentGains;
	// }}}RME

public:
	// {{{RME operation 'gainControl(Integer,Integer,Integer)'
	gainControl( Integer numOfGains, Integer numOfRfStates, Integer initGain );
	// }}}RME
	// {{{RME operation 'setGain(Integer,Integer,Integer)'
	virtual Integer setGain( Integer gainNumber, Integer gain, Integer rfState );
	// }}}RME
	// {{{RME operation '~gainControl()'
	virtual ~gainControl( void );
	// }}}RME
	// {{{RME operation 'rfInterface(Integer,Integer*,Integer)'
	Integer rfInterface( Integer opType, Integer * arguments, Integer numArguments );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'gainControlInterface_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* gainControl_H */

// }}}RME
