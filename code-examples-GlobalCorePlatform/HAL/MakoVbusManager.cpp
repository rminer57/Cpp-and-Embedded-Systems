// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoUSBSubsystem::VBUSmanager::MakoVbusManager'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "MakoVbusManager.h"
#endif

#include <rf_sequencer_comp.h>
#include <MakoVbusManager.h>
#include <MakoPrivateBitfieldsReg4.h>
#include <MakoUSBConstants.h>
#include <MakoUSBCtrl.h>
#include <TimerVirtual.h>
#include <bitfield.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'm_overcurrent1'
unsigned int MakoVbusManager::m_overcurrent1;
// }}}RME

// {{{RME classAttribute 'm_overcurrent2'
unsigned int MakoVbusManager::m_overcurrent2;
// }}}RME

// {{{RME operation 'MakoVbusManager(MakoUSBCtrl *)'
MakoVbusManager::MakoVbusManager( MakoUSBCtrl * MakoUSBCtrlParent )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_MakoUSBCtrlParent(MakoUSBCtrlParent), m_timerVirtual(0), m_interruptPin(0)
	// }}}USR
	// }}}RME
{
	// {{{USR


	m_overcurrent1 = 0;
	m_overcurrent2 = 0;






	// }}}USR
}
// }}}RME

// {{{RME operation 'eventOccurred(const EventBase * const)'
void MakoVbusManager::eventOccurred( const EventBase * const event )
{
	// {{{USR
	uint32_t regval = 0;

	if (event->isType(TimerVirtual::Event::TIMER_EVENT))
	{
	   //Stops timer.
	   m_timerVirtual->set(0);  //reset timer.

	   vbusCheckVoltage();

	   m_timerVirtual->set(1);
			  
	}

	// if the GPIO/MPUIO pin connected to the Mako interrupt line for which
	// an EVENT_IO_EDGE_CHANGE_HtoL event was registered for,has a level change,
	// then it is due to a Mako interrupt being generated. go ahead and check
	// the vbus.  High to Low edges are the ones of interest since the goal here is to
	// protect for a short on Vbus.  Shorts make lines to low :-) 

	if( event->isEvent(IOVirtual::Event::EVENT_IO_EDGE_CHANGE_HtoL) ) 
	{

	 // read the transceiver 2 control/status register from the Mako IC (via spi bus), obtain its
	 // value, update the MakoUSBCtrl private register image and return its value
	 regval = m_MakoUSBCtrlParent->rdRegisterUSB( MakoUSBConstants::USB1_TRANSCEIVER, MakoUSBConstants::MAKO_REG_FLAGS );

	 if( getBitField( &regval, MAKO_USB1_VBUS_RE_FE_INTRFLAG_BITFIELD) == 1 )
	 {
	    // Mako interrupt pin output is normally high.  The IC drives it low for an interrupt.
	    m_VbusEvent_lvlChange.setEvent(IOVirtual::Event::EVENT_IO_EDGE_CHANGE_HtoL);
	    // Now inform listeners that have registered for a simple level
	    // change that a level change has occurred
		informListeners(&m_VbusEvent_lvlChange);
	 }

	 // this will cause the interrupt output pin to go back high again.
	 setBitField( &regval, MAKO_USB1_VBUS_RE_FE_INTRFLAG_BITFIELD,0 ); // clear the interrupt flag 
	 setBitField( &regval, MAKO_USB2_VBUS_RE_FE_INTRFLAG_BITFIELD,0 ); // clear the interrupt flag

	 // update the register image to reflect the new setting
	 m_MakoUSBCtrlParent->wrRegisterImage( MakoUSBConstants::USB2_TRANSCEIVER, MakoUSBConstants::MAKO_REG_FLAGS, regval );

	 // write the image to the IC
	 m_MakoUSBCtrlParent->wrRegisterUSB( MakoUSBConstants::USB2_TRANSCEIVER, MakoUSBConstants::MAKO_REG_FLAGS );
	 
	 vbusCheckVoltage();
	   
	}

	// }}}USR
}
// }}}RME

// {{{RME operation '~MakoVbusManager()'
MakoVbusManager::~MakoVbusManager( void )
{
	// {{{USR

	if( m_timerVirtual != 0 )
	{
	   //Stops timer.
	   m_timerVirtual->set(0);  //reset timer.

	   m_timerVirtual->unregisterListener(this,TimerVirtual::Event::TIMER_EVENT);
	}


	if( m_interruptPin != 0 )
	{
	   m_interruptPin->unregisterListener(this,IOVirtual::Event::EVENT_IO_EDGE_CHANGE_HtoL);
	}
	// }}}USR
}
// }}}RME

