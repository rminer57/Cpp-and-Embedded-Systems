// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer_subcomponents::synthesizer::synthesizer'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "synthesizer.h"
#endif

#include <HALtestLib_win32.h>
#include <synthesizer.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'synthInterface' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'getError(Integer)'
Integer synthesizer::getError( Integer rfState )
{
	// {{{USR
	  return 0;  // Indicate no error (physical devices may override as needed)

	// }}}USR
}
// }}}RME

// {{{RME operation 'getFrequency(Integer)'
Integer synthesizer::getFrequency( Integer rfState )
{
	// {{{USR
	  return frequency[rfState];

	// }}}USR
}
// }}}RME

// {{{RME operation 'rfInterface(Integer,Integer*,Integer)'
Integer synthesizer::rfInterface( Integer opType, Integer * arguments, Integer numArguments )
{
	// {{{USR
	  // default return is 0
	  Integer returnVal = 0;
	  
	  switch(opType)
	  {
	  case opSetRFState:
	    {
	      // arg0   = rfState
	      // arg1-3 = UNUSED
	      // returns previous rf state
	      returnVal = setRFState(arguments[0]);
	      break;
	    }
	  case opGetFrequency:
	    {
	      // arg0   = rfState
	      // arg1-3 = UNUSED
	      // returns current frequency for selected rf state
	      returnVal = getFrequency(arguments[0]);
	      break;
	    }
	  case opGetError:
	    {
	      // arg0   = rfState
	      // arg1-3 = UNUSED
	      // returns current error for selected rf state
	      returnVal = getError(arguments[0]);
	      break;
	    }
	  case opSetFrequency:
	    {
	      // arg0 = frequency
	      // arg1 = rfState
	      // arg2 = res 
	      // arg3 = fref
	      // returns previous frequency for selected rf state
	      // if only three parameters supplied, then disable the fref override parameter
	      returnVal = setSynthFrequency(arguments[0], arguments[1], arguments[2], arguments[3]);
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

// {{{RME operation 'setSynthFrequency(int32_t,int16_t,int32_t,int32_t)'
int32_t synthesizer::setSynthFrequency( int32_t freq, int16_t rfState, int32_t res, int32_t fref )
{
	// {{{USR
	  int temp = frequency[rfState];
	  frequency[rfState] = freq;
	  return temp;

	// }}}USR
}
// }}}RME

// {{{RME operation 'synthesizer(Integer)'
synthesizer::synthesizer( Integer numOfRfStates )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	  frequency = new Integer[numOfRfStates];

	// }}}USR
}
// }}}RME

// {{{RME operation '~synthesizer()'
synthesizer::~synthesizer( void )
{
	// {{{USR
	  delete [] frequency;

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'synthInterface' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
