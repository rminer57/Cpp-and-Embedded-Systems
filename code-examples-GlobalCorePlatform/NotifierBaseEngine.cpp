// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::EventManagement::NotifierBaseEngine'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "NotifierBaseEngine.h"
#endif

#include <base_interfaces_comp.h>
#include <NotifierBaseEngine.h>
#include <EventBase.h>
#include <ListenerBase.h>
#include <Mutex.h>
#include <NotifierBase.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
NotifierBaseEngine::~NotifierBaseEngine( void )
{
}
// }}}RME

// {{{RME operation 'NotifierBaseEngine()'
NotifierBaseEngine::NotifierBaseEngine( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'NotifierBaseEngine(NotifierBase *)'
NotifierBaseEngine::NotifierBaseEngine( NotifierBase * notif )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	//release all resources from the provided notifier.

	//Save node list for sub-class processing...
	m_temp = notif->m_first.node;

	//Setup a reference to this object within the NotifierBase
	notif->m_first.engine = this;

	if (notif->m_mutex != 0) delete notif->m_mutex;								//release mutex.
	notif->m_mutex = 0;

	//At this point, functionality has been taken over.
	// }}}USR
}
// }}}RME

// {{{RME operation 'informListenersActual(const EventBase * const)'
void NotifierBaseEngine::informListenersActual( const EventBase * const event )
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'registerListener(ListenerBase*,unsigned int)'
bool NotifierBaseEngine::registerListener( ListenerBase * listener, unsigned int event )
{
	// {{{USR
	return false;
	// }}}USR
}
// }}}RME

// {{{RME operation 'unregisterListener(ListenerBase*,unsigned int)'
bool NotifierBaseEngine::unregisterListener( ListenerBase * listener, unsigned int event )
{
	// {{{USR
	return false;
	// }}}USR
}
// }}}RME

// {{{RME operation 'unregisterListenerExt(ListenerBase*,const EventBase * const)'
bool NotifierBaseEngine::unregisterListenerExt( ListenerBase * listener, const EventBase * const event )
{
	// {{{USR
	return false;
	// }}}USR
}
// }}}RME

// {{{RME operation 'registerListenerExt(ListenerBase*,const EventBase * const)'
bool NotifierBaseEngine::registerListenerExt( ListenerBase * listener, const EventBase * const event )
{
	// {{{USR
	return false;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
