// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::abacusIII::abacusIII'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "abacusIII.h"
#endif

#include <HALtestLib_win32.h>
#include <abacusIII.h>
#include <Connection.h>
#include <SIntArray.h>
#include <abacusDefault.h>
#include <rfSpiBuffer.h>
#include <rf_audio_std_types.h>
#include <sequencerTimer.h>
#include <units.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
#ifdef OMAP_HALI_C55


// POWER CONTROL REGISTERS

// UINT 0
defineBitField(STBY,uint32_t,0,24,7);         // BYTE 0
defineBitField(ADCB,uint32_t,0,22,2);         // BYTE 1 
defineBitField(CKOB,uint32_t,0,20,2);
defineBitField(MIXB,uint32_t,0,18,2);
defineBitField(LNAB,uint32_t,0,16,2);
// BYTE 2 UNUSED
// AGC
defineBitField(AGCG_MSBS,uint32_t,0,1,7);   // BYTE 3
defineBitField(ATTEN,uint32_t,0,0,1);

// UINT 1
defineBitField(AGCG_LSBS,uint32_t,4,24,8);    // BYTE 4
defineBitField(AGCD,uint32_t,4,20,4);         // BYTE 5
defineBitField(AGCA,uint32_t,4,16,4);
defineBitField(AGCR,uint32_t,4,13,3);        // BYTE 6
defineBitField(AGCF,uint32_t,4,12,1);
defineBitField(AGCO,uint32_t,4,9,3);
defineBitField(AGCV,uint32_t,4,8,1);
defineBitField(M,uint32_t,4,4,4);           // BYTE 7
defineBitField(K,uint32_t,4,3,1);

// UINT 2
// LO SYNTHESIZER
defineBitField(LOR_MSBS,uint32_t,8,27,6);     // BYTE 8
defineBitField(LOR_LSBS,uint32_t,8,16,8);     // BYTE 9
defineBitField(LOB_MSBS,uint32_t,8,12,5);    // BYTE 10
defineBitField(LOA,uint32_t,8,9,3);
defineBitField(LOB_LSBS,uint32_t,8,0,8);    // BYTE 11 

// UINT 3
defineBitField(LOTM,uint32_t,12,30,2);        // BYTE 12
defineBitField(LOI,uint32_t,12,27,3);
defineBitField(LOINV,uint32_t,12,26,1);
defineBitField(LOF,uint32_t,12,25,1);
defineBitField(LOFA_MSBS,uint32_t,12,18,6);   // BYTE 13
defineBitField(LOFA_LSBS,uint32_t,12,8,8);  // BYTE 14
// BYTE 15 UNUSED

// UINT 4
// CLOCK SYNTHESIZER
defineBitField(CKR_MSBS,uint32_t,16,26,6);    // BYTE 16
defineBitField(CKR_LSBS,uint32_t,16,16,8);    // BYTE 17
defineBitField(CKN_MSBS,uint32_t,16,12,5);   // BYTE 18
defineBitField(CKN_LSBS,uint32_t,16,0,8);   // BYTE 19

// UINT 5
defineBitField(CKTM,uint32_t,20,30,2);        // BYTE 20
defineBitField(CKI,uint32_t,20,27,3);
defineBitField(CKINV,uint32_t,20,26,1);
defineBitField(CKF,uint32_t,20,25,1);
defineBitField(CKFA_MSBS,uint32_t,20,19,6);   // BYTE 21
defineBitField(CKFA_LSBS,uint32_t,20,8,8);  // BYTE 22
// BYTE 23 UNUSED

// UINT 6
// SSI CONTROL
defineBitField(SSICRA,uint32_t,24,24,8);      // BYTE 24
defineBitField(SSICRB,uint32_t,24,16,8);      // BYTE 25
defineBitField(SSIORD,uint32_t,24,12,4);     // BYTE 26
// BYTE 27 UNUSED

// UINT 7  
// ADC TUNING
defineBitField(TUNE_RC,uint32_t,28,31,1);     // BYTE 28
defineBitField(TUNE_LC,uint32_t,28,30,1);
defineBitField(CAPL1,uint32_t,28,21,3);       // BYTE 29
defineBitField(CAPL0,uint32_t,28,10,6);      // BYTE 30
defineBitField(CAPR,uint32_t,28,0,8);       // BYTE 31

