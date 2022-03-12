// {{{RME classifier 'Logical View::Usb::UsbConfigMgr::PG0_Mako2UsbXcvr'

#ifndef PG0_Mako2UsbXcvr_H
#define PG0_Mako2UsbXcvr_H

#ifdef PRAGMA
#pragma interface "PG0_Mako2UsbXcvr.h"
#endif

#include <usbimp.h>
#include <UsbTransceiver.h>
class USBPort;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class PG0_Mako2UsbXcvr : public UsbTransceiver
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
	PG0_Mako2UsbXcvr( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~PG0_Mako2UsbXcvr( void );
	// }}}RME
	// {{{RME operation 'setXcvrState(uint32_t)'
	bool setXcvrState( uint32_t state );
	// }}}RME
	// {{{RME operation 'PG2_Mako2UsbXcvr()'
	void PG2_Mako2UsbXcvr( void );
	// }}}RME
	// {{{RME operation 'setXcvrSpeed(uint32_t)'
	bool setXcvrSpeed( uint32_t xcvrSpeed );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* PG0_Mako2UsbXcvr_H */

// }}}RME
