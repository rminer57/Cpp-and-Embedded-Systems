// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::trident::TridentPrivate::tridentIOVirtual'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "tridentIOVirtual.h"
#endif

#include <rf_sequencer_comp.h>
#include <tridentIOVirtual.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
tridentIOVirtual::~tridentIOVirtual( void )
{
}
// }}}RME

// {{{RME operation 'send(unsigned int)'
void tridentIOVirtual::send( unsigned int outputState )
{
	// {{{USR


	m_lastValueSent = outputState;

	m_tridentParent->setGPO( m_whichIOVirtual, outputState, m_rfState); 

	m_tridentParent->setRFState(m_rfState);
	// }}}USR
}
// }}}RME

// {{{RME operation 'receive()'
unsigned int tridentIOVirtual::receive( void )
{
	// {{{USR


	return m_lastValueSent;
	// }}}USR
}
// }}}RME

// {{{RME operation 'tridentIOVirtual(int,int32_t,trident *)'
tridentIOVirtual::tridentIOVirtual( int whichIOVirtual, int32_t rfState, trident * tridentParent )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_whichIOVirtual(whichIOVirtual), m_lastValueSent(0xFFFF), m_rfState( rfState ), m_tridentParent(tridentParent)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
