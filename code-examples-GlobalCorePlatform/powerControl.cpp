// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer_subcomponents::power_control::powerControl'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "powerControl.h"
#endif

#include <rf_sequencer_comp.h>
#include <powerControl.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'powerControlInterface_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
powerControl::powerControl( void )
{
}
// }}}RME

// {{{RME operation 'powerControl(Integer)'
powerControl::powerControl( Integer numberOfRfStates )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	  currentPowerLevels = new Integer[numberOfRfStates];

	// }}}USR
}
// }}}RME

// {{{RME operation 'setPowerLevel(Integer,Integer)'
Integer powerControl::setPowerLevel( Integer level, Integer rfState )
{
	// {{{USR
	  int temp = currentPowerLevels[rfState];
	  currentPowerLevels[rfState] = level;
	  return temp;    
	// }}}USR
}
// }}}RME

// {{{RME operation 'rfInterface(Integer,Integer*,Integer)'
Integer powerControl::rfInterface( Integer opType, Integer * arguments, Integer numArguments )
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
	  case OP_SET_POWER_LEVEL:
	    {
	      // arg0   = level
	      // arg1   = rfState
	      // arg2-3 = UNUSED
	      // returns previous power level for selected rf state
	      returnVal = setPowerLevel(arguments[0], arguments[1]);
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

// {{{RME operation '~powerControl()'
powerControl::~powerControl( void )
{
	// {{{USR
	  delete [] currentPowerLevels;

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'powerControlInterface_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
