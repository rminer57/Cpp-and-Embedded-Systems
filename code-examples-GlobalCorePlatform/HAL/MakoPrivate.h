// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoPrivateHeaders::MakoPrivate'

#ifndef MakoPrivate_H
#define MakoPrivate_H

#ifdef PRAGMA
#pragma interface "MakoPrivate.h"
#endif

#include <HALtestLib_win32.h>
#include <bitfield.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>

#ifndef MAKO_PRIVATE_HDR
#define MAKO_PRIVATE_HDR

// Definitions for MAKO Bit Fields
#define DAC_REGISTER_BASE 0
#define MAKO_READ 0                                             // To read data back from Mako
#define MAKO_WRITE 1                                            // To write data to Mako

// add these to top of MakoPrivate
#define MAKO_ZERO_REGISTER_BASE 0
#define MAKO_BITFIELD_SIZE_1 1
#define MAKO_BITFIELD_SIZE_2 2
#define MAKO_BITFIELD_SIZE_3 3
#define MAKO_BITFIELD_SIZE_4 4
#define MAKO_BITFIELD_SIZE_5 5
#define MAKO_BITFIELD_SIZE_6 6
#define MAKO_BITFIELD_SIZE_7 7
#define MAKO_BITFIELD_SIZE_8 8
#define MAKO_BITFIELD_SIZE_9 9
#define MAKO_BITFIELD_SIZE_10 10
#define MAKO_BITFIELD_SIZE_28 28
 
#define MAKO_RDWR_FIELD_LSBBIT_31 31
#define MAKO_ADDR_FIELD_LSBBIT_28 28
#define MAKO_SUBCOMP_DATA_FIELD_LSBBIT_0 0

#define MAKO_HIGHEST_REG_ADDR 7



// Read/write control bitfield MAKO_READ_WRITE_CNTRL_MAKO definition - applicable to all MAKO registers
defineBitField( MAKO_READ_WRITE_CNTRL, uint32_t, MAKO_ZERO_REGISTER_BASE, MAKO_RDWR_FIELD_LSBBIT_31, MAKO_BITFIELD_SIZE_1 );

// Read/write control bitfield MAKO_REG_ADDRESS definition - applicable to all MAKO registers
defineBitField(MAKO_REG_ADDRESS,uint32_t,MAKO_ZERO_REGISTER_BASE,MAKO_ADDR_FIELD_LSBBIT_28,MAKO_BITFIELD_SIZE_3);

// bitfield MAKO_SUBCOMP_DATA definition - sub-component data, applicable to all MAKO registers (D27 - D0)
defineBitField( MAKO_SUBCOMP_DATA, uint32_t, MAKO_ZERO_REGISTER_BASE,  MAKO_SUBCOMP_DATA_FIELD_LSBBIT_0, MAKO_BITFIELD_SIZE_28 );



#define MAKO_AD_ENABLE 1
#define MAKO_AD_DISABLE 0

#define NUMBER_OF_OPT_CTRL_RESOURCES 1  // 1 resource bound to all GPIOs
// used to allocate space for the image array
#define MAKO_NUMBER_OF_IDCTRL_REGISTER_GROUPS 3

// number of selectable audio register groups...sreg 1 - 5 and PA-REG, PA_SCP
#define MAKO_NUMBER_OF_AUDIO_REGISTER_GROUPS 3

// register indices in the Mako image array m_audioRegImageArray[MAKO_NUMBER_OF_AUDIO_REGISTERS]
#define SREG1_3 0
#define SREG4_5 1
#define SREG_PA 2

typedef uint32_t (* USB_EventHandlerFP_t )(uint32_t arg); /* FuncType is a function pointer type */


#endif //ifndef MAKO_PRIVATE_HDR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* MakoPrivate_H */

// }}}RME
