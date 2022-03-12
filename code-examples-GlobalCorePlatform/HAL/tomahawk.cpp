// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::tomahawk::tomahawk'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "tomahawk.h"
#endif

#include <HALtestLib_win32.h>
#include <tomahawk.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'tomahawkDiscreteRegEnum_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'tomahawkGainRegEnum_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'tomahawkGpoRegEnum_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'tomahawk(tomahawkDefault*,rfSpiBuffer**,int,int,int,int)'
tomahawk::tomahawk( tomahawkDefault * init, rfSpiBuffer * * spiBuffers, int numberOfRfStates, int numberOfDiscretes, int numberOfGPOs, int numberOfGains )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	:discreteDeviceControl(numberOfDiscretes, numberOfRfStates),
	  synthesizer(numberOfRfStates),
	  generalPurposeOutputManager(numberOfGPOs),
	  gainControl(numberOfGains, numberOfRfStates, 0),
	  bbpControl(numberOfRfStates)

	// }}}USR
	// }}}RME
{
	// {{{USR
	 //----------------------------- LOCAL VARIABLES ------------------------------

	  
	 //---------------------------------- CODE ------------------------------------  
	  
	 // Call the common code shared amongst the Tomahawk constructors
	  cmnTomahawkConstructor(init, spiBuffers, numberOfRfStates);



	// }}}USR
}
// }}}RME

// {{{RME operation 'tomahawk(tomahawkDefault*,rfSpiBuffer**,int)'
tomahawk::tomahawk( tomahawkDefault * init, rfSpiBuffer * * spiBuffers, int numberOfRfStates )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	:discreteDeviceControl(NUM_TOMAHAWK_DISCRETES, numberOfRfStates),
	  synthesizer(numberOfRfStates),
	  generalPurposeOutputManager(NUM_TOMAHAWK_GPOS),
	  gainControl(NUM_TOMAHAWK_GAINS, numberOfRfStates, 0),
	  bbpControl(numberOfRfStates)

	// }}}USR
	// }}}RME
{
	// {{{USR
	 //----------------------------- LOCAL VARIABLES ------------------------------

	  
	 //---------------------------------- CODE ------------------------------------  
	  
	 // Call the common code shared amongst the Tomahawk constructors
	  cmnTomahawkConstructor(init, spiBuffers, numberOfRfStates);

	// }}}USR
}
// }}}RME

// {{{RME operation 'cmnTomahawkConstructor(tomahawkDefault*,rfSpiBuffer**,int)'
void tomahawk::cmnTomahawkConstructor( tomahawkDefault * init, rfSpiBuffer * * spiBuffers, int numberOfRfStates )
{
	// {{{USR
	  //----------------------------- LOCAL VARIABLES ------------------------------

	  int i, j;

	  //---------------------------------- CODE ------------------------------------  
	  
	  // set default data
	  spi 			  = spiBuffers;			// Pointer to the SPI buffers
	  defaultData 	  = init;				// Pointer to the default SPI images
	  SnippetSpiIndex = numberOfRfStates;	// The last SPI buffer is used for partial SPI transmits

	  // Create RfState based data variables
	  error         = new int[numberOfRfStates];				// identify previous error
	  ModifiedImage = new bool[numberOfRfStates];				// SPI snippet modification status
	  ResetImage    = new bool[numberOfRfStates];				// SPI snippet reset status
	  SnippetStatus = new SnippetStatus_t[numberOfRfStates];	// Individual snippet modification status for each state

	  // Initialize RF State based data elements
	 for(i = 0; i < numberOfRfStates; i++)
	  {

	  // Copy default image data to local SPI buffer
	    for(j = 0; j < TOMAHAWK_IMAGE_SIZE_UINT32; j++)
		{
		  (*spi[i])[j] = defaultData->defaultImages[i][j];
		}

		  

		// Initialize the first byte of the SPI buffer with the static header tx type and 
		// address offset infromation
	      // Initialize snippet status variables 
	     for(j = 0; j <  NUM_TOMAHAWK_SNIPPETS; j++)
		 {
	         SnippetStatus[i][j].modified = false;
	         SnippetStatus[i][j].reset    = false;
		 }

	   // Initialize RfState based Data variables
	   ModifiedImage[i] = false;
	   ResetImage[i]	= false;
	   error[i] 		= 0;
	  } 

	  // Initialize non-RF State specific data
	  LastSyncState     = -1;		// Set to a known non-legitimate value

	  // Create and initialize the BW baseband interpolation tables
	  bwDataTbl = new dataPoint*[BW_DATA_SIZE];

	  bwDataTbl[0]  = new dataPoint(0,0);        			// 0    - 4.25 - 4.47 KHz
	  bwDataTbl[1]  = new dataPoint((4.47 * KHZ),0);  		// 
	  bwDataTbl[2]  = new dataPoint((4.48 * KHZ),1);  		// 4.48 - 4.69 - 4.94 KHz
	  bwDataTbl[3]  = new dataPoint((4.94 * KHZ),1);  		// 
	  bwDataTbl[4]  = new dataPoint((4.95 * KHZ),2);  		// 4.95 - 5.18 - 5.45 KHz
	  bwDataTbl[5]  = new dataPoint((5.45 * KHZ),2); 		// 
	  bwDataTbl[6]  = new dataPoint((5.46 * KHZ),3); 		// 5.46 - 5.72 - 6.02 KHz
	  bwDataTbl[7]  = new dataPoint((6.02 * KHZ),3); 		// 
	  bwDataTbl[8]  = new dataPoint((6.03 * KHZ),4);  		// 6.03 - 6.32 - 6.65 KHz
	  bwDataTbl[9]  = new dataPoint((6.65 * KHZ),4);  		// 
	  bwDataTbl[10] = new dataPoint((6.66 * KHZ),5);  		// 6.66 - 6.97 - 7.33 KHz
	  bwDataTbl[11] = new dataPoint((7.33 * KHZ),5);  		// 
	  bwDataTbl[12] = new dataPoint((7.34 * KHZ),6);  		// 7.34 - 7.70 - 8.10 KHz
	  bwDataTbl[13] = new dataPoint((8.10 * KHZ),6); 		// 
	  bwDataTbl[14] = new dataPoint((8.11 * KHZ),7); 		// 8.11 - 8.50 - 8.95 KHz
	  bwDataTbl[15] = new dataPoint((8.95 * KHZ),7); 		// 
	  bwDataTbl[16] = new dataPoint((8.96 * KHZ),8);  		// 8.96 - 9.39 - 9.78 KHz
	  bwDataTbl[17] = new dataPoint((9.78 * KHZ),8);  		// 
	  bwDataTbl[18] = new dataPoint((9.79 * KHZ),9);  		// 9.79 - 10.36 - 10.90 KHz
	  bwDataTbl[19] = new dataPoint((10.90 * KHZ),9);  		// 
	  bwDataTbl[20] = new dataPoint((10.91 * KHZ),10); 		// 10.91 - 11.44 - 12.04 KHz
	  bwDataTbl[21] = new dataPoint((12.04 * KHZ),10); 		// 
	  bwDataTbl[22] = new dataPoint((12.05 * KHZ),11); 		// 12.05 - 12.63 - 13.29 KHz
	  bwDataTbl[23] = new dataPoint((13.29 * KHZ),11); 		// 
	  bwDataTbl[24] = new dataPoint((13.30 * KHZ),12); 		// 13.30 - 13.95 - 14.68 KHz
	  bwDataTbl[25] = new dataPoint((14.68 * KHZ),12); 		// 
	  bwDataTbl[26] = new dataPoint((14.69 * KHZ),13); 		// 14.69 - 15.40 - 16.20 KHz
	  bwDataTbl[27] = new dataPoint((16.20 * KHZ),13); 		// 
	  bwDataTbl[28] = new dataPoint((16.21 * KHZ),14); 		// 16.21 - 17.00 - 17.88 KHz
	  bwDataTbl[29] = new dataPoint((17.88 * KHZ),14); 		// 
	  bwDataTbl[30] = new dataPoint((17.89 * KHZ),15); 		// 17.89 - 18.77 - 19.75 KHz
	  bwDataTbl[31] = new dataPoint((19.75 * KHZ),15); 		// 
	  bwDataTbl[32] = new dataPoint((19.76 * KHZ),16); 		// 19.76 - 20.73 - 21.80 KHz
	  bwDataTbl[33] = new dataPoint((21.80 * KHZ),16); 		// 
	  bwDataTbl[34] = new dataPoint((21.81 * KHZ),17); 		// 21.81 - 22.88 - 24.08 KHz
	  bwDataTbl[35] = new dataPoint((24.08 * KHZ),17); 		// 
	  bwDataTbl[36] = new dataPoint((24.09 * KHZ),18); 		// 24.09 - 25.27 - 26.59 KHz
	  bwDataTbl[37] = new dataPoint((26.59 * KHZ),18); 		// 
	  bwDataTbl[38] = new dataPoint((26.60 * KHZ),19); 		// 26.60 - 27.90 - 29.35 KHz
	  bwDataTbl[39] = new dataPoint((29.35 * KHZ),19); 		// 
	  bwDataTbl[40] = new dataPoint((29.36 * KHZ),20); 		// 29.36 - 30.80 - 32.45 KHz
	  bwDataTbl[41] = new dataPoint((32.45 * KHZ),20); 		// 
	  bwDataTbl[42] = new dataPoint((32.46 * KHZ),21); 		// 32.46 - 34.01 - 35.78 KHz
	  bwDataTbl[43] = new dataPoint((35.78 * KHZ),21); 		// 
	  bwDataTbl[44] = new dataPoint((35.79 * KHZ),22); 		// 35.79 - 37.55 - 39.51 KHz
	  bwDataTbl[45] = new dataPoint((39.51 * KHZ),22); 		// 
	  bwDataTbl[46] = new dataPoint((39.52 * KHZ),23); 		// 39.52 - 41.46 - 43.62 KHz
	  bwDataTbl[47] = new dataPoint((43.62 * KHZ),23); 		// 
	  bwDataTbl[48] = new dataPoint((43.63 * KHZ),24); 		// 43.63 - 45.77 - 48.16 KHz
	  bwDataTbl[49] = new dataPoint((48.16 * KHZ),24); 		// 
	  bwDataTbl[50] = new dataPoint((48.17 * KHZ),25); 		// 48.17 - 50.54 - 53.17 KHz
	  bwDataTbl[51] = new dataPoint((53.17 * KHZ),25); 		// 
	  bwDataTbl[52] = new dataPoint((53.18 * KHZ),26); 		// 53.18 - 55.80 - 58.21 KHz
	  bwDataTbl[53] = new dataPoint((58.21 * KHZ),26); 		// 
	  bwDataTbl[54] = new dataPoint((58.22 * KHZ),27); 		// 58.22 - 61.61 - 64.82 KHz
	  bwDataTbl[55] = new dataPoint((64.82 * KHZ),27); 		// 
	  bwDataTbl[56] = new dataPoint((64.83 * KHZ),28); 		// 64.83 - 68.02 - 71.56 KHz
	  bwDataTbl[57] = new dataPoint((71.56 * KHZ),28); 		// 
	  bwDataTbl[58] = new dataPoint((71.57 * KHZ),29); 		// 71.57 - 75.10 - 79.10 KHz
	  bwDataTbl[59] = new dataPoint((79.10 * KHZ),29); 		// 
	  bwDataTbl[60] = new dataPoint((79.11 * KHZ),30); 		// 79.11 - 82.92 - 87.24 KHz
	  bwDataTbl[61] = new dataPoint((87.24 * KHZ),30); 		// 
	  bwDataTbl[62] = new dataPoint((87.25 * KHZ),31); 		// 87.25 - 91.55 - 100.0 KHz
	  bwDataTbl[63] = new dataPoint((100.0 * KHZ),31); 		// 

	  bwBB = new interpolationData((dataPoint**)bwDataTbl, BW_DATA_SIZE);



	// }}}USR
}
// }}}RME

