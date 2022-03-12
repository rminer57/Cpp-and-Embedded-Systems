// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::GPS_Interface::InstantGPS_MG4100::InstantGPS_mg4100'

#ifndef InstantGPS_mg4100_H
#define InstantGPS_mg4100_H

#ifdef PRAGMA
#pragma interface "InstantGPS_mg4100.h"
#endif

#include <HALtestLib_win32.h>
#include <Array.h>
#include <ListenerBase.h>
#include <RXThresholdEvent.h>
#include <SCharArray.h>
#include <Sem.h>
#include <Thread.h>
class Connection;
class GPSEventHandlerBase;
class IOVirtual;
class TimeSpec;
class TimerVirtual;
class UartConfig;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>

#define RXBUFFER_SIZE 80

// }}}USR
// }}}RME

class InstantGPS_mg4100 : public ListenerBase, public Thread
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
	// {{{RME classAttribute 'm_resetPin'
	IOVirtual * m_resetPin;
	// }}}RME
	// {{{RME classAttribute 'm_userEventHandler'
	GPSEventHandlerBase * m_userEventHandler;
	// }}}RME
	// {{{RME classAttribute 'm_ramError'
	unsigned int m_ramError;
	// }}}RME

public:
	// {{{RME classAttribute 'STATUS_ERROR_DEVICE_NOT_DETECTED'
	static const unsigned int STATUS_ERROR_DEVICE_NOT_DETECTED;
	// }}}RME

protected:
	// {{{RME classAttribute 'm_RxData'
	char m_RxData[ RXBUFFER_SIZE ];
	// }}}RME

public:
	// {{{RME classAttribute 'STATUS_ERROR_FIRMWARE_CORRUPT'
	static const unsigned int STATUS_ERROR_FIRMWARE_CORRUPT;
	// }}}RME
	// {{{RME classAttribute 'STATUS_FIRMWARE_SUCCESS'
	static const unsigned int STATUS_FIRMWARE_SUCCESS;
	// }}}RME
	// {{{RME classAttribute 'STATUS_BOOTLOAD_IN_PROGRESS'
	static const unsigned int STATUS_BOOTLOAD_IN_PROGRESS;
	// }}}RME
	// {{{RME classAttribute 'STATUS_BOOTLOAD_DONE'
	static const unsigned int STATUS_BOOTLOAD_DONE;
	// }}}RME

protected:
	// {{{RME classAttribute 'm_timerDone'
	volatile unsigned int m_timerDone;
	// }}}RME
	// {{{RME classAttribute 'm_TxData'
	SCharArray * m_TxData;
	// }}}RME
	// {{{RME classAttribute 'm_str_OK'
	static const char m_str_OK[ 3 ];
	// }}}RME
	// {{{RME classAttribute 'm_str_ATMODE7'
	static const char m_str_ATMODE7[ 10 ];
	// }}}RME
	// {{{RME classAttribute 'm_uartConnection'
	Connection * m_uartConnection;
	// }}}RME

public:
	// {{{RME classAttribute 'STATUS_ERROR_GPS_COMMUNICATION_FAILURE'
	static const unsigned int STATUS_ERROR_GPS_COMMUNICATION_FAILURE;
	// }}}RME

protected:
	// {{{RME classAttribute 'm_str_bootstrap_ram_firmware_state'
	static const char m_str_bootstrap_ram_firmware_state[ 7 ];
	// }}}RME
	// {{{RME classAttribute 'm_keyword_valid'
	static const char m_keyword_valid[ 4 ];
	// }}}RME
	// {{{RME classAttribute 'm_keyword_invalid'
	static const char m_keyword_invalid[ 4 ];
	// }}}RME
	// {{{RME classAttribute 'm_bootstrap_configure_baud_rate'
	static const char m_bootstrap_configure_baud_rate[ 9 ];
	// }}}RME

public:
	// {{{RME classAttribute 'STATUS_ERROR_DEVICE_BAUD_RATE_NOT_SET'
	static const unsigned int STATUS_ERROR_DEVICE_BAUD_RATE_NOT_SET;
	// }}}RME

protected:
	// {{{RME classAttribute 'm_bootstrap_jump_to_address'
	static const char m_bootstrap_jump_to_address[ 11 ];
	// }}}RME

public:
	// {{{RME classAttribute 'STATUS_TRYING_BOOTLOAD_AGAIN'
	static const unsigned int STATUS_TRYING_BOOTLOAD_AGAIN;
	// }}}RME
	// {{{RME classAttribute 'STATUS_CHKSM_ERROR'
	static const unsigned int STATUS_CHKSM_ERROR;
	// }}}RME

protected:
	// {{{RME classAttribute 'm_gpsFirmwareLocation'
	char * m_gpsFirmwareLocation;
	// }}}RME
	// {{{RME classAttribute 'm_gpsFirmwarePagesNum'
	int m_gpsFirmwarePagesNum;
	// }}}RME
	// {{{RME classAttribute 'm_clockStringAddress'
	char * m_clockStringAddress;
	// }}}RME
	// {{{RME classAttribute 'm_bootstrap_download_firmware_page'
	static const char m_bootstrap_download_firmware_page[ 138 ];
	// }}}RME

