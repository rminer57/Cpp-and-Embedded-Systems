// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::deployment_utilities::gpi::generalPurposeInputManager'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "generalPurposeInputManager.h"
#endif

#include <rf_sequencer_comp.h>
#include <generalPurposeInputManager.h>
#include <generalPurposeInput.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'generalPurposeInputManager(Integer)'
generalPurposeInputManager::generalPurposeInputManager( Integer numPorts )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	  // create array to hold gpis
	  numberGPIs = numPorts;
	  
	  GPIs = new generalPurposeInput*[numberGPIs];

	  for(int i = 0; i < numberGPIs; i++)
	  {
	    // create gpos
	    GPIs[i] = new generalPurposeInput(i, this);
	  }  

	// }}}USR
}
// }}}RME

// {{{RME operation 'getInput(Integer)'
generalPurposeInput * generalPurposeInputManager::getInput( Integer num )
{
	// {{{USR
	  return GPIs[num];  

	// }}}USR
}
// }}}RME

// {{{RME operation '~generalPurposeInputManager()'
generalPurposeInputManager::~generalPurposeInputManager( void )
{
	// {{{USR
	   for(int i = 0; i < numberGPIs; i++)
	  {
	    // delete GPIs
	    delete GPIs[i];
	    GPIs[i] = 0;
	  }

	  // delete GPI array
	  delete [] GPIs;

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
