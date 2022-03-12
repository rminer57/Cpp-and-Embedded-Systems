// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::TestSupportWin32::IOVirtualSerialSimulationStderr'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "IOVirtualSerialSimulationStderr.h"
#endif

#include <HALtestLib_win32.h>
#include <IOVirtualSerialSimulationStderr.h>
#include <SCharArray.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
#ifdef _WIN32

using namespace std;

static FILE * m_logfile_ptr;

#endif
// }}}USR
// }}}RME

// {{{RME operation 'IOVirtualSerialSimulationStderr()'
IOVirtualSerialSimulationStderr::IOVirtualSerialSimulationStderr( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR

	m_outputBase = OUTPUT_MODE_HEX;

	//Enable logging
	//m_logger = DefaultLogger::getDefaultLogger();
	//m_logDestination = new LogHexDump();
	//m_logger->registerDestination(m_logDestination);
	//m_logger->enable();

	//Log a started message
	//m_logMessage = new DataBuffer("Logging Enabled\n\r", sizeof("Logging Enabled\n\r"));
	//m_logger->log(m_logMessage);
	// }}}USR
}
// }}}RME

// {{{RME operation 'activate()'
bool IOVirtualSerialSimulationStderr::activate( void )
{
	// {{{USR
	return true;
	// }}}USR
}
// }}}RME

// {{{RME operation 'deactivate()'
bool IOVirtualSerialSimulationStderr::deactivate( void )
{
	// {{{USR
	return true;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getStatus()'
Connection::Status * IOVirtualSerialSimulationStderr::getStatus( void )
{
	// {{{USR
	return (Connection::Status *)0;
	// }}}USR
}
// }}}RME

// {{{RME operation 'receive()'
Array * IOVirtualSerialSimulationStderr::receive( void )
{
	// {{{USR


	SCharArray * returndb = 0; // = new DataBuffer((void *)&m_valueToBeReturnedByReceive,(unsigned int)4);

	return returndb;


	// }}}USR
}
// }}}RME

// {{{RME operation 'send(Array *)'
bool IOVirtualSerialSimulationStderr::send( Array * buffer )
{
	// {{{USR

	return  IOVirtualSimBase::send(buffer);
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
