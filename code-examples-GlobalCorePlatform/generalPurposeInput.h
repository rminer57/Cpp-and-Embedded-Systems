// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::deployment_utilities::gpi::generalPurposeInput'

#ifndef generalPurposeInput_H
#define generalPurposeInput_H

#ifdef PRAGMA
#pragma interface "generalPurposeInput.h"
#endif

#include <rf_sequencer_comp.h>
#include <rf_audio_std_types.h>
class generalPurposeInputManager;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class generalPurposeInput
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR
	friend class generalPurposeInputManager;
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
	// {{{RME classAttribute 'inputManager'
	generalPurposeInputManager * inputManager;
	// }}}RME
	// {{{RME classAttribute 'portNumber'
	Integer portNumber;
	// }}}RME

protected:
	// {{{RME operation 'generalPurposeInput(Integer,generalPurposeInputManager*)'
	generalPurposeInput( Integer port, generalPurposeInputManager * managerPtr );
	// }}}RME

public:
	// {{{RME operation 'get(Integer)'
	Integer get( Integer rfState );
	// }}}RME
	// {{{RME operation 'update(Integer)'
	void update( Integer rfState );
	// }}}RME
	// {{{RME operation '~generalPurposeInput()'
	~generalPurposeInput( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* generalPurposeInput_H */

// }}}RME
