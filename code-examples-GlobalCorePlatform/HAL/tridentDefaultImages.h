// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::Trident::TridentDefaultImages'

#ifndef TridentDefaultImages_H
#define TridentDefaultImages_H

#ifdef PRAGMA
#pragma interface "TridentDefaultImages.h"
#endif

#include <rf_sequencer_comp.h>
#include <rf_audio_std_types.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h> 


// }}}USR
// }}}RME

class TridentDefaultImages
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR
	friend class trident;
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
	int16_t * * defaultImages;
	// }}}RME

protected:
	// {{{RME classAttribute 'm_numberOfImages'
	int m_numberOfImages;
	// }}}RME

public:
	// {{{RME operation 'TridentDefaultImages(int16_t **,int)'
	TridentDefaultImages( int16_t * * defaultRegisterImages, int numberOfImages );
	// }}}RME
	// {{{RME operation '~TridentDefaultImages()'
	virtual ~TridentDefaultImages( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* TridentDefaultImages_H */

// }}}RME
