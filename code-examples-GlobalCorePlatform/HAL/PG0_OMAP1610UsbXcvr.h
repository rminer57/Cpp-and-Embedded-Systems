// {{{RME classifier 'Logical View::Usb::UsbConfigMgr::PG0_OMAP1610UsbXcvr'

#ifndef PG0_OMAP1610UsbXcvr_H
#define PG0_OMAP1610UsbXcvr_H

#ifdef PRAGMA
#pragma interface "PG0_OMAP1610UsbXcvr.h"
#endif

#include <usbimp.h>
#include <UsbTransceiver.h>
class USBPort;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class PG0_OMAP1610UsbXcvr : public UsbTransceiver
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
	virtual ~PG0_OMAP1610UsbXcvr( void );
	// }}}RME
	// {{{RME operation 'setXcvrState(uint32_t)'
	bool setXcvrState( uint32_t state );
	// }}}RME
	// {{{RME operation 'PG0_OMAP1610UsbXcvr()'
	PG0_OMAP1610UsbXcvr( void );
	// }}}RME
	// {{{RME operation 'setXcvrSpeed(uint32_t)'
	bool setXcvrSpeed( uint32_t xcvrSpeed );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* PG0_OMAP1610UsbXcvr_H */

// }}}RME
