// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer_subcomponents::power_control::powerAmplifier'

#ifndef powerAmplifier_H
#define powerAmplifier_H

#ifdef PRAGMA
#pragma interface "powerAmplifier.h"
#endif

#include <rf_sequencer_comp.h>
#include <rfBaseClass.h>
#include <rf_audio_std_types.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'powerAmplifierInterface_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class powerAmplifier : public rfBaseClass
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
	// {{{RME classifier 'powerAmplifierInterface_t'
	enum powerAmplifierInterface_t
	{
		OP_SET_RFSTATE = 0
	  , OP_SET_PA
	};
	// }}}RME
	// {{{RME classAttribute 'currentPAstates'
	Integer * currentPAstates;
	// }}}RME
	// {{{RME classAttribute 'numRfStates'
	Integer numRfStates;
	// }}}RME
	// {{{RME classAttribute 'PA_INIT_VALUE'
	static const Integer PA_INIT_VALUE;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	powerAmplifier( void );
	// }}}RME
	// {{{RME operation 'powerAmplifier(Integer)'
	powerAmplifier( Integer numberOfRfStates );
	// }}}RME
	// {{{RME operation 'setPA(Integer,Integer)'
	virtual Integer setPA( Integer paState, Integer rfState );
	// }}}RME
	// {{{RME operation 'rfInterface(Integer,Integer*,Integer)'
	virtual Integer rfInterface( Integer opType, Integer * arguments, Integer numArguments );
	// }}}RME
	// {{{RME operation '~powerAmplifier()'
	virtual ~powerAmplifier( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'powerAmplifierInterface_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* powerAmplifier_H */

// }}}RME
