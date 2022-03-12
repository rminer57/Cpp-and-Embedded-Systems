// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::tomahawk::tomahawkDefault'

#ifndef tomahawkDefault_H
#define tomahawkDefault_H

#ifdef PRAGMA
#pragma interface "tomahawkDefault.h"
#endif

#include <HALtestLib_win32.h>
#include <bitfield.h>
#include <rf_audio_std_types.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h> 

//
// Enumerated identifier values for all Tomahawk SPI registers
//
// Enumerates/Values to be used by the client to reference 
// the IC registers.

	enum TomahawkRegEnum_t
	{
	    DN_DLY 	        =   1
	  , ABR_SEL         =   2
	  , ABF_SEL         =   3
	  , SDTX_POL 		=   4
	  , SSI_DLY 		=   5
	  , SC_SEL 		    =   6
	  , OVSX 			=   7
	  , TXC_REF 		=   8
	  , ABW 			=   9
	  , TXF_REF 		= 10
	  , OVS_REF 		= 11
	  , I_DCOFS 		= 12
	  , GPIO_TRIST1 	= 13
	  , GPIO_TRIST2 	= 14
	  , GPIO_TRIST3 	= 15
	  , GPIO_TRIST4 	= 16
	  , GPIO_TRIST5 	= 17
	  , GPIO_TRIST6 	= 18
	  , WFG_REF 		= 19
	  , DCOC_SIGN_EF 	= 20
	  , TX_DCOC_SIGN 	= 21
	  , AOC_HIB 		= 22
	  , X1DR0 			= 23
	  , DC_CORRECT 	    = 24
	  , HP_SEL 		    = 25
	  , ATT_SSI 		= 26
	  , X1DR1 			= 27
	  , EN_DLY_MUX 	    = 28
	  , X1DR2 			= 29
	  , EN_OVS_DLYD 	= 30
	  , X1DR3 			= 31
	  , SYMB_REF 		= 32
	  , X1DR4 			= 33
	  , TRIST_PAB 		= 34
	  , BSAVE_EF 		= 35
	  , BSAVE_Q 		= 36
	  , BSAVE_I 		= 37
	  , BSAVE_WG 		= 38
	  , BSAVE_PAB 	= 39
	  , X1DR5 			= 40
	  , TXCONFIG 		= 41
	  , LP_ADD 		= 42
	  , X2DR0 			= 43
	  , X2DR1 			= 44
	  , X2DR2 			= 45
	  , X2DR3 			= 46
	  , X2DR4 			= 47
	  , X2DR5 			= 48
	  , X3DR0 			= 49
	  , X3DR1 			= 50
	  , X3DR2 		= 51
	  , X3DR3 		= 52
	  , X3DR4 		= 53
	  , X3DR5 		= 54
	  , X4DR0 		= 55
	  , X4DR1 		= 56
	  , X4DR2 		= 57
	  , X4DR3 		= 58
	  , X4DR4 		= 59
	  , X4DR5 		= 60
	  , DCOC_REF 		= 61
	  , TM_BUFF 		= 62
	  , EF_SEL 		= 63
	  , EF_DC_CORRECT 	= 64
	  , EF_DLY 		= 65
	  , TEST_MUX 		= 66
	  , TR_LOWER 		= 67
	  , TR_UPPER 		= 68
	  , DAC_TEST 		= 69
	  , DAC_TEST_EN 	= 70
	  , FIRCLK_SB 		= 71
	  , LAST_INT 		= 72
	  , IDC_DAC 		= 73
	  , DC_DAC_GM 		= 74
	  , QDC_DAC 		= 75
	  , DCOCL_HOLD 		= 76
	  , DCOC_LPF_BW 	= 77
	  , KDLPT 		= 78
	  , THP2 		= 79
	  , THP1 		= 80
	  , FHP3 		= 81
	  , ADAC_BIAS 		= 82
	  , SOS_MUX 		= 83
	  , SM_AGC_EN 		= 84
	  , FHP2 		= 85
	  , FHP1 		= 86
	  , SD_MODE 		= 87
	  , PMA_BIAS 		= 88
	  , SSI_TS 		= 89
	  , AB_SEL 		= 90
	  , DBW 		= 91
	  , PMA_BP 		= 92
	  , TRK_LOW 		= 93
	  , FREE_RUN 		= 94
	  , TRK_HIGH 		= 95
	  , RXSC_SEL 		= 96
	  , AGC_CLK 		= 97
	  , RXDIG_DIV 		= 98
	  , DEC_DIV 		= 99
	  , BS_DLY_TMR 		= 100
	  , ADPT_DLY_TMR 	= 101
	  , FBC_TMR 		= 102
	  , AGCFLAGEN 		= 103
	  , SEQMGR_EN 		= 104
	  , DC_CALEN 		= 105
	  , AGC_MAX_A 		= 106
	  , FE_OFF_A 		= 107
	  , STEP_SLOT 		= 108
	  , AGC_DAC_VREF 	= 109
	  , STEP_THRESH 	= 110
	  , STEP_OFFSET 	= 111
	  , BW 			= 112
	  , BB2P_Q 		= 113
	  , AGC_STEP_CMP 	= 114
	  , RAGC_PHASE 		= 115
	  , RAGC_DIV 		= 116
	  , FAGC_STEPS 		= 117
	  , FAGC_DIV 		= 118
	  , NAGC_DIV 		= 119
	  , AGCLVL 		= 120
	  , CIC_OFFSET 		= 121
	  , AUTO_AGC 		= 122
	  , RF_STEPEN 		= 123
	  , AGC_DAC_MODE 	= 124
	  , AUX_DAC 		= 125
	  , AGCHIGH 		= 126
	  , MCPTEST 		= 127
	  , MCP_GAIN 		= 128
	  , MCRS_TMR 		= 129
	  , MADP_TMR 		= 130
	  , MREF_DIV 		= 131
	  , CLK_NUM 		= 132
	  , MACC 		= 133
	  , MND_8BIT_SEL 	= 134
	  , MLBPRCS_SEL 	= 135
	  , CLK_ACC 		= 136
	  , ROT 		= 137
	  , CLK_N 		= 138
	  , CLK_R 		= 139
	  , CLKCP_TEST 		= 140
	  , BSAVE_CLKS_SYN 	= 141
	  , CLK1_DIV 		= 142
	  , CLK2_DIV 		= 143
	  , TCLK_OUT_EN 	= 144
	  , CLK1_OUT_EN 	= 145
	  , CLK2_OUT_EN 	= 146
	  , TCLK_DIV_SEL 	= 147
	  , TCLK_DIV 		= 148
	  , COB1_SEL 		= 149
	  , COB2_SEL 		= 150
	  , BSAVE_CRS_DAC 	= 151
	  , ES_CP_BIAS_EN 	= 152
	  , ES_VCO_STEER2 	= 153
	  , ES_VCO_STEER1 	= 154
	  , ES_SEL3 		= 155
	  , ES_NUD_MUL_BYP 	= 156
	  , ES_NUD_BYP 		= 157
	  , ES_D16_BYP 		= 158
	  , ES_CP_EN 		= 159
	  , ES_SEL1 		= 160
	  , ES_DIV_TEST 	= 161
	  , ES_BIAS_EN 		= 162
	  , ES_STEER_EN 	= 163
	  , ES_NUD_EN 		= 164
	  , CLK2_IN_SEL 	= 165
	  , CLK1_IN_SEL 	= 166
	  , AGC_DAC 		= 167
	  , TRACK_OSCEN 	= 168
	  , RX_BB_BS 		= 169
	  , FE_EN 		= 170
	  , SD_BS 		= 171
	  , AGC_BS 		= 172
	  , RX_DIG_BS 		= 173
	  , ADAPT 		= 174
	  , AUXDAC_BS 		= 175
	  , BUFGAIN 		= 176
	  , AMP_AGC 		= 177
	  , PMA_AGC 		= 178
	  , RX_BS 		= 179
	  , ADAPTEN 		= 180
	  , AGC_PRELOAD 	= 181
	  , FAST_AGC 		= 182
	  , RF_STEP 		= 183
	  , SSI_MODE 		= 184
	  , MAINNUM 		= 185
	  , MAINNUM_0_15	= 186 	// Not accessable to user
	  , MAINNUM_16_23 	= 187 	// Not accessable to user
	  , MFADJ 		= 188
	  , BSAVE_MAIN_SYN 	= 189
	  , BSAVE_SYN_ALL 	= 190
	  , BSAVE_ALL 		= 191
	  , SF_BS 		= 192
	  , SYN_ADAPTEN 	= 193
	  , RXSM_ASPI_EN 	= 194
	  , MAINND 		= 195
	  , MCRS_DAC 		= 196
	  , NUD 		= 197
	  , ES_SEL2 		= 198
	  , BSAVE_ESCORT 	= 199
	  , GPO_1 		= 200
	  , GPO_2 		= 201
	  , GPO_3 		= 202
	  , GPO_5 		= 203
	  , GPO_6 		= 204
	  , GPO_4 		= 205
	  , CEFBEN 		= 206
	  , BSAVE_TX 		= 207
	  , ATTEN_Q 		= 208
	  , ATTEN_I 		= 209
	  , PABIASDAC 		= 210
	  , STATT_IQ 		= 211
	  , EF_DC_UPDATE 	= 212
	  , DC_UPDATE 		= 213
	  , BSAVE_TXR 		= 214
	  , PWRCTL 		= 215
	  , A0_ENV 		= 216
	  , A1_ENV 		= 217
	  , ASPI_CLK_SEL 	= 218
	  , A2_ENV 		= 219
	  , AUXCEPOL 		= 220
	  , AUXCLKDIV2 		= 221
	  , AUXCLKDIV1 		= 222
	  , RX_EVENT2 		= 223
	  , RX_EVENT1 		= 224
      , HPDC_HOLD       = 225
      , ESC_DIVSEL      = 226
      , GPO_TRIST_ALL   = 227
	  ,NUM_TOMAHAWK_REGS 	= 228
	};



