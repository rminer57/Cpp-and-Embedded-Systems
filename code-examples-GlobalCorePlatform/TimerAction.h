// {{{RME classifier 'Logical View::OS Abstraction Layer::TimerAction'

#ifndef TimerAction_H
#define TimerAction_H

#ifdef PRAGMA
#pragma interface "TimerAction.h"
#endif

// {{{RME general 'documentation'
/* {{{USR
This abstract class represents the action that should occur when a timer expires.  It represents a way to avoid having to figure out which timer the expiration is associated with because the expiration message will be able to simply execute the action in this object.  This action can also be executed through the Timer object.  A TimerAction object should include references to Threads or any other objects that it needs to execute its action.
   }}}USR */
// }}}RME

#include <osal_build.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class TimerAction
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
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	TimerAction( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~TimerAction( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	TimerAction( const TimerAction & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	TimerAction & operator=( const TimerAction & rtg_arg );
	// }}}RME
	// {{{RME operation 'action()'
	// {{{RME general 'documentation'
	/* {{{USR
	This abstract method represents what is to be done when the timer expires.  The return value is true if it worked and false if it did not.
	   }}}USR */
	// }}}RME
	virtual bool action( void ) = 0;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* TimerAction_H */

// }}}RME
