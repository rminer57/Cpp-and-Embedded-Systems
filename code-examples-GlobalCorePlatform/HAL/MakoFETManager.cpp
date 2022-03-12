// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoUSBSubsystem::FETmanager::MakoFETManager'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "MakoFETManager.h"
#endif

#include <HALtestLib_win32.h>
#include <MakoFETManager.h>
#include <MakoUSBCtrl.h>
#include <Thread.h>
#include <TimeSpec.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
// ***************************************************************************
// constants for use in the transceiverModeChange statemachine case statements.
// ***************************************************************************

// dual purpose defines serve as bit masks and method argument operation selects
// Mask selects USB1 control/status register address and USB_CONNECT = 1
#define MAKOFETMGR_FET_ON   0x00008000
#define MAKOFETMGR_FET_OFF  0xFFFF7FFF

#define MAKOUSB1_CTRL_STAT_ADDR 0x00000000 // D27-D24 =0000b to select USB1 
#define MAKOUSB2_CTRL_STAT_ADDR 0x01000000 // D27-D24 =0001b to select USB2


// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
MakoFETManager::MakoFETManager( void )
{
}
// }}}RME

// {{{RME operation 'MakoFETManager(MakoUSBCtrl *)'
MakoFETManager::MakoFETManager( MakoUSBCtrl * parent )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR

	m_MakoUSBCtrlParent = parent;

	// initialize transceivers and FET to off.
	transceiverModeChange(0,0,0,0);

	 
	// }}}USR
}
// }}}RME

