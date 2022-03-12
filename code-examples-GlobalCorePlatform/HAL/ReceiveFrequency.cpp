// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Configurable RF Deck::Options::ReceiveFrequency'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "ReceiveFrequency.h"
#endif

#include <hal.h>
#include <ReceiveFrequency.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
SERIAL_CLASS_INITIALIZE(ReceiveFrequency);

// }}}USR
// }}}RME

// {{{RME classAttribute 'RECEIVE_FREQUENCY_OPTION'
const unsigned int ReceiveFrequency::RECEIVE_FREQUENCY_OPTION( 4099 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
ReceiveFrequency::~ReceiveFrequency( void )
{
}
// }}}RME

// {{{RME operation 'getType()'
ClassType ReceiveFrequency::getType( void ) const
{
	// {{{USR
	return RECEIVE_FREQUENCY_OPTION;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool ReceiveFrequency::isType( ClassType type ) const
{
	// {{{USR
	return (type == RECEIVE_FREQUENCY_OPTION)?true:RFVirtualOption::isType(type);
	// }}}USR
}
// }}}RME

// {{{RME operation 'getFrequency()'
unsigned long ReceiveFrequency::getFrequency( void ) const
{
	// {{{USR
	return m_rxFrequency;
	// }}}USR
}
// }}}RME

// {{{RME operation 'serialize(SerialObject*)'
void ReceiveFrequency::serialize( SerialObject * so )
{
	// {{{USR
	*so << m_rxFrequency;

	RFVirtualOption::serialize(so);
	// }}}USR
}
// }}}RME

// {{{RME operation 'deserialize(SerialObject*)'
void ReceiveFrequency::deserialize( SerialObject * so )
{
	// {{{USR
	*so >> m_rxFrequency;

	RFVirtualOption::deserialize(so);
	// }}}USR
}
// }}}RME

// {{{RME operation 'ReceiveFrequency(unsigned long)'
ReceiveFrequency::ReceiveFrequency( unsigned long rxFrequency )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_rxFrequency(rxFrequency)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'ReceiveFrequency(SerialObject*)'
ReceiveFrequency::ReceiveFrequency( SerialObject * so )
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
