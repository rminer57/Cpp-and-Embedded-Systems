// abacus.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"





  typedef   signed char   int8_t;
    typedef unsigned char  uint8_t;
    typedef   signed short  int16_t;
    typedef unsigned short uint16_t;
    typedef   signed long   int32_t;
    typedef unsigned long  uint32_t;

#define PROCESSOR_ACCESS_SIZE 8

#define ABACUS_TEST_REG_3B  0x3C
#define ABACUS_TEST_REG_3F 0x40
#define ABACUS_REG_0         0x01
#define ABACUS_REG_25       0x1A
#define ABACUS_REG_28       0x1D
#define ABACUS_REG_29       0x1E
#define ABACUS_REG_30       0x1F
#define ABACUS_REG_31       0x20

#define   ABACUS_TEST_REG_3A  0x3B 

#define   MAX_TUNE_TRIES 5
#define   TUNE_BITS 0x03
#define   TUNE_LC_MASK_D1 0x02
#define   TUNE_RC_MASK_D0 0x01

#define   ABACUS_REV_6    0x06
#define   ABACUS_REV_87   0x87

/* Tuning was introduced in the second revision of the AbacusIII */
#define NON_TUNED_VERSION   1

/* The version number read back from the first LP ABACUSIII (tunable) is 4 */
#define FIRST_TUNED_VERSION 4
#define MAX_VERSION 0XFF

#define MIN_ABACUSIII_GOOD_TUNING_VAL_REG_1F   0x20
#define MAX_ABACUSIII_GOOD_TUNING_VAL_REG_1F  0x80
#define DEF_ABACUSIII_GOOD_TUNING_VAL_REG_1F 0x45
#define ABACUS_R0_BIT0 8	
#define ABACUS_R1_BIT0 0
#define ABACUS_R2_BIT0 24
#define ABACUS_R3_BIT0 16
#define ABACUS_R4_BIT0 8
#define ABACUS_R5_BIT0 0
#define ABACUS_R6_BIT0 24
#define ABACUS_R7_BIT0 16
#define ABACUS_R8_BIT0 8 
#define ABACUS_R9_BIT0 0
#define ABACUS_R10_BIT0 24 
#define ABACUS_R11_BIT0 16 
#define ABACUS_R12_BIT0 8 
#define ABACUS_R13_BIT0 0 
#define ABACUS_R14_BIT0 24 
#define ABACUS_R15_BIT0 16
#define ABACUS_R16_BIT0 8 
#define ABACUS_R17_BIT0 0
#define ABACUS_R18_BIT0 24
#define ABACUS_R19_BIT0 16
#define ABACUS_R20_BIT0 8
#define ABACUS_R21_BIT0 0
#define ABACUS_R22_BIT0 24
#define ABACUS_R23_BIT0 16
#define ABACUS_R24_BIT0 8
#define ABACUS_R25_BIT0 0
#define ABACUS_R26_BIT0 24
#define ABACUS_R27_BIT0 16
#define ABACUS_R28_BIT0 8
#define ABACUS_R29_BIT0 0
#define ABACUS_R30_BIT0 24
#define ABACUS_R31_BIT0 16

// NOTE - these offset values adjust for the fact that the buffer is a uint32_t and the first
// byte in memory is to be skipped while the second byte is address header.  thus, the third
// byte of the first uint32_t is register 0.

#define ABACUS_R0_REGOFFSET 0
#define ABACUS_R1_REGOFFSET 0 
#define ABACUS_R2_REGOFFSET 4
#define ABACUS_R3_REGOFFSET 4
#define ABACUS_R4_REGOFFSET 4
#define ABACUS_R5_REGOFFSET 4 
#define ABACUS_R6_REGOFFSET 8 
#define ABACUS_R7_REGOFFSET 8
#define ABACUS_R8_REGOFFSET 8
#define ABACUS_R9_REGOFFSET 8
#define ABACUS_R10_REGOFFSET 12 
#define ABACUS_R11_REGOFFSET 12
#define ABACUS_R12_REGOFFSET 12
#define ABACUS_R13_REGOFFSET 12 
#define ABACUS_R14_REGOFFSET 16 
#define ABACUS_R15_REGOFFSET 16
#define ABACUS_R16_REGOFFSET 16
#define ABACUS_R17_REGOFFSET 16
#define ABACUS_R18_REGOFFSET 20 
#define ABACUS_R19_REGOFFSET 20
#define ABACUS_R20_REGOFFSET 20
#define ABACUS_R21_REGOFFSET 20
#define ABACUS_R22_REGOFFSET 24
#define ABACUS_R23_REGOFFSET 24
#define ABACUS_R24_REGOFFSET 24
#define ABACUS_R25_REGOFFSET 24
#define ABACUS_R26_REGOFFSET 28
#define ABACUS_R27_REGOFFSET 28
#define ABACUS_R28_REGOFFSET 28
#define ABACUS_R29_REGOFFSET 28
#define ABACUS_R30_REGOFFSET 32
#define ABACUS_R31_REGOFFSET 32
  

