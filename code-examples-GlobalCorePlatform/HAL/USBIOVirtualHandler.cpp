// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoUSBSubsystem::USBIOVirtualHandler'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "USBIOVirtualHandler.h"
#endif

#include <HALtestLib_win32.h>
#include <USBIOVirtualHandler.h>
#include <MakoUSBCtrl.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
USBIOVirtualHandler::USBIOVirtualHandler( void )
	: m_whichTransceiver( 0 )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
USBIOVirtualHandler::~USBIOVirtualHandler( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
USBIOVirtualHandler::USBIOVirtualHandler( const USBIOVirtualHandler & rtg_arg )
	: IOVirtual( rtg_arg )
	, m_whichIOVirtual( rtg_arg.m_whichIOVirtual )
	, m_whichTransceiver( rtg_arg.m_whichTransceiver )
	, m_MakoUSBCtrl_parent( rtg_arg.m_MakoUSBCtrl_parent )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
USBIOVirtualHandler & USBIOVirtualHandler::operator=( const USBIOVirtualHandler & rtg_arg )
{
	if( this != &rtg_arg )
	{
		IOVirtual::operator=( rtg_arg );
		m_whichIOVirtual = rtg_arg.m_whichIOVirtual;
		m_whichTransceiver = rtg_arg.m_whichTransceiver;
		m_MakoUSBCtrl_parent = rtg_arg.m_MakoUSBCtrl_parent;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'USBIOVirtualHandler(int,int,MakoUSBCtrl *)'
USBIOVirtualHandler::USBIOVirtualHandler( int type, int transceiver, MakoUSBCtrl * parent )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	:m_whichIOVirtual(type), m_whichTransceiver(transceiver), m_MakoUSBCtrl_parent(parent)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'receive()'
unsigned int USBIOVirtualHandler::receive( void )
{
	// {{{USR
	    unsigned int retval = 0;

	    if( m_whichIOVirtual == MakoUSBConstants::IOVIRTUAL_DEVPUEN ) 
	    {
	      if( m_MakoUSBCtrl_parent->getPullUp(m_whichTransceiver) == MakoUSBConstants::USB_PULLUP_ON )
	      {
	        retval = 1;

	      } // else retval = 0;    
	    }
	    else if( m_whichIOVirtual == MakoUSBConstants::IOVIRTUAL_PWRENABLE )
	    {
	      if( m_MakoUSBCtrl_parent->getPowerEnable(m_whichTransceiver) == MakoUSBConstants::USB_PWR_ON )
	      {
	        retval = 1;

	      } // else retval = 0;
	    }
	    else if( m_whichIOVirtual == MakoUSBConstants::IOVIRTUAL_SUSPEND )
	    {
	      if( m_MakoUSBCtrl_parent->getSuspend(m_whichTransceiver) == MakoUSBConstants::USB_SUSPEND_ON )
	      {
	        retval = 1;

	      } // else retval = 0;
	    }
	     else if( m_whichIOVirtual == MakoUSBConstants::IOVIRTUAL_VBUSDETECT )
	    {
	     if( m_MakoUSBCtrl_parent->getVbusVal(m_whichTransceiver) == MakoUSBConstants::USB_VBUS_5V )
	      {
	        retval = 1;

	      } // else retval = 0;

	    }
	  

	    return retval;    
	// }}}USR
}
// }}}RME

// {{{RME operation 'send(unsigned int)'
void USBIOVirtualHandler::send( unsigned int data )
{
	// {{{USR

	    if( m_whichIOVirtual == MakoUSBConstants::IOVIRTUAL_DEVPUEN ) 
	    {
	      if( data == 1)
	      {
	        m_MakoUSBCtrl_parent->setPullUp(MakoUSBConstants::USB_PULLUP_ON,m_whichTransceiver);
	      }
	      else
	      {
	        m_MakoUSBCtrl_parent->setPullUp(MakoUSBConstants::USB_PULLUP_OFF,m_whichTransceiver);
	      }
	      
	    }
	    else if( m_whichIOVirtual == MakoUSBConstants::IOVIRTUAL_PWRENABLE )
	    {

	      if( data == 1)
	      {
	        m_MakoUSBCtrl_parent->setPowerEnable(MakoUSBConstants::USB_PWR_ON,m_whichTransceiver);
	      }
	      else
	      {
	        m_MakoUSBCtrl_parent->setPowerEnable(MakoUSBConstants::USB_PWR_OFF,m_whichTransceiver);
	      }

	    }
	    else if( m_whichIOVirtual == MakoUSBConstants::IOVIRTUAL_SUSPEND )
	    {

	      if( data == 1)
	      {
	        m_MakoUSBCtrl_parent->setSuspend(MakoUSBConstants::USB_SUSPEND_ON,m_whichTransceiver);
	      }
	      else
	      {
	        m_MakoUSBCtrl_parent->setSuspend(MakoUSBConstants::USB_SUSPEND_OFF,m_whichTransceiver);
	      }

	    }
	    else if( m_whichIOVirtual == MakoUSBConstants::IOVIRTUAL_VBUSDETECT )
	    {
	      // this else is left here for readability.  Vbus detection is a read-only function. There is no Mako bit
	      // that provides any control over this functionality.  Thus, send is "do nothing" in this case.
	    }
	 


	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
