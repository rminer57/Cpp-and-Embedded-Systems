// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::data::dataStore'

#ifndef dataStore_H
#define dataStore_H

#ifdef PRAGMA
#pragma interface "dataStore.h"
#endif

#include <rf_sequencer_comp.h>
#include <rf_audio_std_types.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class dataStore
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
	// {{{RME operation 'set(Integer,Integer)'
	virtual void set( Integer reference, Integer value ) = 0;
	// }}}RME
	// {{{RME operation 'get(Integer)'
	virtual Integer get( Integer ref ) = 0;
	// }}}RME
	// {{{RME operation 'get(Integer,Integer)'
	virtual Integer get( Integer ref1, Integer ref2 ) = 0;
	// }}}RME
	// {{{RME operation 'get(Integer,Integer,Integer)'
	virtual Integer get( Integer ref1, Integer ref2, Integer ref3 ) = 0;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* dataStore_H */

// }}}RME