// {{{RME operation '~tomahawk()'
tomahawk::~tomahawk( void )
{
	// {{{USR
	  // Remove the partial SPI image data structures
	  delete [] ModifiedImage;
	  delete [] ResetImage;
	  delete [] SnippetStatus;

	// Remove error management variables
	  delete [] error;

	  delete [] bwDataTbl;

	  delete bwBB;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setRFState(int32_t)'
int32_t tomahawk::setRFState( int32_t rfState )
{
	// {{{USR
	//----------------------------- LOCAL VARIABLES ------------------------------
	 
	int	i, j; 

	//---------------------------------- CODE ------------------------------------  

	// First determine if we need to send out the whole image, or
	// we can send out a piece(s) of the image that changed

	if ((rfState != LastSyncState) || 		// RF state has changed since last sync
	    (ModifiedImage[rfState] == false))	// Re-sending same RF State image
		{

	    // write the entire local SPI image
	    spi[rfState]->sync();	

		// May have made modification to image prior to sync
		// Loop through the image snippet status record to find modified indications
		for (i = 0; i < NUM_TOMAHAWK_SNIPPETS; i++)

			// Check if snippet of memory has been modified
			if (SnippetStatus[rfState][i].modified == true)

				// Clear the modified status indication
				SnippetStatus[rfState][i].modified = false;
		}
	else
		{
		// Loop through the image snippet status record to find modified indications
		for (i = 0; i < NUM_TOMAHAWK_SNIPPETS; i++)
			{

			// Check if snippet of memory has been modified
			if (SnippetStatus[rfState][i].modified == true)
				{

				// Insert the tomahawk header information in byte 0. (Mode and address offset)
				(*spi[SnippetSpiIndex])[0] = (uint32_t)((TOMAHAWK_SPI_MODE_WRITE<<6) | (((i * TOMAHAWK_SNIPPET_SIZE)/2))); 
		
				// Copy the snippet image from the local SPI buffer to the 
				// snippet buffer for transmission.  Offset the payload 
				// in the snippet buffer to compensate for the tomahawk header
				(*spi[SnippetSpiIndex])[1] = (uint32_t)(*spi[rfState])[i+TOMAHWK_SPI_HEADER_SIZE];

		    	// write the entire local SPI image
	    		spi[SnippetSpiIndex]->sync();	
			
				// Clear the modified status indication
				SnippetStatus[rfState][i].modified = false;

				}
			}
		}

	// Reset status indicators
	ModifiedImage[rfState] = false;
	LastSyncState          = rfState;

	// set the RF state and return the previous Rf state
	return synthesizer::setRFState(rfState);  
	// }}}USR
}
// }}}RME

// {{{RME operation 'setGPO(int16_t,int16_t,int16_t)'
void tomahawk::setGPO( int16_t portNumber, int16_t outputState, int16_t rfState )
{
	// {{{USR
	// Macro that calls the appropriate element update routines:
	//    - setBitField : updates local IC image record 
	//    - LogSnippetMod : Set partial SPI image write status
#define updateGPOAtts(rfState, imagereg, value) { \
	    setBitField(&((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), imagereg, value); \
		LogSnippetMod(rfState, imagereg## _RegToSnippet); \
	    }  
	  //----------------------------- LOCAL VARIABLES ------------------------------

	  //---------------------------------- CODE ------------------------------------  

	  
	  //GPO1 = port 1 pin has 0 (low) or 1 (high) state options
	  //GPO2 = port 2 pin has 0 (low) or 1 (high) state options
	  //GPO3 = port 3 pin has 0 (low) or 1 (high) state options
	  //GPO4 = port 4 pin has 0 (low) or 1 (high) state options
	  //GPO5 = port 5 pin has 0 (low) or 1 (high) state options
	  //GPO6 = port 6 pin has 0 (low) or 1 (high) state options

	  switch(portNumber)
	  {
	  case GPO_1:
	    {
	      // write port 1	     
		  updateGPOAtts(rfState, GPO_1, ((outputState == ENABLE)?ENABLE:DISABLE));
	      break;
	    }
	  case GPO_2:
	    {
	      // write port 2
		  updateGPOAtts(rfState, GPO_2, ((outputState == ENABLE)?ENABLE:DISABLE));
	      break;
	    }
	  case GPO_3:
	    {
	      // write port 3
		  updateGPOAtts(rfState, GPO_3, ((outputState == ENABLE)?ENABLE:DISABLE));
	      break;
	    }
	  case GPO_4:
	    {
	      // write port 4
		  updateGPOAtts(rfState, GPO_4, ((outputState == ENABLE)?ENABLE:DISABLE));
	      break;
	    }
	  case GPO_5:
	    {
	      // write port 5
		  updateGPOAtts(rfState, GPO_5, ((outputState == ENABLE)?ENABLE:DISABLE));
	      break;
	    }
	  case GPO_6:
	    {
	      // write port 6
		  updateGPOAtts(rfState, GPO_6, ((outputState == ENABLE)?ENABLE:DISABLE));
	      break;
	    }
	  default:
	    break;
	  }

	 
	// }}}USR
}
// }}}RME

// {{{RME operation 'setDeviceState(int,int,int)'
int tomahawk::setDeviceState( int setting, int deviceId, int rfState )
{
	// {{{USR
	// Macro that calls the appropriate element update routines:
	//    - setBitField : updates local IC image record 
	//    - LogSnippetMod : Set partial SPI image write status
	//    - setDeviceState : updates RF Sequencer subsystem record
#define updateDeviceAtts(rfState, imagereg, setting, value) { \
	    setBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), imagereg, value); \
		LogSnippetMod(rfState, imagereg## _RegToSnippet); \
	    return discreteDeviceControl::setDeviceState(setting, DISC_##imagereg, rfState); \
	    }

	  //----------------------------- LOCAL VARIABLES ------------------------------

	   int temp;

	  //---------------------------------- CODE ------------------------------------  

	  switch(deviceId)
	  {

	//
	// TRANSMITTER REGISTERS
	//

	  case AUX_DAC:
		{
		   // Auxiliary receiver DAC bits

		   // Verify valid parameter range between 0x00-0xFF
		   temp = checkBounds(0x00, 0xFF, setting, 0x00);	// returns valid value or default if invalid
		 
		   // Update the local IC image, and the subsystem setting record 
		   updateDeviceAtts(rfState, AUX_DAC, setting, temp);

		   break;
		}

	  case WFG_REF:
	    {

		  // Test Mux output selection bits
		  // 
		  // Verify test multiplexer value between 0x00-0x1F
		  temp = checkBounds(0x00, 0x1F, setting, 0x02);	// returns valid value or default if invalid

		  // Update the local IC image, and the subsystem setting record 
		  updateDeviceAtts(rfState, WFG_REF, setting, temp);

	      break;
	    }	


	//
	// RECEIVER REGISTERS
	//

	  case STEP_THRESH:
	    {
	      // Actuating step attenuator threshold value 

		  // Verify valid parameter range between 0x0-0x7 
		  temp = checkBounds(0x0, 0x7, setting, 0x2);	// returns valid value or default if invalid
	 
		  // Update the local IC image, and the subsystem setting record 
		  updateDeviceAtts(rfState, STEP_THRESH, setting, temp);

	      break;
	    }	  

	  case SEQMGR_EN:
	    {
		  // Enable sequence manager to control battery save signal
		  // 0 = Normal operation (DISABLE)
	   	  // 1 = Control rx_bs_sig internal signal  (ENABLE)

		  // Update the local IC image, and the subsystem setting record 
		  updateDeviceAtts(rfState, SEQMGR_EN, setting, ((setting == ENABLE)?ENABLE:DISABLE));

	      break;
	    }

	  case AGCFLAGEN:
	    {
		  // Enable AGC flag to influence the AGC state machine
		  // 0 = Normal operation (DISABLE)
	   	  // 1 = Enable AGC state machine influence (ENABLE)

		  // Update the local IC image, and the subsystem setting record 
		  updateDeviceAtts(rfState, AGCFLAGEN, setting, ((setting == ENABLE)?ENABLE:DISABLE));

	      break;
	    }

	  case FBC_TMR:
	    {
	      // Fast bias charge signal counter timer 

		  // Verify valid parameter range between 0x0-0x3
		  temp = checkBounds(0x0, 0x3, setting, 0x0);	// returns valid value or default if invalid
	 
		  // Update the local IC image, and the subsystem setting record 
		  updateDeviceAtts(rfState, FBC_TMR, setting, temp);
	      break;
	    }	  


	//
	// SYNTHESIZER REGISTERS
	//

	  case MREF_DIV:
	    {
	      // Main synthesizer reference divider
	     // convert to bit setting
	 
		  // Verify valid parameter range between 0x1-0x7
		  temp = checkBounds(0x1, 0x7, setting, 0x1);	// returns valid value or default if invalid

		  // Update the local IC image, and the subsystem setting record 
		  updateDeviceAtts(rfState, MREF_DIV, setting, temp);

	      break;
	    }	  

		  
	  case MACC:
	    {
	      // 

	     // main synthesizer accumulator configuration
		  // Verify valid parameter range between 0x0-0x3
		  temp = checkBounds(0x0, 0x3, setting, 0x0);	// returns valid value or default if invalid

		  // Update the local IC image, and the subsystem setting record 
		  updateDeviceAtts(rfState, MACC, setting, temp);

	      break;
	    }	  

	  case CLK_R:
	    {
	      // Integer divisor for reference side of the clock generator

		  // Verify valid parameter range between 0x00-0xFF
		  temp = checkBounds(0x00, 0xFF, setting, 0x00);	// returns valid value or default if invalid
	 
		  // Update the local IC image, and the subsystem setting record 
		  updateDeviceAtts(rfState, CLK_R, setting, temp);

	      break;
	    }	  


	//
	// CHANNEL REGISTERS
	//
		  
	  case SSI_MODE:
	    {
	      // SSI format Mode
		     switch(setting)
		     {
		       case SSI_MODE_IDEN:
				 temp = 0;
		         break;
		       case SSI_MODE_TETRA:
				 temp = 1;
		         break;
		       case SSI_MODE_CGISS:
		       case SSI_MODE_SAM_50:
		       case SSI_MODE_SAM_100:
				 temp = 2;
		         break;
		       case SSI_MODE_SAM_150:
				 temp = 3;
		         break; 
		       case SSI_MODE_IDEN_CEFM_24:
				 temp = 4;
		         break;
		       case SSI_MODE_IDEN_CEFM_48:
				 temp = 5;
		         break;
		       case SSI_MODE_SAM_50_CEFM:
		       case SSI_MODE_SAM_100_CEFM:
				 temp = 6;
		         break;
		       case SSI_MODE_SAM_150_CEFM: 
		         temp = 7;
		         break;
		       default: 
		         temp = 2;
		         break;
				}

		  // Update the local IC image, and the subsystem setting record 
		  updateDeviceAtts(rfState, SSI_MODE, setting, temp);

	      break;
	    }	  

	  case RF_STEP:
	    {
		  // Enable direct control of the RFSTEPA pin
		  // 0 = disable RFSTEPA pin control (DISABLE)
	   	  // 1 = enable  RFSTEPA pin control (ENABLE)

		  // Update the local IC image, and the subsystem setting record 
		  updateDeviceAtts(rfState, RF_STEP, setting, ((setting == ENABLE)?ENABLE:DISABLE));

	      break;
	    }

	  case FAST_AGC:
	    {
		  // Enable fast AGC pull down mode control
		  // 0 = disable fast AGC pull down mode (DISABLE)
	   	  // 1 = enable fast AGC pull down mode (ENABLE)

		  // Update the local IC image, and the subsystem setting record 
		  updateDeviceAtts(rfState, FAST_AGC, setting, ((setting == ENABLE)?ENABLE:DISABLE));

	      break;
	    }
	    
	  case AGC_DAC_VREF:
		    {
		     // AGC DAC adjustable reference offset voltage value (mV resolution)
		     switch(setting)
		     {
		       case ((int)(0 * MV)):
				 temp = 0;
		         break;
		       case ((int)(-25 * MV)):
				 temp = 1;
		         break;
		       case ((int)(-50 * MV)):
				 temp = 2;
		         break;
		       case ((int)(-75 * MV)):
				 temp = 3;
		         break; 
				case ((int)(-100 * MV)):
				 temp = 4;
		         break; 
		       case ((int)(-125 * MV)):
				 temp = 5;
		         break; 
		       case ((int)(-150 * MV)):
				 temp = 6;
		         break; 
		       default: 
		         temp = 0;
		         break;
				}

			  // Update the local IC image, and the subsystem setting record 
			  updateDeviceAtts(rfState, AGC_DAC_VREF, setting, temp);

		      break;
		    }	  

		  case AGC_DAC_MODE:
		    {
			  // AGC DAC configuration
			  // 0 = Initial half voltage, and then increase (AGC_DAC_MODE_INCREASE)
		   	  // 1 = Initial 2.0V, and then decrease 		 (AGC_DAC_MODE_DECREASE)

			  // Update the local IC image, and the subsystem setting record 
			  updateDeviceAtts(rfState, AGC_DAC_MODE, setting, ((setting == AGC_DAC_MODE_DECREASE)?AGC_DAC_MODE_DECREASE:AGC_DAC_MODE_INCREASE));

		      break;
		    }
	  

	  case ADAPTEN:
	    {
		  // Enable the DC offset correction loop
		  // 0 = disable the DC offset correction loop (DISABLE)
	   	  // 1 = enable the DC offset correction loop (ENABLE)

		  // Update the local IC image, and the subsystem setting record 
		  updateDeviceAtts(rfState, ADAPTEN, setting, ((setting == ENABLE)?ENABLE:DISABLE));

	      break;
	    }

	  case RX_BS:
	    {
		  // Receiver battery save mode
		  // 0 = Disable receiver battery save mode (DISABLE)
	   	  // 1 = Enable receiver battery save mode (ENABLE)

		  // Update the local IC image, and the subsystem setting record 
		  updateDeviceAtts(rfState, RX_BS, setting, ((setting == DISABLE)?DISABLE:ENABLE));

	      break;
	    }

	  case SYN_ADAPTEN:
	    {
		  // Main synthesizer adapt charge pump timer
		  // 0 = Disable main synthesizer adapt charge pump timer (DISABLE)
	   	  // 1 = Enable main synthesizer adapt charge pump timer (ENABLE)

		  // Update the local IC image, and the subsystem setting record 
		  updateDeviceAtts(rfState, SYN_ADAPTEN, setting, ((setting == ENABLE)?ENABLE:DISABLE));

	      break;
	    }

	  case BSAVE_SYN_ALL:
	    {
		  // Battery save mode for all synthesizers
		  // 0 = Disable Battery save mode for all synthesizers (DISABLE)
	   	  // 1 = Enable Battery save mode for all synthesizers (ENABLE)

		  // Update the local IC image, and the subsystem setting record 
		  updateDeviceAtts(rfState, BSAVE_SYN_ALL, setting, ((setting == DISABLE)?DISABLE:ENABLE));

	      break;
	    }

	  case BSAVE_MAIN_SYN:
	    {
		  // Battery save mode for main synthesizer
		  // 0 = Disable Battery save mode for main synthesizer (DISABLE)
	   	  // 1 = Enable Battery save mode for main synthesizer (ENABLE)

		  // Update the local IC image, and the subsystem setting record 
		  updateDeviceAtts(rfState, BSAVE_MAIN_SYN, setting, ((setting == DISABLE)?DISABLE:ENABLE));

	      break;
	    }

	  case BSAVE_TX:
	    {
		  // Battery save mode for internal clocks and Tomahawk TX
		  // 0 = Disable Battery save mode for Tomahawk TX (DISABLE)
	   	  // 1 = Enable Battery save mode for Tomahawk TX (ENABLE)

		  // Update the local IC image, and the subsystem setting record 
		  updateDeviceAtts(rfState, BSAVE_TX, setting, ((setting == DISABLE)?DISABLE:ENABLE));

	      break;
	    }
	    
	  case BSAVE_EF:
		    {
			  // envelope following system is placed in battery save for Tomahawk TX
			  // 0 = Disable Battery save mode for Tomahawk TX modulation(DISABLE)
		   	  // 1 = Enable Battery save mode for Tomahawk TX modulation (ENABLE)

			  // Update the local IC image, and the subsystem setting record 
			  updateDeviceAtts(rfState, BSAVE_EF, setting, ((setting == DISABLE)?DISABLE:ENABLE));

		      break;
		    }


	  case HP_SEL:
		    {
			  //If programmed high low then the internal envelope following generator passes the I 
		      //channel signal to the next stage for CGISS use. If programmed high
		      //low then normal envelope following operation is performed.
			  // 0 = (DISABLE)
		   	  // 1 =  (ENABLE)

			  // Update the local IC image, and the subsystem setting record 
			  updateDeviceAtts(rfState, HP_SEL, setting, ((setting == DISABLE)?DISABLE:ENABLE));

		      break;
		    }
	  

	  case BSAVE_ESCORT:
	    {
		  // Battery save mode for Escort
		  // 0 = Disable Battery save mode for Escort (DISABLE)
	   	  // 1 = Enable Battery save mode for Escort (ENABLE)

		  // Update the local IC image, and the subsystem setting record 
		  updateDeviceAtts(rfState, BSAVE_ESCORT, setting, ((setting == DISABLE)?DISABLE:ENABLE));

	      break;
	    }

	  case ES_SEL2:
	    {
		  // Escort ??? selector
		  // 0 = REFIN to near unity divide (NUD) (ES_SEL2_REFIN)
	   	  // 1 = VCOIN to near unity divide (NUD) (ES_SEL2_VCOIN)

		  // Update the local IC image, and the subsystem setting record 
		  updateDeviceAtts(rfState, ES_SEL2, setting, ((setting == ES_SEL2_REFIN)?DISABLE:ENABLE));

	      break;
	    }

	  case NUD:
	    {
	      // Integer divisor for reference side of the clock generator

		  // Verify valid parameter range between 0x00-0x3F
		  temp = checkBounds(0x00, 0x3F, setting, 0x00);	// returns valid value or default if invalid
	 
		  // Update the local IC image, and the subsystem setting record 
		  updateDeviceAtts(rfState, NUD, setting, temp);

	      break;
	    }	  

	  case BSAVE_TXR:
	    {
		  // Battery save for filter calibration system
		  // 0 = Disable battery save for filter calibration system (DISABLE)
	   	  // 1 = Enable Disable battery save for filter calibration system (ENABLE)

		  // Update the local IC image, and the subsystem setting record 
		  updateDeviceAtts(rfState, BSAVE_TXR, setting, ((setting == DISABLE)?DISABLE:ENABLE));

	      break;
	    }

	  case EF_DC_UPDATE:
	    {
		  // DCOC correction
		  // 0 = Disable DCOC correction (DISABLE)
	   	  // 1 = Enable DCOC correction (ENABLE)

		  // Update the local IC image, and the subsystem setting record 
		  updateDeviceAtts(rfState, EF_DC_UPDATE, setting, ((setting == ENABLE)?ENABLE:DISABLE));

	      break;
	    }

	  case ATTEN_I:
	    {
	      // Attenuation factor for the TX D/A I channel

		  // Verify valid parameter range between 0x00-0xFF
		  temp = checkBounds(0x00, 0xFF, setting, 0x00);	// returns valid value or default if invalid
	 
		  // Update the local IC image, and the subsystem setting record 
		  updateDeviceAtts(rfState, ATTEN_I, setting, temp);

	      break;
	    }	  

	  case ATTEN_Q:
	    {
	      // Attenuation factor for the TX D/A Q channel

		  // Verify valid parameter range between 0x00-0xFF
		  temp = checkBounds(0x00, 0xFF, setting, 0x00);	// returns valid value or default if invalid
	 
		  // Update the local IC image, and the subsystem setting record 
		  updateDeviceAtts(rfState, ATTEN_Q, setting, temp);

	      break;
	    }	  
	 default:
		{
	//
	// ERROR CONDITION - TBD
	//
		  return( -1 );
	      break;
		}

	  }  // END - switch


	// }}}USR
}
// }}}RME

// {{{RME operation 'setGain(int,int,int)'
int tomahawk::setGain( int gainNumber, int gain, int rfState )
{
	// {{{USR

	// Macro that calls the appropriate element update routines:
	//    - setBitField : updates local IC image record 
	//    - LogSnippetMod : Set partial SPI image write status
	//    - setGain : updates RF Sequencer subsystem record
#define updateGainAtts(rfState, imagereg, gain, value) { \
	    setBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), imagereg, value); \
		LogSnippetMod(rfState, imagereg## _RegToSnippet); \
	    return gainControl::setGain(GAIN_##imagereg, gain, rfState); \
		}

	   //----------------------------- LOCAL VARIABLES ------------------------------

	   int temp;

	  //---------------------------------- CODE ------------------------------------  

	  switch(gainNumber)
	  {


	//
	// CHANNEL REGISTERS
	//

	  // AGC gain steps of the IF amp
	  case AMP_AGC:
	    {


	      // determine attribute based on gain value (dB resolution)
		  switch(gain)
		  {
			case ((int)(3 * DB)):
				temp = 0;
				break;
			case ((int)(5 * DB)):
				temp = 1;
				break;
			case ((int)(7 * DB)):
				temp = 2;
				break;
			case ((int)(9 * DB)):
				temp = 3;
				break;
			case ((int)(11 * DB)):
				temp = 4;
				break;
			case ((int)(13 * DB)):
				temp = 5;
				break;
			case ((int)(15 * DB)):
				temp = 6;
				break;
			case ((int)(17 * DB)):
				temp = 7;
				break;
			default:
				temp = 0;
				break;
		  }

	 	  // Update the local IC image, and the subsystem setting record 
		  updateGainAtts(rfState, AMP_AGC, gain, temp)
		  
	      break;
		   
	    }


	  // Gain steps of output buffer amp
	  case BUFGAIN:
	    {
	      // determine attribute based on gain value (dB resolution)
		  switch(gain)
		  {
			case ((int)(0 * DB)):
				temp = 0;
				break;
			case ((int)(3 * DB)):
				temp = 1;
				break;
			case ((int)(6 * DB)):
				temp = 2;
				break;
			case ((int)(9 * DB)):
				temp = 3;
				break;
			case ((int)(12 * DB)):
				temp = 4;
				break;
			default:
				temp = 0;
				break;
		  }

	 	  // Update the local IC image, and the subsystem setting record 
		  updateGainAtts(rfState, BUFGAIN, gain, temp)
		  
	      break;
		   
	    }

	  // Gain steps for X2 buffer
	  case STATT_IQ:
	    {
	      // determine attribute based on gain value  (dB resolution)
		  switch(gain)
		  {
			case ((int)(6 * DB)):
				temp = 0;
				break;
			case ((int)(2 * DB)):
				temp = 1;
				break;
			case ((int)(-2 * DB)):
				temp = 2;
				break;
			case ((int)(-6 * DB)):
				temp = 3;
				break;
			default:
				temp = 0;
				break;
		  }

	 	  // Update the local IC image, and the subsystem setting record 
		  updateGainAtts(rfState, STATT_IQ, gain, temp)
		  
	      break;
		   
	    }

	  default:
		{
	//
	// ERROR CONDITION - TBD
	//
		  return( -1 );
	      break;
		}

	  }


	// }}}USR
}
// }}}RME

