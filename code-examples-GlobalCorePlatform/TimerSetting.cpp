// {{{RME classifier 'Logical View::OS Abstraction Layer::TimerSetting'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "TimerSetting.h"
#endif

#include <osal_build.h>
#include <TimerSetting.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
extern "C" {
#include <unistd.h>
#include <time.h>
}
// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
TimerSetting::~TimerSetting( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
TimerSetting::TimerSetting( const TimerSetting & rtg_arg )
	: m_intervalTime( rtg_arg.m_intervalTime )
	, m_firstTime( rtg_arg.m_firstTime )
	, m_firstTimeAbsolute( rtg_arg.m_firstTimeAbsolute )
	, ownee( rtg_arg.ownee )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
TimerSetting & TimerSetting::operator=( const TimerSetting & rtg_arg )
{
	if( this != &rtg_arg )
	{
		m_intervalTime = rtg_arg.m_intervalTime;
		m_firstTime = rtg_arg.m_firstTime;
		m_firstTimeAbsolute = rtg_arg.m_firstTimeAbsolute;
		ownee = rtg_arg.ownee;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'TimerSetting(TimeSpec,bool,TimeSpec)'
TimerSetting::TimerSetting( TimeSpec firstTime, bool firstTimeAbsolute, TimeSpec intervalTime )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_firstTimeAbsolute(firstTimeAbsolute),
	  m_firstTime(firstTime),
	  m_intervalTime(intervalTime)



	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'setFirstTime(TimeSpec,bool)'
void TimerSetting::setFirstTime( TimeSpec time, bool absolute )
{
	// {{{USR
	m_firstTimeAbsolute = absolute;
	m_firstTime = time;

	// }}}USR
}
// }}}RME

// {{{RME operation 'setIntervalTime(TimeSpec)'
void TimerSetting::setIntervalTime( TimeSpec time )
{
	// {{{USR
	m_intervalTime = time;

	// }}}USR
}
// }}}RME

// {{{RME operation 'getFirstTime()'
TimeSpec TimerSetting::getFirstTime( void ) const
{
	// {{{USR
	return m_firstTime;


	// }}}USR
}
// }}}RME

// {{{RME operation 'getIntervalTime()'
TimeSpec TimerSetting::getIntervalTime( void ) const
{
	// {{{USR
	return m_intervalTime;

	// }}}USR
}
// }}}RME

// {{{RME operation 'getFirstTimeAbsolute()'
bool TimerSetting::getFirstTimeAbsolute( void ) const
{
	// {{{USR
	return m_firstTimeAbsolute;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
