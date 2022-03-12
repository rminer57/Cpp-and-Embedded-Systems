// {{{RME classifier 'Logical View::Usb::UsbHost::UsbHID::GenericHidKeyboard'

#ifndef GenericHidKeyboard_H
#define GenericHidKeyboard_H

#ifdef PRAGMA
#pragma interface "GenericHidKeyboard.h"
#endif

#include <usbimp.h>
#include <UserInput.h>
#include <UserOutput.h>
class SECT;
class UserInputEvent;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class GenericHidKeyboard : public UserOutput, public UserInput
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
	GenericHidKeyboard( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~GenericHidKeyboard( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* GenericHidKeyboard_H */

// }}}RME
