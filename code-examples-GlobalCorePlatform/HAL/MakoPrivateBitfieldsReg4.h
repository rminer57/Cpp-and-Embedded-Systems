// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoPrivateHeaders::MakoPrivateBitfieldsReg4'

#ifndef MakoPrivateBitfieldsReg4_H
#define MakoPrivateBitfieldsReg4_H

#ifdef PRAGMA
#pragma interface "MakoPrivateBitfieldsReg4.h"
#endif

#include <HALtestLib_win32.h>
#include <bitfield.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <MakoPrivate.h>

// *******************************************************************************************************
//                      MAKO Accessory Option Detect and GPIO specific bitfield macros
// *******************************************************************************************************

// ADC Mako Sub-Component
//MAKO Address:       |==|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
// Field:                |RW| Address| OPT_CTRL  |<-------------------- OPT_CTRL1 ---------------------------->|
//                                               |                                                             |
// Field:                |RW| Address| OPT_CTRL  |<-------------------- OPT_CTRL2 ---------------------------->|
//                                               |   don't care bits D23 -D12        |GPIO_DIR |X|CFGB |X|CFGA |

// Field:                |RW| Address| OPT_CTRL  |<-------------------- OPT_CTRL3 ---------------------------->|
                                                 
// RW:         Read/~Write D31
// Address:    Address of this Mako register, $111 for ADC  D30 - D28
// OPT_CTRL:  selects OPT subcomponent control  D27 - D24

			
#define OPT_CTRL_REGISTER_ADDR 4        // Register base for this sub-component within Mako (same as USB)
                                                                   // use to setBitField MAKO_REG_ADDRESS D30 - D28


#define MAKO_OPT_CTRL1_ADDRESS 0x08     // address of OPT_CTRL registers 1 
#define MAKO_OPT_CTRL2_ADDRESS 0x09     // address of OPT_CTRL registers 2 
#define MAKO_OPT_CTRL3_ADDRESS 0x0a     // address of OPT_CTRL registers 3 
                                        // use to set bitfield MAKO_OPT_CTRL_BITFIELD D27 - D24

#define MAKO_OPT_CTRL_FIELD_LSBBIT_24 24
#define MAKO_GPIO_DIR_FIELD_LSBBIT_8 8
#define MAKO_OPT_CONFIGA_FIELD_LSBBIT_0 0
#define MAKO_OPT_CONFIGB_FIELD_LSBBIT_4 4



// bitfield MAKO_OPT_CTRL_BITFIELD definition - accesses option control registers
// Use name MAKO_OPT_CTRL_BITFIELD to access the field, register is uint32_t wide, starts at D24 and is a 4 bit field 
defineBitField(MAKO_OPT_CTRL_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_OPT_CTRL_FIELD_LSBBIT_24, MAKO_BITFIELD_SIZE_4);

// bitfield MAKO_GPIO_DIR_BITFIELD definition OPT_CTRL2[11:8]  GPIO_DIR[3:0] 
// Use name MAKO_GPIO_DIR_BITFIELD to access the field, register is uint32_t wide, starts at D8 and is a 4 bit field 
defineBitField(MAKO_GPIO_DIR_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_GPIO_DIR_FIELD_LSBBIT_8, MAKO_BITFIELD_SIZE_4);

// bitfield MAKO_OPT_CONFIGA_BITFIELD definition OPT_CTRL2[2:0]  OPT_CONFIG_A[2:0] 
// Use name MAKO_OPT_CONFIGA_BITFIELD to access the field, register is uint32_t wide, starts at D0 and is a 3 bit field 
defineBitField(MAKO_OPT_CONFIGA_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_OPT_CONFIGA_FIELD_LSBBIT_0, MAKO_BITFIELD_SIZE_3);

// bitfield MAKO_OPT_CONFIGB_BITFIELD definition OPT_CTRL2[6:4]  OPT_CONFIG_B[2:0] 
// Use name MAKO_OPT_CONFIGB_BITFIELD to access the field, register is uint32_t wide, starts at D4 and is a 3 bit field 
defineBitField(MAKO_OPT_CONFIGB_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_OPT_CONFIGB_FIELD_LSBBIT_4, MAKO_BITFIELD_SIZE_3);



// *******************************************************************************************************
//                      MAKO USB bitfield macros
// *******************************************************************************************************

// MAKO bits:            |31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
// Field:                |RW| Address|USB_REG_ADR|<--------------------  USB_OPT  ---------------------------->|
                                                        
// D31       RW:       Read/~Write 
// D30 - D28 Address:  Address of this Mako register, $100 for USB
// D27 - D24 USB_REG_ADR = REG_SEL[3:0] selects one of the five USB registers, or three OPT_CTRL registers at $100. 
// D23 - D0  USB_OPT  USB Register data.  

