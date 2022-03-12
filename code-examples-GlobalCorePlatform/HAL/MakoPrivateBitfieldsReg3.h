// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoPrivateHeaders::MakoPrivateBitfieldsReg3'

#ifndef MakoPrivateBitfieldsReg3_H
#define MakoPrivateBitfieldsReg3_H

#ifdef PRAGMA
#pragma interface "MakoPrivateBitfieldsReg3.h"
#endif

#include <HALtestLib_win32.h>
#include <MakoPrivate.h>
#include <bitfield.h>
#include <rf_audio_std_types.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR


// *******************************************************************************************************
//                      MAKO AUDIO Device specific bitfield macros
// *******************************************************************************************************

// Data bits:     |31|30|29|28|27|26| 25|24|23|22|21|20|19|18|17|16| 15|14|13|12|11|10| 9| 8| 7| 6| 5| 4| 3| 2| 1| 0|
// Field:         |RW| Address|<--  MAKO_SUBCOMP_DATA -- >         |                        |                       |
// MAKO_SUBCOMP_DATA                       |                       |                        |                       |   
// AUDIO SPECIFIC FIELDS:     | SEL |PRG|x | <---   DATA 1    ---> | <---   DATA 2  --->    |   <--   DATA 3    --> |
// Data bits:                              | 7| 6| 5| 4| 3| 2| 1| 0|  7| 6| 5| 4| 3| 2| 1| 0| 7| 6| 5| 4| 3| 2| 1| 0|
//         Reg 1  - Reg 3     | 00  |PRG|x |RXPA 7:5|   RXA 4:0    |TXD|TXG 6:4 | x x x  |MA| RXD 7:5|   TXA 4:0    |           
//         Reg 4  - Reg 5     | 01  |PRG|x |DE|S5|S4|C0|RF|TF|SB|MO| x |S3|S2|S1| CTR2| CTR1| x| x| x| x| x| x| x| x|
//         PA_REG - PA_SCP    | 10  |PRG|x |PA_GE|PA_GI|M1|M2|PS|MS| DEB  |MUTP | x| x| x| x| x| x| x| x| x| x| x| x|
// *******************************************************************************************************
 // D31      RW:               Read/~Write 
// D30-D28 Address:           Address of this Mako register, $001 for DC regulator component 
// D27-D0  MAKO_SUBCOMP_DATA: subcomponent field
// D27-D26 SEL (MAKO_AUDIO_SEL_BITFIELD) selects the audio destination/source register DAT0, DAT1, or PA
// D25     PRG (MAKO_AUDIO_PRG_BITFIELD) commits changes into the hardware (D23-D0)

//===========================            //===========================  //===========================
//SEL = 0 Reg 1 D23-D16 DATA1            //SEL = 0 Reg 2 D15-D8  DATA2  //SEL = 0 Reg 3 D7-D0   DATA3  
//===========================            //===========================  //=========================== 
//RXPA D23:D21 Spkr Preamp G3 gain       //TXD D15 TX Digital Volume    //RXD D7:D5 Speaker digital gain
//RXA  D20:D16 Spkr G5 analog gain(vol)  //TXG D14:D12 Mic G1 gain      //TXA D4:D0 c  
                                         //not used D11-D9
                                         //MA MAINAUX D8                               
                                                                                                                                                
//===========================             //===========================
//SEL = 1 Reg 4 D23-D16 DATA1             //SEL = 1 Reg 5 D15-D8  DATA2 
//===========================             //===========================
//DE DEEMPH   D23                         //X        D15 don't care
//S5 S5       D22                         //S3       D14 bypass
//S4 S4       D21                         //S2       D13 bypass
//C0 CTR0     D20 Loopback selector       //S1       D12 bypass
//RF RXBPLP   D19 RXBPLP Speaker filter   //CTR2 1:0 D11-D10 Digital Input Selector
//TF TXBPLP   D18 TXBPLP Mic filter       //CTR1 1:0 D9 - D8 Digital Output Selector
//SB STBY     D17                         //         D7:D0 don't care
//MO MASTERON D16                       

