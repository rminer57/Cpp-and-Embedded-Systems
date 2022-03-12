// {{{RME classifier 'Logical View::UsbPrivate::UsbOsFacade::DeviceInterruptRegistration'

#ifndef DeviceInterruptRegistration_H
#define DeviceInterruptRegistration_H

#ifdef PRAGMA
#pragma interface "DeviceInterruptRegistration.h"
#endif

#include <usbimp.h>
#include <EventBase.h>
#include <IrqHandler.h>
#include <ListenerBase.h>
#include <NotifierBase.h>
class HALiNucleusNotifier;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'UsbDeviceIsrEvent' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class DeviceInterruptRegistration : public ListenerBase, public IrqHandler, public NotifierBase
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
	// {{{RME classifier 'UsbDeviceIsrEvent'
	class UsbDeviceIsrEvent : public EventBase
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
		// {{{RME classAttribute 'USB_DEVICE_ISR_EVENT'
		static const unsigned int USB_DEVICE_ISR_EVENT;
		// }}}RME
		// {{{RME operation 'UsbDeviceIsrEvent()'
		UsbDeviceIsrEvent( void );
		// }}}RME
		// {{{RME operation 'getEvent()'
		virtual unsigned int getEvent( void ) const;
		// }}}RME
		// {{{RME operation 'isType(ClassType)'
		virtual bool isType( ClassType type ) const;
		// }}}RME
		// {{{RME operation '~UsbDeviceIsrEvent()'
		~UsbDeviceIsrEvent( void );
		// }}}RME
	};
	// }}}RME
	// {{{RME classAttribute 'm_handler'
	void ( * m_handler )( void );
	// }}}RME
	// {{{RME associationEnd 'm_usbDeviceIsrEvent'
	UsbDeviceIsrEvent m_usbDeviceIsrEvent;
	// }}}RME
	// {{{RME operation 'DeviceInterruptRegistration(unsigned int,void (*)())'
	DeviceInterruptRegistration( unsigned int irq, void ( * interruptHandler )( void ) );
	// }}}RME
	// {{{RME operation 'eventOccurred(const EventBase * const)'
	virtual void eventOccurred( const EventBase * const event );
	// }}}RME
	// {{{RME operation 'handler()'
	virtual void handler( void );
	// }}}RME
	// {{{RME operation '~DeviceInterruptRegistration()'
	~DeviceInterruptRegistration( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'UsbDeviceIsrEvent' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* DeviceInterruptRegistration_H */

// }}}RME
