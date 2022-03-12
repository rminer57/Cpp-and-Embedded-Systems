// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::Mako1WireCtrl'

#ifndef Mako1WireCtrl_H
#define Mako1WireCtrl_H

#ifdef PRAGMA
#pragma interface "Mako1WireCtrl.h"
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

class Mako1WireCtrl
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
	// {{{RME operation 'Mako1WireCtrl(Mako *)'
	Mako1WireCtrl( Mako * parent );
	// }}}RME
	// {{{RME operation '~Mako1WireCtrl()'
	~Mako1WireCtrl( void );
	// }}}RME
	// {{{RME operation 'setStateOneWireEN2Bus(bool)'
	void setStateOneWireEN2Bus( bool state );
	// }}}RME
	// {{{RME operation 'setStateBatBus(bool)'
	void setStateBatBus( bool state );
	// }}}RME
	// {{{RME operation 'setStateOneWireEN1Bus(bool)'
	void setStateOneWireEN1Bus( bool state );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Mako1WireCtrl_H */

// }}}RME
