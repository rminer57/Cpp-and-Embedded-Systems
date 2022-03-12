// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoUSBSubsystem::MakoUSBCtrl'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "MakoUSBCtrl.h"
#endif

#include <HALtestLib_win32.h>
#include <MakoUSBCtrl.h>
#include <Mako.h>
#include <MakoPrivateBitfieldsReg4.h>
#include <MakoUSBEvents.h>
#include <USBEventHandlerBase.h>
#include <USBIOVirtualHandler.h>
#include <bitfield.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
MakoUSBCtrl::MakoUSBCtrl( const MakoUSBCtrl & rtg_arg )
	: ListenerBase( rtg_arg )
	, m_MakoParent( rtg_arg.m_MakoParent )
	, m_USB1mode( rtg_arg.m_USB1mode )
	, m_IOVirtualGPIO( rtg_arg.m_IOVirtualGPIO )
	, m_userdefinedUSBEventHandlerClass( rtg_arg.m_userdefinedUSBEventHandlerClass )
	, m_USB2mode( rtg_arg.m_USB2mode )
	, m_RegImageUSB1_CTRL_STAT( rtg_arg.m_RegImageUSB1_CTRL_STAT )
	, m_RegImageUSB2_CTRL_STAT( rtg_arg.m_RegImageUSB2_CTRL_STAT )
	, m_RegImageUSB1_INTR_EN( rtg_arg.m_RegImageUSB1_INTR_EN )
	, m_RegImageUSB2_INTR_EN( rtg_arg.m_RegImageUSB2_INTR_EN )
	, m_RegImageUSB_INTR_FLAGS( rtg_arg.m_RegImageUSB_INTR_FLAGS )
	, m_IOVirtualSuspend1( rtg_arg.m_IOVirtualSuspend1 )
	, m_IOVirtualPwrEnable1( rtg_arg.m_IOVirtualPwrEnable1 )
	, m_IOVirtualVbusDetect1( rtg_arg.m_IOVirtualVbusDetect1 )
	, m_IOVirtualDevPUEN1( rtg_arg.m_IOVirtualDevPUEN1 )
	, m_IOVirtualDevPUEN2( rtg_arg.m_IOVirtualDevPUEN2 )
	, m_IOVirtualPwrEnable2( rtg_arg.m_IOVirtualPwrEnable2 )
	, m_IOVirtualSuspend2( rtg_arg.m_IOVirtualSuspend2 )
	, m_IOVirtualVbusDetect2( rtg_arg.m_IOVirtualVbusDetect2 )
	, m_FETmanager( rtg_arg.m_FETmanager )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
