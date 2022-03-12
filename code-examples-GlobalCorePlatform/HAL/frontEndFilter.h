// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer_subcomponents::frontEndFilter::frontEndFilter'

#ifndef frontEndFilter_H
#define frontEndFilter_H

#ifdef PRAGMA
#pragma interface "frontEndFilter.h"
#endif

#include <HALtestLib_win32.h>
#include <rfBaseClass.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'frontEndFilterInterface_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class frontEndFilter : public rfBaseClass
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
	// {{{RME classifier 'frontEndFilterInterface_t'
	enum frontEndFilterInterface_t
	{
		OP_SET_RFSTATE = 0
	  , OP_SET_FILTER
	};
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	frontEndFilter( const frontEndFilter & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	frontEndFilter & operator=( const frontEndFilter & rtg_arg );
	// }}}RME
	// {{{RME operation 'frontEndFilter()'
	frontEndFilter( void );
	// }}}RME
	// {{{RME operation '~frontEndFilter()'
	virtual ~frontEndFilter( void );
	// }}}RME
	// {{{RME operation 'setFilter(Integer,Integer)'
	virtual Integer setFilter( Integer value, Integer rfState ) = 0;
	// }}}RME
	// {{{RME operation 'rfInterface(Integer,Integer*,Integer)'
	Integer rfInterface( Integer opType, Integer * arguments, Integer numArguments );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'frontEndFilterInterface_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* frontEndFilter_H */

// }}}RME
