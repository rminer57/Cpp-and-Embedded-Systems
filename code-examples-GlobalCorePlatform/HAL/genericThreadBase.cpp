// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::genericThreads::genericThreadBase'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "genericThreadBase.h"
#endif

#include <HALtestLib_win32.h>
#include <genericThreadBase.h>
#include <genericThreadCommon.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'genericThreadBaseErrors_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'm_this'
genericThreadBase * genericThreadBase::m_this;
// }}}RME

// {{{RME classAttribute 'm_threadPointerPrimary'
genericThreadBase * genericThreadBase::m_threadPointerPrimary;
// }}}RME

// {{{RME classAttribute 'm_arrayOfAuxiliaryThreadsSize'
unsigned int genericThreadBase::m_arrayOfAuxiliaryThreadsSize;
// }}}RME

// {{{RME classAttribute 'm_arrayOfAuxiliaryThreads'
genericThreadBase * * genericThreadBase::m_arrayOfAuxiliaryThreads;
// }}}RME

// {{{RME operation 'genericThreadBase()'
genericThreadBase::genericThreadBase( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR

	m_targetConfig = 0;

	m_testConfig = 0;

	m_error = GENERICTHREAD_NOERROR;

	m_this = this;

	// }}}USR
}
// }}}RME

// {{{RME operation 'spawnAuxiliaryThreads()'
void genericThreadBase::spawnAuxiliaryThreads( void )
{
	// {{{USR
#define NUMOFSECONDARYTHREADS 2

	genericThreadBase::m_arrayOfAuxiliaryThreadsSize = NUMOFSECONDARYTHREADS;

	genericThreadBase::m_arrayOfAuxiliaryThreads = new genericThreadBase *[NUMOFSECONDARYTHREADS]; 

	for( int i = 0; i < NUMOFSECONDARYTHREADS; i++)
	{
	   // pass i as the thread id
	   genericThreadBase::m_arrayOfAuxiliaryThreads[i] = new genericThreadCommon(i);
	   genericThreadBase::m_arrayOfAuxiliaryThreads[i]->startThread(Thread::getPriorityMin());
	   genericThreadBase::m_arrayOfAuxiliaryThreads[i]->detach();

	}
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'genericThreadBaseErrors_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