/*
bitfield name	reg	offset	startbit  		length
--------------------------------------------------------------
STBY		R0	0	ABACUS_R0_BIT0 + 0	8
REF		R0	0	ABACUS_R0_BIT0 + 7	1
LO		R0	0	ABACUS_R0_BIT0 + 6	1
CKO		R0	0	ABACUS_R0_BIT0 + 5	1
CK		R0	0	ABACUS_R0_BIT0 + 4	1
GC		R0	0	ABACUS_R0_BIT0 + 3	1
LNAMX		R0	0	ABACUS_R0_BIT0 + 2	1	
ADC		R0	0	ABACUS_R0_BIT0 + 0	1

LNAB		R1	0	ABACUS_R1_BIT0 + 6	2
MIXB		R1	0	ABACUS_R1_BIT0 + 4	2
CKOB		R1	0	ABACUS_R1_BIT0 + 2	2
ADCB		R1	0	ABACUS_R1_BIT0 + 0	2

TEST		R2	4	ABACUS_R2_BIT0 + 0	8
ATTEN		R3	4	ABACUS_R3_BIT0 + 7	1
AGCG14_8	R3	4	ABACUS_R3_BIT0 + 0	7
AGCG7_0		R4	4	ABACUS_R4_BIT0 + 0	8
AGCA		R5	4	ABACUS_R5_BIT0 + 4	4
AGCD		R5	4	ABACUS_R5_BIT0 + 0	4
AGCV		R6	8	ABACUS_R6_BIT0 + 7	1
AGCO		R6	8	ABACUS_R6_BIT0 + 4	3
AGCF		R6	8	ABACUS_R6_BIT0 + 3	1
AGCR		R6	8	ABACUS_R6_BIT0 + 0	3
K		R7	8	ABACUS_R7_BIT0 + 4	1
M		R7	8	ABACUS_R7_BIT0 + 0	4
LOR13_8		R8	8	ABACUS_R8_BIT0 + 0	6
LOR7_0		R9	8	ABACUS_R9_BIT0 + 0	8
LOA		R10	12	ABACUS_R10_BIT0 + 5	3
LOB12_8		R10	12	ABACUS_R10_BIT0 + 0	5
LOB7_0		R11	12	ABACUS_R11_BIT0 + 0	8
LOF		R12	12	ABACUS_R12_BIT0 + 6	1
LOINV		R12	12	ABACUS_R12_BIT0 + 5	1
LOI		R12	12	ABACUS_R12_BIT0 + 2	3
LOTM		R12	12	ABACUS_R12_BIT0 + 0	2
LOFA13_8	R13	12	ABACUS_R13_BIT0 + 0	6
LOFA7_0		R14	16	ABACUS_R14_BIT0 + 0	8

CKR13_8		R16	16	ABACUS_R16_BIT0 + 0	6
CKR7_0		R17	16	ABACUS_R17_BIT0 + 0	8
CKN12_8		R18	20	ABACUS_R18_BIT0 + 0	5
CKN7_0		R19	20	ABACUS_R19_BIT0 + 0	8
CKF		R20	20	ABACUS_R20_BIT0 + 6	1
CKINV		R20	20	ABACUS_R20_BIT0 + 5	1
CKI		R20	20	ABACUS_R20_BIT0 + 2	3
CKTM		R20	20	ABACUS_R20_BIT0 + 0	2
CKFA13_8	R21	20	ABACUS_R21_BIT0 + 0	6
CKFA7_0		R22	24	ABACUS_R22_BIT0 + 0	8

SSICRA		R24	24	ABACUS_R24_BIT0 + 0	8
SSICRB		R25	24	ABACUS_R25_BIT0 + 0	8
SSIORD		R26	28	ABACUS_R26_BIT0 + 0	4

TUNE_LC		R28	28	ABACUS_R28_BIT0 + 1	1
TUNE_RC		R28	28	ABACUS_R28_BIT0 + 0	1
CAPL1		R29	28	ABACUS_R29_BIT0 + 0	3
CAPL0		R30	32	ABACUS_R30_BIT0 + 0	6
CAPR		R31	32	ABACUS_R31_BIT0 + 0	8

*/


//The definition PROCESSOR_ACCESS_SIZE is used to determine the word size.

//{Name} is the symbloic name of the bitfield
//{Type} is the base access type
//{Base} is defined as the base address of the bitfield
//{Off} is defined as the BYTE offset from base address of the bitfield
//{Start} is defined as the bit position (0 based)
//{Len} is defined as the number of bits in the bitfield