// {{{RME operation 'setBBPFrequency(int,int)'
int tomahawk::setBBPFrequency( int frequency, int rfState )
{
	// {{{USR

	// Macro that calls the appropriate element update routines:
	//    - setBitField : updates local IC image record 
	//    - LogSnippetMod : Set partial SPI image write status
	//    - setDeviceState : updates RF Sequencer subsystem record
#define updateBBPAtts(rfState, imagereg, setting, value) { \
	        setBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), imagereg, value); \
			LogSnippetMod(rfState, imagereg## _RegToSnippet); \
	    	return bbpControl::setBBPFrequency(setting, rfState); \
	    }

	  //----------------------------- LOCAL VARIABLES ------------------------------


	  //---------------------------------- CODE ------------------------------------  
			
		// Determine bit value of frequency and then modify BW register in the image  	
	  	updateBBPAtts(rfState, BW, frequency, (bwBB->interpolate(frequency)));

	// }}}USR
}
// }}}RME

// {{{RME operation 'setSynthFrequency(int32_t,int16_t,int32_t,int32_t)'
int32_t tomahawk::setSynthFrequency( int32_t freq, int16_t rfState, int32_t res, int32_t fref )
{
	// {{{USR
	  error[rfState] = fref;
	  setFreqParams(freq, fref, res, rfState);
	  return synthesizer::setSynthFrequency(freq, rfState, 0, 0);
	// }}}USR
}
// }}}RME

