// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::deployment_utilities::gpi::generalPurposeInput'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "generalPurposeInput.h"
#endif

#include <rf_sequencer_comp.h>
#include <generalPurposeInput.h>
#include <generalPurposeInputManager.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'generalPurposeInput(Integer,generalPurposeInputManager*)'
generalPurposeInput::generalPurposeInput( Integer port, generalPurposeInputManager * managerPtr )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	  portNumber   = port;
	  inputManager = managerPtr;  

	// }}}USR
}
// }}}RME

// {{{RME operation 'get(Integer)'
Integer generalPurposeInput::get( Integer rfState )
{
	// {{{USR
	  return inputManager->getGPI(portNumber, rfState);  

	// }}}USR
}
// }}}RME

// {{{RME operation 'update(Integer)'
void generalPurposeInput::update( Integer rfState )
{
	// {{{USR
	  inputManager->updateGPI(portNumber, rfState);  

	// }}}USR
}
// }}}RME

// {{{RME operation '~generalPurposeInput()'
generalPurposeInput::~generalPurposeInput( void )
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
