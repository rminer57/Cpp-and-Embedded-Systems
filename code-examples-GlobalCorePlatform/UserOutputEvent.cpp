// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::User IO::UserOutputEvent'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "UserOutputEvent.h"
#endif

#include <hal.h>
#include <UserOutputEvent.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'IndicatorCodes' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'IndicatorStates' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'IndicatorCadences' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classifier 'IndicatorCodes'

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
UserOutputEvent::IndicatorCodes::~IndicatorCodes( void )
{
}
// }}}RME
// }}}RME

// {{{RME classifier 'IndicatorStates'

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
UserOutputEvent::IndicatorStates::~IndicatorStates( void )
{
}
// }}}RME
// }}}RME

// {{{RME classifier 'IndicatorCadences'

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
UserOutputEvent::IndicatorCadences::~IndicatorCadences( void )
{
}
// }}}RME
// }}}RME

// {{{RME classAttribute 'INDICATOR_EVENT'
const unsigned int UserOutputEvent::INDICATOR_EVENT = 33;
// }}}RME

// {{{RME operation 'UserOutputEvent(unsigned int,unsigned int,unsigned int)'
UserOutputEvent::UserOutputEvent( unsigned int indicatorCode, unsigned int indicatorStatus, unsigned int indicatorCadence )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_indicatorCode(indicatorCode), m_indicatorStatus(indicatorStatus), EventBase(INDICATOR_EVENT), m_indicatorCadence(indicatorCadence)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'getIndicatorCode()'
unsigned int UserOutputEvent::getIndicatorCode( void )
{
	// {{{USR
	return m_indicatorCode;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getIndicatorStatus()'
unsigned int UserOutputEvent::getIndicatorStatus( void )
{
	// {{{USR
	return m_indicatorStatus;

	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool UserOutputEvent::isType( ClassType type ) const
{
	// {{{USR
	return((type == INDICATOR_EVENT)?true:(EventBase::isType(type)));


	// }}}USR
}
// }}}RME

// {{{RME operation 'getType()'
ClassType UserOutputEvent::getType( void ) const
{
	// {{{USR
	return INDICATOR_EVENT;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isEvent(unsigned int)'
bool UserOutputEvent::isEvent( unsigned int event ) const
{
	// {{{USR
	return ((event == INDICATOR_EVENT)?true:(EventBase::isEvent(event)));


	// }}}USR
}
// }}}RME

// {{{RME operation '~UserOutputEvent()'
UserOutputEvent::~UserOutputEvent( void )
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'getIndicatorCadence()'
unsigned int UserOutputEvent::getIndicatorCadence( void )
{
	// {{{USR
	return m_indicatorCadence;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'IndicatorCodes' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'IndicatorStates' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'IndicatorCadences' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
