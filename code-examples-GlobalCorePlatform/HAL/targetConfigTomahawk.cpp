// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::targetConfigObjects::configMotorola_ICs::targetConfigTomahawk'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "targetConfigTomahawk.h"
#endif

#include <HALtestLib_win32.h>
#include <targetConfigTomahawk.h>
#include <IOVirtualSerial.h>
#include <connectionBufferFactory.h>
#include <rfSpiBuffer.h>
#include <rfSpiManager.h>
#include <tomahawk.h>
#include <tomahawkDefault.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
targetConfigTomahawk::targetConfigTomahawk( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
targetConfigTomahawk::~targetConfigTomahawk( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
targetConfigTomahawk::targetConfigTomahawk( const targetConfigTomahawk & rtg_arg )
	: targetConfigBase( rtg_arg )
	, m_tomahawk( rtg_arg.m_tomahawk )
	, m_tomahawkRxDefaultImage( rtg_arg.m_tomahawkRxDefaultImage )
	, m_tomahawkTxDefaultImage( rtg_arg.m_tomahawkTxDefaultImage )
	, m_defaultTomahawkImages( rtg_arg.m_defaultTomahawkImages )
	, m_tomahawkDefDataObj( rtg_arg.m_tomahawkDefDataObj )
	, m_spiBuffers( rtg_arg.m_spiBuffers )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
targetConfigTomahawk & targetConfigTomahawk::operator=( const targetConfigTomahawk & rtg_arg )
{
	if( this != &rtg_arg )
	{
		targetConfigBase::operator=( rtg_arg );
		m_tomahawk = rtg_arg.m_tomahawk;
		m_tomahawkRxDefaultImage = rtg_arg.m_tomahawkRxDefaultImage;
		m_tomahawkTxDefaultImage = rtg_arg.m_tomahawkTxDefaultImage;
		m_defaultTomahawkImages = rtg_arg.m_defaultTomahawkImages;
		m_tomahawkDefDataObj = rtg_arg.m_tomahawkDefDataObj;
		m_spiBuffers = rtg_arg.m_spiBuffers;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'init()'
void targetConfigTomahawk::init( void )
{
	// {{{USR
#define NUMofRFStates 2
#define RxState 0
#define TxState 1

	m_tomahawkRxDefaultImage = 0;
	m_tomahawkTxDefaultImage = 0;

	m_defaultTomahawkImages = 0;

	m_tomahawkDefDataObj = 0;

	m_spiBuffers = 0;



			// ************************************************************
			//       create tx and rx default register image arrays  
			// ************************************************************

		   	// rx default image array, uint32_t_t x 4
		  	m_tomahawkRxDefaultImage = new uint32_t [ TOMAHAWK_IMAGE_SIZE_UINT32 ];

		  	// initialize to some printable values for testing on windows
		  	// these represent the actual IC register values.
		  	m_tomahawkRxDefaultImage[0] = 0x41424344;
		  	m_tomahawkRxDefaultImage[1] = 0x45464748;
		  	m_tomahawkRxDefaultImage[2] = 0x49494b4c;
		  	m_tomahawkRxDefaultImage[3] = 0x4d4e4f50;
		  	m_tomahawkRxDefaultImage[4] = 0x41424344;
		  	m_tomahawkRxDefaultImage[5] = 0x45464748;
		  	m_tomahawkRxDefaultImage[6] = 0x49494b4c;
		  	m_tomahawkRxDefaultImage[7] = 0x4d4e4f50;
		  	m_tomahawkRxDefaultImage[8] = 0x41424344;
		  	m_tomahawkRxDefaultImage[9] = 0x45464748;
		  	m_tomahawkRxDefaultImage[10] = 0x49494b4c;
		  	m_tomahawkRxDefaultImage[11] = 0x4d4e4f50;
		  	m_tomahawkRxDefaultImage[12] = 0x41424344;
		  	m_tomahawkRxDefaultImage[13] = 0x45464748;
		  	m_tomahawkRxDefaultImage[14] = 0x49494b4c;
		  	m_tomahawkRxDefaultImage[15] = 0x4d4e4f50;
		  	m_tomahawkRxDefaultImage[16] = 0x41424344;
		  	m_tomahawkRxDefaultImage[17] = 0x45464748;
		  	m_tomahawkRxDefaultImage[18] = 0x49494b4c;
		  	m_tomahawkRxDefaultImage[19] = 0x4d4e4f50;
		  	m_tomahawkRxDefaultImage[20] = 0x41424344;
		  	m_tomahawkRxDefaultImage[21] = 0x45464748;
		  	m_tomahawkRxDefaultImage[22] = 0x49494b4c;
		  	m_tomahawkRxDefaultImage[23] = 0x4d4e4f50;
		  	m_tomahawkRxDefaultImage[24] = 0x41424344;
		  	m_tomahawkRxDefaultImage[25] = 0x45464748;
		  	m_tomahawkRxDefaultImage[26] = 0x49494b4c;
		  	m_tomahawkRxDefaultImage[27] = 0x4d4e4f50;
		  	m_tomahawkRxDefaultImage[28] = 0x41424344;
		  	m_tomahawkRxDefaultImage[29] = 0x45464748;
		  	m_tomahawkRxDefaultImage[30] = 0x49494b4c;
		  	m_tomahawkRxDefaultImage[31] = 0x4d4e4f50;

		  	// tx default image array, uint32_t_t x 4
		  	m_tomahawkTxDefaultImage = new uint32_t [ TOMAHAWK_IMAGE_SIZE_UINT32 ];
		
		  	// initialize to some printable values for testing
		  	m_tomahawkTxDefaultImage[0] = 0x41424344;
		  	m_tomahawkTxDefaultImage[1] = 0x45464748;
		  	m_tomahawkTxDefaultImage[2] = 0x49494b4c;
		  	m_tomahawkTxDefaultImage[3] = 0x4d4e4f50;
		  	m_tomahawkTxDefaultImage[4] = 0x41424344;
		  	m_tomahawkTxDefaultImage[5] = 0x45464748;
		  	m_tomahawkTxDefaultImage[6] = 0x49494b4c;
		  	m_tomahawkTxDefaultImage[7] = 0x4d4e4f50;
		  	m_tomahawkTxDefaultImage[8] = 0x41424344;
		  	m_tomahawkTxDefaultImage[9] = 0x45464748;
		  	m_tomahawkTxDefaultImage[10] = 0x49494b4c;
		  	m_tomahawkTxDefaultImage[11] = 0x4d4e4f50;
		  	m_tomahawkTxDefaultImage[12] = 0x41424344;
		  	m_tomahawkTxDefaultImage[13] = 0x45464748;
		  	m_tomahawkTxDefaultImage[14] = 0x49494b4c;
		  	m_tomahawkTxDefaultImage[15] = 0x4d4e4f50;
		  	m_tomahawkTxDefaultImage[16] = 0x41424344;
		  	m_tomahawkTxDefaultImage[17] = 0x45464748;
		  	m_tomahawkTxDefaultImage[18] = 0x49494b4c;
		  	m_tomahawkTxDefaultImage[19] = 0x4d4e4f50;
		  	m_tomahawkTxDefaultImage[20] = 0x41424344;
		  	m_tomahawkTxDefaultImage[21] = 0x45464748;
		  	m_tomahawkTxDefaultImage[22] = 0x49494b4c;
		  	m_tomahawkTxDefaultImage[23] = 0x4d4e4f50;
		  	m_tomahawkTxDefaultImage[24] = 0x41424344;
		  	m_tomahawkTxDefaultImage[25] = 0x45464748;
		  	m_tomahawkTxDefaultImage[26] = 0x49494b4c;
		  	m_tomahawkTxDefaultImage[27] = 0x4d4e4f50;
		  	m_tomahawkTxDefaultImage[28] = 0x41424344;
		  	m_tomahawkTxDefaultImage[29] = 0x45464748;
		  	m_tomahawkTxDefaultImage[30] = 0x49494b4c;
		  	m_tomahawkTxDefaultImage[31] = 0x4d4e4f50;

		
		  	// array of pointers to uint32_t arrays containing the default IC register image data  
		  	m_defaultTomahawkImages  = new uint32_t * [NUMofRFStates];      // one image per rf state
		 
		  	m_defaultTomahawkImages[RxState] =  m_tomahawkRxDefaultImage;
		  	m_defaultTomahawkImages[TxState] =  m_tomahawkTxDefaultImage;

	        connectionBufferFactory *  bufferManager = new connectionBufferFactory();
		    
	        // this method will return a pointer to an array of rfSpiBuffer objects (aka connectionBuffer_uint32s)
	        // the array size (number of buffer objects) is specified by the NUMofRFStates argument
	        // the second argument TOMAHAWK_IMAGE_SIZE_INBYTES, specifies the SIZE of EACH buffer, in bytes.
	        // Even though each connectionBuffer creates an internal array of uint16_t or uint32_t, we NONETHELESS
	        // specify the size in bytes.  If an odd number of bytes are requested, padding is inserted as needed.
	        // We could ask for a buffer of 3 bytes if we wished. Internally, it would use 4 bytes but when the
	        // sync method is invoked to send the buffer, it only would send 3.
	        m_spiBuffers = bufferManager ->getconnectionBufferArray_uint32( NUMofRFStates, TOMAHAWK_IMAGE_SIZE_BYTES, (Connection *)targetConfigBase::m_tomahawkSPI);

	        if(m_spiBuffers == 0)
	        {
	          targetConfigBase::sendStringToStderr("ERROR: targetConfigTomahawk init() method m_spiBuffers == 0\n");
	        }

	        if(targetConfigBase::m_tomahawkSPI == 0)
	        {
	           targetConfigBase::sendStringToStderr("ERROR: targetConfigTomahawk init() method targetConfigBase::m_tomahawkSPI == 0\n");
	        }
		    
		    m_tomahawkDefDataObj = new tomahawkDefault( m_defaultTomahawkImages );

		    m_tomahawk = new tomahawk(m_tomahawkDefDataObj, m_spiBuffers, NUMofRFStates );

	      
	//      uint16_t addr, uint16_t data, int rfState = 0
	      m_tomahawk->wrRegister(0,0x1234,0);
	 
	      // this causes an assertion error on win32 due to a problem with the generalPurposeOutputManager destructor     
	      //delete m_tomahawk; // test destructor	

	//	    IOSerialDevice = tomahawkSPI; //was IOVirtualSerialDevice;

	targetConfigBase::sendStringToStderr("targetConfigTomahawk init() method!\n");


	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
