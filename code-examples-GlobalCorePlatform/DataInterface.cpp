// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer::data_interface::DataInterface'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "DataInterface.h"
#endif

#include <rf_sequencer_comp.h>
#include <DataInterface.h>
#include <dataStore.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'dataInterface_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'arguments_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'DataInterface(dataStore**)'
DataInterface::DataInterface( dataStore * * dataStores )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	  // set private data element to table pointer passed in
	  dataStoreTbl = dataStores;

	// }}}USR
}
// }}}RME

// {{{RME operation 'rfInterface(Integer,Integer*,Integer)'
Integer DataInterface::rfInterface( Integer opType, Integer * arguments, Integer numArguments )
{
	// {{{USR
	  // default return is 0
	  Integer returnVal = 0;
	  
	  switch(opType)
	  {
	    case OP_GET_DATA:
	    {
	      // arg0   = dataStore number
	      // arg1-n = arguments used in get operation
	      // returns value from dataStore
	      switch(numArguments - 1)
	      {
	        case ONE_ARGUMENT:
	        {
	          returnVal = dataStoreTbl[arguments[0]]->get(arguments[1]);
	          break;
	        }
	        case TWO_ARGUMENTS:
	        {
	          returnVal = dataStoreTbl[arguments[0]]->get(arguments[1], arguments[2]);
	          break;
	        }
	        case THREE_ARGUMENTS:
	        {
	          returnVal = dataStoreTbl[arguments[0]]->get(arguments[1], arguments[2], arguments[3]);
	          break;
	        }
	      }
	      break;
	    }
	    case OP_SET_DATA:
	    {
	      // arg0 = dataStore number
	      // arg1 = reference
	      // arg2 = value
	      dataStoreTbl[arguments[0]]->set(arguments[1], arguments[2]);
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

// {{{RME operation '~DataInterface()'
DataInterface::~DataInterface( void )
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'dataInterface_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'arguments_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
