// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::TestSupportWin32::IOVirtualSerialSimSPI'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "IOVirtualSerialSimSPI.h"
#endif

#include <HALtestLib_win32.h>
#include <IOVirtualSerialSimSPI.h>
#include <SCharArray.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'serialSimSPIdevices_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
IOVirtualSerialSimSPI::IOVirtualSerialSimSPI( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
IOVirtualSerialSimSPI::~IOVirtualSerialSimSPI( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
IOVirtualSerialSimSPI::IOVirtualSerialSimSPI( const IOVirtualSerialSimSPI & rtg_arg )
	: IOVirtualSerial( rtg_arg )
	, IOVirtualSimBase( rtg_arg )
	, m_lastDataSent( rtg_arg.m_lastDataSent )
	, m_whichIC( rtg_arg.m_whichIC )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
IOVirtualSerialSimSPI & IOVirtualSerialSimSPI::operator=( const IOVirtualSerialSimSPI & rtg_arg )
{
	if( this != &rtg_arg )
	{
		IOVirtualSerial::operator=( rtg_arg );
		IOVirtualSimBase::operator=( rtg_arg );
		m_lastDataSent = rtg_arg.m_lastDataSent;
		m_whichIC = rtg_arg.m_whichIC;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'IOVirtualSerialSimSPI(IOVirtualSerialSimSPI::serialSimSPIdevices_t)'
IOVirtualSerialSimSPI::IOVirtualSerialSimSPI( serialSimSPIdevices_t whichIC )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR

	m_whichIC = whichIC;

	m_lastDataSent = 0;


	// }}}USR
}
// }}}RME

// {{{RME operation 'activate()'
bool IOVirtualSerialSimSPI::activate( void )
{
	// {{{USR
	return true;
	// }}}USR
}
// }}}RME

// {{{RME operation 'deactivate()'
bool IOVirtualSerialSimSPI::deactivate( void )
{
	// {{{USR
	return true;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getStatus()'
Connection::Status * IOVirtualSerialSimSPI::getStatus( void )
{
	// {{{USR
	return (Connection::Status *)0;
	// }}}USR
}
// }}}RME

// {{{RME operation 'receive()'
Array * IOVirtualSerialSimSPI::receive( void )
{
	// {{{USR

	int16_t debug_db0;
	int16_t debug_db1;

	debug_db0 = 0;
	debug_db1 = 0;

	IOVirtualSimBase::send("Mako SPI read - (causes write)\n\r");

	if( m_lastDataSent != 0 )
	{
	   debug_db0 = ( *((SIntArray *)m_lastDataSent))[0];
	   debug_db1 = ( *((SIntArray *)m_lastDataSent))[1];    
	}
	else
	{
	  IOVirtualSimBase::send("Error: IOVirtualSerialSimSPIMako->m_lastDataSent = NULL, see IOVirtualSerialSimSPIMako->receive documentation  \n\r");
	}

	return m_lastDataSent;


	// }}}USR
}
// }}}RME

// {{{RME operation 'send(Array *)'
bool IOVirtualSerialSimSPI::send( Array * buffer )
{
	// {{{USR
	  
	   int16_t debug_db0;
	   int16_t debug_db1;

	   debug_db0 = 0;
	   debug_db1 = 0;

	   // the Mako wrRegister method which calls this send, should have converted
	   // the values to Big Endian.
	   // e.g. 0x40002400 should be displayed "backwards" in visual studio, which assumes 
	   // Little Endian, as
	   // debug_db0 = lo/hi = 0040  .. Big Endian decodes this as 4000 which is how SPI expects it.
	   // debug_db1 = lo/hi = 0024  .. Big Endian decodes this as 2400   
	   debug_db0 = (*((SIntArray *)buffer))[0];
	   debug_db1 = (*((SIntArray *)buffer))[1];

	  
	   // clone the buffer to be reused for receive, or for debug evaluation.
	   m_lastDataSent = (Array *)((SIntArray *)buffer)->clone();

	   // the receive method will read back the cloned value, make sure it is correct.
	   debug_db0 = (* ((SIntArray *)m_lastDataSent))[0];
	   debug_db1 = (* ((SIntArray *)m_lastDataSent))[1];    


	   IOVirtualSimBase::send(" Mako SPI send: ");

	   IOVirtualSimBase::setOutputBase(IOVirtualSimBase::OUTPUT_MODE_BIN);

	   IOVirtualSimBase::send( buffer );

	   IOVirtualSimBase::sendENDL();

	   return true;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'serialSimSPIdevices_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
