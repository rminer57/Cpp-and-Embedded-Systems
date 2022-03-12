// {{{RME classifier 'Logical View::UsbPrivate::UsbOsFacade::OS_Facade'

#ifndef OS_Facade_H
#define OS_Facade_H

#ifdef PRAGMA
#pragma interface "OS_Facade.h"
#endif

#include <usbimp.h>
#include <NotifierBase.h>
#include <UsbDevice.h>
class DataQueue;
class DeviceInterruptRegistration;
class GlobalUSBConfiguration;
class HALiNucleusNotifier;
class HostInterruptRegistration;
class IOVirtual;
class IOVirtualSerial;
class Mutex;
class PointerQueue;
class PortConfiguration;
class SCharArray;
class Sem;
class Thread;
class TimeSpec;
class USBConfigMgr;
class UsbThread;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
extern USBConfigMgr* globalConfigManagerRef;

typedef Sem OS_Facade_Sem;
typedef UsbThread OS_Facade_Thread;
typedef unsigned int OS_Facade_MessageQueue;

#define OS_FACADE_ATTACH_EVENT    1
#define OS_FACADE_DETACH_EVENT    2
#define OS_FACADE_DATA_AVAILABLE_EVENT 3
#define OS_FACADE_DATA_THRESHOLD_EVENT 4

#define PORT0_DEV_VBUS_DET         0
#define PORT0_DEV_PUEN             1
#define PORT0_HOST_PWR_EN          2
#define PORT0_HOST_OVERCUR_DET     3
#define PORT0_USB_SUSPEND          4
#define PORT0_USB_SPEED            5

#define PORT1_DEV_VBUS_DET         6
#define PORT1_DEV_PUEN             7
#define PORT1_HOST_PWR_EN          8
#define PORT1_HOST_OVERCUR_DET     9
#define PORT1_USB_SUSPEND          10
#define PORT1_USB_SPEED            11

#define PORT2_DEV_VBUS_DET         12
#define PORT2_DEV_PUEN             13
#define PORT2_HOST_PWR_EN          14
#define PORT2_HOST_OVERCUR_DET     15
#define PORT2_USB_SUSPEND          16
#define PORT2_USB_SPEED            17

#define PORT2A_DEV_VBUS_DET        18
#define PORT2A_DEV_PUEN            19
#define PORT2A_HOST_PWR_EN         20
#define PORT2A_HOST_OVERCUR_DET    21
#define PORT2A_USB_SUSPEND         22
#define PORT2A_USB_SPEED           23
// }}}USR
// }}}RME

class OS_Facade : public NotifierBase
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
	// {{{RME classAttribute 'm_connectionStatusRef'
	UsbDevice::Status * m_connectionStatusRef;
	// }}}RME

private:
	// {{{RME classAttribute 'm_connectionAvailable'
	bool m_connectionAvailable;
	// }}}RME
	// {{{RME classAttribute 'm_threshold'
	unsigned int m_threshold;
	// }}}RME
	// {{{RME classAttribute 'm_mqmutex'
	Mutex * m_mqmutex;
	// }}}RME

public:
	// {{{RME associationEnd 'm_usbConfigManagerRef'
	USBConfigMgr * m_usbConfigManagerRef;
	// }}}RME

private:
	// {{{RME associationEnd 'm_IOVirtualResourceArray'
	IOVirtual * m_IOVirtualResourceArray[ 24 ];
	// }}}RME
	// {{{RME associationEnd 'm_receiveDataQueue'
	DataQueue * m_receiveDataQueue;
	// }}}RME

