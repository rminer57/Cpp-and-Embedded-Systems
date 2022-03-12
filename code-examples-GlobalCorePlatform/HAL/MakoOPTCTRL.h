// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoOPTCTRL'

#ifndef MakoOPTCTRL_H
#define MakoOPTCTRL_H

#ifdef PRAGMA
#pragma interface "MakoOPTCTRL.h"
#endif

#include <HALtestLib_win32.h>
#include <rf_audio_std_types.h>
class Mako;
class MakoPrivateBitfieldsReg4;
class bitfield;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>
// }}}USR
// }}}RME

class MakoOPTCTRL
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
	// {{{RME operation 'MakoOPTCTRL(Mako *,uint32_t,uint32_t,uint32_t)'
	MakoOPTCTRL( Mako * parent, uint32_t opt1init, uint32_t opt2init, uint32_t opt3init );
	// }}}RME
	// {{{RME operation 'gpioSetConfigB(uint32_t)'
	void gpioSetConfigB( uint32_t config );
	// }}}RME
	// {{{RME operation '~MakoOPTCTRL()'
	~MakoOPTCTRL( void );
	// }}}RME
	// {{{RME operation 'gpioSetDir(uint32_t)'
	void gpioSetDir( uint32_t config );
	// }}}RME
	// {{{RME operation 'gpioSetConfigA(uint32_t)'
	void gpioSetConfigA( uint32_t config );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* MakoOPTCTRL_H */

// }}}RME
