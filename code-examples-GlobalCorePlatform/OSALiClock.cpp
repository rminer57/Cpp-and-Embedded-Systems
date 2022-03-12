// {{{RME classifier 'Logical View::OS Abstraction Layer::OSALi_win32::OSALiClock'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "OSALiClock.h"
#endif

#include <osal_build.h>
#include <OSALiClock.h>
#include <TimeSpec.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'm_realtimeClock'
OSALiClock * OSALiClock::m_realtimeClock = 0;
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
OSALiClock::OSALiClock( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
OSALiClock::OSALiClock( const OSALiClock & rtg_arg )
	: Clock( rtg_arg )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
OSALiClock & OSALiClock::operator=( const OSALiClock & rtg_arg )
{
	if( this != &rtg_arg )
		Clock::operator=( rtg_arg );
	return *this;
}
// }}}RME

// {{{RME operation 'getClock(TimeSpec)'
Clock * OSALiClock::getClock( TimeSpec minimumResolution )
{
	// {{{USR
	if (m_realtimeClock == 0)
	{
		m_realtimeClock = new OSALiClock();
		m_realtimeClock->m_clockId = CLOCK_REALTIME;
	}

	// If the user omits the TimeSpec parameter, a default Timespec will be constructed and
	// passed in by value.  The default Timespec will be constructed with 0sec and 0nsec.  This 
	// case needs to return successfully.

	if (((minimumResolution.getSeconds() == 0) && (minimumResolution.getNanoseconds() == 0)) ||
	   (m_realtimeClock->getResolution() <= minimumResolution))
	{
	   return (m_realtimeClock);
	}
	else
	{
	   return (0);
	}
	// }}}USR
}
// }}}RME

// {{{RME operation '~OSALiClock()'
OSALiClock::~OSALiClock( void )
{
	// {{{USR
	if (this == m_realtimeClock)
	{
		m_realtimeClock = 0;
	}
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
