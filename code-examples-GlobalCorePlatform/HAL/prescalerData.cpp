// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::data::prescaler::prescalerData'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "prescalerData.h"
#endif

#include <HALtestLib_win32.h>
#include <prescalerData.h>
#include <dataPoint.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'prescalerModulusData'
const Integer prescalerData::prescalerModulusData[] = { 0, 4, 8, 12, 16, 1, 32, 0};
// }}}RME

// {{{RME operation 'getPrescalerModulus(Integer)'
Integer prescalerData::getPrescalerModulus( Integer index )
{
	// {{{USR
	  return prescalerModulusData[index];  

	// }}}USR
}
// }}}RME

// {{{RME operation 'prescalerData(dataPoint**,Integer)'
prescalerData::prescalerData( dataPoint * * setData, Integer dataSize )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	  : interpolationData(setData, dataSize)  

	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation '~prescalerData()'
prescalerData::~prescalerData( void )
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
