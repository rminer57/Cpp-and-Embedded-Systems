// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OMAP::I2c::OMAP1610I2c::Omap1610I2c'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Omap1610I2c.h"
#endif

#include <serial_comp.h>
#include <Omap1610I2c.h>
#include <DataBuffer.h>
#include <Omap1610I2cConfig.h>
#include <Omap1610I2cFactory.h>
#include <OptionQuantizationUnit.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
Omap1610I2c::Omap1610I2c( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
Omap1610I2c::~Omap1610I2c( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
Omap1610I2c::Omap1610I2c( const Omap1610I2c & rtg_arg )
	: IOVirtualSerial( rtg_arg )
	, m_currentRxThreshold( rtg_arg.m_currentRxThreshold )
	, m_cfg( rtg_arg.m_cfg )
	, m_parent( rtg_arg.m_parent )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
Omap1610I2c & Omap1610I2c::operator=( const Omap1610I2c & rtg_arg )
{
	if( this != &rtg_arg )
	{
		IOVirtualSerial::operator=( rtg_arg );
		m_currentRxThreshold = rtg_arg.m_currentRxThreshold;
		m_cfg = rtg_arg.m_cfg;
		m_parent = rtg_arg.m_parent;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'Omap1610I2c(Omap1610I2cConfig *,Omap1610I2cFactory *)'
Omap1610I2c::Omap1610I2c( Omap1610I2cConfig * config, Omap1610I2cFactory * parent )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	:m_cfg(config),m_parent(parent)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'receive()'
Array * Omap1610I2c::receive( void )
{
	// {{{USR
	DataBuffer *ret = 0;

	unsigned char *buffer = m_parent->receive(m_cfg,m_currentRxThreshold);

	// If the first receive failed, try one more time before returning zero.
	if (buffer == 0)
	{
	   buffer = m_parent->receive(m_cfg,m_currentRxThreshold);
	}

	//If no error occurs, create data buffer for client
	if (buffer != 0) ret = new DataBuffer(buffer,m_currentRxThreshold,true);

	return ret;
	// }}}USR
}
// }}}RME

// {{{RME operation 'send(Array*)'
bool Omap1610I2c::send( Array * buf )
{
	// {{{USR
	bool ret = false;

	if (buf->isType(DataBuffer::DATA_BUFFER_ARRAY))
	{
	   DataBuffer *buffer = (DataBuffer *)buf;				//Type safe up cast
	   unsigned int size = buffer->getSize();
	   unsigned char* dataPtr = (unsigned char *)buffer->copyToArray();

	   //send the data and get back the reveived data
	   ret = m_parent->send(m_cfg,dataPtr,size);

	   // If the first send failed, try one more time before returning false.
	   if (!ret)
	   {
	      ret = m_parent->send(m_cfg,dataPtr,size);
	   }

	   // Free the buffer copy ... the parent send does not consume it.
	   delete dataPtr;
	}

	// If the send was successful, free the passed in buffer.
	if (ret)
	{
	   delete buf;
	}

	return ret;



	// }}}USR
}
// }}}RME

// {{{RME operation 'activate()'
bool Omap1610I2c::activate( void )
{
	// {{{USR
	return true;
	// }}}USR
}
// }}}RME

// {{{RME operation 'deactivate()'
bool Omap1610I2c::deactivate( void )
{
	// {{{USR
	return true;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setOption(Configurable::Option *)'
bool Omap1610I2c::setOption( Configurable::Option * option )
{
	// {{{USR
	bool retValue = false;

	if(option->isType(OptionQuantizationUnit::CONNECTION_OPTION_QUANT))
	{
		m_currentRxThreshold = ((OptionQuantizationUnit *)option)->getQuantizationUnit();
		delete(option);
		retValue = true;
	}

	return retValue;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getOption(ClassType)'
Connection::Option * Omap1610I2c::getOption( ClassType optionType )
{
	// {{{USR
	OptionQuantizationUnit *ret = 0;

	if (optionType == OptionQuantizationUnit::CONNECTION_OPTION_QUANT)
	{
		ret = new OptionQuantizationUnit(m_currentRxThreshold);
	}
	return ret;

	// }}}USR
}
// }}}RME

// {{{RME operation 'getStatus()'
Connection::Status * Omap1610I2c::getStatus( void )
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

// }}}RME
