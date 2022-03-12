// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoUSBSubsystem::USBEventHandlerBase'

#ifndef USBEventHandlerBase_H
#define USBEventHandlerBase_H

#ifdef PRAGMA
#pragma interface "USBEventHandlerBase.h"
#endif

#include <HALtestLib_win32.h>
#include <MakoPrivate.h>
class MakoUSBConstants;
class MakoUSBEvents;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>

// }}}USR
// }}}RME

class USBEventHandlerBase
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
	// {{{RME classAttribute 'm_EventHandlerArray'
	USB_EventHandlerFP_t * m_EventHandlerArray;
	// }}}RME
	// {{{RME classAttribute 'm_EventHandlerArrayLen'
	int m_EventHandlerArrayLen;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	USBEventHandlerBase( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~USBEventHandlerBase( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	USBEventHandlerBase( const USBEventHandlerBase & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	USBEventHandlerBase & operator=( const USBEventHandlerBase & rtg_arg );
	// }}}RME
	// {{{RME operation 'processEvent(int,int,uint32_t)'
	virtual int processEvent( int event_constant, int usb_transceiver_num, uint32_t register_data ) = 0;
	// }}}RME
	// {{{RME operation 'handlerUSB2IntrEventVbus_0V()'
	virtual void handlerUSB2IntrEventVbus_0V( void ) = 0;
	// }}}RME
	// {{{RME operation 'handlerUSB2IntrEventVbus_5V()'
	virtual void handlerUSB2IntrEventVbus_5V( void ) = 0;
	// }}}RME
	// {{{RME operation 'handlerUSB1IntrEventVbus_0V()'
	virtual void handlerUSB1IntrEventVbus_0V( void ) = 0;
	// }}}RME
	// {{{RME operation 'handlerUSB1IntrEventVbus_5V()'
	virtual void handlerUSB1IntrEventVbus_5V( void ) = 0;
	// }}}RME
	// {{{RME operation 'initEventHandlerArray(USB_EventHandlerFP_t *,int)'
	void initEventHandlerArray( USB_EventHandlerFP_t * event_handler_array = 0, int array_len = 0 );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* USBEventHandlerBase_H */

// }}}RME
