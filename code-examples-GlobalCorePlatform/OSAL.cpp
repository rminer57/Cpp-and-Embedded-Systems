// {{{RME classifier 'Logical View::OS Abstraction Layer::OSAL'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "OSAL.h"
#endif

#include <osal_build.h>
#include <OSAL.h>
#include <Thread.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR


// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
OSAL::OSAL( void )
{
}
// }}}RME

// {{{RME operation 'init()'
void OSAL::init( void )
{
	// {{{USR
	// Call the Implementation function to initialize the OSALi.

	Implementation::init();

	// Call methods for all the OSAL classes that need static initialization
	// that use OSAL services (mutex is the most common example)

	Thread::staticInit();
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
