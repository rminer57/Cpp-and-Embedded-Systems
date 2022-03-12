// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::data::interpolationData'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "interpolationData.h"
#endif

#include <HALtestLib_win32.h>
#include <interpolationData.h>
#include <dataPoint.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'interpolate(Integer)'
Integer interpolationData::interpolate( Integer freq )
{
	// {{{USR
	  //This code assumes (and requires) a list of (freq,value) points sorted in
	  //ascending order in the array by freq.
	  Integer interpVal = 0;
	  
	  //check to see if freq is in range of the freq set.
	  if( freq < dataPtr[0]->freq ) 
	  {
	    interpVal = dataPtr[0]->value;
	  }
	  
	  if( freq > dataPtr[dataArraySize - 1]->freq ) 
	  {
	    interpVal = dataPtr[dataArraySize - 1]->value;
	  }

	  //if interpVal is nonzero then freq in in range of the data set. 
	  if ( interpVal == 0)
	  {
	   // find indices to use
	   for(Integer i = 0; i < dataArraySize; i++)
	   { 
	     // check if frequency falls between two points
	     if((freq >= dataPtr[i]->freq) && (freq <= dataPtr[i+1]->freq))
	     {
	      // slope from i+1 to i = slope from passed in freq to i
	      interpVal= (((dataPtr[i+1]->value - dataPtr[i]->value)/(dataPtr[i+1]->freq - dataPtr[i]->freq))
	                  *(freq - dataPtr[i]->freq) + dataPtr[i]->value);
	     }
	   }
	   
	  }
	  
	  return interpVal;  

	// }}}USR
}
// }}}RME

// {{{RME operation 'interpolationData(dataPoint **,Integer)'
interpolationData::interpolationData( dataPoint * * setData, Integer numDataPoints )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	  // set pointer to data and size of size to respective elements
	  dataPtr = setData;
	  dataArraySize = numDataPoints;  

	// }}}USR
}
// }}}RME

// {{{RME operation 'set(Integer,Integer)'
void interpolationData::set( Integer reference, Integer value )
{
	// {{{USR
	  //search for the frequency in the array. If not found, do nothing
	  for(Integer i = 0; i < interpolationData::dataArraySize; i++)
	  {
	    if( dataPtr[i]->freq == reference )
	    {
		  dataPtr[i]->value = value;
		  break; 
	    }
	  }

	// }}}USR
}
// }}}RME

// {{{RME operation 'get(Integer,Integer,Integer)'
Integer interpolationData::get( Integer reference, Integer r2, Integer r3 )
{
	// {{{USR
	  //read back the value for the given reference.
	  return interpolate(reference);  

	// }}}USR
}
// }}}RME

// {{{RME operation '~interpolationData()'
interpolationData::~interpolationData( void )
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'get(Integer,Integer)'
Integer interpolationData::get( Integer reference, Integer r2 )
{
	// {{{USR
	  //read back the value for the given reference.
	  return interpolate(reference);  

	// }}}USR
}
// }}}RME

// {{{RME operation 'get(Integer)'
Integer interpolationData::get( Integer reference )
{
	// {{{USR
	  //read back the value for the given reference.
	  return interpolate(reference);  

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