// {{{RME operation 'vbusCheckVoltage()'
void MakoVbusManager::vbusCheckVoltage( void )
{
	// {{{USR

	// used by the logic to only perform a spi write if necessary.
	bool MakoUSB1UpdateRequired = false;
	bool MakoUSB2UpdateRequired = false; 

	uint32_t usb1_ctrl_statRegData = 0; // current contents of Mako usb control/stat reg 1.
	uint32_t usb2_ctrl_statRegData = 0; // current contents of Mako usb control/stat reg 1.

	int Vbus1ValBit = 0;       // Mako control/stat register 1 vbus value
	int Vbus1DischargeBit = 0; // mako control/stat register 1 Vbus discharge bit
	int Vbus1LDOBit = 1;       // mako control/stat register 1 Vbus LDO bit

	int Vbus2ValBit = 0;       // Mako control/stat register 2 vbus value
	int Vbus2DischargeBit = 0; // mako control/stat register 2 Vbus discharge bit
	int Vbus2LDOBit = 1;       // mako control/stat register 2 Vbus LDO bit

	// read the current contents of the Mako USB 1 control status register via the spi bus
	usb1_ctrl_statRegData = m_MakoUSBCtrlParent->rdRegisterUSB(MakoUSBConstants::USB1_TRANSCEIVER, MakoUSBConstants::MAKO_REG_CTRL_STAT);

	// read the current contents of the Mako USB 2 control status register via the spi bus
	usb2_ctrl_statRegData = m_MakoUSBCtrlParent->rdRegisterUSB(MakoUSBConstants::USB2_TRANSCEIVER, MakoUSBConstants::MAKO_REG_CTRL_STAT);

	// read the state of these mako bits in the value read above.
	Vbus1ValBit          = getBitField( &usb1_ctrl_statRegData, MAKO_USB_VBUS_VAL_BITFIELD);
	Vbus1DischargeBit    = getBitField( &usb1_ctrl_statRegData, MAKO_USB_VBUS_DISCH_BITFIELD);
	Vbus1LDOBit          = getBitField( &usb1_ctrl_statRegData, MAKO_USB_VBUS_LDO_ON_BITFIELD);

	Vbus2ValBit          = getBitField( &usb2_ctrl_statRegData, MAKO_USB_VBUS_VAL_BITFIELD);
	Vbus2DischargeBit    = getBitField( &usb2_ctrl_statRegData, MAKO_USB_VBUS_DISCH_BITFIELD);
	Vbus2LDOBit          = getBitField( &usb2_ctrl_statRegData, MAKO_USB_VBUS_LDO_ON_BITFIELD);

	// **********************************
	// transceiver 1 discharge bit check
	// **********************************
	if( Vbus1ValBit == 1 )  // if Vbus > 4.2V
	{
	    // clear Vbus discharge bit if not already cleared.
	    // it needs to be zero, we'll only change and do spi update if absolutely necessary
	    if( Vbus1DischargeBit != 0 )
	    {
	      setBitField( &usb1_ctrl_statRegData, MAKO_USB_VBUS_DISCH_BITFIELD, 0);
	      MakoUSB1UpdateRequired = true;
	    }
	}
	else
	{
	    // set Vbus discharge bit if not already set.
	    if( Vbus1DischargeBit != 1 )
	    {
	      setBitField( &usb1_ctrl_statRegData, MAKO_USB_VBUS_DISCH_BITFIELD, 1);
	      MakoUSB1UpdateRequired = true;
	    }
	}


	// **********************************
	// transceiver 2 discharge bit check
	// **********************************
	if( Vbus2ValBit == 1 )  // if Vbus > 4.2V
	{
	    // clear Vbus discharge bit if not already cleared.
	    // it needs to be zero, we'll only change and do spi update if absolutely necessary
	    if( Vbus2DischargeBit != 0 )
	    {
	      setBitField( &usb2_ctrl_statRegData, MAKO_USB_VBUS_DISCH_BITFIELD, 0);
	      MakoUSB2UpdateRequired = true;
	    }
	}
	else
	{
	    // set Vbus discharge bit if not already set.
	    if( Vbus2DischargeBit != 1 )
	    {
	      setBitField( &usb2_ctrl_statRegData, MAKO_USB_VBUS_DISCH_BITFIELD, 1);
	      MakoUSB2UpdateRequired = true;
	    }
	}

	// **********************************
	// transceiver 1 overload check
	// **********************************
	if( Vbus1LDOBit == 1 )    // if Vbus enabled for this transceiver
	{
	   if( Vbus1ValBit != 1 ) // if Vbus value is too low
	   {
	      // set the transceiver mode back to device. This will result in LDO being
	     // disabled and disconnect of the external FET - overload detected!  
	     m_MakoUSBCtrlParent->setMode(MakoUSBConstants::USB_MODE_DEVICE,MakoUSBConstants::USB1_TRANSCEIVER);

	     MakoUSB1UpdateRequired = false;  // not necessary since setMode does all that's needed.
	     m_overcurrent1 = 1;
	   }
	   else  // Vbus value is normal.
	   {
	     m_overcurrent1 = 0;
	   }

	}

	// **********************************
	// transceiver 2 overload check
	// **********************************
	if( Vbus2LDOBit == 1 )    // if Vbus enabled for this transceiver
	{
	   if( Vbus2ValBit != 1 ) // if Vbus value is too low
	   {

	     // set the transceiver mode back to device. This will result in LDO being
	     // disabled and disconnect of the external FET - overload detected!  
	     m_MakoUSBCtrlParent->setMode(MakoUSBConstants::USB_MODE_DEVICE,MakoUSBConstants::USB2_TRANSCEIVER);

	     MakoUSB2UpdateRequired = false; // not necessary since setMode does all that's needed.

	     m_overcurrent2 = 1;
	   }
	   else  // Vbus value is normal.
	   {
	     m_overcurrent2 = 0;
	   }

	}

	// *****************************************
	// determine if any spi writes are necessary
	// *****************************************
	if( MakoUSB1UpdateRequired == true )
	{
	 
	   // write new image to the IC
	   m_MakoUSBCtrlParent->wrRegisterUSB(MakoUSBConstants::USB1_TRANSCEIVER, MakoUSBConstants::MAKO_REG_CTRL_STAT,usb1_ctrl_statRegData);
	}

	if( MakoUSB2UpdateRequired == true )
	{
	   // write new image to the IC
	   m_MakoUSBCtrlParent->wrRegisterUSB(MakoUSBConstants::USB2_TRANSCEIVER, MakoUSBConstants::MAKO_REG_CTRL_STAT,usb2_ctrl_statRegData);
	}

	// }}}USR
}
// }}}RME

