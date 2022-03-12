// {{{RME classifier 'Logical View::UsbPrivate::PointerQueue::DataQueue'

#ifndef DataQueue_H
#define DataQueue_H

#ifdef PRAGMA
#pragma interface "DataQueue.h"
#endif

#include <usbimp.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class DataQueue
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
	unsigned char * m_queue;
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
	DataQueue( void );
	// }}}RME
	// {{{RME operation 'DataQueue(unsigned int)'
	DataQueue( unsigned int size );
	// }}}RME
	// {{{RME operation 'get()'
	unsigned char get( void );
	// }}}RME
	// {{{RME operation 'put(unsigned char)'
	bool put( unsigned char data );
	// }}}RME
	// {{{RME operation 'getSize()'
	unsigned int getSize( void );
	// }}}RME
	// {{{RME operation '~DataQueue()'
	~DataQueue( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* DataQueue_H */

// }}}RME
