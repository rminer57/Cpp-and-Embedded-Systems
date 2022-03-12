// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::Trident::Trident'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Trident.h"
#endif

#include <rf_sequencer_comp.h>
#include <Trident.h>
#include <Connection.h>
#include <SIntArray.h>
#include <rfSpiBuffer_int16.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'tridentSettingsEnum_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'tridentBitFieldEnum_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'Trident(TridentDefaultImages*,rfSpiBuffer_int16 **,int,int,int,int)'
Trident::Trident( TridentDefaultImages * init, rfSpiBuffer_int16 * * spiBuffers, int numberOfRfStates, int numberOfDiscretes, int numberOfGPOs, int numberOfGains )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	:discreteDeviceControl(numberOfDiscretes, numberOfRfStates),
	  synthesizer(numberOfRfStates),
	  synthesizerAdjust(numberOfRfStates),
	  generalPurposeOutputManager(numberOfGPOs),
	  gainControl( numberOfGains, numberOfRfStates, 0),
	  bbpControl(numberOfRfStates),
	  m_icVersion(0),
	  m_numberOfRfStates(numberOfRfStates),
	  m_currentRfState(0)

	 



	// }}}USR
	// }}}RME
{
	// {{{USR
	 //----------------------------- LOCAL VARIABLES ------------------------------

	  
	 //---------------------------------- CODE ------------------------------------  
	  
	 // Call the common code shared amongst the trident constructors
	  cmnTridentConstructor(init, spiBuffers, numberOfRfStates);

	// }}}USR
}
// }}}RME

// {{{RME operation 'cmnTridentConstructor(TridentDefaultImages*,rfSpiBuffer_int16 **,int)'
void Trident::cmnTridentConstructor( TridentDefaultImages * init, rfSpiBuffer_int16 * * spiBuffers, int numberOfRfStates )
{
	// {{{USR
	  //----------------------------- LOCAL VARIABLES ------------------------------

	  int i, j;  

	  //---------------------------------- CODE ------------------------------------  
	  
	  // set default data
	  m_rfSpiBuffer   = spiBuffers;			    // Pointer to the SPI buffers
	  m_defaultData 	  = init;				// Pointer to the default SPI images
	  m_SnippetSpiIndex = numberOfRfStates;	    // The last SPI buffer is used for partial SPI transmits

	  // Create RfState based data variables
	  m_ModifiedImage = new bool[numberOfRfStates];				    // SPI snippet modification status
	  m_ResetImage    = new bool[numberOfRfStates];				    // SPI snippet reset status
	  m_SnippetStatus   = new TridentSnippetStatus_t[numberOfRfStates];	// Individual snippet modification status for each state

	  // Initialize RF State based data elements
	 for(i = 0; i < numberOfRfStates; i++)
	  {

	  // Copy default image data to local SPI buffer
	    for(j = 0; j < TRIDENT_IMAGE_SIZE_INT16; j++)
		{
		  (*m_rfSpiBuffer[i])[j] = m_defaultData->defaultImages[i][j];
		}


		// Initialize the first byte of the SPI buffer with the static header tx type and 
		// address offset infromation
	      // Initialize snippet status variables 
	     for(j = 0; j <  TRIDENT_NUM_SNIPPETS; j++)
		 {
	         m_SnippetStatus[i][j].modified = false;
	         m_SnippetStatus[i][j].reset    = false;
		 }

	   // Initialize RfState based Data variables
	   m_ModifiedImage[i] = false;
	   m_ResetImage[i]	= false;
	  } 

	    // Create and initialize the BW baseband interpolation tables
	  m_bwDataTbl = new dataPoint*[TRIDENT_BW_DATA_SIZE];

	  m_bwDataTbl[0]  = new dataPoint(0,0);        			    // 0    - 4.25 - 4.47 KHz
	  m_bwDataTbl[1]  = new dataPoint((4.47 * KHZ),0);  		// 
	  m_bwDataTbl[2]  = new dataPoint((4.48 * KHZ),1);  		// 4.48 - 4.69 - 4.94 KHz
	  m_bwDataTbl[3]  = new dataPoint((4.94 * KHZ),1);  		// 
	  m_bwDataTbl[4]  = new dataPoint((4.95 * KHZ),2);  		// 4.95 - 5.18 - 5.45 KHz
	  m_bwDataTbl[5]  = new dataPoint((5.45 * KHZ),2); 		    // 
	  m_bwDataTbl[6]  = new dataPoint((5.46 * KHZ),3); 		    // 5.46 - 5.72 - 6.02 KHz
	  m_bwDataTbl[7]  = new dataPoint((6.02 * KHZ),3); 		    // 
	  m_bwDataTbl[8]  = new dataPoint((6.03 * KHZ),4);  		// 6.03 - 6.32 - 6.65 KHz
	  m_bwDataTbl[9]  = new dataPoint((6.65 * KHZ),4);  		// 
	  m_bwDataTbl[10] = new dataPoint((6.66 * KHZ),5);  		// 6.66 - 6.97 - 7.33 KHz
	  m_bwDataTbl[11] = new dataPoint((7.33 * KHZ),5);  		// 
	  m_bwDataTbl[12] = new dataPoint((7.34 * KHZ),6);  		// 7.34 - 7.70 - 8.10 KHz
	  m_bwDataTbl[13] = new dataPoint((8.10 * KHZ),6); 		    // 
	  m_bwDataTbl[14] = new dataPoint((8.11 * KHZ),7); 		    // 8.11 - 8.50 - 8.95 KHz
	  m_bwDataTbl[15] = new dataPoint((8.95 * KHZ),7); 		    // 
	  m_bwDataTbl[16] = new dataPoint((8.96 * KHZ),8);  		// 8.96 - 9.39 - 9.78 KHz
	  m_bwDataTbl[17] = new dataPoint((9.78 * KHZ),8);  		// 
	  m_bwDataTbl[18] = new dataPoint((9.79 * KHZ),9);  		// 9.79 - 10.36 - 10.90 KHz
	  m_bwDataTbl[19] = new dataPoint((10.90 * KHZ),9);  		// 
	  m_bwDataTbl[20] = new dataPoint((10.91 * KHZ),10); 		// 10.91 - 11.44 - 12.04 KHz
	  m_bwDataTbl[21] = new dataPoint((12.04 * KHZ),10); 		// 
	  m_bwDataTbl[22] = new dataPoint((12.05 * KHZ),11); 		// 12.05 - 12.63 - 13.29 KHz
	  m_bwDataTbl[23] = new dataPoint((13.29 * KHZ),11); 		// 
	  m_bwDataTbl[24] = new dataPoint((13.30 * KHZ),12); 		// 13.30 - 13.95 - 14.68 KHz
	  m_bwDataTbl[25] = new dataPoint((14.68 * KHZ),12); 		// 
	  m_bwDataTbl[26] = new dataPoint((14.69 * KHZ),13); 		// 14.69 - 15.40 - 16.20 KHz
	  m_bwDataTbl[27] = new dataPoint((16.20 * KHZ),13); 		// 
	  m_bwDataTbl[28] = new dataPoint((16.21 * KHZ),14); 		// 16.21 - 17.00 - 17.88 KHz
	  m_bwDataTbl[29] = new dataPoint((17.88 * KHZ),14); 		// 
	  m_bwDataTbl[30] = new dataPoint((17.89 * KHZ),15); 		// 17.89 - 18.77 - 19.75 KHz
	  m_bwDataTbl[31] = new dataPoint((19.75 * KHZ),15); 		// 
	  m_bwDataTbl[32] = new dataPoint((19.76 * KHZ),16); 		// 19.76 - 20.73 - 21.80 KHz
	  m_bwDataTbl[33] = new dataPoint((21.80 * KHZ),16); 		// 
	  m_bwDataTbl[34] = new dataPoint((21.81 * KHZ),17); 		// 21.81 - 22.88 - 24.08 KHz
	  m_bwDataTbl[35] = new dataPoint((24.08 * KHZ),17); 		// 
	  m_bwDataTbl[36] = new dataPoint((24.09 * KHZ),18); 		// 24.09 - 25.27 - 26.59 KHz
	  m_bwDataTbl[37] = new dataPoint((26.59 * KHZ),18); 		// 
	  m_bwDataTbl[38] = new dataPoint((26.60 * KHZ),19); 		// 26.60 - 27.90 - 29.35 KHz
	  m_bwDataTbl[39] = new dataPoint((29.35 * KHZ),19); 		// 
	  m_bwDataTbl[40] = new dataPoint((29.36 * KHZ),20); 		// 29.36 - 30.80 - 32.45 KHz
	  m_bwDataTbl[41] = new dataPoint((32.45 * KHZ),20); 		// 
	  m_bwDataTbl[42] = new dataPoint((32.46 * KHZ),21); 		// 32.46 - 34.01 - 35.78 KHz
	  m_bwDataTbl[43] = new dataPoint((35.78 * KHZ),21); 		// 
	  m_bwDataTbl[44] = new dataPoint((35.79 * KHZ),22); 		// 35.79 - 37.55 - 39.51 KHz
	  m_bwDataTbl[45] = new dataPoint((39.51 * KHZ),22); 		// 
	  m_bwDataTbl[46] = new dataPoint((39.52 * KHZ),23); 		// 39.52 - 41.46 - 43.62 KHz
	  m_bwDataTbl[47] = new dataPoint((43.62 * KHZ),23); 		// 
	  m_bwDataTbl[48] = new dataPoint((43.63 * KHZ),24); 		// 43.63 - 45.77 - 48.16 KHz
	  m_bwDataTbl[49] = new dataPoint((48.16 * KHZ),24); 		// 
	  m_bwDataTbl[50] = new dataPoint((48.17 * KHZ),25); 		// 48.17 - 50.54 - 53.17 KHz
	  m_bwDataTbl[51] = new dataPoint((53.17 * KHZ),25); 		// 
	  m_bwDataTbl[52] = new dataPoint((53.18 * KHZ),26); 		// 53.18 - 55.80 - 58.21 KHz
	  m_bwDataTbl[53] = new dataPoint((58.21 * KHZ),26); 		// 
	  m_bwDataTbl[54] = new dataPoint((58.22 * KHZ),27); 		// 58.22 - 61.61 - 64.82 KHz
	  m_bwDataTbl[55] = new dataPoint((64.82 * KHZ),27); 		// 
	  m_bwDataTbl[56] = new dataPoint((64.83 * KHZ),28); 		// 64.83 - 68.02 - 71.56 KHz
	  m_bwDataTbl[57] = new dataPoint((71.56 * KHZ),28); 		// 
	  m_bwDataTbl[58] = new dataPoint((71.57 * KHZ),29); 		// 71.57 - 75.10 - 79.10 KHz
	  m_bwDataTbl[59] = new dataPoint((79.10 * KHZ),29); 		// 
	  m_bwDataTbl[60] = new dataPoint((79.11 * KHZ),30); 		// 79.11 - 82.92 - 87.24 KHz
	  m_bwDataTbl[61] = new dataPoint((87.24 * KHZ),30); 		// 
	  m_bwDataTbl[62] = new dataPoint((87.25 * KHZ),31); 		// 87.25 - 91.55 - 100.0 KHz
	  m_bwDataTbl[63] = new dataPoint((100.0 * KHZ),31); 		// 

	  m_bwBB = new interpolationData((dataPoint**)m_bwDataTbl, TRIDENT_BW_DATA_SIZE);



	// }}}USR
}
// }}}RME

