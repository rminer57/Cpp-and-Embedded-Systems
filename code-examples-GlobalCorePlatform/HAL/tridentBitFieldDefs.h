// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::Trident::TridentPrivate::TridentBitFieldDefs'

#ifndef TridentBitFieldDefs_H
#define TridentBitFieldDefs_H

#ifdef PRAGMA
#pragma interface "TridentBitFieldDefs.h"
#endif

#include <rf_sequencer_comp.h>
#include <TridentDefines.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>

// THESE ARE PROVIDED FOR READABILITY OF THE definebitfield macro definitions.
#define BFIELD_SIZEinBits_1 1
#define BFIELD_SIZEinBits_2 2
#define BFIELD_SIZEinBits_3 3
#define BFIELD_SIZEinBits_4 4
#define BFIELD_SIZEinBits_5 5
#define BFIELD_SIZEinBits_6 6
#define BFIELD_SIZEinBits_7 7
#define BFIELD_SIZEinBits_8 8
#define BFIELD_SIZEinBits_9 9
#define BFIELD_SIZEinBits_10 10
#define BFIELD_SIZEinBits_11 11
#define BFIELD_SIZEinBits_12 12
#define BFIELD_SIZEinBits_13 13
#define BFIELD_SIZEinBits_14 14
#define BFIELD_SIZEinBits_15 15
#define BFIELD_SIZEinBits_16 16
#define BFIELD_SIZEinBits_17 16
#define BFIELD_SIZEinBits_18 16
#define BFIELD_SIZEinBits_19 16
#define BFIELD_SIZEinBits_20 16
#define BFIELD_SIZEinBits_21 16
#define BFIELD_SIZEinBits_22 16
#define BFIELD_SIZEinBits_23 16
#define BFIELD_SIZEinBits_24 24

#define BFIELD_STARTBIT_0 0
#define BFIELD_STARTBIT_1 1
#define BFIELD_STARTBIT_2 2
#define BFIELD_STARTBIT_3 3
#define BFIELD_STARTBIT_4 4
#define BFIELD_STARTBIT_5 5
#define BFIELD_STARTBIT_6 6
#define BFIELD_STARTBIT_7 7
#define BFIELD_STARTBIT_8 8
#define BFIELD_STARTBIT_9 9
#define BFIELD_STARTBIT_10 10
#define BFIELD_STARTBIT_11 11
#define BFIELD_STARTBIT_12 12
#define BFIELD_STARTBIT_13 13
#define BFIELD_STARTBIT_14 14
#define BFIELD_STARTBIT_15 15

#define BFIELD_STARTBIT_16 16
#define BFIELD_STARTBIT_17 17
#define BFIELD_STARTBIT_18 18
#define BFIELD_STARTBIT_19 19
#define BFIELD_STARTBIT_20 20 
#define BFIELD_STARTBIT_21 21
#define BFIELD_STARTBIT_22 22
#define BFIELD_STARTBIT_23 23
#define BFIELD_STARTBIT_24 24
#define BFIELD_STARTBIT_25 25
#define BFIELD_STARTBIT_26 26
#define BFIELD_STARTBIT_27 27
#define BFIELD_STARTBIT_28 28 
#define BFIELD_STARTBIT_29 29
#define BFIELD_STARTBIT_30 30
#define BFIELD_STARTBIT_31 31

// needed to access 24 bit CLK_NUM field
#define BFIELD_BYTEOFFSET_CLKNUM 92

// needed to access MAINNM field greater than 16 bits
#define BFIELD_BYTEOFFSET_MAINNM 106


// This line is being done as a defensive measure.  Just in case we need to use 
// defineBitFieldRev v.s. defineBitField macros on one core C55 v.s. arm9
// This issue will be resolved when testing on both targets.
#define defineBitFieldTrident(name,type,off,start,len) \
        defineBitField(name,type,off,start,len); \
        const static unsigned int name ## _RegToSnippet = ((((start)/8) + (off)) / TRIDENT_SNIPPET_SIZE);

// offset formulas
// offset = addr * 2,  for MSB of 16 bit hword
// offset = (addr * 2) + 1, for LSB of 16 bit hword
// offset = addr * 2, first sequential hword address in 32 bit word

// the bitfield macro byte offset numbering is zero based.
#define TRIDENT_BYTEOFFSET 2
#define TRIDENT_ADDR00 0
#define TRIDENT_ADDR01 TRIDENT_ADDR00 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR02 TRIDENT_ADDR01 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR03 TRIDENT_ADDR02 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR04 TRIDENT_ADDR03 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR05 TRIDENT_ADDR04 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR06 TRIDENT_ADDR05 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR07 TRIDENT_ADDR06 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR08 TRIDENT_ADDR07 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR09 TRIDENT_ADDR08 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR0A TRIDENT_ADDR09 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR0B TRIDENT_ADDR0A + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR0C TRIDENT_ADDR0B + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR0D TRIDENT_ADDR0C + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR0E TRIDENT_ADDR0D + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR0F TRIDENT_ADDR0E + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR10 TRIDENT_ADDR0F + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR11 TRIDENT_ADDR10 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR12 TRIDENT_ADDR11 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR13 TRIDENT_ADDR12 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR14 TRIDENT_ADDR13 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR15 TRIDENT_ADDR14 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR16 TRIDENT_ADDR15 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR17 TRIDENT_ADDR16 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR18 TRIDENT_ADDR17 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR19 TRIDENT_ADDR18 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR1A TRIDENT_ADDR19 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR1B TRIDENT_ADDR1A + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR1C TRIDENT_ADDR1B + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR1D TRIDENT_ADDR1C + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR1E TRIDENT_ADDR1D + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR1F TRIDENT_ADDR1E + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR20 TRIDENT_ADDR1F + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR21 TRIDENT_ADDR20 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR22 TRIDENT_ADDR21 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR23 TRIDENT_ADDR22 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR24 TRIDENT_ADDR23 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR25 TRIDENT_ADDR24 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR26 TRIDENT_ADDR25 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR27 TRIDENT_ADDR26 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR28 TRIDENT_ADDR27 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR29 TRIDENT_ADDR28 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR2A TRIDENT_ADDR29 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR2B TRIDENT_ADDR2A + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR2C TRIDENT_ADDR2B + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR2D TRIDENT_ADDR2C + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR2E TRIDENT_ADDR2D + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR2F TRIDENT_ADDR2E + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR30 TRIDENT_ADDR2F + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR31 TRIDENT_ADDR30 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR32 TRIDENT_ADDR31 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR33 TRIDENT_ADDR32 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR34 TRIDENT_ADDR33 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR35 TRIDENT_ADDR34 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR36 TRIDENT_ADDR35 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR37 TRIDENT_ADDR36 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR38 TRIDENT_ADDR37 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR39 TRIDENT_ADDR38 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR3A TRIDENT_ADDR39 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR3B TRIDENT_ADDR3A + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR3C TRIDENT_ADDR3B + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR3D TRIDENT_ADDR3C + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR3E TRIDENT_ADDR3D + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR3F TRIDENT_ADDR3E + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR40 TRIDENT_ADDR3F + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR41 TRIDENT_ADDR40 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR42 TRIDENT_ADDR41 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR43 TRIDENT_ADDR42 + TRIDENT_BYTEOFFSET
#define TRIDENT_ADDR44 TRIDENT_ADDR43 + TRIDENT_BYTEOFFSET

