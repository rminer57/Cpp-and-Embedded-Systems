// {{{RME classifier 'Logical View::OS Abstraction Layer::Sem'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Sem.h"
#endif

#include <osal_build.h>
#include <Sem.h>
#include <TimeSpec.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
extern "C" {
#include <unistd.h>
#include <semaphore.h>
#include <errno.h>
#include <limits.h>
#include <time.h>
}

// }}}USR
// }}}RME

// {{{RME classAttribute 'ERRINVAL'
const int Sem::ERRINVAL( EINVAL );
// }}}RME

// {{{RME classAttribute 'ERRNOSPC'
const int Sem::ERRNOSPC( ENOSPC );
// }}}RME

// {{{RME classAttribute 'ERRDEADLK'
const int Sem::ERRDEADLK( EDEADLK );
// }}}RME

// {{{RME classAttribute 'ERRAGAIN'
const int Sem::ERRAGAIN( EAGAIN );
// }}}RME

// {{{RME classAttribute 'VALUE_MAX'
const int Sem::VALUE_MAX = SEM_VALUE_MAX;
// }}}RME

// {{{RME classAttribute 'ERRTIMEDOUT'
const int Sem::ERRTIMEDOUT( ETIMEDOUT );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
Sem::Sem( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
Sem::Sem( const Sem & rtg_arg )
	: m_sem( rtg_arg.m_sem )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
Sem & Sem::operator=( const Sem & rtg_arg )
{
	if( this != &rtg_arg )
		m_sem = rtg_arg.m_sem;
	return *this;
}
// }}}RME

// {{{RME operation 'createSem(unsigned int,int *)'
Sem * Sem::createSem( unsigned int value, int * errPtr )
{
	// {{{USR
	sem_t s;
	Sem * sem = 0;


	if (sem_init(&s, 0 /* default to non-pshared */, value) != -1)
	{
		sem = new Sem();
		sem->m_sem = s;
	}
	else
	{
		// error logging
		if (errPtr)
		{
			*errPtr = errno;
		}
	}

	return sem;

	// }}}USR
}
// }}}RME

// {{{RME operation 'wait()'
bool Sem::wait( void )
{
	// {{{USR
	return (sem_wait(&m_sem) != -1);
	// }}}USR
}
// }}}RME

// {{{RME operation 'tryWait()'
int Sem::tryWait( void )
{
	// {{{USR
	return (sem_trywait(&m_sem) != -1) ? 0 : errno;

	// }}}USR
}
// }}}RME

// {{{RME operation 'post()'
void Sem::post( void )
{
	// {{{USR
	sem_post(&m_sem);
	// }}}USR
}
// }}}RME

// {{{RME operation 'getValue()'
int Sem::getValue( void )
{
	// {{{USR
	int i;

	sem_getvalue(&m_sem, &i);

	return i;
	// }}}USR
}
// }}}RME

// {{{RME operation '~Sem()'
Sem::~Sem( void )
{
	// {{{USR
	// error log if it fails
	sem_destroy(&m_sem);
	// }}}USR
}
// }}}RME

// {{{RME operation 'timedWait(TimeSpec)'
int Sem::timedWait( TimeSpec relativeTime )
{
	// {{{USR
	struct timespec cts; 	// current timespec and absolute time spec
	int retVal = 0; 		// assume success
	    
	// get the current time
	clock_gettime(CLOCK_REALTIME, &cts);
	    
	// create a timespec with the current time... 
	TimeSpec absoluteTime(cts.tv_sec, cts.tv_nsec);
	    
	// add in the relative time offset to get the timeout in absolute time
	absoluteTime += relativeTime;

	// convert the timespec class back into a posix timespec structure
	cts.tv_sec = absoluteTime.getSeconds();
	cts.tv_nsec = absoluteTime.getNanoseconds();

	// now call the posix function to wait on the semaphore until
	// available or until the timeout occurs.
	    
	retVal = sem_timedwait(&m_sem, &cts);
	    
	// check the return value and update accordingly
	if (retVal != 0)
	{
	    // then there was an error, so update with the error number
	    retVal = errno;
	}
	    
	return (retVal);




	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
