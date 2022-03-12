// {{{RME classifier 'Logical View::Usb::UsbConfigMgr::PortConfiguration'

#ifndef PortConfiguration_H
#define PortConfiguration_H

#ifdef PRAGMA
#pragma interface "PortConfiguration.h"
#endif

#include <usbimp.h>
class IOVirtual;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class PortConfiguration
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
	// {{{RME classAttribute 'm_usbXcvrType'
	uint32_t m_usbXcvrType;
	// }}}RME
	// {{{RME classAttribute 'm_usbDevPUEN'
	IOVirtual * m_usbDevPUEN;
	// }}}RME
	// {{{RME classAttribute 'm_usbDevVbusDetect'
	IOVirtual * m_usbDevVbusDetect;
	// }}}RME
	// {{{RME classAttribute 'm_usbHostPwrEnable'
	IOVirtual * m_usbHostPwrEnable;
	// }}}RME
	// {{{RME classAttribute 'm_usbHostOvercurrent'
	IOVirtual * m_usbHostOvercurrent;
	// }}}RME
	// {{{RME classAttribute 'm_usbSpeed'
	IOVirtual * m_usbSpeed;
	// }}}RME
	// {{{RME classAttribute 'm_usbSuspend'
	IOVirtual * m_usbSuspend;
	// }}}RME
	// {{{RME classAttribute 'm_usbMaxPortCurrent'
	uint32_t m_usbMaxPortCurrent;
	// }}}RME
	// {{{RME classAttribute 'USB_XCVR_OMAP1610'
	static const uint32_t USB_XCVR_OMAP1610;
	// }}}RME
	// {{{RME classAttribute 'USB_XCVR_MAKO_1'
	static const uint32_t USB_XCVR_MAKO_1;
	// }}}RME
	// {{{RME classAttribute 'USB_XCVR_MAKO_2'
	static const uint32_t USB_XCVR_MAKO_2;
	// }}}RME
	// {{{RME classAttribute 'USB_XCVR_ISP1105'
	static const uint32_t USB_XCVR_ISP1105;
	// }}}RME
	// {{{RME classAttribute 'USB_XCVR_HOST_TLL'
	static const uint32_t USB_XCVR_HOST_TLL;
	// }}}RME
	// {{{RME classAttribute 'USB_XCVR_DEVICE_TLL'
	static const uint32_t USB_XCVR_DEVICE_TLL;
	// }}}RME
	// {{{RME classAttribute 'm_managedVbus'
	bool m_managedVbus;
	// }}}RME
	// {{{RME classAttribute 'USB_XCVR_NULL'
	static const uint32_t USB_XCVR_NULL;
	// }}}RME
	// {{{RME classAttribute 'IO_UNUSED'
	static IOVirtual * const IO_UNUSED;
	// }}}RME
	// {{{RME classAttribute 'NO_CURRENT'
	static const uint32_t NO_CURRENT;
	// }}}RME
	// {{{RME classAttribute 'CURRENT_100mA'
	static const uint32_t CURRENT_100mA;
	// }}}RME
	// {{{RME classAttribute 'CURRENT_500mA'
	static const uint32_t CURRENT_500mA;
	// }}}RME
	// {{{RME operation 'PortConfiguration(uint32_t,IOVirtual *,IOVirtual *,IOVirtual *,IOVirtual * ,IOVirtual *,IOVirtual *,uint32_t,bool)'
	PortConfiguration( uint32_t usbXcvrType = 0, IOVirtual * usbDevVbusDetect = 0, IOVirtual * usbDevPUEN = 0, IOVirtual * usbHostPwrEnable = 0, IOVirtual * usbHostOvercurrent = 0, IOVirtual * usbSuspend = 0, IOVirtual * usbSpeed = 0, uint32_t usbMaxPortCurrent = 50, bool managedVbus = false );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* PortConfiguration_H */

// }}}RME
