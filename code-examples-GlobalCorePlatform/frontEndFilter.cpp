// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer_subcomponents::frontEndFilter::frontEndFilter'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "frontEndFilter.h"
#endif

#include <rf_sequencer_comp.h>
#include <frontEndFilter.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'frontEndFilterInterface_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'frontEndFilter()'
frontEndFilter::frontEndFilter( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation '~frontEndFilter()'
frontEndFilter::~frontEndFilter( void )
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'rfInterface(Integer,Integer*,Integer)'
Integer frontEndFilter::rfInterface( Integer opType, Integer * arguments, Integer numArguments )
{
	// {{{USR
	  // default return is 0
	  Integer returnVal = 0;
	  
	  switch(opType)
	  {
	    case OP_SET_RFSTATE:  // execute the setRFState method inherited from rf base class
	    {
	      // arg0   = rfState
	      // arg1-3 = UNUSED
	      // returns previous rf state
	      returnVal = setRFState(arguments[0]);
	      break;
	    }
	    case OP_SET_FILTER:
	    {
	      // arg0 = value
	      // arg1 = UNUSED
	      // arg2 = UNUSED
	      // arg3 = UNUSED
	      // returns the previous gain
	      returnVal = setFilter(arguments[0], arguments[1]);
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
// {{{RME classifier 'frontEndFilterInterface_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