// {{{RME operation 'setFreqParams(int32_t,int32_t,int32_t,int16_t)'
void tomahawk::setFreqParams( int32_t synthFrequency, int32_t refFrequency, int32_t resolution, int16_t rfState )
{
	// {{{USR
	// Macro that calls the appropriate element update routines:
	//    - setBitField : updates local IC image record 
	//    - LogSnippetMod : Set partial SPI image write status
#define updateFreqAtts(rfState, imagereg, value) { \
	    setBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), imagereg, value); \
		LogSnippetMod(rfState, imagereg## _RegToSnippet); \
	    }  

	  //----------------------------- LOCAL VARIABLES ------------------------------

	  int32_t	 refDivisor;
	  int32_t	 refFreqFrequency;
	  int32_t	 divInteger;
	  int32_t	 divFractional;

	  //---------------------------------- CODE ------------------------------------  


	    // =========================================================================
		//                       TOMAHAWK MAIN SYNTHESIZER
		// =========================================================================
		//
		//	Tomahawk Main frequency formula:
		//  	synth freq = clock generator divider * (oscillator freq/reference divisor)
		//	
		//  Solve for the synthesizer generator divider:
		//		synth generator divider = (synth freq * reference divisor)/oscillator freq)
		//
		//	Solve for synthesizer divider integer portion: 
		//		Integer(synth generator divider) - accumulator mode value = Freq_Integer
		//
		//	Solve for clock divider fractional portion: 
		//		Modulus(synth generator divider) * (2**24) = Freq_Fractional

		// ===============================================================
		// NOTE:
		//   Verify that the frequency and reference frequency parameters
		//   are entered in MHZ granularity.
		// ===============================================================

		// Get the current reference divider value from the image
	    refDivisor = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), MREF_DIV );

		// Check if divisor = 0, set to 1 to avoid divide-by-0 error
		if (refDivisor == 0)
			refDivisor = 1;

		// Determine the integer portion of the divisor
		refFreqFrequency = synthFrequency * refDivisor;
		divInteger		 = refFreqFrequency / refFrequency;

		// Determine the fractional portion of the divisor
		divFractional = refFreqFrequency - (divInteger * refFrequency);

		// Adjust integer portion based on the accumulator (MACC) setting
		if ((getBitField(&((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), MACC)) > 0x01)
			divInteger = divInteger - 3;

		// Determine the fractional portion of the divisor
		divFractional = (int32_t)(((float)(divFractional)/(float)(refFrequency))*0x1000000);

		// Modify the image with the new attributes
		 updateFreqAtts(rfState, MAINNUM_16_23,((divFractional>>16) & 0x000000FF));
	     updateFreqAtts(rfState, MAINNUM_0_15, (divFractional & 0x0000FFFF));
	     updateFreqAtts(rfState, MAINND, divInteger);




	/* ### REMOVE CLOCK SYNTHESIZER PROGRAMMING

		NOTE:  The Clock synthesizer is not programmed separately during normal
			   operation.  The registers for this synthesizer are set when the full
			   default SPI images are downloaded to the IC, currently reset/start up,
			   and rx mode.  Should there be a need to program this synthesizer during
			   operation the synthesizer base class will need to be modified.  It currently 
			   only supports the programming of one synthesizer device per rf state.

			   Since the device does not need to be programmed, the following code has 
			   been commented out.

		// =========================================================================
		//                       TOMAHAWK CLOCK SYNTHESIZER
		// =========================================================================
		//
		//	Tomahawk Clock frequency formula:
		//  	clock freq = clock generator divider * (oscillator freq/reference divisor)
		//	
		//  Solve for the clock generator divider:
		//		clock generator divider = (clock freq * reference divisor)/oscillator freq)
		//
		//	Solve for clock divider integer portion: 
		//		Integer(clock generator divider) - accumulator mode value = Freq_Integer
		//
		//	Solve for clock divider fractional portion: 
		//		Modulus(clock generator divider) * (2**24) = Freq_Fractional
		//

		// ===============================================================
		// NOTE:
		//   Verify that the frequency and reference frequency parameters
		//   are entered in KHZ granularity.
		// ===============================================================
	  
		// Get the current reference divider value from the image
	    refDivisor = getBitField(&((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), MREF_DIV);

		// Check if divisor = 0, set to 1 to avoid error
		if (refDivisor == 0)
			refDivisor = 1;

		// Determine the integer portion of the divisor
		refFreqFrequency = synthFrequency / refDivisor;
		divInteger		 = refFreqFrequency / refFrequency;

		// Determine the fractional portion of the divisor
		divFractional = refFreqFrequency - (divInteger * refFrequency);

		// Adjust integer portion based on the accumulator (CLK_ACC) setting
		if ((getBitField(&((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), MACC)) > 0x01)
			divInteger = divInteger - 3;

		// Determine the fractional portion of the divisor
		divFractional = (int)(((float)(divFractional)/(float)(refFrequency))*0x1000000);

		// Modify the image with the new attributes
	     setBitField(((uint32_t *)spi[rfState]), CLK_NUM_16_23,((divFractional>>16) & 0x000000FF));
	     setBitField(((uint32_t *)spi[rfState]), CLK_NUM_0_15, (divFractional & 0x000000FF));
	     setBitField(((uint32_t *)spi[rfState]), CLK_N,  divInteger);


	 ### END OF REMOVE CLOCK SYNTHESIZER PROGRAMMING

	*/


	// }}}USR
}
// }}}RME

