// {{{RME classifier 'Logical View::Usb::UsbHost::UsbHID::UsbHidMicrophone'

#ifndef UsbHidMicrophone_H
#define UsbHidMicrophone_H

#ifdef PRAGMA
#pragma interface "UsbHidMicrophone.h"
#endif

#include <usbimp.h>
#include <UsbHidDevice.h>
class GenericHidMicrophone;
class SECT;
class UsbHidFactory;
class UserInputEvent;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class UsbHidMicrophone : public UsbHidDevice
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
	struct RTState_UsbHidMicrophone
	{
		inline RTState_UsbHidMicrophone( void )
			: state( 1U )
		{
		}
		inline ~RTState_UsbHidMicrophone( void )
		{
		}
		unsigned char state;
	};
	RTState_UsbHidMicrophone rtg_state_UsbHidMicrophone;
	// {{{RME classAttribute 'hidReportPtr'
	uint32_t * hidReportPtr;
	// }}}RME
	// {{{RME classAttribute 'm_mic_backlight_green'
	uint8_t m_mic_backlight_green;
	// }}}RME
	// {{{RME classAttribute 'm_mic_backlight_red'
	uint8_t m_mic_backlight_red;
	// }}}RME
	// {{{RME classAttribute 'm_mic_backlight_blue'
	uint8_t m_mic_backlight_blue;
	// }}}RME
	// {{{RME classAttribute 'm_mic_hotmic'
	bool m_mic_hotmic;
	// }}}RME

public:
	// {{{RME associationEnd 'm_GenericMicPtr'
	static GenericHidMicrophone * m_GenericMicPtr;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	UsbHidMicrophone( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~UsbHidMicrophone( void );
	// }}}RME
	// {{{RME operation 'UsbHidMicrophone(uint16_t,uint16_t,uint16_t,uint16_t)'
	UsbHidMicrophone( uint16_t vendorID, uint16_t productID, uint16_t deviceClass, uint16_t usagePage );
	// }}}RME
	// {{{RME operation 'sethidReportPtr(uint32_t *)'
	void sethidReportPtr( uint32_t * newVal );
	// }}}RME
	// {{{RME operation 'setBacklight(uint8_t,uint8_t,uint8_t)'
	void setBacklight( uint8_t greenLevel, uint8_t redLevel, uint8_t blueLevel );
	// }}}RME
	// {{{RME operation 'setHotMic(bool)'
	void setHotMic( bool hotMic );
	// }}}RME
	// {{{RME operation 'micKeyEvent(uint16_t,uint16_t)'
	void micKeyEvent( uint16_t keyCode, uint16_t status );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* UsbHidMicrophone_H */

// }}}RME
