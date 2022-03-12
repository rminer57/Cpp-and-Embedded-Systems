// {{{RME classifier 'Logical View::EventManagement::NotifierBaseExtender'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "NotifierBaseExtender.h"
#endif

#include <event_mgmt.h>
#include <NotifierBaseExtender.h>
#include <EventBase.h>
#include <NotifierBase.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
NotifierBaseExtender::~NotifierBaseExtender( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
NotifierBaseExtender::NotifierBaseExtender( const NotifierBaseExtender & rtg_arg )
	: m_notifier( rtg_arg.m_notifier )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
NotifierBaseExtender & NotifierBaseExtender::operator=( const NotifierBaseExtender & rtg_arg )
{
	if( this != &rtg_arg )
		m_notifier = rtg_arg.m_notifier;
	return *this;
}
// }}}RME

// {{{RME operation 'informListenersActual(const EventBase * const)'
void NotifierBaseExtender::informListenersActual( const EventBase * const event )
{
	// {{{USR
	m_notifier->informListenersActual(event);
	// }}}USR
}
// }}}RME

// {{{RME operation 'NotifierBaseExtender()'
NotifierBaseExtender::NotifierBaseExtender( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'NotifierBaseExtender(NotifierBase *)'
NotifierBaseExtender::NotifierBaseExtender( NotifierBase * notif )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_notifier(notif)
	// }}}USR
	// }}}RME
{
	// {{{USR
	notif->m_extender = this;							//attach to notifierbase
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
