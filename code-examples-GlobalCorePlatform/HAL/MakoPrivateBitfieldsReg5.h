// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoPrivateHeaders::MakoPrivateBitfieldsReg5'

#ifndef MakoPrivateBitfieldsReg5_H
#define MakoPrivateBitfieldsReg5_H

#ifdef PRAGMA
#pragma interface "MakoPrivateBitfieldsReg5.h"
#endif

#include <HALtestLib_win32.h>
#include <bitfield.h>
#include <rf_audio_std_types.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

#include <MakoPrivate.h>

// *******************************************************************************************************
//                      MAKO Test register specific bitfield macros
// *******************************************************************************************************

// MAKO bits:            |31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
// Field:                |RW| Address|<--  MAKO_SUBCOMP_DATA -- >                                              |          

// D31       RW:       Read/~Write 
// D30 - D28 Address:  Address of this Mako register 
// D27 - D0  MAKO_SUBCOMP_DATA: subcomponent field

// *******************************************************************************************************
#define MAKO_TEST_REGISTER_ADDR 5    // Register base for this sub-component within Mako
 

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* MakoPrivateBitfieldsReg5_H */

// }}}RME
