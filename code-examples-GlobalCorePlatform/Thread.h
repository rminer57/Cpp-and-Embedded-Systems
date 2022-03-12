// {{{RME classifier 'Logical View::OS Abstraction Layer::Thread'

#ifndef Thread_H
#define Thread_H

#ifdef PRAGMA
#pragma interface "Thread.h"
#endif

// {{{RME general 'documentation'
/* {{{USR
This class models a POSIX thread.  The methods generally map to the pthread calls as described in the POSIX specification.  The corresponding specification is attached to this class.

Notes for Thread Implementors
------------------------------------------------
Those wishing to write a Thread, should subclass this class and add any local variables as instance variables for the object.  Management of the object itself is automatic, and will happen without any explicit delete calls via the use of thread-specific data in the implementation of the Thread base class.  The routine that is the main loop is to be in the subclass's main() method.  The default main method simply returns.  It is IMPORTANT that all subclasses make sure thread creation and deletion are handled properly by doing the following:

1. specification of a static createThread() method based on the implementation that is in Thread::createThread().  See createThread() for details.
2. additions to the destructor (e.g. ~ThreadSubClass()) that frees all other resources used by the thread.

IMPORTANT: under no circumstances should the Thread object be deleted.  This is managed automatically.  The client needs to detach() or join() the Thread.

Notes for Thread Creators
----------------------------------------
Thread creators are those that call createThread() on the subclasses of Thread.  As per the POSIX specification, the user of the subclass MUST call detach() or join() on the Thread object returned so that the underlying POSIX implementation can release all resources associated with that thread.  After that, it is UNSAFE to use the Thread object.

IMPORTANT: under no circumstances should the Thread object be deleted.  This is managed automatically.  The client needs to detach() or join() the Thread.

Thread Exit and Destruction
--------------------------------------------
Threads can exit in one of two ways.  First, if the main() method returns, the thread ends.  Second, if the exit() method is called, the thread ends.  However, exit() will only work if it is invoked on the Thread instance that corresponds to the current thread.  It is not legal for a thread to stop another thread by calling the other Thread's exit() method.

Scheduling and Priorities
---------------------------------------
Priorities are proportional to the numeric value given from getPriorityMin() to getPriorityMax().  In other words, the higher the priority number, the higher the priority.  The scheduling policy can vary, and clients of this interface should not make assumptions based on a particular policy.  It can be assumed that threads of higher priority will run more often than threads of lower priority, but any dependencies on which thread should run to ensure correctness, should use mutexes, semaphores, and/or message queues for inter-thread coordination and synchronization.


   }}}USR */
// }}}RME

#include <osal_build.h>
class Mutex;
class TimeSpec;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include "Implementation.h"
#include <stdint.h>
// }}}USR
// }}}RME

class Thread
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR
	friend class OSAL;
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
	// {{{RME classAttribute 'm_pthread'
	pthread_t m_pthread;
	// }}}RME
	// {{{RME classAttribute 'm_threadInstanceKey'
	static pthread_key_t m_threadInstanceKey;
	// }}}RME
	// {{{RME classAttribute 'm_staticMutex'
	static Mutex * m_staticMutex;
	// }}}RME
	// {{{RME classAttribute 'm_detached'
	bool m_detached;
	// }}}RME
	// {{{RME classAttribute 'm_mutex'
	Mutex * m_mutex;
	// }}}RME
	// {{{RME classAttribute 'm_dead'
	bool m_dead;
	// }}}RME
	// {{{RME classAttribute 'm_threadToCleanup'
	static Thread * m_threadToCleanup;
	// }}}RME
	// {{{RME classAttribute 'm_priorityMax'
	static int m_priorityMax;
	// }}}RME
	// {{{RME classAttribute 'm_priorityMin'
	static int m_priorityMin;
	// }}}RME

