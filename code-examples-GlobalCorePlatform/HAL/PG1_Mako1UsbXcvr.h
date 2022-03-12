// {{{RME classifier 'Logical View::Usb::UsbConfigMgr::PG1_Mako1UsbXcvr'

#ifndef PG1_Mako1UsbXcvr_H
#define PG1_Mako1UsbXcvr_H

#ifdef PRAGMA
#pragma interface "PG1_Mako1UsbXcvr.h"
#endif

#include <usbimp.h>
#include <UsbTransceiver.h>
class USBPort;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class PG1_Mako1UsbXcvr : public UsbTransceiver
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
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~PG1_Mako1UsbXcvr( void );
	// }}}RME
	// {{{RME operation 'setXcvrState(uint32_t)'
	bool setXcvrState( uint32_t state );
	// }}}RME
	// {{{RME operation 'PG1_Mako1UsbXcvr()'
	PG1_Mako1UsbXcvr( void );
	// }}}RME
	// {{{RME operation 'setXcvrSpeed(uint32_t)'
	bool setXcvrSpeed( uint32_t xcvrSpeed );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* PG1_Mako1UsbXcvr_H */

// }}}RME
