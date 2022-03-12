// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::data::fref::frefData'

#ifndef frefData_H
#define frefData_H

#ifdef PRAGMA
#pragma interface "frefData.h"
#endif

#include <HALtestLib_win32.h>
#include <dataStore.h>
#include <rf_audio_std_types.h>
class dataPoint;
class interpolationData;
class utility;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class frefData : public dataStore
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
	// {{{RME classAttribute 'frequencyData'
	dataPoint * * frequencyData;
	// }}}RME
	// {{{RME classAttribute 'numberOfRefFreqs'
	Integer numberOfRefFreqs;
	// }}}RME
	// {{{RME classAttribute 'FREQUENCY_CHECK_PERCENTAGE'
	static const Integer FREQUENCY_CHECK_PERCENTAGE;
	// }}}RME

public:
	// {{{RME operation 'frefData(dataPoint**,Integer)'
	frefData( dataPoint * * freqData, Integer numOfRefFreqs );
	// }}}RME
	// {{{RME operation 'get(Integer)'
	Integer get( Integer reference );
	// }}}RME
	// {{{RME operation '~frefData()'
	~frefData( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* frefData_H */

// }}}RME
