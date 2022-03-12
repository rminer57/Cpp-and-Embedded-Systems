// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Configurable RF Deck::Options::RFDeckMode'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "RFDeckMode.h"
#endif

#include <hal.h>
#include <RFDeckMode.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
SERIAL_CLASS_INITIALIZE(RFDeckMode);

// }}}USR
// }}}RME

// {{{RME classAttribute 'RF_DECK_MODE'
const unsigned int RFDeckMode::RF_DECK_MODE( 4104 );
// }}}RME

// {{{RME classAttribute 'M_CONTINUOUS'
const unsigned int RFDeckMode::M_CONTINUOUS = 0;
// }}}RME

// {{{RME classAttribute 'M_TIME_DIVISION'
const unsigned int RFDeckMode::M_TIME_DIVISION = 1;
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
RFDeckMode::~RFDeckMode( void )
{
}
// }}}RME

// {{{RME operation 'getType()'
ClassType RFDeckMode::getType( void ) const
{
	// {{{USR
	return RF_DECK_MODE;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool RFDeckMode::isType( ClassType type ) const
{
	// {{{USR
	return (type == RF_DECK_MODE)?true:RFVirtualOption::isType(type);
	// }}}USR
}
// }}}RME

// {{{RME operation 'getMode()'
unsigned int RFDeckMode::getMode( void ) const
{
	// {{{USR
	return m_mode;
	// }}}USR
}
// }}}RME

// {{{RME operation 'serialize(SerialObject*)'
void RFDeckMode::serialize( SerialObject * so )
{
	// {{{USR
	*so << m_mode;

	RFVirtualOption::serialize(so);
	// }}}USR
}
// }}}RME

// {{{RME operation 'deserialize(SerialObject*)'
void RFDeckMode::deserialize( SerialObject * so )
{
	// {{{USR
	*so >> m_mode;

	RFVirtualOption::deserialize(so);
	// }}}USR
}
// }}}RME

// {{{RME operation 'RFDeckMode(SerialObject*)'
RFDeckMode::RFDeckMode( SerialObject * so )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	deserialize(so);
	// }}}USR
}
// }}}RME

// {{{RME operation 'RFDeckMode(unsigned int)'
RFDeckMode::RFDeckMode( unsigned int mode )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_mode(mode)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
