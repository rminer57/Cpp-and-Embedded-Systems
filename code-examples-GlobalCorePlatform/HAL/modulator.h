// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer_subcomponents::modulation::modulator'

#ifndef modulator_H
#define modulator_H

#ifdef PRAGMA
#pragma interface "modulator.h"
#endif

#include <HALtestLib_win32.h>
#include <rfBaseClass.h>
#include <rf_audio_std_types.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'modulatorInterface_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class modulator : public rfBaseClass
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
	// {{{RME classifier 'modulatorInterface_t'
	enum modulatorInterface_t
	{
		OP_SET_RF_STATE = 0
	  , OP_SET_MOD_SENSITIVITY
	};
	// }}}RME
	// {{{RME classAttribute 'currentModSensitivity'
	Integer * currentModSensitivity;
	// }}}RME

public:
	// {{{RME operation 'setModSensitivity(Integer,Integer)'
	virtual Integer setModSensitivity( Integer dev, Integer rfState );
	// }}}RME
	// {{{RME operation 'modulator(Integer)'
	modulator( Integer numberOfRfStates );
	// }}}RME
	// {{{RME operation 'rfInterface(Integer,Integer*,Integer)'
	Integer rfInterface( Integer opType, Integer * arguments, Integer numArguments );
	// }}}RME
	// {{{RME operation '~modulator()'
	virtual ~modulator( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'modulatorInterface_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* modulator_H */

// }}}RME
