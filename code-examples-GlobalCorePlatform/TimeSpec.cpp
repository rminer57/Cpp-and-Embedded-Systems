// {{{RME classifier 'Logical View::OS Abstraction Layer::TimeSpec'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "TimeSpec.h"
#endif

#include <osal_build.h>
#include <TimeSpec.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'BILLION'
const uint32_t TimeSpec::BILLION( 1000000000 );
// }}}RME

// {{{RME classAttribute 'UINTMAX'
const uint32_t TimeSpec::UINTMAX = (uint32_t) 0 - 1;
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
TimeSpec::~TimeSpec( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
TimeSpec::TimeSpec( const TimeSpec & rtg_arg )
	: m_sec( rtg_arg.m_sec )
	, m_nsec( rtg_arg.m_nsec )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
TimeSpec & TimeSpec::operator=( const TimeSpec & rtg_arg )
{
	if( this != &rtg_arg )
	{
		m_sec = rtg_arg.m_sec;
		m_nsec = rtg_arg.m_nsec;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'TimeSpec(uint32_t,uint32_t)'
TimeSpec::TimeSpec( uint32_t seconds, uint32_t nanoseconds )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	m_sec = seconds;
	setNanoseconds(nanoseconds);

	// }}}USR
}
// }}}RME

// {{{RME operation 'getSeconds()'
uint32_t TimeSpec::getSeconds( void ) const
{
	// {{{USR
	return m_sec;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getNanoseconds()'
uint32_t TimeSpec::getNanoseconds( void ) const
{
	// {{{USR
	return m_nsec;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setSeconds(uint32_t)'
void TimeSpec::setSeconds( uint32_t seconds )
{
	// {{{USR
	m_sec = seconds;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setNanoseconds(uint32_t)'
void TimeSpec::setNanoseconds( uint32_t nanoseconds )
{
	// {{{USR
	m_nsec = nanoseconds;

	while (m_nsec >= BILLION)
	{
		if (m_sec != UINTMAX)
		{
			m_sec++;
			m_nsec -= BILLION;
		}
		else
		{
			m_nsec = BILLION;
			break;
		}
	}

	// }}}USR
}
// }}}RME

// {{{RME operation 'operator ==(const TimeSpec)'
bool TimeSpec::operator ==( const TimeSpec otherTime )
{
	// {{{USR
	return ((m_sec == otherTime.m_sec) &&
			(m_nsec == otherTime.m_nsec));

	// }}}USR
}
// }}}RME

// {{{RME operation 'operator >(const TimeSpec)'
bool TimeSpec::operator >( const TimeSpec otherTime )
{
	// {{{USR
	return ((m_sec > otherTime.m_sec) ||
			((m_sec == otherTime.m_sec) &&
			 (m_nsec > otherTime.m_nsec)));

	// }}}USR
}
// }}}RME

// {{{RME operation 'operator <(const TimeSpec)'
bool TimeSpec::operator <( const TimeSpec otherTime )
{
	// {{{USR
	return ((m_sec < otherTime.m_sec) ||
			((m_sec == otherTime.m_sec) &&
			 (m_nsec < otherTime.m_nsec)));

	// }}}USR
}
// }}}RME

// {{{RME operation 'operator +(const TimeSpec)'
TimeSpec TimeSpec::operator +( const TimeSpec otherTime )
{
	// {{{USR
	uint32_t sec, nsec;

	// check for overrun
	if ( (UINTMAX - m_sec) < otherTime.m_sec )
	{
		sec = UINTMAX;
		nsec = BILLION;
	}
	else
	{
		// add seconds
		sec = m_sec + otherTime.m_sec;

		// add nanoseconds
		nsec = m_nsec + otherTime.m_nsec;

		// check for overrun
		if (nsec >= BILLION)
		{
			if (sec == UINTMAX)
			{
				nsec = BILLION;
			}
			else
			{
				nsec -= BILLION;
				sec++;
			}
		}
	}

	return TimeSpec(sec, nsec);

	// }}}USR
}
// }}}RME

// {{{RME operation 'operator -(const TimeSpec)'
TimeSpec TimeSpec::operator -( const TimeSpec otherTime )
{
	// {{{USR
	TimeSpec t;
	uint32_t sec, nsec;

	// subtract seconds (implementation minimized to the UINT32 data type)

	// check for underrun
	if (m_sec < otherTime.m_sec)
	{
		sec = 0;
		nsec = 0;   
	}
	else
	{
	    sec = m_sec - otherTime.m_sec;

	    if (m_nsec < otherTime.m_nsec)
	    {
		    // check for underrun        
	        if (sec == 0)
	        {
	            nsec = 0;
	        }
	        else
			{
	            nsec = BILLION - (otherTime.m_nsec - m_nsec);
				sec--;
			}
	    }
	    else
	    {
		   // subtract nanoseconds
		   nsec = m_nsec - otherTime.m_nsec;
	    }
	}


	t.m_sec = sec;
	t.m_nsec = nsec;

	return t;

	// }}}USR
}
// }}}RME

// {{{RME operation 'operator >=(const TimeSpec)'
bool TimeSpec::operator >=( const TimeSpec otherTime )
{
	// {{{USR
	return (((*this) > otherTime) || ((*this) == otherTime));
	// }}}USR
}
// }}}RME

// {{{RME operation 'operator <=(const TimeSpec)'
bool TimeSpec::operator <=( const TimeSpec otherTime )
{
	// {{{USR
	return (((*this) < otherTime) || ((*this) == otherTime));
	// }}}USR
}
// }}}RME

// {{{RME operation 'operator +=(const TimeSpec)'
TimeSpec TimeSpec::operator +=( const TimeSpec otherTime )
{
	// {{{USR
	(*this) = (*this) + otherTime;
	return (*this);


	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
