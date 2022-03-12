// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::genericThreads::genericThreadBase'

#ifndef genericThreadBase_H
#define genericThreadBase_H

#ifdef PRAGMA
#pragma interface "genericThreadBase.h"
#endif

#include <HALtestLib_win32.h>
#include <OSAL.h>
#include <Thread.h>
#include <TimeSpec.h>
#include <genericTestBase.h>
#include <targetConfigBase.h>
class genericThreadCommon;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR


// }}}USR
// }}}RME
// {{{RME classifier 'genericThreadBaseErrors_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class genericThreadBase : public Thread
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
	// {{{RME classifier 'genericThreadBaseErrors_t'
	enum genericThreadBaseErrors_t
	{
		GENERICTHREAD_NOERROR
	  , GENERICTHREAD_NULLTEST
	  , GENERICTHREAD_NULLTARGET
	};
	// }}}RME
	// {{{RME classAttribute 'm_targetConfig'
	targetConfigBase * m_targetConfig;
	// }}}RME
	// {{{RME classAttribute 'm_testConfig'
	genericTestBase * m_testConfig;
	// }}}RME
	// {{{RME classAttribute 'm_error'
	int m_error;
	// }}}RME
	// {{{RME classAttribute 'm_this'
	static genericThreadBase * m_this;
	// }}}RME
	// {{{RME classAttribute 'm_threadPointerPrimary'
	static genericThreadBase * m_threadPointerPrimary;
	// }}}RME
	// {{{RME classAttribute 'm_arrayOfAuxiliaryThreadsSize'
	static unsigned int m_arrayOfAuxiliaryThreadsSize;
	// }}}RME
	// {{{RME classAttribute 'm_arrayOfAuxiliaryThreads'
	static genericThreadBase * * m_arrayOfAuxiliaryThreads;
	// }}}RME
	// {{{RME operation 'genericThreadBase()'
	genericThreadBase( void );
	// }}}RME
	// {{{RME operation 'execute()'
	virtual int execute( void ) = 0;
	// }}}RME
	// {{{RME operation 'init()'
	virtual void init( void ) = 0;
	// }}}RME
	// {{{RME operation 'startThread(int)'
	virtual Thread * startThread( int priority = Thread::getPriorityMin() ) = 0;
	// }}}RME
	// {{{RME operation 'spawnAuxiliaryThreads()'
	static void spawnAuxiliaryThreads( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'genericThreadBaseErrors_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* genericThreadBase_H */

// }}}RME
