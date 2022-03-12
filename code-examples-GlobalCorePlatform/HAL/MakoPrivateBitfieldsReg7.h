// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoPrivateHeaders::MakoPrivateBitfieldsReg7'

#ifndef MakoPrivateBitfieldsReg7_H
#define MakoPrivateBitfieldsReg7_H

#ifdef PRAGMA
#pragma interface "MakoPrivateBitfieldsReg7.h"
#endif

#include <HALtestLib_win32.h>
#include <bitfield.h>
#include <rf_audio_std_types.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <MakoPrivate.h>

// *******************************************************************************************************
//                      MAKO Analog to Digital Device specific bitfield macros
// *******************************************************************************************************

// ADC Mako Sub-Component
//MAKO Address:       |==|31|30|29|28|27|26|25|24|==|23|22 |21|20|19|18|17|16|15|14|13|12|11|10| 9| 8|==| 7| 6| 5| 4| 3| 2| 1| 0|=|
// Field:                |RW| Address|  <-AD_CH->|ADEN |ASC|    don't care bits    |<---------ADC_DATA------------>|don't care bits|

// RW:      Read/~Write D31
// Address: Address of this Mako register, $111 for ADC  D30 - D28
// AD_CH:   A/D device 0 - 10 D27 - D24
// ADEN:    A/D enable/disable, 1 = enable, 0 disables. default on powerup is 0 D23
// ASC      A/D start conversion, 1 = start conversion on all devices, default at 0.  D22
//          Data sheet implies that ASC is held to the 1 state, until conversion completes. Then
//          it is cleared by the hardware.
// AD_DATA: A/D data, result of conversion. D21 - D4, 10 bit field
		
		
#define ADC_REGISTER_ADDR 7    // Register base for this sub-component within Mako


// the mako ADC channel select field is D27 - D24, bitfield macro requires LSB
#define MAKO_AD_CH_FIELD_LSBBIT_24 24

// the mako ADC enable/disable bitfield is D23
#define MAKO_ADEN_FIELD_LSBBIT_23 23     

// the mako ASC start conversion bitfield is D22
#define MAKO_ASC_FIELD_LSBBIT_22 22

// the mako A/D data bitfield is D21 - D4
#define MAKO_AD_DATA_FIELD_LSBBIT_4 4


#define MAKO_ASC_STARTCONVERSION 1
#define MAKO_ASC_CONVERSION_DONE 0
    


// A/D channel select bitfield MAKO_AD_CH_BITFIELD definition field to select which of the 11 A/D's to access
// Use name MAKO_AD_CH_BITFIELD to access the field, register is uint32_t wide, starts at D24 and is a 4 bit field 
defineBitField(MAKO_AD_CH_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AD_CH_FIELD_LSBBIT_24, MAKO_BITFIELD_SIZE_4);      

// A/D enable bitfield MAKO_ADEN_BITFIELD definition field to enable or disable the selected A/D converter
// Use name MAKO_ADEN_BITFIELD to access the field, register is uint32_t wide, starts at D23 and is a 1 bit field 
defineBitField(MAKO_ADEN_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_ADEN_FIELD_LSBBIT_23, MAKO_BITFIELD_SIZE_1); 

// A/D start conversion bitfield MAKO_ADEN_BITFIELD definition
// Use name MAKO_ASC_BITFIELD to access the field, register is uint32_t wide, starts at D22 and is a 1 bit field 
defineBitField(MAKO_ASC_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_ASC_FIELD_LSBBIT_22, MAKO_BITFIELD_SIZE_1);

// A/D data bitfield MAKO_AD_DATA_BITFIELD definition - accesses data from the selected A/D converter
// Use name MAKO_AD_DATA_BITFIELD to access the field, register is uint32_t wide, starts at D10 and is a 1 bit field 
defineBitField(MAKO_AD_DATA_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AD_DATA_FIELD_LSBBIT_4, MAKO_BITFIELD_SIZE_10);

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* MakoPrivateBitfieldsReg7_H */

// }}}RME
