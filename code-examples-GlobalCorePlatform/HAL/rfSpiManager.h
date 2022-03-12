// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::deployment_utilities::spi::rfSpiManager'

#ifndef rfSpiManager_H
#define rfSpiManager_H

#ifdef PRAGMA
#pragma interface "rfSpiManager.h"
#endif

#include <HALtestLib_win32.h>
#include <rf_audio_std_types.h>
class rfSpiBuffer;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class rfSpiManager
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR
	friend class rfSpiBuffer;
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
	// {{{RME operation 'getSpiBuffers(unsigned int,unsigned int)'
	virtual rfSpiBuffer * * getSpiBuffers( unsigned int num, unsigned int size ) = 0;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* rfSpiManager_H */

// }}}RME
