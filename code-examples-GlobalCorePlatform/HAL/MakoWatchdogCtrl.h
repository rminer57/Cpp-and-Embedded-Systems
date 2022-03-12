// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoWatchdogCtrl'

#ifndef MakoWatchdogCtrl_H
#define MakoWatchdogCtrl_H

#ifdef PRAGMA
#pragma interface "MakoWatchdogCtrl.h"
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

class MakoWatchdogCtrl
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
	// {{{RME operation 'MakoWatchdogCtrl(Mako *)'
	MakoWatchdogCtrl( Mako * parent );
	// }}}RME
	// {{{RME operation '~MakoWatchdogCtrl()'
	~MakoWatchdogCtrl( void );
	// }}}RME
	// {{{RME operation 'refresh()'
	void refresh( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* MakoWatchdogCtrl_H */

// }}}RME
