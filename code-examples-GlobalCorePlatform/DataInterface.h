// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer::data_interface::DataInterface'

#ifndef DataInterface_H
#define DataInterface_H

#ifdef PRAGMA
#pragma interface "DataInterface.h"
#endif

#include <rf_sequencer_comp.h>
#include <rf_audio_std_types.h>
#include <sequencerComponent.h>
class dataStore;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'dataInterface_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'arguments_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class DataInterface : public sequencerComponent
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
	// {{{RME classifier 'dataInterface_t'
	enum dataInterface_t
	{
		OP_GET_DATA = 0
	  , OP_SET_DATA
	};
	// }}}RME
	// {{{RME classifier 'arguments_t'
	enum arguments_t
	{
		ONE_ARGUMENT = 1
	  , TWO_ARGUMENTS = 2
	  , THREE_ARGUMENTS = 3
	};
	// }}}RME

private:
	// {{{RME classAttribute 'dataStoreTbl'
	dataStore * * dataStoreTbl;
	// }}}RME

public:
	// {{{RME operation 'DataInterface(dataStore**)'
	DataInterface( dataStore * * dataStores );
	// }}}RME
	// {{{RME operation 'rfInterface(Integer,Integer*,Integer)'
	Integer rfInterface( Integer opType, Integer * arguments, Integer numArguments );
	// }}}RME
	// {{{RME operation '~DataInterface()'
	~DataInterface( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'dataInterface_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'arguments_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* DataInterface_H */

// }}}RME
