// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::targetConfigObjects::configWin32::targetConfigWin32'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "targetConfigWin32.h"
#endif

#include <HALtestLib_win32.h>
#include <targetConfigWin32.h>
#include <Connection.h>
#include <IOVirtual.h>
#include <IOVirtualPinSimulation.h>
#include <IOVirtualSerial.h>
#include <IOVirtualSerialSimSPI.h>
#include <IOVirtualSerialSimulationStderr.h>
#include <OptionQuantizationUnit.h>
#include <RXThresholdEvent.h>
#include <SoftTimerFactory.h>
#include <TimerVirtual.h>
#include <TimerVirtualFactory.h>
#include <UartConfig.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'init()'
void targetConfigWin32::init( void )
{
	// {{{USR

	   // *************************************************************************
	   // init stderr
	   // *************************************************************************
	   // stderr output for this target. On windows, this is the console (iostream)
	   // on radios HPD, LTD and MCH control head, it is uart 1 of Omap
	   targetConfigBase::m_platform_stderr = new IOVirtualSerialSimulationStderr();

	   // *************************************************************************
	   // init uarts
	   // *************************************************************************

	   targetConfigBase::m_targetConfigArray[targetConfigBase::UART1] = (targetConfigBase *)new targetConfigUartWin32(1);
	   targetConfigBase::m_uartArray[0] = ((targetConfigUartWin32 *) targetConfigBase::m_targetConfigArray[targetConfigBase::UART1])->getIOVirtualSerial();
	 
	   targetConfigBase::m_targetConfigArray[targetConfigBase::UART2] = (targetConfigBase *)new targetConfigUartWin32(2);
	   targetConfigBase::m_uartArray[1] = ((targetConfigUartWin32 *) targetConfigBase::m_targetConfigArray[targetConfigBase::UART2])->getIOVirtualSerial();
	 
	   // *************************************************************************
	   // initialize soft timer
	   // *************************************************************************
	   // Setup timer factory thread. The timer will not work correctly if it is less that the underlying
	   // tic time of the operating system... win32 is 20-30mSec.
	   SoftTimerFactory * tfactory = new SoftTimerFactory(30); // set for 30mSec.

	   //Create a new timer - default, auto re-arming timer. 
	   targetConfigBase::m_softTimerVirtual = tfactory->getTimerVirtual();

	   // *************************************************************************
	   // initialize io pins (on Omap, can be gpio, mpuio or keypad
	   // *************************************************************************
	   // create the pin manager object.
	   // this array holds IOVirtual pointers.
	   targetConfigBase::m_PinsGPIO = new targetConfigBase::IOPinManager(64);

	   IOVirtual * pgamPin = 0;

	   pgamPin = new IOVirtualPinSimulation(IOVirtualPinSimulation::PGAM_CSPIN);

	   // add pins needed for the testing. the test object will extract them as IOVirtuals,
	   // not knowning or needing to know if executing on windows or on Omap.
	   m_PinsGPIO->savePin(targetConfigBase::PGAM_RESET_PIN, pgamPin);

	   targetConfigBase::m_PGAMuart = targetConfigBase::m_uartArray[0]; // use com1 for PGAM
	   targetConfigBase::m_PGAMchipSelect = pgamPin; 

	   targetConfigBase::m_MakoSPI = new IOVirtualSerialSimSPI(IOVirtualSerialSimSPI::MAKO);
	   targetConfigBase::m_MakochipSelect = new IOVirtualPinSimulation(IOVirtualPinSimulation::MAKO_CSPIN); 

	   targetConfigBase::m_tomahawkSPI = new IOVirtualSerialSimulationStderr();
	   targetConfigBase::m_tomahawkchipSelect = new IOVirtualPinSimulation(IOVirtualPinSimulation::TOMAHAWK_CSPIN); 

	   targetConfigBase::m_abacusSPI = new IOVirtualSerialSimulationStderr();
	   targetConfigBase::m_abacuschipSelect = new IOVirtualPinSimulation(IOVirtualPinSimulation::ABACUS_CSPIN); 


	   targetConfigBase::sendStringToStderr("targetConfigWin32->init() complete\n");


	 


	// }}}USR
}
// }}}RME

// {{{RME operation 'eventOccurred(const EventBase * const)'
void targetConfigWin32::eventOccurred( const EventBase * const event )
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