public:
	// {{{RME classAttribute 'STATUS_TXBUF_SEND_ERROR'
	static const unsigned int STATUS_TXBUF_SEND_ERROR;
	// }}}RME
	// {{{RME classAttribute 'm_userErrorStatus'
	unsigned int m_userErrorStatus;
	// }}}RME
	// {{{RME classAttribute 'STATUS_BOOTLOAD_FAILED'
	static const unsigned int STATUS_BOOTLOAD_FAILED;
	// }}}RME
	// {{{RME classAttribute 'STATUS_LISTENING_FOR_PGAM'
	static const unsigned int STATUS_LISTENING_FOR_PGAM;
	// }}}RME
	// {{{RME classAttribute 'STATUS_KEYWORDVALID_CKSUM_FAILURE'
	static const unsigned int STATUS_KEYWORDVALID_CKSUM_FAILURE;
	// }}}RME
	// {{{RME classAttribute 'STATUS_BOOTSTRAP_JUMP_TO_ADDRESS_FAILED'
	static const unsigned int STATUS_BOOTSTRAP_JUMP_TO_ADDRESS_FAILED;
	// }}}RME

protected:
	// {{{RME classAttribute 'm_firmwareVersion'
	uint32_t m_firmwareVersion;
	// }}}RME
	// {{{RME classAttribute 'm_uartcfg'
	UartConfig * m_uartcfg;
	// }}}RME
	// {{{RME classAttribute 'm_versionError'
	unsigned int m_versionError;
	// }}}RME

public:
	// {{{RME classAttribute 'STATUS_ERROR_FIRMWARE_VERSION_ERROR'
	static const unsigned int STATUS_ERROR_FIRMWARE_VERSION_ERROR;
	// }}}RME

protected:
	// {{{RME classAttribute 'firmwareVerInPGAM'
	static uint32_t firmwareVerInPGAM;
	// }}}RME

public:
	// {{{RME associationEnd 'm_timerVirtual'
	TimerVirtual * m_timerVirtual;
	// }}}RME

protected:
	// {{{RME operation 'startBootLoad(char *,int)'
	unsigned int startBootLoad( char * bootCodeAddress, int bootCodeLenInBytes );
	// }}}RME
	// {{{RME operation 'eventOccurred(const EventBase * const)'
	void eventOccurred( const EventBase * const event );
	// }}}RME
	// {{{RME operation 'GPSopen()'
	unsigned int GPSopen( void );
	// }}}RME
	// {{{RME operation 'sendToPGAM(char *,int)'
	unsigned int sendToPGAM( char * data, int len );
	// }}}RME
	// {{{RME operation 'startOperation(char *)'
	virtual unsigned int startOperation( char * clockStringAddress );
	// }}}RME
	// {{{RME operation 'Delay(unsigned int)'
	void Delay( unsigned int delayTime );
	// }}}RME
	// {{{RME operation 'compareString(const char *,const char *,unsigned int)'
	unsigned int compareString( const char * string1, const char * string2, unsigned int len );
	// }}}RME
	// {{{RME operation 'main()'
	virtual void * main( void );
	// }}}RME
	// {{{RME operation 'isKeywordValid()'
	unsigned int isKeywordValid( void );
	// }}}RME
	// {{{RME operation 'uploadFirmware(char *,int)'
	void uploadFirmware( char * bootCodeAddress, int gpsFirmwarePagesNum );
	// }}}RME
	// {{{RME operation 'checksm(char *,unsigned int,bool)'
	unsigned int checksm( char * strBuffer, unsigned int len, bool add );
	// }}}RME
	// {{{RME operation 'setBaudRateDevice(unsigned int)'
	unsigned int setBaudRateDevice( unsigned int device_baud_rate );
	// }}}RME
	// {{{RME operation 'startFirmware()'
	void startFirmware( void );
	// }}}RME
	// {{{RME operation 'copystr(char*,const char*,unsigned int)'
	unsigned int copystr( char * string1, const char * string2, unsigned int len );
	// }}}RME

public:
	// {{{RME operation '~InstantGPS_mg4100()'
	~InstantGPS_mg4100( void );
	// }}}RME

protected:
	// {{{RME operation 'timerStart(unsigned int)'
	void timerStart( unsigned int value );
	// }}}RME
	// {{{RME operation 'resetPGAM()'
	void resetPGAM( void );
	// }}}RME
	// {{{RME operation 'isTimerExpired()'
	bool isTimerExpired( void );
	// }}}RME
	// {{{RME operation 'timerStop()'
	void timerStop( void );
	// }}}RME
	// {{{RME operation 'isRxDataAvailable()'
	bool isRxDataAvailable( void );
	// }}}RME
	// {{{RME operation 'notifyUserOfStatus(unsigned int)'
	void notifyUserOfStatus( unsigned int eventcode );
	// }}}RME

public:
	// {{{RME operation 'receiveFromPGAM(unsigned int)'
	unsigned int receiveFromPGAM( unsigned int numCharsToGet );
	// }}}RME

protected:
	// {{{RME operation 'flush()'
	void flush( void );
	// }}}RME

public:
	// {{{RME operation 'launchBootloadThread()'
	void launchBootloadThread( void );
	// }}}RME

protected:
	// {{{RME operation 'readToInt(char[],unsigned int)'
	unsigned int readToInt( char str[], unsigned int count );
	// }}}RME

public:
	// {{{RME operation 'InstantGPS_mg4100(Connection *,IOVirtual *,TimerVirtual *,char *,int,char *,GPSEventHandlerBase *,uint32_t,bool)'
	InstantGPS_mg4100( Connection * uartConnection, IOVirtual * resetPin, TimerVirtual * timer, char * gpsFirmwareLocation, int gpsFirmwarePagesNum, char * clockStringAddress, GPSEventHandlerBase * event_handler, uint32_t firmwareVersion, bool launchThread = true );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* InstantGPS_mg4100_H */

// }}}RME
