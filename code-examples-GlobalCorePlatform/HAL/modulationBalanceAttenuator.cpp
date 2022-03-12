// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer_subcomponents::modulation::modulationBalanceAttenuator'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "modulationBalanceAttenuator.h"
#endif

#include <HALtestLib_win32.h>
#include <modulationBalanceAttenuator.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'modBalanceAttenInterface_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'setModBalance(Integer,Integer)'
Integer modulationBalanceAttenuator::setModBalance( Integer attenuation, Integer rfState )
{
	// {{{USR
	  Integer temp = currentModBalance[rfState];
	  currentModBalance[rfState] = attenuation;
	  return temp;  

	// }}}USR
}
// }}}RME

// {{{RME operation 'modulationBalanceAttenuator(Integer)'
modulationBalanceAttenuator::modulationBalanceAttenuator( Integer numberOfRfStates )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	  currentModBalance = new Integer[numberOfRfStates];

	// }}}USR
}
// }}}RME

// {{{RME operation 'rfInterface(Integer,Integer*,Integer)'
Integer modulationBalanceAttenuator::rfInterface( Integer opType, Integer * arguments, Integer numArguments )
{
	// {{{USR
	  // default return is 0
	  Integer returnVal = 0;
	  
	  switch (opType) 
	  {
	    case OP_SET_RF_STATE:
	    {
	      // arg0   = rfState
	      // arg1-3 = UNUSED
	      // returns previous rf state
	      returnVal = setRFState(arguments[0]); 
	      break; 
	    }
	    case OP_SET_MOD_BALANCE:
	    {
	      // arg0   = attenuation
	      // arg1   = rfState
	      // arg2-3 = UNUSED
	      // returns previous attenuation for current rf state
	      returnVal = setModBalance(arguments[0], arguments[1]); 
	      break; 
	    }
	    default: 
	    {
	      break; 
	    }
	  }

	  return returnVal;  

	// }}}USR
}
// }}}RME

// {{{RME operation '~modulationBalanceAttenuator()'
modulationBalanceAttenuator::~modulationBalanceAttenuator( void )
{
	// {{{USR
	  delete [] currentModBalance;

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'modBalanceAttenInterface_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
