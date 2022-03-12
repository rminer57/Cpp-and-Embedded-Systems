// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Connections::OptionQuantizationUnit'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "OptionQuantizationUnit.h"
#endif

#include <conn.h>
#include <OptionQuantizationUnit.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
SERIAL_CLASS_INITIALIZE(OptionQuantizationUnit);
// }}}USR
// }}}RME

// {{{RME classAttribute 'CONNECTION_OPTION_QUANT'
const unsigned int OptionQuantizationUnit::CONNECTION_OPTION_QUANT( 4 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
OptionQuantizationUnit::~OptionQuantizationUnit( void )
{
}
// }}}RME

// {{{RME operation 'getType()'
ClassType OptionQuantizationUnit::getType( void ) const
{
	// {{{USR
	return CONNECTION_OPTION_QUANT;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool OptionQuantizationUnit::isType( ClassType type ) const
{
	// {{{USR
	return (type == CONNECTION_OPTION_QUANT)?true:ConnectionOption::isType(type);
	// }}}USR
}
// }}}RME

// {{{RME operation 'getQuantizationUnit()'
unsigned int OptionQuantizationUnit::getQuantizationUnit( void ) const
{
	// {{{USR
	return m_quantizationUnit;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setQuantizationUnit(unsigned int)'
void OptionQuantizationUnit::setQuantizationUnit( unsigned int thresh )
{
	// {{{USR
	m_quantizationUnit = thresh;
	// }}}USR
}
// }}}RME

// {{{RME operation 'OptionQuantizationUnit(unsigned int,bool)'
OptionQuantizationUnit::OptionQuantizationUnit( unsigned int quantizationUnit, bool adjust )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_quantizationUnit(quantizationUnit), m_adjust(adjust)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'deserialize(SerialObject*)'
void OptionQuantizationUnit::deserialize( SerialObject * so )
{
	// {{{USR
	*so >> m_quantizationUnit >> m_adjust;
	Option::deserialize(so);
	// }}}USR
}
// }}}RME

// {{{RME operation 'serialize(SerialObject*)'
void OptionQuantizationUnit::serialize( SerialObject * so )
{
	// {{{USR
	*so << m_quantizationUnit << m_adjust;
	Option::serialize(so);

	// }}}USR
}
// }}}RME

// {{{RME operation 'OptionQuantizationUnit(SerialObject*)'
OptionQuantizationUnit::OptionQuantizationUnit( SerialObject * so )
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

// {{{RME operation 'isAdjust()'
bool OptionQuantizationUnit::isAdjust( void )
{
	// {{{USR
	return m_adjust;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setAdjust(bool)'
void OptionQuantizationUnit::setAdjust( bool adjust )
{
	// {{{USR
	m_adjust = adjust;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
