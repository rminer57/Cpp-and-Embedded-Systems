// {{{RME classifier 'Logical View::Usb::UsbHost::UsbHID::UsbBaseDevice'

#ifndef UsbBaseDevice_H
#define UsbBaseDevice_H

#ifdef PRAGMA
#pragma interface "UsbBaseDevice.h"
#endif

#include <usbimp.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class UsbBaseDevice
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
	// {{{RME classAttribute 'm_vendorID'
	uint16_t m_vendorID;
	// }}}RME
	// {{{RME classAttribute 'm_productID'
	uint16_t m_productID;
	// }}}RME
	// {{{RME classAttribute 'm_deviceClass'
	uint16_t m_deviceClass;
	// }}}RME
	// {{{RME classAttribute 'm_maxPower'
	uint16_t m_maxPower;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	UsbBaseDevice( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~UsbBaseDevice( void );
	// }}}RME
	// {{{RME operation 'UsbBaseDevice(uint16_t,uint16_t,uint16_t)'
	UsbBaseDevice( uint16_t vendorID, uint16_t productID, uint16_t deviceClass );
	// }}}RME
	// {{{RME operation 'getm_vendorID()'
	inline uint16_t getm_vendorID( void )
	{
		// {{{USR
		return m_vendorID;
		// }}}USR
	}
	// }}}RME
	// {{{RME operation 'setm_vendorID(uint16_t)'
	inline void setm_vendorID( uint16_t newVal )
	{
		// {{{USR
		this->m_vendorID=newVal;
		// }}}USR
	}
	// }}}RME
	// {{{RME operation 'getm_productID()'
	inline uint16_t getm_productID( void )
	{
		// {{{USR
		return m_productID;
		// }}}USR
	}
	// }}}RME
	// {{{RME operation 'setm_productID(uint16_t)'
	inline void setm_productID( uint16_t newVal )
	{
		// {{{USR
		this->m_productID=newVal;
		// }}}USR
	}
	// }}}RME
	// {{{RME operation 'getm_deviceClass()'
	inline uint16_t getm_deviceClass( void )
	{
		// {{{USR
		return m_deviceClass;
		// }}}USR
	}
	// }}}RME
	// {{{RME operation 'setm_deviceClass(uint16_t)'
	inline void setm_deviceClass( uint16_t newVal )
	{
		// {{{USR
		this->m_deviceClass=newVal;
		// }}}USR
	}
	// }}}RME
	// {{{RME operation 'getm_maxPower()'
	inline uint16_t getm_maxPower( void )
	{
		// {{{USR
		return m_maxPower;
		// }}}USR
	}
	// }}}RME
	// {{{RME operation 'setm_maxPower(uint16_t)'
	inline void setm_maxPower( uint16_t newVal )
	{
		// {{{USR
		this->m_maxPower=newVal;
		// }}}USR
	}
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* UsbBaseDevice_H */

// }}}RME
