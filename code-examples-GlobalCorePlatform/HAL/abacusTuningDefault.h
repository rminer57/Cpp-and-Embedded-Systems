// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::abacusIII::abacusTuningDefault'

#ifndef abacusTuningDefault_H
#define abacusTuningDefault_H

#ifdef PRAGMA
#pragma interface "abacusTuningDefault.h"
#endif

#include <HALtestLib_win32.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

#define   ABACUS_REG_ADDR     0x00      /* Abacus address register            */
#define   ABACUS_REG_0        0x01      /* Abacus register 1                  */
#define   ABACUS_REG_1        0x02      /* Abacus register 2                  */
#define   ABACUS_REG_2        0x03      /* Abacus register 3                  */
#define   ABACUS_REG_3        0x04      /* Abacus register 4                  */
#define   ABACUS_REG_4        0x05      /* Abacus register 5                  */
#define   ABACUS_REG_5        0x06      /* Abacus register 6                  */
#define   ABACUS_REG_6        0x07      /* Abacus register 7                  */
#define   ABACUS_REG_7        0x08      /* Abacus register 8                  */
#define   ABACUS_REG_8        0x09      /* Abacus register 9                  */
#define   ABACUS_REG_9        0x0A      /* Abacus register 10                 */
#define   ABACUS_REG_10       0x0B      /* Abacus register 11                 */
#define   ABACUS_REG_11       0x0C      /* Abacus register 12                 */
#define   ABACUS_REG_12       0x0D      /* Abacus register 13                 */
#define   ABACUS_REG_13       0x0E      /* Abacus register 14                 */
#define   ABACUS_REG_14       0x0F      /* Abacus register 15                 */
#define   ABACUS_REG_15       0x10      /* Abacus register 16                 */
#define   ABACUS_REG_16       0x11      /* Abacus register 17                 */
#define   ABACUS_REG_17       0x12      /* Abacus register 18                 */
#define   ABACUS_REG_18       0x13      /* Abacus register 19                 */
#define   ABACUS_REG_19       0x14      /* Abacus register 20                 */
#define   ABACUS_REG_20       0x15      /* Abacus register 21                 */
#define   ABACUS_REG_21       0x16      /* Abacus register 22                 */
#define   ABACUS_REG_22       0x17      /* Abacus register 23                 */
#define   ABACUS_REG_23       0x18      /* Abacus register 24                 */
#define   ABACUS_REG_24       0x19      /* Abacus register 25                 */
#define   ABACUS_REG_25       0x1A      /* Abacus register 26                 */
#define   ABACUS_REG_26       0x1B      /* Abacus register 27                 */
#define   ABACUS_REG_27       0x1C      /* Abacus register 28                 */
#define   ABACUS_REG_28       0x1D      /* Abacus register 29                 */
#define   ABACUS_REG_29       0x1E      /* Abacus register 30                 */
#define   ABACUS_REG_30       0x1F      /* Abacus register 31                 */
#define   ABACUS_REG_31       0x20      /* Abacus register 32                 */

#define   ABACUS_TEST_REG_37  0x38      /* Abacus register 37                 */
#define   ABACUS_TEST_REG_38  0x39      /* Abacus register 38                 */
#define   ABACUS_TEST_REG_39  0x3A      /* Abacus register 39                 */
#define   ABACUS_TEST_REG_3A  0x3B      /* Abacus register 3A                 */
#define   ABACUS_TEST_REG_3B  0x3C      /* Abacus register 3B                 */
#define   ABACUS_TEST_REG_3C  0x3D      /* Abacus register 3C                 */
#define   ABACUS_TEST_REG_3D  0x3E      /* Abacus register 3D                 */
#define   ABACUS_TEST_REG_3E  0x3F      /* Abacus register 3E                 */
#define   ABACUS_TEST_REG_3F  0x40      /* Abacus register 3F                 */


#define   MAX_TUNE_TRIES 5
#define   TUNE_BITS 0x03

#define   ABACUS_REV_6    0x06
#define   ABACUS_REV_87   0x87