// {{{RME operation 'transceiverModeChange(int,int,int,int)'
void MakoFETManager::transceiverModeChange( int oldUSB1state, int newUSB1state, int oldUSB2state, int newUSB2state )
{
	// {{{USR
	     // some notes about what is being done here and why....
	    // USB_CONNECT is an output which behaves as a GPIO and which was originally intended to support APCO
	    // radios. It is used here to control the FET.  When a USB transceiver is to be a HOST, according to the
	    // USB protocol, it must drive the Vbus line to +5V. In order to do this, Mako includes an internal power
	    // supply, referred to herein as switcher #5. Although each transceiver has a separate Vbus pin, there is
	    // only one switcher. Enabling the switcher and connecting it to the selected transceiver Vbus pin requires
	    // that two USB control register bits be manipulated. These are Vbus_Sw_On and Vbus_LDO_On. The Sw_On
	    // bits of both transceivers are wire-ored together.
		    
		         // if USB1 changed from device to host AND USB2 changed from device to host
		         if( oldUSB1state == MakoUSBConstants::USB_MODE_DEVICE && 
		             newUSB1state == MakoUSBConstants::USB_MODE_HOST   && 
		        
		             oldUSB2state == MakoUSBConstants::USB_MODE_DEVICE &&
		             newUSB2state == MakoUSBConstants::USB_MODE_HOST 
		           )
		         {
		             // if USB1 changed from device to host AND USB2 changed from device to host
		             // then both would have been off.
		             changeFETstate( MAKOFETMGR_FET_ON, MakoUSBConstants::USB_TRANSCEIVERS_BOTH );       
		         }
		      
		    // if USB1 changed from host to device AND USB2 changed from host to device 
		    else if( oldUSB1state == MakoUSBConstants::USB_MODE_HOST   && 
		             newUSB1state == MakoUSBConstants::USB_MODE_DEVICE &&
		         
		             oldUSB2state == MakoUSBConstants::USB_MODE_HOST   &&
		             newUSB2state == MakoUSBConstants::USB_MODE_DEVICE 
		           )
		    {
		             changeFETstate( MAKOFETMGR_FET_OFF, MakoUSBConstants::USB_TRANSCEIVERS_BOTH ); 
		    }

		    // if USB1 changed from device to host AND USB2 changed from host to device
		    else if( oldUSB1state == MakoUSBConstants::USB_MODE_DEVICE && 
		             newUSB1state == MakoUSBConstants::USB_MODE_HOST   &&
		         
		             oldUSB2state == MakoUSBConstants::USB_MODE_HOST   &&
		             newUSB2state == MakoUSBConstants::USB_MODE_DEVICE 
		           )
		    {
		             // enable USB1 first
		             // Since USB2 was alread on, switcher 5 was on and FET was enabled.
		             // leave the FET on since its needed for USB1 which now becomes a host. 	                
		             // set bit D21 Vbus_Sw_On to enable switcher #5 for USB1
					 m_MakoUSBCtrlParent->setPowerEnable(MakoUSBConstants::USB_PWR_ON,MakoUSBConstants::USB1_TRANSCEIVER);

		             // set Vbus_LDO_On (regulator on control) bits for USB1
		             m_MakoUSBCtrlParent->setVbusLDO( MakoUSBConstants::USB_LDO_ON, MakoUSBConstants::USB1_TRANSCEIVER );

		             // turn off switching bit for USB2 since its being changed to device mode
					 m_MakoUSBCtrlParent->setPowerEnable(MakoUSBConstants::USB_PWR_OFF,MakoUSBConstants::USB2_TRANSCEIVER);            	
					 m_MakoUSBCtrlParent->setVbusLDO( MakoUSBConstants::USB_LDO_OFF, MakoUSBConstants::USB2_TRANSCEIVER );					     	                   
		    }
		    
		    // if USB1 changed from host to device AND USB2 changed from device to host
		    // this change requires that FET be left on for USB2 use meanwhile USB1 switcher control is disabled.
		    else if( oldUSB1state == MakoUSBConstants::USB_MODE_HOST   && 
		             newUSB1state == MakoUSBConstants::USB_MODE_DEVICE &&
		         
		             oldUSB2state == MakoUSBConstants::USB_MODE_DEVICE &&
		             newUSB2state == MakoUSBConstants::USB_MODE_HOST 
		           )
		    {
		             // enable USB2 first
		             // set bit D21 Vbus_Sw_On to enable switcher #5 for USB2
					 m_MakoUSBCtrlParent->setPowerEnable(MakoUSBConstants::USB_PWR_ON,MakoUSBConstants::USB2_TRANSCEIVER);

		             // set Vbus_LDO_On (regulator on control) bits for USB2
		             m_MakoUSBCtrlParent->setVbusLDO( MakoUSBConstants::USB_LDO_ON, MakoUSBConstants::USB2_TRANSCEIVER );

		             // turn off switching bit and LDO for USB1
					 m_MakoUSBCtrlParent->setPowerEnable(MakoUSBConstants::USB_PWR_OFF,MakoUSBConstants::USB1_TRANSCEIVER);            	
					 m_MakoUSBCtrlParent->setVbusLDO( MakoUSBConstants::USB_LDO_OFF, MakoUSBConstants::USB1_TRANSCEIVER );			     	                   
		    }

		    // if USB1 changed from device to host AND USB2 did not change state
		    else if( oldUSB1state == MakoUSBConstants::USB_MODE_DEVICE && 
		             newUSB1state == MakoUSBConstants::USB_MODE_HOST   &&
		         
		             oldUSB2state == newUSB2state 
		           )
		    {
		             // find out if USB2 is not host. If not, FET must be enabled for USB1
		             // This is necessary because although we know that the state of USB2 did not
		             // change, we don't yet know if USB2 was host or device - this knowledge is
		             // required in order to know what must done to the FET.
		             if( oldUSB2state != MakoUSBConstants::USB_MODE_HOST )
		             {
		         		 changeFETstate( MAKOFETMGR_FET_ON, MakoUSBConstants::USB1_TRANSCEIVER ); 	         		  
		             }
		             else // FET was on for USB2 and will be left as is.
		             {
		                 // enable USB1 
		                 // set bit D21 Vbus_Sw_On to enable switcher #5 for USB1
						 m_MakoUSBCtrlParent->setPowerEnable(MakoUSBConstants::USB_PWR_ON,MakoUSBConstants::USB1_TRANSCEIVER);

		            	 // set Vbus_LDO_On (regulator on control) bits for USB1
		            	 m_MakoUSBCtrlParent->setVbusLDO( MakoUSBConstants::USB_LDO_ON, MakoUSBConstants::USB1_TRANSCEIVER );
		             }	        
		                   
		    }

		    // if USB1 changed from host to device AND USB2 did not change state
		    else if( oldUSB1state == MakoUSBConstants::USB_MODE_HOST   && 
		             newUSB1state == MakoUSBConstants::USB_MODE_DEVICE &&
		         
		             oldUSB2state == newUSB2state 
		           )
		    {
		            	 // find out if USB2 is not host. If not, FET must turned off
		             if( oldUSB2state != MakoUSBConstants::USB_MODE_HOST )
		             {
		         		 changeFETstate( MAKOFETMGR_FET_OFF, MakoUSBConstants::USB_TRANSCEIVERS_BOTH ); // turn the FET off
		                
		             }

		             else // FET was already on for USB2 so it will be left as is.
		             {

		                 // disable USB1 
		                 // clr bit D21 Vbus_Sw_On to disable switcher #5 for USB1
						 m_MakoUSBCtrlParent->setPowerEnable(MakoUSBConstants::USB_PWR_OFF,MakoUSBConstants::USB1_TRANSCEIVER);

		            	 // clr Vbus_LDO_On (regulator on control) bits for USB1
		            	 m_MakoUSBCtrlParent->setVbusLDO( MakoUSBConstants::USB_LDO_OFF, MakoUSBConstants::USB1_TRANSCEIVER );

		             }	        
		                   
		    }

		    // if USB1 did not change state AND USB2 changed from device to host  
		    else if( oldUSB1state == newUSB1state &&
		         
		             oldUSB2state == MakoUSBConstants::USB_MODE_DEVICE &&
		             newUSB2state == MakoUSBConstants::USB_MODE_HOST 
		           )
		    {	      
	      	         // Determine if USB1 is not host. If not, FET must be enabled for USB2
		             if( oldUSB1state != MakoUSBConstants::USB_MODE_HOST )
		             {
		         		 changeFETstate( MAKOFETMGR_FET_ON, MakoUSBConstants::USB2_TRANSCEIVER ); 
		             }
		             else // FET was alread on due to USB1 being set to HOST
		             {

		                 // enable USB2 
		                 // set bit D21 Vbus_Sw_On to enable switcher #5 for USB2
						 m_MakoUSBCtrlParent->setPowerEnable(MakoUSBConstants::USB_PWR_ON,MakoUSBConstants::USB2_TRANSCEIVER);

		            	 // set Vbus_LDO_On (regulator on control) bits for USB2
		            	 m_MakoUSBCtrlParent->setVbusLDO( MakoUSBConstants::USB_LDO_ON, MakoUSBConstants::USB2_TRANSCEIVER );

		             }	        
		                   
		    }

		    // if USB1 did not change state AND USB2 changed from host to device  
		    else if( oldUSB1state == newUSB1state &&
		         
		             oldUSB2state == MakoUSBConstants::USB_MODE_HOST &&
		             newUSB2state == MakoUSBConstants::USB_MODE_DEVICE 
		           )
		    {
		             // find out if USB1 is not host. If not, FET must turned off
		             if( oldUSB1state != MakoUSBConstants::USB_MODE_HOST )
		             {
		         		 changeFETstate( MAKOFETMGR_FET_OFF, MakoUSBConstants::USB_TRANSCEIVERS_BOTH ); // turn the FET off
		                
		             }

		             else // FET was on
		             {
		                 // disable USB2 
		                 // clr bit D21 Vbus_Sw_On to disable switcher #5 for USB2
						 m_MakoUSBCtrlParent->setPowerEnable(MakoUSBConstants::USB_PWR_OFF,MakoUSBConstants::USB2_TRANSCEIVER);

		            	 // clr Vbus_LDO_On (regulator on control) bits for USB2
		            	 m_MakoUSBCtrlParent->setVbusLDO( MakoUSBConstants::USB_LDO_OFF, MakoUSBConstants::USB2_TRANSCEIVER );
		             }
		                  
		    }
	// }}}USR
}
// }}}RME

