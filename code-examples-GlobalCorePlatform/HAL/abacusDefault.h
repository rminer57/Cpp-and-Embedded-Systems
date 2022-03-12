// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::abacusIII::abacusDefault'

#ifndef abacusDefault_H
#define abacusDefault_H

#ifdef PRAGMA
#pragma interface "abacusDefault.h"
#endif

#include <HALtestLib_win32.h>
#include <rf_audio_std_types.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>
// }}}USR
// }}}RME

class abacusDefault
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

protected:
	// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

private:
	// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

public:
	// {{{RME classAttribute 'defaultImages'
	uint32_t * * defaultImages;
	// }}}RME
	// {{{RME classAttribute 'defaultHwFref'
	Integer defaultHwFref;
	// }}}RME
	// {{{RME classAttribute 'defaultSwFref'
	Integer defaultSwFref;
	// }}}RME
	// {{{RME operation 'abacusDefault(uint32_t**,Integer,Integer)'
	abacusDefault( uint32_t * * images, Integer hwFref, Integer swFref );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* abacusDefault_H */

// }}}RME
