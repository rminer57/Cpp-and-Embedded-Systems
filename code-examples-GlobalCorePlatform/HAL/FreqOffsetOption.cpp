// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Configurable RF Deck::Options::FreqOffsetOption'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "FreqOffsetOption.h"
#endif

#include <hal.h>
#include <FreqOffsetOption.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
SERIAL_CLASS_INITIALIZE(FreqOffsetOption);
// }}}USR
// }}}RME

// {{{RME classAttribute 'FREQ_OFFSET_OPTION'
const unsigned int FreqOffsetOption::FREQ_OFFSET_OPTION( 4096 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
FreqOffsetOption::~FreqOffsetOption( void )
{
}
// }}}RME

// {{{RME operation 'getType()'
ClassType FreqOffsetOption::getType( void ) const
{
	// {{{USR
	return FREQ_OFFSET_OPTION;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool FreqOffsetOption::isType( ClassType type ) const
{
	// {{{USR
	return (type == FREQ_OFFSET_OPTION)?true:RFVirtualOption::isType(type);
	// }}}USR
}
// }}}RME

// {{{RME operation 'getOffset()'
int FreqOffsetOption::getOffset( void ) const
{
	// {{{USR
	return m_offset;
	// }}}USR
}
// }}}RME

// {{{RME operation 'serialize(SerialObject*)'
void FreqOffsetOption::serialize( SerialObject * so )
{
	// {{{USR
	*so << m_offset;

	RFVirtualOption::serialize(so);
	// }}}USR
}
// }}}RME

// {{{RME operation 'deserialize(SerialObject*)'
void FreqOffsetOption::deserialize( SerialObject * so )
{
	// {{{USR
	*so >> m_offset;

	RFVirtualOption::deserialize(so);
	// }}}USR
}
// }}}RME

// {{{RME operation 'FreqOffsetOption(SerialObject*)'
FreqOffsetOption::FreqOffsetOption( SerialObject * so )
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

// {{{RME operation 'FreqOffsetOption(int)'
FreqOffsetOption::FreqOffsetOption( int offset )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_offset(offset)
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
