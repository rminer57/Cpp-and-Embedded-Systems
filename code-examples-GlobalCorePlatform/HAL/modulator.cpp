// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer_subcomponents::modulation::modulator'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "modulator.h"
#endif

#include <HALtestLib_win32.h>
#include <modulator.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'modulatorInterface_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'setModSensitivity(Integer,Integer)'
Integer modulator::setModSensitivity( Integer dev, Integer rfState )
{
	// {{{USR
	  Integer temp = currentModSensitivity[rfState];
	  currentModSensitivity[rfState] = dev;
	  return temp;  

	// }}}USR
}
// }}}RME

// {{{RME operation 'modulator(Integer)'
modulator::modulator( Integer numberOfRfStates )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	  currentModSensitivity = new Integer[numberOfRfStates];

	// }}}USR
}
// }}}RME

// {{{RME operation 'rfInterface(Integer,Integer*,Integer)'
Integer modulator::rfInterface( Integer opType, Integer * arguments, Integer numArguments )
{
	// {{{USR
	  // default return is 0
	  Integer returnVal = 0;
	  
	  switch(opType)
	  {
	    case OP_SET_RF_STATE:
	    {
	      // arg0   = rfState
	      // arg1-3 = UNUSED
	      // returns previous rf state
	      returnVal = setRFState(arguments[0]);
	      break;
	    }
	    case OP_SET_MOD_SENSITIVITY:
	    {
	      // arg0   = dev
	      // arg1   = rfState
	      // arg2-3 = UNUSED
	      // returns previous dev for selected rf state
	      returnVal = setModSensitivity(arguments[0], arguments[1]);
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

// {{{RME operation '~modulator()'
modulator::~modulator( void )
{
	// {{{USR
	  delete [] currentModSensitivity;

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'modulatorInterface_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
