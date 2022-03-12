// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::TestSupportAllPlatforms::connectionbuffer::connectionBuffer_uint32'

#ifndef connectionBuffer_uint32_H
#define connectionBuffer_uint32_H

#ifdef PRAGMA
#pragma interface "connectionBuffer_uint32.h"
#endif

#include <HALtestLib_win32.h>
#include <rfSpiBuffer.h>
class Connection;
class SIntArray;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>
// }}}USR
// }}}RME

class connectionBuffer_uint32 : public rfSpiBuffer
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
	// {{{RME classAttribute 'm_allocatedNumOfStorageUnits'
	int m_allocatedNumOfStorageUnits;
	// }}}RME
	// {{{RME classAttribute 'm_bSkipFirst'
	bool m_bSkipFirst;
	// }}}RME
	// {{{RME classAttribute 'm_bSkipLast'
	bool m_bSkipLast;
	// }}}RME
	// {{{RME classAttribute 'm_buffer'
	uint32_t * m_buffer;
	// }}}RME
	// {{{RME classAttribute 'm_doEndianSwap'
	bool m_doEndianSwap;
	// }}}RME
	// {{{RME classAttribute 'm_sizeBytes'
	unsigned int m_sizeBytes;
	// }}}RME
	// {{{RME classAttribute 'STORAGEUNITSIZEINBYTES'
	static const int STORAGEUNITSIZEINBYTES;
	// }}}RME
	// {{{RME classAttribute 'm_connection'
	Connection * m_connection;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	connectionBuffer_uint32 & operator=( const connectionBuffer_uint32 & rtg_arg );
	// }}}RME
	// {{{RME operation 'connectionBuffer_uint32(unsigned int,Connection *,bool,bool)'
	connectionBuffer_uint32( unsigned int bufferSizeInBytes, Connection * conn, bool skipFirst = false, bool skipLast = false );
	// }}}RME
	// {{{RME operation 'operator uint32_t *()'
	virtual operator uint32_t *( void );
	// }}}RME
	// {{{RME operation 'operator[](int)'
	virtual uint32_t & operator[]( int index );
	// }}}RME
	// {{{RME operation 'setEndianSwap(bool)'
	void setEndianSwap( bool value );
	// }}}RME
	// {{{RME operation 'sync()'
	virtual void sync( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* connectionBuffer_uint32_H */

// }}}RME
