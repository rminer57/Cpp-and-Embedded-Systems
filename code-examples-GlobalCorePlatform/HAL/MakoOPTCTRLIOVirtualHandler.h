// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoOPTCTRLSubsystem::MakoOPTCTRLIOVirtualHandler'

#ifndef MakoOPTCTRLIOVirtualHandler_H
#define MakoOPTCTRLIOVirtualHandler_H

#ifdef PRAGMA
#pragma interface "MakoOPTCTRLIOVirtualHandler.h"
#endif

#include <rf_sequencer_comp.h>
#include <IOVirtual.h>
class Mako;
class MakoOPTCTRL;
class MakoPrivateBitfieldsReg4;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
 #include <stdint.h>
// }}}USR
// }}}RME

class MakoOPTCTRLIOVirtualHandler : public IOVirtual
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
	// {{{RME classAttribute 'm_which_OPT_CTRL_reg'
	int m_which_OPT_CTRL_reg;
	// }}}RME
	// {{{RME classAttribute 'm_MakoOPTCTRL_parent'
	MakoOPTCTRL * m_MakoOPTCTRL_parent;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~MakoOPTCTRLIOVirtualHandler( void );
	// }}}RME
	// {{{RME operation 'MakoOPTCTRLIOVirtualHandler(unsigned int,MakoOPTCTRL *)'
	MakoOPTCTRLIOVirtualHandler( unsigned int whichIOVirtual, MakoOPTCTRL * parent );
	// }}}RME
	// {{{RME operation 'receive()'
	unsigned int receive( void );
	// }}}RME
	// {{{RME operation 'send(unsigned int)'
	void send( unsigned int data );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* MakoOPTCTRLIOVirtualHandler_H */

// }}}RME
