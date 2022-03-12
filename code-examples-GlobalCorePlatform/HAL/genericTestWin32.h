// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::genericTests::genericTestsWin32::genericTestWin32'

#ifndef genericTestWin32_H
#define genericTestWin32_H

#ifdef PRAGMA
#pragma interface "genericTestWin32.h"
#endif

#include <HALtestLib_win32.h>
#include <genericTestBase.h>
class IOVirtual;
class IOVirtualSerial;
class TimerVirtual;
class targetConfigBase;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

#include <stdint.h>

// }}}USR
// }}}RME

class genericTestWin32 : public genericTestBase
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
	// {{{RME operation 'genericTestWin32(targetConfigBase *)'
	genericTestWin32( targetConfigBase * hwPlatformConfig );
	// }}}RME
	// {{{RME operation 'init(genericTestBase::initConfig *)'
	genericTestBase::initResult * init( genericTestBase::initConfig * config );
	// }}}RME
	// {{{RME operation 'execute(genericTestBase::testConfig *)'
	genericTestBase::testResult * execute( genericTestBase::testConfig * config = 0 );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* genericTestWin32_H */

// }}}RME
