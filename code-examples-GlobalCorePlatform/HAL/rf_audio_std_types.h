// {{{RME classifier 'Logical View::HAL Instantiation::Standard Includes::rf_audio_std_types'

#ifndef rf_audio_std_types_H
#define rf_audio_std_types_H

#ifdef PRAGMA
#pragma interface "rf_audio_std_types.h"
#endif

#include <HALtestLib_win32.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>

#define NULL 0
#define EOS 0

//Setup UML standard types

#ifdef OMAP_HALI_C55
typedef signed long int Integer;
typedef unsigned long int UInteger;
#else
typedef int Integer;
typedef unsigned int UInteger;
#endif

typedef bool Boolean;
typedef unsigned char Byte;
typedef unsigned int size_t;

/*---------------------- STRUCTURE/UNION DATA TYPES --------------------------*/

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* rf_audio_std_types_H */

// }}}RME
