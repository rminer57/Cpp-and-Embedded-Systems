// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoDCPwrCtrl'

#ifndef MakoDCPwrCtrl_H
#define MakoDCPwrCtrl_H

#ifdef PRAGMA
#pragma interface "MakoDCPwrCtrl.h"
#endif

#include <HALtestLib_win32.h>
#include <rf_audio_std_types.h>
class Mako;
class MakoPrivateBitfieldsReg2;
class bitfield;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class MakoDCPwrCtrl
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
	// {{{RME operation 'MakoDCPwrCtrl(Mako *,unsigned int)'
	MakoDCPwrCtrl( Mako * parent, unsigned int reginit );
	// }}}RME
	// {{{RME operation '~MakoDCPwrCtrl()'
	~MakoDCPwrCtrl( void );
	// }}}RME
	// {{{RME operation 'setSwitcherFreq(int)'
	void setSwitcherFreq( int data );
	// }}}RME

private:
	// {{{RME operation 'setCHCKbit()'
	void setCHCKbit( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* MakoDCPwrCtrl_H */

// }}}RME
