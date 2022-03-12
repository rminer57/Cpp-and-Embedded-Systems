// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::genericThreads::genericThreadCommon::genericThreadCommon'

#ifndef genericThreadCommon_H
#define genericThreadCommon_H

#ifdef PRAGMA
#pragma interface "genericThreadCommon.h"
#endif

#include <HALtestLib_win32.h>
#include <genericThreadBase.h>
class IOVirtualSimBase;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class genericThreadCommon : public genericThreadBase
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
	// {{{RME classAttribute 'm_counter'
	int16_t m_counter;
	// }}}RME
	// {{{RME classAttribute 'm_myID'
	unsigned int m_myID;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	genericThreadCommon( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~genericThreadCommon( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	genericThreadCommon( const genericThreadCommon & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	genericThreadCommon & operator=( const genericThreadCommon & rtg_arg );
	// }}}RME
	// {{{RME operation 'genericThreadCommon(unsigned int)'
	genericThreadCommon( unsigned int myID );
	// }}}RME

protected:
	// {{{RME operation 'main()'
	void * main( void );
	// }}}RME

public:
	// {{{RME operation 'execute()'
	int execute( void );
	// }}}RME
	// {{{RME operation 'init()'
	void init( void );
	// }}}RME
	// {{{RME operation 'startThread(int)'
	Thread * startThread( int priority = Thread::getPriorityMin() );
	// }}}RME
	// {{{RME operation 'genericThreadCommon(unsigned int,int)'
	genericThreadCommon( unsigned int myID, int priority );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* genericThreadCommon_H */

// }}}RME
