// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OneWire_Interface::DeviceDrivers::RTCVirtual'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "RTCVirtual.h"
#endif

#include <serial_comp.h>
#include <RTCVirtual.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Event' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'RTCTimeSpec' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classifier 'Event'

// {{{RME classAttribute 'ONEWIRE_RTC_EVENT'
const unsigned int RTCVirtual::Event::ONEWIRE_RTC_EVENT( 4624 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
RTCVirtual::Event::~Event( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
RTCVirtual::Event::Event( const Event & rtg_arg )
	: EventBase( rtg_arg )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
RTCVirtual::Event & RTCVirtual::Event::operator=( const Event & rtg_arg )
{
	if( this != &rtg_arg )
		EventBase::operator=( rtg_arg );
	return *this;
}
// }}}RME

// {{{RME operation 'getType()'
ClassType RTCVirtual::Event::getType( void ) const
{
	// {{{USR
	return ONEWIRE_RTC_EVENT;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool RTCVirtual::Event::isType( ClassType type ) const
{
	// {{{USR
	return (type == ONEWIRE_RTC_EVENT)?true:EventBase::isType(type);
	// }}}USR
}
// }}}RME

// {{{RME operation 'Event()'
RTCVirtual::Event::Event( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: EventBase(ONEWIRE_RTC_EVENT)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME classifier 'RTCTimeSpec'

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
RTCVirtual::RTCTimeSpec::~RTCTimeSpec( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
RTCVirtual::RTCTimeSpec::RTCTimeSpec( const RTCTimeSpec & rtg_arg )
	: m_hours( rtg_arg.m_hours )
	, m_minutes( rtg_arg.m_minutes )
	, m_seconds( rtg_arg.m_seconds )
	, m_day( rtg_arg.m_day )
	, m_month( rtg_arg.m_month )
	, m_year( rtg_arg.m_year )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
RTCVirtual::RTCTimeSpec & RTCVirtual::RTCTimeSpec::operator=( const RTCTimeSpec & rtg_arg )
{
	if( this != &rtg_arg )
	{
		m_hours = rtg_arg.m_hours;
		m_minutes = rtg_arg.m_minutes;
		m_seconds = rtg_arg.m_seconds;
		m_day = rtg_arg.m_day;
		m_month = rtg_arg.m_month;
		m_year = rtg_arg.m_year;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'RTCTimeSpec(unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int)'
RTCVirtual::RTCTimeSpec::RTCTimeSpec( unsigned int hours, unsigned int minutes, unsigned int seconds, unsigned int day, unsigned int month, unsigned int year )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_hours(hours),m_minutes(minutes),m_seconds(seconds),m_day(day),m_month(month),m_year(year)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
RTCVirtual::RTCVirtual( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
RTCVirtual::~RTCVirtual( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Event' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'RTCTimeSpec' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
