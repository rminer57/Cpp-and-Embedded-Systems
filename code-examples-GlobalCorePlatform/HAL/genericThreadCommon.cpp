// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::genericThreads::genericThreadCommon::genericThreadCommon'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "genericThreadCommon.h"
#endif

#include <HALtestLib_win32.h>
#include <genericThreadCommon.h>
#include <IOVirtualSimBase.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
genericThreadCommon::genericThreadCommon( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
genericThreadCommon::~genericThreadCommon( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
genericThreadCommon::genericThreadCommon( const genericThreadCommon & rtg_arg )
	: genericThreadBase( rtg_arg )
	, m_counter( rtg_arg.m_counter )
	, m_myID( rtg_arg.m_myID )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
genericThreadCommon & genericThreadCommon::operator=( const genericThreadCommon & rtg_arg )
{
	if( this != &rtg_arg )
	{
		genericThreadBase::operator=( rtg_arg );
		m_counter = rtg_arg.m_counter;
		m_myID = rtg_arg.m_myID;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'genericThreadCommon(unsigned int)'
genericThreadCommon::genericThreadCommon( unsigned int myID )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR

	m_myID = myID;

	m_counter = 0;

	// }}}USR
}
// }}}RME

// {{{RME operation 'main()'
void * genericThreadCommon::main( void )
{
	// {{{USR

	while(1)
	{
	  m_counter++;

	  //targetConfigBase::sendStringToStderr("genericThreadCommon main thread, myID =");
	  //IOVirtualSimBase::setOutputBase(IOVirtualSimBase::OUTPUT_MODE_DEFAULT);
	  //targetConfigBase::send_int16_ToStderr((int16_t)m_myID);
	  //targetConfigBase::sendStringToStderr("   Loop=");
	  //IOVirtualSimBase::setOutputBase(IOVirtualSimBase::OUTPUT_MODE_DEFAULT);
	  //targetConfigBase::send_int16_ToStderr(m_counter);
	  //targetConfigBase::sendStringToStderr("  is alive!\n");

	  Thread::sleep(2);
	}

	detach();

	return 0;
	// }}}USR
}
// }}}RME

// {{{RME operation 'execute()'
int genericThreadCommon::execute( void )
{
	// {{{USR


	return 0;
	// }}}USR
}
// }}}RME

// {{{RME operation 'init()'
void genericThreadCommon::init( void )
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'startThread(int)'
Thread * genericThreadCommon::startThread( int priority )
{
	// {{{USR



	// launch this object as a thread
	return actuallyCreateThread(priority, this);
	// }}}USR
}
// }}}RME

// {{{RME operation 'genericThreadCommon(unsigned int,int)'
genericThreadCommon::genericThreadCommon( unsigned int myID, int priority )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR

	m_myID = myID;

	m_counter = 0;

	startThread(priority);
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
