// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::gpo_gain_control::gpoGainControl'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "gpoGainControl.h"
#endif

#include <HALtestLib_win32.h>
#include <gpoGainControl.h>
#include <generalPurposeOutput.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'gpoGainControl(generalPurposeOutput**,Integer,Integer,Integer)'
gpoGainControl::gpoGainControl( generalPurposeOutput * * gainTable, Integer numOfGains, Integer numOfRfStates, Integer initialGain )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	  : gainControl(numOfGains, numOfRfStates, initialGain)

	// }}}USR
	// }}}RME
{
	// {{{USR
	  gains = gainTable;

	// }}}USR
}
// }}}RME

// {{{RME operation 'setGain(Integer,Integer,Integer)'
Integer gpoGainControl::setGain( Integer gainNumber, Integer gain, Integer rfState )
{
	// {{{USR
	  gains[gainNumber]->set(gain, rfState);
	  return gainControl::setGain(gainNumber, gain, rfState);

	// }}}USR
}
// }}}RME

// {{{RME operation '~gpoGainControl()'
gpoGainControl::~gpoGainControl( void )
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
