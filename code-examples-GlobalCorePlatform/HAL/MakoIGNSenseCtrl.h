// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoIGNSenseCtrl'

#ifndef MakoIGNSenseCtrl_H
#define MakoIGNSenseCtrl_H

#ifdef PRAGMA
#pragma interface "MakoIGNSenseCtrl.h"
#endif

#include <HALtestLib_win32.h>
#include <IOVirtual.h>
#include <rf_audio_std_types.h>
class Mako;
class MakoPrivateBitfieldsReg2;
class bitfield;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>
// }}}USR
// }}}RME

class MakoIGNSenseCtrl : public IOVirtual
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
	// {{{RME classAttribute 'm_MakoParent'
	Mako * m_MakoParent;
	// }}}RME

public:
	// {{{RME operation 'MakoIGNSenseCtrl(Mako *,unsigned int)'
	MakoIGNSenseCtrl( Mako * parent, unsigned int ignmode );
	// }}}RME
	// {{{RME operation '~MakoIGNSenseCtrl()'
	~MakoIGNSenseCtrl( void );
	// }}}RME
	// {{{RME operation 'setIGNmode(int)'
	void setIGNmode( int ignmode );
	// }}}RME
	// {{{RME operation 'getIGNpinState()'
	uint32_t getIGNpinState( void );
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

#endif /* MakoIGNSenseCtrl_H */

// }}}RME
