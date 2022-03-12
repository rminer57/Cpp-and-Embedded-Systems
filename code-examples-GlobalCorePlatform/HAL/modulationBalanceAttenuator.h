// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer_subcomponents::modulation::modulationBalanceAttenuator'

#ifndef modulationBalanceAttenuator_H
#define modulationBalanceAttenuator_H

#ifdef PRAGMA
#pragma interface "modulationBalanceAttenuator.h"
#endif

#include <HALtestLib_win32.h>
#include <rfBaseClass.h>
#include <rf_audio_std_types.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'modBalanceAttenInterface_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class modulationBalanceAttenuator : public rfBaseClass
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
	// {{{RME classifier 'modBalanceAttenInterface_t'
	enum modBalanceAttenInterface_t
	{
		OP_SET_RF_STATE = 0
	  , OP_SET_MOD_BALANCE
	};
	// }}}RME
	// {{{RME classAttribute 'currentModBalance'
	Integer * currentModBalance;
	// }}}RME

public:
	// {{{RME operation 'setModBalance(Integer,Integer)'
	virtual Integer setModBalance( Integer attenuation, Integer rfState );
	// }}}RME
	// {{{RME operation 'modulationBalanceAttenuator(Integer)'
	modulationBalanceAttenuator( Integer numberOfRfStates );
	// }}}RME
	// {{{RME operation 'rfInterface(Integer,Integer*,Integer)'
	Integer rfInterface( Integer opType, Integer * arguments, Integer numArguments );
	// }}}RME
	// {{{RME operation '~modulationBalanceAttenuator()'
	virtual ~modulationBalanceAttenuator( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'modBalanceAttenInterface_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* modulationBalanceAttenuator_H */

// }}}RME
