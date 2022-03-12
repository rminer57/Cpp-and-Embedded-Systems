// {{{RME classifier 'Logical View::OS Abstraction Layer::Timer'

#ifndef Timer_H
#define Timer_H

#ifdef PRAGMA
#pragma interface "Timer.h"
#endif

// {{{RME general 'documentation'
/* {{{USR
This class models a POSIX timer.  The methods map to the timer calls as described in the POSIX specification, with the qualification that messages are generated for timer expiration because signals are not supported in the profile under use.  A Timer gets created via the createTimer method on a Clock.  A MessageQueue, a message priority, and a TimerAction are provided at creation time.  When the timer expires, a TimerExpirationMsg is sent to the given MessageQueue with the given priority.  The TimerAction can then be executed by calling action() on the TimerExpirationMsg.  timer_overrun() is not supported because of the non-use of signals.  That functionality is replaced by the sequence number that is returned on every call to settime() to set up the timer.

As with the posix specification, specifying a ABSOLUTE TimerSetting that is in the past will cause the timer to expire immediately.  Specifying a TimerSetting of 0 will disable the timer and is equivallent to calling Timer::stop();  OS timers are guaranteed to expire and be serviced "at least" the time specified in the TimerSetting parameters, but it may be longer due to other thread priorities in the system.  User's should be discouraged from generate timers that are equal to the minimum clock resolution in your system (especially re-arming timers at that resolution).

The corresponding POSIX specification is attached to this class.
   }}}USR */
// }}}RME

#include <osal_build.h>
#include <TimerSetting.h>
class Clock;
class MessageQueue;
class Mutex;
class Thread;
class TimeSpec;
class TimerAction;
class TimerExpirationMsg;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include "Implementation.h"
// }}}USR
// }}}RME
// {{{RME classifier 'ExpMsgList' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class Timer
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR
	friend class Clock;
	friend class TimerSetting;
	friend class TimerExpirationMsg;
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
	// {{{RME classifier 'ExpMsgList'
	class ExpMsgList
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
		// {{{RME classAttribute 'm_next'
		ExpMsgList * m_next;
		// }}}RME
		// {{{RME classAttribute 'm_msg'
		TimerExpirationMsg * m_msg;
		// }}}RME

	public:
		// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
		virtual ~ExpMsgList( void );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
		ExpMsgList( const ExpMsgList & rtg_arg );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
		ExpMsgList & operator=( const ExpMsgList & rtg_arg );
		// }}}RME
		// {{{RME operation 'ExpMsgList(TimerExpirationMsg *,ExpMsgList *)'
		// {{{RME general 'documentation'
		/* {{{USR
		Constructor that takes optional parameters of a message to be part of the list and a next message list to make list addition convenient.
		   }}}USR */
		// }}}RME
		ExpMsgList( TimerExpirationMsg * msg = 0, ExpMsgList * next = 0 );
		// }}}RME
		// {{{RME operation 'add(TimerExpirationMsg *)'
		// {{{RME general 'documentation'
		/* {{{USR
		Adds a message to the list.
		   }}}USR */
		// }}}RME
		void add( TimerExpirationMsg * msg );
		// }}}RME
		// {{{RME operation 'remove(TimerExpirationMsg *)'
		// {{{RME general 'documentation'
		/* {{{USR
		Removes a message from the list. If 0 is provided, it removes the first entry.  A return of 0 says the entry was not found, or if 0 was passed in, that there are no more entries.
		   }}}USR */
		// }}}RME
		TimerExpirationMsg * remove( TimerExpirationMsg * msg = 0 );
		// }}}RME
	};
	// }}}RME

private:
	// {{{RME classAttribute 'm_timerId'
	timer_t m_timerId;
	// }}}RME
	// {{{RME classAttribute 'm_sequenceNum'
	unsigned int m_sequenceNum;
	// }}}RME
	// {{{RME classAttribute 'm_msgQ'
	MessageQueue * m_msgQ;
	// }}}RME
	// {{{RME classAttribute 'm_msgpri'
	unsigned int m_msgpri;
	// }}}RME
	// {{{RME classAttribute 'm_action'
	TimerAction * m_action;
	// }}}RME
	// {{{RME classAttribute 'm_mutex'
	Mutex * m_mutex;
	// }}}RME
	// {{{RME classAttribute 'm_zeroTime'
	static const TimerSetting m_zeroTime;
	// }}}RME
	// {{{RME classAttribute 'm_nextExpirationTime'
	TimeSpec m_nextExpirationTime;
	// }}}RME
	// {{{RME classAttribute 'm_clock'
	Clock * m_clock;
	// }}}RME
	// {{{RME classAttribute 'm_intervalTime'
	TimeSpec m_intervalTime;
	// }}}RME
	// {{{RME classAttribute 'm_msgList'
	ExpMsgList m_msgList;
	// }}}RME

