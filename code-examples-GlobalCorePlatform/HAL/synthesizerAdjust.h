// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer_subcomponents::synthesizer::synthesizerAdjust'

#ifndef synthesizerAdjust_H
#define synthesizerAdjust_H

#ifdef PRAGMA
#pragma interface "synthesizerAdjust.h"
#endif

#include <HALtestLib_win32.h>
#include <rfBaseClass.h>
#include <rf_audio_std_types.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'synthAdjustInterface' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class synthesizerAdjust : public rfBaseClass
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
	// {{{RME classifier 'synthAdjustInterface'
	enum synthAdjustInterface
	{
		opSetRFState = 0
	  , opSetWarp
	};
	// }}}RME

private:
	// {{{RME classAttribute 'currentWarp'
	Integer * currentWarp;
	// }}}RME

public:
	// {{{RME operation 'rfInterface(Integer,Integer*,Integer)'
	Integer rfInterface( Integer opType, Integer * arguments, Integer numArguments );
	// }}}RME
	// {{{RME operation 'setWarp(Integer,Integer)'
	virtual Integer setWarp( Integer warp, Integer rfState );
	// }}}RME
	// {{{RME operation 'synthesizerAdjust(Integer)'
	synthesizerAdjust( Integer numOfRfStates );
	// }}}RME
	// {{{RME operation '~synthesizerAdjust()'
	virtual ~synthesizerAdjust( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'synthAdjustInterface' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* synthesizerAdjust_H */

// }}}RME
