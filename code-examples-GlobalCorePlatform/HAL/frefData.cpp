// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::data::fref::frefData'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "frefData.h"
#endif

#include <HALtestLib_win32.h>
#include <frefData.h>
#include <dataPoint.h>
#include <interpolationData.h>
#include <utility.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'FREQUENCY_CHECK_PERCENTAGE'
const Integer frefData::FREQUENCY_CHECK_PERCENTAGE( 2 );
// }}}RME

// {{{RME operation 'frefData(dataPoint**,Integer)'
frefData::frefData( dataPoint * * freqData, Integer numOfRefFreqs )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	  frequencyData        = freqData;
	  numberOfRefFreqs     = numOfRefFreqs;

	// }}}USR
}
// }}}RME

// {{{RME operation 'get(Integer)'
Integer frefData::get( Integer reference )
{
	// {{{USR
	  //----------------------------- LOCAL VARIABLES ------------------------------
	  Integer refFreq;
	  
	  // set reference frequency to default (assumed to be last reference frequency in array passed in)
	  refFreq = frequencyData[numberOfRefFreqs - 1]->freq;

	  // do a range check of carrier freq (ie. reference) with reference frequency (freq in dataPoint) 
	  // and fmult frequency (value in dataPoint).  If both pass, set refFreq.
	  for(Integer i = 0; i < (numberOfRefFreqs - 1); i++)
	  {
	    if(((utility::check_range(reference, frequencyData[i]->freq, FREQUENCY_CHECK_PERCENTAGE)) 
	      && (utility::check_range(reference, frequencyData[i]->value, FREQUENCY_CHECK_PERCENTAGE))) == true)
	    {
	      refFreq = frequencyData[i]->freq;
	      break;
	    }
	  } 

	  return refFreq;  

	// }}}USR
}
// }}}RME

// {{{RME operation '~frefData()'
frefData::~frefData( void )
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
