// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer_subcomponents::modulation::modulationAttenuator'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "modulationAttenuator.h"
#endif

#include <HALtestLib_win32.h>
#include <modulationAttenuator.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'modAttenInterface_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'setModAttenuation(Integer,Integer,Integer)'
Integer modulationAttenuator::setModAttenuation( Integer attenuation, Integer rfState, Integer parm1 )
{
	// {{{USR
	  int temp = currentAttenuation[rfState];
	  currentAttenuation[rfState] = attenuation;
	  return temp;  

	// }}}USR
}
// }}}RME

// {{{RME operation 'modulationAttenuator(Integer)'
modulationAttenuator::modulationAttenuator( Integer numberOfRfStates )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	  currentAttenuation = new Integer[numberOfRfStates];

	// }}}USR
}
// }}}RME

// {{{RME operation 'rfInterface(Integer,Integer*,Integer)'
Integer modulationAttenuator::rfInterface( Integer opType, Integer * arguments, Integer numArguments )
{
	// {{{USR
	  // default return is 0
	  int returnVal = 0;
	  
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
	  case OP_SET_MOD_ATTENUATION:
	    {
	      // arg0 = attenuation
	      // arg1 = rfState
	      // arg2 = param1
	      // arg3 = UNUSED
	      // returns previous attenuation for current rf state
	      returnVal = setModAttenuation(arguments[0], arguments[1], arguments[2]); 
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

// {{{RME operation '~modulationAttenuator()'
modulationAttenuator::~modulationAttenuator( void )
{
	// {{{USR
	  delete currentAttenuation;

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'modAttenInterface_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
