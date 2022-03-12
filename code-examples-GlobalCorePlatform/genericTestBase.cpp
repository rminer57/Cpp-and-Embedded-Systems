// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::genericTests::genericTestBase'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "genericTestBase.h"
#endif

#include <HALtestLib_win32.h>
#include <genericTestBase.h>
#include <TimeSpec.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'genericTestEnum_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'testConfig' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'testResult' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'initConfig' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'initResult' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classifier 'testConfig'

// }}}RME

// {{{RME classifier 'testResult'

// }}}RME

// {{{RME classifier 'initConfig'

// {{{RME operation 'init()'
void genericTestBase::initConfig::init( void )
{
	// {{{USR


	//initConfig * targetConfigNodePointer = this;

	//while( targetConfigNodePointer->m_targetConfig != 0)
	//{
	  // initialize current object.
	//  m_targetConfig->init();

	  // traverse the list.
	//  if( targetConfigNodePointer->m_initConfigList != 0 )
	//  {
	    // point to next initConfig object in list and initialize it.
	//    targetConfigNodePointer = targetConfigNodePointer->m_initConfigList;
	//  }

	//}

	// }}}USR
}
// }}}RME

// {{{RME operation 'initConfig(targetConfigBase *)'
genericTestBase::initConfig::initConfig( targetConfigBase * targetConfig )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR

	m_targetConfig = targetConfig;

	// }}}USR
}
// }}}RME

// {{{RME operation 'addNewinitConfigToList()'
void genericTestBase::initConfig::addNewinitConfigToList( void )
{
	// {{{USR

	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME classifier 'initResult'

// }}}RME

// {{{RME operation 'eventOccurred(const EventBase * const)'
void genericTestBase::eventOccurred( const EventBase * const event )
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'genericTestEnum_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'testConfig' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'testResult' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'initConfig' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'initResult' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
