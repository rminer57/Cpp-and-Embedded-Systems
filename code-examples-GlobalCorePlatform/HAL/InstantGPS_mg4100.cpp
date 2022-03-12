// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::GPS_Interface::InstantGPS_MG4100::InstantGPS_mg4100'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "InstantGPS_mg4100.h"
#endif

#include <HALtestLib_win32.h>
#include <InstantGPS_mg4100.h>
#include <Connection.h>
#include <GPSEventHandlerBase.h>
#include <IOVirtual.h>
#include <TimeSpec.h>
#include <TimerVirtual.h>
#include <UartConfig.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'STATUS_ERROR_DEVICE_NOT_DETECTED'
const unsigned int InstantGPS_mg4100::STATUS_ERROR_DEVICE_NOT_DETECTED( 1 );
// }}}RME

// {{{RME classAttribute 'STATUS_ERROR_FIRMWARE_CORRUPT'
const unsigned int InstantGPS_mg4100::STATUS_ERROR_FIRMWARE_CORRUPT( 2 );
// }}}RME

// {{{RME classAttribute 'STATUS_FIRMWARE_SUCCESS'
const unsigned int InstantGPS_mg4100::STATUS_FIRMWARE_SUCCESS( 0 );
// }}}RME

// {{{RME classAttribute 'STATUS_BOOTLOAD_IN_PROGRESS'
const unsigned int InstantGPS_mg4100::STATUS_BOOTLOAD_IN_PROGRESS( 3 );
// }}}RME

// {{{RME classAttribute 'STATUS_BOOTLOAD_DONE'
const unsigned int InstantGPS_mg4100::STATUS_BOOTLOAD_DONE( 4 );
// }}}RME

// {{{RME classAttribute 'm_str_OK'
const char InstantGPS_mg4100::m_str_OK[ 3 ] = {0x4F,0x4B,0x0D};
// }}}RME

// {{{RME classAttribute 'm_str_ATMODE7'
const char InstantGPS_mg4100::m_str_ATMODE7[ 10 ] = {0x41,0x54,0x2B,0x4D,0x4F,0x44,0x45,0x3D,0x37,0x0D};
// }}}RME

// {{{RME classAttribute 'STATUS_ERROR_GPS_COMMUNICATION_FAILURE'
const unsigned int InstantGPS_mg4100::STATUS_ERROR_GPS_COMMUNICATION_FAILURE( 5 );
// }}}RME

// {{{RME classAttribute 'm_str_bootstrap_ram_firmware_state'
const char InstantGPS_mg4100::m_str_bootstrap_ram_firmware_state[ 7 ] = {0x40,0x40,0x53,0x6A,0x30,0x0D,0x0A};
// }}}RME

// {{{RME classAttribute 'm_keyword_valid'
const char InstantGPS_mg4100::m_keyword_valid[ 4 ] = {0x40,0x40,0x53,0x6A};
// }}}RME

// {{{RME classAttribute 'm_keyword_invalid'
const char InstantGPS_mg4100::m_keyword_invalid[ 4 ] = {0x40,0x40,0x53,0x7A};
// }}}RME

// {{{RME classAttribute 'm_bootstrap_configure_baud_rate'
const char InstantGPS_mg4100::m_bootstrap_configure_baud_rate[ 9 ] = {0x40,0x40,0x53,0x6C,0x30,0x30,0xFF,0x0D,0x0A};
// }}}RME

// {{{RME classAttribute 'STATUS_ERROR_DEVICE_BAUD_RATE_NOT_SET'
const unsigned int InstantGPS_mg4100::STATUS_ERROR_DEVICE_BAUD_RATE_NOT_SET( 6 );
// }}}RME

// {{{RME classAttribute 'm_bootstrap_jump_to_address'
const char InstantGPS_mg4100::m_bootstrap_jump_to_address[ 11 ] = {0x40,0x40,0x53,0x67,0x30,0x30,0x30,0x30,0x30,0x0D,0x0A};
// }}}RME

// {{{RME classAttribute 'STATUS_TRYING_BOOTLOAD_AGAIN'
const unsigned int InstantGPS_mg4100::STATUS_TRYING_BOOTLOAD_AGAIN = 7;
// }}}RME

