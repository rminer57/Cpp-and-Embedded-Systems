// {{{RME classifier 'Logical View::OS Abstraction Layer::OSAL'

#ifndef OSAL_H
#define OSAL_H

#ifdef PRAGMA
#pragma interface "OSAL.h"
#endif

// {{{RME general 'documentation'
/* {{{USR
This class represents all of the initialization and global aspects of the OSAL.  It will provide the ability for the OSAL to be initalized properly before use.
   }}}USR */
// }}}RME

#include <osal_build.h>
class Thread;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include "Implementation.h"

// }}}USR
// }}}RME

class OSAL
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
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	OSAL( void );
	// }}}RME

public:
	// {{{RME operation 'init()'
	// {{{RME general 'documentation'
	/* {{{USR
	This method does all initialization that should happen before the OSAL is used.  This method should not be called by the user as it is automatically called for you by the startup libraries.


	   }}}USR */
	// }}}RME
	static void init( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* OSAL_H */

// }}}RME
