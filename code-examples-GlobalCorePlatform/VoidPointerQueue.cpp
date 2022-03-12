// {{{RME classifier 'Logical View::Private::Private Serial Devices::SerialCommon::VoidPointerQueue::VoidPointerQueue'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "VoidPointerQueue.h"
#endif

#include <serial_comp.h>
#include <VoidPointerQueue.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
VoidPointerQueue::VoidPointerQueue( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
VoidPointerQueue::VoidPointerQueue( const VoidPointerQueue & rtg_arg )
	: m_queue( rtg_arg.m_queue )
	, m_readPtr( rtg_arg.m_readPtr )
	, m_writePtr( rtg_arg.m_writePtr )
	, m_size( rtg_arg.m_size )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
VoidPointerQueue & VoidPointerQueue::operator=( const VoidPointerQueue & rtg_arg )
{
	if( this != &rtg_arg )
	{
		m_queue = rtg_arg.m_queue;
		m_readPtr = rtg_arg.m_readPtr;
		m_writePtr = rtg_arg.m_writePtr;
		m_size = rtg_arg.m_size;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'VoidPointerQueue(unsigned int)'
VoidPointerQueue::VoidPointerQueue( unsigned int size )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_size(size+1), m_readPtr(0), m_writePtr(0), m_queue( new void * [ size+1 ] )
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'get()'
void * VoidPointerQueue::get( void )
{
	// {{{USR
	void * retval = 0;

	if ( m_readPtr != m_writePtr )
	{
		retval = m_queue[m_readPtr];

		m_readPtr++;

		if ( m_readPtr >= m_size )
		{
			m_readPtr = 0;
		}    
	}

	return retval;

	// }}}USR
}
// }}}RME

// {{{RME operation 'put(void *)'
bool VoidPointerQueue::put( void * data )
{
	// {{{USR
	bool retVal = false;

	if ( getSize() < (m_size-1) )
	{
	   m_queue[m_writePtr] = data;

	   m_writePtr ++;

	   if ( m_writePtr >= m_size )
	   {
		   m_writePtr = 0;
	   }

	   retVal = true;
	}

	return retVal;

	// }}}USR
}
// }}}RME

// {{{RME operation 'getSize()'
unsigned int VoidPointerQueue::getSize( void )
{
	// {{{USR
	unsigned int my_write_ptr = m_writePtr;
	unsigned int my_read_ptr = m_readPtr;

	return ( my_read_ptr > my_write_ptr ) ?
	                      ( my_write_ptr + m_size - my_read_ptr ) :
	                      ( my_write_ptr - my_read_ptr );

	// }}}USR
}
// }}}RME

// {{{RME operation '~VoidPointerQueue()'
VoidPointerQueue::~VoidPointerQueue( void )
{
	// {{{USR
	delete[] m_queue;

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