protected:
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	Thread( const Thread & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	Thread & operator=( const Thread & rtg_arg );
	// }}}RME

public:
	// {{{RME operation 'join(void **)'
	// {{{RME general 'documentation'
	/* {{{USR
	Blocks this thread until another thread has terminated.  If the call succeeds, true is returned.  Otherwise, false is returned.  The only expected error is that a deadlock was detected which happens when the Thread object refers to the thread currently being run in, or if the thread is already detached.

	NOTE: join() or detach() MUST be called by the parent thread to ensure all resources used by the thread are released.  Thread objects should NEVER be explicitly deleted.  They should be join()'d or detach()'d.

	See the specification for pthread_join().
	   }}}USR */
	// }}}RME
	bool join( void * * valuePtrPtr = 0 ) const;
	// }}}RME
	// {{{RME operation 'detach()'
	// {{{RME general 'documentation'
	/* {{{USR
	Detaches the thread.  This means it cannot be joined, and the system can release its resources when the thread terminates.

	NOTE: join() or detach() MUST be called by the parent thread to ensure all resources used by the thread are released.  Thread objects should NEVER be explicitly deleted.  They should be join()'d or detach()'d.

	See the specification for pthread_detach().
	   }}}USR */
	// }}}RME
	void detach( void );
	// }}}RME
	// {{{RME operation 'exit(void *)'
	// {{{RME general 'documentation'
	/* {{{USR
	This method causes the Thread to exit() if the current thread corresponds to this Thread object.  Otherwise, false is returned.
	   }}}USR */
	// }}}RME
	bool exit( void * valuePtr = 0 );
	// }}}RME
	// {{{RME operation 'self()'
	// {{{RME general 'documentation'
	/* {{{USR
	This routine returns a Thread object that represents the current thread.  A single object will be used to point to the Thread no matter how many references to this Thread there are, so the caller of self() should not destroy the Thread.  In fact, a Thread object should never be deleted - it is handled automatically by this class.

	This method is based on pthread_self() .  See the specification for pthread_self() for more details.
	   }}}USR */
	// }}}RME
	static Thread * self( void );
	// }}}RME
	// {{{RME operation '~Thread()'
	// {{{RME general 'documentation'
	/* {{{USR
	Do not destroy this object!  It will be done automatically.
	   }}}USR */
	// }}}RME
	virtual ~Thread( void );
	// }}}RME

private:
	// {{{RME operation 'setThreadInstance()'
	// {{{RME general 'documentation'
	/* {{{USR
	This method sets the ThreadInstance so that it will get destroyed once this thread exits.
	   }}}USR */
	// }}}RME
	void setThreadInstance( void );
	// }}}RME

protected:
	// {{{RME operation 'Thread()'
	// {{{RME general 'documentation'
	/* {{{USR
	This is the default constructor, which is not expected to be used directly by Thread users.  A thread should be created with createThread().  This method does general threading initialization.
	   }}}USR */
	// }}}RME
	Thread( void );
	// }}}RME

public:
	// {{{RME operation 'staticStart(void *)'
	// {{{RME general 'documentation'
	/* {{{USR
	This is a method that exists as a way to interface with the POSIX C interface.  pthread_create() requires a function pointer, and the only way to do that is to use a static method to hand off to it.  The parameter sent along is the RunnableThread instance, so that that is where local variables for the thread should be.
	   }}}USR */
	// }}}RME
	void * staticStart( void * thread );
	// }}}RME
	// {{{RME operation 'sleep(unsigned int)'
	// {{{RME general 'documentation'
	/* {{{USR
	This operation causes the current thread to sleep for the specified number of seconds and maps to the sleep() POSIX function from the Process Primitives section.  It returns the amount of "unslept" time.  This should only happen if a signal interrupts the sleep().  Since the CGISS profile does not include signals, the return should always be 0.

	See the attached specification for more details.
	   }}}USR */
	// }}}RME
	static unsigned int sleep( unsigned int seconds );
	// }}}RME
	// {{{RME operation 'nanosleep(const TimeSpec,TimeSpec *)'
	// {{{RME general 'documentation'
	/* {{{USR
	This method maps to the Clock and Timer POSIX routine, nanosleep().  It causes the caller's thread to block for the amount of time specified.  It returns true if it worked and false if the timespec parameter has a value greater than 1 billion for the nanosecond value.  The resolution is that of the CLOCK_REALTIME clock.

	See the corresponding specification.
	   }}}USR */
	// }}}RME
	static bool nanosleep( const TimeSpec requestedTime, TimeSpec * remainingTime = 0 );
	// }}}RME
	// {{{RME operation 'setPriority(int)'
	// {{{RME general 'documentation'
	/* {{{USR
	Sets the priority of the thread.  If this succeeds, the call returns true.  If it the value specified is invalid, false is returned.

	See the specification for pthread_setschedparam().
	   }}}USR */
	// }}}RME
	bool setPriority( int priority );
	// }}}RME
	// {{{RME operation 'getPriority()'
	// {{{RME general 'documentation'
	/* {{{USR
	Returns the priority of the thread.

	See the specification for pthread_getschedparam().
	   }}}USR */
	// }}}RME
	int getPriority( void ) const;
	// }}}RME

protected:
	// {{{RME operation 'main()'
	// {{{RME general 'documentation'
	/* {{{USR
	This is the main routine for this class.  It is to be instantiated in the sub-classes that are the real threads.
	   }}}USR */
	// }}}RME
	virtual void * main( void );
	// }}}RME
	// {{{RME operation 'actuallyCreateThread(int,Thread *,uint16_t)'
	// {{{RME general 'documentation'
	/* {{{USR
	This method encompasses the common code to actually create a thread.  It takes in a created thread object of the subclass actually needed.  It returns the thread on success, or 0 if it fails.

	This method uses the pthread_create() POSIX routine.  See the related specification for details.
	   }}}USR */
	// }}}RME
	static Thread * actuallyCreateThread( int priority, Thread * thread, uint16_t stackSize = 2048 );
	// }}}RME

public:
	// {{{RME operation 'createThread(int,uint16_t)'
	// {{{RME general 'documentation'
	/* {{{USR
	This method creates a thread.  The idea is that subclasses will be created that implements the main() method, which is the main loop of the thread.  A corresponding static method to createThread() in that subclass is used to create Thread instances.  A priority must be specified.  Thread::getPriorityMin() can be used if the client has no specific requirements.  Components should consider offering a configuration parameter to have system integrators choose thread priorities for any threads within a component, to manage the relative priorities.  The thread stackSize may be optionally specified. 

	Implementation note: Useful protected methods are used in here and implementers of subclasses should copy the implementation done here.

	If this method fails, 0 is returned.  The only reasons for failure are lack of system resources or an invalid priority.  Error logging will show which ocurred.  No error code is returned.

	This method uses the pthread_create() POSIX routine.  See the related specification for details.

	Since the PLATFORM hides implementations from it's clients, it is copied here for your reference:
	// This method should should be cut and pasted to be reused by
	// subclasses of Thread replacing "new Thread()" with a new of
	// the correct class.

	return actuallyCreateThread(priority, new Thread(), stackSize);
	   }}}USR */
	// }}}RME
	static Thread * createThread( int priority, uint16_t stackSize = 2048 );
	// }}}RME
	// {{{RME operation 'getPriorityMax()'
	// {{{RME general 'documentation'
	/* {{{USR
	Returns the maximum priority that can be assigned.  The higher the numeric priority, the higher the priority.
	   }}}USR */
	// }}}RME
	static int getPriorityMax( void );
	// }}}RME
	// {{{RME operation 'getPriorityMin()'
	// {{{RME general 'documentation'
	/* {{{USR
	Returns the minimum priority that can be assigned.  The higher the numeric priority, the higher the priority.
	   }}}USR */
	// }}}RME
	static int getPriorityMin( void );
	// }}}RME

private:
	// {{{RME operation 'clearThreadInstance()'
	// {{{RME general 'documentation'
	/* {{{USR
	This method clears the ThreadInstance.
	   }}}USR */
	// }}}RME
	void clearThreadInstance( void );
	// }}}RME

public:
	// {{{RME operation 'destructor(void *)'
	// {{{RME general 'documentation'
	/* {{{USR
	This is the destructor passed to the thread-specific data holding the thread instance.
	   }}}USR */
	// }}}RME
	static void destructor( void * obj );
	// }}}RME

private:
	// {{{RME operation 'cleanup(const Thread *)'
	// {{{RME general 'documentation'
	/* {{{USR
	Private function to cleanup Thread instances.
	   }}}USR */
	// }}}RME
	static void cleanup( const Thread * threadToCleanup = 0 );
	// }}}RME

protected:
	// {{{RME operation 'staticInit()'
	// {{{RME general 'documentation'
	/* {{{USR
	This method initializes any static variables that need the OSAL to already be initialized, such as initializing static Mutexes and thread min and max priority levels..
	   }}}USR */
	// }}}RME
	static void staticInit( void );
	// }}}RME

public:
	// {{{RME operation 'yield()'
	// {{{RME general 'documentation'
	/* {{{USR
	This operation causes the current thread to yield its execution in favor of another thread of equal or higher priority. This operation maps to the yield() POSIX function from the Process Primitives section.  It returns success after the current task is re-started.

	See the attached specification for more details.

	WARNING - This function should not be used. If you feel that you need to use this function, talk to someone else to make sure that you know what you are doing.  A possible usage situation would include integrating with 3rd party SW that is out of our architectural control.
	   }}}USR */
	// }}}RME
	static int yield( void );
	// }}}RME
	// {{{RME operation 'getSysPriorityMax()'
	// {{{RME general 'documentation'
	/* {{{USR
	Returns the maximum priority that can be assigned.  The higher the numeric priority, the higher the priority.  Priority levels between the getPriorityMax value and this value are reserved for system critical threads and should be used with extreme caution and justification.
	   }}}USR */
	// }}}RME
	static int getSysPriorityMax( void );
	// }}}RME
	// {{{RME operation 'getSysPriorityMin()'
	// {{{RME general 'documentation'
	/* {{{USR
	Returns the minimum priority that can be assigned.  The higher the numeric priority, the higher the priority.  Priority levels between the getPriorityMin value and this value are reserved for system critical threads and should be used with extreme caution and justification.
	   }}}USR */
	// }}}RME
	static int getSysPriorityMin( void );
	// }}}RME
	// {{{RME operation 'setPriorityMax(int)'
	// {{{RME general 'documentation'
	/* {{{USR
	Sets the maximum priority for future thread creations that use the getPriorityMax() method.  The higher the numeric priority, the higher the priority.

	Returns true if a valid priority level for the system was requested.  Returns false otherwise.
	   }}}USR */
	// }}}RME
	static bool setPriorityMax( int priority );
	// }}}RME
	// {{{RME operation 'setPriorityMin(int)'
	// {{{RME general 'documentation'
	/* {{{USR
	Sets the minimum priority for future thread creations that use the getPriorityMin() method.  The higher the numeric priority, the higher the priority.

	Returns true if a valid priority level for the system was requested.  Returns false otherwise.
	   }}}USR */
	// }}}RME
	static bool setPriorityMin( int priority );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Thread_H */

// }}}RME
