// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Configurable RF Deck::Options::TransmitDeviation'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "TransmitDeviation.h"
#endif

#include <hal.h>
#include <TransmitDeviation.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
SERIAL_CLASS_INITIALIZE(TransmitDeviation);

// }}}USR
// }}}RME

// {{{RME classAttribute 'TRANSMIT_DEVIATION_OPTION'
const unsigned int TransmitDeviation::TRANSMIT_DEVIATION_OPTION( 4102 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
TransmitDeviation::~TransmitDeviation( void )
{
}
// }}}RME

// {{{RME operation 'getType()'
ClassType TransmitDeviation::getType( void ) const
{
	// {{{USR
	return TRANSMIT_DEVIATION_OPTION;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool TransmitDeviation::isType( ClassType type ) const
{
	// {{{USR
	return (type == TRANSMIT_DEVIATION_OPTION)?true:RFVirtualOption::isType(type);
	// }}}USR
}
// }}}RME

// {{{RME operation 'getDeviation()'
unsigned int TransmitDeviation::getDeviation( void ) const
{
	// {{{USR
	return m_txDeviation;
	// }}}USR
}
// }}}RME

// {{{RME operation 'serialize(SerialObject*)'
void TransmitDeviation::serialize( SerialObject * so )
{
	// {{{USR
	*so << m_txDeviation;

	RFVirtualOption::serialize(so);

	// }}}USR
}
// }}}RME

// {{{RME operation 'deserialize(SerialObject*)'
void TransmitDeviation::deserialize( SerialObject * so )
{
	// {{{USR
	*so >> m_txDeviation;

	RFVirtualOption::deserialize(so);
	// }}}USR
}
// }}}RME

// {{{RME operation 'TransmitDeviation(unsigned int)'
TransmitDeviation::TransmitDeviation( unsigned int txDeviation )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_txDeviation(txDeviation)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'TransmitDeviation(SerialObject*)'
TransmitDeviation::TransmitDeviation( SerialObject * so )
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