// {{{RME classAttribute 'STATUS_CHKSM_ERROR'
const unsigned int InstantGPS_mg4100::STATUS_CHKSM_ERROR = 8;
// }}}RME

// {{{RME classAttribute 'm_bootstrap_download_firmware_page'
const char InstantGPS_mg4100::m_bootstrap_download_firmware_page[ 138 ] = {0x40,0x40,0x53,0x6B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0D,0x0A};
// }}}RME

// {{{RME classAttribute 'STATUS_TXBUF_SEND_ERROR'
const unsigned int InstantGPS_mg4100::STATUS_TXBUF_SEND_ERROR = 9;
// }}}RME

// {{{RME classAttribute 'STATUS_BOOTLOAD_FAILED'
const unsigned int InstantGPS_mg4100::STATUS_BOOTLOAD_FAILED( 25 );
// }}}RME

// {{{RME classAttribute 'STATUS_LISTENING_FOR_PGAM'
const unsigned int InstantGPS_mg4100::STATUS_LISTENING_FOR_PGAM( 26 );
// }}}RME

// {{{RME classAttribute 'STATUS_KEYWORDVALID_CKSUM_FAILURE'
const unsigned int InstantGPS_mg4100::STATUS_KEYWORDVALID_CKSUM_FAILURE( 27 );
// }}}RME

// {{{RME classAttribute 'STATUS_BOOTSTRAP_JUMP_TO_ADDRESS_FAILED'
const unsigned int InstantGPS_mg4100::STATUS_BOOTSTRAP_JUMP_TO_ADDRESS_FAILED( 29 );
// }}}RME

// {{{RME classAttribute 'STATUS_ERROR_FIRMWARE_VERSION_ERROR'
const unsigned int InstantGPS_mg4100::STATUS_ERROR_FIRMWARE_VERSION_ERROR( 10 );
// }}}RME

// {{{RME classAttribute 'firmwareVerInPGAM'
uint32_t InstantGPS_mg4100::firmwareVerInPGAM( 0 );
// }}}RME

// {{{RME operation 'startBootLoad(char *,int)'
unsigned int InstantGPS_mg4100::startBootLoad( char * bootCodeAddress, int bootCodeLenInBytes )
{
	// {{{USR
	    unsigned int retval = STATUS_BOOTLOAD_IN_PROGRESS;
	    unsigned int status = 0;

	    if ( (!m_ramError)&&(!m_versionError) )    //First pass at uploading firmware.
		{
		    status = isKeywordValid();  //Check if keyword is valid.
		}

	    if( (status==0) || (m_ramError) || (m_versionError) )
		{
		    //Keyword is invalid or second pass at firmware upload
		    uploadFirmware(bootCodeAddress, bootCodeLenInBytes);
		}
	    else
		{
		    retval = status;
		}
	    return retval;


	// }}}USR
}
// }}}RME

// {{{RME operation 'eventOccurred(const EventBase * const)'
void InstantGPS_mg4100::eventOccurred( const EventBase * const event )
{
	// {{{USR
		 Connection::Status * connectionStatus;


		 if (event->isType(TimerVirtual::Event::TIMER_EVENT))
		 {
			  m_timerDone = 1;
		 }
		 else
		 {
			  m_userErrorStatus = -99; // unknown event
		 }

	// }}}USR
}
// }}}RME

// {{{RME operation 'GPSopen()'
unsigned int InstantGPS_mg4100::GPSopen( void )
{
	// {{{USR
	unsigned int retval = 0;
	unsigned int numOfCharsReceived = 0;

	// set host baud to 19200 (use m_uartConnection to do this)
	m_uartConnection->setOption(m_uartcfg);

	resetPGAM();

	// wait for AT command within 110ms.
	timerStart(200);

	while(1)
	{
	    // wait for AT command string. If it fails to appear, the timer will expire
	    numOfCharsReceived = receiveFromPGAM( sizeof(m_str_ATMODE7) );


	    if( (isTimerExpired() == true) || (numOfCharsReceived == 0) )
		{
		    //PGAM hardware failed to respond with AT command.
		    retval = STATUS_ERROR_DEVICE_NOT_DETECTED;  //GPS device not detected.
		    timerStop(); 
		    break;
		}
	    else
		{
		    timerStop();

		    // AT command received; send 'OK<CR>' to PGAM
		    sendToPGAM((char *)m_str_OK, sizeof(m_str_OK));

		    //Flush receive buffer to clean accumulated'AT+MODE=7' commands.
		    flush();

		    break;
		}
	}
	return retval;

	// }}}USR
}
// }}}RME

