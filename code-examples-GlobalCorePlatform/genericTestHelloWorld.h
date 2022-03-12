// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::genericTests::genericTestsHelloWorld::genericTestHelloWorld'

#ifndef genericTestHelloWorld_H
#define genericTestHelloWorld_H

#ifdef PRAGMA
#pragma interface "genericTestHelloWorld.h"
#endif

#include <HALtestLib_win32.h>
#include <genericTestBase.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class genericTestHelloWorld : public genericTestBase
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
	genericTestHelloWorld( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~genericTestHelloWorld( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	genericTestHelloWorld( const genericTestHelloWorld & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	genericTestHelloWorld & operator=( const genericTestHelloWorld & rtg_arg );
	// }}}RME
	// {{{RME operation 'execute(genericTestBase::testConfig *)'
	genericTestBase::testResult * execute( genericTestBase::testConfig * config = 0 );
	// }}}RME
	// {{{RME operation 'init(genericTestBase::initConfig *)'
	genericTestBase::initResult * init( genericTestBase::initConfig * config = 0 );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* genericTestHelloWorld_H */

// }}}RME
