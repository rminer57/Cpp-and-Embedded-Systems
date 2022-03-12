// {{{RME classifier 'Logical View::OS Abstraction Layer::Thread'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Thread.h"
#endif

#include <osal_build.h>
#include <Thread.h>
#include <Mutex.h>
#include <TimeSpec.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
extern "C" {
//#include <unistd.h>
//#include <pthread.h>
//#include <sched.h>
//#include <time.h>





static void * g_staticStart(void *);
static void g_threadDestructor(void *);


static void * g_staticStart(void * thread)
{
	return ( (Thread *) thread )->staticStart( (Thread*) thread  );
}

static void g_threadDestructor(void *obj)
{
   ( (Thread * ) obj )->destructor( obj );
}


}


// }}}USR
// }}}RME

// {{{RME classAttribute 'm_threadInstanceKey'
pthread_key_t Thread::m_threadInstanceKey;
// }}}RME

// {{{RME classAttribute 'm_staticMutex'
Mutex * Thread::m_staticMutex = 0;
// }}}RME

// {{{RME classAttribute 'm_threadToCleanup'
Thread * Thread::m_threadToCleanup = 0;
// }}}RME

// {{{RME classAttribute 'm_priorityMax'
int Thread::m_priorityMax;
// }}}RME

// {{{RME classAttribute 'm_priorityMin'
int Thread::m_priorityMin;
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
Thread::Thread( const Thread & rtg_arg )
	: m_pthread( rtg_arg.m_pthread )
	, m_detached( rtg_arg.m_detached )
	, m_mutex( rtg_arg.m_mutex )
	, m_dead( rtg_arg.m_dead )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
