// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer_subcomponents::power_control::powerAmplifier'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "powerAmplifier.h"
#endif

#include <HALtestLib_win32.h>
#include <powerAmplifier.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'powerAmplifierInterface_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'PA_INIT_VALUE'
const Integer powerAmplifier::PA_INIT_VALUE( 0 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
powerAmplifier::powerAmplifier( void )
{
}
// }}}RME

// {{{RME operation 'powerAmplifier(Integer)'
powerAmplifier::powerAmplifier( Integer numberOfRfStates )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	  currentPAstates = new Integer[numberOfRfStates];
	  for(Integer initIndex=0; initIndex < numberOfRfStates; initIndex++)
	  {
	    currentPAstates[initIndex] = PA_INIT_VALUE;
	  }
	  numRfStates = numberOfRfStates;

	// }}}USR
}
// }}}RME

// {{{RME operation 'setPA(Integer,Integer)'
Integer powerAmplifier::setPA( Integer paState, Integer rfState )
{
	// {{{USR
	  Integer temp = currentPAstates[rfState];
	  currentPAstates[rfState] = paState;
	  return temp;  

	// }}}USR
}
// }}}RME

// {{{RME operation 'rfInterface(Integer,Integer*,Integer)'
Integer powerAmplifier::rfInterface( Integer opType, Integer * arguments, Integer numArguments )
{
	// {{{USR
	  // default return is 0
	  int returnVal = 0;
	  
	  switch(opType)
	  {
	  case OP_SET_RFSTATE:
	    {
	      // arg0   = rfState
	      // arg1-3 = UNUSED
	      // returns previous rf state
	      returnVal = setRFState(arguments[0]);
	      break;
	    }
	  case OP_SET_PA:
	    {
	      // arg0   = paState
	      // arg1   = rfState
	      // arg2-3 = UNUSED
	      // returns previous power amplifier state for selected rf state
	      returnVal = setPA(arguments[0], arguments[1]);  
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

// {{{RME operation '~powerAmplifier()'
powerAmplifier::~powerAmplifier( void )
{
	// {{{USR
	  delete [] currentPAstates;

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'powerAmplifierInterface_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
