// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::genericTests::genericTestsMOTICs::genericTestsLVFracN::genericTestLVFracN'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "genericTestLVFracN.h"
#endif

#include <HALtestLib_win32.h>
#include <genericTestLVFracN.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
genericTestLVFracN::genericTestLVFracN( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
genericTestLVFracN::~genericTestLVFracN( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
genericTestLVFracN::genericTestLVFracN( const genericTestLVFracN & rtg_arg )
	: genericTestBase( rtg_arg )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
genericTestLVFracN & genericTestLVFracN::operator=( const genericTestLVFracN & rtg_arg )
{
	if( this != &rtg_arg )
		genericTestBase::operator=( rtg_arg );
	return *this;
}
// }}}RME

// {{{RME operation 'execute(genericTestBase::testConfig *)'
genericTestBase::testResult * genericTestLVFracN::execute( genericTestBase::testConfig * config )
{
	// {{{USR

	   targetConfigBase::sendStringToStderr("genericTestLvFracN execute() method!\n");

	return 0;
	// }}}USR
}
// }}}RME

// {{{RME operation 'init(genericTestBase::initConfig *)'
genericTestBase::initResult * genericTestLVFracN::init( genericTestBase::initConfig * config )
{
	// {{{USR

	if( config != 0)
	{
	  m_initConfig_ptr = config;

	  config->m_targetConfig->init();
	}

	return 0;
	// }}}USR
}
// }}}RME

// {{{RME operation 'oldTest()'
void genericTestLVFracN::oldTest( void )
{
	// {{{USR
		    uint16_t * tomahawkRxSequenceArray;
			uint16_t * tomahawkTxSequenceArray;
			uint16_t * DelaySequenceArray;

			uint32_t * tomahawkRxDefaultImage;
			uint32_t * tomahawkTxDefaultImage;

			// ************************************************************
			// create two sequences to set the rf state. This will result 
			// in data being written to the IC over the spi bus
			// ************************************************************

			// this sequence will call the synthesizer->setRFstate() method.
			// fracn is a synthesizer component.

			// **************************************************
			// sequence generator tool output
			// **************************************************
			//{  0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
			//   0xff, 0x0, 0x7f, 0x7f, 0x7f, 0x7f }; 
			/*---Begin code---*/
			//	EXEC L0,synthesizer:setRFState,#0
			//	END
			/*---End code---*/


	//		tomahawkRxSequenceArray = new uint16_t[6];
	//		tomahawkRxSequenceArray[0] = 0x0000 ;
	//		tomahawkRxSequenceArray[1] = 0x0000 ;
	//		tomahawkRxSequenceArray[2] = 0x0000 ;
	//		tomahawkRxSequenceArray[3] = 0xff00 ;
	//		tomahawkRxSequenceArray[4] = 0x7f7f ;
	//		tomahawkRxSequenceArray[5] = 0x7f7f ;

	//		tomahawkTxSequenceArray = new uint16_t[6];
	//		tomahawkTxSequenceArray[0] = 0x0000 ;
	//		tomahawkTxSequenceArray[1] = 0x0000 ;
	//		tomahawkTxSequenceArray[2] = 0x0000 ;
	//		tomahawkTxSequenceArray[3] = 0xff00 ;
	//		tomahawkTxSequenceArray[4] = 0x7f7f ;
	//		tomahawkTxSequenceArray[5] = 0x7f7f ;

	//		DelaySequenceArray = new uint16_t[6];

	//		DelaySequenceArray[0] = 0xe000 ;
	//		DelaySequenceArray[1] = 0x0000 ;
	//		DelaySequenceArray[2] = 3000;    //3000 microSecond
	//		DelaySequenceArray[3] = 0xff00 ; //All sequences but be ended with 
	//		DelaySequenceArray[4] = 0x7f7f ; // { 0xFF00, 0x7F7F, 0x7F7F }
	//		DelaySequenceArray[5] = 0x7f7f ;

	//	 	sequencePointersArray = new uint16_t * [ LTDMiscClass::NUMofSequences ];
	//	    sequencePointersArray[LTDMiscClass::RxSeqID] = tomahawkRxSequenceArray;
	//	    sequencePointersArray[LTDMiscClass::TxSeqID] = tomahawkTxSequenceArray;
	//	    sequencePointersArray[LTDMiscClass::DelaySeqID] = DelaySequenceArray;

			// ************************************************************
			//       create tx and rx default register image arrays  
			// ************************************************************

		   	// rx default image array, uint32_t_t x 4
	//	  	tomahawkRxDefaultImage = new uint32_t_t [ TOMAHAWK_IMAGE_SIZE / 4];

		  	// initialize to some printable values for testing on windows
		  	// these represent the actual IC register values.
	//	  	tomahawkRxDefaultImage[0] = 0x41424344;
	//	  	tomahawkRxDefaultImage[1] = 0x45464748;
	//	  	tomahawkRxDefaultImage[2] = 0x49494b4c;
	//	  	tomahawkRxDefaultImage[3] = 0x4d4e4f50;
	//	  	tomahawkRxDefaultImage[4] = 0x41424344;
	//	  	tomahawkRxDefaultImage[5] = 0x45464748;
	//	  	tomahawkRxDefaultImage[6] = 0x49494b4c;
	//	  	tomahawkRxDefaultImage[7] = 0x4d4e4f50;
	//	  	tomahawkRxDefaultImage[8] = 0x41424344;
	//	  	tomahawkRxDefaultImage[9] = 0x45464748;
	//	  	tomahawkRxDefaultImage[10] = 0x49494b4c;
	//	  	tomahawkRxDefaultImage[11] = 0x4d4e4f50;
	//	  	tomahawkRxDefaultImage[12] = 0x41424344;
	//	  	tomahawkRxDefaultImage[13] = 0x45464748;
	//	  	tomahawkRxDefaultImage[14] = 0x49494b4c;
	//	  	tomahawkRxDefaultImage[15] = 0x4d4e4f50;
	//	  	tomahawkRxDefaultImage[16] = 0x41424344;
	//	  	tomahawkRxDefaultImage[17] = 0x45464748;
	//	  	tomahawkRxDefaultImage[18] = 0x49494b4c;
	//	  	tomahawkRxDefaultImage[19] = 0x4d4e4f50;
	//	  	tomahawkRxDefaultImage[20] = 0x41424344;
	//	  	tomahawkRxDefaultImage[21] = 0x45464748;
	//	  	tomahawkRxDefaultImage[22] = 0x49494b4c;
	//	  	tomahawkRxDefaultImage[23] = 0x4d4e4f50;
	//	  	tomahawkRxDefaultImage[24] = 0x41424344;
	//	  	tomahawkRxDefaultImage[25] = 0x45464748;
	//	  	tomahawkRxDefaultImage[26] = 0x49494b4c;
	//	  	tomahawkRxDefaultImage[27] = 0x4d4e4f50;
	//	  	tomahawkRxDefaultImage[28] = 0x41424344;
	//	  	tomahawkRxDefaultImage[29] = 0x45464748;
	//	  	tomahawkRxDefaultImage[30] = 0x49494b4c;
	//	  	tomahawkRxDefaultImage[31] = 0x4d4e4f50;

		  	// tx default image array, uint32_t_t x 4
	//	  	tomahawkTxDefaultImage = new uint32_t_t [ TOMAHAWK_IMAGE_SIZE / 4 ];	
		  	// initialize to some printable values for testing
	//	  	tomahawkTxDefaultImage[0] = 0x41424344;
	//	  	tomahawkTxDefaultImage[1] = 0x45464748;
	//	  	tomahawkTxDefaultImage[2] = 0x49494b4c;
	//	  	tomahawkTxDefaultImage[3] = 0x4d4e4f50;
	//	  	tomahawkTxDefaultImage[4] = 0x41424344;
	//	  	tomahawkTxDefaultImage[5] = 0x45464748;
	//	  	tomahawkTxDefaultImage[6] = 0x49494b4c;
	//	  	tomahawkTxDefaultImage[7] = 0x4d4e4f50;
	//	  	tomahawkTxDefaultImage[8] = 0x41424344;
	//	  	tomahawkTxDefaultImage[9] = 0x45464748;
	//	  	tomahawkTxDefaultImage[10] = 0x49494b4c;
	//	  	tomahawkTxDefaultImage[11] = 0x4d4e4f50;
	//	  	tomahawkTxDefaultImage[12] = 0x41424344;
	//	  	tomahawkTxDefaultImage[13] = 0x45464748;
	//	  	tomahawkTxDefaultImage[14] = 0x49494b4c;
	//	  	tomahawkTxDefaultImage[15] = 0x4d4e4f50;
	//	  	tomahawkTxDefaultImage[16] = 0x41424344;
	//	  	tomahawkTxDefaultImage[17] = 0x45464748;
	//	  	tomahawkTxDefaultImage[18] = 0x49494b4c;
	//	  	tomahawkTxDefaultImage[19] = 0x4d4e4f50;
	//	  	tomahawkTxDefaultImage[20] = 0x41424344;
	//	  	tomahawkTxDefaultImage[21] = 0x45464748;
	//	  	tomahawkTxDefaultImage[22] = 0x49494b4c;
	//	  	tomahawkTxDefaultImage[23] = 0x4d4e4f50;
	//	  	tomahawkTxDefaultImage[24] = 0x41424344;
	//	  	tomahawkTxDefaultImage[25] = 0x45464748;
	//	  	tomahawkTxDefaultImage[26] = 0x49494b4c;
	//	  	tomahawkTxDefaultImage[27] = 0x4d4e4f50;
	//	  	tomahawkTxDefaultImage[28] = 0x41424344;
	//	  	tomahawkTxDefaultImage[29] = 0x45464748;
	//	  	tomahawkTxDefaultImage[30] = 0x49494b4c;
	//	  	tomahawkTxDefaultImage[31] = 0x4d4e4f50;

		
		  	// array of pointers to uint32_t arrays containing the default IC register image data  
	//	  	defaultTomahawkImages  = new int * [LTDMiscClass::NUMofRFStates];      // one image per rf state
		 
	//	  	defaultTomahawkImages[LTDMiscClass::RxState] = (int *) tomahawkRxDefaultImage;
	//	  	defaultTomahawkImages[LTDMiscClass::TxState] = (int *) tomahawkTxDefaultImage;
		

	//	    IOSerialDevice = tomahawkSPI; //was IOVirtualSerialDevice;
		    
	//	    timerPtr = timer;
		    
	//	    components = new sequencerComponent * [LTDMiscClass::NUMofComponents];
		    
		    // temperature compensation data array
		    //fracNTemperatureData = new uint32_t[1];
		             
	//	    clockCtrl = new uint32_t[1];
		    
	 //       connectionBufferFactory *  bufferManager = new connectionBufferFactory();
		    
	        // this method will return a pointer to an array of rfSpiBuffer objects (aka connectionBuffer_uint32s)
	        // the array size (number of buffer objects) is specified by the NUMofRFStates argument
	        // the second argument TOMAHAWK_IMAGE_SIZE_INBYTES, specifies the SIZE of EACH buffer, in bytes.
	        // Even though each connectionBuffer creates an internal array of uint16_t or uint32_t, we NONETHELESS
	        // specify the size in bytes.  If an odd number of bytes are requested, padding is inserted as needed.
	        // We could ask for a buffer of 3 bytes if we wished. Internally, it would use 4 bytes but when the
	        // sync method is invoked to send the buffer, it only would send 3.
	//        rfSpiBuffer ** spiBuffers = bufferManager ->getconnectionBufferArray_uint32( NUMofRFStates, TOMAHAWK_IMAGE_SIZE_INBYTES, (Connection *)myIOVirtualSerial);
		    
	//	    tomahawkDefDataObj = new tomahawkDefault( (const int **)defaultTomahawkImages );

	//	    tomahawk_IC = new tomahawk(tomahawkDefDataObj, rfSpiBuffer, LTDMiscClass::NUMofRFStates );

		 	     
	//	    components[0] = (synthesizer *) tomahawk_IC;   
		   
	//	    theSequencer = new sequencer( sequencePointersArray, components, timerPtr );
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