public:
	// {{{RME operation 'OS_Facade(USBConfigMgr*)'
	OS_Facade( USBConfigMgr * usbConfigMgrRef );
	// }}}RME
	// {{{RME operation 'getSemaphore(uint32_t)'
	Sem * getSemaphore( uint32_t val = 1 );
	// }}}RME
	// {{{RME operation 'semaphoreTimedWait(Sem*,unsigned int)'
	void semaphoreTimedWait( Sem * semHandle, unsigned int timeOut );
	// }}}RME
	// {{{RME operation 'semaphoreWait(Sem*)'
	void semaphoreWait( Sem * semHandle );
	// }}}RME
	// {{{RME operation 'semaphorePost(Sem *)'
	void semaphorePost( Sem * semHandle );
	// }}}RME
	// {{{RME operation 'deleteSemaphore(Sem *)'
	void deleteSemaphore( Sem * semHandle );
	// }}}RME
	// {{{RME operation 'setThreshold(unsigned int)'
	void setThreshold( unsigned int threshold );
	// }}}RME
	// {{{RME operation 'startThread(int (*)( void*),uint16_t,char *)'
	UsbThread * startThread( int ( * thread_entry )(  void * ), uint16_t stackSize, char * name );
	// }}}RME
	// {{{RME operation 'deleteThread(UsbThread *)'
	void deleteThread( UsbThread * Thread_ptr );
	// }}}RME
	// {{{RME operation 'msgQueueCreate(const char*)'
	unsigned int msgQueueCreate( const char * msgQ_name );
	// }}}RME
	// {{{RME operation 'msgQueueReceive(unsigned int)'
	void * msgQueueReceive( unsigned int msgQ );
	// }}}RME
	// {{{RME operation 'msgQueueSend(unsigned int,void *)'
	bool msgQueueSend( unsigned int msgQ, void * msg );
	// }}}RME
	// {{{RME operation 'msgQueueDelete(unsigned int)'
	void msgQueueDelete( unsigned int msgQueue );
	// }}}RME
	// {{{RME operation 'registerUSBDevInterrupt(unsigned int,void (*)())'
	void registerUSBDevInterrupt( unsigned int irq, void ( * interrupt_entry )( void ) );
	// }}}RME
	// {{{RME operation 'registerUSBHostInterrupt(unsigned int,void (*)())'
	void registerUSBHostInterrupt( unsigned int irq, void ( * interrupt_entry )( void ) );
	// }}}RME
	// {{{RME operation 'inform(uint32_t)'
	void inform( uint32_t event );
	// }}}RME
	// {{{RME operation 'enqueueReceiveData(uint8_t*,int32_t)'
	void enqueueReceiveData( uint8_t * buffer, int32_t length );
	// }}}RME
	// {{{RME operation 'IOVirtualSend(uint32_t,uint32_t)'
	void IOVirtualSend( uint32_t io, uint32_t value );
	// }}}RME
	// {{{RME operation 'IOVirtualReceive(uint32_t)'
	uint32_t IOVirtualReceive( uint32_t io );
	// }}}RME

private:
	// {{{RME operation 'lookupIOVirtualResource(uint32_t)'
	IOVirtual * lookupIOVirtualResource( uint32_t ioResource );
	// }}}RME

public:
	// {{{RME operation 'setDeviceReceiveDataQueue(DataQueue*)'
	void setDeviceReceiveDataQueue( DataQueue * receiveDataQueue );
	// }}}RME
	// {{{RME operation 'setDeviceConnection(IOVirtualSerial*)'
	void setDeviceConnection( IOVirtualSerial * serialIO );
	// }}}RME
	// {{{RME operation 'getDeviceState()'
	bool getDeviceState( void );
	// }}}RME
	// {{{RME operation 'setDeviceState(bool)'
	void setDeviceState( bool connectionStatus );
	// }}}RME
	// {{{RME operation '~OS_Facade()'
	~OS_Facade( void );
	// }}}RME
};

// {{{RME operation 'OS_MemMove(void *,void *,unsigned long)'
unsigned long OS_MemMove( void * dest, void * src, unsigned long len );
// }}}RME

// {{{RME operation 'OS_MemSet(void *,char,unsigned long)'
void * OS_MemSet( void * ptr, char val, unsigned long len );
// }}}RME

// {{{RME operation 'OS_Malloc(unsigned long)'
void * OS_Malloc( unsigned long len );
// }}}RME

// {{{RME operation 'OS_Free(void *)'
void OS_Free( void * ptr );
// }}}RME

// {{{RME operation 'OS_MemCmp(void *,void *,unsigned int)'
int OS_MemCmp( void * ptr1, void * ptr2, unsigned int len );
// }}}RME

// {{{RME operation 'OS_WaitNanoSeconds(unsigned int)'
void OS_WaitNanoSeconds( unsigned int timeOut );
// }}}RME

// {{{RME operation 'OS_Wait(unsigned int)'
void OS_Wait( unsigned int timeOut );
// }}}RME

// {{{RME operation 'OS_Strcpy(char *,const char *)'
char * OS_Strcpy( char * dest, const char * src );
// }}}RME

// {{{RME operation 'OS_Strlen(const char*)'
unsigned long OS_Strlen( const char * string );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* OS_Facade_H */

// }}}RME