// {{{RME operation 'sendToPGAM(char *,int)'
unsigned int InstantGPS_mg4100::sendToPGAM( char * data, int len )
{
	// {{{USR
		bool consumeBuffer = false;
		unsigned int retval = 0;
		bool txstatus;
		TimeSpec myTime(0,100L*1000000L);

		SCharArray * txBuffer = new SCharArray(len, (char *)data, consumeBuffer);

		// A return of "true" does not imply that the data has actually been 
		// sent by the connection, but rather indicates that the connection is 
		// capable of sending the data.  A return of "false" indicates that NONE 
		// of the data in the Array could be sent, in which case the provided 
		// buffer object is guaranteed to be UNMODIFIED.

		txstatus = m_uartConnection->send( txBuffer);


		if( txstatus == false )
		{
		    //Transmit unsuccessful.
		    retval = STATUS_TXBUF_SEND_ERROR;
		}

		Thread::nanosleep(myTime);

		return retval; 

	// }}}USR
}
// }}}RME

// {{{RME operation 'startOperation(char *)'
unsigned int InstantGPS_mg4100::startOperation( char * clockStringAddress )
{
	// {{{USR
	unsigned int retval = STATUS_FIRMWARE_SUCCESS;
	unsigned int Rxstatus = 0;
	unsigned int Ckstatus = 0;

	char pb_status_byte = 48;
	unsigned char pb_status_ram_fail = 1<<1;

	//Position Fix Response Message @@PbattttnnnndeeeeFGoKchhhbbbwwmmmmuuppxyzzvvvvsseerrrriiiiC<CR><LF>
	unsigned int  len_PosFixRspMsg = 62; //Length of 'Position Fix Response Message'.
	char * cmd = (char *)"@@Pb";
	char versionPosInPbMsg = 56;             //Location in @@Pb message (iiii) where firmware version is stored.

#define MAXMSGLENGTH 80              //Maximum message length.
	char *pmsgStr = clockStringAddress;
	unsigned int msgLength = 0;          //Length of message string to follow.
	unsigned int msgLengthSize = 2;      //No. of characters that make up the message length.
	unsigned int lenVersionStr = 3;      //No. of characters that comprise the version string in the @@Pb message.
	char rawOutputBuffer[MAXMSGLENGTH];  //Maximum message length of any one message \
	                                     //in the concatenated message string.

	// wait for Receive string from PGAM uart for 50ms.
	timerStart(200);

	while (1)
	{
		 Rxstatus = receiveFromPGAM(len_PosFixRspMsg);
		 Ckstatus = checksm(m_RxData, len_PosFixRspMsg, 0);
		 if( isTimerExpired() == true)
		 {
			  retval = STATUS_ERROR_GPS_COMMUNICATION_FAILURE;
			  break;
		 }

		 if ( (Rxstatus != 0) && (Ckstatus != STATUS_CHKSM_ERROR) )
		 {
			  // check rx string
			  if (0 == compareString(m_RxData, cmd, 4) )  // if response message is @@Pb
			  {
				   if ((m_RxData[pb_status_byte] & pb_status_ram_fail))  // Ram program check
				   {
						// Ram program check failed.
						if (m_ramError)
						{
							 retval = STATUS_ERROR_FIRMWARE_CORRUPT;
						}
						else 
						{
							 m_ramError = 1;

							 retval = STATUS_TRYING_BOOTLOAD_AGAIN;
						}
				   }
				   else
				   {
						//Ram program check passed, now check for version number.

						//Version # = 3 bytes in @@Pb message right-shifted by 1(drop the LSB).
						firmwareVerInPGAM = 0;
						firmwareVerInPGAM |= m_RxData[versionPosInPbMsg] << 16;
						firmwareVerInPGAM |= m_RxData[versionPosInPbMsg + 1] << 8;
						firmwareVerInPGAM |= m_RxData[versionPosInPbMsg + 2];
						firmwareVerInPGAM = firmwareVerInPGAM >> 1;          //Drop the LSB

						if ( firmwareVerInPGAM == m_firmwareVersion )
						{
							 while( msgLength = readToInt(pmsgStr, msgLengthSize) )   //Read 2-byte message length.
							 {
								  copystr(rawOutputBuffer, pmsgStr + msgLengthSize, msgLength);
								  checksm(rawOutputBuffer, msgLength, 1 );
								  sendToPGAM(rawOutputBuffer, (int)msgLength);
								  flush();  //Receive the response message and discard.
								  pmsgStr = (pmsgStr + msgLengthSize) + msgLength;  //Point to message length of next message.
							 }
							 retval = STATUS_FIRMWARE_SUCCESS;
							 break;
						}
						else 
						{
							 if(m_versionError)
							 {
								  retval = STATUS_ERROR_FIRMWARE_VERSION_ERROR;
							 }
							 else
							 {
								  m_versionError = 1;
								  retval = STATUS_TRYING_BOOTLOAD_AGAIN;
							 }
						}
				   }
			  }
			  else
			  {
				   //Received message is not @@Pb; this means 'Bootstrap Jump to Address (@@Sg)' failed.
				   retval = STATUS_BOOTSTRAP_JUMP_TO_ADDRESS_FAILED;
			  }
		 }
		 else
		 {
			  retval = STATUS_CHKSM_ERROR;
			  notifyUserOfStatus(STATUS_CHKSM_ERROR);
			  break;
		 }
	flush();
	}
	timerStop();

	return retval;


	// }}}USR
}
// }}}RME

