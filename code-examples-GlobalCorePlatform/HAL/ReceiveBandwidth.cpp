// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Configurable RF Deck::Options::ReceiveBandwidth'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "ReceiveBandwidth.h"
#endif

#include <hal.h>
#include <ReceiveBandwidth.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
SERIAL_CLASS_INITIALIZE(ReceiveBandwidth);
// }}}USR
// }}}RME

// {{{RME classAttribute 'RECEIVE_BANDWIDTH_OPTION'
const unsigned int ReceiveBandwidth::RECEIVE_BANDWIDTH_OPTION( 4101 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
ReceiveBandwidth::~ReceiveBandwidth( void )
{
}
// }}}RME

// {{{RME operation 'getType()'
ClassType ReceiveBandwidth::getType( void ) const
{
	// {{{USR
	return RECEIVE_BANDWIDTH_OPTION;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool ReceiveBandwidth::isType( ClassType type ) const
{
	// {{{USR
	return (type == RECEIVE_BANDWIDTH_OPTION)?true:RFVirtualOption::isType(type);
	// }}}USR
}
// }}}RME

// {{{RME operation 'getBandwidth()'
unsigned int ReceiveBandwidth::getBandwidth( void ) const
{
	// {{{USR
	return m_rxBandwidth;
	// }}}USR
}
// }}}RME

// {{{RME operation 'serialize(SerialObject*)'
void ReceiveBandwidth::serialize( SerialObject * so )
{
	// {{{USR
	*so << m_rxBandwidth;

	RFVirtualOption::serialize(so);
	// }}}USR
}
// }}}RME

// {{{RME operation 'deserialize(SerialObject*)'
void ReceiveBandwidth::deserialize( SerialObject * so )
{
	// {{{USR
	*so >> m_rxBandwidth;

	RFVirtualOption::deserialize(so);
	// }}}USR
}
// }}}RME

// {{{RME operation 'ReceiveBandwidth(unsigned int)'
ReceiveBandwidth::ReceiveBandwidth( unsigned int rxBandwidth )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_rxBandwidth(rxBandwidth)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'ReceiveBandwidth(SerialObject*)'
ReceiveBandwidth::ReceiveBandwidth( SerialObject * so )
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
