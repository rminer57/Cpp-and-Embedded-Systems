// {{{RME classifier 'Logical View::EventManagement::NotifierBaseExtender'

#ifndef NotifierBaseExtender_H
#define NotifierBaseExtender_H

#ifdef PRAGMA
#pragma interface "NotifierBaseExtender.h"
#endif

#include <event_mgmt.h>
class EventBase;
class NotifierBase;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class NotifierBaseExtender
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
	// {{{RME associationEnd 'm_notifier'
	NotifierBase * m_notifier;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~NotifierBaseExtender( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	NotifierBaseExtender( const NotifierBaseExtender & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	NotifierBaseExtender & operator=( const NotifierBaseExtender & rtg_arg );
	// }}}RME
	// {{{RME operation 'informListeners(const EventBase * const)'
	virtual void informListeners( const EventBase * const event ) = 0;
	// }}}RME
	// {{{RME operation 'informListenersActual(const EventBase * const)'
	void informListenersActual( const EventBase * const event );
	// }}}RME

private:
	// {{{RME operation 'NotifierBaseExtender()'
	NotifierBaseExtender( void );
	// }}}RME

public:
	// {{{RME operation 'NotifierBaseExtender(NotifierBase *)'
	NotifierBaseExtender( NotifierBase * notif );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* NotifierBaseExtender_H */

// }}}RME
