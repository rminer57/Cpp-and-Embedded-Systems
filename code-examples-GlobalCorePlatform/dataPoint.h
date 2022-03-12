// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::data::dataPoint'

#ifndef dataPoint_H
#define dataPoint_H

#ifdef PRAGMA
#pragma interface "dataPoint.h"
#endif

#include <rf_sequencer_comp.h>
#include <rf_audio_std_types.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class dataPoint
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
	// {{{RME classAttribute 'freq'
	Integer freq;
	// }}}RME
	// {{{RME classAttribute 'value'
	Integer value;
	// }}}RME
	// {{{RME operation 'dataPoint(Integer,Integer)'
	dataPoint( Integer f, Integer v );
	// }}}RME
	// {{{RME operation '~dataPoint()'
	~dataPoint( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* dataPoint_H */

// }}}RME
