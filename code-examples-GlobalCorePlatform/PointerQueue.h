// {{{RME classifier 'Logical View::UsbPrivate::PointerQueue::PointerQueue'

#ifndef PointerQueue_H
#define PointerQueue_H

#ifdef PRAGMA
#pragma interface "PointerQueue.h"
#endif

#include <usbimp.h>
class Sem;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class PointerQueue
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
	// {{{RME associationEnd 'm_sem'
	Sem * m_sem;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	PointerQueue( void );
	// }}}RME
	// {{{RME operation 'PointerQueue(unsigned int)'
	PointerQueue( unsigned int size );
	// }}}RME
	// {{{RME operation 'get()'
	void * get( void );
	// }}}RME
	// {{{RME operation 'put(void *)'
	bool put( void * data );
	// }}}RME
	// {{{RME operation 'getNonBlocking()'
	void * getNonBlocking( void );
	// }}}RME
	// {{{RME operation 'getSize()'
	unsigned int getSize( void );
	// }}}RME
	// {{{RME operation '~PointerQueue()'
	~PointerQueue( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* PointerQueue_H */

// }}}RME
