// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoADC'

#ifndef MakoADC_H
#define MakoADC_H

#ifdef PRAGMA
#pragma interface "MakoADC.h"
#endif

#include <HALtestLib_win32.h>
#include <IOVirtual.h>
#include <rf_audio_std_types.h>
class Mako;
class MakoPrivateBitfieldsReg7;
class bitfield;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>
// }}}USR
// }}}RME

class MakoADC : public IOVirtual
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
	// {{{RME classAttribute 'm_adcSelect'
	unsigned int m_adcSelect;
	// }}}RME
	// {{{RME classAttribute 'm_MakoParent'
	Mako * m_MakoParent;
	// }}}RME

public:
	// {{{RME operation 'MakoADC(Mako *,unsigned int,uint32_t)'
	MakoADC( Mako * parent, unsigned int adcSelect, uint32_t adcConfig = 0 );
	// }}}RME
	// {{{RME operation 'send(unsigned int)'
	void send( unsigned int data );
	// }}}RME
	// {{{RME operation 'receive()'
	unsigned int receive( void );
	// }}}RME
	// {{{RME operation '~MakoADC()'
	~MakoADC( void );
	// }}}RME
	// {{{RME operation 'setState(bool)'
	void setState( bool state );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* MakoADC_H */

// }}}RME
