// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer_subcomponents::rf_base::rfBaseClass'

#ifndef rfBaseClass_H
#define rfBaseClass_H

#ifdef PRAGMA
#pragma interface "rfBaseClass.h"
#endif

#include <HALtestLib_win32.h>
#include <rf_audio_std_types.h>
#include <sequencerComponent.h>
class rfBaseClass;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class rfBaseClass : public sequencerComponent
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
	// {{{RME classAttribute 'currentRFState'
	Integer currentRFState;
	// }}}RME

public:
	// {{{RME operation 'setRFState(Integer)'
	virtual Integer setRFState( Integer rfState );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* rfBaseClass_H */

// }}}RME