// ***********************************
// USB REGISTERS
// **********************************
#define MAKO_USB_REGISTER_ADDR 4    // Register base for this sub-component within Mako

#define MAKO_USB1_CTRL_STAT_REG_ADDR 0
#define MAKO_USB2_CTRL_STAT_REG_ADDR 1
#define MAKO_USB1_INT_EN_REG_ADDR 2
#define MAKO_USB2_INT_EN_REG_ADDR 3
#define MAKO_USB_INT_FLAGS_REG_ADDR 4


// MAKO_USB_REG_ADDR_BITFIELD is used to set the USB register address, register is uint32_t wide, starts at D24 and is a 4 bit field 
#define MAKO_USB_REG_ADDR_FIELD_LSBBIT_24 24
defineBitField( MAKO_USB_REG_ADDR_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB_REG_ADDR_FIELD_LSBBIT_24, MAKO_BITFIELD_SIZE_4);

// USB Control Registers
// --------------------------------------
// MAKO_USB1_CTRL_STAT_REG_ADDR bitfields
// MAKO_USB2_CTRL_STAT_REG_ADDR bitfields  
// --------------------------------------
// bits 23,22,15,7,6,5 are undefined (dont' care)

// Vbus switcher on control, write only. Used to enable switcher #5 for both USB1 and USB2. Both must be off to cut power
// Vbus switch operating status - read only. Meaningfull only in 6 cell mode.
#define MAKO_USB_VBUS_SW_ON_FIELD_LSBBIT_21 21
defineBitField( MAKO_USB_VBUS_SW_ON_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB_VBUS_SW_ON_FIELD_LSBBIT_21, MAKO_BITFIELD_SIZE_1);

// vbus switch operating - read only
#define MAKO_USB_VBUS_SW_OP_FIELD_LSBBIT_21 21
defineBitField( MAKO_USB_VBUS_SW_OP_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB_VBUS_SW_OP_FIELD_LSBBIT_21, MAKO_BITFIELD_SIZE_1);


// Vbus LDO Regulator control read/write.  Enable this regulator only AFTER Vbus_SW_On is enabled. 
#define MAKO_USB_VBUS_LDO_ON_FIELD_LSBBIT_20 20
defineBitField( MAKO_USB_VBUS_LDO_ON_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB_VBUS_LDO_ON_FIELD_LSBBIT_20, MAKO_BITFIELD_SIZE_1);

// Vbus Mon On - monitor  read/write.  when set, the monitor block is enabled
#define MAKO_USB_VBUS_MON_ON_FIELD_LSBBIT_19 19
defineBitField( MAKO_USB_VBUS_MON_ON_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB_VBUS_MON_ON_FIELD_LSBBIT_19, MAKO_BITFIELD_SIZE_1);

// Vbus current limit control - read/write.  0 = current limited to 50mA, 1 = limit current to 500mA
#define MAKO_USB_VBUS_ILIMIT_FIELD_LSBBIT_18 18
defineBitField( MAKO_USB_VBUS_ILIMIT_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB_VBUS_ILIMIT_FIELD_LSBBIT_18, MAKO_BITFIELD_SIZE_1);

// Vbus Disch - read/write.  When set, causes Vbus to be discharged to ground via an internal resistor
#define MAKO_USB_VBUS_DISCH_FIELD_LSBBIT_17 17
defineBitField( MAKO_USB_VBUS_DISCH_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB_VBUS_DISCH_FIELD_LSBBIT_17, MAKO_BITFIELD_SIZE_1);

// Vbus chg - read/write. When set, causes Vbus to be charged to 3.3v
#define MAKO_USB_VBUS_CHG_FIELD_LSBBIT_16 16
defineBitField( MAKO_USB_VBUS_CHG_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB_VBUS_CHG_FIELD_LSBBIT_16, MAKO_BITFIELD_SIZE_1);

// USB1 connect - read/write. Used in APCO radios to control USB isolation switch
#define MAKO_USB_CONNECT_APCO_FIELD_LSBBIT_15 15
defineBitField( MAKO_USB_CONNECT_APCO_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB_CONNECT_APCO_FIELD_LSBBIT_15, MAKO_BITFIELD_SIZE_1);

// Pullup. read/write When set, causes pull-up on bus DP or DM depending on speed.
#define MAKO_USB_PULLUP_FIELD_LSBBIT_14 14
defineBitField( MAKO_USB_PULLUP_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB_PULLUP_FIELD_LSBBIT_14, MAKO_BITFIELD_SIZE_1);

