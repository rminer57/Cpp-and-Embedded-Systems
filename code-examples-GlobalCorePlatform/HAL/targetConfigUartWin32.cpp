// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::targetConfigObjects::configWin32::targetConfigUartWin32'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "targetConfigUartWin32.h"
#endif

#include <HALtestLib_win32.h>
#include <targetConfigUartWin32.h>
#include <Mako.h>
#include <abacusIII.h>
#include <fractionalN.h>
#include <targetConfigAbacus.h>
#include <targetConfigLvFracN.h>
#include <targetConfigMako.h>
#include <targetConfigPGAM.h>
#include <targetConfigTomahawk.h>
#include <tomahawk.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'm_uart'
IOVirtualSerial * targetConfigUartWin32::m_uart;
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
targetConfigUartWin32::targetConfigUartWin32( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
targetConfigUartWin32::~targetConfigUartWin32( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
targetConfigUartWin32::targetConfigUartWin32( const targetConfigUartWin32 & rtg_arg )
	: targetConfigBase( rtg_arg )
	, ListenerBase( rtg_arg )
	, m_uartcfg( rtg_arg.m_uartcfg )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
targetConfigUartWin32 & targetConfigUartWin32::operator=( const targetConfigUartWin32 & rtg_arg )
{
	if( this != &rtg_arg )
	{
		targetConfigBase::operator=( rtg_arg );
		ListenerBase::operator=( rtg_arg );
		m_uartcfg = rtg_arg.m_uartcfg;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'init()'
void targetConfigUartWin32::init( void )
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'receiveFromUart(unsigned char *,int,int)'
int targetConfigUartWin32::receiveFromUart( unsigned char * buffer, int numCharsToGet, int whichUart )
{
	// {{{USR
	int retval = 0;
	//Connection::Status * connectionStatus;
	//Connection * uartConnection = 0;
	//int numCharsReceived = 0;
	//SCharArray * rxBufferObj = 0;
	 
	//TimeSpec tp(0,30000000); // 30 mSec = 30,000uSec = 30000000nSec 

	//switch(whichUart)
	//{
	//  case 3:
	         // does nothing right now.
	//         return retval;
	//  break;

	//  case 2:
	//         uartConnection = (Connection *)m_uart2_IOVirtualSerial;
	//         m_uart2cfg->m_threshold = numCharsToGet;
	//         uartConnection->setOption(m_uart2cfg);

	//  break;

	//  case 1:
	//  default:
	//         uartConnection = (Connection *)m_uart1_IOVirtualSerial;
	//         m_uart1cfg->m_threshold = numCharsToGet;
	//         uartConnection->setOption(m_uart1cfg);

	//  break;
	//}

	//    do
	//    {
	//        connectionStatus = uartConnection->getStatus();
	          
	//        if( connectionStatus->isDataAvailable() == true )
	//        {
	          // get the data
	//          SCharArray * rxBufferObj = (SCharArray *)uartConnection->receive();

	//    	  if( rxBufferObj != 0)
	//    	  {
	            // get length of the data in the SCharArray
	//       	    int length = rxBufferObj->getLength();

	//        	for(int i = 0; i < length; i++)
	//        	{
	//           		buffer[numCharsReceived] = (*rxBufferObj)[i];
	//                numCharsReceived++;

	//                if(numCharsReceived == numCharsToGet)
	//                {
	//                  delete rxBufferObj; 
	//                  return retval;
	//                }
	//        	}

	        	
	//    	  } // if( rxBufferObj != 0)

	//        }
	//        else
	//        {
	          // wait for eventOccurred to get characters
	          // Lets wait till some data arrives.  
	          // eventOccured will set the semaphore Blocks task till sem goes positive.
	//          m_sem->wait();
	//        }


	//    }while( numCharsReceived < numCharsToGet);


	    return retval;
	 
	// }}}USR
}
// }}}RME

// {{{RME operation 'init(unsigned int)'
void targetConfigUartWin32::init( unsigned int whichUart )
{
	// {{{USR

	   	
		 switch(whichUart)
	     {
		   case 1:
		          if(m_uart == 0)
		          {

		           // Get IOVirtualSerial instance. 
		           m_uart = new IOVirtualSerialCom(19200,"COM1");

	               // init a semaphore for this uart
	               //m_sem = Sem::createSem(whichUart);
		          }
	       case 2:

		   
		          if(m_uart == 0)
		          {

		           // Get IOVirtualSerial instance. 
		           m_uart = new IOVirtualSerialCom(19200,"COM2");

	               // init a semaphore for this uart
	               //m_sem = Sem::createSem(whichUart);
		          }

	       break;
			   
		  };  
	// }}}USR
}
// }}}RME

// {{{RME operation 'targetConfigUartWin32(unsigned int)'
targetConfigUartWin32::targetConfigUartWin32( unsigned int whichUart )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	  
	 init(whichUart);
	 
	// }}}USR
}
// }}}RME

// {{{RME operation 'getIOVirtualSerial()'
IOVirtualSerial * targetConfigUartWin32::getIOVirtualSerial( void )
{
	// {{{USR

	return m_uart;
	// }}}USR
}
// }}}RME

// {{{RME operation 'eventOccurred(const EventBase * const)'
void targetConfigUartWin32::eventOccurred( const EventBase * const event )
{
	// {{{USR
	//Connection::Status * connectionStatus;
	//Connection * theConnection;
	//volatile unsigned char buffer[32]; // for verification of data receipt

	// uart receive data events
	//if( event->isType(RXThresholdEvent::RX_THRESHOLD_EVENT) )
	//{
	//  if(  m_uart1_IOVirtualSerial != 0 )
	//  {
	//    theConnection = (Connection *)m_uart1_IOVirtualSerial;
	//    connectionStatus = theConnection->getStatus();
	  
	//    if( connectionStatus->isDataAvailable() )
	//    {
	      // Increment the semaphore so that the rx task will wake up and receive the data.
	//      m_sem->post();    
	//    }
	//  }

	//  if(  m_uart2_IOVirtualSerial != 0 )
	//  {
	//    theConnection = (Connection *)m_uart2_IOVirtualSerial;
	//    connectionStatus = theConnection->getStatus();
	 
	//    if( connectionStatus->isDataAvailable() )
	//    {
	      	// Increment the semaphore so that the rx task will wake up and receive the data.
	//      	m_sem->post();

	//    } // end if( connectionStatus->isDataAvailable() )

	//  } 
	//}

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
