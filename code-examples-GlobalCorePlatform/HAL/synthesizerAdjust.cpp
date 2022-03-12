// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer_subcomponents::synthesizer::synthesizerAdjust'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "synthesizerAdjust.h"
#endif

#include <HALtestLib_win32.h>
#include <synthesizerAdjust.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'synthAdjustInterface' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'rfInterface(Integer,Integer*,Integer)'
Integer synthesizerAdjust::rfInterface( Integer opType, Integer * arguments, Integer numArguments )
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
	  case opSetWarp:
	    {
	      // arg0   = warp
	      // arg1   = rfState
	      // arg2-3 = UNUSED
	      // returns previous warp adjustment for current rf state
	      returnVal = setWarp(arguments[0], arguments[1]);
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

// {{{RME operation 'setWarp(Integer,Integer)'
Integer synthesizerAdjust::setWarp( Integer warp, Integer rfState )
{
	// {{{USR
	  Integer temp = currentWarp[rfState];
	  currentWarp[rfState] = warp;
	  return temp;

	// }}}USR
}
// }}}RME

// {{{RME operation 'synthesizerAdjust(Integer)'
synthesizerAdjust::synthesizerAdjust( Integer numOfRfStates )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	  currentWarp = new Integer[numOfRfStates];

	// }}}USR
}
// }}}RME

// {{{RME operation '~synthesizerAdjust()'
synthesizerAdjust::~synthesizerAdjust( void )
{
	// {{{USR
	  delete currentWarp;

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'synthAdjustInterface' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
