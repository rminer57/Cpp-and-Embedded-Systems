// {{{RME classifier 'Logical View::Private::Private Serial Devices::SerialCommon::SerialQueuing::Queuing'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Queuing.h"
#endif

#include <misc_comp.h>
#include <Queuing.h>
#include <DataBuffer.h>
#include <Mutex.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'Queuing(unsigned int,unsigned int)'
Queuing::Queuing( unsigned int sendQueueSize, unsigned int receiveQueueSize )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_sendQueueSize(sendQueueSize), m_receiveQueueSize(receiveQueueSize), m_receiveQueueHeadIndex(0), m_sendQueueHeadIndex(0), m_receiveQueueTailIndex(0), m_sendQueueTailIndex(0)
	// }}}USR
	// }}}RME
{
	// {{{USR
	unsigned int i;

	m_receiveQueue = new DataBuffer*[m_receiveQueueSize];
	m_sendQueue = new DataBuffer*[m_sendQueueSize];
	m_mutex = Mutex::createMutex();

	for(i = 0; i < m_sendQueueSize; i++)
	{
	   m_sendQueue[i] = (DataBuffer*)0;
	}

	for(i = 0; i < m_receiveQueueSize; i++)
	{
	   m_receiveQueue[i] = (DataBuffer*)0;
	}


	// }}}USR
}
// }}}RME

// {{{RME operation 'enqueueReceiveData(DataBuffer*)'
bool Queuing::enqueueReceiveData( DataBuffer * buffer )
{
	// {{{USR
	bool isDataAvailable = false;

	m_mutex->lock();

	// If there is still room in the queue, add the buffer.
	// Otherwise throw it away.
	if (((m_receiveQueueTailIndex+1) % m_receiveQueueSize) != m_receiveQueueHeadIndex)
	{
	   m_receiveQueue[m_receiveQueueTailIndex] = buffer;
	   m_receiveQueueTailIndex = ((m_receiveQueueTailIndex+1) % m_receiveQueueSize);
	   m_mutex->unlock();
	   isDataAvailable= true;
	   m_mutex->lock();
	}
	else
	{
	   delete(buffer);
	}

	m_mutex->unlock();

	return isDataAvailable;
	// }}}USR
}
// }}}RME

// {{{RME operation 'enqueueSendData(DataBuffer*)'
void Queuing::enqueueSendData( DataBuffer * buffer )
{
	// {{{USR
	m_mutex->lock();

	// If there is still room in the queue, add the buffer.
	// Otherwise throw it away.

	if (((m_sendQueueTailIndex+1) % m_sendQueueSize) != m_sendQueueHeadIndex)
	{
	   m_sendQueue[m_sendQueueTailIndex] = buffer;
	   m_sendQueueTailIndex = ((m_sendQueueTailIndex+1) % m_sendQueueSize);
	}
	else
	{
	   delete(buffer);
	}

	m_mutex->unlock();
	// }}}USR
}
// }}}RME

// {{{RME operation 'dequeueReceiveData()'
DataBuffer * Queuing::dequeueReceiveData( void )
{
	// {{{USR
	DataBuffer* buffer=0;

	m_mutex->lock();

	// If there is data in the queue, extract and return it.
	// Otherwise return zero.
	if (m_receiveQueueHeadIndex != m_receiveQueueTailIndex)
	{
	   buffer = m_receiveQueue[m_receiveQueueHeadIndex];
	   m_receiveQueue[m_receiveQueueHeadIndex] = 0;
	   m_receiveQueueHeadIndex = ((m_receiveQueueHeadIndex+1) % m_receiveQueueSize);
	}

	m_mutex->unlock();

	return buffer;
	// }}}USR
}
// }}}RME

// {{{RME operation 'dequeueSendData()'
DataBuffer * Queuing::dequeueSendData( void )
{
	// {{{USR
	DataBuffer* buffer = 0;
	m_mutex->lock();

	// If there is data in the queue, extract and return it.
	// Otherwise return zero.

	if (m_sendQueueHeadIndex != m_sendQueueTailIndex)
	{
	   buffer = m_sendQueue[m_sendQueueHeadIndex];
	   m_sendQueue[m_sendQueueHeadIndex] = 0;
	   m_sendQueueHeadIndex = ((m_sendQueueHeadIndex+1) % m_sendQueueSize);
	}

	m_mutex->unlock();
	return(buffer);

	// }}}USR
}
// }}}RME

// {{{RME operation '~Queuing()'
Queuing::~Queuing( void )
{
	// {{{USR
	delete m_mutex;

	unsigned int i;

	for (i=0; i<m_receiveQueueSize; i++)
	{
	   delete(m_receiveQueue[i]);
	   m_receiveQueue[i] = 0;
	}

	delete[](m_receiveQueue);

	for (i=0; i<m_sendQueueSize; i++)
	{
	   delete(m_sendQueue[i]);
	   m_sendQueue[i] = 0;
	}

	delete[](m_sendQueue);
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
