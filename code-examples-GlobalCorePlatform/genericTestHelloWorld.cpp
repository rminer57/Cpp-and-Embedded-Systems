// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::genericTests::genericTestsHelloWorld::genericTestHelloWorld'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "genericTestHelloWorld.h"
#endif

#include <HALtestLib_win32.h>
#include <genericTestHelloWorld.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
genericTestHelloWorld::genericTestHelloWorld( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
genericTestHelloWorld::~genericTestHelloWorld( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
genericTestHelloWorld::genericTestHelloWorld( const genericTestHelloWorld & rtg_arg )
	: genericTestBase( rtg_arg )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
genericTestHelloWorld & genericTestHelloWorld::operator=( const genericTestHelloWorld & rtg_arg )
{
	if( this != &rtg_arg )
		genericTestBase::operator=( rtg_arg );
	return *this;
}
// }}}RME

// {{{RME operation 'execute(genericTestBase::testConfig *)'
genericTestBase::testResult * genericTestHelloWorld::execute( genericTestBase::testConfig * config )
{
	// {{{USR

	   targetConfigBase::sendStringToStderr("genericTestHelloWorld execute() method!\n");

	return 0;
	// }}}USR
}
// }}}RME

// {{{RME operation 'init(genericTestBase::initConfig *)'
genericTestBase::initResult * genericTestHelloWorld::init( genericTestBase::initConfig * config )
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

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
