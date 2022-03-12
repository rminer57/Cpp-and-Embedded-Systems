// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer_subcomponents::rf_status::rfStatus'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "rfStatus.h"
#endif

#include <HALtestLib_win32.h>
#include <rfStatus.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'rfStatusInterface_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'rfInterface(Integer,Integer*,Integer)'
Integer rfStatus::rfInterface( Integer opType, Integer * arguments, Integer numArguments )
{
	// {{{USR
	  //   default return is 0
	  Integer returnVal = 0;
	  
	  switch(opType)
	  {
	    case OP_GET_STATUS:
	    {
	      // arg0   = systemID
	      // arg1   = rfState
	      // arg2-3 = UNUSED
	      // returns previous rf state
	      returnVal = getStatus(arguments[0], arguments[1]);
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
// {{{RME classifier 'rfStatusInterface_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
