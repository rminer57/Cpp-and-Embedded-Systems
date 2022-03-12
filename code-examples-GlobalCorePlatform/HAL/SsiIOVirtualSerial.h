// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OMAP::Ssi::SsiIOVirtualSerial::SsiIOVirtualSerial'

#ifndef SsiIOVirtualSerial_H
#define SsiIOVirtualSerial_H

#ifdef PRAGMA
#pragma interface "SsiIOVirtualSerial.h"
#endif

#include <serial_comp.h>
#include <Connection.h>
#include <IOVirtualSerial.h>
class DataBuffer;
class Mutex;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Status' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class SsiIOVirtualSerial : public IOVirtualSerial
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
	struct RTState_SsiIOVirtualSerial
	{
		inline RTState_SsiIOVirtualSerial( void )
			: state( 1U )
		{
		}
		inline ~RTState_SsiIOVirtualSerial( void )
		{
		}
		unsigned char state;
	};

public:
	// {{{RME classifier 'Status'
	class Status : public Connection::Status
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
		// {{{RME classAttribute 'm_isDataAvailable'
		bool m_isDataAvailable;
		// }}}RME

	public:
		// {{{RME associationEnd 'm_rxDataAvailableEvent'
		Connection::Status::Event * m_rxDataAvailableEvent;
		// }}}RME
		// {{{RME operation 'Status()'
		Status( void );
		// }}}RME
		// {{{RME operation 'isDataAvailable()'
		virtual bool isDataAvailable( void ) const;
		// }}}RME
		// {{{RME operation 'setDataAvailable(bool)'
		void setDataAvailable( bool dataAvailable );
		// }}}RME
		// {{{RME operation '~Status()'
		~Status( void );
		// }}}RME
	};
	// }}}RME

private:
	RTState_SsiIOVirtualSerial rtg_state_SsiIOVirtualSerial;

protected:
	// {{{RME classAttribute 'IDLE_HIGH'
	static const unsigned short int IDLE_HIGH;
	// }}}RME
	// {{{RME classAttribute 'IDLE_HIGH_SUB'
	static const unsigned short int IDLE_HIGH_SUB;
	// }}}RME
	// {{{RME classAttribute 'IDLE_LOW'
	static const unsigned short int IDLE_LOW;
	// }}}RME
	// {{{RME classAttribute 'IDLE_LOW_SUB'
	static const unsigned short int IDLE_LOW_SUB;
	// }}}RME
	// {{{RME classAttribute 'STX'
	static const unsigned short int STX;
	// }}}RME
	// {{{RME classAttribute 'ESC'
	static const unsigned short int ESC;
	// }}}RME
	// {{{RME classAttribute 'XOR'
	static const unsigned short int XOR;
	// }}}RME

private:
	// {{{RME classAttribute 'm_receiveQueue'
	DataBuffer * * m_receiveQueue;
	// }}}RME
	// {{{RME classAttribute 'm_sendQueue'
	DataBuffer * * m_sendQueue;
	// }}}RME
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
	// {{{RME classAttribute 'm_nextReceivedWord'
	unsigned short int m_nextReceivedWord;
	// }}}RME
	// {{{RME classAttribute 'm_currentReceiveBuffer'
	DataBuffer * m_currentReceiveBuffer;
	// }}}RME
	// {{{RME classAttribute 'm_currentSendBuffer'
	DataBuffer * m_currentSendBuffer;
	// }}}RME
	// {{{RME classAttribute 'm_escWord'
	unsigned short int m_escWord;
	// }}}RME
	// {{{RME classAttribute 'm_sendMutex'
	Mutex * m_sendMutex;
	// }}}RME
	// {{{RME classAttribute 'm_currentReceiveSize'
	unsigned short m_currentReceiveSize;
	// }}}RME
	// {{{RME classAttribute 'm_receiveIndex'
	unsigned int m_receiveIndex;
	// }}}RME
	// {{{RME classAttribute 'm_receiveQueueSize'
	unsigned int m_receiveQueueSize;
	// }}}RME
	// {{{RME classAttribute 'm_sendQueueSize'
	unsigned int m_sendQueueSize;
	// }}}RME
	// {{{RME classAttribute 'm_maxBufferSize'
	unsigned int m_maxBufferSize;
	// }}}RME
	// {{{RME classAttribute 'm_sentStxFlag'
	bool m_sentStxFlag;
	// }}}RME
	// {{{RME classAttribute 'm_receiveMutex'
	Mutex * m_receiveMutex;
	// }}}RME

