// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::trident::TridentPrivate::tridentSpiBuffer'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "tridentSpiBuffer.h"
#endif

#include <rf_sequencer_comp.h>
#include <tridentSpiBuffer.h>
#include <Connection.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
tridentSpiBuffer::tridentSpiBuffer( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
tridentSpiBuffer::~tridentSpiBuffer( void )
{
}
// }}}RME

// {{{RME operation 'sync()'
void tridentSpiBuffer::sync( void )
{
	// {{{USR
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
	// }}}USR
}
// }}}RME

// {{{RME operation 'operator[](int)'
uint32_t & tridentSpiBuffer::operator[]( int index )
{
	// {{{USR


	return m_buffer[index];
	// }}}USR
}
// }}}RME

// {{{RME operation 'operator uint32_t *()'
tridentSpiBuffer::operator uint32_t *( void )
{
	// {{{USR
	  
	  return m_buffer;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setEndianSwap(bool)'
void tridentSpiBuffer::setEndianSwap( bool value )
{
	// {{{USR
	m_doEndianSwap = value;
	// }}}USR
}
// }}}RME

// {{{RME operation 'endianSwap(Array **)'
void tridentSpiBuffer::endianSwap( Array * * buf )
{
	// {{{USR
	    if(  (*buf)->isType(SIntArray::SIGNED_INT_ARRAY)  )
	    {
		  int16_t temp0 = (((*(SIntArray *)(*buf))[0] >> 8) &0x00FF) | (((*(SIntArray *)(*buf))[0] << 8) &0xFF00);
		  (*(SIntArray *)(*buf))[0]  = (((*(SIntArray *)(*buf))[1] >> 8) &0x00FF) | (((*(SIntArray *)(*buf))[1] << 8) &0xFF00);
		  (*(SIntArray *)(*buf))[1] = temp0;
	    }
	// }}}USR
}
// }}}RME

// {{{RME operation 'tridentSpiBuffer(unsigned int,Connection *,bool,bool)'
tridentSpiBuffer::tridentSpiBuffer( unsigned int bufferSizeInBytes, Connection * conn, bool skipFirst, bool skipLast )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_connection(conn), m_sizeBytes(bufferSizeInBytes),m_doEndianSwap(true)
	// }}}USR
	// }}}RME
{
	// {{{USR
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

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