// {{{RME operation 'LogSnippetMod(int,int)'
void tomahawk::LogSnippetMod( int RfState, int SnippetID )
{
	// {{{USR
	  //----------------------------- LOCAL VARIABLES ------------------------------

	   int temp;

	  //---------------------------------- CODE ------------------------------------  

		// Set status indicating specified snippet is modified for syncheonization and 
		// will require an update during a reset
		SnippetStatus[RfState][SnippetID].modified = true;
		SnippetStatus[RfState][SnippetID].reset    = true;

		// Global image status indicating update and reset 
		ModifiedImage[RfState] = true;
		ResetImage[RfState]    = true;

	// }}}USR
}
// }}}RME

// {{{RME operation 'ResetRFState(int)'
void tomahawk::ResetRFState( int rfState )
{
	// {{{USR
	//----------------------------- LOCAL VARIABLES ------------------------------
	  
	int		i, j;
	unsigned char 	*tempSpi;

	//---------------------------------- CODE ------------------------------------  
	// Determine if image needs to be reset
	if (ResetImage[rfState] == true)
		{
		// Loop through the image snippet status record to find modified indications
		for (i = 0; i < NUM_TOMAHAWK_SNIPPETS; i++)
			{
			// Check if snippet of memory has been modified
			if (SnippetStatus[rfState][i].reset == true)
				{
				// Cast the SPI buffer pointer to a byte array
				tempSpi = (unsigned char *)&((*spi[rfState])[0]);

				// Copy the snippet image from the local SPI buffer to the 
				// snippet buffer for transmission
				for (j = 0; j < TOMAHAWK_SNIPPET_SIZE; j++)		

					tempSpi[(i*TOMAHAWK_SNIPPET_SIZE)+TOMAHWK_SPI_HEADER_SIZE+j] =
						defaultData->defaultImages[rfState][(i*TOMAHAWK_SNIPPET_SIZE)+j];
			
				// Clear the modified status indication
				SnippetStatus[rfState][i].modified = false;
				SnippetStatus[rfState][i].reset    = false;

				}
			}

		// Reset Modified status indiciation
		ModifiedImage[rfState] = false;
		ResetImage[rfState]    = false;
		}
	// }}}USR
}
// }}}RME

