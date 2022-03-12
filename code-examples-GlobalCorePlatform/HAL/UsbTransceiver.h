// {{{RME classifier 'Logical View::Usb::UsbConfigMgr::UsbTransceiver'

#ifndef UsbTransceiver_H
#define UsbTransceiver_H

#ifdef PRAGMA
#pragma interface "UsbTransceiver.h"
#endif

#include <usbimp.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class UsbTransceiver
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
	// {{{RME classAttribute 'm_xcvrState'
	uint32_t m_xcvrState;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	UsbTransceiver( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~UsbTransceiver( void );
	// }}}RME
	// {{{RME operation 'setXcvrState(uint32_t)'
	virtual bool setXcvrState( uint32_t state ) = 0;
	// }}}RME
	// {{{RME operation 'setXcvrSpeed(uint32_t)'
	virtual bool setXcvrSpeed( uint32_t xcvrSpeed ) = 0;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* UsbTransceiver_H */

// }}}RME
