// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OMAP::Ssi::SsiIOVirtualSerial::SsiIOVirtualSerial'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "SsiIOVirtualSerial.h"
#endif

#include <serial_comp.h>
#include <SsiIOVirtualSerial.h>
#include <DataBuffer.h>
#include <Mutex.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Status' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classifier 'Status'

// {{{RME operation 'Status()'
SsiIOVirtualSerial::Status::Status( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_isDataAvailable(false)
	// }}}USR
	// }}}RME
{
	// {{{USR
	m_rxDataAvailableEvent = new Connection::Status::Event(Connection::Status::Event::DATA_AVAILABLE);

	// }}}USR
}
// }}}RME

// {{{RME operation 'isDataAvailable()'
bool SsiIOVirtualSerial::Status::isDataAvailable( void ) const
{
	// {{{USR
	return m_isDataAvailable;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setDataAvailable(bool)'
void SsiIOVirtualSerial::Status::setDataAvailable( bool dataAvailable )
{
	// {{{USR
	m_isDataAvailable = dataAvailable;

	if (m_isDataAvailable)
	{
	   informListeners(m_rxDataAvailableEvent);
	}

	// }}}USR
}
// }}}RME

// {{{RME operation '~Status()'
SsiIOVirtualSerial::Status::~Status( void )
{
	// {{{USR
	delete m_rxDataAvailableEvent;
	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME classAttribute 'IDLE_HIGH'
const unsigned short int SsiIOVirtualSerial::IDLE_HIGH( 0xFFFF );
// }}}RME

// {{{RME classAttribute 'IDLE_HIGH_SUB'
const unsigned short int SsiIOVirtualSerial::IDLE_HIGH_SUB( 0x0EE1 );
// }}}RME

// {{{RME classAttribute 'IDLE_LOW'
const unsigned short int SsiIOVirtualSerial::IDLE_LOW( 0x0000 );
// }}}RME

// {{{RME classAttribute 'IDLE_LOW_SUB'
const unsigned short int SsiIOVirtualSerial::IDLE_LOW_SUB( 0x0EE0 );
// }}}RME

// {{{RME classAttribute 'STX'
const unsigned short int SsiIOVirtualSerial::STX( 0x0ED0 );
// }}}RME

// {{{RME classAttribute 'ESC'
const unsigned short int SsiIOVirtualSerial::ESC( 0x0ED2 );
// }}}RME

// {{{RME classAttribute 'XOR'
const unsigned short int SsiIOVirtualSerial::XOR( 0xA0A0 );
// }}}RME

// {{{RME operation 'SsiIOVirtualSerial(unsigned int,unsigned int,unsigned int)'
SsiIOVirtualSerial::SsiIOVirtualSerial( unsigned int sendQueueSize, unsigned int receiveQueueSize, unsigned int maxBufferSize )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_maxBufferSize(maxBufferSize), m_sendQueueSize(sendQueueSize), m_receiveQueueSize(receiveQueueSize), m_receiveQueueHeadIndex(0), m_sendQueueHeadIndex(0), m_receiveQueueTailIndex(0), m_sendQueueTailIndex(0), m_currentReceiveBuffer(0), m_currentSendBuffer(0), m_escWord(0), m_sentStxFlag(false)
	// }}}USR
	// }}}RME
{
	// {{{USR
	unsigned int i;

	m_receiveQueue = new DataBuffer*[m_receiveQueueSize];
	m_sendQueue = new DataBuffer*[m_sendQueueSize];

	for (i=0; i<m_receiveQueueSize; i++)
	{
	   m_receiveQueue[i] = 0;
	}

	for (i=0; i<m_sendQueueSize; i++)
	{
	   m_sendQueue[i] = 0;
	}

	m_status = new SsiIOVirtualSerial::Status();

	m_sendMutex = Mutex::createMutex();
	m_receiveMutex = Mutex::createMutex();

	// Initialize receive state machine
	rtg_init1();
	// }}}USR
}
// }}}RME

// {{{RME operation 'send(Array*)'
bool SsiIOVirtualSerial::send( Array * buf )
{
	// {{{USR
	bool returnValue = false;
	if (buf->isType(DataBuffer::DATA_BUFFER_ARRAY))
	{
		DataBuffer *buffer = (DataBuffer *)buf;				//Type safe up cast
		unsigned short size;

		if(buffer != 0)
		{
		   size = buffer->getSize();

		   if(size != 0)
		   {
		      returnValue = true;

		      prependSerialWord(size, buffer);

	          m_sendMutex->lock();

		      if(m_currentSendBuffer == 0)
		      {
		         m_currentSendBuffer = buffer;
		      }
		      else
		      {
		         enqueueSendData(buffer);
		      }

	          m_sendMutex->unlock();

		      dataAvailableToSend();
		   }
		}
	}

	return(returnValue);
	// }}}USR
}
// }}}RME

// {{{RME operation 'receive()'
Array * SsiIOVirtualSerial::receive( void )
{
	// {{{USR
	return(dequeueReceiveData());

	// }}}USR
}
// }}}RME

// {{{RME operation 'getStatus()'
Connection::Status * SsiIOVirtualSerial::getStatus( void )
{
	// {{{USR
	return m_status;
	// }}}USR
}
// }}}RME

// {{{RME operation 'deactivate()'
bool SsiIOVirtualSerial::deactivate( void )
{
	// {{{USR
	// Not implemented.

	return(true);

	// }}}USR
}
// }}}RME

// {{{RME operation 'activate()'
bool SsiIOVirtualSerial::activate( void )
{
	// {{{USR
	// Not implemented.

	return(true);

	// }}}USR
}
// }}}RME

// {{{RME operation 'storeReceivedWord(uint16_t)'
void SsiIOVirtualSerial::storeReceivedWord( uint16_t word )
{
	// {{{USR
	m_nextReceivedWord = word;

	triggerReceive();
	// }}}USR
}
// }}}RME

// {{{RME operation 'isWordAvailableToSend()'
bool SsiIOVirtualSerial::isWordAvailableToSend( void )
{
	// {{{USR
	return(m_currentSendBuffer != 0);
	// }}}USR
}
// }}}RME

// {{{RME operation 'getWordToSend()'
uint16_t SsiIOVirtualSerial::getWordToSend( void )
{
	// {{{USR
	unsigned short int word = IDLE_HIGH;

	if(!m_sentStxFlag)
	{
	   word = STX;
	   m_sentStxFlag = true;
	}
	else
	{
	   if (m_escWord != 0)
	   {
	      word = m_escWord;
	      m_escWord = 0;

	      if(m_currentSendBuffer->getSize() == 0)
	      {
	         m_sendMutex->lock();
	         delete m_currentSendBuffer;
	         m_currentSendBuffer=dequeueSendData();
	         m_sentStxFlag = false;
	         m_sendMutex->unlock();
	      }
	   }
	   else if(m_currentSendBuffer != 0)
	   {
	      word = extractSerialWord(m_currentSendBuffer);

	      // Perform substitution
	      word = substituteSerialWord(word);

	      // Perform escaping
	      if((word == IDLE_HIGH) ||
	      (word == IDLE_LOW)  ||
	      (word == STX)       ||
	      (word == ESC))
	      {
	         m_escWord = word ^ XOR;

	         word = ESC;
	      }
	      else if(m_currentSendBuffer->getSize() == 0)
	      {
	         m_sendMutex->lock();
	         delete m_currentSendBuffer;
	         m_currentSendBuffer=dequeueSendData();
	         m_sentStxFlag = false;
	         m_sendMutex->unlock();
	      }

	   }
	}
	return word;
	// }}}USR
}
// }}}RME

// {{{RME operation 'enqueueReceiveData(DataBuffer*)'
void SsiIOVirtualSerial::enqueueReceiveData( DataBuffer * buffer )
{
	// {{{USR
	m_receiveMutex->lock();

	// If there is still room in the queue, add the buffer.
	// Otherwise throw it away.
	if (((m_receiveQueueTailIndex+1) % m_receiveQueueSize) != m_receiveQueueHeadIndex)
	{
	   m_receiveQueue[m_receiveQueueTailIndex] = buffer;
	   m_receiveQueueTailIndex = ((m_receiveQueueTailIndex+1) % m_receiveQueueSize);
	   m_receiveMutex->unlock();
	   m_status->setDataAvailable(true);
	   m_receiveMutex->lock();
	}
	else
	{
	   delete(buffer);
	}

	m_receiveMutex->unlock();
	// }}}USR
}
// }}}RME

// {{{RME operation 'enqueueSendData(DataBuffer*)'
void SsiIOVirtualSerial::enqueueSendData( DataBuffer * buffer )
{
	// {{{USR
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


	// }}}USR
}
// }}}RME

// {{{RME operation 'dequeueReceiveData()'
DataBuffer * SsiIOVirtualSerial::dequeueReceiveData( void )
{
	// {{{USR
	DataBuffer* buffer = 0;

	m_receiveMutex->lock();

	// If there is data in the queue, extract and return it.
	// Otherwise return zero.
	if (m_receiveQueueHeadIndex != m_receiveQueueTailIndex)
	{
	   buffer = m_receiveQueue[m_receiveQueueHeadIndex];
	   m_receiveQueue[m_receiveQueueHeadIndex] = 0;
	   m_receiveQueueHeadIndex = ((m_receiveQueueHeadIndex+1) % m_receiveQueueSize);
	}

	if(m_receiveQueueHeadIndex==m_receiveQueueTailIndex)
	{
	   m_receiveMutex->unlock();
	   m_status->setDataAvailable(false);
	   m_receiveMutex->lock();
	}

	m_receiveMutex->unlock();

	return(buffer);

	// }}}USR
}
// }}}RME

// {{{RME operation 'dequeueSendData()'
DataBuffer * SsiIOVirtualSerial::dequeueSendData( void )
{
	// {{{USR
	DataBuffer* buffer = 0;

	// If there is data in the queue, extract and return it.
	// Otherwise return zero.

	if (m_sendQueueHeadIndex != m_sendQueueTailIndex)
	{
	   buffer = m_sendQueue[m_sendQueueHeadIndex];
	   m_sendQueue[m_sendQueueHeadIndex] = 0;
	   m_sendQueueHeadIndex = ((m_sendQueueHeadIndex+1) % m_sendQueueSize);
	}

	return(buffer);

	// }}}USR
}
// }}}RME

// {{{RME operation 'substituteSerialWord(unsigned short)'
unsigned short SsiIOVirtualSerial::substituteSerialWord( unsigned short word )
{
	// {{{USR
	// Check for substitute words
	if (word == IDLE_HIGH)
	{
	   word = IDLE_HIGH_SUB;
	}
	else if(word == IDLE_LOW)
	{
	   word = IDLE_LOW_SUB;
	}
	else if (word == IDLE_HIGH_SUB)
	{
	   word = IDLE_HIGH;
	}
	else if(word == IDLE_LOW_SUB)
	{
	   word = IDLE_LOW;
	}

	return word;
	// }}}USR
}
// }}}RME

// {{{RME operation 'extractSerialWord(DataBuffer*)'
unsigned short SsiIOVirtualSerial::extractSerialWord( DataBuffer * buffer )
{
	// {{{USR
	unsigned short word;

	word = (((((unsigned short int)(*buffer)[0]) << 8) & 0xFF00) |
	         (((unsigned short int)(*buffer)[1])       & 0x00FF));

	buffer->erase(0,2);

	return word;
	// }}}USR
}
// }}}RME

// {{{RME operation 'prependSerialWord(unsigned short,DataBuffer*)'
void SsiIOVirtualSerial::prependSerialWord( unsigned short word, DataBuffer * buffer )
{
	// {{{USR
	unsigned char temp[2];

	// Translate Word
	temp[0] = (word >> 8) & 0xFF;
	temp[1] =  word       & 0xFF;

	// Append it to databuffer
	buffer->add(temp,2);
	// }}}USR
}
// }}}RME

// {{{RME operation 'appendSerialWord(unsigned short,DataBuffer*)'
void SsiIOVirtualSerial::appendSerialWord( unsigned short word, DataBuffer * buffer )
{
	// {{{USR
	unsigned char temp[2];

	// Translate Word
	temp[0] = (word >> 8) & 0xFF;
	temp[1] =  word       & 0xFF;

	// Append it to databuffer
	buffer->append(temp,2);
	// }}}USR
}
// }}}RME

// {{{RME operation 'processNextReceiveWord()'
void SsiIOVirtualSerial::processNextReceiveWord( void )
{
	// {{{USR
	m_nextReceivedWord = substituteSerialWord(m_nextReceivedWord);

	appendSerialWord(m_nextReceivedWord, m_currentReceiveBuffer);

	m_currentReceiveSize-=2;
	// }}}USR
}
// }}}RME

// {{{RME operation 'processLastReceivedWord()'
void SsiIOVirtualSerial::processLastReceivedWord( void )
{
	// {{{USR
	unsigned char temp;

	m_nextReceivedWord = substituteSerialWord(m_nextReceivedWord);


	if(m_currentReceiveSize==2)
	{
	   appendSerialWord(m_nextReceivedWord, m_currentReceiveBuffer);
	}
	else
	{

	   temp = (m_nextReceivedWord >> 8) & 0xFF;

	   m_currentReceiveBuffer->append((unsigned char*)&temp,1);

	}

	m_currentReceiveSize=0;
	enqueueReceiveData(m_currentReceiveBuffer);
	m_currentReceiveBuffer=0;
	// }}}USR
}
// }}}RME

// {{{RME operation '~SsiIOVirtualSerial()'
SsiIOVirtualSerial::~SsiIOVirtualSerial( void )
{
	// {{{USR
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

	delete m_status;

	delete m_sendMutex;
	delete m_receiveMutex;
	// }}}USR
}
// }}}RME

void SsiIOVirtualSerial::rtg_init1( void )
{
	// {{{RME transition ':TOP:Initial:Initial'
	{
		// {{{USR

		// }}}USR
	}
	// }}}RME
	rtg_state_SsiIOVirtualSerial.state = 2U;
}

// {{{RME operation 'triggerReceive()'
void SsiIOVirtualSerial::triggerReceive( void )
{
	unsigned char rtg_state = rtg_state_SsiIOVirtualSerial.state;
	for(;;)
	{
		switch( rtg_state )
		{
		case 2U:
			// {{{RME state ':TOP:WAITING_TO_START_RECEIVING_NEW_MESSAGE'
			// {{{RME transition ':TOP:WAITING_TO_START_RECEIVING_NEW_MESSAGE:J4006DB6B02E7:STX' guard '1'
			if(
				// {{{USR
				(m_nextReceivedWord == STX)
				// }}}USR
				)
			// }}}RME
			{
				// {{{RME transition ':TOP:WAITING_TO_START_RECEIVING_NEW_MESSAGE:J4006DB6B02E7:STX'
				{
					// {{{USR

					// }}}USR
				}
				// }}}RME
				rtg_state_SsiIOVirtualSerial.state = 5U;
				return;
			}
			rtg_state = 1U;
			break;
			// }}}RME
		case 3U:
			// {{{RME state ':TOP:WAITING_FOR_NEXT_RECEIVED_WORD_OF_MESSAGE'
			// {{{RME transition ':TOP:WAITING_FOR_NEXT_RECEIVED_WORD_OF_MESSAGE:J400DAE8E0398:STX' guard '1'
			if(
				// {{{USR
				(m_nextReceivedWord == STX)
				// }}}USR
				)
			// }}}RME
			{
				// {{{RME transition ':TOP:WAITING_FOR_NEXT_RECEIVED_WORD_OF_MESSAGE:J400DAE8E0398:STX'
				{
					// {{{USR
					delete m_currentReceiveBuffer;
					m_currentReceiveBuffer=0;
					m_currentReceiveSize=0;
					// }}}USR
				}
				// }}}RME
				rtg_state_SsiIOVirtualSerial.state = 5U;
				return;
			}
			// {{{RME transition ':TOP:WAITING_FOR_NEXT_RECEIVED_WORD_OF_MESSAGE:J4006DBF7020C:Done' guard '1'
			if(
				// {{{USR
				(m_nextReceivedWord != IDLE_HIGH) && (m_nextReceivedWord != IDLE_LOW) && (m_nextReceivedWord != STX) && (m_nextReceivedWord != ESC) && (m_currentReceiveSize <= 2)
				// }}}USR
				)
			// }}}RME
			{
				// {{{RME transition ':TOP:WAITING_FOR_NEXT_RECEIVED_WORD_OF_MESSAGE:J4006DBF7020C:Done'
				{
					// {{{USR
					processLastReceivedWord();
					// }}}USR
				}
				// }}}RME
				rtg_state_SsiIOVirtualSerial.state = 2U;
				return;
			}
			// {{{RME transition ':TOP:WAITING_FOR_NEXT_RECEIVED_WORD_OF_MESSAGE:J4006DC1602C8:not_IDLE_STX_ESC' guard '1'
			if(
				// {{{USR
				(m_nextReceivedWord != IDLE_HIGH) && (m_nextReceivedWord != IDLE_LOW) && (m_nextReceivedWord != STX) && (m_nextReceivedWord != ESC) && (m_currentReceiveSize > 2)
				// }}}USR
				)
			// }}}RME
			{
				// {{{RME transition ':TOP:WAITING_FOR_NEXT_RECEIVED_WORD_OF_MESSAGE:J4006DC1602C8:not_IDLE_STX_ESC'
				{
					// {{{USR
					processNextReceiveWord();
					// }}}USR
				}
				// }}}RME
				rtg_state_SsiIOVirtualSerial.state = 3U;
				return;
			}
			// {{{RME transition ':TOP:WAITING_FOR_NEXT_RECEIVED_WORD_OF_MESSAGE:J4006DC3801BD:ESC' guard '1'
			if(
				// {{{USR
				(m_nextReceivedWord == ESC)
				// }}}USR
				)
			// }}}RME
			{
				// {{{RME transition ':TOP:WAITING_FOR_NEXT_RECEIVED_WORD_OF_MESSAGE:J4006DC3801BD:ESC'
				{
					// {{{USR

					// }}}USR
				}
				// }}}RME
				rtg_state_SsiIOVirtualSerial.state = 4U;
				return;
			}
			rtg_state = 1U;
			break;
			// }}}RME
		case 4U:
			// {{{RME state ':TOP:WAITING_TO_DE_ESCAPE_NEXT_RECEIVED_WORD_OF_MESSAGE'
			// {{{RME transition ':TOP:WAITING_TO_DE_ESCAPE_NEXT_RECEIVED_WORD_OF_MESSAGE:J4006DC6601DB:not_IDLE' guard '1'
			if(
				// {{{USR
				(m_nextReceivedWord != IDLE_HIGH) && (m_nextReceivedWord != IDLE_LOW) && (m_currentReceiveSize > 2)
				// }}}USR
				)
			// }}}RME
			{
				// {{{RME transition ':TOP:WAITING_TO_DE_ESCAPE_NEXT_RECEIVED_WORD_OF_MESSAGE:J4006DC6601DB:not_IDLE'
				{
					// {{{USR
					m_nextReceivedWord = m_nextReceivedWord ^ XOR;

					processNextReceiveWord();
					// }}}USR
				}
				// }}}RME
				rtg_state_SsiIOVirtualSerial.state = 3U;
				return;
			}
			// {{{RME transition ':TOP:WAITING_TO_DE_ESCAPE_NEXT_RECEIVED_WORD_OF_MESSAGE:J401566040168:Done' guard '1'
			if(
				// {{{USR
				(m_nextReceivedWord != IDLE_HIGH) && (m_nextReceivedWord != IDLE_LOW) && (m_currentReceiveSize <= 2)
				// }}}USR
				)
			// }}}RME
			{
				// {{{RME transition ':TOP:WAITING_TO_DE_ESCAPE_NEXT_RECEIVED_WORD_OF_MESSAGE:J401566040168:Done'
				{
					// {{{USR
					m_nextReceivedWord = m_nextReceivedWord ^ XOR;

					processLastReceivedWord();
					// }}}USR
				}
				// }}}RME
				rtg_state_SsiIOVirtualSerial.state = 2U;
				return;
			}
			rtg_state = 1U;
			break;
			// }}}RME
		case 5U:
			// {{{RME state ':TOP:WAITING_FOR_SIZE_OF_MESSAGE'
			// {{{RME transition ':TOP:WAITING_FOR_SIZE_OF_MESSAGE:J40107D7A001A:overflow' guard '1'
			if(
				// {{{USR
				((m_nextReceivedWord != IDLE_HIGH) && (m_nextReceivedWord != IDLE_LOW) && (m_nextReceivedWord != ESC) && (m_nextReceivedWord > m_maxBufferSize)) || (m_nextReceivedWord == IDLE_HIGH_SUB) || (m_nextReceivedWord == IDLE_LOW_SUB) || (m_nextReceivedWord == 0)
				// }}}USR
				)
			// }}}RME
			{
				// {{{RME transition ':TOP:WAITING_FOR_SIZE_OF_MESSAGE:J40107D7A001A:overflow'
				{
					// {{{USR
					m_currentReceiveSize = 0;
					// }}}USR
				}
				// }}}RME
				rtg_state_SsiIOVirtualSerial.state = 2U;
				return;
			}
			// {{{RME transition ':TOP:WAITING_FOR_SIZE_OF_MESSAGE:J400EAA810218:ESC' guard '1'
			if(
				// {{{USR
				(m_nextReceivedWord == ESC)
				// }}}USR
				)
			// }}}RME
			{
				// {{{RME transition ':TOP:WAITING_FOR_SIZE_OF_MESSAGE:J400EAA810218:ESC'
				{
					// {{{USR

					// }}}USR
				}
				// }}}RME
				rtg_state_SsiIOVirtualSerial.state = 6U;
				return;
			}
			// {{{RME transition ':TOP:WAITING_FOR_SIZE_OF_MESSAGE:J400DAADC02BB:not_IDLE_ESC' guard '1'
			if(
				// {{{USR
				(m_nextReceivedWord != IDLE_HIGH) && (m_nextReceivedWord != IDLE_LOW) && (m_nextReceivedWord != ESC) && (m_nextReceivedWord != IDLE_HIGH_SUB) && (m_nextReceivedWord != IDLE_LOW_SUB) && (m_nextReceivedWord <= m_maxBufferSize)
				// }}}USR
				)
			// }}}RME
			{
				// {{{RME transition ':TOP:WAITING_FOR_SIZE_OF_MESSAGE:J400DAADC02BB:not_IDLE_ESC'
				{
					// {{{USR
					m_currentReceiveSize = substituteSerialWord(m_nextReceivedWord);

					m_currentReceiveBuffer = new DataBuffer(0,0,false,0,m_currentReceiveSize);
					// }}}USR
				}
				// }}}RME
				rtg_state_SsiIOVirtualSerial.state = 3U;
				return;
			}
			rtg_state = 1U;
			break;
			// }}}RME
		case 6U:
			// {{{RME state ':TOP:WAITING_TO_DE_ESCAPE_SIZE'
			// {{{RME transition ':TOP:WAITING_TO_DE_ESCAPE_SIZE:J400E85E002CA:not_IDLE' guard '1'
			if(
				// {{{USR
				(m_nextReceivedWord != IDLE_HIGH) && (m_nextReceivedWord != IDLE_LOW) && (m_nextReceivedWord <= m_maxBufferSize)
				// }}}USR
				)
			// }}}RME
			{
				// {{{RME transition ':TOP:WAITING_TO_DE_ESCAPE_SIZE:J400E85E002CA:not_IDLE'
				{
					// {{{USR
					m_nextReceivedWord = m_nextReceivedWord ^ XOR;

					m_currentReceiveSize = substituteSerialWord(m_nextReceivedWord);

					m_currentReceiveBuffer = new DataBuffer(0,0,false,0,m_currentReceiveSize);
					// }}}USR
				}
				// }}}RME
				rtg_state_SsiIOVirtualSerial.state = 3U;
				return;
			}
			// {{{RME transition ':TOP:WAITING_TO_DE_ESCAPE_SIZE:J401562CC0082:overflow' guard '1'
			if(
				// {{{USR
				((m_nextReceivedWord != IDLE_HIGH) && (m_nextReceivedWord != IDLE_LOW) && (m_nextReceivedWord > m_maxBufferSize)) || (m_nextReceivedWord == IDLE_HIGH_SUB) || (m_nextReceivedWord == IDLE_LOW_SUB) || (m_nextReceivedWord == 0)
				// }}}USR
				)
			// }}}RME
			{
				// {{{RME transition ':TOP:WAITING_TO_DE_ESCAPE_SIZE:J401562CC0082:overflow'
				{
					// {{{USR
					m_currentReceiveSize = 0;
					// }}}USR
				}
				// }}}RME
				rtg_state_SsiIOVirtualSerial.state = 2U;
				return;
			}
			rtg_state = 1U;
			break;
			// }}}RME
		default:
			return;
		}
	}
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Status' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
