// {{{RME classifier 'Logical View::Usb::UsbHost::UsbHID::GenericHidMicrophone'

#ifndef GenericHidMicrophone_H
#define GenericHidMicrophone_H

#ifdef PRAGMA
#pragma interface "GenericHidMicrophone.h"
#endif

#include <usbimp.h>
#include <UserInput.h>
#include <UserOutput.h>
class SECT;
class UsbHidDevice;
class UsbHidMicrophone;
class UserInputEvent;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#define MIC_MAX_DEVICES  4
// }}}USR
// }}}RME

class GenericHidMicrophone : public UserOutput, public UserInput
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
	// {{{RME classAttribute 'm_mic_backlight_blue'
	static uint8_t m_mic_backlight_blue;
	// }}}RME
	// {{{RME classAttribute 'm_mic_backlight_green'
	static uint8_t m_mic_backlight_green;
	// }}}RME
	// {{{RME classAttribute 'm_mic_backlight_red'
	static uint8_t m_mic_backlight_red;
	// }}}RME
	// {{{RME classAttribute 'm_mic_hotmic'
	static bool m_mic_hotmic;
	// }}}RME
	// {{{RME classAttribute 'm_usbMicObjectArray'
	static UsbHidMicrophone * m_usbMicObjectArray[ 4 ];
	// }}}RME
	// {{{RME classAttribute 'm_currentUsbMicCount'
	static uint32_t m_currentUsbMicCount;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~GenericHidMicrophone( void );
	// }}}RME
	// {{{RME operation 'setBacklight(uint8_t,uint8_t,uint8_t)'
	void setBacklight( uint8_t greenLevel, uint8_t redLevel, uint8_t blueLevel );
	// }}}RME
	// {{{RME operation 'eventOccurred(const EventBase * const)'
	virtual void eventOccurred( const EventBase * const event );
	// }}}RME
	// {{{RME operation 'processKeyEvent(uint16_t,uint16_t)'
	void processKeyEvent( uint16_t keyCode, uint16_t status );
	// }}}RME
	// {{{RME operation 'GenericHidMicrophone()'
	GenericHidMicrophone( void );
	// }}}RME
	// {{{RME operation 'inform(const EventBase * const)'
	void inform( const EventBase * const event );
	// }}}RME
	// {{{RME operation 'setm_mic_hotmic(bool)'
	void setm_mic_hotmic( bool newVal = true );
	// }}}RME
	// {{{RME operation 'setNewMicBacklight(UsbHidMicrophone *)'
	void setNewMicBacklight( UsbHidMicrophone * micPtr );
	// }}}RME
	// {{{RME operation 'deleteUsbMic(UsbHidMicrophone *)'
	bool deleteUsbMic( UsbHidMicrophone * micPtr );
	// }}}RME
	// {{{RME operation 'newUsbMic(UsbHidMicrophone *)'
	bool newUsbMic( UsbHidMicrophone * micPtr );
	// }}}RME
	// {{{RME operation 'isNewMicAllowed()'
	bool isNewMicAllowed( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* GenericHidMicrophone_H */

// }}}RME
