// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Configurable RF Deck::Options::AGCOption'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "AGCOption.h"
#endif

#include <hal.h>
#include <AGCOption.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
SERIAL_CLASS_INITIALIZE(AGCOption);

// }}}USR
// }}}RME

// {{{RME classAttribute 'AGC_OPTION'
const unsigned int AGCOption::AGC_OPTION( 4097 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
AGCOption::~AGCOption( void )
{
}
// }}}RME

// {{{RME operation 'getType()'
ClassType AGCOption::getType( void ) const
{
	// {{{USR
	return AGC_OPTION;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool AGCOption::isType( ClassType type ) const
{
	// {{{USR
	return (type == AGC_OPTION)?true:RFVirtualOption::isType(type);
	// }}}USR
}
// }}}RME

// {{{RME operation 'getGain()'
unsigned int AGCOption::getGain( void ) const
{
	// {{{USR
	return m_gain;
	// }}}USR
}
// }}}RME

// {{{RME operation 'serialize(SerialObject*)'
void AGCOption::serialize( SerialObject * so )
{
	// {{{USR
	*so << m_gain;

	RFVirtualOption::serialize(so);
	// }}}USR
}
// }}}RME

// {{{RME operation 'deserialize(SerialObject*)'
void AGCOption::deserialize( SerialObject * so )
{
	// {{{USR
	*so >> m_gain;

	RFVirtualOption::deserialize(so);
	// }}}USR
}
// }}}RME

// {{{RME operation 'AGCOption(SerialObject*)'
AGCOption::AGCOption( SerialObject * so )
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

// {{{RME operation 'AGCOption(unsigned int)'
AGCOption::AGCOption( unsigned int gain )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_gain(gain)
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