MakoUSBCtrl & MakoUSBCtrl::operator=( const MakoUSBCtrl & rtg_arg )
{
	if( this != &rtg_arg )
	{
		ListenerBase::operator=( rtg_arg );
		m_MakoParent = rtg_arg.m_MakoParent;
		m_USB1mode = rtg_arg.m_USB1mode;
		m_IOVirtualGPIO = rtg_arg.m_IOVirtualGPIO;
		m_userdefinedUSBEventHandlerClass = rtg_arg.m_userdefinedUSBEventHandlerClass;
		m_USB2mode = rtg_arg.m_USB2mode;
		m_RegImageUSB1_CTRL_STAT = rtg_arg.m_RegImageUSB1_CTRL_STAT;
		m_RegImageUSB2_CTRL_STAT = rtg_arg.m_RegImageUSB2_CTRL_STAT;
		m_RegImageUSB1_INTR_EN = rtg_arg.m_RegImageUSB1_INTR_EN;
		m_RegImageUSB2_INTR_EN = rtg_arg.m_RegImageUSB2_INTR_EN;
		m_RegImageUSB_INTR_FLAGS = rtg_arg.m_RegImageUSB_INTR_FLAGS;
		m_IOVirtualSuspend1 = rtg_arg.m_IOVirtualSuspend1;
		m_IOVirtualPwrEnable1 = rtg_arg.m_IOVirtualPwrEnable1;
		m_IOVirtualVbusDetect1 = rtg_arg.m_IOVirtualVbusDetect1;
		m_IOVirtualDevPUEN1 = rtg_arg.m_IOVirtualDevPUEN1;
		m_IOVirtualDevPUEN2 = rtg_arg.m_IOVirtualDevPUEN2;
		m_IOVirtualPwrEnable2 = rtg_arg.m_IOVirtualPwrEnable2;
		m_IOVirtualSuspend2 = rtg_arg.m_IOVirtualSuspend2;
		m_IOVirtualVbusDetect2 = rtg_arg.m_IOVirtualVbusDetect2;
		m_FETmanager = rtg_arg.m_FETmanager;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'MakoUSBCtrl(Mako *,uint32_t,uint32_t)'
MakoUSBCtrl::MakoUSBCtrl( Mako * parent, uint32_t usb1_int_en_init, uint32_t usb2_int_en_init )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_MakoParent( parent ), m_USB1mode(MakoUSBConstants::USB_MODE_DEVICE), m_USB2mode(MakoUSBConstants::USB_MODE_DEVICE), m_RegImageUSB1_CTRL_STAT(MAKOUSB_CTRL_STAT_DEFAULT), m_RegImageUSB2_CTRL_STAT(MAKOUSB_CTRL_STAT_DEFAULT), m_RegImageUSB_INTR_FLAGS(0)
	// }}}USR
	// }}}RME
{
	// {{{USR
	   uint32_t regimage = 0;
	 
	   uint32_t reginitValue = 0;

	   // initialize to device,
	   m_USB1mode = MakoUSBConstants::USB_MODE_DEVICE;
	   m_USB2mode = MakoUSBConstants::USB_MODE_DEVICE;

	   // read powerup default register state of control/status register
	   regimage = rdRegisterUSB(MakoUSBConstants::USB1_TRANSCEIVER , MakoUSBConstants::MAKO_REG_CTRL_STAT);

	   // update the transceiver 1 register image to reflect the new setting
	   wrRegisterImage( MakoUSBConstants::USB1_TRANSCEIVER, MakoUSBConstants::MAKO_REG_CTRL_STAT, regimage );

	   
	   // update the transceiver 1 interrupt register image to reflect the new setting
	   wrRegisterImage( MakoUSBConstants::USB1_TRANSCEIVER, MakoUSBConstants::MAKO_REG_INTR_EN, usb1_int_en_init );

	   // write the interrupt register image to the IC
	   wrRegisterUSB( MakoUSBConstants::USB1_TRANSCEIVER, MakoUSBConstants::MAKO_REG_INTR_EN ); 


	   // read powerup default register state of control/status register
	   regimage = rdRegisterUSB(MakoUSBConstants::USB2_TRANSCEIVER , MakoUSBConstants::MAKO_REG_CTRL_STAT);

	   // update the transceiver 2 register image to reflect the new setting
	   wrRegisterImage( MakoUSBConstants::USB2_TRANSCEIVER, MakoUSBConstants::MAKO_REG_CTRL_STAT, regimage );   

	   // update the transceiver 2 interrupt register image to reflect the new setting
	   wrRegisterImage( MakoUSBConstants::USB2_TRANSCEIVER, MakoUSBConstants::MAKO_REG_INTR_EN, usb2_int_en_init );

	   // write the interrupt register image to the IC
	   wrRegisterUSB( MakoUSBConstants::USB2_TRANSCEIVER, MakoUSBConstants::MAKO_REG_INTR_EN ); 

	   // create the iovirtuals for USB config manager to use
	   m_IOVirtualDevPUEN1 = new USBIOVirtualHandler(MakoUSBConstants::IOVIRTUAL_DEVPUEN, MakoUSBConstants::USB1_TRANSCEIVER, this);
	   m_IOVirtualDevPUEN2 = new USBIOVirtualHandler(MakoUSBConstants::IOVIRTUAL_DEVPUEN, MakoUSBConstants::USB2_TRANSCEIVER, this);

	   m_IOVirtualPwrEnable1 = new USBIOVirtualHandler(MakoUSBConstants::IOVIRTUAL_PWRENABLE, MakoUSBConstants::USB1_TRANSCEIVER, this);
	   m_IOVirtualPwrEnable2 = new USBIOVirtualHandler(MakoUSBConstants::IOVIRTUAL_PWRENABLE, MakoUSBConstants::USB2_TRANSCEIVER, this);

	   m_IOVirtualSuspend1 = new USBIOVirtualHandler(MakoUSBConstants::IOVIRTUAL_SUSPEND, MakoUSBConstants::USB1_TRANSCEIVER, this);
	   m_IOVirtualSuspend2 = new USBIOVirtualHandler(MakoUSBConstants::IOVIRTUAL_SUSPEND, MakoUSBConstants::USB2_TRANSCEIVER, this);

	   m_IOVirtualVbusDetect1 = new USBIOVirtualHandler(MakoUSBConstants::IOVIRTUAL_VBUSDETECT, MakoUSBConstants::USB1_TRANSCEIVER, this);
	   m_IOVirtualVbusDetect2 = new USBIOVirtualHandler(MakoUSBConstants::IOVIRTUAL_VBUSDETECT, MakoUSBConstants::USB2_TRANSCEIVER, this);


	   // instantiate the FET Manager
	   m_FETmanager = new MakoFETManager(this);
	   

	// }}}USR
}
// }}}RME

// {{{RME operation '~MakoUSBCtrl()'
MakoUSBCtrl::~MakoUSBCtrl( void )
{
	// {{{USR

	  // Mark the Mako USB resource flag as available
	  m_MakoParent->m_ResourceAvailableUsb = true;

	  // restore all Mako register bits to their power up state.
	  // these states turn everything off
	  pgmPwrUpDefault(MakoUSBConstants::USB1_TRANSCEIVER);
	  pgmPwrUpDefault(MakoUSBConstants::USB2_TRANSCEIVER);

	  delete m_FETmanager;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getMode(int)'
int MakoUSBCtrl::getMode( int transceiver )
{
	// {{{USR

	bool retval = m_USB2mode; 
	  
	if ( transceiver == MakoUSBConstants::USB1_TRANSCEIVER )
	{
	  retval = m_USB1mode;
	}

	return retval;
	// }}}USR
}
// }}}RME

// {{{RME operation 'registerEventHandler(USBEventHandlerBase *,IOVirtual *,unsigned int)'
void MakoUSBCtrl::registerEventHandler( USBEventHandlerBase * event_handler_object, IOVirtual * gpio_device, unsigned int event_change_type )
{
	// {{{USR

	// only register if arguments are all valid
	if( (gpio_device != 0) && (event_handler_object != 0) )
	{
	  m_IOVirtualGPIO = gpio_device;

	  m_userdefinedUSBEventHandlerClass = event_handler_object;

	  // class MakoUSBCtrl is a ListenerBase
	  m_IOVirtualGPIO->registerListener( this, event_change_type );

	}


	// }}}USR
}
// }}}RME

// {{{RME operation 'getCurrentLimit(int)'
int MakoUSBCtrl::getCurrentLimit( int transceiver )
{
	// {{{USR
	   // read bit USBn_CTRL[18] - MAKO_USB_VBUS_ILIMIT_BITFIELD
	   // by setting bitfield MAKO_USB_REG_ADDR_BITFIELD (D27-D24)
	   // to value of MAKO_USB1_CTRL_STAT_REG_ADDR or MAKO_USB2_CTRL_STAT_REG_ADDR
	         
	   unsigned int retval = MakoUSBConstants::USB_CURRENT_LIM_50mA;
	   
	   // read the appropriate register from the Mako IC (via spi bus), obtain its
	   // value, update the MakoUSBCtrl private register image and return its value
	   retval = rdRegisterUSB( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT );
	    
	   // extract desired bit
	   if( getBitField( &retval, MAKO_USB_VBUS_ILIMIT_BITFIELD) == 1 )
	   {
	      retval = MakoUSBConstants::USB_CURRENT_LIM_500mA;
	   }

	   return retval;    
	// }}}USR
}
// }}}RME

// {{{RME operation 'getPullUp(int)'
int MakoUSBCtrl::getPullUp( int transceiver )
{
	// {{{USR
	   // read bit USBn_CTRL_STAT[14] Pullup - MAKO_USB_PULLUP_BITFIELD
	   // by setting bitfield MAKO_USB_REG_ADDR_BITFIELD (D27-D24)
	   // to value of MAKO_USB1_CTRL_STAT_REG_ADDR or MAKO_USB2_CTRL_STAT_REG_ADDR
	                  
	   unsigned int retval = MakoUSBConstants::USB_PULLUP_OFF;
	   
	   // read the appropriate register from the Mako IC (via spi bus), obtain its
	   // value, update the MakoUSBCtrl private register image and return its value
	   retval = rdRegisterUSB( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT ); 
	 
	   // extract desired bit and check state
	   if( getBitField( &retval, MAKO_USB_PULLUP_BITFIELD) == 1 )
	   {
	      retval = MakoUSBConstants::USB_PULLUP_ON;
	   }
	  

	   return retval;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getPullDn(int)'
int MakoUSBCtrl::getPullDn( int transceiver )
{
	// {{{USR
	   // read bit USBn_CTRL_STAT[12] Dp_Pulldown - MAKO_USB_DPPULLDN_BITFIELD
	   // by setting bitfield MAKO_USB_REG_ADDR_BITFIELD (D27-D24)
	   // to value of MAKO_USB1_CTRL_STAT_REG_ADDR or MAKO_USB2_CTRL_STAT_REG_ADDR
	                   
	   unsigned int retval = MakoUSBConstants::USB_PULLUP_OFF;
	   
	   // read the appropriate register from the Mako IC (via spi bus), obtain its
	   // value, update the MakoUSBCtrl private register image and return its value
	   retval = rdRegisterUSB( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT ); 
	 
	 
	   // extract desired bit and check state
	   if( getBitField( &retval, MAKO_USB_DPPULLDN_BITFIELD) == 1 )
	   {
	      retval = MakoUSBConstants::USB_PULLUP_ON;
	   }
	  
	   return retval;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getPowerEnable(int)'
int MakoUSBCtrl::getPowerEnable( int transceiver )
{
	// {{{USR
	   // read bit USBn_CTRL_STAT[21] V_bus_Sw_On - MAKO_USB_VBUS_SW_ON_BITFIELD
	   // by setting bitfield MAKO_USB_REG_ADDR_BITFIELD (D27-D24)
	   // to value of MAKO_USB1_CTRL_STAT_REG_ADDR or MAKO_USB2_CTRL_STAT_REG_ADDR
	         
	   unsigned int retval = MakoUSBConstants::USB_PWR_OFF;
	   
	   // read the appropriate register from the Mako IC (via spi bus), obtain its
	   // value, update the MakoUSBCtrl private register image and return its value
	   retval = rdRegisterUSB( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT ); 
	 
	   // extract desired bit
	   if( getBitField( &retval, MAKO_USB_VBUS_SW_ON_BITFIELD) == 1 )
	  {
	      retval = MakoUSBConstants::USB_PWR_ON;
	   }
	  
	   return retval;  
	// }}}USR
}
// }}}RME

// {{{RME operation 'getSpeed(int)'
int MakoUSBCtrl::getSpeed( int transceiver )
{
	// {{{USR
	   // read bit USBn_CTRL_STAT[13] Speed - MAKO_USB_SPEED_BITFIELD
	   // by setting bitfield MAKO_USB_REG_ADDR_BITFIELD (D27-D24)
	   // to value of MAKO_USB1_CTRL_STAT_REG_ADDR or MAKO_USB2_CTRL_STAT_REG_ADDR
	          
	   unsigned int retval = MakoUSBConstants::USB_SPEED_LOW;
	   
	   // read the appropriate register from the Mako IC (via spi bus), obtain its
	   // value, update the MakoUSBCtrl private register image and return its value
	   retval = rdRegisterUSB( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT ); 
	 
	   // extract desired bit and check state
	   if( getBitField( &retval, MAKO_USB_SPEED_BITFIELD) == 1 )
	   {
	      retval = MakoUSBConstants::USB_SPEED_FULL;
	   }
	  

	   return retval;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getSuspend(int)'
int MakoUSBCtrl::getSuspend( int transceiver )
{
	// {{{USR
	   // read bit USBn_CTRL_STAT[10] Suspend - MAKO_USB_SUSPEND_BITFIELD
	   // by setting bitfield MAKO_USB_REG_ADDR_BITFIELD (D27-D24)
	   // to value of MAKO_USB1_CTRL_STAT_REG_ADDR or MAKO_USB2_CTRL_STAT_REG_ADDR
	          
	   unsigned int retval = MakoUSBConstants::USB_SUSPEND_OFF;
	   
	   // read the appropriate register from the Mako IC (via spi bus), obtain its
	   // value, update the MakoUSBCtrl private register image and return its value
	   retval = rdRegisterUSB( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT ); 
	 
	   // extract desired bit and check state
	   if( getBitField( &retval, MAKO_USB_SUSPEND_BITFIELD) == 1 )
	   {
	      retval = MakoUSBConstants::USB_SUSPEND_ON;
	   }

	   return retval;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getVbusDischarge(int)'
int MakoUSBCtrl::getVbusDischarge( int transceiver )
{
	// {{{USR
	   // read bit USBn_CTRL_STAT[17] Vbus_Disch - MAKO_USB_VBUS_DISCH_BITFIELD
	   // by setting bitfield MAKO_USB_REG_ADDR_BITFIELD (D27-D24)
	   // to value of MAKO_USB1_CTRL_STAT_REG_ADDR or MAKO_USB2_CTRL_STAT_REG_ADDR
	          
	   unsigned int retval = MakoUSBConstants::USB_VBUS_DISCH_OFF;
	   
	   // read the appropriate register from the Mako IC (via spi bus), obtain its
	   // value, update the MakoUSBCtrl private register image and return its value
	   retval = rdRegisterUSB( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT ); 
	 
	   // extract desired bit and check state
	   if( getBitField( &retval, MAKO_USB_VBUS_DISCH_BITFIELD) == 1 )
	   {
	      retval = MakoUSBConstants::USB_VBUS_DISCH_ON;
	   }
	  

	   return retval;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getVbusIMon(int)'
int MakoUSBCtrl::getVbusIMon( int transceiver )
{
	// {{{USR
	   // read bit USBn_CTRL_STAT[19] Vbus_Mon_On - MAKO_USB_VBUS_MON_ON_BITFIELD
	   // by setting bitfield MAKO_USB_REG_ADDR_BITFIELD (D27-D24)
	   // to value of MAKO_USB1_CTRL_STAT_REG_ADDR or MAKO_USB2_CTRL_STAT_REG_ADDR
	          
	   unsigned int retval = MakoUSBConstants::USB_VBUS_MON_OFF;
	   
	   // read the appropriate register from the Mako IC (via spi bus), obtain its
	   // value, update the MakoUSBCtrl private register image and return its value
	   retval = rdRegisterUSB( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT ); 
	 
	   // extract desired bit and check state
	   if( getBitField( &retval, MAKO_USB_VBUS_MON_ON_BITFIELD) == 1 )
	   {
	      retval = MakoUSBConstants::USB_VBUS_MON_ON;
	   }
	  

	   return retval;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getVbusVal(int)'
int MakoUSBCtrl::getVbusVal( int transceiver )
{
	// {{{USR
	   // read bits USBn_CTRL_STAT[4] Vbus_Val   MAKO_USB_VBUS_VAL_BITFIELD 
	   //      and  USBn_CTRL_STAT[0] Sess_End - MAKO_USB_SESS_END_BITFIELD
	   // by setting bitfield MAKO_USB_REG_ADDR_BITFIELD (D27-D24)
	   // to value of MAKO_USB1_CTRL_STAT_REG_ADDR or MAKO_USB2_CTRL_STAT_REG_ADDR
	 
	   // initialize to indeterminate, if in host mode
	   unsigned int retval = MakoUSBConstants::VBUS_ERROR;

	   int mode = MakoUSBConstants::USB_MODE_HOST;

	   int Vbus_val = 0;
	   int Sess_End = 0;
	    
	   if ( transceiver == MakoUSBConstants::USB1_TRANSCEIVER )
	   { 
	     mode = m_USB1mode; // find out if this transceiver is in host or device mode   
	   }
	   else
	   {
	     mode = m_USB2mode; // find out if this transceiver is in host or device mode     
	   }

	   if( mode == MakoUSBConstants::USB_MODE_DEVICE ) // Vbus reading is only valid when in device mode
	   {
	      // handle the Vbus fiasco hack
	      switch ( m_MakoParent->getICVersion() )
	      {
	        case 2: // Mako P2 reads an externally supplied GPIO pin

	          if(transceiver == MakoUSBConstants::USB1_TRANSCEIVER)
	          {
	             retval = m_IOVirtualVbusDetect1->receive();
	          }
	          else
	          {
	             retval = m_IOVirtualVbusDetect2->receive();
	          }

	          // add one to conform to the switch statement/truth table down below
	          // a zero is represented by a one and a one is represented by a 2
	          retval += 1; 

	        break;

	        case 3:  // Mako P3 reads the session valid bit, not Vbus monitor


	        break;

	        default:

	   
	          // read the appropriate register from the Mako IC (via spi bus), obtain its
	          // value, update the MakoUSBCtrl private register image and return its value
	          retval = rdRegisterUSB( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT );
	 
	          Vbus_val = getBitField( &retval, MAKO_USB_VBUS_VAL_BITFIELD);

	          Sess_End = getBitField( &retval, MAKO_USB_SESS_END_BITFIELD);

	          // combine the bits to use them in switch statement
	          retval = (Vbus_val << 1) | Sess_End;

	       break;


	      }

		      //   ******  Mako Bits *****      |
		      // VbusVal_bit   SessEnd_bit |  Vbus Voltage   return constant
		      // ==============================================
		      // 0                    0                  | 0.8 < V < 4V  |  VBUS_INDETERMINATE
		      // 0                    1                  | Vbus< 0.8V    |  VBUS_0V
		      // 1                    0                  | Vbus > 4.4V   |  VBUS_5V
		      // 1                    1                  | can't occur   |  VBUS_ERROR
	          switch (retval)
	          {
	            case 0:
	                retval = MakoUSBConstants::VBUS_INDETERMINATE;
	            break;
	 
	            case 1:
	                retval = MakoUSBConstants::USB_VBUS_0V;
	            break;

	            case 2:
	                retval = MakoUSBConstants::USB_VBUS_5V;
	            break;
	   
	            default:
	                retval = MakoUSBConstants::VBUS_ERROR;
	            break;
	          }

	   
	   } // end if( mode == USB_MODE_DEVICE )

	   return retval;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getIntrFlagVbusVal(int)'
int MakoUSBCtrl::getIntrFlagVbusVal( int transceiver )
{
	// {{{USR
	   // read bit USB_INT_FLAGS[4] USB2_Vbus_Val or  USB_INT_FLAGS[12] USB1_Vbus_Val
	   // MAKO_USB2_VBUS_VALID_LE_BITFIELD  or MAKO_USB1_VBUS_VALID_LE_BITFIELD
	   // by setting bitfield MAKO_USB_REG_ADDR_BITFIELD (D27-D24)
	   // to value of MAKO_USB_INT_FLAGS_REG_ADDR
	         
	   unsigned int retval = 0;
	   
	   // read the appropriate register from the Mako IC (via spi bus), obtain its
	   // value, update the MakoUSBCtrl private register image and return its value
	   retval = rdRegisterUSB( transceiver, MakoUSBConstants::MAKO_REG_FLAGS ); 

	   if ( transceiver == MakoUSBConstants::USB1_TRANSCEIVER )
	   {
	      retval = getBitField( &retval, MAKO_USB1_VBUS_VALID_LE_BITFIELD );
	   }
	   else
	   {
	      retval = getBitField( &retval, MAKO_USB2_VBUS_VALID_LE_BITFIELD );         
	   }


	   return retval;    
	// }}}USR
}
// }}}RME

// {{{RME operation 'getIntrFlagBSessEnd(int)'
int MakoUSBCtrl::getIntrFlagBSessEnd( int transceiver )
{
	// {{{USR
	   // read bit USB_INT_FLAGS[0] USB2_B_Sess_End or  USB_INT_FLAGS[8] USB1_B_Sess_End
	   // MAKO_USB2_BSESS_END_LE_BITFIELD  or MAKO_USB1_BSESS_END_LE_BITFIELD
	   // by setting bitfield MAKO_USB_REG_ADDR_BITFIELD (D27-D24)
	   // to value of MAKO_USB_INT_FLAGS_REG_ADDR
	         
	   unsigned int retval = 0;
	   
	   // read the appropriate register from the Mako IC (via spi bus), obtain its
	   // value, update the MakoUSBCtrl private register image and return its value
	   retval = rdRegisterUSB( transceiver, MakoUSBConstants::MAKO_REG_FLAGS ); 
	   
	   if ( transceiver == MakoUSBConstants::USB1_TRANSCEIVER )
	   {
	      retval = getBitField( &retval, MAKO_USB1_BSESS_END_LE_BITFIELD );
	   }
	   else
	   {
	      retval = getBitField( &retval, MAKO_USB2_BSESS_END_LE_BITFIELD );         
	   }


	   return retval;    
	// }}}USR
}
// }}}RME

// {{{RME operation 'selectPhyIF(bool,int)'
void MakoUSBCtrl::selectPhyIF( bool state, int transceiver )
{
	// {{{USR
	   uint32_t wrData = 0;

	   // get current register image contents
	   wrData = rdRegisterImage( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT );

	 
	   // set the bit to the state argument
	     setBitField( &wrData, MAKO_USB_RS232_BITFIELD, state);  


	   // update the register image to reflect the new setting
	   wrRegisterImage( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT, wrData );

	   // write the image to the IC
	   wrRegisterUSB( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT ); 
	// }}}USR
}
// }}}RME

// {{{RME operation 'setIntrEnVbus(int,int)'
void MakoUSBCtrl::setIntrEnVbus( int state, int transceiver )
{
	// {{{USR

	   uint32_t wrData = 0;

	   // get current register image contents
	   wrData = rdRegisterImage( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT );
	  

	   if ( state == MakoUSBConstants::USB_VBUS_INTR_EN)
	   {

	     // set the bit to the state argument
	     setBitField( &wrData, MAKO_USB_VBUS_VALID_INTR_BITFIELD, 1);
	   }
	   else // USB_VBUS_INTR_DIS
	   {
	     // set the bit to the state argument
	     setBitField( &wrData, MAKO_USB_VBUS_VALID_INTR_BITFIELD, 0);     
	   }  


	   // update the register image to reflect the new setting
	   wrRegisterImage( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT, wrData );

	   // write the image to the IC
	   wrRegisterUSB( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT ); 

	// }}}USR
}
// }}}RME

// {{{RME operation 'clrIntrFlagsVbus(int)'
void MakoUSBCtrl::clrIntrFlagsVbus( int transceiver )
{
	// {{{USR

	   uint32_t wrData = 0;

	   // get current register image contents
	   wrData = rdRegisterImage( transceiver, MakoUSBConstants::MAKO_REG_FLAGS );


	   if ( transceiver == MakoUSBConstants::USB1_TRANSCEIVER )
	   { 
	 
	     // clear the hardware bit output by writing 1 to it - according to data sheet.
	     setBitField( &wrData, MAKO_USB1_VBUS_VALID_LE_BITFIELD, 1);
	 
	     // clear the hardware bit output by writing 1 to it - according to data sheet.
	     setBitField( &wrData, MAKO_USB1_BSESS_END_LE_BITFIELD, 1);     

	   }
	   else
	   {
	 
	     // clear the hardware bit output by writing 1 to it - according to data sheet.
	     setBitField( &wrData, MAKO_USB2_VBUS_VALID_LE_BITFIELD, 1);
	 
	     // clear the hardware bit output by writing 1 to it - according to data sheet.
	     setBitField( &wrData, MAKO_USB2_BSESS_END_LE_BITFIELD, 1);     

	   }

	   // update the register image to reflect the new setting
	   wrRegisterImage( transceiver, MakoUSBConstants::MAKO_REG_FLAGS, wrData );

	   // write the image to the IC
	   wrRegisterUSB( transceiver, MakoUSBConstants::MAKO_REG_FLAGS );


	// }}}USR
}
// }}}RME

// {{{RME operation 'setMode(int,int)'
void MakoUSBCtrl::setMode( int newhost_device_mode, int transceiver )
{
	// {{{USR

	  
	 
	  if ( transceiver == MakoUSBConstants::USB1_TRANSCEIVER )
	  {
	    // changing state of transceiver 1
	    // transceiver state arguments: old 1, new 1, old 2, new 2
	    m_FETmanager->transceiverModeChange( m_USB1mode, newhost_device_mode, m_USB2mode, m_USB2mode);

	    m_USB1mode = newhost_device_mode;
	  }
	  else
	  {
	    // changing state of transceiver 2
	    // transceiver state arguments: old 1, new 1, old 2, new 2
	    m_FETmanager->transceiverModeChange( m_USB1mode, m_USB1mode, m_USB2mode, newhost_device_mode);
	    m_USB2mode = newhost_device_mode;
	  }


	  

	// }}}USR
}
// }}}RME

// {{{RME operation 'setVbusLDO(int,int)'
void MakoUSBCtrl::setVbusLDO( int state, int transceiver )
{
	// {{{USR
	 
	   uint32_t wrData = 0;

	   // get current register image contents
	   wrData = rdRegisterImage( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT );

	   if ( state == MakoUSBConstants::USB_LDO_ON)
	   {

	     // set the bit to the state argument
	     setBitField( &wrData, MAKO_USB_VBUS_LDO_ON_BITFIELD, 1);
	   }
	   else // USB_LDO_OFF
	   {
	     // set the bit to the state argument
	     setBitField( &wrData, MAKO_USB_VBUS_LDO_ON_BITFIELD, 0);     
	   }  


	   // update the register image to reflect the new setting
	   wrRegisterImage( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT, wrData );

	   // write the image to the IC
	   wrRegisterUSB( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT ); 

	  
	  
	// }}}USR
}
// }}}RME

// {{{RME operation 'setPullDn(int,int)'
void MakoUSBCtrl::setPullDn( int state, int transceiver )
{
	// {{{USR

	   uint32_t wrData = 0;

	   // get current register image contents
	   wrData = rdRegisterImage( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT );
	  
	   if ( state == MakoUSBConstants::USB_PULLDN_ON)
	   {

	     // set the bit to the state argument
	     setBitField( &wrData, MAKO_USB_DMPULLDN_BITFIELD, 1);

	     // set the bit to the state argument
	     setBitField( &wrData, MAKO_USB_DPPULLDN_BITFIELD, 1);
	   }
	   else // USB_PULLUP_OFF
	   {
	     // set the bit to the state argument
	     setBitField( &wrData, MAKO_USB_DMPULLDN_BITFIELD, 0);

	     // set the bit to the state argument
	     setBitField( &wrData, MAKO_USB_DPPULLDN_BITFIELD, 0);     
	   
	   }    


	   // update the register image to reflect the new setting
	   wrRegisterImage( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT, wrData );

	   // write the image to the IC
	   wrRegisterUSB( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT );
	  
	// }}}USR
}
// }}}RME

// {{{RME operation 'setPullUp(int,int)'
void MakoUSBCtrl::setPullUp( int state, int transceiver )
{
	// {{{USR

	   uint32_t wrData = 0;

	   // get current register image contents
	   wrData = rdRegisterImage( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT );
	     

	   if ( state == MakoUSBConstants::USB_PULLUP_ON)
	   {

	     // set the bit to the state argument
	     setBitField( &wrData, MAKO_USB_PULLUP_BITFIELD, 1);
	   }
	   else // USB_PULLUP_OFF
	   {
	     // set the bit to the state argument
	     setBitField( &wrData, MAKO_USB_PULLUP_BITFIELD, 0);     
	   }
	 

	   // update the register image to reflect the new setting
	   wrRegisterImage( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT, wrData );

	   // write the image to the IC
	   wrRegisterUSB( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT ); 

	  
	// }}}USR
}
// }}}RME

// {{{RME operation 'setSpeed(int,int)'
void MakoUSBCtrl::setSpeed( int state, int transceiver )
{
	// {{{USR

	   uint32_t wrData = 0;

	   // get current register image contents
	   wrData = rdRegisterImage( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT );


	   if ( state == MakoUSBConstants::USB_SPEED_FULL )
	   {

	     // set the bit to the state argument
	     setBitField( &wrData, MAKO_USB_SPEED_BITFIELD, 1);
	   }
	   else // USB_SPEED_LOW
	   {
	    // set the bit to the state argument
	     setBitField( &wrData, MAKO_USB_SPEED_BITFIELD, 0);   
	   }
	  

	   // update the register image to reflect the new setting
	   wrRegisterImage( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT, wrData );

	   // write the image to the IC
	   wrRegisterUSB( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT ); 

	  
	  
	// }}}USR
}
// }}}RME

// {{{RME operation 'setSuspend(int,int)'
void MakoUSBCtrl::setSuspend( int state, int transceiver )
{
	// {{{USR
	 
	   uint32_t wrData = 0;

	   // get current register image contents
	   wrData = rdRegisterImage( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT );

	   if ( state == MakoUSBConstants::USB_SUSPEND_ON )
	   {

	     // set the bit to the state argument
	     setBitField( &wrData, MAKO_USB_SUSPEND_BITFIELD, 1);
	   }
	   else // USB_SUSPEND_OFF
	   {
	    // set the bit to the state argument
	     setBitField( &wrData, MAKO_USB_SUSPEND_BITFIELD, 0);   
	   }
	  

	   // update the register image to reflect the new setting
	   wrRegisterImage( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT, wrData );

	   // write the image to the IC
	   wrRegisterUSB( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT ); 


	// }}}USR
}
// }}}RME

// {{{RME operation 'setVbusDischarge(int,int)'
void MakoUSBCtrl::setVbusDischarge( int state, int transceiver )
{
	// {{{USR
	   uint32_t wrData = 0;

	   // get current register image contents
	   wrData = rdRegisterImage( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT );

	   if ( state == MakoUSBConstants::USB_VBUS_DISCH_ON )
	   {

	     // set the bit to the state argument
	     setBitField( &wrData, MAKO_USB_VBUS_DISCH_BITFIELD, 1);
	   }
	   else // USB_VBUS_DISCH_OFF
	   {
	    // set the bit to the state argument
	     setBitField( &wrData, MAKO_USB_VBUS_DISCH_BITFIELD, 0);   
	   }
	  

	   // update the register image to reflect the new setting
	   wrRegisterImage( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT, wrData );

	   // write the image to the IC
	   wrRegisterUSB( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT ); 

	  
	   
	// }}}USR
}
// }}}RME

// {{{RME operation 'setCurrentLimit(bool,int)'
void MakoUSBCtrl::setCurrentLimit( bool state, int transceiver )
{
	// {{{USR
	 
	   uint32_t wrData = 0;

	   // get current register image contents
	   wrData = rdRegisterImage( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT );


	   // set the current limit bit to the state argument
	     setBitField( &wrData, MAKO_USB_VBUS_ILIMIT_BITFIELD, state);  


	   // update the register image to reflect the new setting
	   wrRegisterImage( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT, wrData );

	   // write the image to the IC
	   wrRegisterUSB( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT ); 

	// }}}USR
}
// }}}RME

// {{{RME operation 'eventOccurred(const EventBase * const )'
void MakoUSBCtrl::eventOccurred( const EventBase * const event )
{
	// {{{USR
	  
	   uint32_t temp1 = 0;
	   uint32_t temp2 = 0;
	   uint32_t flag_data = 0;

	// check the type of the EventBase object representing the event that occurred.
	// we are only interested in an IOVirtual event.  Thus, for good programming practice,
	// we discard all other event types. 
	if( event->isType(IOVirtual::Event::IO_EVENT) ) 
	{
	  
	   // Step 1 - read mako interrupt flag register to determine
	   // which interrupt fired. Events are:
	   // USB1_INTR_EVENT1_VBUS_0V when 
	   // USB1_INTR_EVENT2_VBUS_5V when
	   // USB2_INTR_EVENT3_VBUS_0V when
	   // USB2_INTR_EVENT4_VBUS_5V when

	   //	******  Mako Vbus truth table *****      
	   //                   
	   // D1 VbusVal_bit       D0  SessEnd_bit    |  Vbus Voltage |  return constant
	   // =============================================================================
	   // 0                    0                  | 0.8 < V < 4V  |  VBUS_INDETERMINATE
	   // 0                    1                  | Vbus< 0.8V    |  USBn_INTR_EVENT1_VBUS_0V
	   // 1                    0                  | Vbus > 4.4V   |  USBn_INTR_EVENT2_VBUS_5V
	   // 1                    1                  | can't occur   |  VBUS_ERROR

	   // read the appropriate register from the Mako IC (via spi bus), obtain its
	   // value, update the MakoUSBCtrl private register image and return its value
	   // the first argument of rdRegisterUSB is the transceiver number. The flag
	   // register contains bits for both transceivers so the transceiver argument
	   // is not applicable - we'll set it to zero then.
	   // WARNING - don't change this code to use the getIntrFlagBSessEnd and
	   // getIntrFlagVbusVal interface methods instead of the "raw register read
	   // implemented below. Doing so might be more straightforward, but will result in
	   // TWO spi accesses instead of one - this is to be avoided!

	   flag_data = rdRegisterUSB( 0, MakoUSBConstants::MAKO_REG_FLAGS );

	   // read the Vbus_Valid flag for transceiver 1 and shift up one bit to conform
	   // to the Mako Vbus truth table above.
	   temp1  = getBitField( &flag_data, MAKO_USB1_VBUS_VALID_LE_BITFIELD ) << 1;
	   temp1 |= getBitField( &flag_data, MAKO_USB1_BSESS_END_LE_BITFIELD  );
	 
	  // read the Vbus_Valid flag for transceiver 2 and shift up one bit to conform
	   // to the Mako Vbus truth table above.
	   temp2  = getBitField( &flag_data, MAKO_USB2_VBUS_VALID_LE_BITFIELD ) << 1;
	   temp2 |= getBitField( &flag_data, MAKO_USB2_BSESS_END_LE_BITFIELD  );

	   // Step 2 - call User defined event handler.

	   // process transceiver 1 events first - this priority decision is arbitrary
	   // we will ignore VBUS_INDETERMINATE and VBUS_ERROR states
	   switch (temp1)
	   {
	  
	     case 1:
	       
	        m_userdefinedUSBEventHandlerClass->processEvent(MakoUSBEvents::USB1_INTR_EVENT1_VBUS_0V,
	                                                        MakoUSBConstants::USB1_TRANSCEIVER, 
	                                                        flag_data); 
	     break;

	     case 2:

	        m_userdefinedUSBEventHandlerClass->processEvent(MakoUSBEvents::USB1_INTR_EVENT2_VBUS_5V,
	                                                        MakoUSBConstants::USB1_TRANSCEIVER, 
	                                                        flag_data); 
	     break;

	   }
	     
	  // process transceiver 2 events
	   
	   switch (temp2)
	   {
	  
	     case 1:
	       
	        m_userdefinedUSBEventHandlerClass->processEvent(MakoUSBEvents::USB2_INTR_EVENT3_VBUS_0V,
	                                                        MakoUSBConstants::USB2_TRANSCEIVER, 
	                                                        flag_data); 
	     break;

	     case 2:

	        m_userdefinedUSBEventHandlerClass->processEvent(MakoUSBEvents::USB2_INTR_EVENT4_VBUS_5V,
	                                                        MakoUSBConstants::USB2_TRANSCEIVER, 
	                                                        flag_data); 
	     break;

	   } 

	   // now, clear the flag bits.
	  
	   // get current register image contents
	   flag_data = m_RegImageUSB_INTR_FLAGS; 

	   // clear the hardware bit output by writing 1 to it - according to data sheet.
	   setBitField( &flag_data, MAKO_USB1_VBUS_VALID_LE_BITFIELD, 1);
	 
	   // clear the hardware bit output by writing 1 to it - according to data sheet.
	   setBitField( &flag_data, MAKO_USB1_BSESS_END_LE_BITFIELD, 1);     

	   // clear the hardware bit output by writing 1 to it - according to data sheet.
	   setBitField( &flag_data, MAKO_USB2_VBUS_VALID_LE_BITFIELD, 1);
	 
	   // clear the hardware bit output by writing 1 to it - according to data sheet.
	   setBitField( &flag_data, MAKO_USB2_BSESS_END_LE_BITFIELD, 1);     

	   // update the register image to reflect the new setting
	   m_RegImageUSB_INTR_FLAGS = flag_data;

	   // write the register image to the IC out over the spi bus
	   wrRegisterUSB( 0, MakoUSBConstants::MAKO_REG_FLAGS );

	} // end if( event->isType(IO_EVENT) )   
	// }}}USR
}
// }}}RME

// {{{RME operation 'pgmPwrUpDefault(int)'
void MakoUSBCtrl::pgmPwrUpDefault( int transceiver )
{
	// {{{USR
	   uint32_t wrData = 0;

	    
	   wrData = MakoUSBConstants::MAKO_CTRL_STAT_DEFAULT;

	   // **************************************************************
	   // Initialize control status register 1 to default power up state
	   // **************************************************************   
	   // set USB subregister address to USB1
	   setBitField( &wrData, MAKO_USB_REG_ADDR_BITFIELD, MAKO_USB1_CTRL_STAT_REG_ADDR);        
	 
	   // call mako parent's register interface, specifing which Mako component ( addr = 0 - 7 )
	   // register to access. USB/Opt Control is = 4. USB subcomponent register specifed in wrData.       
	   m_MakoParent->wrRegister( MAKO_USB_REGISTER_ADDR, wrData );


	   // **************************************************************
	   // Initialize control status register 2 to default power up state
	   // **************************************************************   
	   // set USB subregister address to USB2
	   setBitField( &wrData, MAKO_USB_REG_ADDR_BITFIELD, MAKO_USB2_CTRL_STAT_REG_ADDR);        
	 
	   // call mako parent's register interface, specifing which Mako component ( addr = 0 - 7 )
	   // register to access. USB/Opt Control is = 4. USB subcomponent register specifed in wrData.       
	   m_MakoParent->wrRegister( MAKO_USB_REGISTER_ADDR, wrData );

	   wrData = MakoUSBConstants::MAKO_INT_EN_DEFAULT;

	   // ******************************************************************
	   // Initialize interrupt enable register 1 to default power up state
	   // ****************************************************************   
	   // set USB subregister address to USB1
	   setBitField( &wrData, MAKO_USB_REG_ADDR_BITFIELD, MAKO_USB1_INT_EN_REG_ADDR);        
	 
	   // call mako parent's register interface, specifing which Mako component ( addr = 0 - 7 )
	   // register to access. USB/Opt Control is = 4. USB subcomponent register specifed in wrData.       
	   m_MakoParent->wrRegister( MAKO_USB_REGISTER_ADDR, wrData ); 

	   // ******************************************************************
	   // Initialize interrupt enable register 2 to default power up state
	   // ****************************************************************   
	   // set USB subregister address to USB1
	   setBitField( &wrData, MAKO_USB_REG_ADDR_BITFIELD, MAKO_USB2_INT_EN_REG_ADDR);        
	 
	   // call mako parent's register interface, specifing which Mako component ( addr = 0 - 7 )
	   // register to access. USB/Opt Control is = 4. USB subcomponent register specifed in wrData.       
	   m_MakoParent->wrRegister( MAKO_USB_REGISTER_ADDR, wrData );

	   wrData = MakoUSBConstants::MAKO_INT_FLAGS_DEFAULT;

	   // ***************************************************************
	   // Initialize interrupt flags register to default power up state
	   // *************************************************************   
	   // set USB subregister address to USB1
	   setBitField( &wrData, MAKO_USB_REG_ADDR_BITFIELD, MAKO_USB_INT_FLAGS_REG_ADDR);        
	 
	   // call mako parent's register interface, specifing which Mako component ( addr = 0 - 7 )
	   // register to access. USB/Opt Control is = 4. USB subcomponent register specifed in wrData.       
	   m_MakoParent->wrRegister( MAKO_USB_REGISTER_ADDR, wrData );

	   
	// }}}USR
}
// }}}RME

// {{{RME operation 'setVbusIMon(int,int)'
void MakoUSBCtrl::setVbusIMon( int state, int transceiver )
{
	// {{{USR
	   uint32_t wrData = 0;

	   // get current register image contents
	   wrData = rdRegisterImage( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT );

	   if ( state == MakoUSBConstants::USB_VBUS_MON_ON )
	   {

	     // set the bit to the state argument
	     setBitField( &wrData, MAKO_USB_VBUS_MON_ON_BITFIELD, 1);
	   }
	   else // USB_VBUS_MON_OFF
	   {
	    // set the bit to the state argument
	     setBitField( &wrData, MAKO_USB_VBUS_MON_ON_BITFIELD, 0);   
	   }

	   // update the register image to reflect the new setting
	   wrRegisterImage( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT, wrData );

	   // write the image to the IC
	   wrRegisterUSB( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT ); 
	  

	 
	// }}}USR
}
// }}}RME

// {{{RME operation 'setPowerEnable(int,int)'
void MakoUSBCtrl::setPowerEnable( int state, int transceiver )
{
	// {{{USR
	 
	   uint32_t wrData = 0;

	   // get current register image contents
	   wrData = rdRegisterImage( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT );

	  
	   if ( state == MakoUSBConstants::USB_PWR_ON)
	   {

	     // set the bit to the state argument
	     setBitField( &wrData, MAKO_USB_VBUS_SW_ON_BITFIELD, 1);
	   }
	   else // USB_PWR_OFF
	   {
	     // set the bit to the state argument
	     setBitField( &wrData, MAKO_USB_VBUS_SW_ON_BITFIELD, 0);     
	   }  


	   // update the register image to reflect the new setting
	   wrRegisterImage( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT, wrData );

	   // write the image to the IC
	   wrRegisterUSB( transceiver, MakoUSBConstants::MAKO_REG_CTRL_STAT ); 

	  
	  
	// }}}USR
}
// }}}RME

// {{{RME operation 'wrRegisterUSB(int,int)'
void MakoUSBCtrl::wrRegisterUSB( int transceiver, int reg_sel )
{
	// {{{USR
	   uint32_t wrData = 0;
	              

	   if ( transceiver == MakoUSBConstants::USB1_TRANSCEIVER )
	   {
	    
	     if( reg_sel == MakoUSBConstants::MAKO_REG_CTRL_STAT)
	     {

	         wrData = m_RegImageUSB1_CTRL_STAT;

	         // set USB subregister address for USB1
	         setBitField( &wrData, MAKO_USB_REG_ADDR_BITFIELD, MAKO_USB1_CTRL_STAT_REG_ADDR );

		 	// call mako parent's register interface, specifing which Mako component ( addr = 0 - 7 )
	   		// register to access. USB/Opt Control is = 4. USB subcomponent register specifed in wrData.       
	   		m_MakoParent->wrRegister( MAKO_USB_REGISTER_ADDR, wrData );

	        m_RegImageUSB1_CTRL_STAT = wrData; 
	   
	     }

	     else if ( reg_sel == MakoUSBConstants::MAKO_REG_INTR_EN )
	     {
	         wrData = m_RegImageUSB1_INTR_EN;

	         // set USB subregister address for USB1
	         setBitField( &wrData, MAKO_USB_REG_ADDR_BITFIELD, MAKO_USB1_INT_EN_REG_ADDR );

			 // call mako parent's register interface, specifing which Mako component ( addr = 0 - 7 )
	   		 // register to access. USB/Opt Control is = 4. USB subcomponent register specifed in wrData.       
	   		 m_MakoParent->wrRegister( MAKO_USB_REGISTER_ADDR, wrData ); 

	         m_RegImageUSB1_INTR_EN = wrData; 

	     }

	     else if ( reg_sel == MakoUSBConstants::MAKO_REG_FLAGS )
	     {
	         wrData = m_RegImageUSB_INTR_FLAGS;

	         // set USB subregister address for USB1
	         setBitField( &wrData, MAKO_USB_REG_ADDR_BITFIELD, MAKO_USB_INT_FLAGS_REG_ADDR );

			 // call mako parent's register interface, specifing which Mako component ( addr = 0 - 7 )
	   		 // register to access. USB/Opt Control is = 4. USB subcomponent register specifed in wrData.       
	   		 m_MakoParent->wrRegister( MAKO_USB_REGISTER_ADDR, wrData ); 

	         m_RegImageUSB_INTR_FLAGS = wrData; 

	     }
	 

	   }
	   else // transceiver two
	   {
	     if ( reg_sel == MakoUSBConstants::MAKO_REG_CTRL_STAT )
	     {
	         wrData = m_RegImageUSB2_CTRL_STAT;

	         // set USB subregister address for USB2
	         setBitField( &wrData, MAKO_USB_REG_ADDR_BITFIELD, MAKO_USB2_CTRL_STAT_REG_ADDR );

			 // call mako parent's register interface, specifing which Mako component ( addr = 0 - 7 )
	   		 // register to access. USB/Opt Control is = 4. USB subcomponent register specifed in wrData.       
	   		 m_MakoParent->wrRegister( MAKO_USB_REGISTER_ADDR, wrData ); 

	         m_RegImageUSB1_CTRL_STAT = wrData; 
	   
	     }

	     else if ( reg_sel == MakoUSBConstants::MAKO_REG_INTR_EN )
	     {
	         wrData = m_RegImageUSB2_INTR_EN;

	         // set USB subregister address for USB2
	         setBitField( &wrData, MAKO_USB_REG_ADDR_BITFIELD, MAKO_USB2_INT_EN_REG_ADDR );

			 // call mako parent's register interface, specifing which Mako component ( addr = 0 - 7 )
	   		 // register to access. USB/Opt Control is = 4. USB subcomponent register specifed in wrData.       
	   		 m_MakoParent->wrRegister( MAKO_USB_REGISTER_ADDR, wrData ); 

	         m_RegImageUSB2_INTR_EN = wrData; 

	     }

	     else if ( reg_sel == MakoUSBConstants::MAKO_REG_FLAGS )
	     {
	         wrData = m_RegImageUSB_INTR_FLAGS;

	         // set USB subregister address
	         setBitField( &wrData, MAKO_USB_REG_ADDR_BITFIELD, MAKO_USB_INT_FLAGS_REG_ADDR );

			 // call mako parent's register interface, specifing which Mako component ( addr = 0 - 7 )
	   		 // register to access. USB/Opt Control is = 4. USB subcomponent register specifed in wrData.       
	   		 m_MakoParent->wrRegister( MAKO_USB_REGISTER_ADDR, wrData ); 

	         m_RegImageUSB_INTR_FLAGS = wrData; 

	     }

	 
	  }

	// }}}USR
}
// }}}RME

// {{{RME operation 'wrRegisterImage(int,int,uint32_t)'
void MakoUSBCtrl::wrRegisterImage( int transceiver, int reg_sel, uint32_t newdata )
{
	// {{{USR
	   if ( transceiver == MakoUSBConstants::USB1_TRANSCEIVER )
	   {
	       if ( reg_sel == MakoUSBConstants::MAKO_REG_CTRL_STAT )
	       {
	         m_RegImageUSB1_CTRL_STAT = newdata;
	   
	       }

	       else if ( reg_sel == MakoUSBConstants::MAKO_REG_INTR_EN )
	       {
	         m_RegImageUSB1_INTR_EN = newdata;

	       }

	       else if ( reg_sel == MakoUSBConstants::MAKO_REG_FLAGS )
	       {
	         m_RegImageUSB_INTR_FLAGS = newdata;

	       }

	 

	   }
	   else // transceiver two
	   {
	       if ( reg_sel == MakoUSBConstants::MAKO_REG_CTRL_STAT )
	       {
	         m_RegImageUSB2_CTRL_STAT = newdata;
	  
	       }

	       else if ( reg_sel == MakoUSBConstants::MAKO_REG_INTR_EN )
	       {
	         m_RegImageUSB2_INTR_EN = newdata;

	       }

	       else if ( reg_sel == MakoUSBConstants::MAKO_REG_FLAGS )
	       {
	         m_RegImageUSB_INTR_FLAGS = newdata;

	       }

	 
	   }

	   

	// }}}USR
}
// }}}RME

// {{{RME operation 'rdRegisterUSB(int,int)'
uint32_t MakoUSBCtrl::rdRegisterUSB( int transceiver, int reg_sel )
{
	// {{{USR
	   uint32_t wrData = 0;

	   unsigned int retval = 0;
	               
	   if ( transceiver == MakoUSBConstants::USB1_TRANSCEIVER )
	   {
	       if ( reg_sel ==MakoUSBConstants::MAKO_REG_CTRL_STAT )
	       { 
	         // set USB subregister address for USB1
	         setBitField( &wrData, MAKO_USB_REG_ADDR_BITFIELD, MAKO_USB1_CTRL_STAT_REG_ADDR );

			 // call mako parent's register interface, specifing which Mako component ( addr = 0 - 7 )
	   		 // register to access. USB/Opt Control is = 4. USB subcomponent register specifed in wrData.       
	   		 retval = m_MakoParent->rdRegister( MAKO_USB_REGISTER_ADDR, wrData);

	         m_RegImageUSB1_CTRL_STAT = retval; 
	   
	       }

	       else if ( reg_sel == MakoUSBConstants::MAKO_REG_INTR_EN )
	       {
	         // set USB subregister address for USB1
	         setBitField( &wrData, MAKO_USB_REG_ADDR_BITFIELD, MAKO_USB1_INT_EN_REG_ADDR );

			 // call mako parent's register interface, specifing which Mako component ( addr = 0 - 7 )
	   		 // register to access. USB/Opt Control is = 4. USB subcomponent register specifed in wrData.       
	   		 retval = m_MakoParent->rdRegister( MAKO_USB_REGISTER_ADDR, wrData);

	         m_RegImageUSB1_INTR_EN = retval; 

	       }

	       else if ( reg_sel ==MakoUSBConstants::MAKO_REG_FLAGS )
	       {

	         // set USB subregister address for USB1
	         setBitField( &wrData, MAKO_USB_REG_ADDR_BITFIELD, MAKO_USB_INT_FLAGS_REG_ADDR );

			 // call mako parent's register interface, specifing which Mako component ( addr = 0 - 7 )
	   		 // register to access. USB/Opt Control is = 4. USB subcomponent register specifed in wrData.       
	   		 retval = m_MakoParent->rdRegister( MAKO_USB_REGISTER_ADDR, wrData);

	         m_RegImageUSB_INTR_FLAGS = retval; 

	       }


	   }
	   else // transceiver two
	   {
	       if ( reg_sel ==MakoUSBConstants::MAKO_REG_CTRL_STAT )
	       {
	         // set USB subregister address for USB2
	         setBitField( &wrData, MAKO_USB_REG_ADDR_BITFIELD, MAKO_USB2_CTRL_STAT_REG_ADDR );

			 // call mako parent's register interface, specifing which Mako component ( addr = 0 - 7 )
	   		 // register to access. USB/Opt Control is = 4. USB subcomponent register specifed in wrData.       
	   		 retval = m_MakoParent->rdRegister( MAKO_USB_REGISTER_ADDR, wrData);

	         m_RegImageUSB1_CTRL_STAT = retval; 
	   
	       }

	       else if ( reg_sel ==MakoUSBConstants::MAKO_REG_INTR_EN )
	       {
	         // set USB subregister address for USB2
	         setBitField( &wrData, MAKO_USB_REG_ADDR_BITFIELD, MAKO_USB2_INT_EN_REG_ADDR );

			 // call mako parent's register interface, specifing which Mako component ( addr = 0 - 7 )
	   		 // register to access. USB/Opt Control is = 4. USB subcomponent register specifed in wrData.       
	   		 retval = m_MakoParent->rdRegister( MAKO_USB_REGISTER_ADDR, wrData);

	         m_RegImageUSB2_INTR_EN = retval; 

	       }

	       else if ( reg_sel ==MakoUSBConstants::MAKO_REG_FLAGS )
	       {

	         // set USB subregister address
	         setBitField( &wrData, MAKO_USB_REG_ADDR_BITFIELD, MAKO_USB_INT_FLAGS_REG_ADDR );

			 // call mako parent's register interface, specifing which Mako component ( addr = 0 - 7 )
	   		 // register to access. USB/Opt Control is = 4. USB subcomponent register specifed in wrData.       
	   		 retval = m_MakoParent->rdRegister( MAKO_USB_REGISTER_ADDR, wrData);

	         m_RegImageUSB_INTR_FLAGS = retval; 

	       }


	  }

	   


	   return retval;  

	// }}}USR
}
// }}}RME

// {{{RME operation 'rdRegisterImage(int,int)'
uint32_t MakoUSBCtrl::rdRegisterImage( int transceiver, int reg_sel )
{
	// {{{USR
	 
	   unsigned int retval = 0;
	               

	   if ( transceiver == MakoUSBConstants::USB1_TRANSCEIVER )
	   {
	       if ( reg_sel == MakoUSBConstants::MAKO_REG_CTRL_STAT )
	       {
	         retval = m_RegImageUSB1_CTRL_STAT;
	   
	       }

	       else if ( reg_sel == MakoUSBConstants::MAKO_REG_INTR_EN )
	       {
	         retval = m_RegImageUSB1_INTR_EN;

	       }

	       else if ( reg_sel == MakoUSBConstants::MAKO_REG_FLAGS )
	       {
	         retval = m_RegImageUSB_INTR_FLAGS;

	       }

	   }
	   else // transceiver two
	   {
	       if ( reg_sel ==  MakoUSBConstants::MAKO_REG_CTRL_STAT )
	       {
	         retval = m_RegImageUSB2_CTRL_STAT;
	  
	       }

	       else if ( reg_sel ==  MakoUSBConstants::MAKO_REG_INTR_EN )
	       {
	         retval = m_RegImageUSB2_INTR_EN;

	       }

	       else if ( reg_sel ==  MakoUSBConstants::MAKO_REG_FLAGS )
	       {
	         retval = m_RegImageUSB_INTR_FLAGS;

	       }
	       
	  }

	   
	   return retval;  

	// }}}USR
}
// }}}RME

// {{{RME operation 'getIOVirtualPin(int,int,IOVirtual *)'
IOVirtual * MakoUSBCtrl::getIOVirtualPin( int transceiver, int whichpin, IOVirtual * VbusDetIOVirtual )
{
	// {{{USR

	   IOVirtual * retval = 0;

	   if( whichpin == MakoUSBConstants::IOVIRTUAL_VBUSDETECT )
	   {

	   		if( transceiver == MakoUSBConstants::USB1_TRANSCEIVER )
	   		{
	     		// remove the default USBIOVirtualHandler (IOVirtual) object
	     		// created by the constructor, since the client-supplied IOVirtual
	     		// will be used instead.
	     		delete m_IOVirtualVbusDetect1;

	     		m_IOVirtualVbusDetect1 = VbusDetIOVirtual;

	            retval = m_IOVirtualVbusDetect1;
	   		}
	   		else
	   		{
	     		delete m_IOVirtualVbusDetect2;

	     		m_IOVirtualVbusDetect2 = VbusDetIOVirtual;

	            retval = m_IOVirtualVbusDetect2;
	   		}


	   }

	   return retval;    

	// }}}USR
}
// }}}RME

// {{{RME operation 'getIOVirtualPin(int,int)'
IOVirtual * MakoUSBCtrl::getIOVirtualPin( int transceiver, int whichpin )
{
	// {{{USR

	   IOVirtual * retval = 0;


	   if ( transceiver == MakoUSBConstants::USB1_TRANSCEIVER )
	   {
	    	if( whichpin == MakoUSBConstants::IOVIRTUAL_DEVPUEN ) 
	    	{
	      	retval = m_IOVirtualDevPUEN1;
	    	}
	    	else if( whichpin == MakoUSBConstants::IOVIRTUAL_PWRENABLE )
	    	{
	      	retval = m_IOVirtualPwrEnable1;
	    	}
	    	else if( whichpin == MakoUSBConstants::IOVIRTUAL_SUSPEND )
	    	{
	      	retval = m_IOVirtualSuspend1;
	    	}
	     	else if( whichpin == MakoUSBConstants::IOVIRTUAL_VBUSDETECT )
	    	{
	      	retval = m_IOVirtualVbusDetect1;
	    	}
	   }
	   else
	   {
	    	if( whichpin == MakoUSBConstants::IOVIRTUAL_DEVPUEN ) 
	    	{
	      	retval = m_IOVirtualDevPUEN2;
	    	}
	    	else if( whichpin == MakoUSBConstants::IOVIRTUAL_PWRENABLE )
	    	{
	      	retval = m_IOVirtualPwrEnable2;
	    	}
	    	else if( whichpin == MakoUSBConstants::IOVIRTUAL_SUSPEND )
	    	{
	      	retval = m_IOVirtualSuspend2;
	    	}
	     	else if( whichpin == MakoUSBConstants::IOVIRTUAL_VBUSDETECT )
	    	{
	      	retval = m_IOVirtualVbusDetect2;
	    	}
	   }

	    return retval;    

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