//===========================                            //===========================
//SEL = 2 PA_REG D23-D16 DATA1                           //SEL = 2 PA_SCP D15-D8  DATA2
//===========================                            //=========================== 
//PA_GE G_SEL_E 1:0 D23:D22  External Speaker PA gain    //DEB  C   D15:D14 Debounce period 
//PA_GI G_SEL_I 1:0 D21:D20  Internal Speaker PA gain    //MUTP MUTEPERIOD D13:D12 Mute Period
//M1 PA_MODE1    D19                                     //            D11:D0  don't care
//M2 PA_MODE2    D18                                    
//PS PA_SEL      D17                                   
//MS MIC_SET     D16                                  

//********************************************************************************************************
// MAKO AUDIO bitfield definitions
//********************************************************************************************************
 
#define MAKO_AUDIO_REGISTER_ADDR 003    // Register base for this sub-component within Mako

// write these to MAKO_AUDIO_SEL_BITFIELD bitfield to address the register
#define MAKO_AUDIO_DAT0_ADDR 0 
#define MAKO_AUDIO_DAT1_ADDR 1
#define MAKO_AUDIO_PA_ADDR   2

// values written to the MAKO_AUDIO_SEL_BITFIELD

#define MAKO_AUDIO_SREG123_SEL 0
#define MAKO_AUDIO_SREG45_SEL 1
#define MAKO_AUDIO_PA_SEL 2

// this define is provided for debugging use only.
// some of the get methods which read gain settings and return db values
// use case statements. The default statements should never execute, but
// for good programming practice, this value will be returned in that event,
// instead of garbage.  The methods in question, normally translate bitfield values to db.
// A #define is used instead of a constant to hide the value (constant would show up in the model) and confuse users,
// but meanwhile make this value accessible to the developer.
#define INVALID_VALUE_ERROR -99


				
// bitfield used to select the destination register of the audio/codec sub component
#define MAKO_AUDIO_SEL_FIELD_LSBBIT_26 26
defineBitField(MAKO_AUDIO_SEL_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AUDIO_SEL_FIELD_LSBBIT_26, MAKO_BITFIELD_SIZE_2);

// bitfield used to trigger the loading of the registers from the pre-loading stage of double buffer to working set.
// set this bit on the last transfer of the SPI sequence bound for the codec and audio pa register.
#define MAKO_AUDIO_PRG_FIELD_LSBBIT_25 25
defineBitField(MAKO_AUDIO_PRG_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AUDIO_PRG_FIELD_LSBBIT_25, MAKO_BITFIELD_SIZE_1);


//**************************************
// MAKO AUDIO reg 1 - reg 3 bitfields
//**************************************

// RXPA<2:0> Rx (speaker) Preamp G3 Gain 3 bits
#define MAKO_AUDIO_RXPA_FIELD_LSBBIT_21 21
defineBitField(MAKO_AUDIO_RXPA_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AUDIO_RXPA_FIELD_LSBBIT_21, MAKO_BITFIELD_SIZE_3);

// RXA<4:0> Rx (speaker) 5 bits  
#define MAKO_AUDIO_RXA_FIELD_LSBBIT_16 16
defineBitField(MAKO_AUDIO_RXA_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AUDIO_RXA_FIELD_LSBBIT_16, MAKO_BITFIELD_SIZE_5);

// TXD 1 bit Rx (speaker) digital volume  
#define MAKO_AUDIO_TXD_FIELD_LSBBIT_15 15
defineBitField(MAKO_AUDIO_TXD_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AUDIO_TXD_FIELD_LSBBIT_15, MAKO_BITFIELD_SIZE_1);

// TXG<2:0> Mic analog G1 gain 3 bits
#define MAKO_AUDIO_TXG_FIELD_LSBBIT_12 12
defineBitField(MAKO_AUDIO_TXG_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AUDIO_TXG_FIELD_LSBBIT_12, MAKO_BITFIELD_SIZE_3);

