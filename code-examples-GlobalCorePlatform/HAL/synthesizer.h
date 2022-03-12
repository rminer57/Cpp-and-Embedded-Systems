// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer_subcomponents::synthesizer::synthesizer'

#ifndef synthesizer_H
#define synthesizer_H

#ifdef PRAGMA
#pragma interface "synthesizer.h"
#endif

#include <HALtestLib_win32.h>
#include <rfBaseClass.h>
#include <rf_audio_std_types.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'synthInterface' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class synthesizer : public rfBaseClass
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
	// {{{RME classifier 'synthInterface'
	enum synthInterface
	{
		opSetRFState = 0
	  , opSetFrequency
	  , opGetFrequency
	  , opGetError
	};
	// }}}RME
	// {{{RME classAttribute 'frequency'
	Integer * frequency;
	// }}}RME

public:
	// {{{RME operation 'getError(Integer)'
	virtual Integer getError( Integer rfState );
	// }}}RME
	// {{{RME operation 'getFrequency(Integer)'
	virtual Integer getFrequency( Integer rfState );
	// }}}RME
	// {{{RME operation 'rfInterface(Integer,Integer*,Integer)'
	Integer rfInterface( Integer opType, Integer * arguments, Integer numArguments );
	// }}}RME
	// {{{RME operation 'setSynthFrequency(int32_t,int16_t,int32_t,int32_t)'
	virtual int32_t setSynthFrequency( int32_t freq, int16_t rfState, int32_t res, int32_t fref );
	// }}}RME
	// {{{RME operation 'synthesizer(Integer)'
	synthesizer( Integer numOfRfStates );
	// }}}RME
	// {{{RME operation '~synthesizer()'
	virtual ~synthesizer( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'synthInterface' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* synthesizer_H */

// }}}RME
