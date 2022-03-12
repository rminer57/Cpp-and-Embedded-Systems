// {{{RME classifier 'Logical View::StateMachineFramework::StateMachineFramework'

#ifndef StateMachineFramework_H
#define StateMachineFramework_H

#ifdef PRAGMA
#pragma interface "StateMachineFramework.h"
#endif

#include <smf.h>
#include <InvokerQueue.h>
class BaseStateMachine;
class EventData;
class Invoker;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR



// }}}USR
// }}}RME

class StateMachineFramework
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
	// {{{RME classAttribute 'm_processingRequest'
	bool m_processingRequest;
	// }}}RME
	// {{{RME associationEnd 'eventQueue'
	InvokerQueue eventQueue;
	// }}}RME
	// {{{RME associationEnd 'dispatchQueue'
	InvokerQueue dispatchQueue;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	StateMachineFramework( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~StateMachineFramework( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	StateMachineFramework( const StateMachineFramework & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	StateMachineFramework & operator=( const StateMachineFramework & rtg_arg );
	// }}}RME

protected:
	// {{{RME operation 'dispatch(BaseStateMachine *,unsigned int,EventData *)'
	void dispatch( BaseStateMachine * sm, unsigned int event, EventData * data = 0 );
	// }}}RME

public:
	// {{{RME operation 'queueEvent(BaseStateMachine *,unsigned int,EventData *)'
	void queueEvent( BaseStateMachine * sm, unsigned int event, EventData * data = 0 );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* StateMachineFramework_H */

// }}}RME