// BYTE size of a Tomahawk partial SPI image buffer
#define TOMAHAWK_SNIPPET_SIZE		4

// This Macro is used to access the generic bitfield definition macro.  Based on the register bit position,
//  a partial SPI image index is determined.
// is also used to determine the partial SPI image  
#define defineICBitFieldRev(name,type,off,start,len) \
	defineBitFieldRev(name,type,off,start,len); \
        const static unsigned int name ## _RegToSnippet = ((((start)/8) + (off)) / TOMAHAWK_SNIPPET_SIZE);

#define defineICBitField(name,type,off,start,len) \
	defineBitField(name,type,off,start,len); \
        const static unsigned int name ## _RegToSnippet = ((((start)/8) + (off)) / TOMAHAWK_SNIPPET_SIZE);

// The following are the bitfield definitions for the Tomahawk image 
// defined by: 
//{Name} is the symbloic name of the bitfield
//{Type} is the base access type
//{Off} is defined as the BYTE offset from base address of the bitfield
//{Start} is defined as the bit position (0 based)
//{Len} is defined as the number of bits in the bitfield

// Tomahawk registers structures 
// NOTE: Inside the BITFIELDS the variables sequence MUST be from
//   Least Significant to Most Significant 

#ifdef OMAP_HALI_C55