// Speed control - read/write  When set, causes transmitter to be slew rate limited for full speed operation
#define MAKO_USB_SPEED_FIELD_LSBBIT_13 13
defineBitField( MAKO_USB_SPEED_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB_SPEED_FIELD_LSBBIT_13, MAKO_BITFIELD_SIZE_1);

// DP Pulldown read/write. When set, causes pulldown on bus DP
#define MAKO_USB_DPPULLDN_FIELD_LSBBIT_12 12
defineBitField( MAKO_USB_DPPULLDN_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB_DPPULLDN_FIELD_LSBBIT_12, MAKO_BITFIELD_SIZE_1);

// DM Pulldown read/write. When set, causes pulldown on bus DM
#define MAKO_USB_DMPULLDN_FIELD_LSBBIT_11 11
defineBitField( MAKO_USB_DMPULLDN_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB_DMPULLDN_FIELD_LSBBIT_11, MAKO_BITFIELD_SIZE_1);

// Suspend read/write. When set, causes the transmitter to be in suspend mode.
#define MAKO_USB_SUSPEND_FIELD_LSBBIT_10 10
defineBitField( MAKO_USB_SUSPEND_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB_SUSPEND_FIELD_LSBBIT_10, MAKO_BITFIELD_SIZE_1);

// RS232_USB - read/write. When set, causes USB transceiver to be bypassed.
#define MAKO_USB_RS232_FIELD_LSBBIT_9 9
defineBitField( MAKO_USB_RS232_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB_RS232_FIELD_LSBBIT_9, MAKO_BITFIELD_SIZE_1);

// Bdis_Acon_En read/write. B disconnect, A connect enable.  When set, causes A to assert pullup on DP when device B does so.
// this forces B to become the host.
#define MAKO_USB_BDIS_ACON_EN_FIELD_LSBBIT_8 8
defineBitField( MAKO_USB_BDIS_ACON_EN_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB_BDIS_ACON_EN_FIELD_LSBBIT_8, MAKO_BITFIELD_SIZE_1);

// Vbus valid.  read only. 1 means Vbus > 4.4v
#define MAKO_USB_VBUS_VAL_FIELD_LSBBIT_4 4
defineBitField( MAKO_USB_VBUS_VAL_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB_VBUS_VAL_FIELD_LSBBIT_4, MAKO_BITFIELD_SIZE_1);

// Session Valid - read only. 1 means Vbus < 2v
#define MAKO_USB_SESS_VAL_FIELD_LSBBIT_3 3
defineBitField( MAKO_USB_SESS_VAL_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB_SESS_VAL_FIELD_LSBBIT_3, MAKO_BITFIELD_SIZE_1);

// DP asserted during session request. read only. 1 = DP asserted.
#define MAKO_USB_DP_SRP_FIELD_LSBBIT_2 2
defineBitField( MAKO_USB_DP_SRP_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB_DP_SRP_FIELD_LSBBIT_2, MAKO_BITFIELD_SIZE_1);

// Session end read only. 1 means Vbus < 0.8v
#define MAKO_USB_SESS_END_FIELD_LSBBIT_0 0
defineBitField( MAKO_USB_SESS_END_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB_SESS_END_FIELD_LSBBIT_0, MAKO_BITFIELD_SIZE_1);


// USB Interrupt Enable Registers
// --------------------------------------
// MAKO_USB1_INT_EN_REG_ADDR bitfields 
// MAKO_USB2_INT_EN_REG_ADDR bitfields 
// --------------------------------------
// bits 23 - 13, 7 -5, 1 are undefined (dont' care)

// Vbus_Val_RE  Vbus Valid Rising Edge Interrupt Enable write only
#define MAKO_USB_VBUS_VALID_INTR_FIELD_LSBBIT_12 12
defineBitField( MAKO_USB_VBUS_VALID_INTR_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB_VBUS_VALID_INTR_FIELD_LSBBIT_12, MAKO_BITFIELD_SIZE_1);


#define MAKO_USB_SESS_VALID_FIELD_LSBBIT_11 11
defineBitField( MAKO_USB_SESS_VALID_INTR_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB_SESS_VALID_FIELD_LSBBIT_11, MAKO_BITFIELD_SIZE_1);

#define MAKO_USB_DP_SRP_ASSERTED_FIELD_LSBBIT_10 10
defineBitField( MAKO_USB_DP_SRP_ASSERTED_INTR_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB_DP_SRP_ASSERTED_FIELD_LSBBIT_10, MAKO_BITFIELD_SIZE_1);

#define MAKO_USB_BDIS_ACON_FIELD_LSBBIT_9 9
defineBitField( MAKO_USB_BDIS_ACON_INTR_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB_BDIS_ACON_FIELD_LSBBIT_9, MAKO_BITFIELD_SIZE_1);

