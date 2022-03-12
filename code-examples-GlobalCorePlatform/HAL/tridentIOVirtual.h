// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::trident::TridentPrivate::tridentIOVirtual'

#ifndef tridentIOVirtual_H
#define tridentIOVirtual_H

#ifdef PRAGMA
#pragma interface "tridentIOVirtual.h"
#endif

#include <rf_sequencer_comp.h>
#include <IOVirtual.h>
#include <trident.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class tridentIOVirtual : public IOVirtual
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
	// {{{RME classAttribute 'm_whichIOVirtual'
	int m_whichIOVirtual;
	// }}}RME
	// {{{RME classAttribute 'm_lastValueSent'
	unsigned int m_lastValueSent;
	// }}}RME
	// {{{RME classAttribute 'm_tridentParent'
	trident * m_tridentParent;
	// }}}RME
	// {{{RME classAttribute 'm_rfState'
	int32_t m_rfState;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~tridentIOVirtual( void );
	// }}}RME
	// {{{RME operation 'send(unsigned int)'
	virtual void send( unsigned int outputState );
	// }}}RME
	// {{{RME operation 'receive()'
	virtual unsigned int receive( void );
	// }}}RME
	// {{{RME operation 'tridentIOVirtual(int,int32_t,trident *)'
	tridentIOVirtual( int whichIOVirtual, int32_t rfState, trident * tridentParent );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* tridentIOVirtual_H */

// }}}RME
