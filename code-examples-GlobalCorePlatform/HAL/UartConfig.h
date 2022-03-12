// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Serial IO::UART::UartConfig'

#ifndef UartConfig_H
#define UartConfig_H

#ifdef PRAGMA
#pragma interface "UartConfig.h"
#endif

#include <hal.h>
#include <Connection.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'FlowControl' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Parity' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class UartConfig : public Connection::ConnectionOption
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

protected:
	// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

private:
	// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

public:
	// {{{RME classifier 'FlowControl'
	enum FlowControl
	{
		NO_FLOW_CONTROL = 0
	  , SOFTWARE_FLOW_CONTROL = 1
	  , HARDWARE_FLOW_CONTROL = 2
	};
	// }}}RME
	// {{{RME classifier 'Parity'
	enum Parity
	{
		NONE = 0
	  , ODD = 1
	  , EVEN = 2
	};
	// }}}RME
	// {{{RME classAttribute 'm_baudRate'
	unsigned int m_baudRate;
	// }}}RME
	// {{{RME classAttribute 'm_dataBits'
	unsigned int m_dataBits;
	// }}}RME
	// {{{RME classAttribute 'm_parity'
	Parity m_parity;
	// }}}RME
	// {{{RME classAttribute 'm_stopBits'
	unsigned int m_stopBits;
	// }}}RME
	// {{{RME classAttribute 'm_flowControl'
	FlowControl m_flowControl;
	// }}}RME
	// {{{RME classAttribute 'm_xon'
	unsigned char m_xon;
	// }}}RME
	// {{{RME classAttribute 'm_xoff'
	unsigned char m_xoff;
	// }}}RME
	// {{{RME classAttribute 'm_threshold'
	unsigned int m_threshold;
	// }}}RME
	// {{{RME classAttribute 'UART_CONFIG_OPTION'
	static const unsigned int UART_CONFIG_OPTION;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~UartConfig( void );
	// }}}RME
	// {{{RME operation 'UartConfig(unsigned int,unsigned int,Parity,unsigned int,FlowControl,unsigned char,unsigned char,unsigned int)'
	UartConfig( unsigned int baudRate = 9600, unsigned int dataBits = 8, Parity parity = NONE, unsigned int stopBits = 1, FlowControl flowControl = NO_FLOW_CONTROL, unsigned char xon = 0x11, unsigned char xoff = 0x13, unsigned int threshold = 16 );
	// }}}RME
	// {{{RME operation 'isType(ClassType)'
	virtual bool isType( ClassType type ) const;
	// }}}RME
	// {{{RME operation 'getType()'
	virtual ClassType getType( void ) const;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'FlowControl' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Parity' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* UartConfig_H */

// }}}RME
