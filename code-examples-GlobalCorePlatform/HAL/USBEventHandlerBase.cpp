// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoUSBSubsystem::USBEventHandlerBase'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "USBEventHandlerBase.h"
#endif

#include <HALtestLib_win32.h>
#include <USBEventHandlerBase.h>
#include <MakoUSBConstants.h>
#include <MakoUSBEvents.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
USBEventHandlerBase::USBEventHandlerBase( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
USBEventHandlerBase::~USBEventHandlerBase( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
USBEventHandlerBase::USBEventHandlerBase( const USBEventHandlerBase & rtg_arg )
	: m_EventHandlerArray( rtg_arg.m_EventHandlerArray )
	, m_EventHandlerArrayLen( rtg_arg.m_EventHandlerArrayLen )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
USBEventHandlerBase & USBEventHandlerBase::operator=( const USBEventHandlerBase & rtg_arg )
{
	if( this != &rtg_arg )
	{
		m_EventHandlerArray = rtg_arg.m_EventHandlerArray;
		m_EventHandlerArrayLen = rtg_arg.m_EventHandlerArrayLen;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'initEventHandlerArray(USB_EventHandlerFP_t *,int)'
void USBEventHandlerBase::initEventHandlerArray( USB_EventHandlerFP_t * event_handler_array, int array_len )
{
	// {{{USR
	m_EventHandlerArray = event_handler_array;

	m_EventHandlerArrayLen = array_len;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
