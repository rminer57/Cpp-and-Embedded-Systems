// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::abacusIII::abacusDefault'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "abacusDefault.h"
#endif

#include <HALtestLib_win32.h>
#include <abacusDefault.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'abacusDefault(uint32_t**,Integer,Integer)'
abacusDefault::abacusDefault( uint32_t * * images, Integer hwFref, Integer swFref )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	  defaultImages  = images;
	  defaultHwFref  = hwFref;
	  defaultSwFref  = swFref;  
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
