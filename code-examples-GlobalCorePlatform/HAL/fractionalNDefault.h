// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::lvfractn::fractionalNDefault'

#ifndef fractionalNDefault_H
#define fractionalNDefault_H

#ifdef PRAGMA
#pragma interface "fractionalNDefault.h"
#endif

#include <HALtestLib_win32.h>
#include <rf_audio_std_types.h>
class bitfield;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>
// }}}USR
// }}}RME

class fractionalNDefault
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
	// {{{RME classAttribute 'oscillatorSensitivity'
	uint32_t oscillatorSensitivity;
	// }}}RME
	// {{{RME classAttribute 'defaultImages'
	uint32_t * * defaultImages;
	// }}}RME
	// {{{RME classAttribute 'tempCompData'
	uint32_t * tempCompData;
	// }}}RME
	// {{{RME classAttribute 'voltageMode'
	Integer voltageMode;
	// }}}RME
	// {{{RME classAttribute 'clockControl'
	uint32_t * clockControl;
	// }}}RME
	// {{{RME operation 'fractionalNDefault(uint32_t*,uint32_t**,uint32_t*,Integer,Integer)'
	fractionalNDefault( uint32_t * tempData, uint32_t * * defaultFractImages, uint32_t * clockCtrl, Integer oscilSensitivity, Integer voltMode );
	// }}}RME
	// {{{RME operation '~fractionalNDefault()'
	~fractionalNDefault( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* fractionalNDefault_H */

// }}}RME
