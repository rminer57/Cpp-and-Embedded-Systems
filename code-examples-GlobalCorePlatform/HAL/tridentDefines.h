// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::Trident::TridentPrivate::TridentDefines'

#ifndef TridentDefines_H
#define TridentDefines_H

#ifdef PRAGMA
#pragma interface "TridentDefines.h"
#endif

#include <rf_sequencer_comp.h>
#include <TridentSnippetStatus_s.h>
#include <bitfield.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR







// }}}USR
// }}}RME

// {{{RME classAttribute 'TRIDENT_SNIPPET_SIZE'
#define TRIDENT_SNIPPET_SIZE 2
// }}}RME

// {{{RME classAttribute 'TRIDENT_IMAGE_SIZE_BYTES'
#define TRIDENT_IMAGE_SIZE_BYTES 0x8B
// }}}RME

// {{{RME classAttribute 'TRIDENT_IMAGE_SIZE_INT16'
#define TRIDENT_IMAGE_SIZE_INT16 0x46
// }}}RME

// {{{RME classAttribute 'TRIDENT_NUM_SNIPPETS'
#define TRIDENT_NUM_SNIPPETS (TRIDENT_IMAGE_SIZE_INT16 + 1)
// }}}RME

// {{{RME classAttribute 'TRIDENT_SPI_HEADER_SIZE'
#define TRIDENT_SPI_HEADER_SIZE 1
// }}}RME

// {{{RME classAttribute 'TRIDENT_SPI_MODE_WRITE'
#define TRIDENT_SPI_MODE_WRITE 0
// }}}RME

// {{{RME classAttribute 'TRIDENT_SPI_MODE_ACE1'
#define TRIDENT_SPI_MODE_ACE1 1
// }}}RME

// {{{RME classAttribute 'TRIDENT_SPI_MODE_ACE2'
#define TRIDENT_SPI_MODE_ACE2 2
// }}}RME

// {{{RME classAttribute 'TRIDENT_SPI_MODE_READ'
#define TRIDENT_SPI_MODE_READ 3
// }}}RME

// {{{RME classAttribute 'TRIDENT_CO_FREQ'
#define TRIDENT_CO_FREQ 1680
// }}}RME

// {{{RME classAttribute 'TRIDENT_BW_DATA_SIZE'
#define TRIDENT_BW_DATA_SIZE 64
// }}}RME

// {{{RME classAttribute 'TRIDENT_NUM_GPOS'
#define TRIDENT_NUM_GPOS 6
// }}}RME

// {{{RME classAttribute 'TRIDENT_NUM_GAINS'
#define TRIDENT_NUM_GAINS 4
// }}}RME

// {{{RME classAttribute 'TRIDENT_READ'
#define TRIDENT_READ false
// }}}RME

// {{{RME classAttribute 'TRIDENT_WRITE'
#define TRIDENT_WRITE true
// }}}RME

// {{{RME classAttribute 'TRIDENT_ACCESS_IMAGE'
#define TRIDENT_ACCESS_IMAGE true
// }}}RME

// {{{RME classAttribute 'TRIDENT_ACCESS_IC'
#define TRIDENT_ACCESS_IC false
// }}}RME

// {{{RME classAttribute 'TRIDENT_NUMOF_BITFIELDS'
#define TRIDENT_NUMOF_BITFIELDS 268
// }}}RME

// {{{RME classAttribute 'TRIDENT_INTERNAL_READ'
#define TRIDENT_INTERNAL_READ 0xD0
// }}}RME

// {{{RME classAttribute 'TRIDENT_NUM_GAIN_AMP_AGC'
#define TRIDENT_NUM_GAIN_AMP_AGC 0
// }}}RME

// {{{RME classAttribute 'TRIDENT_NUM_GAIN_BUFGAIN'
#define TRIDENT_NUM_GAIN_BUFGAIN 1
// }}}RME

// {{{RME classAttribute 'TRIDENT_NUM_GAIN_STATT_IQ'
#define TRIDENT_NUM_GAIN_STATT_IQ 3
// }}}RME

// {{{RME classAttribute 'TRIDENT_NUM_GAIN_STATT_EF'
#define TRIDENT_NUM_GAIN_STATT_EF 2
// }}}RME

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* TridentDefines_H */

// }}}RME