// {{{RME operation 'Delay(unsigned int)'
void InstantGPS_mg4100::Delay( unsigned int delayTime )
{
	// {{{USR

	timerStart(delayTime);

	// wait for delay period
	while( isTimerExpired() == false)
	{
	    Thread::sleep(1);  // delay for one unit of time
	}
	timerStop(); // stop timer

	// }}}USR
}
// }}}RME

// {{{RME operation 'compareString(const char *,const char *,unsigned int)'
unsigned int InstantGPS_mg4100::compareString( const char * string1, const char * string2, unsigned int len )
{
	// {{{USR

	while (len--)
	{
	    if ( !(*string1 == *string2))
		return 1; // error, string1 and string2 DO NOT match.
	    string1++;
	    string2++;
	}
	return 0;  // string1 and string2 match.

	// }}}USR
}
// }}}RME

// {{{RME operation 'main()'
void * InstantGPS_mg4100::main( void )
{
	// {{{USR
	unsigned int status = 0;
	unsigned int retries = 0;
	bool exit = false;
	Connection::Status * uartConnectionStatus;

	timerStop();

	m_timerVirtual->registerListener(this,TimerVirtual::Event::TIMER_EVENT);

	m_uartcfg = new UartConfig(19200); 

	while( 1 )
	{

		 status = GPSopen();

		 if( status == STATUS_ERROR_DEVICE_NOT_DETECTED )
		 {
	          // indicates that GPSopen listened for the AT+MODE7 string that PGAM
	          // always sends following reset, but failed to receive the string.

			  // call the user's callback function, if registered.
			  notifyUserOfStatus(STATUS_ERROR_DEVICE_NOT_DETECTED);
			  exit = true;
		 }
		 else
		 {

			  startBootLoad(m_gpsFirmwareLocation,m_gpsFirmwarePagesNum);

			  startFirmware();

			  status = startOperation(m_clockStringAddress);


			  switch (status)
			  {
			  case STATUS_FIRMWARE_SUCCESS:

				   notifyUserOfStatus(STATUS_FIRMWARE_SUCCESS);
				   exit = true;

				   break;

			  case STATUS_ERROR_FIRMWARE_CORRUPT:
				   // call the user's callback function, if registered.
				   notifyUserOfStatus(STATUS_ERROR_FIRMWARE_CORRUPT);
				   exit = true;
				   break;

				   // first attempt failed, try again
			  case STATUS_TRYING_BOOTLOAD_AGAIN:
				   retries++;
				   notifyUserOfStatus(STATUS_TRYING_BOOTLOAD_AGAIN);
				   break;

			  case STATUS_BOOTSTRAP_JUMP_TO_ADDRESS_FAILED:
				   retries++;
				   notifyUserOfStatus(STATUS_TRYING_BOOTLOAD_AGAIN);
				   break;

			  case STATUS_ERROR_GPS_COMMUNICATION_FAILURE:
				   notifyUserOfStatus(STATUS_ERROR_GPS_COMMUNICATION_FAILURE);
				   exit = true;
				   break;

			  case STATUS_ERROR_FIRMWARE_VERSION_ERROR:
				   notifyUserOfStatus(STATUS_ERROR_FIRMWARE_VERSION_ERROR);
				   exit = true;
				   break;
		          
			  default:
				   break;
			  };    
		 } // end  if( status == STATUS_ERROR_DEVICE_NOT_DETECTED )else...

		 // retry logic - two retries are allowed.
		 if( retries == 2 )
		 {
			  notifyUserOfStatus(STATUS_BOOTLOAD_FAILED);
			  exit = true;        
		 }

		 if(exit == true) 
			  break;
		  
	}

	delete m_uartcfg;

	timerStop();

	m_timerVirtual->unregisterListener(this,TimerVirtual::Event::TIMER_EVENT);

	return 0;

	// }}}USR
}
// }}}RME

