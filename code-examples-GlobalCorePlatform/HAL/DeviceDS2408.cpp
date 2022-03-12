// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OneWire_Interface::DeviceDrivers::Device-specific drivers::DeviceDS2408'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "DeviceDS2408.h"
#endif

#include <serial_comp.h>
#include <DeviceDS2408.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'CMD_CHANNEL_ACCESS_WRITE'
const unsigned char DeviceDS2408::CMD_CHANNEL_ACCESS_WRITE( 0x5A );
// }}}RME

// {{{RME classAttribute 'CMD_CHANNEL_ACCESS_WRITE_SIZE'
const unsigned int DeviceDS2408::CMD_CHANNEL_ACCESS_WRITE_SIZE( 3 );
// }}}RME

// {{{RME classAttribute 'CMD_CHANNEL_ACCESS_READ'
const unsigned char DeviceDS2408::CMD_CHANNEL_ACCESS_READ( 0xF5 );
// }}}RME

// {{{RME classAttribute 'CMD_CHANNEL_ACCESS_READ_SIZE'
const unsigned int DeviceDS2408::CMD_CHANNEL_ACCESS_READ_SIZE( 1 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
DeviceDS2408::DeviceDS2408( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
DeviceDS2408::~DeviceDS2408( void )
{
}
// }}}RME

// {{{RME operation 'DeviceDS2408(OneWireConnection*)'
DeviceDS2408::DeviceDS2408( OneWireConnection * connection )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: OneWireIODevice(connection)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'send(unsigned int)'
void DeviceDS2408::send( unsigned int data )
{
	// {{{USR
	unsigned char readByte = 0;

	m_oneWireConnection->acquireBus();

	char * txBuffer = new char[CMD_CHANNEL_ACCESS_WRITE_SIZE];

	// Send the channel access write command, followed by the data
	// byte and the inverted version of the data byte. The device
	// requires the inverted version of the byte to ensure data
	// integrity.

	txBuffer[0] = (char)CMD_CHANNEL_ACCESS_WRITE;
	txBuffer[1] = (char)data;
	txBuffer[2] = (char)(~data);

	m_txBuffer = new SCharArray(CMD_CHANNEL_ACCESS_WRITE_SIZE,txBuffer,true);

	bool status = m_oneWireConnection->send(m_txBuffer);
	if( status == false ) delete m_txBuffer;

	// Read bytes from the device until the confirmation byte
	// is received (0xAA). This signals that the operation has
	// completed.

	while (readByte != 0xAA)
	{
		m_rxBuffer = (SCharArray*)m_oneWireConnection->receive();

	    if( m_rxBuffer != 0 )
	    {
		  readByte = (unsigned char)((*m_rxBuffer)[0]);
		  delete m_rxBuffer;
	    }
	    else
	    {
	      break; // if receive returned a null then this is a serious error so quit.
	    }
	}

	m_oneWireConnection->releaseBus();
	// }}}USR
}
// }}}RME

// {{{RME operation 'receive()'
unsigned int DeviceDS2408::receive( void )
{
	// {{{USR
	unsigned char retVal = 0;

	// Send the channel access read command

	m_oneWireConnection->acquireBus();

	char * txBuffer = new char[CMD_CHANNEL_ACCESS_READ_SIZE];

	txBuffer[0] = (char)CMD_CHANNEL_ACCESS_READ;

	m_txBuffer = new SCharArray(CMD_CHANNEL_ACCESS_READ_SIZE,txBuffer,true);

	bool status = m_oneWireConnection->send(m_txBuffer);
	if( status == false ) delete m_txBuffer;

	// Return the read value

	m_rxBuffer = (SCharArray*)m_oneWireConnection->receive();

	if( m_rxBuffer != 0 )
	{
	  retVal = (unsigned char)((*m_rxBuffer)[0]);
	  delete m_rxBuffer;
	}
	// else retVal will still be equal to zero and will be returned as such.

	m_oneWireConnection->releaseBus();

	return retVal;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
