// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer_subcomponents::power_control::powerControl'

#ifndef powerControl_H
#define powerControl_H

#ifdef PRAGMA
#pragma interface "powerControl.h"
#endif

#include <rf_sequencer_comp.h>
#include <rfBaseClass.h>
#include <rf_audio_std_types.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'powerControlInterface_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class powerControl : public rfBaseClass
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
	// {{{RME classifier 'powerControlInterface_t'
	enum powerControlInterface_t
	{
		OP_SET_RFSTATE = 0
	  , OP_SET_POWER_LEVEL
	};
	// }}}RME
	// {{{RME classAttribute 'currentPowerLevels'
	Integer * currentPowerLevels;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	powerControl( void );
	// }}}RME
	// {{{RME operation 'powerControl(Integer)'
	powerControl( Integer numberOfRfStates );
	// }}}RME
	// {{{RME operation 'setPowerLevel(Integer,Integer)'
	virtual Integer setPowerLevel( Integer level, Integer rfState );
	// }}}RME
	// {{{RME operation 'rfInterface(Integer,Integer*,Integer)'
	Integer rfInterface( Integer opType, Integer * arguments, Integer numArguments );
	// }}}RME
	// {{{RME operation '~powerControl()'
	virtual ~powerControl( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'powerControlInterface_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* powerControl_H */

// }}}RME