//This macro reverses a 16 or 32 bit quantity for endian correctness
#define reverseEndian(x,size) \
	( \
	size == 4? \
		((x) >> 24) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | ((x) << 24): \
		(size == 2? \
			(((x) >> 8) & 0xFF) | (((x)& 0xFF) << 8 ): \
			(x) \
		) \
	)

//This Macro is used to define a Standard Bitfield
#define defineBitField(name,type,off,start,len) \
	const static unsigned int name ## _reverse = 0; \
	defineBitFieldCommon(name,type,off,start,len)

//This Macro is used to define a Reversed Endian Bitfield
#define defineBitFieldRev(name,type,off,start,len) \
	const static unsigned int name ## _reverse = 1; \
	defineBitFieldCommon(name,type,off,start,len)

//This Macro is used to define a Bitfield (do not use directly, used by ABOVE macros)
#define defineBitFieldCommon(name,type,off,start,len) \
	const static unsigned int name ## _start = (start) % (sizeof(type) * PROCESSOR_ACCESS_SIZE); \
	const static     uint32_t name ## _fieldMask = (uint32_t)((1L << (len))-1) << name ## _start; \
	const static unsigned int name ## _off = (((start)/PROCESSOR_ACCESS_SIZE) + (8*(off)/PROCESSOR_ACCESS_SIZE)) / sizeof(type)

