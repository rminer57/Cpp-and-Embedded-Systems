// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer::sequencerComponent'

#ifndef sequencerComponent_H
#define sequencerComponent_H

#ifdef PRAGMA
#pragma interface "sequencerComponent.h"
#endif

#include <HALtestLib_win32.h>
#include <rf_audio_std_types.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>
// }}}USR
// }}}RME

class sequencerComponent
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
	// {{{RME operation 'rfInterface(Integer,Integer*,Integer)'
	virtual Integer rfInterface( Integer opType, Integer * arguments, Integer numArguments ) = 0;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* sequencerComponent_H */

// }}}RME
