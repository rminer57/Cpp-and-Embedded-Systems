// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Radio Frequency Deck::RFVirtual'

#ifndef RFVirtual_H
#define RFVirtual_H

#ifdef PRAGMA
#pragma interface "RFVirtual.h"
#endif

#include <hal.h>
#include <NotifierBase.h>
class RFVirtualSequence;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class RFVirtual : public NotifierBase
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
	// {{{RME associationEnd 'theRFVIrtualSequences'
	RFVirtualSequence ** theRFVIrtualSequences;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~RFVirtual( void );
	// }}}RME
	// {{{RME operation 'executeSequence(unsigned int)'
	virtual bool executeSequence( unsigned int sequence ) = 0;
	// }}}RME
	// {{{RME operation 'setRegister(unsigned int,long)'
	virtual void setRegister( unsigned int reg, long value ) = 0;
	// }}}RME
	// {{{RME operation 'getRegister(unsigned int)'
	virtual long getRegister( unsigned int reg ) = 0;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* RFVirtual_H */

// }}}RME
