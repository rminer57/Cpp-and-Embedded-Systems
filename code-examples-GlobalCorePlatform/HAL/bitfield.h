// {{{RME classifier 'Logical View::HAL Instantiation::Standard Includes::bitfield'

#ifndef bitfield_H
#define bitfield_H

#ifdef PRAGMA
#pragma interface "bitfield.h"
#endif

#include <HALtestLib_win32.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>

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




// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* bitfield_H */

// }}}RME