// {{{RME operation 'isKeywordValid()'
unsigned int InstantGPS_mg4100::isKeywordValid( void )
{
	// {{{USR

	unsigned int retval = 0;
	unsigned int lenFirmwareStRspMsg = 8;  //Length of 'Bootstrap RAM Firmware State' response message.
	unsigned int Ckstatus = 0;

	char rawOutputBuffer[sizeof(m_str_bootstrap_ram_firmware_state)];
	copystr(rawOutputBuffer, m_str_bootstrap_ram_firmware_state, sizeof(m_str_bootstrap_ram_firmware_state));

	// Calculates checksum and plugs it into the str array.
	checksm(rawOutputBuffer, sizeof(rawOutputBuffer), 1 );

	// send '@@SjC<CR><LF>' to PGAM
	sendToPGAM(rawOutputBuffer, sizeof(rawOutputBuffer));

	// start timer
	timerStart(200);

	// wait for Receive string from PAGM uart for 50ms.
	while (1)
	{
	    // no need to check return value of receive here - it will either be correct
	    // or a timeout will have occurred.
	    receiveFromPGAM(lenFirmwareStRspMsg);
	    Ckstatus = checksm(m_RxData, lenFirmwareStRspMsg, 0);
	    timerStop();  // reset timer since we either received something or timed out.

	    if( isTimerExpired() == true )
		{ 
		    retval = STATUS_ERROR_GPS_COMMUNICATION_FAILURE;
		    break;
		}
	    else
		{
		    // is checksum valid
		    if( Ckstatus == STATUS_CHKSM_ERROR )
			{
			    retval = STATUS_CHKSM_ERROR;  // Receive from PGAM failed
			    break;
			}

		    // is data valid    
		    // check rx string for keyword valid.
		    if (0 == compareString(m_RxData, m_keyword_valid, 4) )
			{
			    retval = 1;
			    break;
			}
		    // check rx string for keyword invalid.
		    else if (0 == compareString(m_RxData, m_keyword_invalid, 4))
			{			   
			    retval = 0;
			    break;
			}
		}
	}
	timerStop();  // reset timer.
	return retval;

	// }}}USR
}
// }}}RME