Thread & Thread::operator=( const Thread & rtg_arg )
{
	if( this != &rtg_arg )
	{
		m_pthread = rtg_arg.m_pthread;
		m_detached = rtg_arg.m_detached;
		m_mutex = rtg_arg.m_mutex;
		m_dead = rtg_arg.m_dead;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'join(void **)'
bool Thread::join( void * * valuePtrPtr ) const
{
	// {{{USR
	int retval = 1;
/*
	m_mutex->lock();
	if (!m_detached)
	{
		m_mutex->unlock();
		retval = pthread_join(m_pthread, valuePtrPtr);
		if (retval == 0)
		{
			cleanup(this);
		}
		// else: do error logging here
	}
	else
	{
		m_mutex->unlock();
	}
*/
	return (retval == 0);

	// }}}USR
}
// }}}RME

// {{{RME operation 'detach()'
void Thread::detach( void )
{
	// {{{USR
/*	m_mutex->lock();

	if (!m_detached)
	{
		pthread_detach(m_pthread);
		// check the return value above when add error logging
		m_detached = true;
	}

	if (m_dead)
	{
		m_mutex->unlock();
		cleanup(this);
	}
	else
	{
		m_mutex->unlock();
	}
*/
	// }}}USR
}
// }}}RME

// {{{RME operation 'exit(void *)'
bool Thread::exit( void * valuePtr )
{
	// {{{USR
//	if (pthread_self() == m_pthread)
//	{
//		pthread_exit(valuePtr);
		// the call above never returns
//	}

	// we can only get here if this is the wrong thread, so return false
	return false;

	// }}}USR
}
// }}}RME

// {{{RME operation 'self()'
Thread * Thread::self( void )
{
	// {{{USR
	// thread-specific data is being used to implement this

	Thread * th = 0;
/*
	if ((th = (Thread *) pthread_getspecific(m_threadInstanceKey)) == 0)
	{
		// if the object reference doesn't exist, someone deleted it or
		// it is the main parent thread
		// this won't be the subclassed Thread object, but it should work
		// for basic thread services
		th = new Thread();
		th->m_pthread = pthread_self(); // set the pthread_t value
		th->setThreadInstance();
	}
*/
	return th;

	// }}}USR
}
// }}}RME

// {{{RME operation '~Thread()'
Thread::~Thread( void )
{
	// {{{USR
	delete m_mutex;

	// }}}USR
}
// }}}RME

// {{{RME operation 'setThreadInstance()'
void Thread::setThreadInstance( void )
{
	// {{{USR
	// set the instance
//	pthread_setspecific(m_threadInstanceKey, (void *)this);

	// }}}USR
}
// }}}RME

// {{{RME operation 'Thread()'
Thread::Thread( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_mutex(Mutex::createMutex()), m_detached(false), m_dead(false)
	// }}}USR
	// }}}RME
{
	// {{{USR
	cleanup();  // so old Thread objects get cleaned up

	// }}}USR
}
// }}}RME

// {{{RME operation 'staticStart(void *)'
void * Thread::staticStart( void * thread )
{
	// {{{USR
	// First put the Thread object in thread-specific data.
	// Note that an alternate implementation was considered
	// that should be revived if thread-specific data turns
	// out to be unsupported in a POSIX implementation.  see
	// inspection CGISS00000490 in clearquest for details.
	((Thread *) thread)->setThreadInstance();

	return ((Thread *) thread)->main();

	// if main returns, the Thread object needs to get cleaned up
	// this should happen automatically because of our use of the thread-specific data
	// to hold the Thread instance

	// }}}USR
}
// }}}RME

// {{{RME operation 'sleep(unsigned int)'
unsigned int Thread::sleep( unsigned int seconds )
{
	// {{{USR
	return 0; //::sleep(seconds);
	// }}}USR
}
// }}}RME

// {{{RME operation 'nanosleep(const TimeSpec,TimeSpec *)'
bool Thread::nanosleep( const TimeSpec requestedTime, TimeSpec * remainingTime )
{
/*	// {{{USR  
	struct timespec rqts, rmts;
	bool worked;

	rqts.tv_sec = requestedTime.getSeconds();
	rqts.tv_nsec = requestedTime.getNanoseconds();

	worked = (::nanosleep(&rqts, &rmts) == 0);

	if (remainingTime != 0)
	{
		remainingTime->setSeconds(rmts.tv_sec);
		remainingTime->setNanoseconds(rmts.tv_nsec);
	}
*/
	return true; //worked;

	// }}}USR
}
// }}}RME

// {{{RME operation 'setPriority(int)'
bool Thread::setPriority( int priority )
{
	// {{{USR
	int policy, retval;
//	struct sched_param sp;

	// this is not strictly thread-safe because two calls could be simultaneous and
	// the
//	if (!(retval = pthread_getschedparam(m_pthread, &policy, &sp)))
//	{
//		sp.sched_priority = priority;
//		retval = pthread_setschedparam(m_pthread, policy, &sp);
//	}

	return (retval == 0);
	// }}}USR
}
// }}}RME

// {{{RME operation 'getPriority()'
int Thread::getPriority( void ) const
{
	// {{{USR
	//int policy;
	//struct sched_param sp;

	//pthread_getschedparam(m_pthread, &policy, &sp);
	//return sp.sched_priority;
	return 1;
	// }}}USR
}
// }}}RME

// {{{RME operation 'main()'
void * Thread::main( void )
{
	// {{{USR
	// default main routine does nothing
	return 0;
	// }}}USR
}
// }}}RME

// {{{RME operation 'actuallyCreateThread(int,Thread *,uint16_t)'
Thread * Thread::actuallyCreateThread( int priority, Thread * thread, uint16_t stackSize )
{
	// {{{USR  /*
	int retval;  /*
	pthread_attr_t attr;
	struct sched_param sp;

	if ((priority < getSysPriorityMin()) || (priority > getSysPriorityMax()))
	{
		delete thread;
		thread = 0;
	}
	else
	{
		retval = pthread_attr_init(&attr);
		if (retval == 0)
		{
			sp.sched_priority = priority;
			pthread_attr_setschedparam(&attr, &sp);
			pthread_attr_setschedpolicy(&attr, Implementation::getSchedPolicy());
	        pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED );

	        pthread_attr_setstacksize(&attr, stackSize);

			retval = pthread_create(&(thread->m_pthread),
	                   			 	&attr,
	                   			 	g_staticStart,
	                   			 	(void *) thread);
			pthread_attr_destroy(&attr);
		}
		if (retval != 0)
		{
			delete thread;
			thread = 0;
			// once we have data logging: use retval
			// EINVAL: invalid value - log a "weird" error
			// EAGAIN: out of resources
			// ENOMEM: out of memory
		}
	}
*/
	return 0; // thread;

	// }}}USR
}
// }}}RME

// {{{RME operation 'createThread(int,uint16_t)'
Thread * Thread::createThread( int priority, uint16_t stackSize )
{
	// {{{USR
	// This method should should be cut and pasted to be reused by
	// subclasses of Thread replacing "new Thread()" with a new of
	// the correct class.

	// add error logging

	return actuallyCreateThread(priority, new Thread(), stackSize);

	// }}}USR
}
// }}}RME

// {{{RME operation 'getPriorityMax()'
int Thread::getPriorityMax( void )
{
	// {{{USR
	return (m_priorityMax);
	// }}}USR
}
// }}}RME

// {{{RME operation 'getPriorityMin()'
int Thread::getPriorityMin( void )
{
	// {{{USR
	return (m_priorityMin);
	// }}}USR
}
// }}}RME

// {{{RME operation 'clearThreadInstance()'
void Thread::clearThreadInstance( void )
{
	// {{{USR
//	pthread_setspecific(m_threadInstanceKey, 0);

	// }}}USR
}
// }}}RME

// {{{RME operation 'destructor(void *)'
void Thread::destructor( void * obj )
{
	// {{{USR
	Thread * t = (Thread *) obj;

	t->m_mutex->lock();

	// clear the thread-specific data so POSIX will know this worked
	t->clearThreadInstance();

	if (t->m_detached)
	{
		t->m_mutex->unlock();
		cleanup(t);
	}
	else
	{
		t->m_dead = true;
		t->m_mutex->unlock();
	}


	// }}}USR
}
// }}}RME

// {{{RME operation 'cleanup(const Thread *)'
void Thread::cleanup( const Thread * threadToCleanup )
{
	// {{{USR
	m_staticMutex->lock();

	delete m_threadToCleanup;

	m_threadToCleanup = (Thread *) threadToCleanup;

	m_staticMutex->unlock();

	// }}}USR
}
// }}}RME

// {{{RME operation 'staticInit()'
void Thread::staticInit( void )
{
	// {{{USR
/*	if (m_staticMutex == 0)
	{
		m_staticMutex = Mutex::createMutex(); // add error-logging here

		// create a key for keeping the thread object instance in thread-specific data
		if (pthread_key_create(&m_threadInstanceKey, g_threadDestructor) != 0)
		{
			// error logging here
		}
	}

	// Setup default Minimum and Maximum Priority Levels
	   m_priorityMax = Thread::getSysPriorityMax();
	   m_priorityMin = Thread::getSysPriorityMin();
*/
	// }}}USR
}
// }}}RME

// {{{RME operation 'yield()'
int Thread::yield( void )
{
	// {{{USR
	return 0; //sched_yield();
	// }}}USR
}
// }}}RME

// {{{RME operation 'getSysPriorityMax()'
int Thread::getSysPriorityMax( void )
{
	// {{{USR
	return 0; //sched_get_priority_max(Implementation::getSchedPolicy());
	// }}}USR
}
// }}}RME

// {{{RME operation 'getSysPriorityMin()'
int Thread::getSysPriorityMin( void )
{
	// {{{USR
	return 0; //sched_get_priority_min(Implementation::getSchedPolicy());
	// }}}USR
}
// }}}RME

// {{{RME operation 'setPriorityMax(int)'
bool Thread::setPriorityMax( int priority )
{
	// {{{USR
	bool ret_val = false;

//	if ((priority <= getSysPriorityMax()) && (priority >= getSysPriorityMin()) && (priority >= m_priorityMin))
//	{
//	   m_priorityMax = priority;
//	   ret_val = true;
//	}
	   
	return (ret_val);
	// }}}USR
}
// }}}RME

// {{{RME operation 'setPriorityMin(int)'
bool Thread::setPriorityMin( int priority )
{
	// {{{USR
	bool ret_val = false;

//	if ((priority <= getSysPriorityMax()) && (priority >= getSysPriorityMin()) && (priority <= m_priorityMax))
//	{
//	   m_priorityMin = priority;
//	   ret_val = true;
//	}
	   
	return (ret_val);
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
