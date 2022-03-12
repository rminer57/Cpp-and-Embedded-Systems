// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer_subcomponents::mod_conversion::frequencyConversionReference'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "frequencyConversionReference.h"
#endif

#include <HALtestLib_win32.h>
#include <frequencyConversionReference.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'freqConversionRefInterface_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'setLO(Integer,Integer)'
Integer frequencyConversionReference::setLO( Integer freq, Integer rfState )
{
	// {{{USR
	  Integer temp = frequency[rfState];
	  frequency[rfState] = freq;
	  return temp;  

	// }}}USR
}
// }}}RME

// {{{RME operation 'frequencyConversionReference(Integer)'
frequencyConversionReference::frequencyConversionReference( Integer numberOfRfStates )
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
Integer frequencyConversionReference::rfInterface( Integer opType, Integer * arguments, Integer numArguments )
{
	// {{{USR

	  // default return value is 0
	  Integer returnVal = 0;

	  // decide which interface function to call based on opType
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
	    case OP_SET_LO:
	    {
	      // arg0   = frequency
	      // arg1   = rfState
	      // arg2-3 = UNUSED
	      // returns previous rf state
	      returnVal = setLO(arguments[0], arguments[1]);
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

// {{{RME operation '~frequencyConversionReference()'
frequencyConversionReference::~frequencyConversionReference( void )
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
// {{{RME classifier 'freqConversionRefInterface_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