protected:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	Timer( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	Timer( const Timer & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	Timer & operator=( const Timer & rtg_arg );
	// }}}RME

public:
	// {{{RME operation 'setTime(const TimerSetting *,TimerSetting *)'
	// {{{RME general 'documentation'
	/* {{{USR
	Sets the time until the next expiration and the reload value of the timer.  The absolute parameter sets whether absolute timing is used or not.  true is returned on success, and false is returned if the nanosecond value is greater than 1 billion.  If ovalue is provided, it is filled in with the remaining time and the old reload value.

	Ownership of the TimeSetting object passed in is retained by the caller.

	See the specification for timer_settime().
	   }}}USR */
	// }}}RME
	bool setTime( const TimerSetting * value, TimerSetting * ovalue = 0 );
	// }}}RME
	// {{{RME operation 'getTime(TimerSetting *)'
	// {{{RME general 'documentation'
	/* {{{USR
	Gets the time until the next expiration and the reload value of the timer.  See the specification for timer_gettime().
	   }}}USR */
	// }}}RME
	void getTime( TimerSetting * value ) const;
	// }}}RME
	// {{{RME operation '~Timer()'
	// {{{RME general 'documentation'
	/* {{{USR
	Deletes the timer.
	   }}}USR */
	// }}}RME
	~Timer( void );
	// }}}RME
	// {{{RME operation 'timerNotify(Timer *)'
	// {{{RME general 'documentation'
	/* {{{USR

	   }}}USR */
	// }}}RME
	static void timerNotify( Timer * timer );
	// }}}RME

protected:
	// {{{RME operation 'Timer(Clock *,MessageQueue *,unsigned int,TimerAction *,int *)'
	// {{{RME general 'documentation'
	/* {{{USR
	This constructor is protected because Clock:getTimer is to be used.

	   }}}USR */
	// }}}RME
	Timer( Clock * clock, MessageQueue * messageQueue, unsigned int priority, TimerAction * action = 0, int * retValPtr = 0 );
	// }}}RME
	// {{{RME operation 'isCurrent(TimerExpirationMsg *)'
	// {{{RME general 'documentation'
	/* {{{USR
	This method takes a TimerExpirationMsg and determines if it is current.  If a TimerExpirationMsg is sent to signal the expiration of this timer, then setTime is called on this timer before the TimerExpirationMsg is recieved, this method will allow detection of this stale TimerExpirationMsg.  This is required to replace the timer_overrun() functionality.
	   }}}USR */
	// }}}RME
	bool isCurrent( TimerExpirationMsg * msg );
	// }}}RME

public:
	// {{{RME operation 'stop(TimerSetting *)'
	// {{{RME general 'documentation'
	/* {{{USR
	This method stops the timer.  If ovalue is provided, it is filled in with the remaining time and the old reload value.  There is no equivalent direct call in POSIX - the timer_settime() interface is used.
	   }}}USR */
	// }}}RME
	void stop( TimerSetting * ovalue = 0 );
	// }}}RME
	// {{{RME operation 'action()'
	// {{{RME general 'documentation'
	/* {{{USR
	This method represents what is to be done when the timer expires.  The return value is true if it worked and false if it did not.
	   }}}USR */
	// }}}RME
	bool action( void );
	// }}}RME
	// {{{RME operation 'setAction(TimerAction *)'
	// {{{RME general 'documentation'
	/* {{{USR
	Sets the timer action.  Ownership of the action object transfers to the Timer object.
	   }}}USR */
	// }}}RME
	void setAction( TimerAction * action );
	// }}}RME
	// {{{RME operation 'getAction()'
	// {{{RME general 'documentation'
	/* {{{USR
	Gets the timer action.
	   }}}USR */
	// }}}RME
	TimerAction * getAction( void );
	// }}}RME

protected:
	// {{{RME operation 'registerExpirationMsg(TimerExpirationMsg *)'
	// {{{RME general 'documentation'
	/* {{{USR
	Registers an expiration message.  Done this way so the Timer knows about all messages out there and will "let them know" when the Timer is going away.
	   }}}USR */
	// }}}RME
	void registerExpirationMsg( TimerExpirationMsg * msg );
	// }}}RME
	// {{{RME operation 'deregisterExpirationMsg(TimerExpirationMsg *)'
	// {{{RME general 'documentation'
	/* {{{USR
	Deregisters an expiration message.  Done this way so the Timer knows about all messages out there and will "let them know" when the Timer is going away.
	   }}}USR */
	// }}}RME
	void deregisterExpirationMsg( TimerExpirationMsg * msg );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'ExpMsgList' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Timer_H */

// }}}RME
