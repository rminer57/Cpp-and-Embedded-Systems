// {{{RME classifier 'Logical View::Private::Private Serial Devices::SerialCommon::VoidPointerQueue::VoidPointerQueue'

#ifndef VoidPointerQueue_H
#define VoidPointerQueue_H

#ifdef PRAGMA
#pragma interface "VoidPointerQueue.h"
#endif

#include <serial_comp.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class VoidPointerQueue
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

protected:
	// {{{RME classAttribute 'm_queue'
	void * * m_queue;
	// }}}RME
	// {{{RME classAttribute 'm_readPtr'
	unsigned int m_readPtr;
	// }}}RME
	// {{{RME classAttribute 'm_writePtr'
	unsigned int m_writePtr;
	// }}}RME
	// {{{RME classAttribute 'm_size'
	unsigned int m_size;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	VoidPointerQueue( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	VoidPointerQueue( const VoidPointerQueue & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	VoidPointerQueue & operator=( const VoidPointerQueue & rtg_arg );
	// }}}RME
	// {{{RME operation 'VoidPointerQueue(unsigned int)'
	VoidPointerQueue( unsigned int size );
	// }}}RME
	// {{{RME operation 'get()'
	void * get( void );
	// }}}RME
	// {{{RME operation 'put(void *)'
	bool put( void * data );
	// }}}RME
	// {{{RME operation 'getSize()'
	unsigned int getSize( void );
	// }}}RME
	// {{{RME operation '~VoidPointerQueue()'
	~VoidPointerQueue( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* VoidPointerQueue_H */

// }}}RME
