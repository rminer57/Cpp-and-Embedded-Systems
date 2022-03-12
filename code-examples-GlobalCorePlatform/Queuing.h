// {{{RME classifier 'Logical View::Private::Private Serial Devices::SerialCommon::SerialQueuing::Queuing'

#ifndef Queuing_H
#define Queuing_H

#ifdef PRAGMA
#pragma interface "Queuing.h"
#endif

#include <misc_comp.h>
class DataBuffer;
class Mutex;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class Queuing
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
	// {{{RME classAttribute 'm_receiveQueueHeadIndex'
	unsigned int m_receiveQueueHeadIndex;
	// }}}RME
	// {{{RME classAttribute 'm_sendQueueHeadIndex'
	unsigned int m_sendQueueHeadIndex;
	// }}}RME
	// {{{RME classAttribute 'm_receiveQueueTailIndex'
	unsigned int m_receiveQueueTailIndex;
	// }}}RME
	// {{{RME classAttribute 'm_sendQueueTailIndex'
	unsigned int m_sendQueueTailIndex;
	// }}}RME
	// {{{RME classAttribute 'm_receiveQueueSize'
	unsigned int m_receiveQueueSize;
	// }}}RME
	// {{{RME classAttribute 'm_sendQueueSize'
	unsigned int m_sendQueueSize;
	// }}}RME

public:
	// {{{RME associationEnd 'm_mutex'
	Mutex * m_mutex;
	// }}}RME
	// {{{RME associationEnd 'm_receiveQueue'
	DataBuffer ** m_receiveQueue;
	// }}}RME
	// {{{RME associationEnd 'm_sendQueue'
	DataBuffer ** m_sendQueue;
	// }}}RME
	// {{{RME operation 'Queuing(unsigned int,unsigned int)'
	Queuing( unsigned int sendQueueSize = 64, unsigned int receiveQueueSize = 64 );
	// }}}RME

protected:
	// {{{RME operation 'enqueueReceiveData(DataBuffer*)'
	virtual bool enqueueReceiveData( DataBuffer * buffer );
	// }}}RME
	// {{{RME operation 'enqueueSendData(DataBuffer*)'
	virtual void enqueueSendData( DataBuffer * buffer );
	// }}}RME
	// {{{RME operation 'dequeueReceiveData()'
	virtual DataBuffer * dequeueReceiveData( void );
	// }}}RME
	// {{{RME operation 'dequeueSendData()'
	virtual DataBuffer * dequeueSendData( void );
	// }}}RME

public:
	// {{{RME operation '~Queuing()'
	~Queuing( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Queuing_H */

// }}}RME
