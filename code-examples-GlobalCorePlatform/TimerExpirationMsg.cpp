// {{{RME classifier 'Logical View::OS Abstraction Layer::TimerExpirationMsg'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "TimerExpirationMsg.h"
#endif

#include <osal_build.h>
#include <TimerExpirationMsg.h>
#include <Mutex.h>
#include <Timer.h>
#include <TimerAction.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
extern "C" {
#include <unistd.h>
#include <time.h>
}
// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
TimerExpirationMsg::TimerExpirationMsg( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
TimerExpirationMsg::TimerExpirationMsg( const TimerExpirationMsg & rtg_arg )
	: Message( rtg_arg )
	, m_timer( rtg_arg.m_timer )
	, m_sequenceNum( rtg_arg.m_sequenceNum )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
TimerExpirationMsg & TimerExpirationMsg::operator=( const TimerExpirationMsg & rtg_arg )
{
	if( this != &rtg_arg )
	{
		Message::operator=( rtg_arg );
		m_timer = rtg_arg.m_timer;
		m_sequenceNum = rtg_arg.m_sequenceNum;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'getType()'
ClassType TimerExpirationMsg::getType( void ) const
{
	// {{{USR
	return GENERAL_MSG_TYPE_TIMER_EXPIRATION;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool TimerExpirationMsg::isType( ClassType type ) const
{
	// {{{USR
	return (type == GENERAL_MSG_TYPE_TIMER_EXPIRATION) ? true : Message::isType(type);
	// }}}USR
}
// }}}RME

// {{{RME operation 'getSequenceNum()'
unsigned int TimerExpirationMsg::getSequenceNum( void ) const
{
	// {{{USR
	return m_sequenceNum;
	// }}}USR
}
// }}}RME

// {{{RME operation 'TimerExpirationMsg(unsigned int,Timer *)'
TimerExpirationMsg::TimerExpirationMsg( unsigned int seqNum, Timer * timer )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_timer(timer), m_sequenceNum(seqNum)

	// }}}USR
	// }}}RME
{
	// {{{USR
	if (timer != 0)
	{
		setPriority(timer->m_msgpri);
	}
	// }}}USR
}
// }}}RME

// {{{RME operation 'getTimer()'
Timer * TimerExpirationMsg::getTimer( void ) const
{
	// {{{USR
	return m_timer;
	// }}}USR
}
// }}}RME

// {{{RME operation 'serialize()'
Array * TimerExpirationMsg::serialize( void )
{
	// {{{USR
	// timer services are only supported in the same address space as of now
	return 0;

	// }}}USR
}
// }}}RME

// {{{RME operation 'unserialize(Array *)'
bool TimerExpirationMsg::unserialize( Array * buf )
{
	// {{{USR
	// timer services are only supported in the same address space as of now
	return false;

	// }}}USR
}
// }}}RME

// {{{RME operation 'getMaxSize()'
unsigned int TimerExpirationMsg::getMaxSize( void )
{
	// {{{USR
	return sizeof(TimerExpirationMsg);
	// }}}USR
}
// }}}RME

// {{{RME operation 'isCurrent()'
bool TimerExpirationMsg::isCurrent( void )
{
	// {{{USR
	return (m_timer != 0) ? m_timer->isCurrent(this) : false;
	// }}}USR
}
// }}}RME

// {{{RME operation 'action()'
bool TimerExpirationMsg::action( void )
{
	// {{{USR
	return (m_timer != 0) ? m_timer->action() : false;

	// }}}USR
}
// }}}RME

// {{{RME operation 'getAction()'
TimerAction * TimerExpirationMsg::getAction( void )
{
	// {{{USR
	return (m_timer != 0) ? m_timer->getAction() : 0;
	// }}}USR
}
// }}}RME

// {{{RME operation '~TimerExpirationMsg()'
TimerExpirationMsg::~TimerExpirationMsg( void )
{
	// {{{USR
	if (m_timer != 0)
	{
		m_timer->deregisterExpirationMsg(this);
	}

	// }}}USR
}
// }}}RME

// {{{RME operation 'clearTimer()'
void TimerExpirationMsg::clearTimer( void )
{
	// {{{USR
	m_timer = 0;

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
