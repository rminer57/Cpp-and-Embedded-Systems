// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Serial IO::UART::UartConfig'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "UartConfig.h"
#endif

#include <hal.h>
#include <UartConfig.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'FlowControl' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Parity' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'UART_CONFIG_OPTION'
const unsigned int UartConfig::UART_CONFIG_OPTION( 5 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
UartConfig::~UartConfig( void )
{
}
// }}}RME

// {{{RME operation 'UartConfig(unsigned int,unsigned int,Parity,unsigned int,FlowControl,unsigned char,unsigned char,unsigned int)'
UartConfig::UartConfig( unsigned int baudRate, unsigned int dataBits, Parity parity, unsigned int stopBits, FlowControl flowControl, unsigned char xon, unsigned char xoff, unsigned int threshold )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_baudRate(baudRate), m_dataBits(dataBits), m_flowControl(flowControl),
	m_parity(parity), m_stopBits(stopBits), m_threshold(threshold), m_xoff(xoff), m_xon(xon)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool UartConfig::isType( ClassType type ) const
{
	// {{{USR
	return (type == UART_CONFIG_OPTION)?true:ConnectionOption::isType(type);
	// }}}USR
}
// }}}RME

// {{{RME operation 'getType()'
ClassType UartConfig::getType( void ) const
{
	// {{{USR
	return UART_CONFIG_OPTION;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'FlowControl' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Parity' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