// 	WORD16 - 0x00
defineICBitField( DN_DLY,		uint32_t,  0, 16, 11);
defineICBitField( ABR_SEL,	uint32_t,  0, 27,  1);
defineICBitField( ABF_SEL,	uint32_t,  0, 28,  1);
defineICBitField( SDTX_POL,	uint32_t,  0, 29,  1);
// 	WORD16 - 0x01
defineICBitField( SSI_DLY,	uint32_t,  0,  0, 12);
defineICBitField( SC_SEL,		uint32_t,  0, 12,  1);
defineICBitField( OVSX,		uint32_t,  0, 13,  2);
// 	WORD16 - 0x02
defineICBitField( TXC_REF,	uint32_t,  4, 16,  8);
defineICBitField( ABW,		uint32_t,  4, 24,  6);
// 	WORD16 - 0x03
defineICBitField( TXF_REF,	uint32_t,  4,  0, 10);
defineICBitField( OVS_REF,	uint32_t,  4, 10,  5);
// 	WORD16 - 0x04
defineICBitField( I_DCOFS,	uint32_t,  8, 16,  8);
defineICBitField( Q_DCOFS,	uint32_t,  8, 24,  8);
// 	WORD16 - 0x05
defineICBitField( GPO_TRIST_ALL,	uint32_t,  8,  0,  6);
defineICBitField( GPO_TRIST1,	uint32_t,  8,  0,  1);
defineICBitField( GPO_TRIST2,	uint32_t,  8,  1,  1);
defineICBitField( GPO_TRIST3,	uint32_t,  8,  2,  1);
defineICBitField( GPO_TRIST4,	uint32_t,  8,  3,  1);
defineICBitField( GPO_TRIST5,	uint32_t,  8,  4,  1);
defineICBitField( GPO_TRIST6,	uint32_t,  8,  5,  1);
defineICBitField( WFG_REF,	uint32_t,  8,  6,  5);
defineICBitField( DCOC_SIGN_EF,	uint32_t,  8, 11,  1);
defineICBitField( TX_DCOC_SIGN,	uint32_t,  8, 12,  1);
defineICBitField( AOC_HIB,	uint32_t,  8, 13,  1);
// 	WORD16 - 0x06	
defineICBitField( X1DR0,		uint32_t, 12, 16, 10);
//defineICBitField( ESC_DIVSEL,		uint32_t, 12, 26, 3);
defineICBitField( DC_CORRECT,	uint32_t, 12, 29,  1);
defineICBitField( HP_SEL,		uint32_t, 12, 30,  1);
defineICBitField( ATT_SSI,	    uint32_t, 12, 31,  1);
// 	WORD16 - 0x07
defineICBitField( X1DR1,		uint32_t, 12,  0, 10);
defineICBitField( EN_DLY_MUX,	uint32_t, 12, 10,  1);
// 	WORD16 - 0x08
defineICBitField( X1DR2,		uint32_t, 16, 16, 10);
defineICBitField( EN_OVS_DLYD,	uint32_t, 16, 26,  6);
// 	WORD16 - 0x09
defineICBitField( X1DR3,		uint32_t, 16,  0, 10);
defineICBitField( SYMB_REF,	uint32_t, 16, 10,  6);
// 	WORD16 - 0x0A
defineICBitField( X1DR4,		uint32_t, 20, 16, 10);
defineICBitField( TRIST_PAB,	uint32_t, 20, 26,  1);
defineICBitField( BSAVE_EF,	uint32_t, 20, 27,  1);
defineICBitField( BSAVE_Q,	uint32_t, 20, 28,  1);
defineICBitField( BSAVE_I,	uint32_t, 20, 29,  1);
defineICBitField( BSAVE_WG,	uint32_t, 20, 30,  1);
defineICBitField( BSAVE_PAB,	uint32_t, 20, 31,  1);
// 	WORD16 - 0x0B
defineICBitField( X1DR5,		uint32_t, 20,  0, 10);
defineICBitField( TXCONFIG,	uint32_t, 20, 10,  2);
defineICBitField( LP_ADD,		uint32_t, 20, 12,  2);
// 	WORD16 - 0x0C
defineICBitField( X2DR0,		uint32_t, 24, 16, 11);
// 	WORD16 - 0x0D
defineICBitField( X2DR1,		uint32_t, 24,  0, 11);
// 	WORD16 - 0x0E
defineICBitField( X2DR2,		uint32_t, 28, 16, 11);
// 	WORD16 - 0x0F
defineICBitField( X2DR3,		uint32_t, 28,  0, 11);
// 	WORD16 - 0x10
defineICBitField( X2DR4,		uint32_t, 32, 16, 11);
// 	WORD16 - 0x11
defineICBitField( X2DR5,		uint32_t, 32,  0, 11);
// 	WORD16 - 0x12
defineICBitField( X3DR0,		uint32_t, 36, 16, 13);
// 	WORD16 - 0x13
defineICBitField( X3DR1,		uint32_t, 36,  0, 13);
// 	WORD16 - 0x14
defineICBitField( X3DR2,		uint32_t, 40, 16, 13);
// 	WORD16 - 0x15
defineICBitField( X3DR3,		uint32_t, 40,  0, 13);
// 	WORD16 - 0x16
defineICBitField( X3DR4,		uint32_t, 44, 16, 13);
// 	WORD16 - 0x17
defineICBitField( X3DR5,		uint32_t, 44,  0, 13);
// 	WORD16 - 0x18
defineICBitField( X4DR0,		uint32_t, 48, 16, 14);
// 	WORD16 - 0x19
defineICBitField( X4DR1,		uint32_t, 48,  0, 14);
// 	WORD16 - 0x1A
defineICBitField( X4DR2,		uint32_t, 52, 16, 14);
// 	WORD16 - 0x1B
defineICBitField( X4DR3,		uint32_t, 52,  0, 14);
// 	WORD16 - 0x1C
defineICBitField( X4DR4,		uint32_t, 56, 16, 14);
// 	WORD16 - 0x1D
defineICBitField( X4DR5,		uint32_t, 56,  0, 14);
// 	WORD16 - 0x1E
defineICBitField( DCOC_REF,	uint32_t, 60, 16, 10);
defineICBitField( TM_BUFF,		uint32_t, 60, 26,  2);
defineICBitField( EF_SEL,		uint32_t, 60, 29,  2);
defineICBitField( EF_DC_CORRECT,	uint32_t, 60, 31,  1);
// 	WORD16 - 0x1F
defineICBitField( EF_DLY,		uint32_t, 60,  0,  3);
defineICBitField( TEST_MUX,	uint32_t, 60,  3,  8);
// 	WORD16 - 0x20
defineICBitField( TR_LOWER,	uint32_t, 64, 16,  8);
defineICBitField( TR_UPPER,	uint32_t, 64, 24,  8);
// 	WORD16 - 0x21
defineICBitField( DAC_TEST,	uint32_t, 64,  0, 10);
defineICBitField( DAC_TEST_EN,	uint32_t, 64, 10,  3);
defineICBitField( FIRCLK_SB,	uint32_t, 64, 13,  1);
defineICBitField( LAST_INT,	uint32_t, 64, 14,  1);
// 	WORD16 - 0x22
defineICBitField( IDC_DAC,	uint32_t, 68, 16,  6);
defineICBitField( DC_DAC_GM,	uint32_t, 68, 22,  2);
defineICBitField( QDC_DAC,	uint32_t, 68, 24,  6);
defineICBitField( DCOCL_HOLD,	uint32_t, 68, 30,  1);
defineICBitField( DCOC_LPF_BW,	uint32_t, 68, 31,  1);
// 	WORD16 - 0x23
defineICBitField( KDLPT,		uint32_t, 68,  0,  3);
defineICBitField( THP2,		uint32_t, 68,  3,  3);
defineICBitField( THP1,		uint32_t, 68,  6,  3);
defineICBitField( FHP3,		uint32_t, 68,  9,  4);
defineICBitField( ADAC_BIAS,	uint32_t, 68, 13,  1);
defineICBitField( SOS_MUX,	uint32_t, 68, 14,  1);
defineICBitField( SM_AGC_EN,	uint32_t, 68, 15,  1);
// 	WORD16 - 0x24
defineICBitField( FHP2,		uint32_t, 72, 16,  4);
defineICBitField( FHP1,		uint32_t, 72, 20,  3);
defineICBitField( SD_MODE,	uint32_t, 72, 23,  1);
defineICBitField( PMA_BIAS,	uint32_t, 72, 24,  2);
defineICBitField( SSI_TS,		uint32_t, 72, 26,  1);
defineICBitField( AB_SEL,		uint32_t, 72, 27,  1);
defineICBitField( DBW,		uint32_t, 72, 28,  3);
defineICBitField( PMA_BP,		uint32_t, 72, 31,  1);
// 	WORD16 - 0x25
defineICBitField( TRK_LOW,	uint32_t, 72,  0,  7);
defineICBitField( FREE_RUN,	uint32_t, 72,  7,  1);
defineICBitField( TRK_HIGH,	uint32_t, 72,  8,  7);
defineICBitField( RXSC_SEL,	uint32_t, 72, 15,  1);
// 	WORD16 - 0x26
defineICBitField( AGC_CLK,	uint32_t, 76, 16,  6);
defineICBitField( RXDIG_DIV,	uint32_t, 76, 22,  4);
defineICBitField( DEC_DIV,	uint32_t, 76, 26,  6);
// 	WORD16 - 0x27
defineICBitField( BS_DLY_TMR,	uint32_t, 76,  0,  8);
defineICBitField( ADPT_DLY_TMR,	uint32_t, 76,  8,  8);
// 	WORD16 - 0x28
defineICBitField( FBC_TMR,	uint32_t, 80, 16,  2);
defineICBitField( AGCFLAGEN,	uint32_t, 80, 18,  1);
defineICBitField( SEQMGR_EN,	uint32_t, 80, 19,  1);
defineICBitField( DC_CALEN,	uint32_t, 80, 20,  1);
defineICBitField( AGC_MAX_A,	uint32_t, 80, 21,  1);
defineICBitField( FE_OFF_A,	uint32_t, 80, 22,  1);
defineICBitField( STEP_SLOT,	uint32_t, 80, 23,  1);
defineICBitField( AGC_DAC_VREF,	uint32_t, 80, 24,  2);
defineICBitField( STEP_THRESH,	uint32_t, 80, 26,  3);
defineICBitField( STEP_OFFSET,	uint32_t, 80, 29,  3);
// 	WORD16 - 0x29
defineICBitField( BW,		uint32_t, 80,  0,  5);
defineICBitField( BB2P_Q,		uint32_t, 80,  5,  3);
defineICBitField( AGC_STEP_CMP,	uint32_t, 80,  8,  8);
// 	WORD16 - 0x2A
defineICBitField( RAGC_PHASE,	uint32_t, 84, 16,  2);
defineICBitField( RAGC_DIV,	uint32_t, 84, 18,  3);
defineICBitField( FAGC_STEPS,	uint32_t, 84, 21,  3);
defineICBitField( FAGC_DIV,	uint32_t, 84, 24,  3);
defineICBitField( NAGC_DIV,	uint32_t, 84, 26,  2);
defineICBitField( AGCLVL,		uint32_t, 84, 29,  3);
// 	WORD16 - 0x2B
defineICBitField( CIC_OFFSET,	uint32_t, 84,  0, 13);
defineICBitField( AUTO_AGC,	uint32_t, 84, 13,  1);
defineICBitField( RF_STEPEN,	uint32_t, 84, 14,  1);
defineICBitField( AGC_DAC_MODE,	uint32_t, 84, 15,  1);
// 	WORD16 - 0x2C
defineICBitField( AUX_DAC,	uint32_t, 88, 16,  8);
defineICBitField( AGCHIGH,	uint32_t, 88, 26,  1);
// Add new:
//defineICBitField( AGC_DAC_VREF,	uint32_t, 88, 27,  3);
//defineICBitField( HPDC_HOLD,	uint32_t, 88, 30,  1);
// 	WORD16 - 0x2D
defineICBitField( MCPTEST,	uint32_t, 88,  0,  3);
defineICBitField( MCP_GAIN,	uint32_t, 88,  3,  3);
defineICBitField( MCRS_TMR,	uint32_t, 88,  6,  2);
defineICBitField( MADP_TMR,	uint32_t, 88,  8,  4);
defineICBitField( MREF_DIV,	uint32_t, 88, 12,  3);
// 	WORD16 - 0x2E
defineICBitField( CLK_NUM,uint32_t, 92, 0,  24);
defineICBitField( CLK_NUM_16_23,uint32_t, 92, 16,  8);
defineICBitField( MACC,			uint32_t, 92, 24,  2);
defineICBitField( MND_8BIT_SEL,	uint32_t, 92, 26,  1);
defineICBitField( MLBPRCS_SEL,	uint32_t, 92, 27,  1);
defineICBitField( CLK_ACC,	uint32_t, 92, 28,  2);
defineICBitField( ROT,		uint32_t, 92, 30,  2);
// 	WORD16 - 0x2F
defineICBitField( CLK_NUM_0_15,uint32_t, 92,  0, 16);
// 	WORD16 - 0x30
defineICBitField( CLK_N,	uint32_t, 96, 16,  8);
defineICBitField( CLK_R,	uint32_t, 96, 24,  8);
// 	WORD16 - 0x31
defineICBitField( CLKCP_TEST,	uint32_t, 96,  0,  3);
defineICBitField( BSAVE_CLKS_SYN,	uint32_t, 96,  3,  1);
defineICBitField( CLK1_DIV,	uint32_t, 96,  4,  2);
defineICBitField( CLK2_DIV,	uint32_t, 96,  6,  2);
defineICBitField( TCLK_OUT_EN,	uint32_t, 96,  8,  1);
defineICBitField( CLK1_OUT_EN,	uint32_t, 96,  9,  1);
defineICBitField( CLK2_OUT_EN,	uint32_t, 96,  10,  1);
defineICBitField( TCLK_DIV_SEL,	uint32_t, 96, 11,  1);
defineICBitField( TCLK_DIV,	uint32_t, 96, 12,  2);
defineICBitField( COB1_SEL,	uint32_t, 96, 14,  1);
defineICBitField( COB2_SEL,	uint32_t, 96, 15,  1);
// 	WORD16 - 0x32
defineICBitField( BSAVE_CRS_DAC,	uint32_t, 100, 16,  1);
defineICBitField( ES_CP_BIAS_EN, 	uint32_t, 100, 17,  1);
defineICBitField( ES_VCO_STEER2,	uint32_t, 100, 18,  1);
defineICBitField( ES_VCO_STEER1,	uint32_t, 100, 19,  1);
defineICBitField( ES_SEL3,	uint32_t, 100, 20,  1);
defineICBitField( ES_NUD_MUL_BYP,	uint32_t, 100, 21,  1);
defineICBitField( ES_NUD_BYP,	uint32_t, 100, 22,  1);
defineICBitField( ES_D16_BYP,	uint32_t, 100, 23,  1);
defineICBitField( ES_CP_EN,	uint32_t, 100, 24,  1);
defineICBitField( ES_SEL1,	uint32_t, 100, 25,  1);
defineICBitField( ES_DIV_TEST,	uint32_t, 100, 26,  1);
defineICBitField( ES_BIAS_EN,	uint32_t, 100, 27,  1);
defineICBitField( ES_STEER_EN,	uint32_t, 100, 28,  1);
defineICBitField( ES_NUD_EN,	uint32_t, 100, 29,  1);
defineICBitField( CLK2_IN_SEL,	uint32_t, 100, 30,  1);
defineICBitField( CLK1_IN_SEL,	uint32_t, 100, 31,  1);
// 	WORD16 - 0x33
defineICBitField( AGC_DAC,	uint32_t, 100,  0,  8);
defineICBitField( TRACK_OSCEN,	uint32_t, 100,  8,  1);
defineICBitField( RX_BB_BS,	uint32_t, 100,  9,  1);
defineICBitField( FE_EN,		uint32_t, 100, 10,  1);
defineICBitField( SD_BS,		uint32_t, 100, 11,  1);
defineICBitField( AGC_BS,		uint32_t, 100, 12,  1);
defineICBitField( RX_DIG_BS,	uint32_t, 100, 13,  1);
defineICBitField( ADAPT,		uint32_t, 100, 14,  1);
defineICBitField( AUXDAC_BS,	uint32_t, 100, 15,  1);
// 	WORD16 - 0x34
defineICBitField( BUFGAIN,	uint32_t, 104, 16,  3);
defineICBitField( AMP_AGC,	uint32_t, 104, 19,  3);
defineICBitField( PMA_AGC,	uint32_t, 104, 22,  2);
defineICBitField( RX_BS,	uint32_t, 104, 24,  1);
defineICBitField( ADAPTEN,	uint32_t, 104, 25,  1);
defineICBitField( AGC_PRELOAD,	uint32_t, 104, 26,  1);
defineICBitField( FAST_AGC,	uint32_t, 104, 27,  1);
defineICBitField( RF_STEP,	uint32_t, 104, 28,  1);
defineICBitField( SSI_MODE,	uint32_t, 104, 29,  3);
// 	WORD16 - 0x35
defineICBitField( MAINNUM_16_23,	uint32_t, 104,  0,  8);
defineICBitField( MFADJ,		uint32_t, 104,  8,  2);
defineICBitField( BSAVE_MAIN_SYN,uint32_t, 104, 10, 1);
defineICBitField( BSAVE_SYN_ALL,uint32_t, 104, 11, 1);
defineICBitField( BSAVE_ALL,	uint32_t, 104, 12,  1);
defineICBitField( SF_BS,		uint32_t, 104, 13,  1);
defineICBitField( SYN_ADAPTEN,	uint32_t, 104, 14,  1);
defineICBitField( RXSM_ASPI_EN,	uint32_t, 104, 15,  1);
// 	WORD16 - 0x36
defineICBitField( MAINNUM_0_15,	uint32_t, 108, 16, 16);
// 	WORD16 - 0x37
defineICBitField( MAINND,	uint32_t, 108,  0, 10);
defineICBitField( MCRS_DAC,	uint32_t, 108, 10,  6);
// 	WORD16 - 0x38
defineICBitField( NUD,		uint32_t, 112, 16,  6);
defineICBitField( ES_SEL2,	uint32_t, 112, 22,  1);
defineICBitField( BSAVE_ESCORT,uint32_t, 112, 23,  1);
defineICBitField( GPO_1,	uint32_t, 112, 24,  1);
defineICBitField( GPO_2,	uint32_t, 112, 25,  1);
defineICBitField( GPO_3,	uint32_t, 112, 26,  1);
defineICBitField( GPO_4,	uint32_t, 112, 27,  1);
defineICBitField( GPO_5,	uint32_t, 112, 28,  1);
defineICBitField( GPO_6,	uint32_t, 112, 29,  1);
defineICBitField( CEFBEN,		uint32_t, 112, 30,  1);
defineICBitField( BSAVE_TX,	uint32_t, 112, 31,  1);
// 	WORD16 - 0x39
defineICBitField( ATTEN_Q,	uint32_t, 112,  0,  8);
defineICBitField( ATTEN_I,	uint32_t, 112,  8,  8);
// 	WORD16 - 0x3A
defineICBitField( PABIASDAC,	uint32_t, 116, 16,  8);
defineICBitField( STATT_IQ,	uint32_t, 116, 24,  2);
defineICBitField( EF_DC_UPDATE,uint32_t, 116, 26,  1);
defineICBitField( DC_UPDATE,	uint32_t, 116, 27,  1);
defineICBitField( BSAVE_TXR,	uint32_t, 116, 28,  1);
// 	WORD16 - 0x3B
defineICBitField( PWRCTL,		uint32_t, 116, 0, 10);
// 	WORD16 - 0x3C
defineICBitField( A0_ENV,		uint32_t, 120, 16, 10);
// 	WORD16 - 0x3D
defineICBitField( A1_ENV,		uint32_t, 120,  0, 10);
defineICBitField( ASPI_CLK_SEL,	uint32_t, 120, 10,  1);
// 	WORD16 - 0x3E
defineICBitField( A2_ENV,		uint32_t, 124, 16, 10);
defineICBitField( AUXCEPOL,	uint32_t, 124, 26,  2);
defineICBitField( AUXCLKDIV2,	uint32_t, 124, 28,  2);
defineICBitField( AUXCLKDIV1,	uint32_t, 124, 30,  2);
// 	WORD16 - 0x3F
defineICBitField( RX_EVENT2,	uint32_t, 124,  0,  8);
defineICBitField( RX_EVENT1,	uint32_t, 124,  8,  8);

