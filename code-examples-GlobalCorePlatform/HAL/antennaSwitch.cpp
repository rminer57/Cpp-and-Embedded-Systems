// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer_subcomponents::antennaSwitch::antennaSwitch'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "antennaSwitch.h"
#endif

#include <HALtestLib_win32.h>
#include <antennaSwitch.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
antennaSwitch::antennaSwitch( const antennaSwitch & rtg_arg )
	: rfBaseClass( rtg_arg )
	, STATE_TX( rtg_arg.STATE_TX )
	, STATE_RX( rtg_arg.STATE_RX )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
antennaSwitch & antennaSwitch::operator=( const antennaSwitch & rtg_arg )
{
	if( this != &rtg_arg )
	{
		rfBaseClass::operator=( rtg_arg );
		STATE_TX = rtg_arg.STATE_TX;
		STATE_RX = rtg_arg.STATE_RX;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'antennaSwitch()'
antennaSwitch::antennaSwitch( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation '~antennaSwitch()'
antennaSwitch::~antennaSwitch( void )
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'rfInterface(Integer,Integer*,Integer)'
Integer antennaSwitch::rfInterface( Integer opType, Integer * arguments, Integer numArguments )
{
	// {{{USR
	  // default return is 0
	  Integer returnVal = 0;
	  
	  switch(opType)
	  {
	    case OP_SET_RFSTATE:   // execute the setRFState method inherited from rf base class.
	    {
	      // arg0   = rfState
	      // arg1-3 = UNUSED
	      // returns previous rf state
	      returnVal = setRFState(arguments[0]);
	      break;
	    }
	    case OP_SET_AS:
	    {
	      // arg0 = state
	      // arg1 = UNUSED
	      // arg2 = UNUSED
	      // arg3 = UNUSED
	      // returns the previous antennaSwitch state
	      returnVal = setAS(arguments[0]);
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

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