/* Tuning was introduced in the second revision of the AbacusIII */
#define NON_TUNED_VERSION   1

/* The version number read back from the first LP ABACUSIII (tunable) is 4 */
#define FIRST_TUNED_VERSION 4
#define MAX_VERSION 0XFF

#define VR_PWRUP_OK 0x00
#define VR_PWRUP_ABACUS_FAILURE 0xA0

typedef struct
{
/* Abacus III codeplug structure */

  unsigned short int abacus_reg_addr  ;  /* (ABACUS_REG_ADDR) 0x00 */

  /* Power Control Registers */
  unsigned short int pcr_reg_1   ;      /* (REG 0x00) 0x00 */
  unsigned short int pcr_reg_2   ;      /* (REG 0x01) 0x51 */
  unsigned short int pcr_reg_3   ;       /* (REG 0x02) 0x00 */

  /* AGC */
  unsigned short int agc_reg_1  ;      /* (REG 0x03) 0x3F */ /* 05 bytes */
  unsigned short int agc_reg_2   ;       /* (REG 0x04) 0xFF */
  unsigned short int agc_reg_3  ;       /* (REG 0x05) 0x00 */
  unsigned short int agc_reg_4  ;       /* (REG 0x06) 0x01 */

  /* Unused */
  unsigned short int dec_reg_1  ;       /* (REG 0x07) 0x0E */

  /* LO Synthesizer */
  unsigned short int los_reg_1  ;     /* (REG 0x08) 0x00 */ /* 10 bytes */
  unsigned short int  los_reg_2   ;      /* (REG 0x09) 0xA8 */
  unsigned short int los_reg_3   ;     /* (REG 0x0A) 0x40 */
  unsigned short int los_reg_4   ;      /* (REG 0x0B) 0x35 */
  unsigned short int los_reg_5   ;      /* (REG 0x0C) 0x1F */
  unsigned short int los_reg_6   ;      /* (REG 0x0D) 0x00 */ /* 15 bytes */
  unsigned short int los_reg_7   ;       /* (REG 0x0E) 0x04 */

  /* Unused */
  unsigned short int rsv_reg_0F  ;      /* (REG 0x0F) 0x00 */

  /* Clock Synthesizer */
  unsigned short int cls_reg_1  ;       /* (REG 0x10) 0x00 */
  unsigned short int cls_reg_2   ;       /* (REG 0x11) 0xA8 */
  unsigned short int cls_reg_3   ;      /* (REG 0x12) 0x00 */ /* 20 bytes */
  unsigned short int cls_reg_4   ;      /* (REG 0x13) 0xB4 */
  unsigned short int cls_reg_5   ;     /* (REG 0x14) 0x1F */
  unsigned short int cls_reg_6   ;       /* (REG 0x15) 0x00 */
  unsigned short int cls_reg_7   ;       /* (REG 0x16) 0x04 */

  /* Unused */
  unsigned short int rsv_reg_17   ;      /* (REG 0x17) 0x00 */ /* 25 bytes */

  /* SSI Control */
  unsigned short int ssi_reg_1  ;      /* (REG 0x18) 0x00 */
  unsigned short int ssi_reg_2   ;      /* (REG 0x19) 0x03 */
  unsigned short int ssi_reg_3   ;      /* (REG 0x1A) 0x0F */

  /* Unused */
  unsigned short int rsv_reg_1B   ;      /* (REG 0x1B) 0x00 */

  /* AAF Capacitor Setting/Calibration */
  unsigned short int aaf_reg_1   ;       /* (REG 0x1C) 0x60 */ /* 30 bytes */
  unsigned short int aaf_reg_2   ;       /* (REG 0x1D) 0x0F */
  unsigned short int aaf_reg_3   ;       /* (REG 0x1E) 0x00 */
  unsigned short int aaf_reg_4   ;      /* (REG 0x1F) 0x00 */

  /* Unused */
  unsigned short int rsv_reg_20   ;      /* (REG 0x20) 0x00 */
  unsigned short int rsv_reg_21   ;      /* (REG 0x21) 0x40 */ /* 35 bytes */
  unsigned short int rsv_reg_22   ;     /* (REG 0x22) 0x00 */
  unsigned short int rsv_reg_23   ;      /* (REG 0x23) 0x00 */
  unsigned short int rsv_reg_24  ;     /* (REG 0x24) 0x00 */
  unsigned short int rsv_reg_25   ;     /* (REG 0x25) 0x00 */
  unsigned short int rsv_reg_26   ;      /* (REG 0x26) 0x00 */ /* 40 bytes */

  /* Test Registers */
  unsigned short int tst_reg_1   ;       /* (REG 0x38) 0x00 */
  unsigned short int tst_reg_2  ;      /* (REG 0x39) 0x00 */
  unsigned short int tst_reg_3   ;      /* (REG 0x3A) 0x00 */
  unsigned short int tst_reg_4   ;      /* (REG 0x3B) 0x00 */
  unsigned short int tst_reg_5   ;     /* (REG 0x3C) 0x00 */ /* 45 bytes */
  unsigned short int tst_reg_6   ;       /* (REG 0x3D) 0x00 */
  unsigned short int tst_reg_7   ;      /* (REG 0x3E) 0x40 */
  unsigned short int  tst_reg_8  ;       /* (REG 0x3F) 0x01 */

  /* ABACUS 2nd LO low side values*/
  unsigned short int LO_low_side_1   ; 
  unsigned short int LO_low_side_2   ;                         /* 50 bytes */
  unsigned short int LO_low_side_3   ; 
  unsigned short int LO_low_side_4   ; 

  /* ABACUS 2nd LO high side values*/
  unsigned short int LO_high_side_1   ; 
  unsigned short int LO_high_side_2   ; 
  unsigned short int LO_high_side_3   ;                      /* 55 bytes */
  unsigned short int LO_high_side_4  ; 
  unsigned short int revision_id ;
} abacus3_blk_t;

