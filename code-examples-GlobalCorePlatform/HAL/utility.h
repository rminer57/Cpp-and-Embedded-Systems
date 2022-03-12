// {{{RME classifier 'Logical View::HAL Instantiation::Standard Includes::utility'

#ifndef utility_H
#define utility_H

#ifdef PRAGMA
#pragma interface "utility.h"
#endif

#include <HALtestLib_win32.h>
#include <rf_audio_std_types.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class utility
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
	// {{{RME operation 'rev_bits(uint32_t,uint32_t)'
	static uint32_t rev_bits( uint32_t data_to_reverse, uint32_t number_of_bits );
	// }}}RME
	// {{{RME operation 'minInt(Integer,Integer)'
	static Integer minInt( Integer int1, Integer int2 );
	// }}}RME
	// {{{RME operation 'maxInt(Integer,Integer)'
	static Integer maxInt( Integer int1, Integer int2 );
	// }}}RME
	// {{{RME operation 'check_range(Integer,Integer,Integer)'
	static Boolean check_range( Integer freq_value, Integer ref_freq_value, Integer percent );
	// }}}RME
	// {{{RME operation 'square_root(uint32_t)'
	static uint16_t square_root( uint32_t val );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* utility_H */

// }}}RME
