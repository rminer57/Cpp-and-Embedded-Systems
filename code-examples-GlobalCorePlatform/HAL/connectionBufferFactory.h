// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::TestSupportAllPlatforms::connectionbuffer::connectionBufferFactory'

#ifndef connectionBufferFactory_H
#define connectionBufferFactory_H

#ifdef PRAGMA
#pragma interface "connectionBufferFactory.h"
#endif

#include <HALtestLib_win32.h>
class Connection;
class connectionBuffer_uint32;
class rfSpiBuffer;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class connectionBufferFactory
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

public:
	// {{{RME operation 'getconnectionBufferArray_uint32(unsigned int,unsigned int,Connection*,bool,bool)'
	virtual rfSpiBuffer * * getconnectionBufferArray_uint32( unsigned int numOfBuffers, unsigned int sizeOfEachBufferInBytes, Connection * conn, bool skipFirst = false, bool skipLast = false );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* connectionBufferFactory_H */

// }}}RME
