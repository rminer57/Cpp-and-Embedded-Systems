// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::TestSupportAllPlatforms::connectionbuffer::connectionBuffer_uint32'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "connectionBuffer_uint32.h"
#endif

#include <HALtestLib_win32.h>
#include <connectionBuffer_uint32.h>
#include <Connection.h>
#include <SIntArray.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'STORAGEUNITSIZEINBYTES'
const int connectionBuffer_uint32::STORAGEUNITSIZEINBYTES( 4 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
connectionBuffer_uint32 & connectionBuffer_uint32::operator=( const connectionBuffer_uint32 & rtg_arg )
{
	if( this != &rtg_arg )
	{
		rfSpiBuffer::operator=( rtg_arg );
		m_allocatedNumOfStorageUnits = rtg_arg.m_allocatedNumOfStorageUnits;
		m_bSkipFirst = rtg_arg.m_bSkipFirst;
		m_bSkipLast = rtg_arg.m_bSkipLast;
		m_buffer = rtg_arg.m_buffer;
		m_doEndianSwap = rtg_arg.m_doEndianSwap;
		m_sizeBytes = rtg_arg.m_sizeBytes;
		m_connection = rtg_arg.m_connection;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'connectionBuffer_uint32(unsigned int,Connection *,bool,bool)'
connectionBuffer_uint32::connectionBuffer_uint32( unsigned int bufferSizeInBytes, Connection * conn, bool skipFirst, bool skipLast )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_connection(conn), m_sizeBytes(bufferSizeInBytes)
	// }}}USR
	// }}}RME
{
	// {{{USR
	m_doEndianSwap = false; // default is false, can be modified by user.
	m_bSkipFirst   = skipFirst;
	m_bSkipLast    = skipLast;

	// if request is for a smaller number of bytes than the
	// minimum storage unit size (e.g. 3 bytes when using 32 bits for storage)
	// then allocate size of 1 storage unit (4 bytes for 32 bit storage unit).

	if( bufferSizeInBytes < STORAGEUNITSIZEINBYTES)
	{
	  // always allocate at least 1 storage unit. If bufferSizeInBytes is 0,
	  // nothing will be sent out, but the code will not crash.
	  m_allocatedNumOfStorageUnits = 1;
	}
	else
	{
	  
	  m_allocatedNumOfStorageUnits = bufferSizeInBytes / STORAGEUNITSIZEINBYTES;

	  int remainder = bufferSizeInBytes % STORAGEUNITSIZEINBYTES;

	  // round up m_allocatedNumOfStorageUnits if necessary
	  if( remainder > 0 )
	  {
	    m_allocatedNumOfStorageUnits++; // round up
	  }
	 
	}
	   //allocate the buffer memory.
	   m_buffer = new uint32_t[m_allocatedNumOfStorageUnits];

	// }}}USR
}
// }}}RME

// {{{RME operation 'operator uint32_t *()'
connectionBuffer_uint32::operator uint32_t *( void )
{
	// {{{USR
	return m_buffer;
	// }}}USR
}
// }}}RME

// {{{RME operation 'operator[](int)'
uint32_t & connectionBuffer_uint32::operator[]( int index )
{
	// {{{USR
	return m_buffer[index];
	// }}}USR
}
// }}}RME

// {{{RME operation 'setEndianSwap(bool)'
void connectionBuffer_uint32::setEndianSwap( bool value )
{
	// {{{USR
	m_doEndianSwap = value;
	// }}}USR
}
// }}}RME

// {{{RME operation 'sync()'
void connectionBuffer_uint32::sync( void )
{
	// {{{USR
	// intent of endian swap is to convert ABCD to DCBA

	/*
	if( m_doEndianSwap == true )
	{

	   // create a temporary array for byte swapping.
	   unsigned char * outputArray = new unsigned char [m_allocatedNumOfStorageUnits * STORAGEUNITSIZEINBYTES];
	   unsigned char * srcArray = (unsigned char * )m_buffer;
	   int index = 0;

	   // swap all bytes in all storage units 
	   for(int i = 0; i < m_allocatedNumOfStorageUnits; i++ )
	   {    
	      // copy bytes and swap at same time.
	      outputArray[index]     = srcArray[index + 3];
	      outputArray[index + 1] = srcArray[index + 2];  
	      outputArray[index + 2] = srcArray[index + 1];
	      outputArray[index + 3] = srcArray[index];
	      index += 4;
	      
	   }

	 
	   //m_connection->send( new SIntArray( (m_sizeBytes+1)/2, ((int16_t *)outputArray)+1, false, new Omap1610Spi::SIntDesc(m_bSkipFirst,m_bSkipLast)) );
	   delete [] outputArray;

	}
	else // EndianSwap disabled 
	{
	*/
	   if (m_bSkipFirst)
	   {
	      Array * p = (Array *)new SIntArray( ((m_sizeBytes+1)/2), ((int16_t *)m_buffer)+1, false);
	      m_connection->send( p );
	   }
	   else
	   {
	      Array * p = new SIntArray( ((m_sizeBytes+1)/2), ((int16_t *)m_buffer), false);
	      m_connection->send( p );
	   }
	//}
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
