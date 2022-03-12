// {{{RME classifier 'Logical View::HAL_Utility::StdTypes'

#ifndef StdTypes_H
#define StdTypes_H

#ifdef PRAGMA
#pragma interface "StdTypes.h"
#endif

#include <misc_comp.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
// included via the compiler tool chain. Provides types such as
// uint32_t which are sized correctly for the target (e.g. arm9 v.s. c55)
#include <stdint.h>

// define these here since 8 bit sizing is invalid for the c55 and hence, are not
// defined in stdint.h
//typedef unsigned char UINT8;
//typedef char INT8;

// some older files use these uppercase obsolete types
// define them here for now, when time permits, they can be changed in all objects where used.
// PLEASE DO NOT USE THE UPPERCASE TYPDEFS FOR ANY NEW DEVELOPMENT CODE. Use the lowercase ANSI 
// standard types instead.
//typedef uint32_t UINT32;
//typedef int32_t INT32;
//typedef uint16_t UINT16;
//typedef int16_t INT16;


#define volatile_read_UINT8(addr)        (*((volatile unsigned char*)((uint32_t)(addr))))
#define volatile_read_UINT16(addr)       (*((volatile uint16_t*)((uint32_t)(addr))))
#define volatile_read_UINT32(xaddr)      (*((volatile uint32_t*)((uint32_t)(addr))))
#define volatile_write_UINT8(addr,data)  (*((volatile unsigned char*)((uint32_t)(addr))))  =  (unsigned char)(data)
#define volatile_write_UINT16(addr,data) (*((volatile uint16_t*)((uint32_t)(addr)))) = (uint16_t)(data)
#define volatile_write_UINT32(addr,data) (*((volatile uint32_t*)((uint32_t)(addr)))) = (uint32_t)(data)

#define volatile_set_bit_in_UINT8(x,y)     (*((volatile unsigned char*)((uint32_t)(x)))) |= (unsigned char)(y)
#define volatile_set_bit_in_UINT16(x,y)    (*((volatile uint16_t*)((uint32_t)(x)))) |= (uint16_t)(y)
#define volatile_set_bit_in_UINT32(x,y)    (*((volatile uint32_t*)((uint32_t)(x)))) |= (uint32_t)(y)
#define volatile_clear_bit_in_UINT8(x,y)   (*((volatile unsigned char*)((uint32_t)(x)))) &= (~((unsigned char)(y)))
#define volatile_clear_bit_in_UINT16(x,y)  (*((volatile uint16_t*)((uint32_t)(x)))) &= (~((uint16_t)(y)))
#define volatile_clear_bit_in_UINT32(x,y)  (*((volatile uint32_t*)((uint32_t)(x)))) &= (~((uint32_t)(y)))
#define volatile_is_bit_set_in_UINT8(x,y)  ((((*((volatile unsigned char *)((uint32_t)(x)))) & ((unsigned char)(y))) != 0) ? TRUE : FALSE )
#define volatile_is_bit_set_in_UINT16(x,y) ((((*((volatile uint16_t *)((uint32_t)(x)))) & ((uint16_t)(y))) != 0) ? TRUE : FALSE )
#define volatile_is_bit_set_in_UINT32(x,y) ((((*((volatile uint32_t *)((uint32_t)(x)))) & ((uint32_t)(y))) != 0) ? TRUE : FALSE )

// BITFIELDS

#ifndef BIT0
#define BIT0 0x01
#endif

#ifndef BIT1
#define BIT1 0x02
#endif

#ifndef BIT2
#define BIT2 0x04
#endif

#ifndef BIT3
#define BIT3 0x08
#endif

#ifndef BIT4
#define BIT4 0x10
#endif

#ifndef BIT5
#define BIT5 0x20
#endif

#ifndef BIT6
#define BIT6 0x40
#endif

#ifndef BIT7
#define BIT7 0x80
#endif

#ifndef BIT8
#define BIT8 0x0100
#endif

#ifndef BIT9
#define BIT9 0x0200
#endif

#ifndef BIT10
#define BIT10 0x0400
#endif

#ifndef BIT11
#define BIT11 0x0800
#endif

#ifndef BIT12
#define BIT12 0x1000
#endif

#ifndef BIT13
#define BIT13 0x2000
#endif

#ifndef BIT14
#define BIT14 0x4000
#endif

#ifndef BIT15
#define BIT15 0x8000
#endif

#ifndef BIT16
#define BIT16 0x00010000UL
#endif

#ifndef BIT17
#define BIT17 0x00020000UL
#endif

#ifndef BIT18
#define BIT18 0x00040000UL
#endif

#ifndef BIT19
#define BIT19 0x00080000UL
#endif

#ifndef BIT20
#define BIT20 0x00100000UL
#endif

#ifndef BIT21
#define BIT21 0x00200000UL
#endif

#ifndef BIT22
#define BIT22 0x00400000UL
#endif

#ifndef BIT23
#define BIT23 0x00800000UL
#endif

#ifndef BIT24
#define BIT24 0x01000000UL
#endif

#ifndef BIT25
#define BIT25 0x02000000UL
#endif

#ifndef BIT26
#define BIT26 0x04000000UL
#endif

#ifndef BIT27
#define BIT27 0x08000000UL
#endif

#ifndef BIT28
#define BIT28 0x10000000UL
#endif

#ifndef BIT29
#define BIT29 0x20000000UL
#endif

#ifndef BIT30
#define BIT30 0x40000000UL
#endif

#ifndef BIT31
#define BIT31 0x80000000UL
#endif



// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* StdTypes_H */

// }}}RME
