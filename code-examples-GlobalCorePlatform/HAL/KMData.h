// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::data::k_m::KMData'

#ifndef KMData_H
#define KMData_H

#ifdef PRAGMA
#pragma interface "KMData.h"
#endif

#include <HALtestLib_win32.h>
#include <dataStore.h>
#include <rf_audio_std_types.h>
class dataPoint;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#define NUM_OF_KM_SCALE_FACTORS 3

// }}}USR
// }}}RME
// {{{RME classifier 'kmScaleFactor_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class KMData : public dataStore
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
	// {{{RME classifier 'kmScaleFactor_t'
	enum kmScaleFactor_t
	{
		SCALE_FACTOR_1 = 0
	  , SCALE_FACTOR_2
	  , SCALE_FACTOR_3
	};
	// }}}RME

private:
	// {{{RME classAttribute 'kData'
	dataPoint * * kData;
	// }}}RME
	// {{{RME classAttribute 'mData'
	dataPoint * * mData;
	// }}}RME
	// {{{RME classAttribute 'arraySize'
	Integer arraySize;
	// }}}RME
	// {{{RME classAttribute 'kmScaleFactors'
	Integer * kmScaleFactors;
	// }}}RME

public:
	// {{{RME operation 'KMData(dataPoint**,dataPoint**,Integer,Integer[NUM_OF_KM_SCALE_FACTORS])'
	KMData( dataPoint * * kDataTbl, dataPoint * * mDataTbl, Integer size, Integer kmSFs[ NUM_OF_KM_SCALE_FACTORS ] );
	// }}}RME
	// {{{RME operation 'updateScaleFactor(Integer,Integer)'
	Integer updateScaleFactor( Integer scaleFactorNum, Integer value );
	// }}}RME
	// {{{RME operation 'get(Integer,Integer)'
	virtual Integer get( Integer frequency, Integer powerLevel ) = 0;
	// }}}RME
	// {{{RME operation '~KMData()'
	~KMData( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'kmScaleFactor_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* KMData_H */

// }}}RME
