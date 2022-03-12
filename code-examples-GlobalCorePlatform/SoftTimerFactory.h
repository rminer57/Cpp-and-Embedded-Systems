// {{{RME classifier 'Logical View::Timers::SoftTimerFactory'

#ifndef SoftTimerFactory_H
#define SoftTimerFactory_H

#ifdef PRAGMA
#pragma interface "SoftTimerFactory.h"
#endif

#include <softtimers.h>
#include <SoftTimer.h>
#include <Thread.h>
#include <TimerVirtual.h>
#include <TimerVirtualFactory.h>
class Clock;
class Message;
class MessageQueue;
class Mutex;
class Timer;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Entry' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class SoftTimerFactory : public Thread, public TimerVirtualFactory
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR
	friend class SoftTimer;
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
	// {{{RME classifier 'Entry'
	class Entry
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
		// {{{RME associationEnd 'm_timer'
		SoftTimer * m_timer;
		// }}}RME
		// {{{RME associationEnd 'm_next'
		Entry * m_next;
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
		Entry( void );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
		virtual ~Entry( void );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
		Entry( const Entry & rtg_arg );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
		Entry & operator=( const Entry & rtg_arg );
		// }}}RME
		// {{{RME operation 'Entry(SoftTimer*,SoftTimerFactory::Entry*)'
		Entry( SoftTimer * timer, Entry * next = 0 );
		// }}}RME
	};
	// }}}RME

private:
	// {{{RME classAttribute 'm_rate'
	unsigned int m_rate;
	// }}}RME

protected:
	// {{{RME classAttribute 'm_nameNo'
	static char m_nameNo;
	// }}}RME
	// {{{RME associationEnd 'm_mutex'
	Mutex * m_mutex;
	// }}}RME
	// {{{RME associationEnd 'm_timerList'
	Entry * m_timerList;
	// }}}RME

private:
	// {{{RME associationEnd 'm_queue'
	MessageQueue * m_queue;
	// }}}RME
	// {{{RME associationEnd 'm_clock'
	Clock * m_clock;
	// }}}RME
	// {{{RME associationEnd 'm_timer'
	Timer * m_timer;
	// }}}RME

protected:
	// {{{RME associationEnd 'm_event'
	TimerVirtual::Event * m_event;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	SoftTimerFactory( const SoftTimerFactory & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	SoftTimerFactory & operator=( const SoftTimerFactory & rtg_arg );
	// }}}RME

protected:
	// {{{RME operation 'main()'
	virtual void * main( void );
	// }}}RME

public:
	// {{{RME operation 'SoftTimerFactory(unsigned int,int)'
	SoftTimerFactory( unsigned int rate = 1, int pri = Thread::getPriorityMin() );
	// }}}RME
	// {{{RME operation '~SoftTimerFactory()'
	~SoftTimerFactory( void );
	// }}}RME
	// {{{RME operation 'getTimerVirtual(bool)'
	virtual TimerVirtual * getTimerVirtual( bool autoRearm = true );
	// }}}RME

private:
	// {{{RME operation 'remove(TimerVirtual *)'
	void remove( TimerVirtual * tim );
	// }}}RME

protected:
	// {{{RME operation 'SoftTimerFactory(Mutex *)'
	SoftTimerFactory( Mutex * mutex );
	// }}}RME
	// {{{RME operation 'advance(unsigned int)'
	void advance( unsigned int count = 1 );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Entry' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* SoftTimerFactory_H */

// }}}RME
