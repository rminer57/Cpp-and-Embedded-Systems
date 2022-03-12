// {{{RME classifier 'Logical View::OS Abstraction Layer::Timer'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Timer.h"
#endif

#include <osal_build.h>
#include <Timer.h>
#include <Clock.h>
#include <MessageQueue.h>
#include <Mutex.h>
#include <Thread.h>
#include <TimeSpec.h>
#include <TimerAction.h>
#include <TimerExpirationMsg.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR


extern "C" {

#include <unistd.h>
#include <time.h>
#include "minsignal.h"
#include <sched.h>
#include <pthread.h>

static void g_timerNotify(union sigval sigvalue);


static void g_timerNotify(union sigval sigvalue)
{
	( (Timer *) sigvalue.sival_ptr )->timerNotify( (Timer *) sigvalue.sival_ptr  );
}


}

// }}}USR
// }}}RME
// {{{RME classifier 'ExpMsgList' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classifier 'ExpMsgList'

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
Timer::ExpMsgList::~ExpMsgList( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
Timer::ExpMsgList::ExpMsgList( const ExpMsgList & rtg_arg )
	: m_next( rtg_arg.m_next )
	, m_msg( rtg_arg.m_msg )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
Timer::ExpMsgList & Timer::ExpMsgList::operator=( const ExpMsgList & rtg_arg )
{
	if( this != &rtg_arg )
	{
		m_next = rtg_arg.m_next;
		m_msg = rtg_arg.m_msg;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'ExpMsgList(TimerExpirationMsg *,ExpMsgList *)'
Timer::ExpMsgList::ExpMsgList( TimerExpirationMsg * msg, ExpMsgList * next )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	m_msg = msg;
	m_next = next;
	// }}}USR
}
// }}}RME

// {{{RME operation 'add(TimerExpirationMsg *)'
void Timer::ExpMsgList::add( TimerExpirationMsg * msg )
{
	// {{{USR
	if (m_msg == 0)
	{
		m_msg = msg;
	}
	else
	{
		m_next = new ExpMsgList(msg, m_next);
	}

	// }}}USR
}
// }}}RME

// {{{RME operation 'remove(TimerExpirationMsg *)'
TimerExpirationMsg * Timer::ExpMsgList::remove( TimerExpirationMsg * msg )
{
	// {{{USR
	ExpMsgList *it, *previous, *tmp;
	TimerExpirationMsg *retval = 0;

	// find the message
	for (it = this, previous = 0; it != 0; it = it->m_next)
	{
		// if the msg looked for is 0, just return the first one
		if ((msg == 0) || (it->m_msg == msg))
		{
			// message found
			retval = it->m_msg;

			// if not the first entry, delete the entry
			if (it != this)
			{
				previous->m_next = it->m_next;
				delete it;
			}
			else
			{
				// if it is the first entry, check if the only entry
				if (m_next == 0)
				{
					// if only entry, just zero out
					m_msg = 0;
				}
				else
				{
					// if there is a next entry, move the value of next to me and delete
					// the next entry so that we always keep the first entry
					m_msg = m_next->m_msg;
					tmp = m_next;
					m_next = m_next->m_next;
					delete tmp;
				}
			}
			break;
		}
		previous = it;
	}

	return retval;

	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME classAttribute 'm_zeroTime'
const TimerSetting Timer::m_zeroTime( TimeSpec(), false, TimeSpec() );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
Timer::Timer( void )
	: m_sequenceNum( 0 )
	, m_action( 0 )
	, m_mutex( Mutex::createMutex() )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
Timer::Timer( const Timer & rtg_arg )
	: m_timerId( rtg_arg.m_timerId )
	, m_sequenceNum( rtg_arg.m_sequenceNum )
	, m_msgQ( rtg_arg.m_msgQ )
	, m_msgpri( rtg_arg.m_msgpri )
	, m_action( rtg_arg.m_action )
	, m_mutex( rtg_arg.m_mutex )
	, m_nextExpirationTime( rtg_arg.m_nextExpirationTime )
	, m_clock( rtg_arg.m_clock )
	, m_intervalTime( rtg_arg.m_intervalTime )
	, m_msgList( rtg_arg.m_msgList )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
Timer & Timer::operator=( const Timer & rtg_arg )
{
	if( this != &rtg_arg )
	{
		m_timerId = rtg_arg.m_timerId;
		m_sequenceNum = rtg_arg.m_sequenceNum;
		m_msgQ = rtg_arg.m_msgQ;
		m_msgpri = rtg_arg.m_msgpri;
		m_action = rtg_arg.m_action;
		m_mutex = rtg_arg.m_mutex;
		m_nextExpirationTime = rtg_arg.m_nextExpirationTime;
		m_clock = rtg_arg.m_clock;
		m_intervalTime = rtg_arg.m_intervalTime;
		m_msgList = rtg_arg.m_msgList;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'setTime(const TimerSetting *,TimerSetting *)'
bool Timer::setTime( const TimerSetting * value, TimerSetting * ovalue )
{
	// {{{USR
	bool retval;
	struct itimerspec val, oval;

	// This mutex makes sure a timer notification and setTime() will be synchronized.
	m_mutex->lock();

	// If timerNotify() runs due to a previous expiration, it will either get
	// the mutex first or block until this call is done.  In the first case,
	// it will have the old sequence number and can be detected as stale via
	// TimerExpirationMsg::isCurrent().  To cover the second case,
	// nextExpirationTime is to be set equal to Clock::getTime().  In this way,
	// when timerNotify() gets to run, it can check nextExpirationTime versus
	// Clock::getTime(), and if the nextExpirationTime is in the future, it
	// knows it is stale and should not use the new sequence number, or, in
	// fact, send a message at all.  This works even in the case of the
	// nextExpirationTime being really close and passing before the
	// timerNotify() gets to really run because the timer spec says if a
	// signal is still queued for an expiration, when the next expiration
	// happens, a new signal will NOT be generated.  Therefore, it is safe
	// to let timerNotify() use the new sequence number.

	m_nextExpirationTime = value->getFirstTimeAbsolute() ? 0 : m_clock->getTime();
	m_nextExpirationTime += value->getFirstTime();
	m_intervalTime = TimeSpec(value->getIntervalTime());

	val.it_value.tv_sec = value->getFirstTime().getSeconds();
	val.it_value.tv_nsec = value->getFirstTime().getNanoseconds();
	val.it_interval.tv_sec = value->getIntervalTime().getSeconds();
	val.it_interval.tv_nsec = value->getIntervalTime().getNanoseconds();

	m_sequenceNum++;

	retval = (timer_settime(m_timerId, (value->getFirstTimeAbsolute() ? TIMER_ABSTIME : 0), &val, &oval)
			== 0);

	if (ovalue != 0)
	{
		ovalue->setFirstTime(TimeSpec(oval.it_value.tv_sec, oval.it_value.tv_nsec));
		ovalue->setIntervalTime(TimeSpec(oval.it_interval.tv_sec, oval.it_interval.tv_nsec));
	}

	m_mutex->unlock();

	return retval;

	// }}}USR
}
// }}}RME

// {{{RME operation 'getTime(TimerSetting *)'
void Timer::getTime( TimerSetting * value ) const
{
	// {{{USR
	struct itimerspec its;

	if (value != 0)
	{
		timer_gettime(m_timerId, &its);
		value->setFirstTime(TimeSpec(its.it_value.tv_sec, its.it_value.tv_nsec));
		value->setIntervalTime(TimeSpec(its.it_interval.tv_sec, its.it_interval.tv_nsec));
	}


	// }}}USR
}
// }}}RME

// {{{RME operation '~Timer()'
Timer::~Timer( void )
{
	// {{{USR
	TimerExpirationMsg *msg;

	// first kill the timer, then grab the mutex below, which ensures we
	// wait for any active timer notifications to finish before deleting
	// the Timer, and that no more notifications will happen.
	timer_delete(m_timerId);

	m_mutex->lock();

	if (m_action != 0)
	{
		delete m_action;
	}

	// update any active messages so they know their Timer is gone
	while (msg = m_msgList.remove())
	{
		msg->clearTimer();
	}

	m_mutex->unlock();
	delete m_mutex;

	// }}}USR
}
// }}}RME

// {{{RME operation 'timerNotify(Timer *)'
void Timer::timerNotify( Timer * timer )
{
	// {{{USR
	TimerExpirationMsg * msg;

	// See the description in setTime() for a full explanation as to
	// how and why this mutex is used.

	timer->m_mutex->lock();

	// if the next expiration time is in the future, don't send a
	// message, someone must have called setTime() just now
	if (timer->m_nextExpirationTime <= timer->m_clock->getTime())
	{
		msg = new TimerExpirationMsg(++(timer->m_sequenceNum), timer);
		timer->registerExpirationMsg(msg);
		timer->m_nextExpirationTime += timer->m_intervalTime;
		timer->m_msgQ->send(msg);
	}

	timer->m_mutex->unlock();

	// }}}USR
}
// }}}RME

// {{{RME operation 'Timer(Clock *,MessageQueue *,unsigned int,TimerAction *,int *)'
Timer::Timer( Clock * clock, MessageQueue * messageQueue, unsigned int priority, TimerAction * action, int * retValPtr )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_clock(clock), m_msgQ(messageQueue),m_msgpri(priority), m_action(action),
	/* these are added because Rational Rose does not add these at it should */
	m_mutex(Mutex::createMutex()), m_sequenceNum(0), m_msgList(0)
	// }}}USR
	// }}}RME
{
	// {{{USR
	int retval;
	struct sigevent evp;
	pthread_attr_t attr;
	struct sched_param sp;

	evp.sigev_notify = SIGEV_THREAD;
	evp.sigev_value.sival_ptr = this;
	//evp.sigev_notify_function = &(Timer::timerNotify);
	evp.sigev_notify_function = g_timerNotify;


	// need to make the notifications happen at the highest priority
	if (pthread_attr_init(&attr) == 0)
	{
		sp.sched_priority = Thread::getSysPriorityMax();
		pthread_attr_setschedparam(&attr, &sp);
	    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
		evp.sigev_notify_attributes = &attr;
	}
	else
	{
		evp.sigev_notify_attributes = NULL;
	}

	retval = timer_create(clock->m_clockId, &evp, &m_timerId);

	if (evp.sigev_notify_attributes != NULL)
	{
		pthread_attr_destroy(&attr);
	}

	if (retValPtr)
		*retValPtr = retval;

	// }}}USR
}
// }}}RME

// {{{RME operation 'isCurrent(TimerExpirationMsg *)'
bool Timer::isCurrent( TimerExpirationMsg * msg )
{
	// {{{USR
	return (msg->getSequenceNum() == m_sequenceNum);
	// }}}USR
}
// }}}RME

// {{{RME operation 'stop(TimerSetting *)'
void Timer::stop( TimerSetting * ovalue )
{
	// {{{USR
	// itimerspec with an it_value of zero disarms the timer
	setTime(&m_zeroTime, ovalue);


	// }}}USR
}
// }}}RME

// {{{RME operation 'action()'
bool Timer::action( void )
{
	// {{{USR
	return (m_action != 0) ? m_action->action() : false;

	// }}}USR
}
// }}}RME

// {{{RME operation 'setAction(TimerAction *)'
void Timer::setAction( TimerAction * action )
{
	// {{{USR
	delete m_action;
	m_action = action;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getAction()'
TimerAction * Timer::getAction( void )
{
	// {{{USR
	return m_action;
	// }}}USR
}
// }}}RME

// {{{RME operation 'registerExpirationMsg(TimerExpirationMsg *)'
void Timer::registerExpirationMsg( TimerExpirationMsg * msg )
{
	// {{{USR
	m_msgList.add(msg);
	// }}}USR
}
// }}}RME

// {{{RME operation 'deregisterExpirationMsg(TimerExpirationMsg *)'
void Timer::deregisterExpirationMsg( TimerExpirationMsg * msg )
{
	// {{{USR
	m_msgList.remove(msg);

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'ExpMsgList' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
