// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer_subcomponents::discrete_device::discreteDeviceControl'

#ifndef discreteDeviceControl_H
#define discreteDeviceControl_H

#ifdef PRAGMA
#pragma interface "discreteDeviceControl.h"
#endif

#include <rf_sequencer_comp.h>
#include <rfBaseClass.h>
#include <rf_audio_std_types.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'discreteDeviceInterface_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class discreteDeviceControl : public rfBaseClass
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
	// {{{RME classifier 'discreteDeviceInterface_t'
	enum discreteDeviceInterface_t
	{
		OP_SET_RF_STATE = 0
	  , OP_SET_DEVICE
	};
	// }}}RME

private:
	// {{{RME classAttribute 'currentDeviceSettings'
	int * * currentDeviceSettings;
	// }}}RME
	// {{{RME classAttribute 'numberDevices'
	int numberDevices;
	// }}}RME

public:
	// {{{RME operation 'setDeviceState(int,int,int)'
	virtual int setDeviceState( int setting, int deviceId, int rfState );
	// }}}RME
	// {{{RME operation 'discreteDeviceControl(int,int)'
	discreteDeviceControl( int numberOfDevices, int numberOfRfStates );
	// }}}RME
	// {{{RME operation 'rfInterface(Integer,Integer *,Integer)'
	Integer rfInterface( Integer opType, Integer * arguments, Integer numArguments );
	// }}}RME
	// {{{RME operation '~discreteDeviceControl()'
	virtual ~discreteDeviceControl( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'discreteDeviceInterface_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* discreteDeviceControl_H */

// }}}RME
