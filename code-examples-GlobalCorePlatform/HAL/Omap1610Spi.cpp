// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OMAP::Spi::OMAP1610Spi::Omap1610Spi'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Omap1610Spi.h"
#endif

#include <serial_comp.h>
#include <Omap1610Spi.h>
#include <ChipSelect.h>
#include <DataBuffer.h>
#include <OMAPSpiConfig.h>
#include <Omap1610SpiFactory.h>
#include <SIntArray.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'SIntDesc' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classifier 'SIntDesc'

// {{{RME classAttribute 'SINT_ARRAY_DESCRIPTOR_SPI'
const unsigned int Omap1610Spi::SIntDesc::SINT_ARRAY_DESCRIPTOR_SPI( 2 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
Omap1610Spi::SIntDesc::~SIntDesc( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
Omap1610Spi::SIntDesc::SIntDesc( const SIntDesc & rtg_arg )
	: ArrayDescriptor( rtg_arg )
	, m_skipFirst( rtg_arg.m_skipFirst )
	, m_skipLast( rtg_arg.m_skipLast )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
Omap1610Spi::SIntDesc & Omap1610Spi::SIntDesc::operator=( const SIntDesc & rtg_arg )
{
	if( this != &rtg_arg )
	{
		ArrayDescriptor::operator=( rtg_arg );
		m_skipFirst = rtg_arg.m_skipFirst;
		m_skipLast = rtg_arg.m_skipLast;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool Omap1610Spi::SIntDesc::isType( ClassType type ) const
{
	// {{{USR
	return (type == SINT_ARRAY_DESCRIPTOR_SPI?true:ArrayDescriptor::isType(type));
	// }}}USR
}
// }}}RME

// {{{RME operation 'getType()'
ClassType Omap1610Spi::SIntDesc::getType( void ) const
{
	// {{{USR
	return SINT_ARRAY_DESCRIPTOR_SPI;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isSkipLast()'
bool Omap1610Spi::SIntDesc::isSkipLast( void ) const
{
	// {{{USR
	return m_skipLast;
	// }}}USR
}
// }}}RME

// {{{RME operation 'SIntDesc(bool,bool)'
Omap1610Spi::SIntDesc::SIntDesc( bool skipFirst, bool skipLast )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_skipFirst(skipFirst), m_skipLast(skipLast)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'isSkipFirst()'
bool Omap1610Spi::SIntDesc::isSkipFirst( void ) const
{
	// {{{USR
	return m_skipFirst;
	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
Omap1610Spi::Omap1610Spi( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
Omap1610Spi::Omap1610Spi( const Omap1610Spi & rtg_arg )
	: IOVirtualSerial( rtg_arg )
	, m_rxSpiBuffer( rtg_arg.m_rxSpiBuffer )
	, m_cfg( rtg_arg.m_cfg )
	, m_parent( rtg_arg.m_parent )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
Omap1610Spi & Omap1610Spi::operator=( const Omap1610Spi & rtg_arg )
{
	if( this != &rtg_arg )
	{
		IOVirtualSerial::operator=( rtg_arg );
		m_rxSpiBuffer = rtg_arg.m_rxSpiBuffer;
		m_cfg = rtg_arg.m_cfg;
		m_parent = rtg_arg.m_parent;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'Omap1610Spi(OMAPSpiConfig *,Omap1610SpiFactory*)'
Omap1610Spi::Omap1610Spi( OMAPSpiConfig * config, Omap1610SpiFactory * parent )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_rxSpiBuffer(0),m_parent(parent),m_cfg(config)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'receive()'
Array * Omap1610Spi::receive( void )
{
	// {{{USR
	// The received buffer from the send operation is
	// passed to the client of the serial device.
	SIntArray *ret = m_rxSpiBuffer;
	m_rxSpiBuffer = 0;									//Remove from this class
	return ret;
	// }}}USR
}
// }}}RME

// {{{RME operation 'send(Array*)'
bool Omap1610Spi::send( Array * buf )
{
	// {{{USR
	bool ret = false;
	bool skipLast = false;
	bool skipFirst = false;

	if (buf->isType(SIntArray::SIGNED_INT_ARRAY))
	{
		SIntArray *buffer = (SIntArray*)buf;				//Type safe up cast
		const ArrayDescriptor *desc = buffer->getDescriptor();

		if (desc != 0 && desc->isType(SIntDesc::SINT_ARRAY_DESCRIPTOR_SPI))
		{
			skipFirst = ((SIntDesc*)desc)->isSkipFirst();
			skipLast =  ((SIntDesc*)desc)->isSkipLast();
		}

		m_parent->configure(m_cfg);
				
		//select the target device
		m_cfg->m_chipSelect->assert();
		
		//send the data and get back the reveived data
		m_parent->sendAndReceive(buffer,skipFirst,skipLast);
		
		//de-select the target device
		m_cfg->m_chipSelect->deAssert();
		
		//delete previous receive buffer
		delete m_rxSpiBuffer;
		
		//Assign buffer to return to user on next receive (consuming given buffer)
		m_rxSpiBuffer = buffer; 
		
		ret = true;
	}
	return ret;
	// }}}USR
}
// }}}RME

// {{{RME operation 'deactivate()'
bool Omap1610Spi::deactivate( void )
{
	// {{{USR
	return true;
	// }}}USR
}
// }}}RME

// {{{RME operation 'activate()'
bool Omap1610Spi::activate( void )
{
	// {{{USR
	return true;
	// }}}USR
}
// }}}RME

// {{{RME operation '~Omap1610Spi()'
Omap1610Spi::~Omap1610Spi( void )
{
	// {{{USR
	delete m_rxSpiBuffer;
	delete m_cfg;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getOption()'
Configurable::Option * Omap1610Spi::getOption( void ) const
{
	// {{{USR
	return 0;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getStatus()'
Connection::Status * Omap1610Spi::getStatus( void )
{
	// {{{USR
	return 0;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'SIntDesc' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