// MAINAUX Main/Aux 1 bit.
#define MAKO_AUDIO_MAINAUX_MIC_FIELD_LSBBIT_8 8
defineBitField(MAKO_AUDIO_MAINAUX_MIC_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AUDIO_MAINAUX_MIC_FIELD_LSBBIT_8, MAKO_BITFIELD_SIZE_1);

// RXD<7:5> Speaker digital gain 3 bits
#define MAKO_AUDIO_RXD_FIELD_LSBBIT_5 5
defineBitField(MAKO_AUDIO_RXD_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AUDIO_RXD_FIELD_LSBBIT_5, MAKO_BITFIELD_SIZE_3);

// TXA<4:0> Mic analog G2 gain 5 bits
#define MAKO_AUDIO_TXA_FIELD_LSBBIT_0 0
defineBitField(MAKO_AUDIO_TXA_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AUDIO_TXA_FIELD_LSBBIT_0, MAKO_BITFIELD_SIZE_5);


//**************************************
// MAKO AUDIO reg 4 - reg 5 bitfields
//**************************************

//DE DEEMPH   D23
#define MAKO_AUDIO_DEEMPH_FIELD_LSBBIT_23 23
defineBitField(MAKO_AUDIO_DEEMPH_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AUDIO_DEEMPH_FIELD_LSBBIT_23, MAKO_BITFIELD_SIZE_1);

//S5 S5       D22
#define MAKO_AUDIO_S5_FIELD_LSBBIT_22 22
defineBitField(MAKO_AUDIO_S5_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AUDIO_S5_FIELD_LSBBIT_22, MAKO_BITFIELD_SIZE_1);

//S4 S4       D21
#define MAKO_AUDIO_S4_FIELD_LSBBIT_21 21
defineBitField(MAKO_AUDIO_S4_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AUDIO_S4_FIELD_LSBBIT_21, MAKO_BITFIELD_SIZE_1);

//C0 CTR0     D20 Loopback selector
#define MAKO_AUDIO_CTR0_FIELD_LSBBIT_20 20
defineBitField(MAKO_AUDIO_CTR0_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AUDIO_CTR0_FIELD_LSBBIT_20, MAKO_BITFIELD_SIZE_1);

//RF RXBPLP   D19 RXBPLP Speaker filter
#define MAKO_AUDIO_RXBPLP_FIELD_LSBBIT_19 19
defineBitField(MAKO_AUDIO_RXBPLP_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AUDIO_RXBPLP_FIELD_LSBBIT_19, MAKO_BITFIELD_SIZE_1);

//TF TXBPLP   D18 TXBPLP Mic filter
#define MAKO_AUDIO_TXBPLP_FIELD_LSBBIT_18 18
defineBitField(MAKO_AUDIO_TXBPLP_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AUDIO_TXBPLP_FIELD_LSBBIT_18, MAKO_BITFIELD_SIZE_1);

//SB STBY     D17
#define MAKO_AUDIO_STBY_FIELD_LSBBIT_17 17
defineBitField(MAKO_AUDIO_STBY_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AUDIO_STBY_FIELD_LSBBIT_17, MAKO_BITFIELD_SIZE_1);

//MO MASTERON D16
#define MAKO_AUDIO_MASTERON_FIELD_LSBBIT_16 16
defineBitField(MAKO_AUDIO_MASTERON_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AUDIO_MASTERON_FIELD_LSBBIT_16, MAKO_BITFIELD_SIZE_1);

//S3 D14 bypass
#define MAKO_AUDIO_S3_FIELD_LSBBIT_14 14
defineBitField(MAKO_AUDIO_S3_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AUDIO_S3_FIELD_LSBBIT_14, MAKO_BITFIELD_SIZE_1);

//S2 D13 bypass
#define MAKO_AUDIO_S2_FIELD_LSBBIT_13 13
defineBitField(MAKO_AUDIO_S2_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AUDIO_S2_FIELD_LSBBIT_13, MAKO_BITFIELD_SIZE_1);

