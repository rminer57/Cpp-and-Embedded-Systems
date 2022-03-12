// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::genericTests::genericTestsWin32::genericTestWin32'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "genericTestWin32.h"
#endif

#include <HALtestLib_win32.h>
#include <genericTestWin32.h>
#include <IOVirtual.h>
#include <IOVirtualSerial.h>
#include <TimerVirtual.h>
#include <targetConfigBase.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'genericTestWin32(targetConfigBase *)'
genericTestWin32::genericTestWin32( targetConfigBase * hwPlatformConfig )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR

	genericTestBase::initConfig * hwconf = new genericTestBase::initConfig(hwPlatformConfig);

	init(hwconf);




	// }}}USR
}
// }}}RME

// {{{RME operation 'init(genericTestBase::initConfig *)'
genericTestBase::initResult * genericTestWin32::init( genericTestBase::initConfig * config )
{
	// {{{USR

	if( config != 0)
	{
	  m_initConfig_ptr = config;

	  config->m_targetConfig->init();
	}

	return 0;



	// }}}USR
}
// }}}RME

// {{{RME operation 'execute(genericTestBase::testConfig *)'
genericTestBase::testResult * genericTestWin32::execute( genericTestBase::testConfig * config )
{
	// {{{USR
	static int x = 0;
	static int loops = 0;


	   targetConfigBase::sendStringToStderr("genericTestWin32 execute() method!\n");

	if(loops++ < 1)
	{
	   (targetConfigBase::m_PinsGPIO->getPin(targetConfigBase::PGAM_RESET_PIN))->send(x);

	   x = ~x;
	}
	return 0;


	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