//      WORD16 - 0x01


// bits D15 and D14 are unused spares.
defineBitFieldTrident( TXCLK_POL,            uint16_t,  TRIDENT_ADDR00,  BFIELD_STARTBIT_13, BFIELD_SIZEinBits_1);
defineBitFieldTrident( ABF_SEL,              uint16_t,  TRIDENT_ADDR00,  BFIELD_STARTBIT_12, BFIELD_SIZEinBits_1);
defineBitFieldTrident( ABR_SEL,              uint16_t,  TRIDENT_ADDR00,  BFIELD_STARTBIT_11, BFIELD_SIZEinBits_1);
defineBitFieldTrident( DN_DLY,               uint16_t,  TRIDENT_ADDR00,  BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_11);

defineBitFieldTrident( OVSX,                 uint16_t,  TRIDENT_ADDR01,  BFIELD_STARTBIT_14, BFIELD_SIZEinBits_2);
defineBitFieldTrident( SC_SEL,               uint16_t,  TRIDENT_ADDR01,  BFIELD_STARTBIT_12, BFIELD_SIZEinBits_2);
defineBitFieldTrident( SSI_DLY,              uint16_t,  TRIDENT_ADDR01,  BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_12);

defineBitFieldTrident( LAST_INT,             uint16_t,  TRIDENT_ADDR02,  BFIELD_STARTBIT_15, BFIELD_SIZEinBits_1);
defineBitFieldTrident( FIRCLK_SB,            uint16_t,  TRIDENT_ADDR02,  BFIELD_STARTBIT_14, BFIELD_SIZEinBits_1);
defineBitFieldTrident( ABW,                  uint16_t,  TRIDENT_ADDR02,  BFIELD_STARTBIT_8,  BFIELD_SIZEinBits_6);
defineBitFieldTrident( TXC_REF,              uint16_t,  TRIDENT_ADDR02,  BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_8);

// D15 is unused spare.
defineBitFieldTrident( OVS_REF,              uint16_t,  TRIDENT_ADDR03,  BFIELD_STARTBIT_10, BFIELD_SIZEinBits_5);
defineBitFieldTrident( TXF_REF,              uint16_t,  TRIDENT_ADDR03,  BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_10);

defineBitFieldTrident( Q_DCOFS,              uint16_t,  TRIDENT_ADDR04,  BFIELD_STARTBIT_8,  BFIELD_SIZEinBits_8);
defineBitFieldTrident( I_DCOFS,              uint16_t,  TRIDENT_ADDR04,  BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_8);