//This Macro is used to set a predefined bitfield to a given value
#define setBitField(base,name,value) \
	do { \
	if (name ## _reverse == 0) { \
		*((base) + name ## _off) = (*((base) + name ## _off) \
			& ~(name ## _fieldMask)) \
			| ((uint32_t)(value) << name ## _start) & name ## _fieldMask; \
	} \
	if (name ## _reverse == 1) { \
		uint32_t temp = reverseEndian(*((base) + name ## _off),sizeof(*(base))); \
		temp = (temp & ~(name ## _fieldMask)) \
			| ((uint32_t)(value) << name ## _start) & name ## _fieldMask; \
		*((base) + name ## _off) = reverseEndian(temp,sizeof(*(base))); \
	} \
	} while(0)

//This Macro is used to return the current value of a bitfield
#define getBitField(base,name) \
	(( \
		((name ## _reverse == 0) ? \
		*((base) + name ## _off) : \
		reverseEndian(*((base) + name ## _off),sizeof(*(base))))\
	& name ## _fieldMask) >> name ## _start)
	
//This Macro is used to return the value of a bitfield, but for test purpose
//Note, the value is unshifted. 
#define testBitField(base,name) \
	( \
		((name ## _reverse == 0) ? \
		*((base) + name ## _off) : \
		reverseEndian(*((base) + name ## _off),sizeof(*(base))))\
	& name ## _fieldMask)

//This Macro is used to combine a base with offset specified in BYTES
//Adjustment for processor access size of non-bytes is also made
#define combineAddr(base,off) ((base) + ((off) / (sizeof(*(base)) * PROCESSOR_ACCESS_SIZE / 8 )))

//This Macro is used to set a predefined Templated bitfield to a given value
#define setTemplatedBitField(base,start,len,value) \
	do { \
		unsigned int TBF_start = (start) % (sizeof(*(base)) * PROCESSOR_ACCESS_SIZE); \
		unsigned int TBF_fieldMask = ((1 << (len))-1) << TBF_start; \
		unsigned int TBF_off = (start) / (PROCESSOR_ACCESS_SIZE * sizeof(*(base))); \
		*((base) + TBF_off) = (*((base) + TBF_off) & ~(TBF_fieldMask)) \
			| ((value) << TBF_start) & TBF_fieldMask; \
	} while(0)

//This Macro is used to define a Templated bitfield for later use
//Base,shift (unsigned int) and mask (unsigned int) are set up...
#define defineTemplatedBitField(base,shift,mask,start,len) \
	do { \
		shift = (start) % (sizeof(*(base)) * PROCESSOR_ACCESS_SIZE); \
		mask = ((1 << (len))-1) << shift; \
		base += (start) / (PROCESSOR_ACCESS_SIZE * sizeof(*(base))); \
	} while(0)

//This Macro is used to set a predefined Templated bitfield to a given value
//See above "defineTemplatedBitField" for use.
#define setDefinedBitField(base,shift,mask,value) \
	*(base) = (*(base) & ~(mask)) | ((value) << (shift)) & (mask)

//This Macro is used to get a predefined Templated bitfield value
//See above "defineTemplatedBitField" for use.
#define getDefinedBitField(base,shift,mask) \
	((*(base) & (mask)) >> (shift))

//Set a given bit (automatically adjusts for base operand size)
#define setBit(base,num,value) \
	do { \
		*((base) + ((num) / (sizeof(*(base)) * PROCESSOR_ACCESS_SIZE))) &= ~( 1 << ((num) % (sizeof(*(base)) * PROCESSOR_ACCESS_SIZE))); \
		*((base) + ((num) / (sizeof(*(base)) * PROCESSOR_ACCESS_SIZE))) |= (((value) & 1) << ((num) % (sizeof(*(base)) * PROCESSOR_ACCESS_SIZE))); \
	} while(0)

//Set a given bit (automatically adjusts for base operand size)
#define testBit(base,num) \
		(*((base) + ((num) / (sizeof(*(base)) * PROCESSOR_ACCESS_SIZE))) & ( 1 << ((num) % (sizeof(*(base)) * PROCESSOR_ACCESS_SIZE))))






// R0 $00
defineBitField(STBY, uint32_t,ABACUS_R0_REGOFFSET,ABACUS_R0_BIT0 + 0,8);         // BYTE 0
defineBitField(REF,  uint32_t,ABACUS_R0_REGOFFSET,ABACUS_R0_BIT0 + 7,1);
defineBitField(LO,   uint32_t,ABACUS_R0_REGOFFSET,ABACUS_R0_BIT0 + 6,1);
defineBitField(CKO,  uint32_t,ABACUS_R0_REGOFFSET,ABACUS_R0_BIT0 + 5,1);
defineBitField(CK,   uint32_t,ABACUS_R0_REGOFFSET,ABACUS_R0_BIT0 + 4,1);
defineBitField(GC,   uint32_t,ABACUS_R0_REGOFFSET,ABACUS_R0_BIT0 + 3,1);
defineBitField(LNAMX,uint32_t,ABACUS_R0_REGOFFSET,ABACUS_R0_BIT0 + 2,1);	
defineBitField(ADC,  uint32_t,ABACUS_R0_REGOFFSET,ABACUS_R0_BIT0 + 0,1);

// R1 $01
defineBitField(LNAB, uint32_t,ABACUS_R1_REGOFFSET,ABACUS_R1_BIT0 + 6,2);
defineBitField(MIXB, uint32_t,ABACUS_R1_REGOFFSET,ABACUS_R1_BIT0 + 4,2);
defineBitField(CKOB, uint32_t,ABACUS_R1_REGOFFSET,ABACUS_R1_BIT0 + 2,2);
defineBitField(ADCB, uint32_t,ABACUS_R1_REGOFFSET,ABACUS_R1_BIT0 + 0,2);

// R2 $02
defineBitField(TEST, uint32_t,ABACUS_R2_REGOFFSET,ABACUS_R2_BIT0 + 0,8);

// R3
defineBitField(ATTEN,    uint32_t,ABACUS_R3_REGOFFSET,ABACUS_R3_BIT0 + 7,1);
defineBitField(AGCG_MSBS,uint32_t,ABACUS_R3_REGOFFSET,ABACUS_R3_BIT0 + 0,7);   // BYTE 3

// R4
defineBitField(AGCG_LSBS,uint32_t,ABACUS_R4_REGOFFSET,ABACUS_R4_BIT0 + 0,8);    // BYTE 4

// R5        
defineBitField(AGCA,uint32_t,ABACUS_R5_REGOFFSET,ABACUS_R5_BIT0 + 4,4);
defineBitField(AGCD,uint32_t,ABACUS_R5_REGOFFSET,ABACUS_R5_BIT0 + 0,4);  

// R6
defineBitField(AGCV,uint32_t,ABACUS_R6_REGOFFSET,ABACUS_R6_BIT0 + 7,1);
defineBitField(AGCO,uint32_t,ABACUS_R6_REGOFFSET,ABACUS_R6_BIT0 + 4,3);
defineBitField(AGCF,uint32_t,ABACUS_R6_REGOFFSET,ABACUS_R6_BIT0 + 3,1);
defineBitField(AGCR,uint32_t,ABACUS_R6_REGOFFSET,ABACUS_R6_BIT0 + 0,3);

// R7
defineBitField(K,uint32_t,ABACUS_R7_REGOFFSET,ABACUS_R7_BIT0 + 4,1);
defineBitField(M,uint32_t,ABACUS_R7_REGOFFSET,ABACUS_R7_BIT0 + 0,4);           

// R8
defineBitField(LOR_MSBS,uint32_t,ABACUS_R8_REGOFFSET,ABACUS_R8_BIT0 + 0,6);

// R9
defineBitField(LOR_LSBS,uint32_t,ABACUS_R9_REGOFFSET,ABACUS_R9_BIT0 + 0,8);

// R10
defineBitField(LOA,     uint32_t,ABACUS_R10_REGOFFSET,ABACUS_R10_BIT0 + 5,3);
defineBitField(LOB_MSBS,uint32_t,ABACUS_R10_REGOFFSET,ABACUS_R10_BIT0 + 0,5);    // BYTE 10

//R11
defineBitField(LOB_LSBS,uint32_t,ABACUS_R11_REGOFFSET,ABACUS_R11_BIT0 + 0,8); 

// R12
defineBitField(LOF,  uint32_t,ABACUS_R12_REGOFFSET,ABACUS_R12_BIT0 + 6,1);
defineBitField(LOINV,uint32_t,ABACUS_R12_REGOFFSET,ABACUS_R12_BIT0 + 5,1);
defineBitField(LOI,  uint32_t,ABACUS_R12_REGOFFSET,ABACUS_R12_BIT0 + 2,3);
defineBitField(LOTM, uint32_t,ABACUS_R12_REGOFFSET,ABACUS_R12_BIT0 + 0,2); 

// R13
defineBitField(LOFA_MSBS,uint32_t,ABACUS_R13_REGOFFSET,ABACUS_R13_BIT0 + 0,6);

// R14
defineBitField(LOFA_LSBS,uint32_t,ABACUS_R14_REGOFFSET,ABACUS_R14_BIT0 + 0,8); 

// R15 UNUSED

// R16
defineBitField(CKR_MSBS,uint32_t,ABACUS_R16_REGOFFSET,ABACUS_R16_BIT0 + 0,6); 

// R17
defineBitField(CKR_LSBS,uint32_t,ABACUS_R17_REGOFFSET,ABACUS_R17_BIT0 + 0,8); 

// R18
defineBitField(CKN_MSBS,uint32_t,ABACUS_R18_REGOFFSET,ABACUS_R18_BIT0 + 0,5); 

// R19
defineBitField(CKN_LSBS,uint32_t,ABACUS_R19_REGOFFSET,ABACUS_R19_BIT0 + 0,8); 


// R20
defineBitField(CKF,  uint32_t,ABACUS_R20_REGOFFSET,ABACUS_R20_BIT0 + 6,1);
defineBitField(CKINV,uint32_t,ABACUS_R20_REGOFFSET,ABACUS_R20_BIT0 + 5,1);
defineBitField(CKI,  uint32_t,ABACUS_R20_REGOFFSET,ABACUS_R20_BIT0 + 2,3);
defineBitField(CKTM, uint32_t,ABACUS_R20_REGOFFSET,ABACUS_R20_BIT0 + 0,2);

// R21
defineBitField(CKFA_MSBS,uint32_t,ABACUS_R21_REGOFFSET,ABACUS_R21_BIT0 + 0,6);

//R22
defineBitField(CKFA_LSBS,uint32_t,ABACUS_R22_REGOFFSET,ABACUS_R22_BIT0 + 0,8);

// R23 UNUSED

// R24
defineBitField(SSICRA,uint32_t,ABACUS_R24_REGOFFSET,ABACUS_R24_BIT0 + 0,8);
// R25
defineBitField(SSICRB,uint32_t,ABACUS_R25_REGOFFSET,ABACUS_R25_BIT0 + 0,8); 
// R26
defineBitField(SSIORD,uint32_t,ABACUS_R26_REGOFFSET,ABACUS_R26_BIT0 + 0,4);

// R27 UNUSED

// R28
defineBitField(TUNE_LC,uint32_t,ABACUS_R28_REGOFFSET,ABACUS_R28_BIT0 + 1,1);
defineBitField(TUNE_RC,uint32_t,ABACUS_R28_REGOFFSET,ABACUS_R28_BIT0 + 0,1);


// R29
defineBitField(CAPL1,uint32_t,ABACUS_R29_REGOFFSET,ABACUS_R29_BIT0 + 0,3);
// R30
defineBitField(CAPL0,uint32_t,ABACUS_R30_REGOFFSET,ABACUS_R30_BIT0 + 0,6);
// R31
defineBitField(CAPR,uint32_t,ABACUS_R31_REGOFFSET,ABACUS_R31_BIT0 + 0,8);

unsigned short int abacusValues[3] = {   0x02, 0x17, 0x4E };
unsigned short int abacus_version_read;

int m_powerUpStatus = 0;
int m_currentRfState = 0;
int m_numberOfRfStates = 2;

int m_ICVersion = 0;

#define VR_PWRUP_ABACUS_FAILURE 1
#define VR_PWRUP_OK 0
void setRFState( int x){}
void spiReadEnable(){}
void delay_ticks(int x){}
int delayTicks = 0;
int autotune(void);

uint16_t regArray[0x40];


uint16_t reg1C_returnValue = 0;
uint16_t reg1F_returnValue = 0;
uint16_t reg1C_lastWritten = 0;
uint16_t reg1F_lastWritten = 0;

void wrRegister( uint16_t addr, uint16_t value)
{
  regArray[addr] = value;

  if(addr == ABACUS_REG_28)     { reg1C_lastWritten = value; }
  if(addr == ABACUS_REG_31)     { reg1F_lastWritten = value; }
}


uint16_t rdRegister( int addr)
{ 
	if(addr == ABACUS_REG_28)     { return reg1C_returnValue; }
	else if(addr == ABACUS_REG_31){ return reg1F_returnValue; }
	else                          { return regArray[addr]; }
}
uint16_t m_minGoodVal_reg1F = 0;
uint16_t m_maxGoodVal_reg1F = 0;
uint16_t m_defGoodVal_reg1F = 0;


int main(int argc, char * argv[])
{
    //m_spi = m_spiArray;

	printf("Abacus autotune test!\n");

	for(int i = 0; i < 0x3F; i++){ regArray[i]=0; }

	// case 1 feature disabled and LC/RC are both = zero
	printf("\n    Case 1 feature disabled and LC/RC are both = zero, should pass...");
	wrRegister( ABACUS_REG_28,0xFF); wrRegister( ABACUS_REG_31,0xFF);
    m_minGoodVal_reg1F = 0; m_maxGoodVal_reg1F = 0;  m_defGoodVal_reg1F = 0;
	reg1C_returnValue = 0; reg1F_returnValue = 0;
	autotune();
	if(m_powerUpStatus == VR_PWRUP_OK){ printf("PASSED\n"); }else{printf("FAILED\n");}

	// case 2 feature disabled and LC/RC are non-zero
	printf("\n    Case 2 feature disabled and LC/RC are non-zero, ...");
	wrRegister( ABACUS_REG_28,0xFF); wrRegister( ABACUS_REG_31,0xFF);
    m_minGoodVal_reg1F = 0; m_maxGoodVal_reg1F = 0;  m_defGoodVal_reg1F = 0;
	reg1C_returnValue = 1; reg1F_returnValue = 0;
	autotune();
	if(m_powerUpStatus == VR_PWRUP_ABACUS_FAILURE){ printf("PASSED\n"); }else{printf("FAILED\n");}

	// case 3 feature enabled and LC/RC are zero but 1F value out of range - should write 0x45 to 1F
	printf("\n    case 3 fe enabled,LC/RC=0, 1F out-of-range,write 0x45 to 1F...");
	wrRegister( ABACUS_REG_28,0xFF); wrRegister( ABACUS_REG_31,0xFF);
    m_minGoodVal_reg1F = 0x20; m_maxGoodVal_reg1F = 0x80;  m_defGoodVal_reg1F = 0x45;
	reg1C_returnValue = 0; reg1F_returnValue = 0x10;
	autotune();
	if( (m_powerUpStatus == VR_PWRUP_OK) && ( reg1F_lastWritten == m_defGoodVal_reg1F ) ){ printf("PASSED\n"); }else{printf("FAILED\n");}

    // case 4 feature enabled and LC/RC are zero and 1F in range
	printf("\n    case 4 feature enabled and LC/RC are zero and 1F in range...");
	wrRegister( ABACUS_REG_28,0xFF); wrRegister( ABACUS_REG_31,0xFF);
    m_minGoodVal_reg1F = 0x20; m_maxGoodVal_reg1F = 0x80;  m_defGoodVal_reg1F = 0x45;
	reg1C_returnValue = 0; reg1F_returnValue = 0x25;
	autotune();
	if( (m_powerUpStatus == VR_PWRUP_OK) ){ printf("PASSED\n"); }else{printf("FAILED\n");}

	// case 5 feature enabled and LC=0 RC=1 and 1F out of range
	printf("\n    case 5 feature enabled and LC=0 RC=1 and 1F out of range...");
	wrRegister( ABACUS_REG_28,0xFF); wrRegister( ABACUS_REG_31,0xFF);
    m_minGoodVal_reg1F = 0x20; m_maxGoodVal_reg1F = 0x80;  m_defGoodVal_reg1F = 0x45;
	reg1C_returnValue = 0x01; reg1F_returnValue = 0x10;
	autotune();
	if( (m_powerUpStatus == VR_PWRUP_OK) &&( reg1C_lastWritten == 0 ) &&( reg1F_lastWritten == m_defGoodVal_reg1F ) ){ printf("PASSED\n"); }else{printf("FAILED\n");}

	// case 6 feature enabled and LC=0 RC=1 and 1F in range
	printf("\n    case 6 feature enabled and LC=0 RC=1 and 1F in range...");
	wrRegister( ABACUS_REG_28,0xFF); wrRegister( ABACUS_REG_31,0xFF);
    m_minGoodVal_reg1F = 0x20; m_maxGoodVal_reg1F = 0x80;  m_defGoodVal_reg1F = 0x45;
	reg1C_returnValue = 0x01; reg1F_returnValue = 0x30;
	autotune();
	if( (m_powerUpStatus == VR_PWRUP_OK) &&( reg1C_lastWritten == 0 ) &&( reg1F_lastWritten == m_defGoodVal_reg1F ) ){ printf("PASSED\n"); }else{printf("FAILED\n");}

	// do failure cases now...
	// case 7 feature enabled and LC=1 RC=0 and 1F out of range
	printf("\n    case 7 feature enabled and LC=1 RC=0 and 1F out of range...");
	wrRegister( ABACUS_REG_28,0xFF); wrRegister( ABACUS_REG_31,0xFF);
    m_minGoodVal_reg1F = 0x20; m_maxGoodVal_reg1F = 0x80;  m_defGoodVal_reg1F = 0x45;
	reg1C_returnValue = 0x02; reg1F_returnValue = 0x10;
	autotune();
	if( (m_powerUpStatus == VR_PWRUP_ABACUS_FAILURE) ){ printf("PASSED\n"); }else{printf("FAILED\n");}

	// case 8 feature enabled and LC=1 RC=0 and 1F in range
	printf("\n    case 8 feature enabled and LC=1 RC=0 and 1F out of range...");
	wrRegister( ABACUS_REG_28,0xFF); wrRegister( ABACUS_REG_31,0xFF);
    m_minGoodVal_reg1F = 0x20; m_maxGoodVal_reg1F = 0x80;  m_defGoodVal_reg1F = 0x45;
	reg1C_returnValue = 0x02; reg1F_returnValue = 0x40;
	autotune();
	if( (m_powerUpStatus == VR_PWRUP_ABACUS_FAILURE) ){ printf("PASSED\n"); }else{printf("FAILED\n");}

	return 0;
}


int autotune(void)
{
 m_powerUpStatus = VR_PWRUP_ABACUS_FAILURE;

	 bool autotuneBugCheckEnabled = false;
	 int tuneResult = 0;

     uint16_t tune_count = 0;      // temp variable saves count of tuning tries...5 max are allowed
     uint16_t tune_buf_read = 0;   // used to store tuning buffer value
     uint16_t tune_capl1_read = 0; // temp variable used to store register capl1
     uint16_t tune_capl0_read = 0; // temp variable used to store register capl0   
     uint16_t tune_capr_read = 0;  // temp variable used to store register capr
     uint16_t reg_data;           // use for wrRegister
  
     tune_count = MAX_TUNE_TRIES;

        // these attributes are optionally written by the product code by invoking abacusIII::setReg1FValues()
	    // prior to calling autotune.  These attributes are initialized to zero by the constructor and if
	    // not changed by calling setReg1FValues(), the old tuning behavior is preserved.  The old tuning 
		// behavior was to not check $1F for a valid value.  The new behavior will always succeed, using a
		// default value if the IC is unable to tune itself.
	    if( (m_minGoodVal_reg1F != 0) && (m_maxGoodVal_reg1F != 0) && (m_defGoodVal_reg1F != 0) )
	    { 
	      autotuneBugCheckEnabled = true;
	    }
          
        while ((tune_count > 0) && (m_powerUpStatus != VR_PWRUP_OK))
        {
                                   
            /* Program register 0x3F (ID) to 0x99 to soft Reset Abacus. */
            wrRegister( ABACUS_TEST_REG_3F, 0x99); 
			
            setRFState( m_currentRfState );  // program IC to the power up default values for the product.
         			                           
            // get register 0 default value and turn on D7 REF, D4 CK, D3 GC = ON			
			//reg_data = getBitField( *m_spi[m_currentRfState] , STBY); // this bitfield is register 0 bits 0-7

			reg_data |= 0x45;           

            wrRegister( ABACUS_REG_0, reg_data );  // write to register 0
                              
            /* Enable SPI read - 3 wire and 4 wire both supported */
            spiReadEnable();
			
			// Read register $3F of AD987x to determine revision ID 
	        // save in attribute for later access if method rdICVersion is invoked.
            m_ICVersion = (unsigned char)rdRegister( ABACUS_TEST_REG_3F );

          
            /* Program register 0x1C (Tune LC and RC) to 0x03. */
            wrRegister( ABACUS_REG_28, 0x03);
               
            /* Program register 0x00 (ADC out of standby). */
			//reg_data = getBitField( *m_spi[m_currentRfState] , STBY); // STBY bitfield is register 0 bits 0-7

			reg_data &= 0xFE;           

            wrRegister( ABACUS_REG_0, reg_data );  // write to register 0
     
            // Delay a minimum of ~6 ms .. assumes tick time is 2.5milliSeconds
            delay_ticks(delayTicks);
                 
            /* Read register $1C of AD9874, if zero tuning was successful, else try again  */
            tune_buf_read = rdRegister( ABACUS_REG_28 );      
                                    
            /* Read register $1D of AD9874 */
            tune_capl1_read = rdRegister( ABACUS_REG_29 );                                
                                      
            /* Read register $1E of AD9874 */
            tune_capl0_read = rdRegister( ABACUS_REG_30 );                                
                                      
            /* Read register $1F of AD9874 */
            tune_capr_read= rdRegister( ABACUS_REG_31);                                      
                                            
            tune_count--;

			// determine result code used in switch statement
			if(autotuneBugCheckEnabled){ tuneResult |= 0x08; } // set D3 Feature Enable bit
			if((tune_capr_read >= m_minGoodVal_reg1F) && (tune_capr_read <= m_maxGoodVal_reg1F)	) { tuneResult |= 0x04; } // set D2 value range bit  
			if((tune_buf_read & (unsigned char)TUNE_LC_MASK_D1) == 2 ){ tuneResult |= 0x02; }  // set D1 RC bit
			if((tune_buf_read & (unsigned char)TUNE_RC_MASK_D0) == 1 ){ tuneResult |= 0x01; }  // set D0 LC bit

			//notes - FE means feature enable ...same as autotuneBugCheckEnabled
			//        VAL indicates if tuned value is in range or not. 1 = in range
			// | FE | VAL | LC | RC |
            switch( tuneResult )
			{
			    case 0x00: // | FE | VAL | LC | RC | = 0000b feature disabled
			    case 0x04: // | FE | VAL | LC | RC | = 0100b feature disabled
				case 0x0C: // | FE | VAL | LC | RC | = 1100b feature enabled
                  m_powerUpStatus = VR_PWRUP_OK;
				break;

			    case 0x08: // | FE | VAL | LC | RC | = 1000b feature enabled, value out of range and LC RC both zero.
                  // overwrite tune_capr_read since it will be written to all rfstate images later
 
				  if(tune_count == 0) // last attempt
                  {
                    tune_capr_read = m_defGoodVal_reg1F; // product defined default value

                    // write register $1F of AD9874 with default tuning value 
                    wrRegister( ABACUS_REG_31,tune_capr_read); 

                    m_powerUpStatus = VR_PWRUP_OK; // set status to be good
                  }
				break;

				case 0x09: // | FE | VAL | LC | RC | = 1001b feature enabled, value out of range and LC=0 RC=1 
				case 0x0D: // | FE | VAL | LC | RC | = 1101b feature enabled, value in range and LC=0 RC=1 

					if(tune_count == 0) // last attempt
                  {
                    tune_capr_read = m_defGoodVal_reg1F; // product defined default value

                    // clear register $1C to prevent error
                    wrRegister( ABACUS_REG_28,0);

                    // write register $1F of AD9874 with default tuning value 
                    wrRegister( ABACUS_REG_31,tune_capr_read);

                    m_powerUpStatus = VR_PWRUP_OK; // set status to be good
                  }
				break;


				default: // all other conbinations are failures

                  if(tune_count == 0) // last attempt
				  {
                    m_powerUpStatus = VR_PWRUP_ABACUS_FAILURE; 
				  }
				break;

			}

   		
        } // end while

		if(m_powerUpStatus == VR_PWRUP_OK)
		{
                /* Tuning was successful,  update the tuning values to the rfSpiBuffers */
			      // update all rfSpiBuffer images with the tuned values.
                  for(int i = 0; i < m_numberOfRfStates; i++)
                  {
			        // write the tuned values into all rfstate register images.
                    //setBitField(*m_spi[i], TUNE_RC, tune_buf_read );      
                    //setBitField(*m_spi[i], TUNE_LC, (tune_buf_read >> 1));                
                    //setBitField(*m_spi[i], CAPL1, tune_capl1_read);                                             
                    //setBitField(*m_spi[i], CAPL0, tune_capl0_read);   
                    //setBitField(*m_spi[i], CAPR, tune_capr_read); 
			      }
		}

        wrRegister( ABACUS_TEST_REG_3B, 0x08);  /* triastate DOUB */

        //reg_data = getBitField( *m_spi[m_currentRfState] , STBY); // STBY bitfield is register 0 bits 0-7

        wrRegister( ABACUS_REG_0, reg_data );  // write to register 0

        return m_powerUpStatus;
}

