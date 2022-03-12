// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OneWire_Interface::DeviceDrivers::RTCVirtual'

#ifndef RTCVirtual_H
#define RTCVirtual_H

#ifdef PRAGMA
#pragma interface "RTCVirtual.h"
#endif

#include <serial_comp.h>
#include <EventBase.h>
#include <NotifierBase.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Event' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'RTCTimeSpec' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class RTCVirtual : public NotifierBase
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
	// {{{RME classifier 'Event'
	class Event : public EventBase
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
		// {{{RME classAttribute 'ONEWIRE_RTC_EVENT'
		static const unsigned int ONEWIRE_RTC_EVENT;
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
		virtual ~Event( void );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
		Event( const Event & rtg_arg );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
		Event & operator=( const Event & rtg_arg );
		// }}}RME
		// {{{RME operation 'getType()'
		virtual ClassType getType( void ) const;
		// }}}RME
		// {{{RME operation 'isType(ClassType)'
		virtual bool isType( ClassType type ) const;
		// }}}RME
		// {{{RME operation 'Event()'
		Event( void );
		// }}}RME
	};
	// }}}RME
	// {{{RME classifier 'RTCTimeSpec'
	class RTCTimeSpec
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
		// {{{RME classAttribute 'm_hours'
		unsigned int m_hours;
		// }}}RME
		// {{{RME classAttribute 'm_minutes'
		unsigned int m_minutes;
		// }}}RME
		// {{{RME classAttribute 'm_seconds'
		unsigned int m_seconds;
		// }}}RME
		// {{{RME classAttribute 'm_day'
		unsigned int m_day;
		// }}}RME
		// {{{RME classAttribute 'm_month'
		unsigned int m_month;
		// }}}RME
		// {{{RME classAttribute 'm_year'
		unsigned int m_year;
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
		virtual ~RTCTimeSpec( void );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
		RTCTimeSpec( const RTCTimeSpec & rtg_arg );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
		RTCTimeSpec & operator=( const RTCTimeSpec & rtg_arg );
		// }}}RME
		// {{{RME operation 'RTCTimeSpec(unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int)'
		RTCTimeSpec( unsigned int hours = 0, unsigned int minutes = 0, unsigned int seconds = 0, unsigned int day = 0, unsigned int month = 0, unsigned int year = 0 );
		// }}}RME
	};
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	RTCVirtual( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~RTCVirtual( void );
	// }}}RME
	// {{{RME operation 'setAlarm(const RTCVirtual::RTCTimeSpec*)'
	virtual void setAlarm( const RTCTimeSpec * time ) = 0;
	// }}}RME
	// {{{RME operation 'setTime(RTCVirtual::RTCTimeSpec*)'
	virtual void setTime( RTCTimeSpec * time ) = 0;
	// }}}RME
	// {{{RME operation 'readTime()'
	virtual RTCTimeSpec * readTime( void ) = 0;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Event' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'RTCTimeSpec' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* RTCVirtual_H */

// }}}RME
