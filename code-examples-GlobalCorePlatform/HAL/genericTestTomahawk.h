// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::genericTests::genericTestsMOTICs::genericTestsTomahawk::genericTestTomahawk'

#ifndef genericTestTomahawk_H
#define genericTestTomahawk_H

#ifdef PRAGMA
#pragma interface "genericTestTomahawk.h"
#endif

#include <HALtestLib_win32.h>
#include <genericTestBase.h>
class targetConfigTomahawk;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class genericTestTomahawk : public genericTestBase
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
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	genericTestTomahawk( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~genericTestTomahawk( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	genericTestTomahawk( const genericTestTomahawk & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	genericTestTomahawk & operator=( const genericTestTomahawk & rtg_arg );
	// }}}RME
	// {{{RME operation 'genericTestTomahawk(targetConfigBase *)'
	genericTestTomahawk( targetConfigBase * hwPlatformConfig );
	// }}}RME
	// {{{RME operation 'init(genericTestBase::initConfig *)'
	genericTestBase::initResult * init( genericTestBase::initConfig * config = 0 );
	// }}}RME
	// {{{RME operation 'execute(genericTestBase::testConfig *)'
	genericTestBase::testResult * execute( genericTestBase::testConfig * config = 0 );
	// }}}RME
	// {{{RME operation 'oldTest()'
	void oldTest( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* genericTestTomahawk_H */

// }}}RME
