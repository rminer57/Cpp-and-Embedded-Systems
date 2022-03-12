// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Timer::TimerVirtualFactory'

#ifndef TimerVirtualFactory_H
#define TimerVirtualFactory_H

#ifdef PRAGMA
#pragma interface "TimerVirtualFactory.h"
#endif

#include <hal.h>
class TimerVirtual;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class TimerVirtualFactory
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
	virtual ~TimerVirtualFactory( void );
	// }}}RME
	// {{{RME operation 'getTimerVirtual(bool)'
	virtual TimerVirtual * getTimerVirtual( bool autoRearm = true ) = 0;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* TimerVirtualFactory_H */

// }}}RME
