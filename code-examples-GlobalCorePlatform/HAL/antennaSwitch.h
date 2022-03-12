// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer_subcomponents::antennaSwitch::antennaSwitch'

#ifndef antennaSwitch_H
#define antennaSwitch_H

#ifdef PRAGMA
#pragma interface "antennaSwitch.h"
#endif

#include <HALtestLib_win32.h>
#include <rfBaseClass.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'OP_SET_RFSTATE'
#define OP_SET_RFSTATE 0
// }}}RME

// {{{RME classAttribute 'OP_SET_AS'
#define OP_SET_AS 1
// }}}RME

class antennaSwitch : public rfBaseClass
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
	// {{{RME classAttribute 'STATE_TX'
	Integer STATE_TX;
	// }}}RME
	// {{{RME classAttribute 'STATE_RX'
	Integer STATE_RX;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	antennaSwitch( const antennaSwitch & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	antennaSwitch & operator=( const antennaSwitch & rtg_arg );
	// }}}RME
	// {{{RME operation 'antennaSwitch()'
	antennaSwitch( void );
	// }}}RME
	// {{{RME operation '~antennaSwitch()'
	virtual ~antennaSwitch( void );
	// }}}RME
	// {{{RME operation 'setAS(Integer)'
	virtual Integer setAS( Integer state ) = 0;
	// }}}RME
	// {{{RME operation 'rfInterface(Integer,Integer*,Integer)'
	Integer rfInterface( Integer opType, Integer * arguments, Integer numArguments );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* antennaSwitch_H */

// }}}RME
