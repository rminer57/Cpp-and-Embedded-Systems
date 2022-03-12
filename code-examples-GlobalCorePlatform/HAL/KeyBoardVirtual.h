// {{{RME classifier 'Logical View::Usb::UsbHost::UsbHID::KeyBoardVirtual::KeyBoardVirtual'

#ifndef KeyBoardVirtual_H
#define KeyBoardVirtual_H

#ifdef PRAGMA
#pragma interface "KeyBoardVirtual.h"
#endif

#include <usbimp.h>
class KeypadVirtualEvent;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class KeyBoardVirtual
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
	KeyBoardVirtual( void );
	// }}}RME
	// {{{RME operation 'receive()'
	virtual int receive( void ) = 0;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* KeyBoardVirtual_H */

// }}}RME