public:
	// {{{RME associationEnd 'm_status'
	Status * m_status;
	// }}}RME

protected:
	// {{{RME operation 'SsiIOVirtualSerial(unsigned int,unsigned int,unsigned int)'
	SsiIOVirtualSerial( unsigned int sendQueueSize = 64, unsigned int receiveQueueSize = 64, unsigned int maxBufferSize = 2048 );
	// }}}RME

public:
	// {{{RME operation 'send(Array*)'
	virtual bool send( Array * buf );
	// }}}RME
	// {{{RME operation 'receive()'
	virtual Array * receive( void );
	// }}}RME
	// {{{RME operation 'getStatus()'
	virtual Connection::Status * getStatus( void );
	// }}}RME
	// {{{RME operation 'deactivate()'
	virtual bool deactivate( void );
	// }}}RME
	// {{{RME operation 'activate()'
	virtual bool activate( void );
	// }}}RME

protected:
	// {{{RME operation 'storeReceivedWord(uint16_t)'
	void storeReceivedWord( uint16_t word );
	// }}}RME
	// {{{RME operation 'isWordAvailableToSend()'
	bool isWordAvailableToSend( void );
	// }}}RME
	// {{{RME operation 'getWordToSend()'
	uint16_t getWordToSend( void );
	// }}}RME
	// {{{RME operation 'dataAvailableToSend()'
	virtual void dataAvailableToSend( void ) = 0;
	// }}}RME

private:
	// {{{RME operation 'enqueueReceiveData(DataBuffer*)'
	void enqueueReceiveData( DataBuffer * buffer );
	// }}}RME
	// {{{RME operation 'enqueueSendData(DataBuffer*)'
	void enqueueSendData( DataBuffer * buffer );
	// }}}RME
	// {{{RME operation 'dequeueReceiveData()'
	DataBuffer * dequeueReceiveData( void );
	// }}}RME
	// {{{RME operation 'dequeueSendData()'
	DataBuffer * dequeueSendData( void );
	// }}}RME
	// {{{RME operation 'substituteSerialWord(unsigned short)'
	unsigned short substituteSerialWord( unsigned short word );
	// }}}RME
	// {{{RME operation 'extractSerialWord(DataBuffer*)'
	unsigned short extractSerialWord( DataBuffer * buffer );
	// }}}RME
	// {{{RME operation 'prependSerialWord(unsigned short,DataBuffer*)'
	void prependSerialWord( unsigned short word, DataBuffer * buffer );
	// }}}RME
	// {{{RME operation 'appendSerialWord(unsigned short,DataBuffer*)'
	void appendSerialWord( unsigned short word, DataBuffer * buffer );
	// }}}RME
	// {{{RME operation 'processNextReceiveWord()'
	void processNextReceiveWord( void );
	// }}}RME
	// {{{RME operation 'processLastReceivedWord()'
	void processLastReceivedWord( void );
	// }}}RME

public:
	// {{{RME operation '~SsiIOVirtualSerial()'
	virtual ~SsiIOVirtualSerial( void );
	// }}}RME

private:
	void rtg_init1( void );
	// {{{RME operation 'triggerReceive()'
	void triggerReceive( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Status' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* SsiIOVirtualSerial_H */

// }}}RME