// {{{RME operation 'changeFETstate(int,int)'
void MakoFETManager::changeFETstate( int newstate, int transceiver )
{
	// {{{USR
	    // state can be MAKOFETMGR_FET_ON or MAKOFETMGR_FET_OFF
	    // transceiver can be MakoUSBConstants::USB1_TRANSCEIVER, MakoUSBConstants::USB2_TRANSCEIVER
	    // or MakoUSBConstants::USB_TRANSCEIVERS_BOTH
	    
		TimeSpec tp(0,20000000);

		int Vbus_Sw_Op1 = 0;	
		int Vbus_Sw_Op2 = 0;
		    
		uint32_t reg1Data = 0;
		uint32_t reg2Data = 0;	

		// get current register image contents
		reg1Data =  m_MakoUSBCtrlParent->rdRegisterImage( MakoUSBConstants::USB1_TRANSCEIVER, MakoUSBConstants::MAKO_REG_CTRL_STAT );
		
	    // caller requires that the FET be turned on.
		if( newstate == MAKOFETMGR_FET_ON )
		{
	      // ******************************************************************************      	    
		  // step 1: procedure first indicates that the FET must be forced off.
	      // ******************************************************************************
		  // set the USB_Connect bit of control_status register 1 - MAKOFETMGR_FET_ON is the mask
		  reg1Data &= MAKOFETMGR_FET_OFF;
		  
		  // always write to USB1 to control the FET. The USB2 USB_CONNECT pin is not used.
		  // update the register image to reflect the new setting
		  m_MakoUSBCtrlParent->wrRegisterImage( MakoUSBConstants::USB1_TRANSCEIVER, MakoUSBConstants::MAKO_REG_CTRL_STAT, reg1Data );

		  // write the image to the IC
		  m_MakoUSBCtrlParent->wrRegisterUSB( MakoUSBConstants::USB1_TRANSCEIVER, MakoUSBConstants::MAKO_REG_CTRL_STAT ); 
	            
	      // ******************************************************************************	  
		  // step 2: set bit D21 Vbus_Sw_On to enable switcher #5 for transceiver selection.
	      // ******************************************************************************
	      
	      if( transceiver == MakoUSBConstants::USB1_TRANSCEIVER)
	      {      
	              m_MakoUSBCtrlParent->setPowerEnable(MakoUSBConstants::USB_PWR_ON,MakoUSBConstants::USB1_TRANSCEIVER);
	 
	      		  // ******************************************************************************	  
		  		  // step 3: wait
	      		  // ******************************************************************************	
	                  
		  		  Thread::nanosleep( tp ); // Wait 2 mSec = 2,000uSec = 2,000,000nSec as per procedure

	      		  // ******************************************************************************	  
		          // step 4: read Vbus_Sw_Op for transceiver selection. 
	              // ******************************************************************************
		          // read the Vbus_Sw_Op bits as per the hardware team procedure.  However, if the switcher
		          // is not operating, there is no provision in the USB application code for how to handle this error

		          Vbus_Sw_Op1 = m_MakoUSBCtrlParent->getPowerEnable( MakoUSBConstants::USB1_TRANSCEIVER);
	        
	      }
	                  
	      else if(  transceiver == MakoUSBConstants::USB2_TRANSCEIVER )
	      {  
	              m_MakoUSBCtrlParent->setPowerEnable(MakoUSBConstants::USB_PWR_ON,MakoUSBConstants::USB2_TRANSCEIVER);

	      		  // ******************************************************************************	  
		  		  // step 3: wait
	      		  // ******************************************************************************	
	                  
		  		  Thread::nanosleep( tp ); // Wait 2 mSec = 2,000uSec = 2,000,000nSec as per procedure 

	      		  // ******************************************************************************	  
		          // step 4: read Vbus_Sw_Op for transceiver selection. 
	              // ******************************************************************************
		          // read the Vbus_Sw_Op bits as per the hardware team procedure.  However, if the switcher
		          // is not operating, there is no provision in the USB application code for how to handle this error

		          Vbus_Sw_Op2 = m_MakoUSBCtrlParent->getPowerEnable( MakoUSBConstants::USB2_TRANSCEIVER);	
	                 
	      }
	      else // MakoUSBConstants::USB_TRANSCEIVERS_BOTH 
	      {
	         
	              m_MakoUSBCtrlParent->setPowerEnable(MakoUSBConstants::USB_PWR_ON,MakoUSBConstants::USB1_TRANSCEIVER); 
	              m_MakoUSBCtrlParent->setPowerEnable(MakoUSBConstants::USB_PWR_ON,MakoUSBConstants::USB2_TRANSCEIVER);

	      		  // ******************************************************************************	  
		  		  // step 3: wait
	      		  // ******************************************************************************	
	                  
		  		  Thread::nanosleep( tp ); // Wait 2 mSec = 2,000uSec = 2,000,000nSec as per procedure

	      		  // ******************************************************************************	  
		          // step 4: read Vbus_Sw_Op for transceiver selection. 
	              // ******************************************************************************
		          // read the Vbus_Sw_Op bits as per the hardware team procedure.  However, if the switcher
		          // is not operating, there is no provision in the USB application code for how to handle this error

		          Vbus_Sw_Op1 = m_MakoUSBCtrlParent->getPowerEnable( MakoUSBConstants::USB1_TRANSCEIVER);         
		          Vbus_Sw_Op2 = m_MakoUSBCtrlParent->getPowerEnable( MakoUSBConstants::USB2_TRANSCEIVER);                                   
	      }  
	      	          
	      // ******************************************************************************	  
		  // step 5: TURN FET ON
	      // ******************************************************************************	    
		  // set the bit - MAKOFETMGR_FET_ON is the mask
		  reg1Data |= MAKOFETMGR_FET_ON;
		  
		  // always write to USB1 to control the FET. The USB2 USB_CONNECT pin is not used.
		  // update the register image to reflect the new setting
		  m_MakoUSBCtrlParent->wrRegisterImage( MakoUSBConstants::USB1_TRANSCEIVER, MakoUSBConstants::MAKO_REG_CTRL_STAT, reg1Data );

		  // write the image to the IC
		  m_MakoUSBCtrlParent->wrRegisterUSB( MakoUSBConstants::USB1_TRANSCEIVER, MakoUSBConstants::MAKO_REG_CTRL_STAT ); 

	      // ******************************************************************************	  
		  // step 6: turn on LDO for transceiver selection.
	      // ******************************************************************************
	      
	      if( transceiver == MakoUSBConstants::USB1_TRANSCEIVER)
	      {
	               // set Vbus_LDO_On (regulator on control) bits for USB2
		          m_MakoUSBCtrlParent->setVbusLDO( MakoUSBConstants::USB_LDO_ON, MakoUSBConstants::USB1_TRANSCEIVER );	         		                    
	      }
	      else if(transceiver == MakoUSBConstants::USB2_TRANSCEIVER)
	      {           
	              // set Vbus_LDO_On (regulator on control) bits for USB2
		          m_MakoUSBCtrlParent->setVbusLDO( MakoUSBConstants::USB_LDO_ON, MakoUSBConstants::USB2_TRANSCEIVER );	         		                  
	         
	      }
	      else // MakoUSBConstants::USB_TRANSCEIVERS_BOTH )
	      {   
	    
	              // set Vbus_LDO_On (regulator on control) bits for USB2
		          m_MakoUSBCtrlParent->setVbusLDO( MakoUSBConstants::USB_LDO_ON, MakoUSBConstants::USB1_TRANSCEIVER );	         		                  
	         
	              // set Vbus_LDO_On (regulator on control) bits for USB2
		          m_MakoUSBCtrlParent->setVbusLDO( MakoUSBConstants::USB_LDO_ON, MakoUSBConstants::USB2_TRANSCEIVER );	         		                   
	      }                	    	  
	 
		}
		// FET is being turned off
		else 
		{
		  // clear the USB_CONNECT bit - MAKOFETMGR_FET_ON is the mask   
		  reg1Data &= MAKOFETMGR_FET_OFF;
		  
		  // always write to USB1 to control the FET. The USB2 USB_CONNECT pin is not used.
		  // update the register image to reflect the new setting
		  m_MakoUSBCtrlParent->wrRegisterImage( MakoUSBConstants::USB1_TRANSCEIVER, MakoUSBConstants::MAKO_REG_CTRL_STAT, reg1Data );

		  // write the image to the IC
		  m_MakoUSBCtrlParent->wrRegisterUSB( MakoUSBConstants::USB1_TRANSCEIVER, MakoUSBConstants::MAKO_REG_CTRL_STAT ); 

		   // clear Vbus_LDO_On (regulator on control) bits for both transceivers
		  m_MakoUSBCtrlParent->setVbusLDO( MakoUSBConstants::USB_LDO_OFF, MakoUSBConstants::USB1_TRANSCEIVER );
		  m_MakoUSBCtrlParent->setVbusLDO( MakoUSBConstants::USB_LDO_OFF, MakoUSBConstants::USB2_TRANSCEIVER );

		  // clr bit D21 Vbus_Sw_On to disable switcher #5 for both transceivers
		  m_MakoUSBCtrlParent->setPowerEnable(MakoUSBConstants::USB_PWR_OFF,MakoUSBConstants::USB1_TRANSCEIVER);
		  m_MakoUSBCtrlParent->setPowerEnable(MakoUSBConstants::USB_PWR_OFF,MakoUSBConstants::USB2_TRANSCEIVER);	      	  
		  
		}

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
