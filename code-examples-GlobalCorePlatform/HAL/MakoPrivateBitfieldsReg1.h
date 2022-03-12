// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoPrivateHeaders::MakoPrivateBitfieldsReg1'

#ifndef MakoPrivateBitfieldsReg1_H
#define MakoPrivateBitfieldsReg1_H

#ifdef PRAGMA
#pragma interface "MakoPrivateBitfieldsReg1.h"
#endif

#include <HALtestLib_win32.h>
#include <bitfield.h>
#include <rf_audio_std_types.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <MakoPrivate.h>

// *******************************************************************************************************
//                      MAKO DC Regulator Device specific bitfield macros
// *******************************************************************************************************

// MAKO bits:            |31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
// Field:                |RW| Address|<--  MAKO_SUBCOMP_DATA -- >                                              |          
//                                   | dontcares |V9SEL|V6SEL|x | V3_VSEL| V2_VSEL|SW2_VSEL|SW1VT|SWCLK|x x x x|
// D31       RW:       Read/~Write 
// D30 - D28 Address:  Address of this Mako register, $001 for DC regulator component 
// D27 - D0  MAKO_SUBCOMP_DATA: subcomponent field

// D27 - D24 X   don't care bits
// D23 - D22 V9_VSEL_BITFIELD
// D21 - D20 V6_VSEL_BITFIELD
// D19       X   don't care bit
// D18 - D16 V3_VSEL_BITFIELD
// D15 - D13 V2_VSEL_BITFIELD
// D12 - D10 SW2_VSEL_BITFIELD
// D9  - D7  SW1_VTRIM_BITFIELD
// D6 - D4   SW_CLKDIV_BITFIELD
// D3 - D0   X   don't care bits		

// *******************************************************************************************************
		
#define MAKO_DCREG_REGISTER_ADDR 001    // Register base for this sub-component within Mako

// DC Regulator register $001 D23-D22 V9_VSEL
#define MAKO_DCREG_V9_VSEL_FIELD_LSBBIT_22 22

// DC Regulator register $001 D21-D20 V6_VSEL
#define MAKO_DCREG_V6_VSEL_FIELD_LSBBIT_20 20

// DC Regulator register $001 D18-D16 V3_VSEL
#define MAKO_DCREG_V3_VSEL_FIELD_LSBBIT_16 16

// DC Regulator register $001 D15-D13 V2_VSEL
#define MAKO_DCREG_V2_VSEL_FIELD_LSBBIT_13 13

// DC Regulator register $001 D12-D10 SW2_VSEL
#define MAKO_DCREG_SW2_VSEL_FIELD_LSBBIT_10 10

// DC Regulator register $001 D9-D7 SW1_VTRIM
#define MAKO_DCREG_SW1_VTRIM_FIELD_LSBBIT_7 7

// DC Regulator register $001 D6-D4 SW_CLKDIV
#define MAKO_DCREG_SW_CLKDIV_MAXVAL 7

#define MAKO_DCREG_SW_CLKDIV_FIELD_LSBBIT_4 4



defineBitField( MAKO_DCREG_V9_VSEL_BITFIELD ,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_DCREG_V9_VSEL_FIELD_LSBBIT_22, MAKO_BITFIELD_SIZE_2);

defineBitField( MAKO_DCREG_V6_VSEL_BITFIELD ,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_DCREG_V6_VSEL_FIELD_LSBBIT_20, MAKO_BITFIELD_SIZE_2);

defineBitField( MAKO_DCREG_V3_VSEL_BITFIELD ,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_DCREG_V3_VSEL_FIELD_LSBBIT_16, MAKO_BITFIELD_SIZE_3);

defineBitField( MAKO_DCREG_V2_VSEL_BITFIELD ,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_DCREG_V2_VSEL_FIELD_LSBBIT_13, MAKO_BITFIELD_SIZE_3);

defineBitField( MAKO_DCREG_SW2_VSEL_BITFIELD ,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_DCREG_SW2_VSEL_FIELD_LSBBIT_10, MAKO_BITFIELD_SIZE_3);

defineBitField( MAKO_DCREG_SW1_VTRIM_BITFIELD ,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_DCREG_SW1_VTRIM_FIELD_LSBBIT_7, MAKO_BITFIELD_SIZE_3);

defineBitField( MAKO_DCREG_SW_CLKDIV_BITFIELD ,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_DCREG_SW_CLKDIV_FIELD_LSBBIT_4, MAKO_BITFIELD_SIZE_3);



// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* MakoPrivateBitfieldsReg1_H */

// }}}RME
