// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::deployment_utilities::spi::rfSpiBuffer'

#ifndef rfSpiBuffer_H
#define rfSpiBuffer_H

#ifdef PRAGMA
#pragma interface "rfSpiBuffer.h"
#endif

#include <HALtestLib_win32.h>
#include <rf_audio_std_types.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>

// }}}USR
// }}}RME

class rfSpiBuffer
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR
	friend class rfSpiManager;
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
	// {{{RME operation 'sync()'
	virtual void sync( void ) = 0;
	// }}}RME
	// {{{RME operation 'operator[](int)'
	virtual uint32_t & operator[]( int index ) = 0;
	// }}}RME
	// {{{RME operation 'operator uint32_t*()'
	virtual operator uint32_t*( void ) = 0;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* rfSpiBuffer_H */

// }}}RME