#define MAKO_USB_SESS_END_TRUE_FIELD_LSBBIT_8 8
defineBitField( MAKO_USB_SESS_END_TRUE_INTR_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB_SESS_END_TRUE_FIELD_LSBBIT_8, MAKO_BITFIELD_SIZE_1);

#define MAKO_USB_VBUS_INVALID_FIELD_LSBBIT_4 4
defineBitField( MAKO_USB_VBUS_INVALID_INTR_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB_VBUS_INVALID_FIELD_LSBBIT_4, MAKO_BITFIELD_SIZE_1);

#define MAKO_USB_SESS_INVALID_FIELD_LSBBIT_3 3
defineBitField( MAKO_USB_SESS_INVALID_INTR_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB_SESS_INVALID_FIELD_LSBBIT_3, MAKO_BITFIELD_SIZE_1);

#define MAKO_USB_DP_SRP_DEASSERTED_FIELD_LSBBIT_2 2
defineBitField( MAKO_USB_DP_SRP_DEASSERTED_INTR_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB_DP_SRP_DEASSERTED_FIELD_LSBBIT_2, MAKO_BITFIELD_SIZE_1);

#define MAKO_USB_SESS_END_FALSE_FIELD_LSBBIT_0 0
defineBitField( MAKO_USB_SESS_END_FALSE_INTR_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB_SESS_END_FALSE_FIELD_LSBBIT_0, MAKO_BITFIELD_SIZE_1);


// --------------------------------------
// MAKO_USB_INT_FLAGS_REG_ADDR bitfields 
// --------------------------------------
// bits 23 - 13, 7 - 5 are undefined (dont' care)

#define MAKO_USB1_VBUS_VALID_LE_FIELD_LSBBIT_12 12
defineBitField( MAKO_USB1_VBUS_VALID_LE_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB1_VBUS_VALID_LE_FIELD_LSBBIT_12, MAKO_BITFIELD_SIZE_1);

#define MAKO_USB1_SESS_VALID_LE_FIELD_LSBBIT_11 11
defineBitField( MAKO_USB1_SESS_VALID_LE_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB1_SESS_VALID_LE_FIELD_LSBBIT_11, MAKO_BITFIELD_SIZE_1);

#define MAKO_USB1_DP_SRP_LE_FIELD_LSBBIT_10 10
defineBitField( MAKO_USB1_DP_SRP_LE_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB1_DP_SRP_LE_FIELD_LSBBIT_10, MAKO_BITFIELD_SIZE_1);

#define MAKO_USB1_BDIS_ACON_LE_FIELD_LSBBIT_9 9
defineBitField( MAKO_USB1_BDIS_ACON_LE_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB1_BDIS_ACON_LE_FIELD_LSBBIT_9, MAKO_BITFIELD_SIZE_1);

#define MAKO_USB1_BSESS_END_LE_FIELD_LSBBIT_8 8
defineBitField( MAKO_USB1_BSESS_END_LE_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB1_BSESS_END_LE_FIELD_LSBBIT_8, MAKO_BITFIELD_SIZE_1);


#define MAKO_USB2_VBUS_VALID_LE_FIELD_LSBBIT_4 4
defineBitField( MAKO_USB2_VBUS_VALID_LE_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB2_VBUS_VALID_LE_FIELD_LSBBIT_4, MAKO_BITFIELD_SIZE_1);

#define MAKO_USB2_SESS_VALID_LE_FIELD_LSBBIT_3 3
defineBitField( MAKO_USB2_SESS_VALID_LE_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB2_SESS_VALID_LE_FIELD_LSBBIT_3, MAKO_BITFIELD_SIZE_1);

#define MAKO_USB2_DP_SRP_LE_FIELD_LSBBIT_2 2
defineBitField( MAKO_USB2_DP_SRP_LE_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB2_DP_SRP_LE_FIELD_LSBBIT_2, MAKO_BITFIELD_SIZE_1);

#define MAKO_USB2_BDIS_ACON_LE_FIELD_LSBBIT_1 1
defineBitField( MAKO_USB2_BDIS_ACON_LE_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB2_BDIS_ACON_LE_FIELD_LSBBIT_1, MAKO_BITFIELD_SIZE_1);

#define MAKO_USB2_BSESS_END_LE_FIELD_LSBBIT_0 0
defineBitField( MAKO_USB2_BSESS_END_LE_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_USB2_BSESS_END_LE_FIELD_LSBBIT_0, MAKO_BITFIELD_SIZE_1);


// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* MakoPrivateBitfieldsReg4_H */

// }}}RME
