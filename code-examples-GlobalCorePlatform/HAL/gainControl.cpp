// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer_subcomponents::gain_control::gainControl'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "gainControl.h"
#endif

#include <HALtestLib_win32.h>
#include <gainControl.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'gainControlInterface_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'gainControl(Integer,Integer,Integer)'
gainControl::gainControl( Integer numOfGains, Integer numOfRfStates, Integer initGain )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	  numberOfGains = numOfGains;

	  // create gains array
	  currentGains = new Integer*[numberOfGains];

	  for(Integer i = 0; i < numberOfGains; i++)
	  {
	    currentGains[i] = new Integer[numOfRfStates];
	    
	    // initialize array 
	    for(Integer j = 0; j < numOfRfStates; j++)
	    {
	      currentGains[i][j] = initGain;
	    }
	  }

	// }}}USR
}
// }}}RME

// {{{RME operation 'setGain(Integer,Integer,Integer)'
Integer gainControl::setGain( Integer gainNumber, Integer gain, Integer rfState )
{
	// {{{USR
	  Integer previousGain = currentGains[gainNumber][rfState];
	  currentGains[gainNumber][rfState] = gain;
	  return previousGain;

	// }}}USR
}
// }}}RME

// {{{RME operation '~gainControl()'
gainControl::~gainControl( void )
{
	// {{{USR
	  // delete gains array
	  for(Integer i = 0; i < numberOfGains; i++)
	  {
	    delete currentGains[i];
	  }
	  delete currentGains;

	// }}}USR
}
// }}}RME

// {{{RME operation 'rfInterface(Integer,Integer*,Integer)'
Integer gainControl::rfInterface( Integer opType, Integer * arguments, Integer numArguments )
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
	    case OP_SET_GAIN:
	    {
	      // arg0 = gainNumber
	      // arg1 = gain
	      // arg2 = rfState
	      // arg3 = UNUSED
	      // returns the previous gain
	      returnVal = setGain(arguments[0], arguments[1], arguments[2]);
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

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'gainControlInterface_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
