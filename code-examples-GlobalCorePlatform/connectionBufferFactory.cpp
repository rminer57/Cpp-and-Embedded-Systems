// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::TestSupportAllPlatforms::connectionbuffer::connectionBufferFactory'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "connectionBufferFactory.h"
#endif

#include <HALtestLib_win32.h>
#include <connectionBufferFactory.h>
#include <Connection.h>
#include <connectionBuffer_uint32.h>
#include <rfSpiBuffer.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'getconnectionBufferArray_uint32(unsigned int,unsigned int,Connection*,bool,bool)'
rfSpiBuffer * * connectionBufferFactory::getconnectionBufferArray_uint32( unsigned int numOfBuffers, unsigned int sizeOfEachBufferInBytes, Connection * conn, bool skipFirst, bool skipLast )
{
	// {{{USR

	// allocate memory for an array of buffers. rfSpiBuffer is the parent class.
	rfSpiBuffer ** ret = new rfSpiBuffer*[numOfBuffers + 1];	

	//allocate a buffer of the given size, for each array element
	for (int i=0; i < numOfBuffers; i++)
	{
		ret[i] = new connectionBuffer_uint32(sizeOfEachBufferInBytes, conn, skipFirst, skipLast);
	}


	return ret;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
