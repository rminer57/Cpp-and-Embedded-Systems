// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::deployment_utilities::gpo::generalPurposeOutput'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "generalPurposeOutput.h"
#endif

#include <rf_sequencer_comp.h>
#include <generalPurposeOutput.h>
#include <generalPurposeOutputManager.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'commit(Integer)'
void generalPurposeOutput::commit( Integer rfState )
{
	// {{{USR
	  // call to parent
	  outputManager->commitGPO(portNumber, rfState);  

	// }}}USR
}
// }}}RME

// {{{RME operation 'generalPurposeOutput(Integer,generalPurposeOutputManager*)'
generalPurposeOutput::generalPurposeOutput( Integer port, generalPurposeOutputManager * managerPtr )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	  portNumber    = port;
	  outputManager = managerPtr;  

	// }}}USR
}
// }}}RME

// {{{RME operation 'set(Integer,Integer)'
void generalPurposeOutput::set( Integer outputState, Integer rfState )
{
	// {{{USR
	  // call to parent
	  outputManager->setGPO(portNumber, outputState, rfState);  

	// }}}USR
}
// }}}RME

// {{{RME operation '~generalPurposeOutput()'
generalPurposeOutput::~generalPurposeOutput( void )
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
