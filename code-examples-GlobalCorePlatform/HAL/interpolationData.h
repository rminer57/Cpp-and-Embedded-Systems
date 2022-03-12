// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::data::interpolationData'

#ifndef interpolationData_H
#define interpolationData_H

#ifdef PRAGMA
#pragma interface "interpolationData.h"
#endif

#include <HALtestLib_win32.h>
#include <dataStore.h>
#include <rf_audio_std_types.h>
class dataPoint;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class interpolationData : public dataStore
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
	// {{{RME classAttribute 'dataPtr'
	dataPoint * * dataPtr;
	// }}}RME
	// {{{RME classAttribute 'dataArraySize'
	Integer dataArraySize;
	// }}}RME

public:
	// {{{RME operation 'interpolate(Integer)'
	Integer interpolate( Integer freq );
	// }}}RME
	// {{{RME operation 'interpolationData(dataPoint **,Integer)'
	interpolationData( dataPoint * * setData, Integer numDataPoints );
	// }}}RME
	// {{{RME operation 'set(Integer,Integer)'
	void set( Integer reference, Integer value );
	// }}}RME
	// {{{RME operation 'get(Integer,Integer,Integer)'
	Integer get( Integer reference, Integer r2, Integer r3 );
	// }}}RME
	// {{{RME operation '~interpolationData()'
	~interpolationData( void );
	// }}}RME
	// {{{RME operation 'get(Integer,Integer)'
	Integer get( Integer reference, Integer r2 );
	// }}}RME
	// {{{RME operation 'get(Integer)'
	Integer get( Integer reference );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* interpolationData_H */

// }}}RME
