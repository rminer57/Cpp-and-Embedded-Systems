// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::tomahawk::SpiImageMgr'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "SpiImageMgr.h"
#endif

#include <HALtestLib_win32.h>
#include <SpiImageMgr.h>
#include <SpiSnippetMgr.h>
#include <rf_audio_std_types.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'SpiImageMgr(int)'
SpiImageMgr::SpiImageMgr( int NumberOfSnippets )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	  //----------------------------- LOCAL VARIABLES ------------------------------

	  int i;

	  //---------------------------------- CODE ------------------------------------  

	// Create an array of status records for each snippet
	SnippetMgr = new SpiSnippetMgr*[NumberOfSnippets];

	// Create a status object for snippet 
	for(i = 0; i < NumberOfSnippets; i++)
	{
	SnippetMgr[i] = new SpiSnippetMgr();
	}

	ImageModified = false;
	ImageReset    = false;

	SnippetMgr[0]->SnippetModified = false;

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