// {{{RME operation 'uploadFirmware(char *,int)'
void InstantGPS_mg4100::uploadFirmware( char * bootCodeAddress, int gpsFirmwarePagesNum )
{
	// {{{USR

	unsigned int Rxstatus = 0;
	unsigned int Ckstatus = 0;

	//'Bootstrap Download Firmware Page' message @@Skaaadddddddddd..ddddddddddC<CR><LF>
#define LEN_CMD_MSG 138  // Message len for @@Skaaa.... command

	unsigned int len_DwnldFirmwarePgRspMsg = 10;  //Length of 'Bootstrap Download Firmware Page' response message.
	char         * currAddr = m_gpsFirmwareLocation;
	unsigned int indexOffset = 4;  // Starting location of data in the cmd string @@Sk...
	unsigned int gpsFirmwarePageLen = 131;  // No. of characters of Firmware data per page
	char         rawOutputBuffer[LEN_CMD_MSG];
	char         responseMsg[] = {'@','@','S','k'};

	copystr(rawOutputBuffer, m_bootstrap_download_firmware_page, sizeof(m_bootstrap_download_firmware_page));

	for(int n = 0; n < gpsFirmwarePagesNum; n++)
	{
	    copystr(rawOutputBuffer+indexOffset, (const char *)currAddr, gpsFirmwarePageLen);
	    checksm(rawOutputBuffer, sizeof(rawOutputBuffer), 1 );
	    sendToPGAM(rawOutputBuffer, sizeof(rawOutputBuffer));
	    timerStart(200); // start timer (receive string is 138 chars long).

	    while (1)
		{
		    Rxstatus = receiveFromPGAM( len_DwnldFirmwarePgRspMsg );
		    Ckstatus = checksm(m_RxData, len_DwnldFirmwarePgRspMsg, 0);

		    if( isTimerExpired() == true)
			{
			    notifyUserOfStatus(STATUS_ERROR_GPS_COMMUNICATION_FAILURE);
			    break;
			}
		    if ( (Rxstatus != 0) && (Ckstatus != STATUS_CHKSM_ERROR) )
			{
			    if (0 == compareString(m_RxData, responseMsg, 4) )
				{
				    if (0 == compareString(m_RxData + 4, (const char *)currAddr, 3) )
					{
					    break;
					}
				}
			}
		}
	    timerStop();  // reset timer.
	    currAddr += gpsFirmwarePageLen;  // Increment pointer to the beginning address of the next page of data
	}


	// }}}USR
}
// }}}RME

// {{{RME operation 'checksm(char *,unsigned int,bool)'
unsigned int InstantGPS_mg4100::checksm( char * strBuffer, unsigned int len, bool add )
{
	// {{{USR
	unsigned int n = 2;		// Checksum Starts at third character, i.e. \
	    // after @@ in the cmd string
	    char chksm = 0;
	char *strBufferEnd; // pointer to end of rx buffer
	char *pCheck;       // pointer to location of checksum in rx buffer

	strBufferEnd = strBuffer + len - 1;
	pCheck = strBufferEnd - 2;

	while(&strBuffer[n] < &pCheck[0])
	{
	    chksm ^= strBuffer[n];        //Ckecksum generated by XORing
	    n++;
	}

	// Add checksum to the buffer string
	if (add)
	{
	    pCheck[0] = chksm;    // Checksum plugged into the string buffer
	    return 0;
	}

	// verify checksum
	if( chksm != pCheck[ 0 ] )
	{
	    return STATUS_CHKSM_ERROR;
	}

	return 0;

	// }}}USR
}
// }}}RME

// {{{RME operation 'setBaudRateDevice(unsigned int)'
unsigned int InstantGPS_mg4100::setBaudRateDevice( unsigned int device_baud_rate )
{
	// {{{USR
	unsigned int retval = 0;
	unsigned int Rxstatus = 0;
	unsigned int Ckstatus = 0;

	char rawOutputBuffer[sizeof(m_bootstrap_configure_baud_rate)];
	char tmpSentBuffer[sizeof(m_bootstrap_configure_baud_rate)];

	//Populate buffer with data to send.
	copystr(rawOutputBuffer, m_bootstrap_configure_baud_rate, sizeof(m_bootstrap_configure_baud_rate));

	//Select baudrate control word.
	switch(device_baud_rate)
	{
	 case 19200:
	     // control word is 0x15
	     rawOutputBuffer[4] = '1';
	     rawOutputBuffer[5] = '5';
	     break;
	 case 57600:
	     // control word is 0x07
	     rawOutputBuffer[4] = '0';
	     rawOutputBuffer[5] = '7';
	     break;
	 case 115200:
	     // control word is 0x04
	     rawOutputBuffer[4] = '0';
	     rawOutputBuffer[5] = '4';
	     break;
	 case 406250:
	     // control word is 0x01
	     rawOutputBuffer[4] = '0';
	     rawOutputBuffer[5] = '1';
	     break;
	 default:
	     break;
	}

	checksm(rawOutputBuffer, sizeof(rawOutputBuffer), 1 );
	// Make copy of above string array for later comparision with response message from PGAM
	copystr(tmpSentBuffer, rawOutputBuffer, sizeof(m_bootstrap_configure_baud_rate));

	sendToPGAM(rawOutputBuffer, sizeof(rawOutputBuffer));

	// start timer
	timerStart(200);

	// wait for Receive string from PAGM uart for 50ms.
	while (1)
	{
	    Rxstatus = receiveFromPGAM( sizeof(m_bootstrap_configure_baud_rate) );
	    Ckstatus = checksm(m_RxData, sizeof(m_bootstrap_configure_baud_rate), 0);

	    if( isTimerExpired() == true)
		{
	            retval = STATUS_ERROR_DEVICE_BAUD_RATE_NOT_SET;
	            notifyUserOfStatus(STATUS_ERROR_DEVICE_BAUD_RATE_NOT_SET);
	            break;

		}
	    if ( (Rxstatus != 0) && (Ckstatus != STATUS_CHKSM_ERROR) )
		{
		    // check rx string for baud rate being ok.
		    if (0 == compareString(m_RxData, tmpSentBuffer, 8) )
			{
	            // success, break out.
			    break;
			}
		}
	}
	     
	timerStop();
	return retval;

	// }}}USR
}
// }}}RME

