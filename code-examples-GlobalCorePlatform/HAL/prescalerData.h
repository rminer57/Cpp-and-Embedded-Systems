// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::data::prescaler::prescalerData'

#ifndef prescalerData_H
#define prescalerData_H

#ifdef PRAGMA
#pragma interface "prescalerData.h"
#endif

#include <HALtestLib_win32.h>
#include <interpolationData.h>
#include <rf_audio_std_types.h>
class dataPoint;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class prescalerData : public interpolationData
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
	// {{{RME classAttribute 'prescalerModulusData'
	static const Integer prescalerModulusData[];
	// }}}RME

public:
	// {{{RME operation 'getPrescalerModulus(Integer)'
	Integer getPrescalerModulus( Integer index );
	// }}}RME
	// {{{RME operation 'prescalerData(dataPoint**,Integer)'
	prescalerData( dataPoint * * setData, Integer dataSize );
	// }}}RME
	// {{{RME operation '~prescalerData()'
	~prescalerData( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* prescalerData_H */

// }}}RME
