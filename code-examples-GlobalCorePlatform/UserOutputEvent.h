// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::User IO::UserOutputEvent'

#ifndef UserOutputEvent_H
#define UserOutputEvent_H

#ifdef PRAGMA
#pragma interface "UserOutputEvent.h"
#endif

#include <hal.h>
#include <EventBase.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'IndicatorCodes' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'IndicatorStates' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'IndicatorCadences' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classifier 'IndicatorCodes' classAttribute 'ALL_ANNUNCIATORS'
#define ALL_ANNUNCIATORS 0xFF
// }}}RME

// {{{RME classifier 'IndicatorCodes' classAttribute 'MAX_INDICATORS'
#define MAX_INDICATORS 255
// }}}RME

// {{{RME classifier 'IndicatorStates' classAttribute 'IND_STATE_OFF'
#define IND_STATE_OFF 0
// }}}RME

// {{{RME classifier 'IndicatorStates' classAttribute 'IND_STATE_ON'
#define IND_STATE_ON 1
// }}}RME

// {{{RME classifier 'IndicatorCadences' classAttribute 'IND_STATE_FLASHING_1'
#define IND_STATE_FLASHING_1 2
// }}}RME

// {{{RME classifier 'IndicatorCadences' classAttribute 'IND_STATE_FLASHING_2'
#define IND_STATE_FLASHING_2 3
// }}}RME

// {{{RME classifier 'IndicatorCadences' classAttribute 'IND_STATE_FLASHING_3'
#define IND_STATE_FLASHING_3 4
// }}}RME

// {{{RME classifier 'IndicatorCadences' classAttribute 'IND_STATE_FLASHING_4'
#define IND_STATE_FLASHING_4 5
// }}}RME

// {{{RME classifier 'IndicatorCadences' classAttribute 'IND_STATE_FLASHING_5'
#define IND_STATE_FLASHING_5 6
// }}}RME

// {{{RME classifier 'IndicatorCadences' classAttribute 'IND_STATE_FLASHING_6'
#define IND_STATE_FLASHING_6 7
// }}}RME

// {{{RME classifier 'IndicatorCadences' classAttribute 'IND_STATE_FLASHING_7'
#define IND_STATE_FLASHING_7 8
// }}}RME

// {{{RME classifier 'IndicatorCadences' classAttribute 'IND_STATE_NO_FLASH'
#define IND_STATE_NO_FLASH 0
// }}}RME

class UserOutputEvent : public EventBase
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
	// {{{RME classifier 'IndicatorCodes'
	class IndicatorCodes
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
		// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
		virtual ~IndicatorCodes( void );
		// }}}RME
	};
	// }}}RME
	// {{{RME classifier 'IndicatorStates'
	class IndicatorStates
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
		// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
		virtual ~IndicatorStates( void );
		// }}}RME
	};
	// }}}RME
	// {{{RME classifier 'IndicatorCadences'
	class IndicatorCadences
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
		// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
		virtual ~IndicatorCadences( void );
		// }}}RME
	};
	// }}}RME

protected:
	// {{{RME classAttribute 'm_indicatorCode'
	unsigned int m_indicatorCode;
	// }}}RME
	// {{{RME classAttribute 'm_indicatorStatus'
	unsigned int m_indicatorStatus;
	// }}}RME

public:
	// {{{RME classAttribute 'INDICATOR_EVENT'
	static const unsigned int INDICATOR_EVENT;
	// }}}RME

protected:
	// {{{RME classAttribute 'm_indicatorCadence'
	unsigned int m_indicatorCadence;
	// }}}RME

public:
	// {{{RME operation 'UserOutputEvent(unsigned int,unsigned int,unsigned int)'
	UserOutputEvent( unsigned int indicatorCode, unsigned int indicatorStatus, unsigned int indicatorCadence );
	// }}}RME
	// {{{RME operation 'getIndicatorCode()'
	unsigned int getIndicatorCode( void );
	// }}}RME
	// {{{RME operation 'getIndicatorStatus()'
	unsigned int getIndicatorStatus( void );
	// }}}RME
	// {{{RME operation 'isType(ClassType)'
	virtual bool isType( ClassType type ) const;
	// }}}RME
	// {{{RME operation 'getType()'
	ClassType getType( void ) const;
	// }}}RME
	// {{{RME operation 'isEvent(unsigned int)'
	virtual bool isEvent( unsigned int event ) const;
	// }}}RME
	// {{{RME operation '~UserOutputEvent()'
	~UserOutputEvent( void );
	// }}}RME
	// {{{RME operation 'getIndicatorCadence()'
	unsigned int getIndicatorCadence( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'IndicatorCodes' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'IndicatorStates' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'IndicatorCadences' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* UserOutputEvent_H */

// }}}RME
