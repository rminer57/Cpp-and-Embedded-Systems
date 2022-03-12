// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Configurable RF Deck::Options::TransmitFrequency'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "TransmitFrequency.h"
#endif

#include <hal.h>
#include <TransmitFrequency.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
SERIAL_CLASS_INITIALIZE(TransmitFrequency);
// }}}USR
// }}}RME

// {{{RME classAttribute 'TRANSMIT_FREQUENCY_OPTION'
const unsigned int TransmitFrequency::TRANSMIT_FREQUENCY_OPTION( 4100 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
TransmitFrequency::~TransmitFrequency( void )
{
}
// }}}RME

// {{{RME operation 'getType()'
ClassType TransmitFrequency::getType( void ) const
{
	// {{{USR
	return TRANSMIT_FREQUENCY_OPTION;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool TransmitFrequency::isType( ClassType type ) const
{
	// {{{USR
	return (type == TRANSMIT_FREQUENCY_OPTION)?true:RFVirtualOption::isType(type);
	// }}}USR
}
// }}}RME

// {{{RME operation 'getFrequency()'
unsigned long TransmitFrequency::getFrequency( void ) const
{
	// {{{USR
	return m_txFrequency;
	// }}}USR
}
// }}}RME

// {{{RME operation 'serialize(SerialObject*)'
void TransmitFrequency::serialize( SerialObject * so )
{
	// {{{USR
	*so << m_txFrequency;

	RFVirtualOption::serialize(so);
	// }}}USR
}
// }}}RME

// {{{RME operation 'deserialize(SerialObject*)'
void TransmitFrequency::deserialize( SerialObject * so )
{
	// {{{USR
	*so >> m_txFrequency;

	RFVirtualOption::deserialize(so);
	// }}}USR
}
// }}}RME

// {{{RME operation 'TransmitFrequency(unsigned long)'
TransmitFrequency::TransmitFrequency( unsigned long txFrequency )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_txFrequency(txFrequency)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'TransmitFrequency(SerialObject*)'
TransmitFrequency::TransmitFrequency( SerialObject * so )
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