#else


// POWER CONTROL REGISTERS

// UINT 0
defineBitFieldRev(STBY,uint32_t,0,24,7);         // BYTE 0
defineBitFieldRev(ADCB,uint32_t,0,22,2);         // BYTE 1 
defineBitFieldRev(CKOB,uint32_t,0,20,2);
defineBitFieldRev(MIXB,uint32_t,0,18,2);
defineBitFieldRev(LNAB,uint32_t,0,16,2);
// BYTE 2 UNUSED
// AGC
defineBitFieldRev(AGCG_MSBS,uint32_t,0,1,7);   // BYTE 3
defineBitFieldRev(ATTEN,uint32_t,0,0,1);

// UINT 1
defineBitFieldRev(AGCG_LSBS,uint32_t,4,24,8);    // BYTE 4
defineBitFieldRev(AGCD,uint32_t,4,20,4);         // BYTE 5
defineBitFieldRev(AGCA,uint32_t,4,16,4);
defineBitFieldRev(AGCR,uint32_t,4,13,3);        // BYTE 6
defineBitFieldRev(AGCF,uint32_t,4,12,1);
defineBitFieldRev(AGCO,uint32_t,4,9,3);
defineBitFieldRev(AGCV,uint32_t,4,8,1);
defineBitFieldRev(M,uint32_t,4,4,4);           // BYTE 7
defineBitFieldRev(K,uint32_t,4,3,1);

// UINT 2
// LO SYNTHESIZER
defineBitFieldRev(LOR_MSBS,uint32_t,8,27,6);     // BYTE 8
defineBitFieldRev(LOR_LSBS,uint32_t,8,16,8);     // BYTE 9
defineBitFieldRev(LOB_MSBS,uint32_t,8,12,5);    // BYTE 10
defineBitFieldRev(LOA,uint32_t,8,9,3);
defineBitFieldRev(LOB_LSBS,uint32_t,8,0,8);    // BYTE 11 

// UINT 3
defineBitFieldRev(LOTM,uint32_t,12,30,2);        // BYTE 12
defineBitFieldRev(LOI,uint32_t,12,27,3);
defineBitFieldRev(LOINV,uint32_t,12,26,1);
defineBitFieldRev(LOF,uint32_t,12,25,1);
defineBitFieldRev(LOFA_MSBS,uint32_t,12,18,6);   // BYTE 13
defineBitFieldRev(LOFA_LSBS,uint32_t,12,8,8);  // BYTE 14
// BYTE 15 UNUSED

// UINT 4
// CLOCK SYNTHESIZER
defineBitFieldRev(CKR_MSBS,uint32_t,16,26,6);    // BYTE 16
defineBitFieldRev(CKR_LSBS,uint32_t,16,16,8);    // BYTE 17
defineBitFieldRev(CKN_MSBS,uint32_t,16,12,5);   // BYTE 18
defineBitFieldRev(CKN_LSBS,uint32_t,16,0,8);   // BYTE 19

// UINT 5
defineBitFieldRev(CKTM,uint32_t,20,30,2);        // BYTE 20
defineBitFieldRev(CKI,uint32_t,20,27,3);
defineBitFieldRev(CKINV,uint32_t,20,26,1);
defineBitFieldRev(CKF,uint32_t,20,25,1);
defineBitFieldRev(CKFA_MSBS,uint32_t,20,19,6);   // BYTE 21
defineBitFieldRev(CKFA_LSBS,uint32_t,20,8,8);  // BYTE 22
// BYTE 23 UNUSED

// UINT 6
// SSI CONTROL
defineBitFieldRev(SSICRA,uint32_t,24,24,8);      // BYTE 24
defineBitFieldRev(SSICRB,uint32_t,24,16,8);      // BYTE 25
defineBitFieldRev(SSIORD,uint32_t,24,12,4);     // BYTE 26
// BYTE 27 UNUSED

// UINT 7  
// ADC TUNING
defineBitFieldRev(TUNE_RC,uint32_t,28,31,1);     // BYTE 28
defineBitFieldRev(TUNE_LC,uint32_t,28,30,1);
defineBitFieldRev(CAPL1,uint32_t,28,21,3);       // BYTE 29
defineBitFieldRev(CAPL0,uint32_t,28,10,6);      // BYTE 30
defineBitFieldRev(CAPR,uint32_t,28,0,8);       // BYTE 31


