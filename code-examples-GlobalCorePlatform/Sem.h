// {{{RME classifier 'Logical View::OS Abstraction Layer::Sem'

#ifndef Sem_H
#define Sem_H

#ifdef PRAGMA
#pragma interface "Sem.h"
#endif

// {{{RME general 'documentation'
/* {{{USR
This class models a POSIX semaphore.  This is a counting semaphore, where the value is greater than 0 if it is unlocked, and zero or negative if it is locked.  If negative, the absolute value represents the number of threads waiting.  If positive, the value represents the number of wait() calls that can be made before the semaphore is locked.

The methods map to the semaphore calls as described in the POSIX specification.  The named semaphores calls (sem_open(), sem_close(), and sem_unlink()) are not supported.  All semaphores are for use within objects sharing the semaphore by reference.

Creation of the semaphore is accomplished by the createSem() method to allow for the fact that the semaphore may not get created due to an error.  See createSem() for details.

The corresponding specification is attached to this class.
   }}}USR */
// }}}RME

#include <osal_build.h>
class TimeSpec;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include "Implementation.h"
// }}}USR
// }}}RME

class Sem
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

protected:
	// {{{RME classAttribute 'm_sem'
	sem_t m_sem;
	// }}}RME

public:
	// {{{RME classAttribute 'ERRINVAL'
	static const int ERRINVAL;
	// }}}RME
	// {{{RME classAttribute 'ERRNOSPC'
	static const int ERRNOSPC;
	// }}}RME
	// {{{RME classAttribute 'ERRDEADLK'
	static const int ERRDEADLK;
	// }}}RME
	// {{{RME classAttribute 'ERRAGAIN'
	static const int ERRAGAIN;
	// }}}RME
	// {{{RME classAttribute 'VALUE_MAX'
	static const int VALUE_MAX;
	// }}}RME
	// {{{RME classAttribute 'ERRTIMEDOUT'
	static const int ERRTIMEDOUT;
	// }}}RME

protected:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	Sem( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	Sem( const Sem & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	Sem & operator=( const Sem & rtg_arg );
	// }}}RME

public:
	// {{{RME operation 'createSem(unsigned int,int *)'
	// {{{RME general 'documentation'
	/* {{{USR
	This method returns a reference to the newly created Sem object if it works.  The initial value is the value parameter, which defaults to 1 if unspecified.  This value specifies how many calls to wait() will not block after initialization before post() is called.  See the Semaphore general description for more details on the meaning of the value.

	If this method fails, 0 is returned, and the error is returned if an errPtr parameter is given in the call.  The possible errors that could be seen are:

	ERRINVAL: The value argument exceeds Sem::VALUE_MAX.
	ERRNOSPC: A resource required has been exhausted.

	Since the CGISS profile does not support multiple processes, the pshared parameter is not exposed and it is set to 0.

	sem_init() is used in this method.  See the specification for sem_init() for the interface.


	   }}}USR */
	// }}}RME
	static Sem * createSem( unsigned int value = 1, int * errPtr = 0 );
	// }}}RME
	// {{{RME operation 'wait()'
	// {{{RME general 'documentation'
	/* {{{USR
	Blocks attempting to get the semaphore.  This method will not return until it is locked, or an error is detected.  The return value will be true if the semaphore locked, and false otherwise.  The only error expected is that a deadlock condition was detected.  Other error types (not implemented) should not occur at runtime, and error logging should be used to detect those cases.

	See the specification for sem_wait().
	   }}}USR */
	// }}}RME
	bool wait( void );
	// }}}RME
	// {{{RME operation 'tryWait()'
	// {{{RME general 'documentation'
	/* {{{USR
	Attempts to lock the semaphore and returns if it was not available or if deadlock was detected.  The return value will be

	0 if the semaphore locked
	ERRAGAIN: if the semaphore could not be locked
	ERRDEADLK: a deadlock condition was detected.

	Other error types (not implemented) should not occur at runtime, and error logging should be used to detect those cases.

	See the specification for sem_trywait().
	   }}}USR */
	// }}}RME
	int tryWait( void );
	// }}}RME
	// {{{RME operation 'post()'
	// {{{RME general 'documentation'
	/* {{{USR
	Unlocks the semaphore.

	See the specification for sem_post().
	   }}}USR */
	// }}}RME
	void post( void );
	// }}}RME
	// {{{RME operation 'getValue()'
	// {{{RME general 'documentation'
	/* {{{USR
	Returns the value of the semaphore.

	See the specification for sem_getvalue().
	   }}}USR */
	// }}}RME
	int getValue( void );
	// }}}RME
	// {{{RME operation '~Sem()'
	// {{{RME general 'documentation'
	/* {{{USR
	Destroys the semaphore.

	WARNING: if a semaphore is destroyed while threads are blocked on it, behavior is undefined.

	This method uses sem_destroy().  See the specification for sem_destroy() for details on it.

	   }}}USR */
	// }}}RME
	~Sem( void );
	// }}}RME
	// {{{RME operation 'timedWait(TimeSpec)'
	// {{{RME general 'documentation'
	/* {{{USR
	Attempts to lock the semaphore and will wait up to the relative time passed in  and returns if it was not available or if deadlock was detected.  The return value will be

	0 if the semaphore locked
	ERRTIMEDOUT: if the semaphore could not be locked within the given Relative Time

	See the specification for sem_timedwait().
	   }}}USR */
	// }}}RME
	int timedWait( TimeSpec relativeTime );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Sem_H */

// }}}RME