// {{{RME operation 'startFirmware()'
void InstantGPS_mg4100::startFirmware( void )
{
	// {{{USR

	char rawOutputBuffer[sizeof(m_bootstrap_jump_to_address)];

	// Plug Start Address into location 'aaaa' of m_bootstrap_jump_to_address[]  ( (@@SgaaaaC<CR><LF>))
	copystr(rawOutputBuffer, m_bootstrap_jump_to_address, sizeof(m_bootstrap_jump_to_address));

	rawOutputBuffer[4] = 0x00;
	rawOutputBuffer[5] = 0x0C;
	rawOutputBuffer[6] = 0x00;
	rawOutputBuffer[7] = 0x00;

	// Calculates checksum and plugs it into the str array.
	checksm(rawOutputBuffer, sizeof(rawOutputBuffer), 1 );

	// send '@@SgaaaaC<CR><LF>' to PGAM
	sendToPGAM(rawOutputBuffer, sizeof(rawOutputBuffer));


	// }}}USR
}
// }}}RME

// {{{RME operation 'copystr(char*,const char*,unsigned int)'
unsigned int InstantGPS_mg4100::copystr( char * string1, const char * string2, unsigned int len )
{
	// {{{USR
	// Copies 'len' number of characters from string2 to string1.

	do
	{
	    *string1 = *string2;
	    string1++;
	    string2++;
	}while(len--);
	return 0;  // string2 copied to string1.

	// }}}USR
}
// }}}RME

// {{{RME operation '~InstantGPS_mg4100()'
InstantGPS_mg4100::~InstantGPS_mg4100( void )
{
	// {{{USR


	// }}}USR
}
// }}}RME

// {{{RME operation 'timerStart(unsigned int)'
void InstantGPS_mg4100::timerStart( unsigned int value )
{
	// {{{USR
	//start timer with given value

	m_timerDone = 0;
	m_timerVirtual->set(0); // reset timer
	m_timerVirtual->set(value); 

	// }}}USR
}
// }}}RME

// {{{RME operation 'resetPGAM()'
void InstantGPS_mg4100::resetPGAM( void )
{
	// {{{USR

	// toggle reset
	m_resetPin->send(true); // 1 means assert the reset

	// wait at least 126u Seconds as per PGAM IC spec.
	Delay(1);

	m_resetPin->send(false);

	// }}}USR
}
// }}}RME

// {{{RME operation 'isTimerExpired()'
bool InstantGPS_mg4100::isTimerExpired( void )
{
	// {{{USR

	return (bool)m_timerDone;
	// }}}USR
}
// }}}RME

// {{{RME operation 'timerStop()'
void InstantGPS_mg4100::timerStop( void )
{
	// {{{USR
	//Stops timer.

	m_timerVirtual->set(0);  //reset timer.

	// }}}USR
}
// }}}RME

// {{{RME operation 'isRxDataAvailable()'
bool InstantGPS_mg4100::isRxDataAvailable( void )
{
	// {{{USR
	bool retval = false;
	Connection::Status * uartStatus = 0;

	uartStatus = ((Connection *)m_uartConnection)->getStatus();
	retval = uartStatus->isDataAvailable();

	return retval;

	// }}}USR
}
// }}}RME

