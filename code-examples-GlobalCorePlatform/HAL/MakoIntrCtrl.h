// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoIntrCtrl'

#ifndef MakoIntrCtrl_H
#define MakoIntrCtrl_H

#ifdef PRAGMA
#pragma interface "MakoIntrCtrl.h"
#endif

#include <HALtestLib_win32.h>
#include <rf_audio_std_types.h>
class Mako;
class MakoPrivateBitfieldsReg2;
class bitfield;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>
// }}}USR
// }}}RME

class MakoIntrCtrl
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
	// {{{RME operation 'MakoIntrCtrl(Mako *,uint32_t)'
	MakoIntrCtrl( Mako * parent, uint32_t reginit );
	// }}}RME
	// {{{RME operation '~MakoIntrCtrl()'
	~MakoIntrCtrl( void );
	// }}}RME
	// {{{RME operation 'rdIntrRegister()'
	uint32_t rdIntrRegister( void );
	// }}}RME
	// {{{RME operation 'wrIntrRegister(uint32_t)'
	void wrIntrRegister( uint32_t data );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* MakoIntrCtrl_H */

// }}}RME
