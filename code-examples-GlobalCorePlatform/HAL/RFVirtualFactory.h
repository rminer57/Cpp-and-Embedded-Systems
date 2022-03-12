// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Radio Frequency Deck::RFVirtualFactory'

#ifndef RFVirtualFactory_H
#define RFVirtualFactory_H

#ifdef PRAGMA
#pragma interface "RFVirtualFactory.h"
#endif

#include <hal.h>
class RFVirtual;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class RFVirtualFactory
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
	virtual ~RFVirtualFactory( void );
	// }}}RME
	// {{{RME operation 'getRFVirtual()'
	virtual RFVirtual * getRFVirtual( void ) = 0;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* RFVirtualFactory_H */

// }}}RME