// {{{RME operation 'commitGPO(Integer,Integer)'
void tomahawk::commitGPO( Integer portNumber, Integer rfState )
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'writeImage(int,int,int)'
void tomahawk::writeImage( int rfState, int deviceId, int setting )
{
	// {{{USR
	// these are the 3 functions that may allow user to set the value of the required
	// register. the user may run thru these 3 function one by one to find the 
	// required register and update the data to the tomahawk image.
	setDeviceState(setting, deviceId, rfState);
	setGPO(deviceId, setting, rfState);
	setGain(deviceId, setting, rfState);


	//write the image to the register of the IC component.
	setRFState(rfState);
	// }}}USR
}
// }}}RME

// {{{RME operation 'wrRegister(uint16_t,uint16_t,int)'
void tomahawk::wrRegister( uint16_t addr, uint16_t data, int rfState )
{
	// {{{USR
	uint32_t wrData = 0;
	uint32_t temp_image;
	uint16_t cal_addr = 1;
	uint16_t value;


	// Because the data store in 32 bit so have to use 
	//the shift to determine which is the correct row (16bits).
	// the (+ 1) is because of the first buffer line is not used.
	cal_addr = (addr >>1);
	cal_addr = cal_addr + 1;



	// To know whether the address is the odd or even by using the last bit.
	value = addr & 0x0001;

	 

	//overwrite tomahawk image based on address given
	if( value == 0)

	{
	// if the addr is even, keep the right significant 16 bits data.
	temp_image = (spi[rfState]->operator[](cal_addr)) & 0x0000FFFF;

	// append the data into the left significant 16 bits of temp_image
	wrData = data; // copy uint16_t data to uint32_t wrData before shifting. 
	wrData = (wrData << 16) + temp_image; 

	}

	else

	{
	// if the addr is odd, keep the left significant 16 bits data.
	temp_image = (spi[rfState]->operator[](cal_addr)) & 0xFFFF0000;

	// append the data into the left significant 16 bits of temp_image
	wrData = temp_image + data;

	}

	//copy the temp_image back to the desired spi
	spi[rfState]->operator[](cal_addr) = wrData;



	//manually activate the snippet flag
	ModifiedImage[rfState] = true;
	SnippetStatus[rfState][cal_addr-1].modified = true;


	//write the data to the tomahawk.
	setRFState(rfState);
	// }}}USR
}
// }}}RME

// {{{RME operation 'ResetCompImage(int)'
void tomahawk::ResetCompImage( int rfState )
{
	// {{{USR
	int j;

	// Copy default image data to local SPI buffer
	    for(j = 0; j < TOMAHAWK_IMAGE_SIZE_UINT32; j++)
		{
		  (*spi[rfState])[j] = defaultData->defaultImages[rfState][j];
		}

	setRFState(rfState);
	// }}}USR
}
// }}}RME