#endif



unsigned short int abacusValues[3] = {   0x02, 0x17, 0x4E };
unsigned short int abacus_version_read;

/* Global image holder. */
//abacus3_blk_t  abacus3_blk;
abacus_image_t abacus_image;
abacus_image_t active_abacus_image;   /* Copy of the currently active image */

/* Flag to tell HW manager when to update abacus tuning values in the codeplug */
unsigned short int  abacus_codeplug_update = 0;     

// }}}USR
// }}}RME

// {{{RME operation 'abacusIII(abacusDefault*,rfSpiBuffer**,int,abacus3_blk_t *,sequencerTimer *,Connection *,bool)'
abacusIII::abacusIII( abacusDefault * init, rfSpiBuffer * * spiBuffers, int numberOfRfStates, abacus3_blk_t * cpImagePtr, sequencerTimer * thesequencerTimer, Connection * conn, bool EnableSpi4Wire )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: frequencyConversionReference(numberOfRfStates),
	    bbpControl(numberOfRfStates)

	// }}}USR
	// }}}RME
{
	// {{{USR

	  m_abacus3_blk = cpImagePtr; // same the external address of codeplug ram image

	  seqTimer = thesequencerTimer;

	  m_connection = conn; // save the IOVirtualSerial connection (e.g. spi)

	  m_spi4wireEnabled = EnableSpi4Wire; // default is false (3 wire operation) 

	  initAbacusIII(init,spiBuffers, numberOfRfStates);

	  m_powerUpStatus |= VR_PWRUP_ABACUS_FAILURE;

	  if( cpImagePtr != 0)
	  {
	    autotune();
	  }


	// }}}USR
}
// }}}RME

// {{{RME operation 'setLO(Integer,Integer)'
Integer abacusIII::setLO( Integer freq, Integer rfState )
{
	// {{{USR
	  Integer loa;
	  Integer lob;
	  Integer nDividerFactor;
	  uint32_t *image;      // pointer to current image based on rfState

	  // calculate current image to use
	  image = *spi[rfState];
	  
	  // calculate values to program
	  nDividerFactor = freq/swFref;
	  lob = nDividerFactor/8;
	  loa = nDividerFactor - (lob*8);
	  
	  // set LOB in image
	  setBitField(image, LOB_MSBS, ((lob>>8)&0x1f));
	  setBitField(image, LOB_LSBS, (lob&0xff));
	  
	  // set LOA in image
	  setBitField(image, LOA, loa);
	  
	  // call parent to set and return previous value
	  return frequencyConversionReference::setLO(freq, rfState);  
	// }}}USR
}
// }}}RME

// {{{RME operation 'setRFState(Integer)'
Integer abacusIII::setRFState( Integer rfState )
{
	// {{{USR
	  // synchronize on state change
	  spi[rfState]->sync();

	  // call to (an arbitrary) parent and return previous value
	  return frequencyConversionReference::setRFState(rfState);  
	// }}}USR
}
// }}}RME

// {{{RME operation 'setBBPFrequency(Integer,Integer)'
Integer abacusIII::setBBPFrequency( Integer frequency, Integer rfState )
{
	// {{{USR
	  uint32_t *image;
	  image = *spi[rfState];

	  switch(frequency)
	  {
	    case (1200000):
	      setBitField(image, SSIORD, 0xF);
	      break;
	    case (1500000):
	      setBitField(image, SSIORD, 0xC);
	      break;
	    default: // 1.8 MHZ
	      setBitField(image, SSIORD, 0xA);
	      break;
	  }

	  return bbpControl::setBBPFrequency(frequency, rfState);
	// }}}USR
}
// }}}RME

