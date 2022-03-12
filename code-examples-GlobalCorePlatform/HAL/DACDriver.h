// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::DACDriver'

#ifndef DACDriver_H
#define DACDriver_H

#ifdef PRAGMA
#pragma interface "DACDriver.h"
#endif

#include <HALtestLib_win32.h>
#include <Mako.h>
class MakoPrivateBitfieldsReg6;
class rfSpiBuffer;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class DACDriver
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

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	DACDriver( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~DACDriver( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	DACDriver( const DACDriver & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	DACDriver & operator=( const DACDriver & rtg_arg );
	// }}}RME
	// {{{RME operation 'putDACBuffer(uint32_t,rfSpiBuffer*,int)'
	virtual void putDACBuffer( uint32_t dac, rfSpiBuffer * buffer, int value );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* DACDriver_H */

// }}}RME
