// {{{RME classifier 'Logical View::Timers::SoftTimerFactory'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "SoftTimerFactory.h"
#endif

#include <softtimers.h>
#include <SoftTimerFactory.h>
#include <Clock.h>
#include <Message.h>
#include <MessageQueue.h>
#include <Mutex.h>
#include <Timer.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Entry' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classifier 'Entry'

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
SoftTimerFactory::Entry::Entry( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
SoftTimerFactory::Entry::~Entry( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
SoftTimerFactory::Entry::Entry( const Entry & rtg_arg )
	: m_timer( rtg_arg.m_timer )
	, m_next( rtg_arg.m_next )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
SoftTimerFactory::Entry & SoftTimerFactory::Entry::operator=( const Entry & rtg_arg )
{
	if( this != &rtg_arg )
	{
		m_timer = rtg_arg.m_timer;
		m_next = rtg_arg.m_next;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'Entry(SoftTimer*,SoftTimerFactory::Entry*)'
SoftTimerFactory::Entry::Entry( SoftTimer * timer, Entry * next )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_timer(timer),m_next(next)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME classAttribute 'm_nameNo'
char SoftTimerFactory::m_nameNo = 'A';
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
SoftTimerFactory::SoftTimerFactory( const SoftTimerFactory & rtg_arg )
	: Thread( rtg_arg )
	, TimerVirtualFactory( rtg_arg )
	, m_rate( rtg_arg.m_rate )
	, m_mutex( rtg_arg.m_mutex )
	, m_timerList( rtg_arg.m_timerList )
	, m_queue( rtg_arg.m_queue )
	, m_clock( rtg_arg.m_clock )
	, m_timer( rtg_arg.m_timer )
	, m_event( rtg_arg.m_event )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
SoftTimerFactory & SoftTimerFactory::operator=( const SoftTimerFactory & rtg_arg )
{
	if( this != &rtg_arg )
	{
		Thread::operator=( rtg_arg );
		TimerVirtualFactory::operator=( rtg_arg );
		m_rate = rtg_arg.m_rate;
		m_mutex = rtg_arg.m_mutex;
		m_timerList = rtg_arg.m_timerList;
		m_queue = rtg_arg.m_queue;
		m_clock = rtg_arg.m_clock;
		m_timer = rtg_arg.m_timer;
		m_event = rtg_arg.m_event;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'main()'
void * SoftTimerFactory::main( void )
{
	// {{{USR
	//Create message queue for timer events...
	char name[10] = "mytimer1 ";
	name[8] = m_nameNo++;

	MessageQueue::remove(name);
	MessageQueue::create(name);
	m_queue = MessageQueue::open(name);

	//Get clock and timer
	TimeSpec tm;
	tm.setSeconds(m_rate / 1000);					//setup seconds portion based on milli-second rate
	tm.setNanoseconds((m_rate % 1000) * 1000000);	//setup remainder
	TimerSetting ts(tm,false,tm);

	m_clock = Clock::getClock(tm);
	m_timer = m_clock->createTimer(m_queue,Thread::getPriorityMin());
	m_timer->setTime(&ts);

	Message *msg;

	while(1)
	{
		msg = m_queue->receive();					//the only message that can be received is a timeout...
		delete msg;

		advance();
	}
	// }}}USR
}
// }}}RME

// {{{RME operation 'SoftTimerFactory(unsigned int,int)'
SoftTimerFactory::SoftTimerFactory( unsigned int rate, int pri )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_rate(rate),m_timerList(0)
	// }}}USR
	// }}}RME
{
	// {{{USR
	m_mutex = Mutex::createMutex();
	m_event = new TimerVirtual::Event();

	// Create the tread last so that everything else is fully initialized when the thread starts running.
	actuallyCreateThread(pri, this);
	// }}}USR
}
// }}}RME

// {{{RME operation '~SoftTimerFactory()'
SoftTimerFactory::~SoftTimerFactory( void )
{
	// {{{USR
	delete m_mutex;
	delete m_event;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getTimerVirtual(bool)'
TimerVirtual * SoftTimerFactory::getTimerVirtual( bool autoRearm )
{
	// {{{USR
	SoftTimer *tim = new SoftTimer(this,autoRearm,m_event);
	m_timerList = new Entry(tim,m_timerList);							//Add new entry to start of list

	return tim;
	// }}}USR
}
// }}}RME

// {{{RME operation 'remove(TimerVirtual *)'
void SoftTimerFactory::remove( TimerVirtual * tim )
{
	// {{{USR
	//First, locate the timer in the list...

	Entry *current = m_timerList;
	Entry *prev =0;

	while (current != 0)
	{
		//if found, update list..
		if (current->m_timer == tim)
		{
			m_mutex->lock();

			//If this is the first entry in the list, update start
			if (prev == 0)
			{
				m_timerList = current->m_next;
			}
			else
			{
				prev->m_next = current->m_next;
			}
			
			delete current;

			m_mutex->unlock();
			current = 0;							//exit loop
		}
		else
		{
			prev = current;
			current = current->m_next;
		}
	}










	// }}}USR
}
// }}}RME

// {{{RME operation 'SoftTimerFactory(Mutex *)'
SoftTimerFactory::SoftTimerFactory( Mutex * mutex )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	:m_timerList(0),m_mutex(mutex)
	// }}}USR
	// }}}RME
{
	// {{{USR
	m_event = new TimerVirtual::Event();
	// }}}USR
}
// }}}RME

// {{{RME operation 'advance(unsigned int)'
void SoftTimerFactory::advance( unsigned int count )
{
	// {{{USR
	Entry *current;

	m_mutex->lock();							//lock use of list...

	//Process all timers
	current = m_timerList;

	//Cycle through all timers, adjusting timeout
	while(current !=0)
	{
		current->m_timer->trigger(count);
		current = current->m_next;
	}

	m_mutex->unlock();
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Entry' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
