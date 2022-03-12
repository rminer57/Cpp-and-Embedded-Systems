// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer_subcomponents::discrete_device::discreteDeviceControl'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "discreteDeviceControl.h"
#endif

#include <HALtestLib_win32.h>
#include <discreteDeviceControl.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'discreteDeviceInterface_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'setDeviceState(int,int,int)'
int discreteDeviceControl::setDeviceState( int setting, int deviceId, int rfState )
{
	// {{{USR
	  int oldValue = currentDeviceSettings[deviceId][rfState];
	  currentDeviceSettings[deviceId][rfState] = setting;
	  return oldValue;

	// }}}USR
}
// }}}RME

// {{{RME operation 'discreteDeviceControl(int,int)'
discreteDeviceControl::discreteDeviceControl( int numberOfDevices, int numberOfRfStates )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	  numberDevices = numberOfDevices;
	  currentDeviceSettings = new int *[numberDevices];
	  for (int i = 0; i < numberDevices; i++)
	  {
	    currentDeviceSettings[i] = new int[numberOfRfStates];
	  }

	// }}}USR
}
// }}}RME

// {{{RME operation 'rfInterface(Integer,Integer *,Integer)'
Integer discreteDeviceControl::rfInterface( Integer opType, Integer * arguments, Integer numArguments )
{
	// {{{USR
	  //   default return is 0
	  int returnVal = 0; 
	  
	  switch(opType) 
	  {
	    case OP_SET_RF_STATE:
	    {
	      // arg0   = rfState
	      // arg1-3 = UNUSED
	      // returns previous rf state
	      returnVal = setRFState(arguments[0]);
	      break;
	    }
	    case OP_SET_DEVICE:
	    {
	      // arg0   = value
	      // arg1   = device Id number
	      // arg2   = rfState
	      // arg3   = UNUSED
	      // returns previous device state
	      returnVal = setDeviceState(arguments[0], arguments[1], arguments[2]);
	      break; 
	    }
	    default: 
	    {
	      break;
	    }
	  } 
	  
	  return returnVal;   

	// }}}USR
}
// }}}RME

// {{{RME operation '~discreteDeviceControl()'
discreteDeviceControl::~discreteDeviceControl( void )
{
	// {{{USR
	  for (Integer i = 0; i < numberDevices; i++)  
	  {
	    delete [] currentDeviceSettings[i];
	  }
	  delete [] currentDeviceSettings;

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'discreteDeviceInterface_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
