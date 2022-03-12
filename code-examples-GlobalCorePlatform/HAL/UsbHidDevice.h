// {{{RME classifier 'Logical View::Usb::UsbHost::UsbHID::UsbHidDevice'

#ifndef UsbHidDevice_H
#define UsbHidDevice_H

#ifdef PRAGMA
#pragma interface "UsbHidDevice.h"
#endif

#include <usbimp.h>
#include <UsbBaseDevice.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class UsbHidDevice : public UsbBaseDevice
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

protected:
	// {{{RME classAttribute 'm_usagePage'
	uint16_t m_usagePage;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	UsbHidDevice( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~UsbHidDevice( void );
	// }}}RME
	// {{{RME operation 'sethidReportPtr(uint32_t *)'
	inline virtual void sethidReportPtr( uint32_t * newVal ) = 0;
	// }}}RME
	// {{{RME operation 'getm_usagePage()'
	inline uint16_t getm_usagePage( void )
	{
		// {{{USR
		return m_usagePage;
		// }}}USR
	}
	// }}}RME
	// {{{RME operation 'setm_usagePage(uint16_t)'
	inline void setm_usagePage( uint16_t newVal )
	{
		// {{{USR
		this->m_usagePage=newVal;
		// }}}USR
	}
	// }}}RME
	// {{{RME operation 'UsbHidDevice(uint16_t,uint16_t,uint16_t,uint16_t)'
	UsbHidDevice( uint16_t vendorID, uint16_t productID, uint16_t deviceClass, uint16_t usagePage );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* UsbHidDevice_H */

// }}}RME
