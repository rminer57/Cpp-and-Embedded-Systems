// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoUSBSubsystem::MakoUSBCtrl'

#ifndef MakoUSBCtrl_H
#define MakoUSBCtrl_H

#ifdef PRAGMA
#pragma interface "MakoUSBCtrl.h"
#endif

#include <HALtestLib_win32.h>
#include <IOVirtual.h>
#include <ListenerBase.h>
#include <MakoFETManager.h>
#include <MakoUSBConstants.h>
class Mako;
class MakoPrivateBitfieldsReg4;
class MakoUSBEvents;
class USBEventHandlerBase;
class USBIOVirtualHandler;
class bitfield;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>

#define MAKOUSB_CTRL_STAT_DEFAULT 0x00000000
#define MAKOUSB_CTRL_STAT_DEFAULT 0x00002401
// }}}USR
// }}}RME

class MakoUSBCtrl : public ListenerBase
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
	// {{{RME classAttribute 'm_MakoParent'
	Mako * m_MakoParent;
	// }}}RME
	// {{{RME classAttribute 'm_USB1mode'
	int m_USB1mode;
	// }}}RME
	// {{{RME classAttribute 'm_IOVirtualGPIO'
	IOVirtual * m_IOVirtualGPIO;
	// }}}RME
	// {{{RME classAttribute 'm_userdefinedUSBEventHandlerClass'
	USBEventHandlerBase * m_userdefinedUSBEventHandlerClass;
	// }}}RME
	// {{{RME classAttribute 'm_USB2mode'
	int m_USB2mode;
	// }}}RME
	// {{{RME classAttribute 'm_RegImageUSB1_CTRL_STAT'
	uint32_t m_RegImageUSB1_CTRL_STAT;
	// }}}RME
	// {{{RME classAttribute 'm_RegImageUSB2_CTRL_STAT'
	uint32_t m_RegImageUSB2_CTRL_STAT;
	// }}}RME
	// {{{RME classAttribute 'm_RegImageUSB1_INTR_EN'
	uint32_t m_RegImageUSB1_INTR_EN;
	// }}}RME
	// {{{RME classAttribute 'm_RegImageUSB2_INTR_EN'
	uint32_t m_RegImageUSB2_INTR_EN;
	// }}}RME
	// {{{RME classAttribute 'm_RegImageUSB_INTR_FLAGS'
	uint32_t m_RegImageUSB_INTR_FLAGS;
	// }}}RME
	// {{{RME classAttribute 'm_IOVirtualSuspend1'
	IOVirtual * m_IOVirtualSuspend1;
	// }}}RME
	// {{{RME classAttribute 'm_IOVirtualPwrEnable1'
	IOVirtual * m_IOVirtualPwrEnable1;
	// }}}RME
	// {{{RME classAttribute 'm_IOVirtualVbusDetect1'
	IOVirtual * m_IOVirtualVbusDetect1;
	// }}}RME
	// {{{RME classAttribute 'm_IOVirtualDevPUEN1'
	IOVirtual * m_IOVirtualDevPUEN1;
	// }}}RME
	// {{{RME classAttribute 'm_IOVirtualDevPUEN2'
	IOVirtual * m_IOVirtualDevPUEN2;
	// }}}RME
	// {{{RME classAttribute 'm_IOVirtualPwrEnable2'
	IOVirtual * m_IOVirtualPwrEnable2;
	// }}}RME
	// {{{RME classAttribute 'm_IOVirtualSuspend2'
	IOVirtual * m_IOVirtualSuspend2;
	// }}}RME
	// {{{RME classAttribute 'm_IOVirtualVbusDetect2'
	IOVirtual * m_IOVirtualVbusDetect2;
	// }}}RME
	// {{{RME classAttribute 'm_FETmanager'
	MakoFETManager * m_FETmanager;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	MakoUSBCtrl( const MakoUSBCtrl & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	MakoUSBCtrl & operator=( const MakoUSBCtrl & rtg_arg );
	// }}}RME
	// {{{RME operation 'MakoUSBCtrl(Mako *,uint32_t,uint32_t)'
	MakoUSBCtrl( Mako * parent = 0, uint32_t usb1_int_en_init = MakoUSBConstants::MAKO_INT_EN_DEFAULT, uint32_t usb2_int_en_init = MakoUSBConstants::MAKO_INT_EN_DEFAULT );
	// }}}RME
	// {{{RME operation '~MakoUSBCtrl()'
	~MakoUSBCtrl( void );
	// }}}RME
	// {{{RME operation 'getMode(int)'
	int getMode( int transceiver );
	// }}}RME
	// {{{RME operation 'registerEventHandler(USBEventHandlerBase *,IOVirtual *,unsigned int)'
	void registerEventHandler( USBEventHandlerBase * event_handler_object, IOVirtual * gpio_device, unsigned int event_change_type = IOVirtual::Event::EVENT_IO_EDGE_CHANGE_LtoH );
	// }}}RME
	// {{{RME operation 'getCurrentLimit(int)'
	int getCurrentLimit( int transceiver );
	// }}}RME
	// {{{RME operation 'getPullUp(int)'
	int getPullUp( int transceiver );
	// }}}RME
	// {{{RME operation 'getPullDn(int)'
	int getPullDn( int transceiver );
	// }}}RME
	// {{{RME operation 'getPowerEnable(int)'
	int getPowerEnable( int transceiver );
	// }}}RME
	// {{{RME operation 'getSpeed(int)'
	int getSpeed( int transceiver );
	// }}}RME
	// {{{RME operation 'getSuspend(int)'
	int getSuspend( int transceiver );
	// }}}RME
	// {{{RME operation 'getVbusDischarge(int)'
	int getVbusDischarge( int transceiver );
	// }}}RME
	// {{{RME operation 'getVbusIMon(int)'
	int getVbusIMon( int transceiver );
	// }}}RME
	// {{{RME operation 'getVbusVal(int)'
	int getVbusVal( int transceiver );
	// }}}RME
	// {{{RME operation 'getIntrFlagVbusVal(int)'
	int getIntrFlagVbusVal( int transceiver );
	// }}}RME
	// {{{RME operation 'getIntrFlagBSessEnd(int)'
	int getIntrFlagBSessEnd( int transceiver );
	// }}}RME
	// {{{RME operation 'selectPhyIF(bool,int)'
	void selectPhyIF( bool state, int transceiver );
	// }}}RME
	// {{{RME operation 'setIntrEnVbus(int,int)'
	void setIntrEnVbus( int state, int transceiver );
	// }}}RME

protected:
	// {{{RME operation 'clrIntrFlagsVbus(int)'
	void clrIntrFlagsVbus( int transceiver );
	// }}}RME

public:
	// {{{RME operation 'setMode(int,int)'
	void setMode( int newhost_device_mode, int transceiver );
	// }}}RME
	// {{{RME operation 'setVbusLDO(int,int)'
	void setVbusLDO( int state, int transceiver );
	// }}}RME
	// {{{RME operation 'setPullDn(int,int)'
	void setPullDn( int state, int transceiver );
	// }}}RME
	// {{{RME operation 'setPullUp(int,int)'
	void setPullUp( int state, int transceiver );
	// }}}RME
	// {{{RME operation 'setSpeed(int,int)'
	void setSpeed( int state, int transceiver );
	// }}}RME
	// {{{RME operation 'setSuspend(int,int)'
	void setSuspend( int state, int transceiver );
	// }}}RME
	// {{{RME operation 'setVbusDischarge(int,int)'
	void setVbusDischarge( int state, int transceiver );
	// }}}RME
	// {{{RME operation 'setCurrentLimit(bool,int)'
	void setCurrentLimit( bool state, int transceiver );
	// }}}RME
	// {{{RME operation 'eventOccurred(const EventBase * const )'
	void eventOccurred( const EventBase * const event );
	// }}}RME

protected:
	// {{{RME operation 'pgmPwrUpDefault(int)'
	void pgmPwrUpDefault( int transceiver );
	// }}}RME

public:
	// {{{RME operation 'setVbusIMon(int,int)'
	void setVbusIMon( int state, int transceiver );
	// }}}RME
	// {{{RME operation 'setPowerEnable(int,int)'
	void setPowerEnable( int state, int transceiver );
	// }}}RME
	// {{{RME operation 'wrRegisterUSB(int,int)'
	void wrRegisterUSB( int transceiver, int reg_sel );
	// }}}RME
	// {{{RME operation 'wrRegisterImage(int,int,uint32_t)'
	void wrRegisterImage( int transceiver, int reg_sel, uint32_t newdata );
	// }}}RME
	// {{{RME operation 'rdRegisterUSB(int,int)'
	uint32_t rdRegisterUSB( int transceiver, int reg_sel );
	// }}}RME
	// {{{RME operation 'rdRegisterImage(int,int)'
	uint32_t rdRegisterImage( int transceiver, int reg_sel );
	// }}}RME
	// {{{RME operation 'getIOVirtualPin(int,int,IOVirtual *)'
	IOVirtual * getIOVirtualPin( int transceiver, int whichpin, IOVirtual * VbusDetIOVirtual );
	// }}}RME
	// {{{RME operation 'getIOVirtualPin(int,int)'
	IOVirtual * getIOVirtualPin( int transceiver, int whichpin );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* MakoUSBCtrl_H */

// }}}RME
