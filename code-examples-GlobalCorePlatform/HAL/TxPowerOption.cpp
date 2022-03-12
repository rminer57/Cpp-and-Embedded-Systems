// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Configurable RF Deck::Options::TxPowerOption'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "TxPowerOption.h"
#endif

#include <hal.h>
#include <TxPowerOption.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
SERIAL_CLASS_INITIALIZE(TxPowerOption);

// }}}USR
// }}}RME

// {{{RME classAttribute 'RF_POWER_OPTION'
const unsigned int TxPowerOption::RF_POWER_OPTION( 4098 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
TxPowerOption::~TxPowerOption( void )
{
}
// }}}RME

// {{{RME operation 'getType()'
ClassType TxPowerOption::getType( void ) const
{
	// {{{USR
	return RF_POWER_OPTION;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool TxPowerOption::isType( ClassType type ) const
{
	// {{{USR
	return (type == RF_POWER_OPTION)?true:RFVirtualOption::isType(type);
	// }}}USR
}
// }}}RME

// {{{RME operation 'getPower()'
unsigned int TxPowerOption::getPower( void ) const
{
	// {{{USR
	return m_rfPower;
	// }}}USR
}
// }}}RME

// {{{RME operation 'serialize(SerialObject*)'
void TxPowerOption::serialize( SerialObject * so )
{
	// {{{USR
	*so << m_rfPower;

	RFVirtualOption::serialize(so);
	// }}}USR
}
// }}}RME

// {{{RME operation 'deserialize(SerialObject*)'
void TxPowerOption::deserialize( SerialObject * so )
{
	// {{{USR
	*so >> m_rfPower;

	RFVirtualOption::deserialize(so);
	// }}}USR
}
// }}}RME

// {{{RME operation 'TxPowerOption(unsigned int)'
TxPowerOption::TxPowerOption( unsigned int power )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_rfPower(power)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'TxPowerOption(SerialObject*)'
TxPowerOption::TxPowerOption( SerialObject * so )
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

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