// {{{RME operation '~Trident()'
Trident::~Trident( void )
{
	// {{{USR
	  // Remove the partial SPI image data structures
	  delete [] m_ModifiedImage;
	  delete [] m_ResetImage;
	  delete [] m_SnippetStatus;

	// Remove error management variables

	  delete [] m_bwDataTbl;

	  delete m_bwBB;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setRFState(int32_t)'
int32_t Trident::setRFState( int32_t rfState )
{
	// {{{USR
	//Header Value		Function						Trident Address
	//00h - 4Fh			Trident SPI addressing-write only	00h - 4Fh
	//50h - 5Fh			Reserved-unused				n/a
	//60h - 67h			Aux1 SPI write/read 4-wire		n/a
	//68h - 6Fh			Aux1 SPI write/read *			n/a
	//70h - 77h			Aux2 SPI write/read 4-wire		n/a
	//78h - 7Fh			Aux2 SPI write/read *			n/a
	//80h - CFh			Trident SPI addressing read/write	00h - 4Fh

	//D0h - DFh			Trident internal read-back	n/a
	//E0h - FFh			reserved	n/a

	int     i;

	static bool firstInvocation = true;


	int32_t prevState = 0;

	// validate rfState argument
	if( (rfState >= 0) && ( rfState <= m_numberOfRfStates) )
	{
		
	   //if first invocation of setRFState
	   if( firstInvocation == true )
	   {  	
	     	// write complete image to the IC
	        m_rfSpiBuffer[rfState]->sync();
	        
	        // Loop through the image snippet status record
	        // and clear all status indication fields since we are writing the entire image to IC
	        for (i = 0; i < TRIDENT_NUM_SNIPPETS; i++)  m_SnippetStatus[rfState][i].modified = false; 
	             
	        firstInvocation = false;
	        synthesizer::setRFState(rfState);  // set the rf state    
	     	
	   }
	   else // not first invocation 
	   {
	        //if old rfState == new rfState and something has been changed  i.e. updating current state
	        if( (m_currentRfState == rfState) && (m_ModifiedImage[rfState] == true) )
	        {
	          // Loop through the image snippet status record to find modified indications
	          for (i = 0; i < TRIDENT_NUM_SNIPPETS; i++)
	          {

	            // Check if snippet of memory has been modified
	            if (m_SnippetStatus[rfState][i].modified == true)
	            {

	             // Insert the trident header information in byte 0. (Mode and address offset)
	             (*m_rfSpiBuffer[m_SnippetSpiIndex])[0] = (int16_t)( (( i * TRIDENT_SNIPPET_SIZE)/2 )); 
	        
	             // Copy the snippet image from the local SPI buffer to the 
	             // snippet buffer for transmission.  Offset the payload 
	             // in the snippet buffer to compensate for the trident header
	             (*m_rfSpiBuffer[m_SnippetSpiIndex])[1] = (*m_rfSpiBuffer[rfState])[i+TRIDENT_SPI_HEADER_SIZE];

	             // write the entire local SPI image
	             m_rfSpiBuffer[m_SnippetSpiIndex]->sync();       
	                
	             // Clear the modified status indication
	             m_SnippetStatus[rfState][i].modified = false;

	            } // end if (m_SnippetStatus[rfState][i].modified == true)
	        
	          }// end for
	        
	 
	        }   	     
	        else // (m_currentRfState != rfState ) ... state change so images must be compared bit by bit
	        {
	           // if previous image != current image then update IC
	           for(int j = 0; j < TRIDENT_IMAGE_SIZE_INT16; j++)
		       {
		         if( (*m_rfSpiBuffer[m_currentRfState])[j] != (*m_rfSpiBuffer[rfState])[j] )
				 {
	                // found differences.
	    	        // write complete image to the IC
	                m_rfSpiBuffer[rfState]->sync();

					// clear all modified indications 
					for (i = 0; i < TRIDENT_NUM_SNIPPETS; i++) 
	                {
					   m_SnippetStatus[rfState][i].modified = false;
					} 

	             }

		       }
	           	
	        }    	     


	   } // end if first invocation of setRFState, else
	 

	   // Always reset status indicators
	   m_ModifiedImage[rfState] = false;
	   m_currentRfState         = rfState;
	 
	   // set the new RF state and return the previous Rf state
	   prevState = synthesizer::setRFState(rfState);
	  
	   m_error = TRIDENT_ERRCODE_NOERR; 

	} // end if( (rfState >= 0) && ( rfState <= m_numberOfRfStates) )
	else
	{
	  // rfState is out of range
	  m_error = TRIDENT_ERRCODE_BADARG_RFSTATE;    
	}

	return prevState;  
	// }}}USR
}
// }}}RME

// {{{RME operation 'setGPO(int16_t,int16_t,int16_t)'
void Trident::setGPO( int16_t portNumber, int16_t outputState, int16_t rfState )
{
	// {{{USR

	// first check rfState argument...use of invalid value will result in memory exception. aka crash
	if( (rfState >= 0 ) && (rfState <= m_numberOfRfStates) )
	{ 

	  switch( portNumber )
	  {
	    // only these are valid for setGPO
	    case Trident::GPO_1:
	    case Trident::GPO_2:
		case Trident::GPO_3:
	    case Trident::GPO_4:
	    case Trident::GPO_5:
	    case Trident::GPO_6:
	    case Trident::GPO_7:
	    case Trident::GPO_8:
		
	      // setting, deviceId, rfState, TRIDENT_READ or TRIDENT_WRITE, TRIDENT_ACCESS_IMAGE or TRIDENT_ACCESS_IC
	      // THIS METHOD PERFORMS COMPLETE ARGUMENT CHECKING
	      cmnRdWrPrimitiveAccessor(outputState, portNumber,rfState,TRIDENT_WRITE,TRIDENT_ACCESS_IMAGE);

	    break;
		
	    default:

	      m_error = TRIDENT_ERRCODE_BADARG_DEVICEID;

		break;
	  }
	  

	}
	else
	{
	  m_error = TRIDENT_ERRCODE_BADARG_RFSTATE;
	}

	 
	// }}}USR
}
// }}}RME

// {{{RME operation 'setDeviceState(int,int,int)'
int Trident::setDeviceState( int setting, int deviceId, int rfState )
{
	// {{{USR

	  //----------------------------- LOCAL VARIABLES ------------------------------

	int returnvalue = 0; // error indicator

	// first check rfState argument...use of invalid value will result in memory exception. aka crash
	if( (rfState >= 0 ) && (rfState <= m_numberOfRfStates) )
	{ 

	  // the purpose of the switch statement is to EXCLUDE from the call to discreteDeviceControl::setDeviceState,
	  // bitfields that are not considered to fall under the discreteDevice category.
	  // The criteria is that if a bitfield CANNOT be accessed via another abstract interface
	  // such as setGain or setGPO then it belongs in discreteDeviceControl
	  switch(deviceId)
	  {

	    case Trident::AMP_AGC:  // gains covered by setGain
	    case Trident::BUFGAIN:
	    case Trident::STATT_IQ:
	    case Trident::STATT_EF:
	    case Trident::GPO_1:    // GPO writes covered by setGPO
	    case Trident::GPO_2:
	    case Trident::GPO_3:
	    case Trident::GPO_4:
	    case Trident::GPO_5:
	    case Trident::GPO_6:
	    case Trident::GPO_7:
	    case Trident::GPO_8:
		case Trident::AUX_DAC:  // covered by setWarp
		{

	       m_error = TRIDENT_ERRCODE_BADARG_DEVICEID; 

		   break;
		}

	    // unlike most switch blocks, here the default case is the one that does something
	    default:
		{
	      // THIS METHOD PERFORMS COMPLETE ARGUMENT CHECKING
		  cmnRdWrPrimitiveAccessor(setting, deviceId, rfState,TRIDENT_WRITE, TRIDENT_ACCESS_IMAGE);

	      if( m_error == TRIDENT_ERRCODE_NOERR )
	      {
		    returnvalue = discreteDeviceControl::setDeviceState(setting, deviceId, rfState);
	      }
	      break;
		}

	  }  // END - switch
	}
	else
	{
	  m_error = TRIDENT_ERRCODE_BADARG_RFSTATE;
	}
	  return returnvalue;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setGain(int,int,int)'
int Trident::setGain( int gainNumber, int gain, int rfState )
{
	// {{{USR

	int returnvalue = 0;
	int gainIndex = 0;
	m_error = TRIDENT_ERRCODE_NOERR;

	// first check rfState argument...use of invalid value will result in memory exception. aka crash
	if( (rfState >= 0 ) && (rfState <= m_numberOfRfStates) )
	{  
	     // gainNumber is an enumeration so it must be translated into an
		 // array index. The gainControl base class maintains an array (size 4 for trident) used
		 // to save the last setting.
	     switch( gainNumber )
		 {
	       case Trident::AMP_AGC:

		     gainIndex = TRIDENT_NUM_GAIN_AMP_AGC;  // index =0

	       break;

		   case Trident::BUFGAIN:

		     gainIndex = TRIDENT_NUM_GAIN_BUFGAIN;  // index =1

	       break;

	       case Trident::STATT_EF:

		     gainIndex = TRIDENT_NUM_GAIN_STATT_EF;  // index =2

	       break;

	       case Trident::STATT_IQ:

		     gainIndex = TRIDENT_NUM_GAIN_STATT_IQ;  // index =3

	       break;

		   default:

	         m_error = TRIDENT_ERRCODE_BADARG_DEVICEID;

		   break;

		 }

		 if( m_error == TRIDENT_ERRCODE_NOERR )
	     {

		   // setting, deviceId, rfState, TRIDENT_READ or TRIDENT_WRITE, TRIDENT_ACCESS_IMAGE or TRIDENT_ACCESS_IC
	       // THIS METHOD PERFORMS COMPLETE ARGUMENT CHECKING
	       cmnRdWrPrimitiveAccessor(gain, gainNumber, rfState,TRIDENT_WRITE, TRIDENT_ACCESS_IMAGE); 

	       // return previous setting for this parameter
	       returnvalue = gainControl::setGain(gainIndex, gain, rfState); 
	     } 	  
	}
	else
	{
	  m_error = TRIDENT_ERRCODE_BADARG_RFSTATE;
	}
		   
	return returnvalue;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setBBPFrequency(int,int)'
int Trident::setBBPFrequency( int frequencyKhz, int rfState )
{
	// {{{USR

			
	// Determine bit value of frequency and then modify BW register in the image 
		
	int setting = 0;
	int argTest;
	int retvalue = 0;

	// first check rfState argument...use of invalid value will result in memory exception. aka crash
	if( (rfState >= 0 ) && (rfState <= m_numberOfRfStates) )
	{
	    // perform interpolation on this setting to obtain the closest possible setting for this radio.	
		setting =  m_bwBB->interpolate(frequencyKhz);	
	  
	    cmnRdWrPrimitiveAccessor(setting, Trident::BW, rfState );

	    if( m_error == TRIDENT_ERRCODE_NOERR )
		{
		  // by baseclass definition, setBBPFrequency must return the previous setting
	      retvalue = bbpControl::setBBPFrequency(frequencyKhz, rfState);
		}

	}
	else
	{
	  m_error = TRIDENT_ERRCODE_BADARG_RFSTATE;
	}

	return retvalue;

	// }}}USR
}
// }}}RME

// {{{RME operation 'setSynthFrequency(int32_t,int16_t,int32_t,int32_t)'
int32_t Trident::setSynthFrequency( int32_t synthFrequencyHz, int16_t rfState, int32_t resolution, int32_t refFrequencyHz )
{
	// {{{USR
	int32_t retvalue = 0;

	// first check rfState argument...use of invalid value will result in memory exception. aka crash
	if( (rfState >= 0 ) && (rfState <= m_numberOfRfStates) )
	{   
	  // calculates the correct bit settings and programs the bits in the image specified by rfState.
	  setFreqParams(synthFrequencyHz, refFrequencyHz, resolution, rfState);

	  // stores the new settings in attributes of the base class and returns the previous frequency setting.
	  retvalue = synthesizer::setSynthFrequency(synthFrequencyHz, rfState, 0, 0);

	  m_error = TRIDENT_ERRCODE_NOERR;
	}
	else
	{
	  m_error = TRIDENT_ERRCODE_BADARG_RFSTATE;
	} 

	  return retvalue;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setFreqParams(int32_t,int32_t,int32_t,int16_t)'
void Trident::setFreqParams( int32_t synthFrequencyHz, int32_t refFrequencyHz, int32_t resolution, int16_t rfState )
{
	// {{{USR

	  //----------------------------- LOCAL VARIABLES ------------------------------

	  int32_t	 refDivisor;
	  int32_t	 refFreqFrequency;
	  int32_t	 divInteger;
	  int32_t	 divFractional;
	  int16_t    macc;


	    // =========================================================================
		//                       TRIDENT MAIN SYNTHESIZER
		// =========================================================================
		//
		//	Trident Main frequency formula:
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
		refDivisor = cmnRdWrPrimitiveAccessor(0, Trident::MREF_DIV,rfState,TRIDENT_READ,TRIDENT_ACCESS_IMAGE);

		// Check if divisor = 0, set to 1 to avoid divide-by-0 error - this code duplicated from tomahawk
		if (refDivisor == 0)
			refDivisor = 1;

		// Determine the integer portion of the divisor
		refFreqFrequency = synthFrequencyHz * refDivisor;
		divInteger		 = refFreqFrequency / refFrequencyHz;

		// Determine the fractional portion of the divisor
		divFractional = refFreqFrequency - (divInteger * refFrequencyHz);

	    macc = cmnRdWrPrimitiveAccessor(0, Trident::MACC,rfState,TRIDENT_READ,TRIDENT_ACCESS_IMAGE);

		// Adjust integer portion based on the accumulator (MACC) setting
		if ( macc > 0x01)		divInteger = divInteger - 3;

		// Determine the fractional portion of the divisor
		divFractional = (int32_t)(((float)(divFractional)/(float)(refFrequencyHz)) * 0x1000000);

		// Modify the image with the new attributes
		cmnRdWrPrimitiveAccessor(((divFractional>>16) & 0x000000FF), Trident::MAINNUM_16_23,rfState,TRIDENT_WRITE,TRIDENT_ACCESS_IMAGE);

	    if(m_error == TRIDENT_ERRCODE_NOERR) // only do this write if the previous arguments were valid
		{   
	   	  // Modify the image with the new attributes
		  cmnRdWrPrimitiveAccessor( (divFractional & 0x0000FFFF), Trident::MAINNUM_0_15,rfState,TRIDENT_WRITE,TRIDENT_ACCESS_IMAGE);
	    }

	    if(m_error == TRIDENT_ERRCODE_NOERR) // only do this write if the previous arguments were valid
		{  
	  	  // Modify the image with the new attributes
		  cmnRdWrPrimitiveAccessor( divInteger, Trident::MAINND,rfState,TRIDENT_WRITE,TRIDENT_ACCESS_IMAGE);
	    }




	// }}}USR
}
// }}}RME

// {{{RME operation 'LogSnippetMod(int,int)'
void Trident::LogSnippetMod( int RfState, int SnippetID )
{
	// {{{USR
	  //----------------------------- LOCAL VARIABLES ------------------------------


	  //---------------------------------- CODE ------------------------------------  

		// Set status indicating specified snippet is modified for syncheonization and 
		// will require an update during a reset
		m_SnippetStatus[RfState][SnippetID].modified = true;
		m_SnippetStatus[RfState][SnippetID].reset    = true;

		// Global image status indicating update and reset 
		m_ModifiedImage[RfState] = true;
		m_ResetImage[RfState]    = true;

	// }}}USR
}
// }}}RME

// {{{RME operation 'ResetRFState(int)'
void Trident::ResetRFState( int rfState )
{
	// {{{USR
	//----------------------------- LOCAL VARIABLES ------------------------------
	  
	int		i, j;
	unsigned char 	*tempSpi;

	// first check rfState argument...use of invalid value will result in memory exception. aka crash
	if( (rfState >= 0 ) && (rfState <= m_numberOfRfStates) )
	{ 

	 // Determine if image needs to be reset
	 if (m_ResetImage[rfState] == true)
	 {
		// Loop through the image snippet status record to find modified indications
		for (i = 0; i < TRIDENT_NUM_SNIPPETS; i++)
		{
			// Check if snippet of memory has been modified
			if (m_SnippetStatus[rfState][i].reset == true)
			{
				// Cast the SPI buffer pointer to a byte array
				tempSpi = (unsigned char *)&((*m_rfSpiBuffer[rfState])[0]);

				// Copy the snippet image from the local SPI buffer to the 
				// snippet buffer for transmission
				for (j = 0; j < TRIDENT_SNIPPET_SIZE; j++)		

					tempSpi[(i*TRIDENT_SNIPPET_SIZE)+TRIDENT_SPI_HEADER_SIZE+j] =
					m_defaultData->defaultImages[rfState][(i*TRIDENT_SNIPPET_SIZE)+j];
			
				// Clear the modified status indication
				m_SnippetStatus[rfState][i].modified = false;
				m_SnippetStatus[rfState][i].reset    = false;

			}
		}

		// Reset Modified status indiciation
		m_ModifiedImage[rfState] = false;
		m_ResetImage[rfState]    = false;
	  }
	  m_error = TRIDENT_ERRCODE_NOERR;

	}
	else
	{
	  m_error = TRIDENT_ERRCODE_BADARG_RFSTATE;
	}
	// }}}USR
}
// }}}RME

// {{{RME operation 'commitGPO(Integer,Integer)'
void Trident::commitGPO( Integer portNumber, Integer rfState )
{
	// {{{USR


	 setRFState(rfState);
	// }}}USR
}
// }}}RME

// {{{RME operation 'writeImage(int,int,int)'
void Trident::writeImage( int rfState, int deviceId, int setting )
{
	// {{{USR

	// first check rfState argument...use of invalid value will result in memory exception. aka crash
	if( (rfState >= 0 ) && (rfState <= m_numberOfRfStates) )
	{ 
	  // sets the specified bit and writes to the IC if arguments are valid.
	  // m_error set according to results
	  cmnRdWrPrimitiveAccessor(setting, deviceId, rfState,TRIDENT_WRITE, TRIDENT_ACCESS_IC);

	}
	else
	{
	  m_error = TRIDENT_ERRCODE_BADARG_RFSTATE;
	}
	// }}}USR
}
// }}}RME

// {{{RME operation 'wrRegister(int16_t,int16_t,int)'
void Trident::wrRegister( int16_t addr, int16_t data, int rfState )
{
	// {{{USR


	// first check rfState argument...use of invalid value will result in memory exception. aka crash
	if( (rfState >= 0 ) && (rfState <= m_numberOfRfStates) )
	{ 
	  // make sure address is within range of 0>= addr <= 0x44
	  if( (addr >= 0) && (addr < TRIDENT_IMAGE_SIZE_INT16) )
	  {
	   // skip first address because it holds address header
	   (*m_rfSpiBuffer[rfState])[addr + 1] = data;


	   //manually activate the snippet flag
	   m_ModifiedImage[rfState] = true;
	   m_SnippetStatus[rfState][addr + 1].modified = true;


	   //write the data to the trident.
	   setRFState(rfState);

	   m_error = TRIDENT_ERRCODE_NOERR;

	  }
	  else
	  {
	    m_error = TRIDENT_ERRCODE_BADARG_ADDR;
	  }

	}
	else
	{
	  m_error = TRIDENT_ERRCODE_BADARG_RFSTATE;
	}
	// }}}USR
}
// }}}RME

// {{{RME operation 'ResetCompImage(int)'
void Trident::ResetCompImage( int rfState )
{
	// {{{USR
	int j;

	// first check rfState argument...use of invalid value will result in memory exception. aka crash
	if( (rfState >= 0 ) && (rfState <= m_numberOfRfStates) )
	{ 
	  // Copy default image data to local SPI buffer
	  for(j = 0; j < TRIDENT_IMAGE_SIZE_INT16; j++)
	  {
	    (*m_rfSpiBuffer[rfState])[j] = m_defaultData->defaultImages[rfState][j];
	  }

	  setRFState(rfState);

	  m_error = TRIDENT_ERRCODE_NOERR;

	}
	else
	{
	  m_error = TRIDENT_ERRCODE_BADARG_RFSTATE;
	}
	// }}}USR
}
// }}}RME

// {{{RME operation 'readImage(int,int)'
int32_t Trident::readImage( int deviceId, int rfState )
{
	// {{{USR
	//------------- LOCAL VARIABLES ------------------------------------------------------------------
	int32_t Reg_Value = 0;

	// first check rfState argument...use of invalid value will result in memory exception. aka crash
	if( (rfState >= 0 ) && (rfState <= m_numberOfRfStates) )
	{ 
	  // setting, deviceId, rfState, TRIDENT_READ or TRIDENT_WRITE, TRIDENT_ACCESS_IMAGE or TRIDENT_ACCESS_IC
	  // THIS METHOD PERFORMS COMPLETE ARGUMENT CHECKING, return value of 1 indicates checking passed.
	  // the first argument, setting, is 0 because its not applicable to a read operation.
	  Reg_Value = cmnRdWrPrimitiveAccessor(0, deviceId, rfState,TRIDENT_READ, TRIDENT_ACCESS_IMAGE);


	}
	else
	{
	  m_error = TRIDENT_ERRCODE_BADARG_RFSTATE;
	}

	return Reg_Value;


	// }}}USR
}
// }}}RME

// {{{RME operation 'rdRegister(int16_t,int)'
int16_t Trident::rdRegister( int16_t addr, int rfState )
{
	// {{{USR
	int16_t data = 0;
	m_error = TRIDENT_ERRCODE_NOERR; 

	// first check rfState argument...use of invalid value will result in memory exception. aka crash
	if( (rfState >= 0 ) && (rfState <= m_numberOfRfStates) )
	{ 
	  // make sure address is within range of 0>= addr <= 0x44
	  if( (addr >= 0) && (addr < TRIDENT_IMAGE_SIZE_INT16) )
	  {

	    // skip first address because it holds address header
	    data = (*m_rfSpiBuffer[rfState])[addr + 1]; 

	  }
	  else
	  {
	    m_error = TRIDENT_ERRCODE_BADARG_ADDR;
	  }

	}
	else
	{
	  m_error = TRIDENT_ERRCODE_BADARG_RFSTATE;
	}

	return data;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setWarp(int,int)'
int Trident::setWarp( int warp, int rfState )
{
	// {{{USR
	int returnvalue = 0;

	// first check rfState argument...use of invalid value will result in memory exception. aka crash
	if( (rfState >= 0 ) && (rfState <= m_numberOfRfStates) )
	{

	  // this method argument-checks and writes results to m_error...

	  //                    setting,     deviceId,  rfState, TRIDENT_READ or TRIDENT_WRITE, TRIDENT_ACCESS_IMAGE or TRIDENT_ACCESS_IC
	  cmnRdWrPrimitiveAccessor(warp, Trident::AUX_DAC,rfState,TRIDENT_WRITE,TRIDENT_ACCESS_IMAGE);

	  if( m_error == TRIDENT_ERRCODE_NOERR )
	  {
	    // set currentWarp value and return previous warp value
	    returnvalue = synthesizerAdjust::setWarp(warp, rfState);
	  }
	}
	else
	{
	  m_error = TRIDENT_ERRCODE_BADARG_RFSTATE;
	}

	return returnvalue;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getStatus(Integer,Integer)'
Integer Trident::getStatus( Integer deviceId, Integer rfState )
{
	// {{{USR
	Integer returnvalue = 0;

	// first check rfState argument...use of invalid value will result in memory exception. aka crash
	if( (rfState >= 0 ) && (rfState <= m_numberOfRfStates) )
	{ 


	  // the purpose of the switch statement is to EXCLUDE from the call to discreteDeviceControl::setDeviceState,
	  // bitfields that are not considered to fall under the discreteDevice category.
	  // The criteria is that if a bitfield CANNOT be accessed via another abstract interface
	  // such as setGain or setGPO then it belongs in discreteDeviceControl
	  switch(deviceId)
	  {

	    case Trident::AMP_AGC:  // gains covered by setGain
	    case Trident::BUFGAIN:
	    case Trident::STATT_IQ:
	    case Trident::STATT_EF:
	    case Trident::GPO_1:    // GPO writes covered by setGPO
	    case Trident::GPO_2:
	    case Trident::GPO_3:
	    case Trident::GPO_4:
	    case Trident::GPO_5:
	    case Trident::GPO_6:
	    case Trident::GPO_7:
	    case Trident::GPO_8:
	    case Trident::AUX_DAC:  // covered by setWarp

		{

	       m_error = TRIDENT_ERRCODE_BADARG_DEVICEID; 

		   break;
		}

	    // unlike most switch blocks, here the default case is the one that does something
	    default:
		{
	      // setting, deviceId, rfState, TRIDENT_READ or TRIDENT_WRITE, TRIDENT_ACCESS_IMAGE or TRIDENT_ACCESS_IC
	      // THIS METHOD PERFORMS COMPLETE ARGUMENT CHECKING, return value of 1 indicates checking passed.
		  // the first argument, setting, is 0 because its not applicable to a read operation.
	      returnvalue = cmnRdWrPrimitiveAccessor(0, deviceId, rfState,TRIDENT_READ, TRIDENT_ACCESS_IMAGE);

	      break;
		}

	  }  // END - switch

	}
	else
	{
	  m_error = TRIDENT_ERRCODE_BADARG_RFSTATE;
	}
	  return returnvalue;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getICVersion()'
int Trident::getICVersion( void )
{
	// {{{USR

	SIntArray * readBackData = 0;

	if( m_icVersion == 0 )
	{
	  //read version number from IC register TRIDENT_HW_ID[7:0] via spi access
	  // This method returns an SIntArray of length 5.
	  readBackData = internalReadBack();

	  // TRIDENT Hardware revision ID is most significant 8 bits (D8 - D15) of second array index.
	  // the first index is the address header.  The internalReadBack method adjusts the data according
	  // to Endian-ness of the target machine.
	  // shift down to D0 - D7 position

	  m_icVersion = (*readBackData)[1] >> 8;

	  delete readBackData;
	}


	return m_icVersion;
	// }}}USR
}
// }}}RME

// {{{RME operation 'Trident(TridentDefaultImages*,rfSpiBuffer_int16 **,int)'
Trident::Trident( TridentDefaultImages * init, rfSpiBuffer_int16 * * spiBuffers, int numberOfRfStates )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	:discreteDeviceControl(TRIDENT_NUMOF_BITFIELDS, numberOfRfStates),
	  synthesizer(numberOfRfStates),
	  synthesizerAdjust(numberOfRfStates),
	  generalPurposeOutputManager(TRIDENT_NUM_GPOS),
	  gainControl( TRIDENT_NUM_GAINS, numberOfRfStates, 0),
	  bbpControl(numberOfRfStates),
	  m_icVersion(0),
	  m_numberOfRfStates(numberOfRfStates),
	  m_currentRfState(0)


	// }}}USR
	// }}}RME
{
	// {{{USR
	 //----------------------------- LOCAL VARIABLES ------------------------------

	  
	 //---------------------------------- CODE ------------------------------------  
	  
	 // Call the common code shared amongst the trident constructors
	  cmnTridentConstructor(init, spiBuffers, numberOfRfStates);

	// }}}USR
}
// }}}RME

// {{{RME operation 'getIOVirtualSerial(unsigned int,bool,bool)'
IOVirtualSerial * Trident::getIOVirtualSerial( unsigned int whichIOVirtualSerial, bool auxSpiBufferSizeNormal, bool spiMode4wire )
{
	// {{{USR

	IOVirtualSerial * retobj = 0;

	switch(whichIOVirtualSerial)
	{
	   case SPIAUX1:
	   case SPIAUX2:

	     retobj = new TridentIOVirtualSerial(whichIOVirtualSerial, this, auxSpiBufferSizeNormal, spiMode4wire);

	     m_error = TRIDENT_ERRCODE_NOERR;

	   break;

	   default:

	     m_error = TRIDENT_ERRCODE_BADARG_DEVICEID;

	   break;

	}


	return retobj;
	// }}}USR
}
// }}}RME

// {{{RME operation 'cmnRdWrPrimitiveAccessor(int,int,int,bool,bool)'
int Trident::cmnRdWrPrimitiveAccessor( int setting, int deviceId, int rfState, bool readORwrite, bool imageORIC )
{
	// {{{USR
	bool badArg;
	int returnvalue = 0;
	m_error = TRIDENT_ERRCODE_BADARG_SETTING;

	//---------------------------------- CODE ------------------------------------  

	// first check rfState argument...use of invalid value could result in memory exception
	if( (rfState >= 0 ) && (rfState <= m_numberOfRfStates) )
	{

	  switch( deviceId)
	  {
	    
	      case Trident::TXCLK_POL:                   
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {       
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFFFF, setting);    

	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), TXCLK_POL , setting);
	             LogSnippetMod(rfState, TXCLK_POL_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	          returnvalue = getBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), MREF_DIV );
			  m_error = TRIDENT_ERRCODE_NOERR;
	        }

	        break;
	      }           
	      case Trident::ABF_SEL:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {       
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), ABF_SEL  , setting);
	             LogSnippetMod(rfState, ABF_SEL_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }                        
	      case Trident::ABR_SEL:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), ABR_SEL  , setting);
	             LogSnippetMod(rfState, ABR_SEL_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::DN_DLY:                      
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), DN_DLY  , setting);
	             LogSnippetMod(rfState,  DN_DLY_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }                        
	      case Trident::OVSX:                        
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), OVSX  , setting);
	             LogSnippetMod(rfState,  OVSX_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::SC_SEL:                      
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), SC_SEL  , setting);
	             LogSnippetMod(rfState,  SC_SEL_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::LAST_INT:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), LAST_INT  , setting);
	             LogSnippetMod(rfState,  LAST_INT_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::FIRCLK_SB:                   
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), FIRCLK_SB  , setting);
	             LogSnippetMod(rfState,  FIRCLK_SB_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::ABW:                         
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), ABW  , setting);
	             LogSnippetMod(rfState,  ABW_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::TXC_REF:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), TXC_REF  , setting);
	             LogSnippetMod(rfState,  TXC_REF_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::OVS_REF:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]),OVS_REF   , setting);
	             LogSnippetMod(rfState,  OVS_REF_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::TXF_REF:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]),TXF_REF   , setting);
	             LogSnippetMod(rfState,  TXF_REF_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::Q_DCOFS:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), Q_DCOFS  , setting);
	             LogSnippetMod(rfState,  Q_DCOFS_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::I_DCOFS:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]),I_DCOFS   , setting);
	             LogSnippetMod(rfState,  I_DCOFS_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::TX_DCOC_SIGN:                
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]),TX_DCOC_SIGN   , setting);
	             LogSnippetMod(rfState,  TX_DCOC_SIGN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::DCOC_SIGN_EF:                
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), DCOC_SIGN_EF  , setting);
	             LogSnippetMod(rfState,  DCOC_SIGN_EF_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::WFG_REF:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), WFG_REF  , setting);
	             LogSnippetMod(rfState,  WFG_REF_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::GPO_TRIST_ALL:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), GPO_TRIST_ALL  , setting);
	             LogSnippetMod(rfState,  GPO_TRIST_ALL_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::GPO_TRIST6:                  
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), GPO_TRIST6  , setting);
	             LogSnippetMod(rfState,  GPO_TRIST6_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::GPO_TRIST5:                  
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), GPO_TRIST5  , setting);
	             LogSnippetMod(rfState,  GPO_TRIST5_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::GPO_TRIST4:                  
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), GPO_TRIST4  , setting);
	             LogSnippetMod(rfState,  GPO_TRIST4_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::GPO_TRIST3:                  
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), GPO_TRIST3  , setting);
	             LogSnippetMod(rfState,  GPO_TRIST3_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::GPO_TRIST2:                  
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), GPO_TRIST2  , setting);
	             LogSnippetMod(rfState,  GPO_TRIST2_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::GPO_TRIST1:                  
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), GPO_TRIST1  , setting);
	             LogSnippetMod(rfState,  GPO_TRIST1_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::ATT_SSI:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), ATT_SSI  , setting);
	             LogSnippetMod(rfState,  ATT_SSI_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::HP_SEL_BS:                   
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), HP_SEL_BS  , setting);
	             LogSnippetMod(rfState,  HP_SEL_BS_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::DC_CORRECT:                  
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), DC_CORRECT  , setting);
	             LogSnippetMod(rfState,  DC_CORRECT_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::X1DR0:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), X1DR0  , setting);
	             LogSnippetMod(rfState,  X1DR0_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::EN_DLY_MUX:                  
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), EN_DLY_MUX  , setting);
	             LogSnippetMod(rfState,  EN_DLY_MUX_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::X1DR1:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), X1DR1  , setting);
	             LogSnippetMod(rfState,  X1DR1_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::EN_OVS_DLYD:                 
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), EN_OVS_DLYD  , setting);
	             LogSnippetMod(rfState,  EN_OVS_DLYD_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::X1DR2:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), X1DR2  , setting);
	             LogSnippetMod(rfState,  X1DR2_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::SYMB_REF:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), SYMB_REF  , setting);
	             LogSnippetMod(rfState,  SYMB_REF_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::X1DR3:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), X1DR3  , setting);
	             LogSnippetMod(rfState,  X1DR3_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::BSAVE_WG:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), BSAVE_WG  , setting);
	             LogSnippetMod(rfState,  BSAVE_WG_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::BSAVE_I:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), BSAVE_I  , setting);
	             LogSnippetMod(rfState,  BSAVE_I_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::BSAVE_Q:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), BSAVE_Q  , setting);
	             LogSnippetMod(rfState,  BSAVE_Q_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::BSAVE_EF:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), BSAVE_EF  , setting);
	             LogSnippetMod(rfState,  BSAVE_EF_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::X1DR4:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]),X1DR4  , setting);
	             LogSnippetMod(rfState,  X1DR4_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::TX_POS_COMP:                 
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), TX_POS_COMP  , setting);
	             LogSnippetMod(rfState,  TX_POS_COMP_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::TX_NEG_COMP:                 
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), TX_NEG_COMP  , setting);
	             LogSnippetMod(rfState,  TX_NEG_COMP_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::TXCONFIG:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), TXCONFIG  , setting);
	             LogSnippetMod(rfState,  TXCONFIG_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::X1DR5:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), X1DR5  , setting);
	             LogSnippetMod(rfState,  X1DR5_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::DIAG_MODE:                   
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), DIAG_MODE  , setting);
	             LogSnippetMod(rfState,  DIAG_MODE_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::DIAG_INADDR:                 
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), DIAG_INADDR  , setting);
	             LogSnippetMod(rfState,  DIAG_INADDR_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::X2DR0:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), X2DR0  , setting);
	             LogSnippetMod(rfState,  X2DR0_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }         
	      case Trident::DIAG_TX_RX_EN:               
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), DIAG_TX_RX_EN  , setting);
	             LogSnippetMod(rfState,  DIAG_TX_RX_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::DIAG_OUTADDR:                
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), DIAG_OUTADDR  , setting);
	             LogSnippetMod(rfState,  DIAG_OUTADDR_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }            
	      case Trident::X2DR1:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), X2DR1  , setting);
	             LogSnippetMod(rfState,  X2DR1_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::X2DR2:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), X2DR2  , setting);
	             LogSnippetMod(rfState,  X2DR2_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::X2DR3:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), X2DR3  , setting);
	             LogSnippetMod(rfState,  X2DR3_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::X2DR4:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), X2DR4  , setting);
	             LogSnippetMod(rfState,  X2DR4_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::X2DR5:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), X2DR5  , setting);
	             LogSnippetMod(rfState,  X2DR5_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::X3DR0:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), X3DR0  , setting);
	             LogSnippetMod(rfState,  X3DR0_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::X3DR1:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), X3DR1  , setting);
	             LogSnippetMod(rfState,  X3DR1_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::X3DR2:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), X3DR2  , setting);
	             LogSnippetMod(rfState,  X3DR2_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::X3DR3:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), X3DR3  , setting);
	             LogSnippetMod(rfState,  X3DR3_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::X3DR4:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), X3DR4  , setting);
	             LogSnippetMod(rfState,  X3DR4_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::X3DR5:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), X3DR5  , setting);
	             LogSnippetMod(rfState,  X3DR5_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::X4DR0:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), X4DR0  , setting);
	             LogSnippetMod(rfState,  X4DR0_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::X4DR1:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), X4DR1  , setting);
	             LogSnippetMod(rfState,  X4DR1_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::X4DR2:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), X4DR2  , setting);
	             LogSnippetMod(rfState,  X4DR2_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::X4DR3:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), X4DR3  , setting);
	             LogSnippetMod(rfState,  X4DR3_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::X4DR4:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), X4DR4  , setting);
	             LogSnippetMod(rfState,  X4DR4_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::X4DR5:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), X4DR5  , setting);
	             LogSnippetMod(rfState,  X4DR5_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::EF_DC_CORRECT:               
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), EF_DC_CORRECT  , setting);
	             LogSnippetMod(rfState,  EF_DC_CORRECT_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::EF_SEL:                      
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), EF_SEL  , setting);
	             LogSnippetMod(rfState,  EF_SEL_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::GPO_TEST_SEL:                
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), GPO_TEST_SEL  , setting);
	             LogSnippetMod(rfState,  GPO_TEST_SEL_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::TM_BUF:                      
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), TM_BUF  , setting);
	             LogSnippetMod(rfState,  TM_BUF_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::DCOC_REF:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), DCOC_REF  , setting);
	             LogSnippetMod(rfState,  DCOC_REF_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::TEST_MUX:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), TEST_MUX  , setting);
	             LogSnippetMod(rfState,  TEST_MUX_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::DMO:                         
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), DMO  , setting);
	             LogSnippetMod(rfState,  DMO_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::AGC_ATTN_ENUP:               
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), AGC_ATTN_ENUP  , setting);
	             LogSnippetMod(rfState,  AGC_ATTN_ENUP_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::FST_STP:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), FST_STP  , setting);
	             LogSnippetMod(rfState,  FST_STP_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::EF_DLY:                      
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]),EF_DLY   , setting);
	             LogSnippetMod(rfState,  EF_DLY_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::TR_UPPER:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), TR_UPPER  , setting);
	             LogSnippetMod(rfState,  TR_UPPER_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::TR_LOWER:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), TR_LOWER  , setting);
	             LogSnippetMod(rfState,  TR_LOWER_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::I_DAC_HOLD:                  
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), I_DAC_HOLD  , setting);
	             LogSnippetMod(rfState,  I_DAC_HOLD_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::Q_DAC_HOLD:                  
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), Q_DAC_HOLD  , setting);
	             LogSnippetMod(rfState,  Q_DAC_HOLD_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::DAC_SEL:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), DAC_SEL  , setting);
	             LogSnippetMod(rfState,  DAC_SEL_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::DAC_WORD:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), DAC_WORD  , setting);
	             LogSnippetMod(rfState,  DAC_WORD_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::DCOC_LPF_BW:                 
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), DCOC_LPF_BW  , setting);
	             LogSnippetMod(rfState,  DCOC_LPF_BW_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::DCOCL_HOLD:                  
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), DCOCL_HOLD  , setting);
	             LogSnippetMod(rfState,  DCOCL_HOLD_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::QDC_DAC:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), QDC_DAC  , setting);
	             LogSnippetMod(rfState,  QDC_DAC_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::DC_DAC_GM:                   
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), DC_DAC_GM  , setting);
	             LogSnippetMod(rfState,  DC_DAC_GM_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::IDC_DAC:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), IDC_DAC  , setting);
	             LogSnippetMod(rfState,  IDC_DAC_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::SM_AGC_EN:                   
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), SM_AGC_EN  , setting);
	             LogSnippetMod(rfState,  SM_AGC_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::NBMUX:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), NBMUX  , setting);
	             LogSnippetMod(rfState,  NBMUX_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::FHP3:                        
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), FHP3  , setting);
	             LogSnippetMod(rfState,  FHP3_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::THP1:                        
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), THP1  , setting);
	             LogSnippetMod(rfState,  THP1_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::THP2:                        
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), THP2  , setting);
	             LogSnippetMod(rfState,  THP2_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::KDLPT:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), KDLPT  , setting);
	             LogSnippetMod(rfState,  KDLPT_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::PMA_BP:                      
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), PMA_BP  , setting);
	             LogSnippetMod(rfState,  PMA_BP_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::DBW:                         
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), DBW  , setting);
	             LogSnippetMod(rfState,  DBW_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::AB_SEL:                      
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), AB_SEL  , setting);
	             LogSnippetMod(rfState,  AB_SEL_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::SSI_TS:                      
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), SSI_TS  , setting);
	             LogSnippetMod(rfState,  SSI_TS_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::PMA_BIAS:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), PMA_BIAS  , setting);
	             LogSnippetMod(rfState,  PMA_BIAS_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::SD_MODE:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), SD_MODE  , setting);
	             LogSnippetMod(rfState,  SD_MODE_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::FHP1:                        
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), FHP1  , setting);
	             LogSnippetMod(rfState,  FHP1_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::FHP2:                        
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), FHP2  , setting);
	             LogSnippetMod(rfState,  FHP2_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::RXSDL_HI_C:                  
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), RXSDL_HI_C , setting);
	             LogSnippetMod(rfState,  RXSDL_HI_C_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::TRK_HIGH:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), TRK_HIGH  , setting);
	             LogSnippetMod(rfState,  TRK_HIGH_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::FREE_RUN:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), FREE_RUN  , setting);
	             LogSnippetMod(rfState,  FREE_RUN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }      
	      case Trident::TRK_LOW:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), TRK_LOW  , setting);
	             LogSnippetMod(rfState,  TRK_LOW_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::DEC_DIV:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), DEC_DIV  , setting);
	             LogSnippetMod(rfState,  DEC_DIV_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::RXDIG_DIV:                   
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), RXDIG_DIV  , setting);
	             LogSnippetMod(rfState,  RXDIG_DIV_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::AGC_CLK:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), AGC_CLK  , setting);
	             LogSnippetMod(rfState,  AGC_CLK_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::ADPT_DLY_TMR:                
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), ADPT_DLY_TMR  , setting);
	             LogSnippetMod(rfState,  ADPT_DLY_TMR_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::BS_DLY_TMR:                  
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), BS_DLY_TMR  , setting);
	             LogSnippetMod(rfState,  BS_DLY_TMR_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::STEP_OFFSET:                 
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), STEP_OFFSET  , setting);
	             LogSnippetMod(rfState,  STEP_OFFSET_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::STEP_THRESH:                 
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), STEP_THRESH  , setting);
	             LogSnippetMod(rfState,  STEP_THRESH_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::RXSC_SEL:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), RXSC_SEL  , setting);
	             LogSnippetMod(rfState,  RXSC_SEL_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::STEP_SLOT:                   
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), STEP_SLOT  , setting);
	             LogSnippetMod(rfState,  STEP_SLOT_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::FE_OFF_A:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), FE_OFF_A  , setting);
	             LogSnippetMod(rfState,  FE_OFF_A_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::AGC_MAX_A:                   
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), AGC_MAX_A  , setting);
	             LogSnippetMod(rfState,  AGC_MAX_A_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::DC_CALEN:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), DC_CALEN  , setting);
	             LogSnippetMod(rfState,  DC_CALEN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::SEQMGR_EN:                   
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), SEQMGR_EN  , setting);
	             LogSnippetMod(rfState,  SEQMGR_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::AGCFLAGEN:                   
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), AGCFLAGEN  , setting);
	             LogSnippetMod(rfState,  AGCFLAGEN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::FBC_TMR:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), FBC_TMR  , setting);
	             LogSnippetMod(rfState,  FBC_TMR_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::AGC_STEP_CMP:                
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), AGC_STEP_CMP  , setting);
	             LogSnippetMod(rfState,  AGC_STEP_CMP_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::BB2P_Q:                      
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), BB2P_Q  , setting);
	             LogSnippetMod(rfState,  BB2P_Q_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::BW:                          
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]),BW   , setting);
	             LogSnippetMod(rfState,  BW_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR; 
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::AGCLVL:                      
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), AGCLVL  , setting);
	             LogSnippetMod(rfState,  AGCLVL_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::NAGC_DIV:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), NAGC_DIV  , setting);
	             LogSnippetMod(rfState,  NAGC_DIV_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::FAGC_DIV:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), FAGC_DIV  , setting);
	             LogSnippetMod(rfState,  FAGC_DIV_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::FAGC_STEPS:                  
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]),FAGC_STEPS   , setting);
	             LogSnippetMod(rfState,  FAGC_STEPS_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::RAGC_DIV:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), RAGC_DIV  , setting);
	             LogSnippetMod(rfState,  RAGC_DIV_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::RAGC_PHASE:                  
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), RAGC_PHASE  , setting);
	             LogSnippetMod(rfState,  RAGC_PHASE_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::AGC_DAC_MODE:                
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), AGC_DAC_MODE  , setting);
	             LogSnippetMod(rfState,  AGC_DAC_MODE_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::RF_STEPEN:                   
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]),RF_STEPEN   , setting);
	             LogSnippetMod(rfState,  RF_STEPEN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::AUTO_AGC:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), AUTO_AGC  , setting);
	             LogSnippetMod(rfState,  AUTO_AGC_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::CIC_OFFSET:                  
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), CIC_OFFSET  , setting);
	             LogSnippetMod(rfState,  CIC_OFFSET_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::AUX_DACBIT0:                 
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0, 1, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), AUX_DACBIT0  , setting);
	             LogSnippetMod(rfState,  AUX_DACBIT0_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::HPDC_HOLD:                   
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), HPDC_HOLD  , setting);
	             LogSnippetMod(rfState,  HPDC_HOLD_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::AGC_DAC_VREF:                
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), AGC_DAC_VREF  , setting);
	             LogSnippetMod(rfState,  AGC_DAC_VREF_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::AGCHIGH:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), AGCHIGH  , setting);
	             LogSnippetMod(rfState,  AGCHIGH_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::AUX_DACBIT10_1:              
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0x3FF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), AUX_DACBIT10_1  , setting);
	             LogSnippetMod(rfState,  AUX_DACBIT10_1_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }
	      // trident uses aux_dac for warping of the external 16.8Mhz vco....to adjust frequency slightly   
	      case Trident::AUX_DAC:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0x7FF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), AUX_DACBIT0  , (setting & 0x01));
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), AUX_DACBIT10_1  , (setting >> 1) );
	             LogSnippetMod(rfState,  AUX_DACBIT10_1_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 

	        {    
			     returnvalue = rdRegister(TRIDENT_ADDR2C, rfState);

			     if( (returnvalue & 0x8000) == 0x8000) // if D15 AKA AUX_DAC[0] is set
				 {
				    returnvalue = ((returnvalue << 1) | 1) & 0x7FF;				
				 }
				 else
				 {
				 	returnvalue = ((returnvalue << 1) ) & 0x7FE;
				 } 
				  

	 			 m_error = TRIDENT_ERRCODE_NOERR;
	        }

	        break;
	      }          
	      case Trident::MREF_DIV:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), MREF_DIV  , setting);
	             LogSnippetMod(rfState,  MREF_DIV_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	            returnvalue = getBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), MREF_DIV );
				m_error = TRIDENT_ERRCODE_NOERR;
	        }

	        break;
	      }          
	      case Trident::MADP_TMR:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]),  MADP_TMR , setting);
	             LogSnippetMod(rfState,  MADP_TMR_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::VMULT_SEL:                   
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]),VMULT_SEL   , setting);
	             LogSnippetMod(rfState,  VMULT_SEL_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::MCP_GAIN:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), MCP_GAIN  , setting);
	             LogSnippetMod(rfState,  MCP_GAIN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::MCPTEST:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]),MCPTEST   , setting);
	             LogSnippetMod(rfState,  MCPTEST_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::CLK_ACC:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), CLK_ACC  , setting);
	             LogSnippetMod(rfState,  CLK_ACC_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::MLBPRCS_SEL:                 
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), MLBPRCS_SEL  , setting);
	             LogSnippetMod(rfState,  MLBPRCS_SEL_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::CLK_IN_SEL:                  
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), CLK_IN_SEL  , setting);
	             LogSnippetMod(rfState,  CLK_IN_SEL_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::MACC:                        
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0x1F, setting); // 5 bits     


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), MACC  , setting);
	             LogSnippetMod(rfState,  MACC_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	            returnvalue = getBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), MACC );
				m_error = TRIDENT_ERRCODE_NOERR;
	        }

	        break;
	      }          
	      case Trident::CLK_NUM_16_23:               
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), CLK_NUM_16_23  , setting);
	             LogSnippetMod(rfState,  CLK_NUM_16_23_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::CLK_NUM:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	               badArg = errorCheckParams(0x00, 0xFFFFFF, setting);  


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), CLK_NUM  , setting);
	             LogSnippetMod(rfState,  CLK_NUM_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::CLK_NUM_0_15:                
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), CLK_NUM_0_15  , setting);
	             LogSnippetMod(rfState,  CLK_NUM_0_15_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::CLK_R:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), CLK_R  , setting);
	             LogSnippetMod(rfState,  CLK_R_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::CLK_N:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), CLK_N  , setting);
	             LogSnippetMod(rfState,  CLK_N_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::MN_SYN_TRK_SEL:              
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), MN_SYN_TRK_SEL  , setting);
	             LogSnippetMod(rfState,  MN_SYN_TRK_SEL_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::TCLK_DIV:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), TCLK_DIV  , setting);
	             LogSnippetMod(rfState,  TCLK_DIV_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::TCLK_DIV_SEL:                
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), TCLK_DIV_SEL  , setting);
	             LogSnippetMod(rfState,  TCLK_DIV_SEL_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::VMULT_DIV:                   
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), VMULT_DIV  , setting);
	             LogSnippetMod(rfState,  VMULT_DIV_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::CLK_DIV:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), CLK_DIV  , setting);
	             LogSnippetMod(rfState,  CLK_DIV_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::CLKCP_TEST:                  
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), CLKCP_TEST  , setting);
	             LogSnippetMod(rfState,  CLKCP_TEST_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::ESC_DIVSEL:                  
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), ESC_DIVSEL  , setting);
	             LogSnippetMod(rfState,  ESC_DIVSEL_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::ES_STEER_EN:                 
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), ES_STEER_EN  , setting);
	             LogSnippetMod(rfState,  ES_STEER_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::ES_BIAS_EN:                  
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), ES_BIAS_EN  , setting);
	             LogSnippetMod(rfState,  ES_BIAS_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::ES_DIV_TEST:                 
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), ES_DIV_TEST  , setting);
	             LogSnippetMod(rfState,  ES_DIV_TEST_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::ES_SEL1:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), ES_SEL1  , setting);
	             LogSnippetMod(rfState,  ES_SEL1_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::ES_CP_EN:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), ES_CP_EN  , setting);
	             LogSnippetMod(rfState,  ES_CP_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::ES_D16_BYP:                  
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), ES_D16_BYP  , setting);
	             LogSnippetMod(rfState,  ES_D16_BYP_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::ES_NUD_BYP:                  
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), ES_NUD_BYP  , setting);
	             LogSnippetMod(rfState,  ES_NUD_BYP_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::ES_NUD_MUL_BYP:              
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), ES_NUD_MUL_BYP  , setting);
	             LogSnippetMod(rfState,  ES_NUD_MUL_BYP_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::ES_SEL3:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), ES_SEL3  , setting);
	             LogSnippetMod(rfState,  ES_SEL3_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::ES_VCO_STEER:                
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), ES_VCO_STEER  , setting);
	             LogSnippetMod(rfState,  ES_VCO_STEER_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::ESD2_EN:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), ESD2_EN  , setting);
	             LogSnippetMod(rfState,  ESD2_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::ES_CP_BIAS_EN:               
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), ES_CP_BIAS_EN  , setting);
	             LogSnippetMod(rfState,  ES_CP_BIAS_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::ES_NUD_EN:                   
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), ES_NUD_EN  , setting);
	             LogSnippetMod(rfState,  ES_NUD_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::ADAPT:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), ADAPT  , setting);
	             LogSnippetMod(rfState,  ADAPT_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::RX_DIG_BS:                   
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), RX_DIG_BS  , setting);
	             LogSnippetMod(rfState,  RX_DIG_BS_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::AGC_BS:                      
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), AGC_BS  , setting);
	             LogSnippetMod(rfState,  AGC_BS_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::SD_BS:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), SD_BS  , setting);
	             LogSnippetMod(rfState,  SD_BS_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::FE_EN:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), FE_EN  , setting);
	             LogSnippetMod(rfState,  FE_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::RX_BB_BS:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), RX_BB_BS  , setting);
	             LogSnippetMod(rfState,  RX_BB_BS_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::TRACK_OSCEN:                 
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), TRACK_OSCEN  , setting);
	             LogSnippetMod(rfState,  TRACK_OSCEN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::AGC_DAC:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), AGC_DAC  , setting);
	             LogSnippetMod(rfState,  AGC_DAC_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::SSI_MODE:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), SSI_MODE  , setting);
	             LogSnippetMod(rfState,  SSI_MODE_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::RF_STEP:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), RF_STEP  , setting);
	             LogSnippetMod(rfState,  RF_STEP_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::FAST_AGC:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]),FAST_AGC   , setting);
	             LogSnippetMod(rfState,  FAST_AGC_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::AGC_PRELOAD:                 
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), AGC_PRELOAD  , setting);
	             LogSnippetMod(rfState,  AGC_PRELOAD_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::ADAPTEN:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), ADAPTEN  , setting);
	             LogSnippetMod(rfState,  ADAPTEN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::RX_BS:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), RX_BS  , setting);
	             LogSnippetMod(rfState,  RX_BS_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::PMA_AGC:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), PMA_AGC  , setting);
	             LogSnippetMod(rfState,  PMA_AGC_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          

	      case Trident::AMP_AGC:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // settings are in db, valid settings are 3db,5db,7db,9db,11db,13db,15db,17db
	           // Verify valid parameter range, returns false if ok
	           //                        min   max     setting  increment
	           badArg = errorCheckParams(3, 17, setting, 2);      

	           if( badArg == false )
	           {

		      	   // determine attribute based on gain value (dB resolution)
			   // AGC gain steps of the IF amp

			  switch(setting)
			  {
				case ((int)17):
				
					setting = 0;  // AMP_AGC= 000
				break;

				case ((int)15):
				
					setting = 1;  // AMP_AGC= 001
				break;

				case ((int)13):
				
					setting = 2;  // AMP_AGC= 010
				break;

				case ((int)11):
				
					setting = 3;  // AMP_AGC= 011
				break;

				case ((int)9):
				
					setting = 4;  // AMP_AGC= 100
				break;

				case ((int)7):
				
					setting = 5;  // AMP_AGC= 101
				break;

				case ((int)5):
				
					setting = 6;  // AMP_AGC= 110
				break;

				case ((int)3):
				
					setting = 7;  // AMP_AGC= 111
				break;
			  }  
			             
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), AMP_AGC  , setting);
	             LogSnippetMod(rfState,  AMP_AGC_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::BUFGAIN:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                        min  max  setting, increment
	           badArg = errorCheckParams(0,    12, setting, 3);      

	           if( badArg == false )
	           {
	           	
			  switch(setting)
			  {
		  		// BUFGAIN[2:0]=111	12db
				// BUFGAIN[2:0]=110	12db
				// BUFGAIN[2:0]=101	12db
				// BUFGAIN[2:0]=100	12db
				case ((int)12):
				
					setting = 4;
				break;
				
				// BUFGAIN[2:0]=011	9db
				case ((int)9):
				
					setting = 3;
				break;

				// BUFGAIN[2:0]=010	6db
				case ((int)6):
				
					setting = 2;
				break;
				
				// BUFGAIN[2:0]=001	3db
				case ((int)3):
				
					setting = 1;
				break;

	                        // BUFGAIN[2:0]=000	0db
				case ((int)0):
				
					setting = 0;
				break;

			  }
			             	
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), BUFGAIN  , setting);
	             LogSnippetMod(rfState,  BUFGAIN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          

	      case Trident::RXSM_ASPI_EN:                
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), RXSM_ASPI_EN  , setting);
	             LogSnippetMod(rfState,  RXSM_ASPI_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::SYN_ADAPTEN:                 
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), SYN_ADAPTEN  , setting);
	             LogSnippetMod(rfState,  SYN_ADAPTEN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::BSAVE_ALL:                   
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), BSAVE_ALL  , setting);
	             LogSnippetMod(rfState,  BSAVE_ALL_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::BSAVE_SYN_ALL:               
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), BSAVE_SYN_ALL  , setting);
	             LogSnippetMod(rfState,  BSAVE_SYN_ALL_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::BSAVE_MAIN_SYN:              
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), BSAVE_MAIN_SYN  , setting);
	             LogSnippetMod(rfState,  BSAVE_MAIN_SYN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::MFADJ:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), MFADJ  , setting);
	             LogSnippetMod(rfState,  MFADJ_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::MAINNUM_16_23:               
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), MAINNUM_16_23  , setting);
	             LogSnippetMod(rfState,  MAINNUM_16_23_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::MAINNUM:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	               badArg = errorCheckParams(0x00, 0xFFFFFF, setting);  


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), MAINNUM  , setting);
	             LogSnippetMod(rfState,  MAINNUM_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	             returnvalue = getBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), MAINNUM );
				 m_error = TRIDENT_ERRCODE_NOERR;
	        }

	        break;
	      }          
	      case Trident::MAINNUM_0_15:                
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), MAINNUM_0_15  , setting);
	             LogSnippetMod(rfState,  MAINNUM_0_15_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::MNLDADJ:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), MNLDADJ  , setting);
	             LogSnippetMod(rfState,  MNLDADJ_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::ADPT_TRKL_EN:                
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), ADPT_TRKL_EN  , setting);
	             LogSnippetMod(rfState,  ADPT_TRKL_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::VSUP_OUT:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), VSUP_OUT  , setting);
	             LogSnippetMod(rfState,  VSUP_OUT_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::MAINND:                      
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), MAINND  , setting);
	             LogSnippetMod(rfState,  MAINND_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::GPO:                         
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), GPO  , setting);
	             LogSnippetMod(rfState,  GPO_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::GPO_8:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(TRIDENT_GPO_LOW, TRIDENT_GPO_HIGH, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), GPO_8  , setting);
	             LogSnippetMod(rfState,  GPO_8_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::GPO_7:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(TRIDENT_GPO_LOW, TRIDENT_GPO_HIGH, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), GPO_7  , setting);
	             LogSnippetMod(rfState,  GPO_7_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::GPO_6:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(TRIDENT_GPO_LOW, TRIDENT_GPO_HIGH, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), GPO_6  , setting);
	             LogSnippetMod(rfState,  GPO_6_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::GPO_5:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(TRIDENT_GPO_LOW, TRIDENT_GPO_HIGH, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), GPO_5  , setting);
	             LogSnippetMod(rfState,  GPO_5_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::GPO_4:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(TRIDENT_GPO_LOW, TRIDENT_GPO_HIGH, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), GPO_4  , setting);
	             LogSnippetMod(rfState,  GPO_4_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::GPO_3:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(TRIDENT_GPO_LOW, TRIDENT_GPO_HIGH, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]),GPO_3   , setting);
	             LogSnippetMod(rfState,  GPO_3_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::GPO_2:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(TRIDENT_GPO_LOW, TRIDENT_GPO_HIGH, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), GPO_2  , setting);
	             LogSnippetMod(rfState,  GPO_2_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::GPO_1:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(TRIDENT_GPO_LOW, TRIDENT_GPO_HIGH, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]),  GPO_1 , setting);
	             LogSnippetMod(rfState,  GPO_1_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::BSAVE_ESCORT:                
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), BSAVE_ESCORT  , setting);
	             LogSnippetMod(rfState,  BSAVE_ESCORT_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::ES_SEL2:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]),  ES_SEL2 , setting);
	             LogSnippetMod(rfState,  ES_SEL2_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::NUD:                         
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), NUD  , setting);
	             LogSnippetMod(rfState,  NUD_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::ATTEN_I:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), ATTEN_I  , setting);
	             LogSnippetMod(rfState,  ATTEN_I_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::ATTEN_Q:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), ATTEN_Q  , setting);
	             LogSnippetMod(rfState,  ATTEN_Q_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::BSAVE_TX:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), BSAVE_TX  , setting);
	             LogSnippetMod(rfState,  BSAVE_TX_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::CEFBEN:                      
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), CEFBEN  , setting);
	             LogSnippetMod(rfState,  CEFBEN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::BSAVE_TXR:                   
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), BSAVE_TXR  , setting);
	             LogSnippetMod(rfState,  BSAVE_TXR_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::DC_UPDATE:                   
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), DC_UPDATE  , setting);
	             LogSnippetMod(rfState,  DC_UPDATE_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::EF_DC_UPDATE:                
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), EF_DC_UPDATE  , setting);
	             LogSnippetMod(rfState,  EF_DC_UPDATE_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }
		            
	      case Trident::STATT_IQ:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                       min  max setting
	           badArg = errorCheckParams(-9, 6,  setting);      


	           if( badArg == false )
	           {
	           	
		     switch(setting)
		     {
			     case ((int)-9):
				    setting = 15;
			     break;

			     case ((int)-8):
				    setting = 14;
			     break;

			     case ((int)-7):
				    setting = 13;
			     break;

			     case ((int)-6):
				    setting = 12;
			     break;

			     case ((int)-5):
				    setting = 11;
			     break;

			     case ((int)-4):
				    setting = 10;
			     break;

			     case ((int)-3):
				    setting = 9;
			     break;

			     case ((int)-2):
				    setting = 8;
			     break;

			     case ((int)-1):
				    setting = 7;
			     break;

			     case ((int)0):
				    setting = 6;
			     break;

			     case ((int)1):
				    setting = 5;
			     break;

			     case ((int)2):
				    setting = 4;
			     break;

			     case ((int)3):
				    setting = 3;
				 break;
				 	     
			     case ((int)4):
				    setting = 2;
			     break;

			     case ((int)5):
				    setting = 1;
			     break;

			     case ((int)6):
				    setting = 0;
			     break;

	             }
		           	
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), STATT_IQ  , setting);
	             LogSnippetMod(rfState,  STATT_IQ_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	}   
	       
	      case Trident::STATT_EF:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                       min  max setting
	           badArg = errorCheckParams(-9, 6,  setting);      


	           if( badArg == false )
	           {
	           	
	             switch(setting)
	             {

			     case ((int)-9):
				    setting = 15;
			     break;

			     case ((int)-8):
				    setting = 14;
			     break;

			     case ((int)-7):
				    setting = 13;
			     break;

			     case ((int)-6):
				    setting = 12;
			     break;

			     case ((int)-5):
				    setting = 11;
			     break;

			     case ((int)-4):
				    setting = 10;
			     break;

			     case ((int)-3):
				    setting = 9;
			     break;

			     case ((int)-2):
				    setting = 8;
			     break;

			     case ((int)-1):
				    setting = 7;
			     break;

			     case ((int)0):
				    setting = 6;
			     break;

			     case ((int)1):
				    setting = 5;
			     break;

			     case ((int)2):
				    setting = 4;
			     break;

			     case ((int)3):
				    setting = 3;
			     break;

			     case ((int)4):
				    setting = 2;
			     break;

			     case ((int)5):
				    setting = 1;
			     break;

			     case ((int)6):
					setting = 0;
	               break;

	             } 
		         	
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), STATT_EF  , setting);
	             LogSnippetMod(rfState,  STATT_EF_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
		           
	      case Trident::NTXBW:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), NTXBW  , setting);
	             LogSnippetMod(rfState,  NTXBW_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::PWRCTL:                      
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), PWRCTL  , setting);
	             LogSnippetMod(rfState,  PWRCTL_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::GPO5_EN:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), GPO5_EN  , setting);
	             LogSnippetMod(rfState,  GPO5_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::GPO6_EN:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]),  GPO6_EN , setting);
	             LogSnippetMod(rfState,  GPO6_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::GPO7_EN:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), GPO7_EN  , setting);
	             LogSnippetMod(rfState,  GPO7_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::GPO8_EN:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), GPO8_EN  , setting);
	             LogSnippetMod(rfState,  GPO8_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::A0_ENV:                      
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), A0_ENV  , setting);
	             LogSnippetMod(rfState,  A0_ENV_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::A1_ENV:                      
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), A1_ENV  , setting);
	             LogSnippetMod(rfState,  A1_ENV_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::SSI_DRV:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), SSI_DRV  , setting);
	             LogSnippetMod(rfState,  SSI_DRV_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::AUXCEPOL:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), AUXCEPOL  , setting);
	             LogSnippetMod(rfState,  AUXCEPOL_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::A2_ENV:                      
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]),A2_ENV  , setting);
	             LogSnippetMod(rfState,  A2_ENV_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::RX_EVENT1:                   
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), RX_EVENT1  , setting);
	             LogSnippetMod(rfState,  RX_EVENT1_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::RX_EVENT2:                   
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), RX_EVENT2  , setting);
	             LogSnippetMod(rfState,  RX_EVENT2_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::REFIN_DS_EN:                 
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), REFIN_DS_EN  , setting);
	             LogSnippetMod(rfState,  REFIN_DS_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }            
	      case Trident::REF_OSC_OUT_DS_EN:           
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), REF_OSC_OUT_DS_EN  , setting);
	             LogSnippetMod(rfState,  REF_OSC_OUT_DS_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }            
	      case Trident::AUXDAC_DS_EN:                
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), AUXDAC_DS_EN  , setting);
	             LogSnippetMod(rfState,  AUXDAC_DS_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }            
	      case Trident::SF_OUT_DS_EN:                
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), SF_OUT_DS_EN  , setting);
	             LogSnippetMod(rfState,  SF_OUT_DS_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }            
	      case Trident::CLK_SYN_DS_EN:               
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), CLK_SYN_DS_EN  , setting);
	             LogSnippetMod(rfState,  CLK_SYN_DS_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }            
	      case Trident::VMULT_DS_EN:                 
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), VMULT_DS_EN  , setting);
	             LogSnippetMod(rfState,  VMULT_DS_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }            
	      case Trident::CLK_OUT_DS_EN:               
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), CLK_OUT_DS_EN  , setting);
	             LogSnippetMod(rfState,  CLK_OUT_DS_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }           
	      case Trident::TCLK_OUT_DS_EN:              
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), TCLK_OUT_DS_EN  , setting);
	             LogSnippetMod(rfState,  TCLK_OUT_DS_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }            
	      case Trident::REFIN_EN:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), REFIN_EN  , setting);
	             LogSnippetMod(rfState,  REFIN_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }            
	      case Trident::REF_OSC_OUT_EN:              
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]),REF_OSC_OUT_EN   , setting);
	             LogSnippetMod(rfState,  REF_OSC_OUT_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }            
	      case Trident::AUXDAC_EN:                   
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), AUXDAC_EN  , setting);
	             LogSnippetMod(rfState,  AUXDAC_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }            
	      case Trident::SF_OUT_EN:                   
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), SF_OUT_EN  , setting);
	             LogSnippetMod(rfState,  SF_OUT_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }           
	      case Trident::CLK_SYN_EN:                  
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), CLK_SYN_EN  , setting);
	             LogSnippetMod(rfState,  CLK_SYN_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }            
	      case Trident::VMULT_EN:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), VMULT_EN  , setting);
	             LogSnippetMod(rfState,  VMULT_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }            
	      case Trident::CLK_OUT_EN:                  
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), CLK_OUT_EN  , setting);
	             LogSnippetMod(rfState,  CLK_OUT_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }            
	      case Trident::TCLK_OUT_EN:                 
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), TCLK_OUT_EN  , setting);
	             LogSnippetMod(rfState,  TCLK_OUT_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::AGC_NAGC_DIV0:               
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]),  AGC_NAGC_DIV0 , setting);
	             LogSnippetMod(rfState,  AGC_NAGC_DIV0_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }             
	      case Trident::AGC_NAGC_DIV1:               
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), AGC_NAGC_DIV1  , setting);
	             LogSnippetMod(rfState,  AGC_NAGC_DIV1_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }             
	      case Trident::AGC_NAGC_DIV2:               
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), AGC_NAGC_DIV2  , setting);
	             LogSnippetMod(rfState,  AGC_NAGC_DIV2_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }              
	      case Trident::AGC_NAGC_3DIV_EN:            
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), AGC_NAGC_3DIV_EN  , setting);
	             LogSnippetMod(rfState,  AGC_NAGC_3DIV_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }            
	      case Trident::AGC_CLK_DIV_MSB:             
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), AGC_CLK_DIV_MSB  , setting);
	             LogSnippetMod(rfState,  AGC_CLK_DIV_MSB_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }             
	      case Trident::RX4GEN:                      
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), RX4GEN  , setting);
	             LogSnippetMod(rfState,  RX4GEN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::AGC_LOW:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), AGC_LOW  , setting);
	             LogSnippetMod(rfState,  AGC_LOW_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }             
	      case Trident::AGC_SOS_THRESH0:             
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), AGC_SOS_THRESH0  , setting);
	             LogSnippetMod(rfState,  AGC_SOS_THRESH0_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }             
	      case Trident::AGC_PROG_THRESH_EN:          
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), AGC_PROG_THRESH_EN  , setting);
	             LogSnippetMod(rfState,  AGC_PROG_THRESH_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }             
	      case Trident::AGC_SOS_THRESH1:             
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), AGC_SOS_THRESH1  , setting);
	             LogSnippetMod(rfState,  AGC_SOS_THRESH1_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::AGC_SOS_THRESH2:             
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), AGC_SOS_THRESH2  , setting);
	             LogSnippetMod(rfState,  AGC_SOS_THRESH2_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }          
	      case Trident::DIV_SEL:                     
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), DIV_SEL  , setting);
	             LogSnippetMod(rfState,  DIV_SEL_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }               
	      case Trident::JITTER_EN:                   
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), JITTER_EN  , setting);
	             LogSnippetMod(rfState,  JITTER_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }            
	      case Trident::CNTR_EN:                    
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), CNTR_EN  , setting);
	             LogSnippetMod(rfState,  CNTR_EN_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }            
	      case Trident::HB_LB:                       
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {  
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), HB_LB  , setting);
	             LogSnippetMod(rfState,  HB_LB_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      }        
	      case Trident::REF_DEL:
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {                                      
	           // Verify valid parameter range, returns false if ok
	           //                      min   max     setting
	           badArg = errorCheckParams(0x00, 0xFFFF, setting);      


	           if( badArg == false )
	           {
	             setBitField( &((*m_rfSpiBuffer[rfState])[TRIDENT_SPI_HEADER_SIZE]), REF_DEL  , setting);
	             LogSnippetMod(rfState,  REF_DEL_RegToSnippet);
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = TRIDENT_ERRCODE_NOERR;  
	           }
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         // read to be done
	        }

	        break;
	      } 
		  // gets the error code.
	      case Trident::M_ERROR:
	      {
	        if(readORwrite == TRIDENT_WRITE)
	        {                                      
	             returnvalue = TRIDENT_ERRCODE_NOERR; // signifies success
	             m_error = setting;  
	           
	        }
	        else //readORwrite == TRIDENT_READ 
	        {
	         returnvalue = m_error;
	        }

	        break;
	      }    
	      default:
	      {
	           // invalid deviceId
	           returnvalue = TRIDENT_ERRCODE_BADARG_DEVICEID;
		       m_error = TRIDENT_ERRCODE_BADARG_DEVICEID;
	        break;
	      }

	  }  // END - switch

	  // if a write to the IC is specified and the argument checking was good, then write to IC.
	  if( (imageORIC == TRIDENT_ACCESS_IC) && (m_error == TRIDENT_ERRCODE_NOERR) )
	  {
	   setRFState(rfState);
	  }

	} // end if( (rfState >= 0 ) && (rfState <= m_numberOfRfStates) )
	else
	{
	  // rfState is invalid
	  returnvalue = TRIDENT_ERRCODE_BADARG_RFSTATE;
	  m_error = TRIDENT_ERRCODE_BADARG_RFSTATE;
	}



	return returnvalue;
	// }}}USR
}
// }}}RME

