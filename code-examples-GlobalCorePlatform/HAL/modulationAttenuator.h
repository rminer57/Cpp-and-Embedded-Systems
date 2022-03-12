// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer_subcomponents::modulation::modulationAttenuator'

#ifndef modulationAttenuator_H
#define modulationAttenuator_H

#ifdef PRAGMA
#pragma interface "modulationAttenuator.h"
#endif

#include <HALtestLib_win32.h>
#include <rfBaseClass.h>
#include <rf_audio_std_types.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'modAttenInterface_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class modulationAttenuator : public rfBaseClass
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
	// {{{RME classifier 'modAttenInterface_t'
	enum modAttenInterface_t
	{
		OP_SET_RF_STATE = 0
	  , OP_SET_MOD_ATTENUATION
	};
	// }}}RME
	// {{{RME classAttribute 'currentAttenuation'
	Integer * currentAttenuation;
	// }}}RME

public:
	// {{{RME operation 'setModAttenuation(Integer,Integer,Integer)'
	virtual Integer setModAttenuation( Integer attenuation, Integer rfState, Integer parm1 );
	// }}}RME
	// {{{RME operation 'modulationAttenuator(Integer)'
	modulationAttenuator( Integer numberOfRfStates );
	// }}}RME
	// {{{RME operation 'rfInterface(Integer,Integer*,Integer)'
	Integer rfInterface( Integer opType, Integer * arguments, Integer numArguments );
	// }}}RME
	// {{{RME operation '~modulationAttenuator()'
	virtual ~modulationAttenuator( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'modAttenInterface_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* modulationAttenuator_H */

// }}}RME
