// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::TestSupportAllPlatforms::connectionbuffer::connectionBufferExample'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "connectionBufferExample.h"
#endif

#include <HALtestLib_win32.h>
#include <connectionBufferExample.h>
#include <IOVirtualSerial.h>
#include <connectionBufferFactory.h>
#include <connectionBuffer_uint32.h>
#include <rfSpiBuffer.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'connectionBufferExample()'
connectionBufferExample::connectionBufferExample( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	// BYTE size  of the Tomahawk (version 2) SPI image, 1 byte address header + 128 registers
#define TOMAHAWK_IMAGE_SIZE_INBYTES     129
#define TOMAHAWK_IMAGE_SIZE_INUINT32s    33

#define NUMofRFStates 1
#define NUMofBytesTotalInEachBuffer

	// this variable must point to a valid IOVirtualSerial reference 
	// (e.g. )Omap1610Spi driver or the rfSpiBuffer->sync() method will crash!
	IOVirtualSerial * myIOVirtualSerial = 0;

	connectionBufferFactory *  bufferManager = new connectionBufferFactory();
		    
	// this method will return a pointer to an array of rfSpiBuffer objects (aka connectionBuffer_uint32s)
	// the array size (number of buffer objects) is specified by the NUMofRFStates argument
	// the second argument TOMAHAWK_IMAGE_SIZE_INBYTES, specifies the SIZE of EACH buffer, in bytes.
	// Even though each connectionBuffer creates an internal array of uint16_t or uint32_t, we NONETHELESS
	// specify the size in bytes.  If an odd number of bytes are requested, padding is inserted as needed.
	// We could ask for a buffer of 3 bytes if we wished. Internally, it would use 4 bytes but when the
	// sync method is invoked to send the buffer, it only would send 3.
	rfSpiBuffer ** spiBuffers = bufferManager ->getconnectionBufferArray_uint32( NUMofRFStates, TOMAHAWK_IMAGE_SIZE_INBYTES, (Connection *)myIOVirtualSerial);

	// ************************************************************
	// buffer access example, adapted from the tomahawk constructor
	// ************************************************************
	        // rx default image array, uint32_t_t x 4
		  	uint32_t * tomahawkRxDefaultImage = new uint32_t [ TOMAHAWK_IMAGE_SIZE_INBYTES / 4];

		  	// initialize to some printable values for testing on windows
		  	// these represent the actual IC register values.
		  	tomahawkRxDefaultImage[0] = 0x41424344;
		  	tomahawkRxDefaultImage[1] = 0x45464748;
		  	tomahawkRxDefaultImage[2] = 0x49494b4c;
		  	tomahawkRxDefaultImage[3] = 0x4d4e4f50;
		  	tomahawkRxDefaultImage[4] = 0x41424344;
		  	tomahawkRxDefaultImage[5] = 0x45464748;
		  	tomahawkRxDefaultImage[6] = 0x49494b4c;
		  	tomahawkRxDefaultImage[7] = 0x4d4e4f50;
		  	tomahawkRxDefaultImage[8] = 0x41424344;
		  	tomahawkRxDefaultImage[9] = 0x45464748;
		  	tomahawkRxDefaultImage[10] = 0x49494b4c;
		  	tomahawkRxDefaultImage[11] = 0x4d4e4f50;
		  	tomahawkRxDefaultImage[12] = 0x41424344;
		  	tomahawkRxDefaultImage[13] = 0x45464748;
		  	tomahawkRxDefaultImage[14] = 0x49494b4c;
		  	tomahawkRxDefaultImage[15] = 0x4d4e4f50;
		  	tomahawkRxDefaultImage[16] = 0x41424344;
		  	tomahawkRxDefaultImage[17] = 0x45464748;
		  	tomahawkRxDefaultImage[18] = 0x49494b4c;
		  	tomahawkRxDefaultImage[19] = 0x4d4e4f50;
		  	tomahawkRxDefaultImage[20] = 0x41424344;
		  	tomahawkRxDefaultImage[21] = 0x45464748;
		  	tomahawkRxDefaultImage[22] = 0x49494b4c;
		  	tomahawkRxDefaultImage[23] = 0x4d4e4f50;
		  	tomahawkRxDefaultImage[24] = 0x41424344;
		  	tomahawkRxDefaultImage[25] = 0x45464748;
		  	tomahawkRxDefaultImage[26] = 0x49494b4c;
		  	tomahawkRxDefaultImage[27] = 0x4d4e4f50;
		  	tomahawkRxDefaultImage[28] = 0x41424344;
		  	tomahawkRxDefaultImage[29] = 0x45464748;
		  	tomahawkRxDefaultImage[30] = 0x49494b4c;
		  	tomahawkRxDefaultImage[31] = 0x4d4e4f50;

	 
		    // array of pointers to uint32_t arrays containing the default IC register image data  
		    uint32_t ** defaultTomahawkImages  = new uint32_t * [NUMofRFStates];      // one image per rf state
		 
		  	defaultTomahawkImages[0] = (uint32_t *) tomahawkRxDefaultImage;
		  

	  // Initialize RF State based data elements
	 for(int i = 0; i < NUMofRFStates; i++)
	  {

	  // Copy default image data to local SPI buffer
	    for(int j = 0; j < TOMAHAWK_IMAGE_SIZE_INUINT32s; j++)
		{
		  (*spiBuffers[i])[j] = defaultTomahawkImages[i][j];
		}
	  }
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