// {{{RME operation 'errorCheckParams(int,int,int,int)'
bool Trident::errorCheckParams( int min, int max, int setting, int increment )
{
	// {{{USR

	bool badArg = true;

	if(increment == 1)
	{
	  // if setting is in range, return it
	  if( (setting >= min) && (setting <= max)  )
	  badArg = false;
	}
	else  // increment is > 1
	{
	  for( int i = min; i <= max; i +=increment )
	  {
	     if( setting == i) // search for the setting 
		 {
	        badArg = false;
			break;
		 }
	  }  

	}


	return badArg;
	// }}}USR
}
// }}}RME

// {{{RME operation 'internalReadBack()'
SIntArray * Trident::internalReadBack( void )
{
	// {{{USR

	SIntArray * txbuf = new SIntArray(6,(int16_t)0);
	SIntArray * rxbuf = 0;
	 
	// write the 8 bit address/mode header required by all Trident SPI transactions.
	// the remaining data is dummy stuff required for clocking out the correct length
	// and the fact that contents are uninitialized is ok
	(*txbuf)[0] = TRIDENT_INTERNAL_READ;

	// perform the send necessary to clock in the data.
	rxbuf = sendAndReceiveSPI(txbuf);   

	if(rxbuf != 0) // successful send must return null
	{
	  delete txbuf; // cleanup unconsumed buffer.
	}
	else
	{
	  rxbuf = sendAndReceiveSPI(); // perform the receive
	}

	return rxbuf;

	// }}}USR
}
// }}}RME