// {{{RME operation 'readImage(int,int)'
int32_t tomahawk::readImage( int deviceId, int rfState )
{
	// {{{USR
	//------------- LOCAL VARIABLES ------------------------------------------------------------------
	int32_t Reg_Value = 0;

	//------------------------------------------------------------------------------------------------

	//Reading the data from the tomahawk image by the register location.
	switch(deviceId)
	  {

	  case ABR_SEL:
	    {
		 Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), ABR_SEL );
		break;
		}	

	  case ABF_SEL:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), ABF_SEL);
		break;
		}	


	  case SDTX_POL:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), SDTX_POL);
		break;
		}

	  case SC_SEL:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), SC_SEL);
		break;
		}

	  case ABW:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), ABW);
		break;
		}
	   
	  case I_DCOFS:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), I_DCOFS);
		break;
		}
	  
	  
	  case OVSX:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), OVSX);
		break;
		}
	   
	  case TXC_REF:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), TXC_REF);
		break;
		}

	  
	  case TXF_REF:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), TXF_REF);
		break;
		}
	   
	  case OVS_REF:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), OVS_REF);
		break;
		}

	  case WFG_REF:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), WFG_REF);
		break;
		}

	  case DCOC_SIGN_EF:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), DCOC_SIGN_EF);
		break;
		}
	   
	  case TX_DCOC_SIGN:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), TX_DCOC_SIGN);
		break;
		}

	  case AOC_HIB:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), AOC_HIB);
		break;
		}

	  case X1DR0:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), X1DR0);
		break;
		}
	   
	  case X1DR1:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), X1DR1);
		break;
		}
	  
	  case X1DR2:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), X1DR2);
		break;
		}

	  case X1DR3:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), X1DR3);
		break;
		}
	   
	  case X1DR4:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), X1DR4);
		break;
		}


	  case X1DR5:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), X1DR5);
		break;
		}

	  case DC_CORRECT:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), DC_CORRECT);
		break;
		}
	   
	  case TRIST_PAB:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), TRIST_PAB);
		break;
		}
	  
	  case BSAVE_EF:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), BSAVE_EF);
		break;
		}

	  case BSAVE_Q:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), BSAVE_Q);
		break;
		}
	   
	  case BSAVE_I:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), BSAVE_I);
		break;
		}

	  case BSAVE_WG:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), BSAVE_WG);
		break;
		}

	  case BSAVE_PAB:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), BSAVE_PAB);
		break;
		}
	   
	  case X2DR0:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), X2DR0);
		break;
		}

	  case X2DR1:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), X2DR1);
		break;
		}

	  case X2DR2:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), X2DR2);
		break;
		}
	   
	  case X2DR3:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), X2DR3);
		break;
		}

	  case X2DR4:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), X2DR4);
		break;
		}

	  case X2DR5:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), X2DR5);
		break;
		}
	   
	  case X3DR0:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), X3DR0);
		break;
		}
	  
	  case X3DR1:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), X3DR1);
		break;
		}

	  case X3DR2:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), X3DR2);
		break;
		}
	   
	  case X3DR3:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), X3DR3);
		break;
		}


	  case X3DR4:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), X3DR4);
		break;
		}

	  case X3DR5:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), X3DR5);
		break;
		}
	   
	  case X4DR0:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), X4DR0);
		break;
		}
	  
	  case X4DR1:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), X4DR1);
		break;
		}

	  case X4DR2:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), X4DR2);
		break;
		}
	   
	  case X4DR3:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), X4DR3);
		break;
		}

	  case X4DR4:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), X4DR4);
		break;
		}

	  case X4DR5:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), X4DR5);
		break;
		}
	   
	  case DCOC_REF:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), DCOC_REF);
		break;
		}

	  case TM_BUFF:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), TM_BUFF);
		break;
		}

	  case EF_DC_CORRECT:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), EF_DC_CORRECT);
		break;
		}
	   
	  case EF_DLY:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), EF_DLY);
		break;
		}

	  case TEST_MUX:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), TEST_MUX);
		break;
		}

	  case TR_LOWER:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), TR_LOWER);
		break;
		}
	   
	  case TR_UPPER:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), TR_UPPER);
		break;
		}
	  
	  case DAC_TEST:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), DAC_TEST);
		break;
		}

	  case DAC_TEST_EN:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), DAC_TEST_EN);
		break;
		}
	   
	  case FIRCLK_SB:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), FIRCLK_SB);
		break;
		}


	  case LAST_INT:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), LAST_INT);
		break;
		}

	  case IDC_DAC:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), IDC_DAC);
		break;
		}
	   
	  case DC_DAC_GM:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), DC_DAC_GM);
		break;
		}
	  
	  case QDC_DAC:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), QDC_DAC);
		break;
		}

	  case DCOCL_HOLD:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), DCOCL_HOLD);
		break;
		}
	   
	  case DCOC_LPF_BW:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), DCOC_LPF_BW);
		break;
		}

	  case KDLPT:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), KDLPT);
		break;
		}

	  case THP2:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), THP2);
		break;
		}
	   
	  case THP1:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), THP1);
		break;
		}

	  case FHP3:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), FHP3);
		break;
		}

	  case ADAC_BIAS:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), ADAC_BIAS);
		break;
		}
	   
	  case SOS_MUX:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), SOS_MUX);
		break;
		}

	  case SM_AGC_EN:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), SM_AGC_EN);
		break;
		}

	  case FHP2:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), FHP2);
		break;
		}
	   
	  case FHP1:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), FHP1);
		break;
		}
	  
	  case SD_MODE:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), SD_MODE);
		break;
		}

	  case PMA_BIAS:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), PMA_BIAS);
		break;
		}
	   
	  case SSI_TS:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), SSI_TS);
		break;
		}


	  case AB_SEL:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), AB_SEL);
		break;
		}

	  case DBW:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), DBW);
		break;
		}
	   
	  case PMA_BP:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), PMA_BP);
		break;
		}
	  
	  case TRK_LOW:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), TRK_LOW);
		break;
		}

	  case FREE_RUN:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), FREE_RUN);
		break;
		}
	   
	  case TRK_HIGH:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), TRK_HIGH);
		break;
		}

	  case RXSC_SEL:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), RXSC_SEL);
		break;
		}

	  case AGC_CLK:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), AGC_CLK);
		break;
		}
	   
	  case RXDIG_DIV:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), RXDIG_DIV);
		break;
		}

	  case DEC_DIV:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), DEC_DIV);
		break;
		}

	  case BS_DLY_TMR:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), BS_DLY_TMR);
		break;
		}
	   
	  case ADPT_DLY_TMR:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), ADPT_DLY_TMR);
		break;
		}

	  case FBC_TMR:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), FBC_TMR);
		break;
		}

	  case AGCFLAGEN:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), AGCFLAGEN);
		break;
		}
	   
	  case SEQMGR_EN:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), SEQMGR_EN);
		break;
		}
	  
	  case DC_CALEN:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), DC_CALEN);
		break;
		}

	  case AGC_MAX_A:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), AGC_MAX_A);
		break;
		}
	   
	  case FE_OFF_A:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), FE_OFF_A);
		break;
		}


	  case STEP_SLOT:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), STEP_SLOT);
		break;
		}

	  case AGC_DAC_VREF:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), AGC_DAC_VREF);
		break;
		}
	   
	  case STEP_THRESH:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), STEP_THRESH);
		break;
		}
	  
	  case STEP_OFFSET:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), STEP_OFFSET);
		break;
		}

	  case BW:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), BW);
		break;
		}
	   
	  case BB2P_Q:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), BB2P_Q);
		break;
		}

	  case AGC_STEP_CMP:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), AGC_STEP_CMP);
		break;
		}

	  case RAGC_PHASE:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), RAGC_PHASE);
		break;
		}
	   
	  case RAGC_DIV:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), RAGC_DIV);
		break;
		}

	  case FAGC_STEPS:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), FAGC_STEPS);
		break;
		}

	  case FAGC_DIV:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), FAGC_DIV);
		break;
		}
	   
	  case NAGC_DIV:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), NAGC_DIV);
		break;
		}

	  case AGCLVL:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), AGCLVL);
		break;
		}

	  case CIC_OFFSET:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), CIC_OFFSET);
		break;
		}
	   
	  case AUTO_AGC:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), AUTO_AGC);
		break;
		}
	  
	  case RF_STEPEN:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), RF_STEPEN);
		break;
		}

	  case AGC_DAC_MODE:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), AGC_DAC_MODE);
		break;
		}
	   
	  case AUX_DAC:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), AUX_DAC);
		break;
		}


	  case AGCHIGH:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), AGCHIGH);
		break;
		}

	  case MCPTEST:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), MCPTEST);
		break;
		}
	   
	  case MCP_GAIN:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), MCP_GAIN);
		break;
		}
	  
	  case MCRS_TMR:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), MCRS_TMR);
		break;
		}

	  case MADP_TMR:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), MADP_TMR);
		break;
		}
	   
	  case MREF_DIV:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), MREF_DIV);
		break;
		}

	  case CLK_NUM:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), CLK_NUM);
		break;
		}

	  case MACC:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), MACC);
		break;
		}
	   
	  case MND_8BIT_SEL:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), MND_8BIT_SEL);
		break;
		}

	  case MLBPRCS_SEL:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), MLBPRCS_SEL);
		break;
		}

	  case CLK_ACC:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), CLK_ACC);
		break;
		}
	   
	  case ROT:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), ROT);
		break;
		}

	  case CLK_N:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), CLK_N);
		break;
		}

	  case CLK_R:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), CLK_R);
		break;
		}
	   
	  case CLKCP_TEST:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), CLKCP_TEST);
		break;
		}
	  
	  case BSAVE_CLKS_SYN:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), BSAVE_CLKS_SYN);
		break;
		}

	  case CLK1_DIV:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), CLK1_DIV);
		break;
		}
	   
	  case CLK2_DIV:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), CLK2_DIV);
		break;
		}

	  case TCLK_OUT_EN:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), TCLK_OUT_EN);
		break;
		}



	  case CLK1_OUT_EN:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), CLK1_OUT_EN);
		break;
		}


	  case CLK2_OUT_EN:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), CLK2_OUT_EN);
		break;
		}


	  case TCLK_DIV_SEL:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), TCLK_DIV_SEL);
		break;
		}


	  case TCLK_DIV:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), TCLK_DIV);
		break;
		}


	  case COB1_SEL:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), COB1_SEL);
		break;
		}

	  case COB2_SEL:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), COB2_SEL);
		break;
		}



	  case BSAVE_CRS_DAC:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), BSAVE_CRS_DAC);
		break;
		}


	  case ES_CP_BIAS_EN:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), ES_CP_BIAS_EN);
		break;
		}


	  case ES_VCO_STEER2:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), ES_VCO_STEER2);
		break;
		}


	  case ES_VCO_STEER1:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), ES_VCO_STEER1);
		break;
		}


	  case ES_SEL3:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), ES_SEL3);
		break;
		}

	  case ES_NUD_MUL_BYP:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), ES_NUD_MUL_BYP);
		break;
		}



	  case ES_NUD_BYP:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), ES_NUD_BYP);
		break;
		}


	  case ES_D16_BYP:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), ES_D16_BYP);
		break;
		}


	  case ES_CP_EN:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), ES_CP_EN);
		break;
		}


	  case ES_SEL1:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), ES_SEL1);
		break;
		}


	  case ES_DIV_TEST:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), ES_DIV_TEST);
		break;
		}

	  case ES_BIAS_EN:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), ES_BIAS_EN);
		break;
		}



	  case ES_STEER_EN:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), ES_STEER_EN);
		break;
		}


	  case ES_NUD_EN:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), ES_NUD_EN);
		break;
		}


	  case CLK2_IN_SEL:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), CLK2_IN_SEL);
		break;
		}


	  case CLK1_IN_SEL:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), CLK1_IN_SEL);
		break;
		}

	 case AGC_DAC:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), AGC_DAC);
		break;
		}



	  case RX_BB_BS:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), RX_BB_BS);
		break;
		}


	  case FE_EN:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), FE_EN);
		break;
		}


	  case SD_BS:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), SD_BS);
		break;
		}


	  case AGC_BS:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), AGC_BS);
		break;
		}


	  case RX_DIG_BS:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), RX_DIG_BS);
		break;
		}

	  case ADAPT:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), ADAPT);
		break;
		}



	  case AUXDAC_BS:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), AUXDAC_BS);
		break;
		}


	  case BUFGAIN:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), BUFGAIN);
		break;
		}


	  case AMP_AGC:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), AMP_AGC);
		break;
		}


	  case PMA_AGC:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), PMA_AGC);
		break;
		}


	  case RX_BS:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), RX_BS);
		break;
		}

	  case ADAPTEN:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), ADAPTEN);
		break;
		}



	  case AGC_PRELOAD:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), AGC_PRELOAD);
		break;
		}


	  case FAST_AGC:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), FAST_AGC);
		break;
		}


	  case RF_STEP:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), RF_STEP);
		break;
		}


	  case SSI_MODE:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), SSI_MODE);
		break;
		}


	  case MFADJ:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), MFADJ);
		break;
		}

	  case BSAVE_MAIN_SYN:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), BSAVE_MAIN_SYN);
		break;
		}



	  case BSAVE_SYN_ALL:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), BSAVE_SYN_ALL);
		break;
		}


	  case BSAVE_ALL:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), BSAVE_ALL);
		break;
		}


	  case SF_BS:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), SF_BS);
		break;
		}


	  case SYN_ADAPTEN:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), SYN_ADAPTEN);
		break;
		}


	  case RXSM_ASPI_EN:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), RXSM_ASPI_EN);
		break;
		}

	  case MCRS_DAC:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), MCRS_DAC);
		break;
		}



	  case NUD:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), NUD);
		break;
		}


	  case ES_SEL2:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), ES_SEL2);
		break;
		}


	  case BSAVE_ESCORT:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), BSAVE_ESCORT);
		break;
		}


	  case GPO_1:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), GPO_1);
		break;
		}


	  case GPO_2:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), GPO_2);
		break;
		}

	  case GPO_3:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), GPO_3);
		break;
		}



	  case GPO_4:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), GPO_4);
		break;
		}


	  case GPO_5:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), GPO_5);
		break;
		}


	  case GPO_6:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), GPO_6);
		break;
		}


	  case CEFBEN:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), CEFBEN);
		break;
		}

	  case BSAVE_TX:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), BSAVE_TX);
		break;
		}

	  case ATTEN_Q:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), ATTEN_Q);
		break;
		}



	  case ATTEN_I:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), ATTEN_I);
		break;
		}


	  case PABIASDAC:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), PABIASDAC);
		break;
		}


	  case STATT_IQ:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), STATT_IQ);
		break;
		}


	  case EF_DC_UPDATE:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), EF_DC_UPDATE);
		break;
		}

	  case DC_UPDATE:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), DC_UPDATE);
		break;
		}

	  case BSAVE_TXR:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), BSAVE_TXR);
		break;
		}



	  case PWRCTL:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), PWRCTL);
		break;
		}


	  case A0_ENV:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), A0_ENV);
		break;
		}


	  case A1_ENV:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), A1_ENV);
		break;
		}


	  case A2_ENV:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), A2_ENV);
		break;
		}

	  case ASPI_CLK_SEL:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), ASPI_CLK_SEL);
		break;
		}

	  case AUXCEPOL:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), AUXCEPOL);
		break;
		}



	  case AUXCLKDIV2:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), AUXCLKDIV2);
		break;
		}


	  case AUXCLKDIV1:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), AUXCLKDIV1);
		break;
		}


	  case RX_EVENT2:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), RX_EVENT2);
		break;
		}


	  case RX_EVENT1:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), RX_EVENT1);
		break;
		}


	  case EF_SEL:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), EF_SEL);
		
		break;
		}



	case TXCONFIG:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), TXCONFIG);
		
		break;
		}



	case LP_ADD:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), LP_ADD);
		
		break;
		}



	case HP_SEL:
	    {
		
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), HP_SEL);
		break;
		}


	case TRACK_OSCEN:
	    {
		
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), TRACK_OSCEN);
		break;
		}


	case EN_DLY_MUX:
	    {
		
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), EN_DLY_MUX);
		break;
		}


	case ATT_SSI:
	    {
		
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), ATT_SSI);
		break;
		}




	case SYMB_REF:
	    {
		
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), SYMB_REF);
		break;
		}



	case EN_OVS_DLYD:
	    {
		
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), EN_OVS_DLYD);
		break;
		}

	case SSI_DLY:
	    {
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), SSI_DLY);
		
		break;
		}


	case DN_DLY:
	    {
		
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), DN_DLY);
		break;
		}


	case MAINND:
	    {
		
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), MAINND);
		break;
		}


	case MAINNUM_16_23:
	    {
		
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), MAINNUM_16_23);
		break;
		}


	case MAINNUM_0_15:
	    {
		
		Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), MAINNUM_0_15);
		break;
		}


	case GPIO_TRIST1:
			// READ port 1
		  	{
			Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), GPO_TRIST1);		
			break;}

	case GPIO_TRIST2:
			// READ port 2
		  	{
			Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), GPO_TRIST2);		
			break;}

	case GPIO_TRIST3:
			// READ port 3
		  	{
			Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), GPO_TRIST3);		
			break;}

	case GPIO_TRIST4:
			// READ port 4
		  	{
			Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), GPO_TRIST4);		
			break;}

	case GPIO_TRIST5:
			// READ port 5
		  	{
			Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), GPO_TRIST5);		
			break;}

	case GPIO_TRIST6:
			// READ port 6
		  	{
			Reg_Value = getBitField( &((*spi[rfState])[TOMAHWK_SPI_HEADER_SIZE]), GPO_TRIST6);		
			break;}


		
		}

	return Reg_Value;


	// }}}USR
}
// }}}RME

// {{{RME operation 'rdRegister(uint16_t,int)'
uint16_t tomahawk::rdRegister( uint16_t addr, int rfState )
{
	// {{{USR
	uint32_t temp_image;
	uint16_t image;
	uint16_t Cal_addr = 1;
	uint16_t value;

	// Because the data store in 32 bit so have to use 
	//the shift to determine which is the correct row (16bits).
	// the (+ 1) is because of the first buffer line is not used.
	Cal_addr = (addr >> 1);
	Cal_addr = Cal_addr + 1;



	// To know whether the address is the odd or even by using the last bit.
	value = addr & 0x0001;

	//getting the tomahawk spi image
	temp_image = spi[rfState]->operator[](Cal_addr);

	if (value == 0)
	{
	// if the addr is even, use the right signficant bits.
	temp_image =  temp_image >> 16;
	image = (uint16_t)temp_image;
	}
	else{
	image = (uint16_t)temp_image;
	}

	//return the pointer of the copy image.
	return image;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'tomahawkDiscreteRegEnum_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'tomahawkGainRegEnum_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'tomahawkGpoRegEnum_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
