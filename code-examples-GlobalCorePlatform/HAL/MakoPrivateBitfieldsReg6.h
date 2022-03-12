// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoPrivateHeaders::MakoPrivateBitfieldsReg6'

#ifndef MakoPrivateBitfieldsReg6_H
#define MakoPrivateBitfieldsReg6_H

#ifdef PRAGMA
#pragma interface "MakoPrivateBitfieldsReg6.h"
#endif

#include <HALtestLib_win32.h>
#include <MakoPrivate.h>
#include <bitfield.h>
#include <rf_audio_std_types.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR


// *******************************************************************************************************
// DAC Mako Sub-Component
//MAKO Address:       |==|31|30|29|28|27|26|25|24|==|23|22|21|20|19|18|17|16|==|15|14|13|12|11|10| 9| 8|==| 7| 6| 5| 4| 3| 2| 1| 0|=|
// Field:                |RW|Address |SE|D3|D2|D1|<-----Pad---->|<---------DAC1_DATA------------>|<---------DAC2_DATA------------>|=|
// Field (DAC3 only):                   |TR|LC|<---DIV--->|R2|LU|<---------DAC Even------------->|<---------DAC Odd-------------->|=|
//                       |<-----REG1------------>|  |<-------REG2---------->|  |<---------REG3-------->|  |<---------REG4-------->| 
// SE - DAC_SELECT
// D3 - DAC3_STATE
// D2 - DAC2_STATE
// D1 - DAC1_STATE
// TR - TX_RX
// LC - LD_CLKDIV
// DIV - CLKDIV
// R2 - RDY2LOAD
// LU - LD_DATA
// *******************************************************************************************************

#define DAC_REGISTER_ADDR 6                                     // Register base for this sub-component

#define DAC1 0                                                  // 0 selects DAC1
#define DAC2 0                                                  // 0 selects DAC2 (accessed through same Mako register)
#define DAC3 1                                                  // 1 selects DAC3 (dedicated for RF PA)
#define OPERATIONAL 0
#define POWER_DOWN 1
#define RAMP_UP 1
#define RAMP_DOWN 
#define ENABLE_CLOCK_LOAD 1
#define DISABLE_CLOCK_LOAD 0
#define CLEAR_LATCH 0
#define SET_LATCH 1
#define ENABLE_LUT_LOAD 1
#define DISABLE_LUT_LOAD 0



defineBitField(READ_WRITE_CNTRL,uint32_t,DAC_REGISTER_BASE,31,1); // Read/write control bit.
defineBitField(DAC_ADDRESS,uint32_t,DAC_REGISTER_BASE,28,3);      // Mako sub-component address
defineBitField(DAC_SELECT,uint32_t,DAC_REGISTER_BASE,27,1);       // DAC address within this sub-component
defineBitField(DAC3_STATE,uint32_t,DAC_REGISTER_BASE,26,1);      // Power-down/Operational control bit -DAC3
defineBitField(DAC2_STATE,uint32_t,DAC_REGISTER_BASE,25,1);      // Power-down/Operational control bit -DAC2
defineBitField(DAC1_STATE,uint32_t,DAC_REGISTER_BASE,24,1);      // Power-down/Operational control bit -DAC1
defineBitField(DAC_DATA_1,uint32_t,DAC_REGISTER_BASE,10,10);     // Data -DAC1
defineBitField(DAC_DATA_2,uint32_t,DAC_REGISTER_BASE,0,10);      // Data -DAC2

// Defines specific to DAC3 (RF Power Shaping DAC)
defineBitField(TX_RX,uint32_t,DAC_REGISTER_BASE,26,1);           // Trigger RampUp/RampDown
defineBitField(LD_CLKDIV,uint32_t,DAC_REGISTER_BASE,25,1);       // Set if clock divider needs to be updated
defineBitField(CLKDIV,uint32_t,DAC_REGISTER_BASE,22,3);          // Clock divider
defineBitField(RDY2LOAD,uint32_t,DAC_REGISTER_BASE,21,1);        // Set on 16th write of DAC3 register to latch
defineBitField(LD_DATA,uint32_t,DAC_REGISTER_BASE,20,1);         // Set when power ramping registers need to be updated
defineBitField(DAC_DATA_EVEN,uint32_t,DAC_REGISTER_BASE,10,10);  // Even RFPA Data
defineBitField(DAC_DATA_ODD,uint32_t,DAC_REGISTER_BASE,0,10);    // Odd RFPA Data




// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* MakoPrivateBitfieldsReg6_H */

// }}}RME