// {{{RME operation 'notifyUserOfStatus(unsigned int)'
void InstantGPS_mg4100::notifyUserOfStatus( unsigned int eventcode )
{
	// {{{USR
	char * unusedptr = 0;
	int unusedarg = 0;
	// write to global status variable
	m_userErrorStatus = eventcode;

	if( m_userEventHandler != 0 )
	{
	  m_userEventHandler->processEvent(eventcode, unusedptr,unusedarg );
	}

	// }}}USR
}
// }}}RME

// {{{RME operation 'receiveFromPGAM(unsigned int)'
unsigned int InstantGPS_mg4100::receiveFromPGAM( unsigned int numCharsToGet )
{
	// {{{USR

	int retval = 0;
	Connection::Status * connectionStatus;
		
	int numCharsReceived = 0;
	SCharArray * rxBufferObj = 0;
	TimeSpec myTime(0,100L*1000000L);

	do
	{
	     connectionStatus = m_uartConnection->getStatus();
		          
	     if( connectionStatus->isDataAvailable() == true )
	     {
			  // get the data
			  SCharArray * rxBufferObj = (SCharArray *)m_uartConnection->receive();

			  if( rxBufferObj != 0)
			  {
				   // get length of the data in the SCharArray
				   int length = rxBufferObj->getLength();

				   for(int i = 0; i < length; i++)
				   {
						m_RxData[numCharsReceived] = (*rxBufferObj)[i];
						numCharsReceived++;

						if(numCharsReceived == numCharsToGet)
						{
							 delete rxBufferObj; 
							 return numCharsReceived;
						}
				   }

		        	
			  } // if( rxBufferObj != 0)

	     }
	     else
	     {
		  // Lets wait till some data arrives.  
		  Thread::nanosleep(myTime);
	     }


	}while( (numCharsReceived < numCharsToGet) && (!isTimerExpired()) );

	return retval;

	// }}}USR
}
// }}}RME

// {{{RME operation 'flush()'
void InstantGPS_mg4100::flush( void )
{
	// {{{USR
	//Flush receive buffer.

	SCharArray * rxBufferObj = 0;
	while (isRxDataAvailable() == true)
	{
	rxBufferObj = (SCharArray *)m_uartConnection->receive();
	delete rxBufferObj;
	}


	// }}}USR
}
// }}}RME

// {{{RME operation 'launchBootloadThread()'
void InstantGPS_mg4100::launchBootloadThread( void )
{
	// {{{USR

	// download error flag, set to no error
	m_ramError = 0;
	m_versionError = 0;

	Thread * theThread = 0;

	// Create the thread that will perform the device searches
	theThread = actuallyCreateThread( Thread::getPriorityMin() ,this, 2048, "PGAMthrd");

	// mark thread for detachment after returning from main.    
	theThread->detach();

	// }}}USR
}
// }}}RME

// {{{RME operation 'readToInt(char[],unsigned int)'
unsigned int InstantGPS_mg4100::readToInt( char str[], unsigned int count )
{
	// {{{USR

	//Reads 'count' number of element values to an integer value.
		 unsigned int i, n;

		 n = 0;

		 for( i = 0; i < count; i++ )
		 {
			  n = 10 * n + str[i];
		 }
		 return n;

	// }}}USR
}
// }}}RME

// {{{RME operation 'InstantGPS_mg4100(Connection *,IOVirtual *,TimerVirtual *,char *,int,char *,GPSEventHandlerBase *,uint32_t,bool)'
InstantGPS_mg4100::InstantGPS_mg4100( Connection * uartConnection, IOVirtual * resetPin, TimerVirtual * timer, char * gpsFirmwareLocation, int gpsFirmwarePagesNum, char * clockStringAddress, GPSEventHandlerBase * event_handler, uint32_t firmwareVersion, bool launchThread )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	:m_uartConnection(uartConnection),m_resetPin(resetPin),m_timerVirtual(timer),m_gpsFirmwareLocation(gpsFirmwareLocation),m_gpsFirmwarePagesNum(gpsFirmwarePagesNum),m_clockStringAddress(clockStringAddress), m_userEventHandler(event_handler), m_firmwareVersion(firmwareVersion), m_userErrorStatus(0)


	// }}}USR
	// }}}RME
{
	// {{{USR

	// constructor arguments are saved via constructor initializer - see C++ tab

	if(launchThread == true)
	{
	 launchBootloadThread();
	}
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
