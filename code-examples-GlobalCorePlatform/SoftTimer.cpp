// {{{RME classifier 'Logical View::Timers::SoftTimer'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "SoftTimer.h"
#endif

#include <softtimers.h>
#include <SoftTimer.h>
#include <SoftTimerFactory.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
SoftTimer::SoftTimer( const SoftTimer & rtg_arg )
	: TimerVirtual( rtg_arg )
	, m_rearm( rtg_arg.m_rearm )
	, m_initialCount( rtg_arg.m_initialCount )
	, m_count( rtg_arg.m_count )
	, m_parent( rtg_arg.m_parent )
	, m_event( rtg_arg.m_event )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
SoftTimer & SoftTimer::operator=( const SoftTimer & rtg_arg )
{
	if( this != &rtg_arg )
	{
		TimerVirtual::operator=( rtg_arg );
		m_rearm = rtg_arg.m_rearm;
		m_initialCount = rtg_arg.m_initialCount;
		m_count = rtg_arg.m_count;
		m_parent = rtg_arg.m_parent;
		m_event = rtg_arg.m_event;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'SoftTimer(SoftTimerFactory*,bool,TimerVirtual::Event *)'
SoftTimer::SoftTimer( SoftTimerFactory * parent, bool rearm, TimerVirtual::Event * event )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_rearm(rearm), m_count(0), m_initialCount(0), m_parent(parent)
	// }}}USR
	// }}}RME
{
	// {{{USR
	m_event = event;
	// }}}USR
}
// }}}RME

// {{{RME operation 'trigger(unsigned int)'
void SoftTimer::trigger( unsigned int count )
{
	// {{{USR
	//If the timer is running...
	if (m_initialCount != 0)
	{
		//If count  expires, determine next step...
		if (m_count <= count)
		{
			//restore the initial count
			m_count = m_initialCount;
			
			//forces timer to stop...	
			if (!m_rearm) m_initialCount = 0;				

			//let clients know the timeout has occurred.
			//note that listeners may set a new timer
			//value from within the listener. Therefore
			//any manipulation of the timer related attibutes
			//must occur before calling inform listeners.			
			informListeners(m_event);						
		}
		else
		{
			//decrement the timer by the count
			m_count -= count;								
		}

	}
	// }}}USR
}
// }}}RME

// {{{RME operation 'set(unsigned int)'
void SoftTimer::set( unsigned int count )
{
	// {{{USR
	m_count = count;
	m_initialCount = count;

	// }}}USR
}
// }}}RME

// {{{RME operation 'get()'
unsigned int SoftTimer::get( void ) const
{
	// {{{USR
	return m_count;
	// }}}USR
}
// }}}RME

// {{{RME operation '~SoftTimer()'
SoftTimer::~SoftTimer( void )
{
	// {{{USR
	m_parent->remove(this);
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
