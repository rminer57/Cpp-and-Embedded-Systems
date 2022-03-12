// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::data::k_m::KMData'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "KMData.h"
#endif

#include <HALtestLib_win32.h>
#include <KMData.h>
#include <dataPoint.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
#include "utility.h"

// }}}USR
// }}}RME
// {{{RME classifier 'kmScaleFactor_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'KMData(dataPoint**,dataPoint**,Integer,Integer[NUM_OF_KM_SCALE_FACTORS])'
KMData::KMData( dataPoint * * kDataTbl, dataPoint * * mDataTbl, Integer size, Integer kmSFs[ NUM_OF_KM_SCALE_FACTORS ] )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	  // set private data elements
	  kData = kDataTbl;
	  mData = mDataTbl;
	  arraySize = size;
	  kmScaleFactors = kmSFs;

	// }}}USR
}
// }}}RME

// {{{RME operation 'updateScaleFactor(Integer,Integer)'
Integer KMData::updateScaleFactor( Integer scaleFactorNum, Integer value )
{
	// {{{USR
	  // variable used to store previous scale factor value
	  Integer previousVal;

	  // check if scaleFactorNum is valid, else return 0
	  if((scaleFactorNum < NUM_OF_KM_SCALE_FACTORS) && (scaleFactorNum > 0))
	  {
	    previousVal = kmScaleFactors[scaleFactorNum - 1];
	    kmScaleFactors[scaleFactorNum - 1] = value;
	  }
	  else
	  {
	    previousVal = 0;
	  }

	  return previousVal;

	// }}}USR
}
// }}}RME

// {{{RME operation '~KMData()'
KMData::~KMData( void )
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'kmScaleFactor_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
