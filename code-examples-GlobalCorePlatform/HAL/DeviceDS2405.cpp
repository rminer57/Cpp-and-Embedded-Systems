// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OneWire_Interface::DeviceDrivers::Device-specific drivers::DeviceDS2405'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "DeviceDS2405.h"
#endif

#include <serial_comp.h>
#include <DeviceDS2405.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
DeviceDS2405::DeviceDS2405( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
DeviceDS2405::~DeviceDS2405( void )
{
}
// }}}RME

// {{{RME operation 'send(unsigned int)'
void DeviceDS2405::send( unsigned int data )
{
	// {{{USR
	if ((data & 0x01) != m_pioState)
	{
		// Selecting the device will toggle its PIO line state
		m_oneWireConnection->acquireBus();
		m_oneWireConnection->releaseBus();
		m_pioState = !m_pioState;
	}
	// }}}USR
}
// }}}RME

// {{{RME operation 'DeviceDS2405(OneWireConnection*,bool)'
DeviceDS2405::DeviceDS2405( OneWireConnection * connection, bool activeHigh )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: OneWireIODevice(connection), m_activeHigh(activeHigh)
	// }}}USR
	// }}}RME
{
	// {{{USR
	unsigned char pioState = 0;

	// Determine initial state of PIO pin.
	// When the device is selected using the Match ROM command,
	// it will toggle the state of its PIO pin. Following the match,
	// every time the user reads a bit from the device, the user will
	// receive the PIO pin state.  Because of this, the initial state will be
	// determined after this first toggle, and the state will be
	// maintained in a member attribute.

	m_oneWireConnection->acquireBus();

	m_rxBuffer = (SCharArray*)m_oneWireConnection->receive();

	if( m_rxBuffer != 0 )
	{
	  pioState = ((unsigned char)((*m_rxBuffer)[0])) & 0x01;
	  delete m_rxBuffer;
	}

	m_pioState = m_activeHigh?(pioState):(!pioState);

	m_oneWireConnection->releaseBus();
	// }}}USR
}
// }}}RME

// {{{RME operation 'receive()'
unsigned int DeviceDS2405::receive( void )
{
	// {{{USR
	return m_pioState;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
