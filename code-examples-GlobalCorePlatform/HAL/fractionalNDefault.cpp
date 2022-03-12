// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::lvfractn::fractionalNDefault'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "fractionalNDefault.h"
#endif

#include <HALtestLib_win32.h>
#include <fractionalNDefault.h>
#include <bitfield.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'fractionalNDefault(uint32_t*,uint32_t**,uint32_t*,Integer,Integer)'
fractionalNDefault::fractionalNDefault( uint32_t * tempData, uint32_t * * defaultFractImages, uint32_t * clockCtrl, Integer oscilSensitivity, Integer voltMode )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	  // set member data
	  defaultImages = defaultFractImages;
	  clockControl  = clockCtrl;
	  tempCompData  = tempData;
	  oscillatorSensitivity = oscilSensitivity;
	  voltageMode = voltMode;

	// }}}USR
}
// }}}RME

// {{{RME operation '~fractionalNDefault()'
fractionalNDefault::~fractionalNDefault( void )
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