//S1 D12 bypass
#define MAKO_AUDIO_S1_FIELD_LSBBIT_12 12
defineBitField(MAKO_AUDIO_S1_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AUDIO_S1_FIELD_LSBBIT_12, MAKO_BITFIELD_SIZE_1);

//CTR2 1:0 D11-D10 Digital Input Selector 2 bits
#define MAKO_AUDIO_CTR2_FIELD_LSBBIT_10 10
//defineBitField(MAKO_AUDIO_CTR2_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AUDIO_CTR2_FIELD_LSBBIT_10, MAKO_BITFIELD_SIZE_2);

//CTR1 1:0 D9-D8 Digital Output Selector 2 bits
#define MAKO_AUDIO_CTR1_FIELD_LSBBIT_8 8
//defineBitField(MAKO_AUDIO_CTR1_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AUDIO_CTR1_FIELD_LSBBIT_8, MAKO_BITFIELD_SIZE_2);

//*********************************************
// MAKO AUDIO reg PA_REG - reg PA_SCP bitfields
//*********************************************

//PA_GE G_SEL_E 1:0 D23:D22  External Speaker PA gain 2 bits
#define MAKO_AUDIO_G_SEL_E_FIELD_LSBBIT_22 22
defineBitField(MAKO_AUDIO_G_SEL_E_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AUDIO_G_SEL_E_FIELD_LSBBIT_22, MAKO_BITFIELD_SIZE_2);

//PA_GI G_SEL_I 1:0 D21:D20  Internal Speaker PA gain 2 bits
#define MAKO_AUDIO_G_SEL_I_FIELD_LSBBIT_20 20
defineBitField(MAKO_AUDIO_G_SEL_I_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AUDIO_G_SEL_I_FIELD_LSBBIT_20, MAKO_BITFIELD_SIZE_2);

//M1 PA_MODE1    D19 1 bit
#define MAKO_AUDIO_PA_MODE1_FIELD_LSBBIT_19 19 
defineBitField(MAKO_AUDIO_PA_MODE1_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AUDIO_PA_MODE1_FIELD_LSBBIT_19, MAKO_BITFIELD_SIZE_1);

//M2 PA_MODE2    D18 1 bit
#define MAKO_AUDIO_PA_MODE2_FIELD_LSBBIT_18 18
defineBitField(MAKO_AUDIO_PA_MODE2_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AUDIO_PA_MODE2_FIELD_LSBBIT_18, MAKO_BITFIELD_SIZE_1);

//PS PA_SEL      D17 1 bit
#define MAKO_AUDIO_PA_SEL_FIELD_LSBBIT_17 17
defineBitField(MAKO_AUDIO_PA_SEL_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AUDIO_PA_SEL_FIELD_LSBBIT_17, MAKO_BITFIELD_SIZE_1);

//MS MIC_SET     D16 1 bit
#define MAKO_AUDIO_MIC_SET_FIELD_LSBBIT_16 16
defineBitField(MAKO_AUDIO_MIC_SET_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AUDIO_MIC_SET_FIELD_LSBBIT_16, MAKO_BITFIELD_SIZE_1);

//DEBOUNCE  D15:D14 Debounce period 2 bits
#define MAKO_AUDIO_DEBOUNCE_FIELD_LSBBIT_14 14
defineBitField(MAKO_AUDIO_DEBOUNCE_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AUDIO_DEBOUNCE_FIELD_LSBBIT_14, MAKO_BITFIELD_SIZE_2);

//MUTEPERIOD        D13:D12 Mute Period 2 bits
#define MAKO_AUDIO_MUTEPERIOD_FIELD_LSBBIT_12 12
defineBitField(MAKO_AUDIO_MUTEPERIOD_BITFIELD,uint32_t,MAKO_ZERO_REGISTER_BASE, MAKO_AUDIO_MUTEPERIOD_FIELD_LSBBIT_12, MAKO_BITFIELD_SIZE_2);




// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* MakoPrivateBitfieldsReg3_H */

// }}}RME