// {{{RME operation 'initAbacusIII(abacusDefault*,rfSpiBuffer**,Integer)'
void abacusIII::initAbacusIII( abacusDefault * init, rfSpiBuffer * * spiBuffers, Integer numberOfRfStates )
{
	// {{{USR
	  int i, j;
	  // set default data object pointer to one passed in
	  defaultData = init;
	  spi = spiBuffers;
	  
	  // set reference frequencies used to program the LO
	  hwFref = defaultData->defaultHwFref;
	  swFref = defaultData->defaultSwFref;
	  
	  // set lor since it is static as long as hw/swFref don't change
	  lor = hwFref/swFref;
	  
	  // initialize images to default images
	  for(i = 0; i < numberOfRfStates; i++)
	  {
	    for(j = 0; j < ABACUS_IMAGE_SIZE_32; j++)
	    {
	      (*spi[i])[j] = defaultData->defaultImages[i][j];
	    }

	    // write to LO portion of both image
	    // if we can make the assumption that the LOR portion of images
	    // is written to before any call to set LO, we don't have to
	    // program LOR portion of image b/c values are static and don't change
	    setBitField((*spi[i]), LOR_MSBS, ((lor>>8)&0x3f));
	    setBitField((*spi[i]), LOR_LSBS, (lor&0xff));
	  }
	// }}}USR
}
// }}}RME

// {{{RME operation 'autotune()'
void abacusIII::autotune( void )
{
	// {{{USR

	      m_powerUpStatus = VR_PWRUP_OK;

	      unsigned char id_buf_read;
	      unsigned char tune_count;		  
		  unsigned char tune_buf_read;	
	      unsigned char tune_capl1_read;
	      unsigned char tune_capl0_read;	
	      unsigned char tune_capr_read;

		  uint32_t *image;      // pointer to current image based on rfState
	 
	      // calculate current image to use
	      image = &((*spi[0])[1]);  // 0 -> rfstate , 1-> spi header size

		 /* Enable SPI read - 3 wire and 4 wire both supported */
		 spiReadEnable();


		 /* Read register $3F of AD987x to determine revision ID */
		 id_buf_read = rdRegister( ABACUS_TEST_REG_3F );

	   	                       
		 if ((id_buf_read >= FIRST_TUNED_VERSION) && (id_buf_read < MAX_VERSION))   
		 {                  

		   tune_count = MAX_TUNE_TRIES;
		 
		   while (tune_count > 0)
		   {
		   
		 
		      /* Program register 0x3F (ID) to 0x99 to soft Reset Abacus. */
		      wrRegister( ABACUS_TEST_REG_3F, 0x99);

		      /* Reset the copy of the active image since we reset */
	          for(int i = 0; i < SIZE_OF_ABACUS_IMAGE; i++)
	          {
	              abacus_image.image[i] = 0xFF;
	          }

		      /* Copy the default Abacus image to the program image. */
				memcpy(abacus_image.image, m_abacus3_blk, ABACUS_TOTAL_NUMOF_REGISTERS);
		
		      /* REF, CK, GC = ON */
		      abacus_image.image[ABACUS_REG_0] = abacus_image.image[ABACUS_REG_0] | 0x45;
		 
		      /* Program registers 0x00 to 0x1B. with image */
		      program();
	         

		      /* Enable SPI read - 3 wire and 4 wire both supported */
		      spiReadEnable();  
		
		      /* Program register 0x1C (Tune LC and RC) to 0x03. */
		      wrRegister( ABACUS_REG_28, 0x03);

			  /* Delay ~5 ms */
	          delay_usec(5000);
		
		      /* Program register 0x00 (ADC out of standby). */
		      wrRegister( ABACUS_REG_0, abacus_image.image[ABACUS_REG_0]& 0xFE);
		 
		      /* Delay ~6 ms */
		      delay_usec(6000);
		 
		      /* Read register $1C of AD9874, if zero tuning was successful, else try again  */
		      tune_buf_read = rdRegister( ABACUS_REG_28 );	
		      abacus_image.image[ABACUS_REG_27] = tune_buf_read;
	          setBitField(image, TUNE_RC, tune_buf_read ); // update tune image for sequencer
	          setBitField(image, TUNE_LC, (tune_buf_read >>1)); // update tune image for sequencer 
		                    
		      /* Read register $1D of AD9874 */
		      tune_capl1_read = rdRegister( ABACUS_REG_29 );	                            
		      abacus_image.image[ABACUS_REG_28] = tune_capl1_read;
	          setBitField(image, CAPL1, tune_capl1_read); // update tune image for sequencer	
		                      
		      /* Read register $1E of AD9874 */
		      tune_capl0_read = rdRegister( ABACUS_REG_30 );	                            
		      abacus_image.image[ABACUS_REG_29] = tune_capl0_read;
	          setBitField(image, CAPL0, tune_capl0_read); // update tune image for sequencer  
		                      
		      /* Read register $1F of AD9874 */
		      tune_capr_read= rdRegister( ABACUS_REG_31);                            
		      abacus_image.image[ABACUS_REG_30] = tune_capr_read;
	          setBitField(image, CAPR, tune_capr_read); // update tune image for sequencer                       
		                            
		      tune_count--;

	          // examine image of register $1C, masking all bits except D0=TUNE_RC and D1=TUNE_LC
	          // if autotune succeeded, these bits will be cleared. 	      
		      if ((tune_buf_read & (unsigned char)TUNE_BITS) == 0 )
		      {
		         tune_count = 0; // set count to zero in order to exit while loop, tuning is done.

		         /* Tuning was successful,  update the tuning values in the codeplug with the */
		         /* new values only when difference between the new and the old is greater than 1. */

		         if ( ( (m_abacus3_blk->aaf_reg_2 - tune_capl1_read) > 1 ) || ( (m_abacus3_blk->aaf_reg_2 - tune_capl1_read) < -1)  ||
		              ( (m_abacus3_blk->aaf_reg_3 - tune_capl0_read) > 1 ) || ( (m_abacus3_blk->aaf_reg_3 - tune_capl0_read) < -1)  ||
		              ( (m_abacus3_blk->aaf_reg_4 - tune_capr_read) > 1 )  || ( (m_abacus3_blk->aaf_reg_2 - tune_capl1_read) < -1)   ) 
		 	        {
		              abacusValues[0] = tune_capl1_read;
		              abacusValues[1] = tune_capl0_read;
		              abacusValues[2] = tune_capr_read;

		              /* Signal HW manager task to update codeplug */
		              abacus_codeplug_update = 1;
			        }

		      }     
		      else  /* tuning fail */
		      {
		          if (tune_count == 0)
		          {

		            /* Program register 0x1C (AAR) with 00  to disable further tuning*/
		            wrRegister( ABACUS_REG_28, 00);
		 
		            /* Program register 0x1D with known good value from the codeplug */
		            wrRegister( ABACUS_REG_29, m_abacus3_blk->aaf_reg_2);

		            /* Program register 0x1E ) with known good value from the codeplug */
		            wrRegister( ABACUS_REG_30, m_abacus3_blk->aaf_reg_3);

		            /* Program register 0x1F  with known good value from the codeplug */
		            wrRegister( ABACUS_REG_31, m_abacus3_blk->aaf_reg_4);
		           
		          }
		      } 
		   
		   } // end while (tune_count > 0)

		      wrRegister( ABACUS_REG_0, m_abacus3_blk->pcr_reg_1);
	          wrRegister( ABACUS_TEST_REG_3B, 0x08);  /* triastate DOUB */

		   
		 }
		 else // if ((id_buf_read >= FIRST_TUNED_VERSION) && (id_buf_read < MAX_VERSION))
		 {
		   /* set fatal error if ABACUSIII version reads back 0-3 or $FF */
		   m_powerUpStatus |= VR_PWRUP_ABACUS_FAILURE;
		 }     


	// }}}USR
}
// }}}RME

