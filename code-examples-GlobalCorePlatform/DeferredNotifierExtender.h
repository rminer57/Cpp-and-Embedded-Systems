// {{{RME classifier 'Logical View::Interrupt Management::DeferredNotifierExtender'

#ifndef DeferredNotifierExtender_H
#define DeferredNotifierExtender_H

#ifdef PRAGMA
#pragma interface "DeferredNotifierExtender.h"
#endif

#include <osal_support_build.h>
#include <NotifierBaseExtender.h>
class HALiNucleusNotifier;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class DeferredNotifierExtender : public NotifierBaseExtender
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
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~DeferredNotifierExtender( void );
	// }}}RME
	// {{{RME operation 'DeferredNotifierExtender(NotifierBase*)'
	DeferredNotifierExtender( NotifierBase * notif );
	// }}}RME

protected:
	// {{{RME operation 'informListeners(const EventBase * const)'
	virtual void informListeners( const EventBase * const event );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* DeferredNotifierExtender_H */

// }}}RME