#else  // for ARM9 platform with little endian

// 	WORD16 - 0x00
defineICBitFieldRev( DN_DLY,		uint32_t,  0, 16, 11);
defineICBitFieldRev( ABR_SEL,	uint32_t,  0, 27,  1);
defineICBitFieldRev( ABF_SEL,	uint32_t,  0, 28,  1);
defineICBitFieldRev( SDTX_POL,	uint32_t,  0, 29,  1);
// 	WORD16 - 0x01
defineICBitFieldRev( SSI_DLY,	uint32_t,  0,  0, 12);
defineICBitFieldRev( SC_SEL,		uint32_t,  0, 12,  1);
defineICBitFieldRev( OVSX,		uint32_t,  0, 13,  2);
// 	WORD16 - 0x02
defineICBitFieldRev( TXC_REF,	uint32_t,  4, 16,  8);
defineICBitFieldRev( ABW,		uint32_t,  4, 24,  6);
// 	WORD16 - 0x03
defineICBitFieldRev( TXF_REF,	uint32_t,  4,  0, 10);
defineICBitFieldRev( OVS_REF,	uint32_t,  4, 10,  5);
// 	WORD16 - 0x04
defineICBitFieldRev( I_DCOFS,	uint32_t,  8, 16,  8);
defineICBitFieldRev( Q_DCOFS,	uint32_t,  8, 24,  8);
// 	WORD16 - 0x05
defineICBitFieldRev( GPO_TRIST_ALL,	uint32_t,  8,  0,  6);
defineICBitFieldRev( GPO_TRIST1,	uint32_t,  8,  0,  1);
defineICBitFieldRev( GPO_TRIST2,	uint32_t,  8,  1,  1);
defineICBitFieldRev( GPO_TRIST3,	uint32_t,  8,  2,  1);
defineICBitFieldRev( GPO_TRIST4,	uint32_t,  8,  3,  1);
defineICBitFieldRev( GPO_TRIST5,	uint32_t,  8,  4,  1);
defineICBitFieldRev( GPO_TRIST6,	uint32_t,  8,  5,  1);
defineICBitFieldRev( WFG_REF,	uint32_t,  8,  6,  5);
defineICBitFieldRev( DCOC_SIGN_EF,	uint32_t,  8, 11,  1);
defineICBitFieldRev( TX_DCOC_SIGN,	uint32_t,  8, 12,  1);
defineICBitFieldRev( AOC_HIB,	uint32_t,  8, 13,  1);
// 	WORD16 - 0x06	
defineICBitFieldRev( X1DR0,		uint32_t, 12, 16, 10);
//defineICBitFieldRev( ESC_DIVSEL,		uint32_t, 12, 26, 3);
defineICBitFieldRev( DC_CORRECT,	uint32_t, 12, 29,  1);
defineICBitFieldRev( HP_SEL,		uint32_t, 12, 30,  1);
defineICBitFieldRev( ATT_SSI,	uint32_t, 12, 31,  1);
// 	WORD16 - 0x07
defineICBitFieldRev( X1DR1,		uint32_t, 12,  0, 10);
defineICBitFieldRev( EN_DLY_MUX,	uint32_t, 12, 10,  1);
// 	WORD16 - 0x08
defineICBitFieldRev( X1DR2,		uint32_t, 16, 16, 10);
defineICBitFieldRev( EN_OVS_DLYD,	uint32_t, 16, 26,  6);
// 	WORD16 - 0x09
defineICBitFieldRev( X1DR3,		uint32_t, 16,  0, 10);
defineICBitFieldRev( SYMB_REF,	uint32_t, 16, 10,  6);
// 	WORD16 - 0x0A
defineICBitFieldRev( X1DR4,		uint32_t, 20, 16, 10);
defineICBitFieldRev( TRIST_PAB,	uint32_t, 20, 26,  1);
defineICBitFieldRev( BSAVE_EF,	uint32_t, 20, 27,  1);
defineICBitFieldRev( BSAVE_Q,	uint32_t, 20, 28,  1);
defineICBitFieldRev( BSAVE_I,	uint32_t, 20, 29,  1);
defineICBitFieldRev( BSAVE_WG,	uint32_t, 20, 30,  1);
defineICBitFieldRev( BSAVE_PAB,	uint32_t, 20, 31,  1);
// 	WORD16 - 0x0B
defineICBitFieldRev( X1DR5,		uint32_t, 20,  0, 10);
defineICBitFieldRev( TXCONFIG,	uint32_t, 20, 10,  2);
defineICBitFieldRev( LP_ADD,		uint32_t, 20, 12,  2);
// 	WORD16 - 0x0C
defineICBitFieldRev( X2DR0,		uint32_t, 24, 16, 11);
// 	WORD16 - 0x0D
defineICBitFieldRev( X2DR1,		uint32_t, 24,  0, 11);
// 	WORD16 - 0x0E
defineICBitFieldRev( X2DR2,		uint32_t, 28, 16, 11);
// 	WORD16 - 0x0F
defineICBitFieldRev( X2DR3,		uint32_t, 28,  0, 11);
// 	WORD16 - 0x10
defineICBitFieldRev( X2DR4,		uint32_t, 32, 16, 11);
// 	WORD16 - 0x11
defineICBitFieldRev( X2DR5,		uint32_t, 32,  0, 11);
// 	WORD16 - 0x12
defineICBitFieldRev( X3DR0,		uint32_t, 36, 16, 13);
// 	WORD16 - 0x13
defineICBitFieldRev( X3DR1,		uint32_t, 36,  0, 13);
// 	WORD16 - 0x14
defineICBitFieldRev( X3DR2,		uint32_t, 40, 16, 13);
// 	WORD16 - 0x15
defineICBitFieldRev( X3DR3,		uint32_t, 40,  0, 13);
// 	WORD16 - 0x16
defineICBitFieldRev( X3DR4,		uint32_t, 44, 16, 13);
// 	WORD16 - 0x17
defineICBitFieldRev( X3DR5,		uint32_t, 44,  0, 13);
// 	WORD16 - 0x18
defineICBitFieldRev( X4DR0,		uint32_t, 48, 16, 14);
// 	WORD16 - 0x19
defineICBitFieldRev( X4DR1,		uint32_t, 48,  0, 14);
// 	WORD16 - 0x1A
defineICBitFieldRev( X4DR2,		uint32_t, 52, 16, 14);
// 	WORD16 - 0x1B
defineICBitFieldRev( X4DR3,		uint32_t, 52,  0, 14);
// 	WORD16 - 0x1C
defineICBitFieldRev( X4DR4,		uint32_t, 56, 16, 14);
// 	WORD16 - 0x1D
defineICBitFieldRev( X4DR5,		uint32_t, 56,  0, 14);
// 	WORD16 - 0x1E
defineICBitFieldRev( DCOC_REF,	uint32_t, 60, 16, 10);
defineICBitFieldRev( TM_BUFF,		uint32_t, 60, 26,  2);
defineICBitFieldRev( EF_SEL,		uint32_t, 60, 29,  2);
defineICBitFieldRev( EF_DC_CORRECT,	uint32_t, 60, 31,  1);
// 	WORD16 - 0x1F
defineICBitFieldRev( EF_DLY,		uint32_t, 60,  0,  3);
defineICBitFieldRev( TEST_MUX,	uint32_t, 60,  3,  8);
// 	WORD16 - 0x20
defineICBitFieldRev( TR_LOWER,	uint32_t, 64, 16,  8);
defineICBitFieldRev( TR_UPPER,	uint32_t, 64, 24,  8);
// 	WORD16 - 0x21
defineICBitFieldRev( DAC_TEST,	uint32_t, 64,  0, 10);
defineICBitFieldRev( DAC_TEST_EN,	uint32_t, 64, 10,  3);
defineICBitFieldRev( FIRCLK_SB,	uint32_t, 64, 13,  1);
defineICBitFieldRev( LAST_INT,	uint32_t, 64, 14,  1);
// 	WORD16 - 0x22
defineICBitFieldRev( IDC_DAC,	uint32_t, 68, 16,  6);
defineICBitFieldRev( DC_DAC_GM,	uint32_t, 68, 22,  2);
defineICBitFieldRev( QDC_DAC,	uint32_t, 68, 24,  6);
defineICBitFieldRev( DCOCL_HOLD,	uint32_t, 68, 30,  1);
defineICBitFieldRev( DCOC_LPF_BW,	uint32_t, 68, 31,  1);
// 	WORD16 - 0x23
defineICBitFieldRev( KDLPT,		uint32_t, 68,  0,  3);
defineICBitFieldRev( THP2,		uint32_t, 68,  3,  3);
defineICBitFieldRev( THP1,		uint32_t, 68,  6,  3);
defineICBitFieldRev( FHP3,		uint32_t, 68,  9,  4);
defineICBitFieldRev( ADAC_BIAS,	uint32_t, 68, 13,  1);
defineICBitFieldRev( SOS_MUX,	uint32_t, 68, 14,  1);
defineICBitFieldRev( SM_AGC_EN,	uint32_t, 68, 15,  1);
// 	WORD16 - 0x24
defineICBitFieldRev( FHP2,		uint32_t, 72, 16,  4);
defineICBitFieldRev( FHP1,		uint32_t, 72, 20,  3);
defineICBitFieldRev( SD_MODE,	uint32_t, 72, 23,  1);
defineICBitFieldRev( PMA_BIAS,	uint32_t, 72, 24,  2);
defineICBitFieldRev( SSI_TS,		uint32_t, 72, 26,  1);
defineICBitFieldRev( AB_SEL,		uint32_t, 72, 27,  1);
defineICBitFieldRev( DBW,		uint32_t, 72, 28,  3);
defineICBitFieldRev( PMA_BP,		uint32_t, 72, 31,  1);
// 	WORD16 - 0x25
defineICBitFieldRev( TRK_LOW,	uint32_t, 72,  0,  7);
defineICBitFieldRev( FREE_RUN,	uint32_t, 72,  7,  1);
defineICBitFieldRev( TRK_HIGH,	uint32_t, 72,  8,  7);
defineICBitFieldRev( RXSC_SEL,	uint32_t, 72, 15,  1);
// 	WORD16 - 0x26
defineICBitFieldRev( AGC_CLK,	uint32_t, 76, 16,  6);
defineICBitFieldRev( RXDIG_DIV,	uint32_t, 76, 22,  4);
defineICBitFieldRev( DEC_DIV,	uint32_t, 76, 26,  6);
// 	WORD16 - 0x27
defineICBitFieldRev( BS_DLY_TMR,	uint32_t, 76,  0,  8);
defineICBitFieldRev( ADPT_DLY_TMR,	uint32_t, 76,  8,  8);
// 	WORD16 - 0x28
defineICBitFieldRev( FBC_TMR,	uint32_t, 80, 16,  2);
defineICBitFieldRev( AGCFLAGEN,	uint32_t, 80, 18,  1);
defineICBitFieldRev( SEQMGR_EN,	uint32_t, 80, 19,  1);
defineICBitFieldRev( DC_CALEN,	uint32_t, 80, 20,  1);
defineICBitFieldRev( AGC_MAX_A,	uint32_t, 80, 21,  1);
defineICBitFieldRev( FE_OFF_A,	uint32_t, 80, 22,  1);
defineICBitFieldRev( STEP_SLOT,	uint32_t, 80, 23,  1);
defineICBitFieldRev( AGC_DAC_VREF,	uint32_t, 80, 24,  2);
defineICBitFieldRev( STEP_THRESH,	uint32_t, 80, 26,  3);
defineICBitFieldRev( STEP_OFFSET,	uint32_t, 80, 29,  3);
// 	WORD16 - 0x29
defineICBitFieldRev( BW,		uint32_t, 80,  0,  5);
defineICBitFieldRev( BB2P_Q,		uint32_t, 80,  5,  3);
defineICBitFieldRev( AGC_STEP_CMP,	uint32_t, 80,  8,  8);
// 	WORD16 - 0x2A
defineICBitFieldRev( RAGC_PHASE,	uint32_t, 84, 16,  2);
defineICBitFieldRev( RAGC_DIV,	uint32_t, 84, 18,  3);
defineICBitFieldRev( FAGC_STEPS,	uint32_t, 84, 21,  3);
defineICBitFieldRev( FAGC_DIV,	uint32_t, 84, 24,  3);
defineICBitFieldRev( NAGC_DIV,	uint32_t, 84, 26,  2);
defineICBitFieldRev( AGCLVL,		uint32_t, 84, 29,  3);
// 	WORD16 - 0x2B
defineICBitFieldRev( CIC_OFFSET,	uint32_t, 84,  0, 13);
defineICBitFieldRev( AUTO_AGC,	uint32_t, 84, 13,  1);
defineICBitFieldRev( RF_STEPEN,	uint32_t, 84, 14,  1);
defineICBitFieldRev( AGC_DAC_MODE,	uint32_t, 84, 15,  1);
// 	WORD16 - 0x2C
defineICBitFieldRev( AUX_DAC,	uint32_t, 88, 16,  8);
defineICBitFieldRev( AGCHIGH,	uint32_t, 88, 26,  1);
// Add new:
//defineICBitFieldRev( AGC_DAC_VREF,	uint32_t, 88, 27,  3);
//defineICBitFieldRev( HPDC_HOLD,	uint32_t, 88, 30,  1);
// 	WORD16 - 0x2D
defineICBitFieldRev( MCPTEST,	uint32_t, 88,  0,  3);
defineICBitFieldRev( MCP_GAIN,	uint32_t, 88,  3,  3);
defineICBitFieldRev( MCRS_TMR,	uint32_t, 88,  6,  2);
defineICBitFieldRev( MADP_TMR,	uint32_t, 88,  8,  4);
defineICBitFieldRev( MREF_DIV,	uint32_t, 88, 12,  3);
// 	WORD16 - 0x2E
defineICBitFieldRev( CLK_NUM,uint32_t, 92, 0,  24);
defineICBitFieldRev( CLK_NUM_16_23,uint32_t, 92, 16,  8);
defineICBitFieldRev( MACC,			uint32_t, 92, 24,  2);
defineICBitFieldRev( MND_8BIT_SEL,	uint32_t, 92, 26,  1);
defineICBitFieldRev( MLBPRCS_SEL,	uint32_t, 92, 27,  1);
defineICBitFieldRev( CLK_ACC,	uint32_t, 92, 28,  2);
defineICBitFieldRev( ROT,		uint32_t, 92, 30,  2);
// 	WORD16 - 0x2F
defineICBitFieldRev( CLK_NUM_0_15,uint32_t, 92,  0, 16);
// 	WORD16 - 0x30
defineICBitFieldRev( CLK_N,	uint32_t, 96, 16,  8);
defineICBitFieldRev( CLK_R,	uint32_t, 96, 24,  8);
// 	WORD16 - 0x31
defineICBitFieldRev( CLKCP_TEST,	uint32_t, 96,  0,  3);
defineICBitFieldRev( BSAVE_CLKS_SYN,	uint32_t, 96,  3,  1);
defineICBitFieldRev( CLK1_DIV,	uint32_t, 96,  4,  2);
defineICBitFieldRev( CLK2_DIV,	uint32_t, 96,  6,  2);
defineICBitFieldRev( TCLK_OUT_EN,	uint32_t, 96,  8,  1);
defineICBitFieldRev( CLK1_OUT_EN,	uint32_t, 96,  9,  1);
defineICBitFieldRev( CLK2_OUT_EN,	uint32_t, 96,  10,  1);
defineICBitFieldRev( TCLK_DIV_SEL,	uint32_t, 96, 11,  1);
defineICBitFieldRev( TCLK_DIV,	uint32_t, 96, 12,  2);
defineICBitFieldRev( COB1_SEL,	uint32_t, 96, 14,  1);
defineICBitFieldRev( COB2_SEL,	uint32_t, 96, 15,  1);
// 	WORD16 - 0x32
defineICBitFieldRev( BSAVE_CRS_DAC,	uint32_t, 100, 16,  1);
defineICBitFieldRev( ES_CP_BIAS_EN, 	uint32_t, 100, 17,  1);
defineICBitFieldRev( ES_VCO_STEER2,	uint32_t, 100, 18,  1);
defineICBitFieldRev( ES_VCO_STEER1,	uint32_t, 100, 19,  1);
defineICBitFieldRev( ES_SEL3,	uint32_t, 100, 20,  1);
defineICBitFieldRev( ES_NUD_MUL_BYP,	uint32_t, 100, 21,  1);
defineICBitFieldRev( ES_NUD_BYP,	uint32_t, 100, 22,  1);
defineICBitFieldRev( ES_D16_BYP,	uint32_t, 100, 23,  1);
defineICBitFieldRev( ES_CP_EN,	uint32_t, 100, 24,  1);
defineICBitFieldRev( ES_SEL1,	uint32_t, 100, 25,  1);
defineICBitFieldRev( ES_DIV_TEST,	uint32_t, 100, 26,  1);
defineICBitFieldRev( ES_BIAS_EN,	uint32_t, 100, 27,  1);
defineICBitFieldRev( ES_STEER_EN,	uint32_t, 100, 28,  1);
defineICBitFieldRev( ES_NUD_EN,	uint32_t, 100, 29,  1);
defineICBitFieldRev( CLK2_IN_SEL,	uint32_t, 100, 30,  1);
defineICBitFieldRev( CLK1_IN_SEL,	uint32_t, 100, 31,  1);
// 	WORD16 - 0x33
defineICBitFieldRev( AGC_DAC,	uint32_t, 100,  0,  8);
defineICBitFieldRev( TRACK_OSCEN,	uint32_t, 100,  8,  1);
defineICBitFieldRev( RX_BB_BS,	uint32_t, 100,  9,  1);
defineICBitFieldRev( FE_EN,		uint32_t, 100, 10,  1);
defineICBitFieldRev( SD_BS,		uint32_t, 100, 11,  1);
defineICBitFieldRev( AGC_BS,		uint32_t, 100, 12,  1);
defineICBitFieldRev( RX_DIG_BS,	uint32_t, 100, 13,  1);
defineICBitFieldRev( ADAPT,		uint32_t, 100, 14,  1);
defineICBitFieldRev( AUXDAC_BS,	uint32_t, 100, 15,  1);
// 	WORD16 - 0x34
defineICBitFieldRev( BUFGAIN,	uint32_t, 104, 16,  3);
defineICBitFieldRev( AMP_AGC,	uint32_t, 104, 19,  3);
defineICBitFieldRev( PMA_AGC,	uint32_t, 104, 22,  2);
defineICBitFieldRev( RX_BS,	uint32_t, 104, 24,  1);
defineICBitFieldRev( ADAPTEN,	uint32_t, 104, 25,  1);
defineICBitFieldRev( AGC_PRELOAD,	uint32_t, 104, 26,  1);
defineICBitFieldRev( FAST_AGC,	uint32_t, 104, 27,  1);
defineICBitFieldRev( RF_STEP,	uint32_t, 104, 28,  1);
defineICBitFieldRev( SSI_MODE,	uint32_t, 104, 29,  3);
// 	WORD16 - 0x35
defineICBitFieldRev( MAINNUM_16_23,	uint32_t, 104,  0,  8);
defineICBitFieldRev( MFADJ,		uint32_t, 104,  8,  2);
defineICBitFieldRev( BSAVE_MAIN_SYN,uint32_t, 104, 10, 1);
defineICBitFieldRev( BSAVE_SYN_ALL,uint32_t, 104, 11, 1);
defineICBitFieldRev( BSAVE_ALL,	uint32_t, 104, 12,  1);
defineICBitFieldRev( SF_BS,		uint32_t, 104, 13,  1);
defineICBitFieldRev( SYN_ADAPTEN,	uint32_t, 104, 14,  1);
defineICBitFieldRev( RXSM_ASPI_EN,	uint32_t, 104, 15,  1);
// 	WORD16 - 0x36
defineICBitFieldRev( MAINNUM_0_15,	uint32_t, 108, 16, 16);
// 	WORD16 - 0x37
defineICBitFieldRev( MAINND,	uint32_t, 108,  0, 10);
defineICBitFieldRev( MCRS_DAC,	uint32_t, 108, 10,  6);
// 	WORD16 - 0x38
defineICBitFieldRev( NUD,		uint32_t, 112, 16,  6);
defineICBitFieldRev( ES_SEL2,	uint32_t, 112, 22,  1);
defineICBitFieldRev( BSAVE_ESCORT,uint32_t, 112, 23,  1);
defineICBitFieldRev( GPO_1,	uint32_t, 112, 24,  1);
defineICBitFieldRev( GPO_2,	uint32_t, 112, 25,  1);
defineICBitFieldRev( GPO_3,	uint32_t, 112, 26,  1);
defineICBitFieldRev( GPO_4,	uint32_t, 112, 27,  1);
defineICBitFieldRev( GPO_5,	uint32_t, 112, 28,  1);
defineICBitFieldRev( GPO_6,	uint32_t, 112, 29,  1);
defineICBitFieldRev( CEFBEN,		uint32_t, 112, 30,  1);
defineICBitFieldRev( BSAVE_TX,	uint32_t, 112, 31,  1);
// 	WORD16 - 0x39
defineICBitFieldRev( ATTEN_Q,	uint32_t, 112,  0,  8);
defineICBitFieldRev( ATTEN_I,	uint32_t, 112,  8,  8);
// 	WORD16 - 0x3A
defineICBitFieldRev( PABIASDAC,	uint32_t, 116, 16,  8);
defineICBitFieldRev( STATT_IQ,	uint32_t, 116, 24,  2);
defineICBitFieldRev( EF_DC_UPDATE,uint32_t, 116, 26,  1);
defineICBitFieldRev( DC_UPDATE,	uint32_t, 116, 27,  1);
defineICBitFieldRev( BSAVE_TXR,	uint32_t, 116, 28,  1);
// 	WORD16 - 0x3B
defineICBitFieldRev( PWRCTL,		uint32_t, 116, 0, 10);
// 	WORD16 - 0x3C
defineICBitFieldRev( A0_ENV,		uint32_t, 120, 16, 10);
// 	WORD16 - 0x3D
defineICBitFieldRev( A1_ENV,		uint32_t, 120,  0, 10);
defineICBitFieldRev( ASPI_CLK_SEL,	uint32_t, 120, 10,  1);
// 	WORD16 - 0x3E
defineICBitFieldRev( A2_ENV,		uint32_t, 124, 16, 10);
defineICBitFieldRev( AUXCEPOL,	uint32_t, 124, 26,  2);
defineICBitFieldRev( AUXCLKDIV2,	uint32_t, 124, 28,  2);
defineICBitFieldRev( AUXCLKDIV1,	uint32_t, 124, 30,  2);
// 	WORD16 - 0x3F
defineICBitFieldRev( RX_EVENT2,	uint32_t, 124,  0,  8);
defineICBitFieldRev( RX_EVENT1,	uint32_t, 124,  8,  8);

#endif
// }}}USR
// }}}RME

class tomahawkDefault
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
	// {{{RME classAttribute 'defaultImages'
	uint32_t * * defaultImages;
	// }}}RME
	// {{{RME operation 'tomahawkDefault(uint32_t **)'
	tomahawkDefault( uint32_t * * defaultTomahawkImages );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* tomahawkDefault_H */

// }}}RME