// {{{RME operation 'wrRegister(unsigned short,unsigned short)'
void abacusIII::wrRegister( unsigned short reg_no, unsigned short reg_data )
{
	// {{{USR

	  int16_t wrData = 0;

	  // Set register target and register data. 
	  // subtract 1 from reg_no to get Abacus Reg. address. 
	  // register numbering begins at 1 (e.g. #define   ABACUS_REG_0 0x01) 
	  // also shift left one bit, since bit 0 is required by Abacus to be don't care. 
	  // bit D7 is rd/wr~, in this case, zero for write 

	  wrData =  (((reg_no-1) << 1) << 8 ) + reg_data ;      

	  // Send 2 bytes ( reg addr + data) over the connection. The spi peripheral always 
	  // sends MSB first. Abacus registers are 8 bits wide.  The first 8 bits 
	  // sent to abacus must be the data followed by the register address. 
	  // SIntArray elements are 16 bits wide. Hence, an SIntArray size of 1 is required. 
	  m_connection->send( new SIntArray( 1, &wrData) );


	// }}}USR
}
// }}}RME

// {{{RME operation 'rdRegister(unsigned short int)'
unsigned short int abacusIII::rdRegister( unsigned short int reg_no )
{
	// {{{USR
	 
	 int16_t regval = 0;  // register read value to be returned
	 int16_t wrData = 0;
	 
	 SIntArray * db; // DataBuffer reference used as the return value for recieve

	 // Set register target and register data. 
	 // subtract 1 from reg_no to get Abacus Reg. address since register numbering begins 
	 // at 1 (e.g. #define   ABACUS_REG_0 0x01) 
	 // also shift left one bit, since bit 0 is don't care. 
	 // bit D7 is rd/wr~, in this case, zero for write 
	 // D7 = 1 for rd, D6-D1 = address, D0 is don't care.
	 wrData = ((( (reg_no - 1 ) << 1) | 0x80) << 8 ) + 0xFF ;

	 /* perform a dummy write to the Abacus device. */
	 m_connection->send( new SIntArray( 1, (int16_t *)&wrData) );

	 db = (SIntArray *)m_connection->receive();

	 // read the register data. Only 8 bits are significant, others are don't care.
	 regval = (*db)[0];

	 delete db;
	  
	 return regval; 
	 
	 
	// }}}USR
}
// }}}RME

