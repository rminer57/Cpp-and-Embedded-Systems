// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::Trident::TridentDefaultImages'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "TridentDefaultImages.h"
#endif

#include <rf_sequencer_comp.h>
#include <TridentDefaultImages.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'TridentDefaultImages(int16_t **,int)'
TridentDefaultImages::TridentDefaultImages( int16_t * * defaultRegisterImages, int numberOfImages )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_numberOfImages(numberOfImages)
	// }}}USR
	// }}}RME
{
	// {{{USR
	  // set member data
	  defaultImages = defaultRegisterImages;

	// }}}USR
}
// }}}RME

// {{{RME operation '~TridentDefaultImages()'
TridentDefaultImages::~TridentDefaultImages( void )
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