#define SIZE_OF_ABACUS_IMAGE  65

#define ABACUS_TOTAL_NUMOF_REGISTERS  30

typedef struct
{ 
  unsigned short int image[ SIZE_OF_ABACUS_IMAGE ]; 
} abacus_image_t;

/* Default Abacus image.  This image is for VHF. */
const abacus_image_t  local_image_default_values =
{
  0x00,       /* ABACUS_REG_ADDR                   */
  0x00,       /* ABACUS_REG_0                      */
  0x51,       /* ABACUS_REG_1                      */
  0x00,       /* ABACUS_REG_2                      */
  0x3F,       /* ABACUS_REG_3                      */
  0xFF,      /* ABACUS_REG_4                      */
  0x00,      /* ABACUS_REG_5                      */
  0x01,      /* ABACUS_REG_6                      */
  0x0E,     /* ABACUS_REG_7                      */
  0x00,     /* ABACUS_REG_8                      */
  0xA8,    /* ABACUS_REG_9                      */
  0x40,    /* ABACUS_REG_10                     */
  0x86,    /* ABACUS_REG_11                     */
  0x03,    /* ABACUS_REG_12                     */
  0x00,    /* ABACUS_REG_13                     */
  0x04,    /* ABACUS_REG_14                     */
  0x00,    /* ABACUS_REG_15                     */
  0x00,    /* ABACUS_REG_16                     */
  0xA8,   /* ABACUS_REG_17                     */
  0x00,    /* ABACUS_REG_18                     */
  0xB4,   /* ABACUS_REG_19                     */
  0x1F,    /* ABACUS_REG_20                     */
  0x00,    /* ABACUS_REG_21                     */
  0x04,    /* ABACUS_REG_22                     */
  0x00,    /* ABACUS_REG_23                     */
  0x00,    /* ABACUS_REG_24                     */
  0x03,    /* ABACUS_REG_25                     */
  0x0F,    /* ABACUS_REG_26                     */
  0x00,    /* ABACUS_REG_27                     */
  0x60     /* ABACUS_REG_28                     */
};
// }}}USR
// }}}RME

class abacusTuningDefault
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
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* abacusTuningDefault_H */

// }}}RME
