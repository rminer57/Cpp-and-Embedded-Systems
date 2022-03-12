// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer_subcomponents::rf_base::rfBaseClass'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "rfBaseClass.h"
#endif

#include <HALtestLib_win32.h>
#include <rfBaseClass.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'setRFState(Integer)'
Integer rfBaseClass::setRFState( Integer rfState )
{
	// {{{USR
	  Integer temp = currentRFState;
	  currentRFState = rfState;
	  return temp;  

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
