// {{{RME classifier 'Logical View::StateMachineFramework::StateMachineFramework'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "StateMachineFramework.h"
#endif

#include <smf.h>
#include <StateMachineFramework.h>
#include <BaseStateMachine.h>
#include <EventData.h>
#include <Invoker.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR


// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
StateMachineFramework::StateMachineFramework( void )
	: m_processingRequest( 0 )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
StateMachineFramework::~StateMachineFramework( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
StateMachineFramework::StateMachineFramework( const StateMachineFramework & rtg_arg )
	: m_processingRequest( rtg_arg.m_processingRequest )
	, eventQueue( rtg_arg.eventQueue )
	, dispatchQueue( rtg_arg.dispatchQueue )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
StateMachineFramework & StateMachineFramework::operator=( const StateMachineFramework & rtg_arg )
{
	if( this != &rtg_arg )
	{
		m_processingRequest = rtg_arg.m_processingRequest;
		eventQueue = rtg_arg.eventQueue;
		dispatchQueue = rtg_arg.dispatchQueue;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'dispatch(BaseStateMachine *,unsigned int,EventData *)'
void StateMachineFramework::dispatch( BaseStateMachine * sm, unsigned int event, EventData * data )
{
	// {{{USR
	Invoker * pInvoker = new Invoker(sm, event, data);

	if(m_processingRequest != true)
	{
		do 
		{
			m_processingRequest = true;

			do
			{
				pInvoker->invoke();

	    		delete pInvoker;

				pInvoker = eventQueue.get();
		
			} while(pInvoker != 0);

			pInvoker = dispatchQueue.get();

		} while (pInvoker != 0);

		m_processingRequest = false;

	}
	else
	{
		dispatchQueue.add(pInvoker);
	}	 




	// }}}USR
}
// }}}RME

// {{{RME operation 'queueEvent(BaseStateMachine *,unsigned int,EventData *)'
void StateMachineFramework::queueEvent( BaseStateMachine * sm, unsigned int event, EventData * data )
{
	// {{{USR
	Invoker * pInvoker = new Invoker(sm, event, data);

	eventQueue.add(pInvoker);
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