// {{{RME operation 'vbusLaunchAutoCheck(IOVirtual *)'
void MakoVbusManager::vbusLaunchAutoCheck( IOVirtual * interruptPin )
{
	// {{{USR
	uint32_t wrData = 0;

	m_interruptPin = interruptPin;

	m_interruptPin->registerListener(this,IOVirtual::Event::EVENT_IO_EDGE_CHANGE_HtoL);


	// get current register image contents
	wrData = m_MakoUSBCtrlParent->rdRegisterImage( MakoUSBConstants::USB1_TRANSCEIVER, MakoUSBConstants::MAKO_REG_CTRL_STAT );
	  

	// set USB_INT_EN Vbus_Val_FE [D4] of USB interrupt enable register to a 1. Falling edge interrupt.
	setBitField( &wrData, MAKO_USB_VBUS_VAL_FE_INTR_BITFIELD, 1);


	// update the register image to reflect the new setting
	m_MakoUSBCtrlParent->wrRegisterImage( MakoUSBConstants::USB1_TRANSCEIVER, MakoUSBConstants::MAKO_REG_CTRL_STAT, wrData );

	// write the image to the IC
	m_MakoUSBCtrlParent->wrRegisterUSB( MakoUSBConstants::USB1_TRANSCEIVER, MakoUSBConstants::MAKO_REG_CTRL_STAT ); 


	// get current register image contents
	wrData = m_MakoUSBCtrlParent->rdRegisterImage( MakoUSBConstants::USB2_TRANSCEIVER, MakoUSBConstants::MAKO_REG_CTRL_STAT );
	  

	// set USB_INT_EN Vbus_Val_FE [D4] of USB interrupt enable register to a 1. Falling edge interrupt.
	setBitField( &wrData, MAKO_USB_VBUS_VAL_FE_INTR_BITFIELD, 1);

	// set USB_INT_EN Vbus_Val_FE [D12] of USB interrupt enable register to a 1. Falling edge interrupt.
	setBitField( &wrData, MAKO_USB_VBUS_VAL_RE_INTR_BITFIELD, 1);


	// update the register image to reflect the new setting
	m_MakoUSBCtrlParent->wrRegisterImage( MakoUSBConstants::USB2_TRANSCEIVER, MakoUSBConstants::MAKO_REG_CTRL_STAT, wrData );

	// write the image to the IC
	m_MakoUSBCtrlParent->wrRegisterUSB( MakoUSBConstants::USB2_TRANSCEIVER, MakoUSBConstants::MAKO_REG_CTRL_STAT ); 
	// }}}USR
}
// }}}RME

// {{{RME operation 'vbusLaunchAutoCheck(TimerVirtual *)'
void MakoVbusManager::vbusLaunchAutoCheck( TimerVirtual * scanTimerVirtual )
{
	// {{{USR
	m_timerVirtual = scanTimerVirtual;

	m_timerVirtual->set(0); // insure timer is stopped.

	m_timerVirtual->registerListener(this,TimerVirtual::Event::TIMER_EVENT);

	vbusCheckVoltage();

	// when timer expires, eventOccurred will execute vbusCheckVoltage();
	// and then it will set the timer to run again.
	m_timerVirtual->set(1); // start timer.
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