// {{{RME operation 'sendAndReceiveSPI(SIntArray *)'
SIntArray * Trident::sendAndReceiveSPI( SIntArray * buf )
{
	// {{{USR
	SIntArray * buffer = 0;

	// get the connection reference from the first spibuffer. There must always be at least one
	// rfstate
	Connection * connectionHandle = m_rfSpiBuffer[0]->getConnection();

	if( connectionHandle != 0 ) // insure handle is valid
	{

	 // if buf is nonzero then send operation is to be performed
	 if( buf != 0 )
	 {
	  buffer = buf;

	  // set descriptor to skip (dont send) the first 8 bits of data in index 0 of the array.
	  // this is required because the first 8 bits received by the trident MUST be the address header
	  // but the first index in buf is an int16_t.  The SPI peripheral driver examines the array
	  // descriptor and will process accordingly.
	  buffer->setDescriptor( new Omap1610Spi::SIntDesc(true,false) );

	  bool retstatus = connectionHandle->send(buffer);

	  // null the pointer since its been consumed and the pointer is being returned.
	  if( retstatus == true)
	  {
	   buffer = 0;
	   m_error = TRIDENT_ERRCODE_NOERR;
	  } 

	 }
	 else
	 {
	  // receive
	  buffer = (SIntArray *)connectionHandle->receive();

	  if( buffer == 0 )
	  { 
	    m_error = TRIDENT_ERRCODE_CONNSPI;
	  }
	  else
	  {
	    m_error = TRIDENT_ERRCODE_NOERR;
	  }
	 }

	}
	else
	{
	  m_error = TRIDENT_ERRCODE_CONNSPI;
	}

	return buffer;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'tridentSettingsEnum_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'tridentBitFieldEnum_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
