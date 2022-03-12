// {{{RME classifier 'Logical View::Interrupt Management::IrqGenerator'

#ifndef IrqGenerator_H
#define IrqGenerator_H

#ifdef PRAGMA
#pragma interface "IrqGenerator.h"
#endif

#include <osal_support_build.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class IrqGenerator
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
	// {{{RME operation 'enableInterrupt(int)'
	virtual void enableInterrupt( int param = 0 ) = 0;
	// }}}RME
	// {{{RME operation 'disableInterrupt(int)'
	virtual void disableInterrupt( int param = 0 ) = 0;
	// }}}RME
	// {{{RME operation 'resetInterrupt(int)'
	virtual void resetInterrupt( int param = 0 ) = 0;
	// }}}RME
	// {{{RME operation 'generateInterrupt(int)'
	virtual void generateInterrupt( int param = 0 ) = 0;
	// }}}RME
	// {{{RME operation 'configInterrupt(int,int)'
	virtual void configInterrupt( int param, int config ) = 0;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* IrqGenerator_H */

// }}}RME
