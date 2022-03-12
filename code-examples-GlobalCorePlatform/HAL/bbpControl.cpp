// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer_subcomponents::bbp_control::bbpControl'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "bbpControl.h"
#endif

#include <HALtestLib_win32.h>
#include <bbpControl.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'bbpControlInterface_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'bbpControl(Integer)'
bbpControl::bbpControl( Integer numberOfRfStates )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	  frequency = new Integer[numberOfRfStates];

	// }}}USR
}
// }}}RME

// {{{RME operation 'rfInterface(Integer,Integer*,Integer)'
Integer bbpControl::rfInterface( Integer opType, Integer * arguments, Integer numArguments )
{
	// {{{USR
	  // default return is 0
	  Integer returnVal = 0;
	  
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
	    case OP_SET_FREQUENCY:
	    {
	      // arg0   = freq
	      // arg1   = rfState
	      // arg2-3 = UNUSED
	      // returns the previous ssi frequency
	      returnVal = setBBPFrequency(arguments[0], arguments[1]);
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

// {{{RME operation 'setBBPFrequency(Integer,Integer)'
Integer bbpControl::setBBPFrequency( Integer freq, Integer rfState )
{
	// {{{USR
	  Integer previousFreq = frequency[rfState];
	  frequency[rfState] = freq;
	  return previousFreq;

	// }}}USR
}
// }}}RME

// {{{RME operation '~bbpControl()'
bbpControl::~bbpControl( void )
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
// {{{RME classifier 'bbpControlInterface_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
