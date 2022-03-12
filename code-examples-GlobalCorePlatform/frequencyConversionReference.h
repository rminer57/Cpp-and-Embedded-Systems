// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer_subcomponents::mod_conversion::frequencyConversionReference'

#ifndef frequencyConversionReference_H
#define frequencyConversionReference_H

#ifdef PRAGMA
#pragma interface "frequencyConversionReference.h"
#endif

#include <rf_sequencer_comp.h>
#include <rfBaseClass.h>
#include <rf_audio_std_types.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'freqConversionRefInterface_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class frequencyConversionReference : public rfBaseClass
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
	// {{{RME classifier 'freqConversionRefInterface_t'
	enum freqConversionRefInterface_t
	{
		OP_SET_RF_STATE = 0
	  , OP_SET_LO
	};
	// }}}RME
	// {{{RME classAttribute 'frequency'
	Integer * frequency;
	// }}}RME

public:
	// {{{RME operation 'setLO(Integer,Integer)'
	virtual Integer setLO( Integer freq, Integer rfState );
	// }}}RME
	// {{{RME operation 'frequencyConversionReference(Integer)'
	frequencyConversionReference( Integer numberOfRfStates );
	// }}}RME
	// {{{RME operation 'rfInterface(Integer,Integer*,Integer)'
	Integer rfInterface( Integer opType, Integer * arguments, Integer numArguments );
	// }}}RME
	// {{{RME operation '~frequencyConversionReference()'
	virtual ~frequencyConversionReference( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'freqConversionRefInterface_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* frequencyConversionReference_H */

// }}}RME
