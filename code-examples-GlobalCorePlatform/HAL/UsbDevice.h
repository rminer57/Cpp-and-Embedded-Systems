// {{{RME classifier 'Logical View::Usb::UsbDevice::UsbDevice'

#ifndef UsbDevice_H
#define UsbDevice_H

#ifdef PRAGMA
#pragma interface "UsbDevice.h"
#endif

#include <usbimp.h>
#include <Configurable.h>
#include <Connection.h>
#include <IOVirtualSerial.h>
#include <Thread.h>
#include <UartConfig.h>
class DataQueue;
class GlobalUSBConfiguration;
class Mutex;
class PointerQueue;
class RXThresholdEvent;
class SCharArray;
class USBConfigMgr;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
struct _TestModem;
// }}}USR
// }}}RME
// {{{RME classifier 'Status' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'ReceiveThread' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'SendThread' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class UsbDevice : public IOVirtualSerial
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

public:
	// {{{RME classifier 'Status'
	class Status : public Thread, public Connection::Status
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
		// {{{RME classAttribute 'MAX_EVENT_QUEUE_SIZE'
		static const uint16_t MAX_EVENT_QUEUE_SIZE;
		// }}}RME
		// {{{RME classAttribute 'm_isDataAvailable'
		bool m_isDataAvailable;
		// }}}RME
		// {{{RME classAttribute 'm_isAvailable'
		bool m_isAvailable;
		// }}}RME
		// {{{RME classAttribute 'm_mutex'
		Mutex * m_mutex;
		// }}}RME

	public:
		// {{{RME associationEnd 'm_eventQueue'
		PointerQueue * m_eventQueue;
		// }}}RME
		// {{{RME associationEnd 'm_deviceDetached'
		Connection::Status::Event * m_deviceDetached;
		// }}}RME
		// {{{RME associationEnd 'm_deviceAttached'
		Connection::Status::Event * m_deviceAttached;
		// }}}RME
		// {{{RME associationEnd 'm_dataAvailable'
		Connection::Status::Event * m_dataAvailable;
		// }}}RME
		// {{{RME associationEnd 'm_threshold'
		RXThresholdEvent * m_threshold;
		// }}}RME
		// {{{RME operation 'Status(Mutex*)'
		Status( Mutex * mutex );
		// }}}RME

	protected:
		// {{{RME operation 'main()'
		virtual void * main( void );
		// }}}RME

	public:
		// {{{RME operation 'createThread(int,Mutex*)'
		static Thread * createThread( int priority, Mutex * mutex );
		// }}}RME
		// {{{RME operation 'isDataAvailable()'
		virtual bool isDataAvailable( void ) const;
		// }}}RME
		// {{{RME operation 'setDataAvailable(bool)'
		void setDataAvailable( bool dataAvailable );
		// }}}RME
		// {{{RME operation 'isAvailable()'
		virtual bool isAvailable( void ) const;
		// }}}RME
		// {{{RME operation 'setAvailable(bool)'
		void setAvailable( bool available );
		// }}}RME
		// {{{RME operation '~Status()'
		~Status( void );
		// }}}RME
	};
	// }}}RME
	// {{{RME classifier 'ReceiveThread'
	class ReceiveThread : public Thread
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
		// {{{RME classAttribute 'm_modem'
		_TestModem * m_modem;
		// }}}RME
		// {{{RME classAttribute 'm_connectionStatus'
		Connection::Status * m_connectionStatus;
		// }}}RME

	public:
		// {{{RME associationEnd 'm_receiveDataQueue'
		DataQueue * m_receiveDataQueue;
		// }}}RME
		// {{{RME operation 'createThread(int,_TestModem*,Connection::Status*)'
		static Thread * createThread( int priority, _TestModem * modem, Connection::Status * connectionStatus );
		// }}}RME
		// {{{RME operation 'ReceiveThread(_TestModem*,Connection::Status*)'
		ReceiveThread( _TestModem * modem, Connection::Status * connectionStatus );
		// }}}RME
		// {{{RME operation 'main()'
		void * main( void );
		// }}}RME
		// {{{RME operation '~ReceiveThread()'
		~ReceiveThread( void );
		// }}}RME
	};
	// }}}RME
	// {{{RME classifier 'SendThread'
	class SendThread : public Thread
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
		// {{{RME classAttribute 'm_modem'
		_TestModem * m_modem;
		// }}}RME

	public:
		// {{{RME associationEnd 'm_sendMessageQueue'
		PointerQueue * m_sendMessageQueue;
		// }}}RME
		// {{{RME operation 'SendThread(_TestModem*,PointerQueue*)'
		SendThread( _TestModem * modem, PointerQueue * messageQueue );
		// }}}RME
		// {{{RME operation 'main()'
		void * main( void );
		// }}}RME
		// {{{RME operation 'createThread(int,_TestModem*,PointerQueue*)'
		static Thread * createThread( int priority, _TestModem * modem, PointerQueue * messageQueue );
		// }}}RME
		// {{{RME operation '~SendThread()'
		~SendThread( void );
		// }}}RME
	};
	// }}}RME

private:
	// {{{RME classAttribute 'm_modem'
	_TestModem * m_modem;
	// }}}RME
	// {{{RME classAttribute 'm_sendSemaTimeOutValue'
	uint32_t m_sendSemaTimeOutValue;
	// }}}RME

public:
	// {{{RME classAttribute 'm_threshold'
	uint32_t m_threshold;
	// }}}RME

private:
	// {{{RME classAttribute 'm_mutex'
	Mutex * m_mutex;
	// }}}RME

public:
	// {{{RME associationEnd 'm_status'
	Status * m_status;
	// }}}RME
	// {{{RME associationEnd 'm_receiveDataQueue'
	DataQueue * m_receiveDataQueue;
	// }}}RME
	// {{{RME associationEnd 'm_sendMessageQueue'
	PointerQueue * m_sendMessageQueue;
	// }}}RME
	// {{{RME associationEnd 'm_uartConfig'
	UartConfig m_uartConfig;
	// }}}RME
	// {{{RME operation 'UsbDevice(USBConfigMgr *,UartConfig*,uint32_t)'
	UsbDevice( USBConfigMgr * ConfigMgrPtr, UartConfig * config, uint32_t sendSemaTimeOutValue = 2 );
	// }}}RME
	// {{{RME operation 'send(Array *)'
	virtual bool send( Array * buffer );
	// }}}RME
	// {{{RME operation 'receive()'
	virtual Array * receive( void );
	// }}}RME
	// {{{RME operation 'deactivate()'
	virtual bool deactivate( void );
	// }}}RME
	// {{{RME operation 'activate()'
	virtual bool activate( void );
	// }}}RME
	// {{{RME operation 'getStatus()'
	virtual Connection::Status * getStatus( void );
	// }}}RME
	// {{{RME operation 'getOption(ClassType)'
	virtual Configurable::Option * getOption( ClassType optionType ) const;
	// }}}RME
	// {{{RME operation 'setOption(Configurable::Option *)'
	virtual bool setOption( Configurable::Option * option );
	// }}}RME
	// {{{RME operation '~UsbDevice()'
	~UsbDevice( void );
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
// {{{RME classifier 'ReceiveThread' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'SendThread' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* UsbDevice_H */

// }}}RME
