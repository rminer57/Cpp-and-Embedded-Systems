// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer_subcomponents::bbp_control::bbpControl'

#ifndef bbpControl_H
#define bbpControl_H

#ifdef PRAGMA
#pragma interface "bbpControl.h"
#endif

#include <HALtestLib_win32.h>
#include <rfBaseClass.h>
#include <rf_audio_std_types.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'bbpControlInterface_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class bbpControl : public rfBaseClass
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
	// {{{RME classifier 'bbpControlInterface_t'
	enum bbpControlInterface_t
	{
		OP_SET_RFSTATE = 0
	  , OP_SET_FREQUENCY
	};
	// }}}RME

private:
	// {{{RME classAttribute 'frequency'
	Integer * frequency;
	// }}}RME

public:
	// {{{RME operation 'bbpControl(Integer)'
	bbpControl( Integer numberOfRfStates );
	// }}}RME
	// {{{RME operation 'rfInterface(Integer,Integer*,Integer)'
	Integer rfInterface( Integer opType, Integer * arguments, Integer numArguments );
	// }}}RME
	// {{{RME operation 'setBBPFrequency(Integer,Integer)'
	virtual Integer setBBPFrequency( Integer freq, Integer rfState );
	// }}}RME
	// {{{RME operation '~bbpControl()'
	virtual ~bbpControl( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'bbpControlInterface_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* bbpControl_H */

// }}}RME
