// {{{RME classifier 'Logical View::Usb::UsbConfigMgr::PG2_ISP1105UsbXcvr'

#ifndef PG2_ISP1105UsbXcvr_H
#define PG2_ISP1105UsbXcvr_H

#ifdef PRAGMA
#pragma interface "PG2_ISP1105UsbXcvr.h"
#endif

#include <usbimp.h>
#include <UsbTransceiver.h>
class USBPort;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class PG2_ISP1105UsbXcvr : public UsbTransceiver
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
	virtual ~PG2_ISP1105UsbXcvr( void );
	// }}}RME
	// {{{RME operation 'setXcvrState(uint32_t)'
	bool setXcvrState( uint32_t state );
	// }}}RME
	// {{{RME operation 'PG2_ISP1105UsbXcvr()'
	PG2_ISP1105UsbXcvr( void );
	// }}}RME
	// {{{RME operation 'setXcvrSpeed(uint32_t)'
	bool setXcvrSpeed( uint32_t xcvrSpeed );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* PG2_ISP1105UsbXcvr_H */

// }}}RME