// {{{RME operation 'delay_usec(int)'
void abacusIII::delay_usec( int delayuSec )
{
	// {{{USR

	seqTimer->delay(delayuSec);
	// }}}USR
}
// }}}RME

// {{{RME operation 'memcpy(void *,const void *,int)'
void abacusIII::memcpy( void * dst, const void * src, int len )
{
	// {{{USR
	unsigned short int * destination;
	unsigned short int * source = (unsigned short int *)src;

	// copy memory contents from source to destination
	for (destination = (unsigned short int *)dst; --len >= 0; *destination++ = *source++);

	// }}}USR
}
// }}}RME

// {{{RME operation 'program()'
void abacusIII::program( void )
{
	// {{{USR
	    int changedValue = 0;
	   
	    // perform a memory compare and write out any changes
	    for(int i = 1; i < ABACUS_TOTAL_NUMOF_REGISTERS - 1; i++)
	    {
	       
	       if( abacus_image.image[i] != active_abacus_image.image[i])
	       {
	        changedValue = 1;
	        wrRegister( (ABACUS_REG_0 + i - 1), abacus_image.image[i]);
	       }
	    }


	    if( changedValue )
	    {
	        /* Save currently  active image */
	        memcpy( active_abacus_image.image, abacus_image.image, (ABACUS_TOTAL_NUMOF_REGISTERS - 1) );     
	    }

	// }}}USR
}
// }}}RME

// {{{RME operation 'spiReadEnable()'
void abacusIII::spiReadEnable( void )
{
	// {{{USR

	   
	  /* the following must be done in both modes */
	  /* Program register 0x3A (enable SPI read) bit D3 SPIREN to 1. Zero is default for other bits */
	  wrRegister( ABACUS_TEST_REG_3A, 0x08);

	// m_spi4wireEnabled is initialized by the constructor
	if( m_spi4wireEnabled == true ) // 4-wire operation
	{
	  /* set Register 0x19 bit D7 (SSICRB register) */
	  /* according to the data sheet, doing so will enable the 4 wire interface and result in */
	  /* the output data (being read from Abacus) to appear on the DOUTB pin */
	  /* of Abacus Pin 30 Quad-Flatpack package */
	  /* DOUTB is also used for data output of SSI Inverted data */
	  /* default state of this bit is 0 on power-up, to avoid bus contention */
	  /* since tuning is done on power-up only, SSI is not being used and is of no concern */

	  /* Program register 0x19 bit D7 to 1, to enable 4-wire, according to data sheet */
	  /* other bits are dont care */
	   wrRegister( ABACUS_REG_25, 0x80);  

	  /* Program register 0x3B bit D3 DBOUTB Tri-State ON, to 0, enabling the output */
	  /* other bits are dont care */
	  wrRegister( ABACUS_TEST_REG_3B, 0x00);  

	 
	}
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
