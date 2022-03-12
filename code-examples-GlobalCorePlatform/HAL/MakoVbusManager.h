// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoUSBSubsystem::VBUSmanager::MakoVbusManager'

#ifndef MakoVbusManager_H
#define MakoVbusManager_H

#ifdef PRAGMA
#pragma interface "MakoVbusManager.h"
#endif

#include <rf_sequencer_comp.h>
#include <IOVirtual.h>
#include <ListenerBase.h>
#include <MakoVbusEvent.h>
#include <NotifierBase.h>
class MakoUSBConstants;
class MakoUSBCtrl;
class TimerVirtual;
class bitfield;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class MakoVbusManager : public ListenerBase, public NotifierBase
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR
	friend class MakoUSBCtrl;
	friend class USBIOVirtualHandler;
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
	// {{{RME classAttribute 'm_timerVirtual'
	TimerVirtual * m_timerVirtual;
	// }}}RME
	// {{{RME classAttribute 'm_overcurrent1'
	static unsigned int m_overcurrent1;
	// }}}RME
	// {{{RME classAttribute 'm_MakoUSBCtrlParent'
	MakoUSBCtrl * m_MakoUSBCtrlParent;
	// }}}RME
	// {{{RME classAttribute 'm_overcurrent2'
	static unsigned int m_overcurrent2;
	// }}}RME
	// {{{RME classAttribute 'm_interruptPin'
	IOVirtual * m_interruptPin;
	// }}}RME
	// {{{RME classAttribute 'm_VbusEvent_lvlChange'
	MakoVbusEvent m_VbusEvent_lvlChange;
	// }}}RME

public:
	// {{{RME operation 'MakoVbusManager(MakoUSBCtrl *)'
	MakoVbusManager( MakoUSBCtrl * MakoUSBCtrlParent );
	// }}}RME
	// {{{RME operation 'eventOccurred(const EventBase * const)'
	void eventOccurred( const EventBase * const event );
	// }}}RME
	// {{{RME operation '~MakoVbusManager()'
	~MakoVbusManager( void );
	// }}}RME

protected:
	// {{{RME operation 'vbusCheckVoltage()'
	virtual void vbusCheckVoltage( void );
	// }}}RME
	// {{{RME operation 'vbusLaunchAutoCheck(IOVirtual *)'
	virtual void vbusLaunchAutoCheck( IOVirtual * interruptPin );
	// }}}RME
	// {{{RME operation 'vbusLaunchAutoCheck(TimerVirtual *)'
	virtual void vbusLaunchAutoCheck( TimerVirtual * scanTimerVirtual );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* MakoVbusManager_H */

// }}}RME
