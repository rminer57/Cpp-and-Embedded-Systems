// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::TestSupportWin32::IOvirtualSerialComUartWin32Src::IOVirtualSerialCom::IOVirtualSerialCom'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "IOVirtualSerialCom.h"
#endif

#include <HALtestLib_win32.h>
#include <IOVirtualSerialCom.h>
#include <DataBuffer.h>
#include <Mutex.h>
#include <OptionQuantizationUnit.h>
#include <SCharArray.h>
#include <Sem.h>
#include <UartConfig.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
#include <fcntl.h>
#include <iostream.h>
#include <stdlib.h>
#include "wtypes.h"
#include "winbase.h"
#include "stdio.h"
#include <fstream.h>

ofstream logfile;





// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
IOVirtualSerialCom::IOVirtualSerialCom( void )
	: m_dataAvailable( false )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
IOVirtualSerialCom::IOVirtualSerialCom( const IOVirtualSerialCom & rtg_arg )
	: IOVirtualSerial( rtg_arg )
	, Thread( rtg_arg )
	, Status( rtg_arg )
	, PortNumber( rtg_arg.PortNumber )
	, PortName( rtg_arg.PortName )
	, m_inIndex( rtg_arg.m_inIndex )
	, m_outIndex( rtg_arg.m_outIndex )
	, m_dataAvailable( rtg_arg.m_dataAvailable )
	, m_readOverlapped( rtg_arg.m_readOverlapped )
	, m_writeOverlapped( rtg_arg.m_writeOverlapped )
	, m_baudrate( rtg_arg.m_baudrate )
	, m_sem( rtg_arg.m_sem )
	, m_mutex( rtg_arg.m_mutex )
{
	for( int rtg_m_rxBuffer_index = (MAX_COM_CHARS); --rtg_m_rxBuffer_index >= 0; )
		m_rxBuffer[ rtg_m_rxBuffer_index ] = rtg_arg.m_rxBuffer[ rtg_m_rxBuffer_index ];
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
IOVirtualSerialCom & IOVirtualSerialCom::operator=( const IOVirtualSerialCom & rtg_arg )
{
	if( this != &rtg_arg )
	{
		IOVirtualSerial::operator=( rtg_arg );
		Thread::operator=( rtg_arg );
		Status::operator=( rtg_arg );
		PortNumber = rtg_arg.PortNumber;
		PortName = rtg_arg.PortName;
		m_inIndex = rtg_arg.m_inIndex;
		m_outIndex = rtg_arg.m_outIndex;
		for( int rtg_m_rxBuffer_index = (MAX_COM_CHARS); --rtg_m_rxBuffer_index >= 0; )
			m_rxBuffer[ rtg_m_rxBuffer_index ] = rtg_arg.m_rxBuffer[ rtg_m_rxBuffer_index ];
		m_dataAvailable = rtg_arg.m_dataAvailable;
		m_readOverlapped = rtg_arg.m_readOverlapped;
		m_writeOverlapped = rtg_arg.m_writeOverlapped;
		m_baudrate = rtg_arg.m_baudrate;
		m_sem = rtg_arg.m_sem;
		m_mutex = rtg_arg.m_mutex;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'IOVirtualSerialCom(unsigned long,char *)'
IOVirtualSerialCom::IOVirtualSerialCom( unsigned long baudrate, char * portname )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	unsigned int index;



	m_mutex = Mutex::createMutex();
	m_sem = Sem::createSem(0);

	m_dataAvailable = false;


	for(index=0 ; index<MAX_COM_CHARS; index++ )
	{
	   m_rxBuffer[index] = 0;
	}

	m_inIndex = 0;
	m_outIndex = 0;

	COMMTIMEOUTS cto = {
	        MAXDWORD, // DWORD ReadIntervalTimeout; 
	        MAXDWORD, // DWORD ReadTotalTimeoutMultiplier; 
	        1,      // DWORD ReadTotalTimeoutConstant; 
	        250,        // DWORD WriteTotalTimeoutMultiplier; 
	        250         // DWORD WriteTotalTimeoutConstant; 
	};

	PortName=strdup(portname);

	m_readOverlapped = (void *) new OVERLAPPED;
	((OVERLAPPED*)m_readOverlapped)->Offset = 0;
	((OVERLAPPED*)m_readOverlapped)->OffsetHigh = 0;
	//((OVERLAPPED*)m_readOverlapped)->hEvent = NULL;
	((OVERLAPPED*)m_readOverlapped)->hEvent = ::CreateEvent(NULL, TRUE, FALSE, NULL);

	m_writeOverlapped = (void *)new OVERLAPPED;
	((OVERLAPPED*)m_writeOverlapped) ->Offset = 0;
	((OVERLAPPED*)m_writeOverlapped) ->OffsetHigh = 0;
	//((OVERLAPPED*)m_writeOverlapped) ->hEvent = NULL;
	((OVERLAPPED*)m_writeOverlapped) ->hEvent = ::CreateEvent(NULL, TRUE, FALSE, NULL);

	PortNumber = (void*)CreateFile(PortName, GENERIC_READ | GENERIC_WRITE, 0, NULL,
	 OPEN_EXISTING  , FILE_FLAG_OVERLAPPED, NULL );

	if((HANDLE)PortNumber == INVALID_HANDLE_VALUE )
	{
	   cout << "Port open failed!" << endl;
	}

	SetCommTimeouts(PortNumber,&cto);


	DCB dcb =
	{
	   sizeof(dcb), //DWORD DCBlength;           // sizeof(DCB) 
	   baudrate,    //DWORD BaudRate;            // current baud rate 
	   TRUE,        //DWORD fBinary: 1;          // binary mode, no EOF check 
	   FALSE,       //DWORD fParity: 1;          // enable parity checking 
	   TRUE,        //DWORD fOutxCtsFlow:1;      // CTS output flow control 
	   FALSE,       //DWORD fOutxDsrFlow:1;      // DSR output flow control 
	   TRUE,        //DWORD fDtrControl:2;       // DTR flow control type 
	   FALSE,       //DWORD fDsrSensitivity:1;   // DSR sensitivity 
	   FALSE,       //DWORD fTXContinueOnXoff:1; // XOFF continues Tx 
	   FALSE,       //DWORD fOutX: 1;            // XON/XOFF out flow control 
	   FALSE,       //DWORD fInX: 1;             // XON/XOFF in flow control 
	   FALSE,       //DWORD fErrorChar: 1;       // enable error replacement 
	   FALSE,       //DWORD fNull: 1;            // enable null stripping 
	   TRUE,        //DWORD fRtsControl:2;       // RTS flow control 
	   TRUE,        //DWORD fAbortOnError:1;     // abort reads/writes on error 
	   0,           //DWORD fDummy2:17;          // reserved 
	   0,           //WORD wReserved;            // not currently used 
	   0,           //WORD XonLim;               // transmit XON threshold 
	   0,           //WORD XoffLim;              // transmit XOFF threshold 
	   8,           //BYTE ByteSize;             // number of bits/byte, 4-8 
	   NOPARITY,           //BYTE Parity;               // 0-4=no,odd,even,mark,space 
	   ONESTOPBIT,           //BYTE StopBits;             // 0,1,2 = 1, 1.5, 2 
	   0,           //char XonChar;              // Tx and Rx XON character 
	   0,           //char XoffChar;             // Tx and Rx XOFF character 
	   0,           //char ErrorChar;            // error replacement character 
	   0,           //char EofChar;              // end of input character 
	   0,           //char EvtChar;              // received event character 
	   0            //WORD wReserved1;           // reserved; do not use 
	};

	//SetupComm(PortNumber,/*inqueue*/ 4096,/*outqueue*/ 4096);

	if ( GetCommState( PortNumber, &dcb ) )
	{
	   dcb.BaudRate = baudrate;
	   dcb.ByteSize = 8;
	   dcb.Parity = NOPARITY;
	   dcb.StopBits = ONESTOPBIT;
	   dcb.fOutxCtsFlow = FALSE;
	   dcb.fRtsControl = FALSE;
	   dcb.fOutxDsrFlow= FALSE;
	   dcb.fDtrControl= FALSE;
	   dcb.fInX= FALSE;
	   dcb.fOutX= FALSE;
	   dcb.fParity= FALSE;
	   dcb.fDtrControl= FALSE;

	}
	else
	{
	   cout << "could not GET comm state" << endl;
	}


	if (!SetCommState(PortNumber,&dcb))
	{
	   cout << "could not SET comm state" << endl;
	}

	m_baudrate = baudrate;





	//
	// Launch the thread.
	//


	// set up the priority to be minimum for the thread
	int pri = (Thread::getPriorityMin() + Thread::getPriorityMax() )/2;

	// create the thread and run everything else from the main program
	actuallyCreateThread(pri, this);

	// }}}USR
}
// }}}RME

// {{{RME operation 'activate()'
bool IOVirtualSerialCom::activate( void )
{
	// {{{USR
	return true;
	// }}}USR
}
// }}}RME

// {{{RME operation 'deactivate()'
bool IOVirtualSerialCom::deactivate( void )
{
	// {{{USR
	return true;
	// }}}USR
}
// }}}RME

// {{{RME operation 'receive()'
Array * IOVirtualSerialCom::receive( void )
{
	// {{{USR
	DataBuffer * myDataBuffer;
	SCharArray * mySCharArray;
	unsigned int semVal;
	char * receivedData;
	unsigned int uiLength;

	// decrement the sem.  We'll block if no data is present.
	m_sem->wait();


	// at this point, we have data. 
	m_mutex->lock();

	semVal = (char)m_sem->getValue();

	if( semVal  == 0 )
	{
	   // We've depleted the queue.  Update the status accordingly.
	   setIsDataAvailable(false);
	}

	// Grab the buffer from the queue.
	// myDataBuffer = new DataBuffer(&m_rxBuffer[m_outIndex], 1, false);
	// The order of the length and buffer pointer are reversed from DataBuffer
	mySCharArray = new SCharArray(1, ( char*)&m_rxBuffer[m_outIndex], false);

#ifdef LOG_UART_DATA_TO_FILE

	   // Get a pointer to the internal buffer
	   receivedData = (char*)*(*(SCharArray*)mySCharArray);

	   uiLength = mySCharArray->getLength();

	   logfile.open("c:\uartlogfile.txt", ios::out | ios:app | ios:binary );

	   logfile << endl << " Sending: ";   
	   for(int xx = 0; xx < uiLength; xx++)
	   {
	       logfile << *(receivedData + xx);     
	   }
	     
	   logfile.close();
#endif

	// point to the next guy in the list.  Handle wrap around too.
	m_outIndex += 1;
	m_outIndex = m_outIndex % MAX_COM_CHARS;

	m_mutex->unlock(); 

	return (mySCharArray);
	// }}}USR
}
// }}}RME

// {{{RME operation 'send(Array *)'
bool IOVirtualSerialCom::send( Array * buffer )
{
	// {{{USR
	bool returnVal = false;
	char * dataToSend;
	DataBuffer * myDataBuffer;
	SCharArray * mySCharArray;

	char error_code[128];
	unsigned long int bytes_written;
	int error_num;


	if ( buffer->isType(DataBuffer::DATA_BUFFER_ARRAY) )
	{
	   // We got a data buffer.  Handle it.
	   myDataBuffer = (DataBuffer *)buffer;

	   // Copy out the payload.
	   dataToSend = (char *)myDataBuffer->copyToArray();

	   error_num = WriteFile((HANDLE)PortNumber, dataToSend, myDataBuffer->getSize() ,&bytes_written, (OVERLAPPED*)m_writeOverlapped);

	   delete [] dataToSend;

	//   if ( bytes_written == 0x00 )
	   if ( false )
	   {
	      sprintf(error_code,"Error.  Bytes written = %d\n",bytes_written);
	      cout << error_code << endl;
	   }

	   returnVal = true;
	}
	else if (buffer->isType(SCharArray::SIGNED_CHAR_ARRAY))
	{
	   // We got a data buffer.  Handle it.
	   mySCharArray = (SCharArray*)buffer;

	   // Get the length of the data
	   unsigned int uiLength = mySCharArray->getLength();
	   
	   // Get a pointer to the internal buffer
	   dataToSend = (char*)*(*(SCharArray*)mySCharArray);

	   // Write to the port
	   error_num = WriteFile((HANDLE)PortNumber, dataToSend , uiLength, &bytes_written, (OVERLAPPED*)m_writeOverlapped);

#ifdef LOG_UART_DATA_TO_FILE

	   logfile.open("c:\uartlogfile.txt", ios::out | ios:app | ios:binary );

	   logfile << endl << " Sending: ";   
	   for(int xx = 0; xx < uiLength; xx++)
	   {
	       logfile << *(dataToSend + xx);     
	   }
	     
	   logfile.close();
#endif


	   delete [] dataToSend;

	   if ( false )
	   {
	      sprintf(error_code,"Error.  Bytes written = %d\n",bytes_written);
	      cout << error_code << endl;
	   }

	   returnVal = true;
	}


	if(returnVal == true)
	{
	   // We sent the data.  Consume the DataBuffer that was given to us.
	   delete buffer;
	}

	return returnVal;
	// }}}USR
}
// }}}RME

// {{{RME operation 'main()'
void * IOVirtualSerialCom::main( void )
{
	// {{{USR
	bool inProgress;
	    char result;
	    unsigned char buffer[10];
	    DWORD numRead, error;

	inProgress = FALSE;
	bool bImmediate = false;

	while ( 1 ) // Loop until exit condition is met
	{
	  if ( !inProgress ) // check if a read is in progress already
	  {
	      // Start out as false
	      bImmediate = false;

	      // No read in progress, so start one
	      if ( ::ReadFile(PortNumber, buffer, 1, &numRead, (OVERLAPPED*)m_readOverlapped) )
	      {
	          // Overlapped read returned immediately with data
	          if ( numRead > 0 )
	          {
	              result = buffer[0];
	              bImmediate = true;
	          }
	      }
	      else
	      {
	          // Check if operation pending or error
	          error = GetLastError();
	          if ( error == ERROR_IO_PENDING )
	          {
	              inProgress = TRUE;
	          }
	          else
	          {
	              // Handle error
	          }
	      }
	  }

	  if ( bImmediate == false  ) // If no immediate result...
	  {
	      // Wait for 'wait' milliseconds (1 second in this example)
	      if (WaitForSingleObject(((OVERLAPPED*)m_readOverlapped)->hEvent, 1) == WAIT_OBJECT_0)
	      {
	          // Didn't time out, so get the data and reset the event
	          GetOverlappedResult(PortNumber, (OVERLAPPED*)m_readOverlapped, &numRead, FALSE);
	          if ( numRead > 0 )
	          {
	              result = buffer[0];
				  bImmediate = true;
	          }
	          ResetEvent(((OVERLAPPED*)m_readOverlapped)->hEvent);
	          inProgress = FALSE;
	      }
	  }

	   if ( bImmediate == true )
	   {
	      accumulateData( &result);
	   }

	  // Check exit condition - I usually pass an event to the thread...
	  // if ( WaitForSingleObject(hExitEvent, 0) == WAIT_OBJECT_0 ) break;
	}
	// }}}USR
}
// }}}RME

// {{{RME operation '~IOVirtualSerialCom()'
IOVirtualSerialCom::~IOVirtualSerialCom( void )
{
	// {{{USR
	CloseHandle(PortNumber);
	delete m_mutex;
	delete m_sem;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isDataAvailable()'
bool IOVirtualSerialCom::isDataAvailable( void ) const
{
	// {{{USR
	return m_dataAvailable;
	// }}}USR
}
// }}}RME

// {{{RME operation 'handleInformListeners()'
void IOVirtualSerialCom::handleInformListeners( void )
{
	// {{{USR
	const EventBase myEvent = EventBase(Connection::Status::Event::DATA_AVAILABLE);

	informListeners( &myEvent);
	// }}}USR
}
// }}}RME

// {{{RME operation 'setIsDataAvailable(bool)'
void IOVirtualSerialCom::setIsDataAvailable( bool state )
{
	// {{{USR
	m_dataAvailable = state;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getStatus()'
Connection::Status * IOVirtualSerialCom::getStatus( void )
{
	// {{{USR
	return this;
	// }}}USR
}
// }}}RME

// {{{RME operation 'accumulateData(char *)'
void IOVirtualSerialCom::accumulateData( char * rxChar )
{
	// {{{USR

	bool eventNotificationRequired = false;



	m_mutex->lock();

	if( m_sem->getValue() < MAX_COM_CHARS)
	{
	   m_rxBuffer[m_inIndex] = *rxChar;

	   // Increment index with rollover.
	   m_inIndex += 1;
	   m_inIndex = m_inIndex % MAX_COM_CHARS;


	   if (isDataAvailable() == false )
	   {
	      // We had depleted the data before.  Now there is data.  We must inform the client.
	      setIsDataAvailable(true);
	      eventNotificationRequired = true;
	   }

	   m_sem->post();
	}

	m_mutex->unlock();

	if ( eventNotificationRequired == true )
	{
	   // We had no data, but now we do.  We have to inform listeners.
	   handleInformListeners();
	}



	// }}}USR
}
// }}}RME

// {{{RME operation 'setOption(Configurable::Option *)'
bool IOVirtualSerialCom::setOption( Configurable::Option * option )
{
	// {{{USR
	bool returnVal = false;
	DCB dcb =
	{
	   sizeof(dcb), //DWORD DCBlength;           // sizeof(DCB) 
	   115200L,     //DWORD BaudRate;            // current baud rate 
	   TRUE,        //DWORD fBinary: 1;          // binary mode, no EOF check 
	   FALSE,       //DWORD fParity: 1;          // enable parity checking 
	   TRUE,        //DWORD fOutxCtsFlow:1;      // CTS output flow control 
	   FALSE,       //DWORD fOutxDsrFlow:1;      // DSR output flow control 
	   TRUE,        //DWORD fDtrControl:2;       // DTR flow control type 
	   FALSE,       //DWORD fDsrSensitivity:1;   // DSR sensitivity 
	   FALSE,       //DWORD fTXContinueOnXoff:1; // XOFF continues Tx 
	   FALSE,       //DWORD fOutX: 1;            // XON/XOFF out flow control 
	   FALSE,       //DWORD fInX: 1;             // XON/XOFF in flow control 
	   FALSE,       //DWORD fErrorChar: 1;       // enable error replacement 
	   FALSE,       //DWORD fNull: 1;            // enable null stripping 
	   TRUE,        //DWORD fRtsControl:2;       // RTS flow control 
	   TRUE,        //DWORD fAbortOnError:1;     // abort reads/writes on error 
	   0,           //DWORD fDummy2:17;          // reserved 
	   0,           //WORD wReserved;            // not currently used 
	   0,           //WORD XonLim;               // transmit XON threshold 
	   0,           //WORD XoffLim;              // transmit XOFF threshold 
	   8,           //BYTE ByteSize;             // number of bits/byte, 4-8 
	   NOPARITY,           //BYTE Parity;               // 0-4=no,odd,even,mark,space 
	   ONESTOPBIT,           //BYTE StopBits;             // 0,1,2 = 1, 1.5, 2 
	   0,           //char XonChar;              // Tx and Rx XON character 
	   0,           //char XoffChar;             // Tx and Rx XOFF character 
	   0,           //char ErrorChar;            // error replacement character 
	   0,           //char EofChar;              // end of input character 
	   0,           //char EvtChar;              // received event character 
	   0            //WORD wReserved1;           // reserved; do not use 
	};




	if ( option->isType( UartConfig::UART_CONFIG_OPTION ) )
	{
	   // We have a config option.  We have to handle it.

	   m_baudrate = ((UartConfig*)option)->m_baudRate;

	   if ( GetCommState( PortNumber, &dcb ) )
	   {
	      dcb.BaudRate = ((UartConfig*)option)->m_baudRate;
	      dcb.ByteSize = 8;
	      dcb.Parity = NOPARITY;
	      dcb.StopBits = ONESTOPBIT;
	      dcb.fOutxCtsFlow = FALSE;
	      dcb.fRtsControl = FALSE;
	      dcb.fOutxDsrFlow= FALSE;
	      dcb.fDtrControl= FALSE;
	      dcb.fInX= FALSE;
	      dcb.fOutX= FALSE;
	      dcb.fParity= FALSE;
	      dcb.fDtrControl= FALSE;
	   
	   }
	   else
	   {
	      cout << "could not GET comm state" << endl;
	   }
	   
	   
	   if (!SetCommState(PortNumber,&dcb))
	   {
	      cout << "could not SET comm state" << endl;
	   }
	   
	}

	return returnVal;



#ifdef DITCH_ME_FOR_NOW

	//SetupComm(PortNumber,/*inqueue*/ 4096,/*outqueue*/ 4096);



#endif
	// }}}USR
}
// }}}RME

// {{{RME operation 'getOption(ClassType)'
Configurable::Option * IOVirtualSerialCom::getOption( ClassType optionType ) const
{
	// {{{USR
	Configurable::Option * myuartConfig ;

	      // Default configuration for uart.
	      myuartConfig = new UartConfig(       m_baudrate ,                         // baud rate
	                                           8,                               // data bits
	                                           UartConfig::NONE,                // parity
	                                           1   ,                            // stop bits
	                                           UartConfig::NO_FLOW_CONTROL ,    // flow control
	                                           0x11,                            // xon
	                                           0x13,                            // xoff
	                                           1                                // threshold
	                                           );

	return myuartConfig ;
	// }}}USR
}
// }}}RME

// {{{RME operation 'sendString(char *)'
void IOVirtualSerialCom::sendString( char * string )
{
	// {{{USR
	int len = 0;
	char * temp = 0;
	temp = string;

	while( *temp != 0)
	{
	  len++;
	  temp++;
	}


	SCharArray * txBuffer = new SCharArray(len, string);

	send(txBuffer);



	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
