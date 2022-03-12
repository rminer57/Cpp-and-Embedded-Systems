// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::EventManagement::NotifierBaseEngine'

#ifndef NotifierBaseEngine_H
#define NotifierBaseEngine_H

#ifdef PRAGMA
#pragma interface "NotifierBaseEngine.h"
#endif

#include <base_interfaces_comp.h>
class EventBase;
class ListenerBase;
class Mutex;
class NotifierBase;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class NotifierBaseEngine
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

protected:
	// {{{RME classAttribute 'm_temp'
	void * m_temp;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~NotifierBaseEngine( void );
	// }}}RME

private:
	// {{{RME operation 'NotifierBaseEngine()'
	NotifierBaseEngine( void );
	// }}}RME

public:
	// {{{RME operation 'NotifierBaseEngine(NotifierBase *)'
	NotifierBaseEngine( NotifierBase * notif );
	// }}}RME
	// {{{RME operation 'informListenersActual(const EventBase * const)'
	virtual void informListenersActual( const EventBase * const event );
	// }}}RME
	// {{{RME operation 'registerListener(ListenerBase*,unsigned int)'
	virtual bool registerListener( ListenerBase * listener, unsigned int event );
	// }}}RME
	// {{{RME operation 'unregisterListener(ListenerBase*,unsigned int)'
	virtual bool unregisterListener( ListenerBase * listener, unsigned int event );
	// }}}RME
	// {{{RME operation 'unregisterListenerExt(ListenerBase*,const EventBase * const)'
	virtual bool unregisterListenerExt( ListenerBase * listener, const EventBase * const event );
	// }}}RME
	// {{{RME operation 'registerListenerExt(ListenerBase*,const EventBase * const)'
	virtual bool registerListenerExt( ListenerBase * listener, const EventBase * const event );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* NotifierBaseEngine_H */

// }}}RME
