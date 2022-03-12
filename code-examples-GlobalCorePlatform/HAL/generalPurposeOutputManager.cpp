// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::deployment_utilities::gpo::generalPurposeOutputManager'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "generalPurposeOutputManager.h"
#endif

#include <HALtestLib_win32.h>
#include <generalPurposeOutputManager.h>
#include <generalPurposeOutput.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'generalPurposeOutputManager(Integer)'
generalPurposeOutputManager::generalPurposeOutputManager( Integer numPorts )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	  numberGPOs = numPorts;
	  
	  // create array to hold gpos
	  GPOs = new generalPurposeOutput*[numberGPOs];

	  for(int i = 0; i < numberGPOs; i++)
	  {
	    // create gpos
	    GPOs[i] = new generalPurposeOutput(i, this);
	  }

	// }}}USR
}
// }}}RME

// {{{RME operation 'getOutput(Integer)'
generalPurposeOutput * generalPurposeOutputManager::getOutput( Integer num )
{
	// {{{USR
	  return GPOs[num];  

	// }}}USR
}
// }}}RME

// {{{RME operation '~generalPurposeOutputManager()'
generalPurposeOutputManager::~generalPurposeOutputManager( void )
{
	// {{{USR
	  for(int i = 0; i < numberGPOs; i++)
	  {
	    // delete GPOs
	    delete [] GPOs[i];
	  }

	  // delete GPO array
	  delete [] GPOs;

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
