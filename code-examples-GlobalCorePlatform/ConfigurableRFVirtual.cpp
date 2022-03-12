// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Configurable RF Deck::ConfigurableRFVirtual'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "ConfigurableRFVirtual.h"
#endif

#include <hal.h>
#include <ConfigurableRFVirtual.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'RFVirtualOption' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Event' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Status' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classifier 'RFVirtualOption'

// {{{RME classAttribute 'RF_VIRTUAL_OPTION'
const unsigned int ConfigurableRFVirtual::RFVirtualOption::RF_VIRTUAL_OPTION( 4 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
ConfigurableRFVirtual::RFVirtualOption::~RFVirtualOption( void )
{
}
// }}}RME

// {{{RME operation 'getType()'
ClassType ConfigurableRFVirtual::RFVirtualOption::getType( void ) const
{
	// {{{USR
	return RF_VIRTUAL_OPTION;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool ConfigurableRFVirtual::RFVirtualOption::isType( ClassType type ) const
{
	// {{{USR
	return (type == RF_VIRTUAL_OPTION)?true:Option::isType(type);
	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME classifier 'Event'

// {{{RME classAttribute 'RF_VIRTUAL_EVENT'
const unsigned int ConfigurableRFVirtual::Event::RF_VIRTUAL_EVENT( 21 );
// }}}RME

// {{{RME classAttribute 'TRANSMIT_ON'
const unsigned int ConfigurableRFVirtual::Event::TRANSMIT_ON( 1 );
// }}}RME

// {{{RME classAttribute 'TRANSMIT_STANDBY'
const unsigned int ConfigurableRFVirtual::Event::TRANSMIT_STANDBY( 2 );
// }}}RME

// {{{RME classAttribute 'RECEIVE_ON'
const unsigned int ConfigurableRFVirtual::Event::RECEIVE_ON( 3 );
// }}}RME

// {{{RME classAttribute 'RECEIVE_STANDBY'
const unsigned int ConfigurableRFVirtual::Event::RECEIVE_STANDBY( 4 );
// }}}RME

// {{{RME classAttribute 'RECEIVE_FAULT'
const unsigned int ConfigurableRFVirtual::Event::RECEIVE_FAULT( 5 );
// }}}RME

// {{{RME classAttribute 'TRANSMIT_FAULT'
const unsigned int ConfigurableRFVirtual::Event::TRANSMIT_FAULT( 6 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
ConfigurableRFVirtual::Event::~Event( void )
{
}
// }}}RME

// {{{RME operation 'getType()'
ClassType ConfigurableRFVirtual::Event::getType( void ) const
{
	// {{{USR
	return RF_VIRTUAL_EVENT;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool ConfigurableRFVirtual::Event::isType( ClassType type ) const
{
	// {{{USR
	return (type == RF_VIRTUAL_EVENT)?true:EventBase::isType(type);
	// }}}USR
}
// }}}RME

// {{{RME operation 'Event(unsigned int)'
ConfigurableRFVirtual::Event::Event( unsigned int event )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: EventBase(event)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME classifier 'Status'

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
ConfigurableRFVirtual::Status::~Status( void )
{
}
// }}}RME

// }}}RME

// {{{RME classAttribute 'RF_MIN_POWER'
const unsigned int ConfigurableRFVirtual::RF_MIN_POWER( 0 );
// }}}RME

// {{{RME classAttribute 'RF_MAX_POWER'
const unsigned int ConfigurableRFVirtual::RF_MAX_POWER( 65535 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
ConfigurableRFVirtual::~ConfigurableRFVirtual( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'RFVirtualOption' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Event' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Status' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