// Address $05 D15-D13 are spares
defineBitFieldTrident( TX_DCOC_SIGN,         uint16_t,  TRIDENT_ADDR05,  BFIELD_STARTBIT_12, BFIELD_SIZEinBits_1);
defineBitFieldTrident( DCOC_SIGN_EF,         uint16_t,  TRIDENT_ADDR05,  BFIELD_STARTBIT_11, BFIELD_SIZEinBits_1);
defineBitFieldTrident( WFG_REF,              uint16_t,  TRIDENT_ADDR05,  BFIELD_STARTBIT_6,  BFIELD_SIZEinBits_5);
defineBitFieldTrident( GPO_TRIST_ALL,        uint16_t,  TRIDENT_ADDR05,  BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_6);
defineBitFieldTrident( GPO_TRIST6,           uint16_t,  TRIDENT_ADDR05,  BFIELD_STARTBIT_5,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( GPO_TRIST5,           uint16_t,  TRIDENT_ADDR05,  BFIELD_STARTBIT_4,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( GPO_TRIST4,           uint16_t,  TRIDENT_ADDR05,  BFIELD_STARTBIT_3,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( GPO_TRIST3,           uint16_t,  TRIDENT_ADDR05,  BFIELD_STARTBIT_2,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( GPO_TRIST2,           uint16_t,  TRIDENT_ADDR05,  BFIELD_STARTBIT_1,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( GPO_TRIST1,           uint16_t,  TRIDENT_ADDR05,  BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_1);

defineBitFieldTrident( ATT_SSI,              uint16_t,  TRIDENT_ADDR06,  BFIELD_STARTBIT_15, BFIELD_SIZEinBits_1);
defineBitFieldTrident( HP_SEL_BS,               uint16_t,  TRIDENT_ADDR06,  BFIELD_STARTBIT_14, BFIELD_SIZEinBits_1);
defineBitFieldTrident( DC_CORRECT,           uint16_t,  TRIDENT_ADDR06,  BFIELD_STARTBIT_13, BFIELD_SIZEinBits_1);
// D12-D10 are spares
defineBitFieldTrident( X1DR0,                uint16_t,  TRIDENT_ADDR06,  BFIELD_STARTBIT_0, BFIELD_SIZEinBits_10);

// D15-D11 are spares.
defineBitFieldTrident( EN_DLY_MUX,           uint16_t, TRIDENT_ADDR07,  BFIELD_STARTBIT_10, BFIELD_SIZEinBits_1);
defineBitFieldTrident( X1DR1,                uint16_t, TRIDENT_ADDR07,  BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_10);

defineBitFieldTrident( EN_OVS_DLYD,          uint16_t, TRIDENT_ADDR08,  BFIELD_STARTBIT_10, BFIELD_SIZEinBits_6);
defineBitFieldTrident( X1DR2,                uint16_t, TRIDENT_ADDR08,  BFIELD_STARTBIT_0, BFIELD_SIZEinBits_10);

defineBitFieldTrident( SYMB_REF,             uint16_t, TRIDENT_ADDR09,  BFIELD_STARTBIT_10, BFIELD_SIZEinBits_6);
defineBitFieldTrident( X1DR3,                uint16_t, TRIDENT_ADDR09,  BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_10);

// D15 is spare.
defineBitFieldTrident( BSAVE_WG,             uint16_t, TRIDENT_ADDR0A,  BFIELD_STARTBIT_14, BFIELD_SIZEinBits_1);
defineBitFieldTrident( BSAVE_I,              uint16_t, TRIDENT_ADDR0A,  BFIELD_STARTBIT_13, BFIELD_SIZEinBits_1);
defineBitFieldTrident( BSAVE_Q,              uint16_t, TRIDENT_ADDR0A,  BFIELD_STARTBIT_12, BFIELD_SIZEinBits_1);
defineBitFieldTrident( BSAVE_EF,             uint16_t, TRIDENT_ADDR0A,  BFIELD_STARTBIT_11, BFIELD_SIZEinBits_1);
// D10 is spare
defineBitFieldTrident( X1DR4,                uint16_t, TRIDENT_ADDR0A,  BFIELD_STARTBIT_0, BFIELD_SIZEinBits_10);

// D15-D14 are spares
defineBitFieldTrident( TX_POS_COMP,         uint16_t, TRIDENT_ADDR0B,  BFIELD_STARTBIT_13, BFIELD_SIZEinBits_1);
defineBitFieldTrident( TX_NEG_COMP,         uint16_t, TRIDENT_ADDR0B,  BFIELD_STARTBIT_12, BFIELD_SIZEinBits_1);
defineBitFieldTrident( TXCONFIG,             uint16_t, TRIDENT_ADDR0B,  BFIELD_STARTBIT_10, BFIELD_SIZEinBits_2);
defineBitFieldTrident( X1DR5,                uint16_t, TRIDENT_ADDR0B,  BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_10);

defineBitFieldTrident( DIAG_MODE,            uint16_t, TRIDENT_ADDR0C,  BFIELD_STARTBIT_15, BFIELD_SIZEinBits_1);
defineBitFieldTrident( DIAG_INADDR,          uint16_t, TRIDENT_ADDR0C,  BFIELD_STARTBIT_11, BFIELD_SIZEinBits_4);
defineBitFieldTrident( X2DR0,                uint16_t, TRIDENT_ADDR0C,  BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_11);

defineBitFieldTrident( DIAG_TX_RX_EN,        uint16_t, TRIDENT_ADDR0D,  BFIELD_STARTBIT_15, BFIELD_SIZEinBits_1);
defineBitFieldTrident( DIAG_OUTADDR,         uint16_t, TRIDENT_ADDR0D,  BFIELD_STARTBIT_11, BFIELD_SIZEinBits_4);
defineBitFieldTrident( X2DR1,                uint16_t, TRIDENT_ADDR0D,  BFIELD_STARTBIT_0, BFIELD_SIZEinBits_11);
// D15 - D11 "not available"
defineBitFieldTrident( X2DR2,                uint16_t, TRIDENT_ADDR0E,  BFIELD_STARTBIT_0, BFIELD_SIZEinBits_11);
// D15 - D11 "not available"
defineBitFieldTrident( X2DR3,                uint16_t, TRIDENT_ADDR0F,  BFIELD_STARTBIT_0, BFIELD_SIZEinBits_11);
// D15 - D11 "not available"
defineBitFieldTrident( X2DR4,                uint16_t, TRIDENT_ADDR10,  BFIELD_STARTBIT_0, BFIELD_SIZEinBits_11);
// D15 - D11 "not available"
defineBitFieldTrident( X2DR5,                uint16_t, TRIDENT_ADDR11,  BFIELD_STARTBIT_0, BFIELD_SIZEinBits_11);


// D15 - D13 "not available"
defineBitFieldTrident( X3DR0,                uint16_t, TRIDENT_ADDR12,  BFIELD_STARTBIT_0, BFIELD_SIZEinBits_13);
// D15 - D13 "not available"
defineBitFieldTrident( X3DR1,                uint16_t, TRIDENT_ADDR13,  BFIELD_STARTBIT_0, BFIELD_SIZEinBits_13);
// D15 - D13 "not available"
defineBitFieldTrident( X3DR2,                uint16_t, TRIDENT_ADDR14,  BFIELD_STARTBIT_0, BFIELD_SIZEinBits_13);
// D15 - D13 "not available"
defineBitFieldTrident( X3DR3,                uint16_t, TRIDENT_ADDR15,  BFIELD_STARTBIT_0, BFIELD_SIZEinBits_13);
// D15 - D13 "not available"
defineBitFieldTrident( X3DR4,                uint16_t, TRIDENT_ADDR16,  BFIELD_STARTBIT_0, BFIELD_SIZEinBits_13);
// D15 - D13 "not available"
defineBitFieldTrident( X3DR5,                uint16_t, TRIDENT_ADDR17,  BFIELD_STARTBIT_0, BFIELD_SIZEinBits_13);


// D15 - D14 "not available"
defineBitFieldTrident( X4DR0,                uint16_t, TRIDENT_ADDR18,  BFIELD_STARTBIT_0, BFIELD_SIZEinBits_14);
// D15 - D14 "not available"
defineBitFieldTrident( X4DR1,                uint16_t, TRIDENT_ADDR19,  BFIELD_STARTBIT_0, BFIELD_SIZEinBits_14);
// D15 - D14 "not available"
defineBitFieldTrident( X4DR2,                uint16_t, TRIDENT_ADDR1A,  BFIELD_STARTBIT_0, BFIELD_SIZEinBits_14);
// D15 - D14 "not available"
defineBitFieldTrident( X4DR3,                uint16_t, TRIDENT_ADDR1B,  BFIELD_STARTBIT_0, BFIELD_SIZEinBits_14);
// D15 - D14 "not available"
defineBitFieldTrident( X4DR4,                uint16_t, TRIDENT_ADDR1C,  BFIELD_STARTBIT_0, BFIELD_SIZEinBits_14);
// D15 - D14 "not available"
defineBitFieldTrident( X4DR5,                uint16_t, TRIDENT_ADDR1D,  BFIELD_STARTBIT_0, BFIELD_SIZEinBits_14);

defineBitFieldTrident( EF_DC_CORRECT,        uint16_t, TRIDENT_ADDR1E,  BFIELD_STARTBIT_15, BFIELD_SIZEinBits_1);
defineBitFieldTrident( EF_SEL,               uint16_t, TRIDENT_ADDR1E,  BFIELD_STARTBIT_13, BFIELD_SIZEinBits_2);
defineBitFieldTrident( GPO_TEST_SEL,         uint16_t, TRIDENT_ADDR1E,  BFIELD_STARTBIT_12, BFIELD_SIZEinBits_1);
defineBitFieldTrident( TM_BUF,               uint16_t, TRIDENT_ADDR1E,  BFIELD_STARTBIT_10, BFIELD_SIZEinBits_2);
defineBitFieldTrident( DCOC_REF,             uint16_t, TRIDENT_ADDR1E,  BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_10);


defineBitFieldTrident( TEST_MUX,             uint16_t, TRIDENT_ADDR1F,  BFIELD_STARTBIT_8,  BFIELD_SIZEinBits_8);
defineBitFieldTrident( DMO,                  uint16_t, TRIDENT_ADDR1F,  BFIELD_STARTBIT_7,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( AGC_ATTN_ENUP,        uint16_t, TRIDENT_ADDR1F,  BFIELD_STARTBIT_6,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( FST_STP,              uint16_t, TRIDENT_ADDR1F,  BFIELD_STARTBIT_3,  BFIELD_SIZEinBits_3);
defineBitFieldTrident( EF_DLY,               uint16_t, TRIDENT_ADDR1F,  BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_3);

defineBitFieldTrident( TR_UPPER,             uint16_t, TRIDENT_ADDR20,  BFIELD_STARTBIT_8, BFIELD_SIZEinBits_8);
defineBitFieldTrident( TR_LOWER,             uint16_t, TRIDENT_ADDR20,  BFIELD_STARTBIT_0, BFIELD_SIZEinBits_8);

defineBitFieldTrident( I_DAC_HOLD,           uint16_t, TRIDENT_ADDR21,  BFIELD_STARTBIT_15,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( Q_DAC_HOLD,           uint16_t, TRIDENT_ADDR21,  BFIELD_STARTBIT_14,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( DAC_SEL,              uint16_t, TRIDENT_ADDR21,  BFIELD_STARTBIT_11,  BFIELD_SIZEinBits_3);
defineBitFieldTrident( DAC_WORD,             uint16_t, TRIDENT_ADDR21,  BFIELD_STARTBIT_0, BFIELD_SIZEinBits_11);


defineBitFieldTrident( DCOC_LPF_BW,          uint16_t, TRIDENT_ADDR22,  BFIELD_STARTBIT_15, BFIELD_SIZEinBits_1);
defineBitFieldTrident( DCOCL_HOLD,           uint16_t, TRIDENT_ADDR22,  BFIELD_STARTBIT_14, BFIELD_SIZEinBits_1);
defineBitFieldTrident( QDC_DAC,              uint16_t, TRIDENT_ADDR22,  BFIELD_STARTBIT_8, BFIELD_SIZEinBits_6);
defineBitFieldTrident( DC_DAC_GM,            uint16_t, TRIDENT_ADDR22,  BFIELD_STARTBIT_6, BFIELD_SIZEinBits_2);
defineBitFieldTrident( IDC_DAC,              uint16_t, TRIDENT_ADDR22,  BFIELD_STARTBIT_0, BFIELD_SIZEinBits_6);

defineBitFieldTrident( SM_AGC_EN,            uint16_t, TRIDENT_ADDR23,  BFIELD_STARTBIT_15, BFIELD_SIZEinBits_1);
// d14 spare
defineBitFieldTrident( NBMUX,                uint16_t, TRIDENT_ADDR23,  BFIELD_STARTBIT_13, BFIELD_SIZEinBits_1);
defineBitFieldTrident( FHP3,                 uint16_t, TRIDENT_ADDR23,  BFIELD_STARTBIT_9,  BFIELD_SIZEinBits_4);
defineBitFieldTrident( THP1,                 uint16_t, TRIDENT_ADDR23,  BFIELD_STARTBIT_6,  BFIELD_SIZEinBits_3);
defineBitFieldTrident( THP2,                 uint16_t, TRIDENT_ADDR23,  BFIELD_STARTBIT_3,  BFIELD_SIZEinBits_3);
defineBitFieldTrident( KDLPT,                uint16_t, TRIDENT_ADDR23,  BFIELD_STARTBIT_0, BFIELD_SIZEinBits_3);


defineBitFieldTrident( PMA_BP,               uint16_t, TRIDENT_ADDR24,  BFIELD_STARTBIT_15,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( DBW,                  uint16_t, TRIDENT_ADDR24,  BFIELD_STARTBIT_12, BFIELD_SIZEinBits_3);
defineBitFieldTrident( AB_SEL,               uint16_t, TRIDENT_ADDR24,  BFIELD_STARTBIT_11, BFIELD_SIZEinBits_1);
defineBitFieldTrident( SSI_TS,               uint16_t, TRIDENT_ADDR24,  BFIELD_STARTBIT_10, BFIELD_SIZEinBits_1);
defineBitFieldTrident( PMA_BIAS,             uint16_t, TRIDENT_ADDR24,  BFIELD_STARTBIT_8, BFIELD_SIZEinBits_2);

defineBitFieldTrident( SD_MODE,              uint16_t, TRIDENT_ADDR24,  BFIELD_STARTBIT_7, BFIELD_SIZEinBits_1);
defineBitFieldTrident( FHP1,                 uint16_t, TRIDENT_ADDR24,  BFIELD_STARTBIT_4, BFIELD_SIZEinBits_3);
defineBitFieldTrident( FHP2,                 uint16_t, TRIDENT_ADDR24,  BFIELD_STARTBIT_0, BFIELD_SIZEinBits_4);

defineBitFieldTrident( RXSDL_HI_C,           uint16_t, TRIDENT_ADDR25,  BFIELD_STARTBIT_15, BFIELD_SIZEinBits_1);
defineBitFieldTrident( TRK_HIGH,             uint16_t, TRIDENT_ADDR25,  BFIELD_STARTBIT_8,  BFIELD_SIZEinBits_7);
defineBitFieldTrident( FREE_RUN,             uint16_t, TRIDENT_ADDR25,  BFIELD_STARTBIT_7,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( TRK_LOW,              uint16_t, TRIDENT_ADDR25,  BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_7);

defineBitFieldTrident( DEC_DIV,              uint16_t, TRIDENT_ADDR26,  BFIELD_STARTBIT_10, BFIELD_SIZEinBits_6);
defineBitFieldTrident( RXDIG_DIV,            uint16_t, TRIDENT_ADDR26,  BFIELD_STARTBIT_6,  BFIELD_SIZEinBits_4);
defineBitFieldTrident( AGC_CLK,              uint16_t, TRIDENT_ADDR26,  BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_6);

defineBitFieldTrident( ADPT_DLY_TMR,         uint16_t, TRIDENT_ADDR27,  BFIELD_STARTBIT_8,  BFIELD_SIZEinBits_8);
defineBitFieldTrident( BS_DLY_TMR,           uint16_t, TRIDENT_ADDR27,  BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_8);


defineBitFieldTrident( STEP_OFFSET,          uint16_t, TRIDENT_ADDR28,  BFIELD_STARTBIT_13, BFIELD_SIZEinBits_3);
defineBitFieldTrident( STEP_THRESH,          uint16_t, TRIDENT_ADDR28,  BFIELD_STARTBIT_10, BFIELD_SIZEinBits_3);
defineBitFieldTrident( RXSC_SEL,             uint16_t, TRIDENT_ADDR28,  BFIELD_STARTBIT_8,  BFIELD_SIZEinBits_2);
defineBitFieldTrident( STEP_SLOT,            uint16_t, TRIDENT_ADDR28,  BFIELD_STARTBIT_7,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( FE_OFF_A,             uint16_t, TRIDENT_ADDR28,  BFIELD_STARTBIT_6,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( AGC_MAX_A,            uint16_t, TRIDENT_ADDR28,  BFIELD_STARTBIT_5,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( DC_CALEN,             uint16_t, TRIDENT_ADDR28,  BFIELD_STARTBIT_4,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( SEQMGR_EN,            uint16_t, TRIDENT_ADDR28,  BFIELD_STARTBIT_3,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( AGCFLAGEN,            uint16_t, TRIDENT_ADDR28,  BFIELD_STARTBIT_2,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( FBC_TMR,              uint16_t, TRIDENT_ADDR28,  BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_2);

defineBitFieldTrident( AGC_STEP_CMP,         uint16_t, TRIDENT_ADDR29,  BFIELD_STARTBIT_8,  BFIELD_SIZEinBits_8);
defineBitFieldTrident( BB2P_Q,               uint16_t, TRIDENT_ADDR29,  BFIELD_STARTBIT_5,  BFIELD_SIZEinBits_3);
defineBitFieldTrident( BW,                   uint16_t, TRIDENT_ADDR29,  BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_5);

defineBitFieldTrident( AGCLVL,               uint16_t, TRIDENT_ADDR2A,  BFIELD_STARTBIT_13, BFIELD_SIZEinBits_3);
defineBitFieldTrident( NAGC_DIV,             uint16_t, TRIDENT_ADDR2A,  BFIELD_STARTBIT_11, BFIELD_SIZEinBits_2);
defineBitFieldTrident( FAGC_DIV,             uint16_t, TRIDENT_ADDR2A,  BFIELD_STARTBIT_8, BFIELD_SIZEinBits_3);
defineBitFieldTrident( FAGC_STEPS,           uint16_t, TRIDENT_ADDR2A,  BFIELD_STARTBIT_5, BFIELD_SIZEinBits_3);
defineBitFieldTrident( RAGC_DIV,             uint16_t, TRIDENT_ADDR2A,  BFIELD_STARTBIT_2, BFIELD_SIZEinBits_3);
defineBitFieldTrident( RAGC_PHASE,           uint16_t, TRIDENT_ADDR2A,  BFIELD_STARTBIT_0, BFIELD_SIZEinBits_2);

defineBitFieldTrident( AGC_DAC_MODE,         uint16_t, TRIDENT_ADDR2B,  BFIELD_STARTBIT_15, BFIELD_SIZEinBits_1);
defineBitFieldTrident( RF_STEPEN,            uint16_t, TRIDENT_ADDR2B,  BFIELD_STARTBIT_14, BFIELD_SIZEinBits_1);
defineBitFieldTrident( AUTO_AGC,             uint16_t, TRIDENT_ADDR2B,  BFIELD_STARTBIT_13, BFIELD_SIZEinBits_1);
defineBitFieldTrident( CIC_OFFSET,           uint16_t, TRIDENT_ADDR2B,  BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_13);


defineBitFieldTrident( AUX_DACBIT0,          uint16_t, TRIDENT_ADDR2C,  BFIELD_STARTBIT_15, BFIELD_SIZEinBits_1);
defineBitFieldTrident( HPDC_HOLD,            uint16_t, TRIDENT_ADDR2C,  BFIELD_STARTBIT_14, BFIELD_SIZEinBits_1);
defineBitFieldTrident( AGC_DAC_VREF,         uint16_t, TRIDENT_ADDR2C,  BFIELD_STARTBIT_11, BFIELD_SIZEinBits_3);
defineBitFieldTrident( AGCHIGH,              uint16_t, TRIDENT_ADDR2C,  BFIELD_STARTBIT_10, BFIELD_SIZEinBits_1);
defineBitFieldTrident( AUX_DACBIT10_1,       uint16_t, TRIDENT_ADDR2C,  BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_10);
// this define is the same as AUX_DACBIT10_1
//defineBitFieldTrident( AUX_DAC,              uint16_t, TRIDENT_ADDR2C,  BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_10);


defineBitFieldTrident( MREF_DIV,             uint16_t, TRIDENT_ADDR2D,  BFIELD_STARTBIT_12, BFIELD_SIZEinBits_4);
defineBitFieldTrident( MADP_TMR,             uint16_t, TRIDENT_ADDR2D,  BFIELD_STARTBIT_8,  BFIELD_SIZEinBits_4);
// d7 NOT AVAILABLE
defineBitFieldTrident( VMULT_SEL,            uint16_t, TRIDENT_ADDR2D,  BFIELD_STARTBIT_6,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( MCP_GAIN,             uint16_t, TRIDENT_ADDR2D,  BFIELD_STARTBIT_3,  BFIELD_SIZEinBits_3);
defineBitFieldTrident( MCPTEST,              uint16_t, TRIDENT_ADDR2D,  BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_3);

//d15-d14 are spares
defineBitFieldTrident( CLK_ACC,              uint16_t, TRIDENT_ADDR2E,  BFIELD_STARTBIT_12, BFIELD_SIZEinBits_2);
defineBitFieldTrident( MLBPRCS_SEL,          uint16_t, TRIDENT_ADDR2E,  BFIELD_STARTBIT_11, BFIELD_SIZEinBits_1);
defineBitFieldTrident( CLK_IN_SEL,           uint16_t, TRIDENT_ADDR2E,  BFIELD_STARTBIT_10, BFIELD_SIZEinBits_1);
defineBitFieldTrident( MACC,                 uint16_t, TRIDENT_ADDR2E,  BFIELD_STARTBIT_8,  BFIELD_SIZEinBits_2);
defineBitFieldTrident( CLK_NUM_16_23,        uint16_t, TRIDENT_ADDR2E,  BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_8);
// 32 bit access
defineBitFieldTrident( CLK_NUM,              uint32_t, BFIELD_BYTEOFFSET_CLKNUM,  BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_24);

defineBitFieldTrident( CLK_NUM_0_15,         uint16_t, TRIDENT_ADDR2F,  BFIELD_STARTBIT_0, BFIELD_SIZEinBits_16);

defineBitFieldTrident( CLK_R,                uint16_t, TRIDENT_ADDR30,  BFIELD_STARTBIT_8, BFIELD_SIZEinBits_8);
defineBitFieldTrident( CLK_N,                uint16_t, TRIDENT_ADDR30,  BFIELD_STARTBIT_0, BFIELD_SIZEinBits_8);


defineBitFieldTrident( MN_SYN_TRK_SEL,       uint16_t, TRIDENT_ADDR31,  BFIELD_STARTBIT_15, BFIELD_SIZEinBits_1);
// D14 spare
defineBitFieldTrident( TCLK_DIV,             uint16_t, TRIDENT_ADDR31,  BFIELD_STARTBIT_12, BFIELD_SIZEinBits_2);
defineBitFieldTrident( TCLK_DIV_SEL,         uint16_t, TRIDENT_ADDR31,  BFIELD_STARTBIT_11, BFIELD_SIZEinBits_1);
// bit D8-10 not available
defineBitFieldTrident( VMULT_DIV,            uint16_t, TRIDENT_ADDR31,  BFIELD_STARTBIT_6,  BFIELD_SIZEinBits_2);
defineBitFieldTrident( CLK_DIV,              uint16_t, TRIDENT_ADDR31,  BFIELD_STARTBIT_4,  BFIELD_SIZEinBits_2);
// bit D3 not available
defineBitFieldTrident( CLKCP_TEST,           uint16_t, TRIDENT_ADDR31,  BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_3);

defineBitFieldTrident( ESC_DIVSEL,           uint16_t, TRIDENT_ADDR32,  BFIELD_STARTBIT_13, BFIELD_SIZEinBits_3);
defineBitFieldTrident( ES_STEER_EN,          uint16_t, TRIDENT_ADDR32,  BFIELD_STARTBIT_12, BFIELD_SIZEinBits_1);
defineBitFieldTrident( ES_BIAS_EN,           uint16_t, TRIDENT_ADDR32,  BFIELD_STARTBIT_11, BFIELD_SIZEinBits_1);
defineBitFieldTrident( ES_DIV_TEST,          uint16_t, TRIDENT_ADDR32,  BFIELD_STARTBIT_10, BFIELD_SIZEinBits_1);
defineBitFieldTrident( ES_SEL1,              uint16_t, TRIDENT_ADDR32,  BFIELD_STARTBIT_9,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( ES_CP_EN,             uint16_t, TRIDENT_ADDR32,  BFIELD_STARTBIT_8,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( ES_D16_BYP,           uint16_t, TRIDENT_ADDR32,  BFIELD_STARTBIT_7,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( ES_NUD_BYP,           uint16_t, TRIDENT_ADDR32,  BFIELD_STARTBIT_6,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( ES_NUD_MUL_BYP,       uint16_t, TRIDENT_ADDR32,  BFIELD_STARTBIT_5,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( ES_SEL3,              uint16_t, TRIDENT_ADDR32,  BFIELD_STARTBIT_4,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( ES_VCO_STEER,         uint16_t, TRIDENT_ADDR32,  BFIELD_STARTBIT_3,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( ESD2_EN,              uint16_t, TRIDENT_ADDR32,  BFIELD_STARTBIT_2,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( ES_CP_BIAS_EN,        uint16_t, TRIDENT_ADDR32,  BFIELD_STARTBIT_1,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( ES_NUD_EN,            uint16_t, TRIDENT_ADDR32,  BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_1);

// D15 NOT AVAILABLE
defineBitFieldTrident( ADAPT,                uint16_t, TRIDENT_ADDR33, BFIELD_STARTBIT_14, BFIELD_SIZEinBits_1);
defineBitFieldTrident( RX_DIG_BS,            uint16_t, TRIDENT_ADDR33, BFIELD_STARTBIT_13, BFIELD_SIZEinBits_1);
defineBitFieldTrident( AGC_BS,               uint16_t, TRIDENT_ADDR33, BFIELD_STARTBIT_12, BFIELD_SIZEinBits_1);
defineBitFieldTrident( SD_BS,                uint16_t, TRIDENT_ADDR33, BFIELD_STARTBIT_11, BFIELD_SIZEinBits_1);
defineBitFieldTrident( FE_EN,                uint16_t, TRIDENT_ADDR33, BFIELD_STARTBIT_10, BFIELD_SIZEinBits_1);
defineBitFieldTrident( RX_BB_BS,             uint16_t, TRIDENT_ADDR33, BFIELD_STARTBIT_9,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( TRACK_OSCEN,          uint16_t, TRIDENT_ADDR33, BFIELD_STARTBIT_8,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( AGC_DAC,              uint16_t, TRIDENT_ADDR33, BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_8);

defineBitFieldTrident( SSI_MODE,             uint16_t, TRIDENT_ADDR34, BFIELD_STARTBIT_13, BFIELD_SIZEinBits_3);
defineBitFieldTrident( RF_STEP,              uint16_t, TRIDENT_ADDR34, BFIELD_STARTBIT_12, BFIELD_SIZEinBits_1);
defineBitFieldTrident( FAST_AGC,             uint16_t, TRIDENT_ADDR34, BFIELD_STARTBIT_11, BFIELD_SIZEinBits_1);
defineBitFieldTrident( AGC_PRELOAD,          uint16_t, TRIDENT_ADDR34, BFIELD_STARTBIT_10, BFIELD_SIZEinBits_1);
defineBitFieldTrident( ADAPTEN,              uint16_t, TRIDENT_ADDR34, BFIELD_STARTBIT_9,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( RX_BS,                uint16_t, TRIDENT_ADDR34, BFIELD_STARTBIT_8,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( PMA_AGC,              uint16_t, TRIDENT_ADDR34, BFIELD_STARTBIT_6,  BFIELD_SIZEinBits_2);
defineBitFieldTrident( AMP_AGC,              uint16_t, TRIDENT_ADDR34, BFIELD_STARTBIT_3,  BFIELD_SIZEinBits_3);
defineBitFieldTrident( BUFGAIN,              uint16_t, TRIDENT_ADDR34, BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_3);

defineBitFieldTrident( RXSM_ASPI_EN,         uint16_t, TRIDENT_ADDR35, BFIELD_STARTBIT_15, BFIELD_SIZEinBits_1);
defineBitFieldTrident( SYN_ADAPTEN,          uint16_t, TRIDENT_ADDR35, BFIELD_STARTBIT_14, BFIELD_SIZEinBits_1);
//D13 NOT AVAILABLE
defineBitFieldTrident( BSAVE_ALL,            uint16_t, TRIDENT_ADDR35, BFIELD_STARTBIT_12, BFIELD_SIZEinBits_1);
defineBitFieldTrident( BSAVE_SYN_ALL,        uint16_t, TRIDENT_ADDR35, BFIELD_STARTBIT_11, BFIELD_SIZEinBits_1);
defineBitFieldTrident( BSAVE_MAIN_SYN,       uint16_t, TRIDENT_ADDR35, BFIELD_STARTBIT_10, BFIELD_SIZEinBits_1);
defineBitFieldTrident( MFADJ,                uint16_t, TRIDENT_ADDR35, BFIELD_STARTBIT_8,  BFIELD_SIZEinBits_2);
defineBitFieldTrident( MAINNUM_16_23,        uint16_t, TRIDENT_ADDR35, BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_8);
// 32 bit access
defineBitFieldTrident( MAINNUM,              uint32_t, BFIELD_BYTEOFFSET_MAINNM,  BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_24);

defineBitFieldTrident( MAINNUM_0_15,         uint16_t, TRIDENT_ADDR36, BFIELD_STARTBIT_0, BFIELD_SIZEinBits_16);

defineBitFieldTrident( MNLDADJ,              uint16_t, TRIDENT_ADDR37, BFIELD_STARTBIT_13,  BFIELD_SIZEinBits_3);
defineBitFieldTrident( ADPT_TRKL_EN,         uint16_t, TRIDENT_ADDR37, BFIELD_STARTBIT_11,  BFIELD_SIZEinBits_2);
defineBitFieldTrident( VSUP_OUT,             uint16_t, TRIDENT_ADDR37, BFIELD_STARTBIT_10,  BFIELD_SIZEinBits_1);
defineBitFieldTrident( MAINND,               uint16_t, TRIDENT_ADDR37, BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_10);

defineBitFieldTrident( GPO,                  uint16_t, TRIDENT_ADDR38, BFIELD_STARTBIT_8, BFIELD_SIZEinBits_8);
defineBitFieldTrident( GPO_8,                uint16_t, TRIDENT_ADDR38, BFIELD_STARTBIT_15, BFIELD_SIZEinBits_1);
defineBitFieldTrident( GPO_7,                uint16_t, TRIDENT_ADDR38, BFIELD_STARTBIT_14, BFIELD_SIZEinBits_1);
defineBitFieldTrident( GPO_6,                uint16_t, TRIDENT_ADDR38, BFIELD_STARTBIT_13, BFIELD_SIZEinBits_1);
defineBitFieldTrident( GPO_5,                uint16_t, TRIDENT_ADDR38, BFIELD_STARTBIT_12, BFIELD_SIZEinBits_1);
defineBitFieldTrident( GPO_4,                uint16_t, TRIDENT_ADDR38, BFIELD_STARTBIT_11, BFIELD_SIZEinBits_1);
defineBitFieldTrident( GPO_3,                uint16_t, TRIDENT_ADDR38, BFIELD_STARTBIT_10, BFIELD_SIZEinBits_1);
defineBitFieldTrident( GPO_2,                uint16_t, TRIDENT_ADDR38, BFIELD_STARTBIT_9, BFIELD_SIZEinBits_1);
defineBitFieldTrident( GPO_1,                uint16_t, TRIDENT_ADDR38, BFIELD_STARTBIT_8, BFIELD_SIZEinBits_1);
defineBitFieldTrident( BSAVE_ESCORT,         uint16_t, TRIDENT_ADDR38, BFIELD_STARTBIT_7, BFIELD_SIZEinBits_1);
defineBitFieldTrident( ES_SEL2,              uint16_t, TRIDENT_ADDR38, BFIELD_STARTBIT_6, BFIELD_SIZEinBits_1);
defineBitFieldTrident( NUD,                  uint16_t, TRIDENT_ADDR38, BFIELD_STARTBIT_0, BFIELD_SIZEinBits_6);

defineBitFieldTrident( ATTEN_I,              uint16_t, TRIDENT_ADDR39, BFIELD_STARTBIT_8,  BFIELD_SIZEinBits_8);
defineBitFieldTrident( ATTEN_Q,              uint16_t, TRIDENT_ADDR39, BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_8);

defineBitFieldTrident( BSAVE_TX,             uint16_t, TRIDENT_ADDR3A, BFIELD_STARTBIT_15, BFIELD_SIZEinBits_1);
defineBitFieldTrident( CEFBEN,               uint16_t, TRIDENT_ADDR3A, BFIELD_STARTBIT_14, BFIELD_SIZEinBits_1);
//D13 IS A SPARE
defineBitFieldTrident( BSAVE_TXR,            uint16_t, TRIDENT_ADDR3A, BFIELD_STARTBIT_12, BFIELD_SIZEinBits_1);
defineBitFieldTrident( DC_UPDATE,            uint16_t, TRIDENT_ADDR3A, BFIELD_STARTBIT_11, BFIELD_SIZEinBits_1);
defineBitFieldTrident( EF_DC_UPDATE,         uint16_t, TRIDENT_ADDR3A, BFIELD_STARTBIT_10, BFIELD_SIZEinBits_1);
// D8-9 ARE SPARES
defineBitFieldTrident( STATT_IQ,             uint16_t, TRIDENT_ADDR3A, BFIELD_STARTBIT_4, BFIELD_SIZEinBits_4);
defineBitFieldTrident( STATT_EF,             uint16_t, TRIDENT_ADDR3A, BFIELD_STARTBIT_0, BFIELD_SIZEinBits_4);

// D15-13 are spares
defineBitFieldTrident( NTXBW,                uint16_t, TRIDENT_ADDR3B, BFIELD_STARTBIT_11, BFIELD_SIZEinBits_3);
defineBitFieldTrident( PWRCTL,               uint16_t, TRIDENT_ADDR3B, BFIELD_STARTBIT_0, BFIELD_SIZEinBits_10);

defineBitFieldTrident( GPO5_EN,              uint16_t, TRIDENT_ADDR3C, BFIELD_STARTBIT_15, BFIELD_SIZEinBits_1);
defineBitFieldTrident( GPO6_EN,              uint16_t, TRIDENT_ADDR3C, BFIELD_STARTBIT_14, BFIELD_SIZEinBits_1);
defineBitFieldTrident( GPO7_EN,              uint16_t, TRIDENT_ADDR3C, BFIELD_STARTBIT_13, BFIELD_SIZEinBits_1);
defineBitFieldTrident( GPO8_EN,              uint16_t, TRIDENT_ADDR3C, BFIELD_STARTBIT_12, BFIELD_SIZEinBits_1);
// D10-11 ARE SPARES
defineBitFieldTrident( A0_ENV,               uint16_t, TRIDENT_ADDR3C, BFIELD_STARTBIT_0, BFIELD_SIZEinBits_10);

// D10-15 ARE SPARES
defineBitFieldTrident( A1_ENV,               uint16_t, TRIDENT_ADDR3D, BFIELD_STARTBIT_0, BFIELD_SIZEinBits_10);

// D13-15 ARE SPARES
defineBitFieldTrident( SSI_DRV,              uint16_t, TRIDENT_ADDR3E, BFIELD_STARTBIT_12, BFIELD_SIZEinBits_1);
defineBitFieldTrident( AUXCEPOL,             uint16_t, TRIDENT_ADDR3E, BFIELD_STARTBIT_10, BFIELD_SIZEinBits_2);
defineBitFieldTrident( A2_ENV,               uint16_t, TRIDENT_ADDR3E, BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_10);

defineBitFieldTrident( RX_EVENT1,            uint16_t, TRIDENT_ADDR3F, BFIELD_STARTBIT_8,  BFIELD_SIZEinBits_8);
defineBitFieldTrident( RX_EVENT2,            uint16_t, TRIDENT_ADDR3F, BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_8);

defineBitFieldTrident( REFIN_DS_EN,          uint16_t, TRIDENT_ADDR40, BFIELD_STARTBIT_15,  BFIELD_SIZEinBits_1);  
defineBitFieldTrident( REF_OSC_OUT_DS_EN,    uint16_t, TRIDENT_ADDR40, BFIELD_STARTBIT_14,  BFIELD_SIZEinBits_1);  
defineBitFieldTrident( AUXDAC_DS_EN,         uint16_t, TRIDENT_ADDR40, BFIELD_STARTBIT_13,  BFIELD_SIZEinBits_1);  
defineBitFieldTrident( SF_OUT_DS_EN,         uint16_t, TRIDENT_ADDR40, BFIELD_STARTBIT_12,  BFIELD_SIZEinBits_1);  
defineBitFieldTrident( CLK_SYN_DS_EN,        uint16_t, TRIDENT_ADDR40, BFIELD_STARTBIT_11,  BFIELD_SIZEinBits_1);  
defineBitFieldTrident( VMULT_DS_EN,          uint16_t, TRIDENT_ADDR40, BFIELD_STARTBIT_10,  BFIELD_SIZEinBits_1);  
defineBitFieldTrident( CLK_OUT_DS_EN,        uint16_t, TRIDENT_ADDR40, BFIELD_STARTBIT_9,  BFIELD_SIZEinBits_1); 
defineBitFieldTrident( TCLK_OUT_DS_EN,       uint16_t, TRIDENT_ADDR40, BFIELD_STARTBIT_8,  BFIELD_SIZEinBits_1);  
defineBitFieldTrident( REFIN_EN,             uint16_t, TRIDENT_ADDR40, BFIELD_STARTBIT_7,  BFIELD_SIZEinBits_1);  
defineBitFieldTrident( REF_OSC_OUT_EN,       uint16_t, TRIDENT_ADDR40, BFIELD_STARTBIT_6,  BFIELD_SIZEinBits_1);  
defineBitFieldTrident( AUXDAC_EN,            uint16_t, TRIDENT_ADDR40, BFIELD_STARTBIT_5,  BFIELD_SIZEinBits_1);  
defineBitFieldTrident( SF_OUT_EN,            uint16_t, TRIDENT_ADDR40, BFIELD_STARTBIT_4,  BFIELD_SIZEinBits_1); 
defineBitFieldTrident( CLK_SYN_EN,           uint16_t, TRIDENT_ADDR40, BFIELD_STARTBIT_3,  BFIELD_SIZEinBits_1);  
defineBitFieldTrident( VMULT_EN,             uint16_t, TRIDENT_ADDR40, BFIELD_STARTBIT_2,  BFIELD_SIZEinBits_1);  
defineBitFieldTrident( CLK_OUT_EN,           uint16_t, TRIDENT_ADDR40, BFIELD_STARTBIT_1,  BFIELD_SIZEinBits_1);  
defineBitFieldTrident( TCLK_OUT_EN,          uint16_t, TRIDENT_ADDR40, BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_1);

defineBitFieldTrident( AGC_NAGC_DIV0,        uint16_t, TRIDENT_ADDR41, BFIELD_STARTBIT_12,  BFIELD_SIZEinBits_4);   
defineBitFieldTrident( AGC_NAGC_DIV1,        uint16_t, TRIDENT_ADDR41, BFIELD_STARTBIT_8,  BFIELD_SIZEinBits_4);   
defineBitFieldTrident( AGC_NAGC_DIV2,        uint16_t, TRIDENT_ADDR41, BFIELD_STARTBIT_4,  BFIELD_SIZEinBits_4);    
defineBitFieldTrident( AGC_NAGC_3DIV_EN,     uint16_t, TRIDENT_ADDR41, BFIELD_STARTBIT_3,  BFIELD_SIZEinBits_1);  
defineBitFieldTrident( AGC_CLK_DIV_MSB,      uint16_t, TRIDENT_ADDR41, BFIELD_STARTBIT_1,  BFIELD_SIZEinBits_2);   
defineBitFieldTrident( RX4GEN,               uint16_t, TRIDENT_ADDR41, BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_1);

defineBitFieldTrident( AGC_LOW,               uint16_t, TRIDENT_ADDR42, BFIELD_STARTBIT_15,  BFIELD_SIZEinBits_1);   
defineBitFieldTrident( AGC_SOS_THRESH0,               uint16_t, TRIDENT_ADDR42, BFIELD_STARTBIT_8,  BFIELD_SIZEinBits_7);   
defineBitFieldTrident( AGC_PROG_THRESH_EN,               uint16_t, TRIDENT_ADDR42, BFIELD_STARTBIT_7,  BFIELD_SIZEinBits_1);   
defineBitFieldTrident( AGC_SOS_THRESH1,               uint16_t, TRIDENT_ADDR42, BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_7);

// D15-87 SPARES   
defineBitFieldTrident( AGC_SOS_THRESH2,               uint16_t, TRIDENT_ADDR43, BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_7);

// D15-8 SPARES  
defineBitFieldTrident( DIV_SEL,               uint16_t, TRIDENT_ADDR44, BFIELD_STARTBIT_7,  BFIELD_SIZEinBits_1);     
defineBitFieldTrident( JITTER_EN,               uint16_t, TRIDENT_ADDR44, BFIELD_STARTBIT_6,  BFIELD_SIZEinBits_1);  
defineBitFieldTrident( CNTR_EN,               uint16_t, TRIDENT_ADDR44, BFIELD_STARTBIT_5,  BFIELD_SIZEinBits_1);  
defineBitFieldTrident( HB_LB,               uint16_t, TRIDENT_ADDR44, BFIELD_STARTBIT_4,  BFIELD_SIZEinBits_1);  
defineBitFieldTrident( REF_DEL,               uint16_t, TRIDENT_ADDR44, BFIELD_STARTBIT_0,  BFIELD_SIZEinBits_4);

typedef TridentSnippetStatus_s TridentSnippetStatus_t[TRIDENT_NUM_SNIPPETS];


// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* TridentBitFieldDefs_H */

// }}}RME
