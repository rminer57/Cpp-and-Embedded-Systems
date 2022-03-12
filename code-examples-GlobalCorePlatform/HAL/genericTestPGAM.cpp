// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::genericTests::genericTestsMOTICs::genericTestsPGAM::genericTestPGAM'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "genericTestPGAM.h"
#endif

#include <HALtestLib_win32.h>
#include <genericTestPGAM.h>
#include <IOVirtual.h>
#include <InstantGPS_mg4100.h>
#include <PGAMUserSupplieddata.h>
#include <SCharArray.h>
#include <TimerVirtual.h>
#include <targetConfigBase.h>
#include <targetConfigPGAM.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'execute(genericTestBase::testConfig *)'
genericTestBase::testResult * genericTestPGAM::execute( genericTestBase::testConfig * config )
{
	// {{{USR

	   targetConfigBase::sendStringToStderr("genericTestPGAM execute() method!\n");

	// targetConfigWin initializes these resources...
	//targetConfigBase::m_uartArray[0]
	//targetConfigBase::m_softTimerVirtual
	// add pins needed for the testing. the test object will extract them as IOVirtuals,
	   // not knowning or needing to know if executing on windows or on Omap.
	   //m_PinsGPIO->savePin(targetConfigBase::PGAM_RESET_PIN, (IOVirtual *)new IOVirtualPinSimulationPGAMreset());

	// ************************************
	// old init code that was in a thread
	// ************************************

	// call the target config object's init method
	//m_targetConfig->initAll();

	//m_targetConfig->ConsoleInterface::send("initializing reset pin, timer and uart \n");


	// ************** prove reset, timer and uart work ************************
	// this will cause the timer to call the eventOccurred method of this class
	// when a timeout occurs, and print messages to the console window.
	// m_targetConfig->m_timer->registerListener(this,TimerVirtual::Event::TIMER_EVENT);
	// m_targetConfig->m_timer->set(2);
	//m_targetConfig->m_resetPin->send(0);
	//m_targetConfig->sendStringToUart("uart on com1 works! \n");
	// ************************************************************************
	  PGAMUserSupplieddata * pgamData = new PGAMUserSupplieddata();

	  char * clockStringAddr = 0;

	  InstantGPS_mg4100 * m_PGAMdriver;

#define PGAMfirmwareVERSION 0x80
#define TICKTIME 30

	clockStringAddr = pgamData->m_PGAM_clockStringArray;



	  m_PGAMdriver = new InstantGPS_mg4100((Connection *)targetConfigBase::m_PGAMuart, 
	                                        targetConfigBase::m_PGAMchipSelect, 
	                                        targetConfigBase::m_softTimerVirtual, 
	                                        pgamData->m_PGAM_Firmware_Array, 
	                                        pgamData->m_PGAM_Firmware_LenPage, 
	                                        pgamData->m_PGAM_clockStringArray,this, PGAMfirmwareVERSION,TICKTIME);


	// m_targetConfigPgam->m_pgam->launchBootloadThread();  

	  //  m_PGAMdriver->m_userErrorStatus 

	//m_targetConfig->ConsoleInterface::send("entering test thread while loop\n");


	return 0;
	// }}}USR
}
// }}}RME

// {{{RME operation 'init(genericTestBase::initConfig *)'
genericTestBase::initResult * genericTestPGAM::init( genericTestBase::initConfig * config )
{
	// {{{USR

	if( config != 0)
	{
	  m_initConfig_ptr = config;

	  config->m_targetConfig->init();
	}

	return 0;


	targetConfigBase::sendStringToStderr("genericTestPGAM init() method!\n");

	// }}}USR
}
// }}}RME

// {{{RME operation 'eventOccurred(const EventBase * const)'
void genericTestPGAM::eventOccurred( const EventBase * const event )
{
	// {{{USR
	if (event->isType(TimerVirtual::Event::TIMER_EVENT))
	{

	// m_targetConfig->ConsoleInterface::send("TimerVirtual::Event::TIMER_EVENT eventOccurred executed! \n");
	// m_targetConfig->sendStringToUart("uart on com1 works! \n");

	}


	// Register for rx data available event     
	//Connection::Status * serialStatus = m_serialIO->getStatus(); 
	//serialStatus->registerListener(this, Connection::Status::Event::DATA_AVAILABLE); 

	// for uart
	//if (event->isType(Connection::Status::Event::DATA_AVAILABLE))
	//{

	// here is the event types for io pin transitions
	//if( event->isEvent(IOVirtual::Event::EVENT_IO_LEVEL_CHANGE) ) 
	//{

	//}


	//if( event->isEvent(IOVirtual::Event::EVENT_IO_EDGE_CHANGE_LtoH) ) 
	//{
	   
	//}

	//if( event->isType(IOVirtual::Event::EVENT_IO_EDGE_CHANGE_HtoL) ) 
	//{
	   
	//}
	// }}}USR
}
// }}}RME

// {{{RME operation 'processEvent(unsigned int,void *,int)'
void genericTestPGAM::processEvent( unsigned int eventcode, void * optionaldata, int optionalarg )
{
	// {{{USR
		volatile unsigned int m_userErrorStatus;
		volatile m_userErrorStatusValue = 0;

	if(eventcode == InstantGPS_mg4100::STATUS_BOOTLOAD_DONE)
	{
	   targetConfigBase::sendStringToStderr("genericTestPGAM processEvent STATUS_BOOTLOAD_DONE\n");
	}

	else if(eventcode == InstantGPS_mg4100::STATUS_BOOTLOAD_FAILED)
	{
	   targetConfigBase::sendStringToStderr("genericTestPGAM processEvent STATUS_BOOTLOAD_FAILED\n");
	}
	else if(eventcode == InstantGPS_mg4100::STATUS_BOOTLOAD_IN_PROGRESS)
	{
	   targetConfigBase::sendStringToStderr("genericTestPGAM processEvent STATUS_BOOTLOAD_IN_PROGRESS\n");
	}
	else if(eventcode == InstantGPS_mg4100::STATUS_BOOTSTRAP_JUMP_TO_ADDRESS_FAILED)
	{
	   targetConfigBase::sendStringToStderr("genericTestPGAM processEvent STATUS_BOOTSTRAP_JUMP_TO_ADDRESS_FAILED\n");
	}
	else if(eventcode == InstantGPS_mg4100::STATUS_CHKSM_ERROR)
	{
	   targetConfigBase::sendStringToStderr("genericTestPGAM processEvent STATUS_CHKSM_ERROR\n");
	}
	else if(eventcode == InstantGPS_mg4100::STATUS_ERROR_DEVICE_BAUD_RATE_NOT_SET)
	{
	   targetConfigBase::sendStringToStderr("genericTestPGAM processEvent STATUS_ERROR_DEVICE_BAUD_RATE_NOT_SET\n");
	}
	else if(eventcode == InstantGPS_mg4100::STATUS_ERROR_DEVICE_NOT_DETECTED)
	{
	   targetConfigBase::sendStringToStderr("genericTestPGAM processEvent STATUS_ERROR_DEVICE_NOT_DETECTED\n");
	}
	else if(eventcode == InstantGPS_mg4100::STATUS_ERROR_FIRMWARE_CORRUPT)
	{
	   targetConfigBase::sendStringToStderr("genericTestPGAM processEvent STATUS_ERROR_FIRMWARE_CORRUPT\n");
	}
	else if(eventcode == InstantGPS_mg4100::STATUS_ERROR_FIRMWARE_VERSION_ERROR)
	{
	   targetConfigBase::sendStringToStderr("genericTestPGAM processEvent STATUS_ERROR_FIRMWARE_VERSION_ERROR\n");
	}
	else if(eventcode == InstantGPS_mg4100::STATUS_ERROR_GPS_COMMUNICATION_FAILURE)
	{
	   targetConfigBase::sendStringToStderr("genericTestPGAM processEvent STATUS_ERROR_GPS_COMMUNICATION_FAILURE\n");
	}
	else if(eventcode == InstantGPS_mg4100::STATUS_FIRMWARE_SUCCESS)
	{
	   targetConfigBase::sendStringToStderr("genericTestPGAM processEvent STATUS_FIRMWARE_SUCCESS\n");
	}
	else if(eventcode == InstantGPS_mg4100::STATUS_KEYWORDVALID_CKSUM_FAILURE)
	{
	   targetConfigBase::sendStringToStderr("genericTestPGAM processEvent STATUS_KEYWORDVALID_CKSUM_FAILURE\n");
	}
	else if(eventcode == InstantGPS_mg4100::STATUS_LISTENING_FOR_PGAM)
	{
	   targetConfigBase::sendStringToStderr("genericTestPGAM processEvent STATUS_LISTENING_FOR_PGAM\n");
	}
	else if(eventcode == InstantGPS_mg4100::STATUS_TRYING_BOOTLOAD_AGAIN)
	{
	   targetConfigBase::sendStringToStderr("genericTestPGAM processEvent STATUS_TRYING_BOOTLOAD_AGAIN\n");
	}
	else if(eventcode == InstantGPS_mg4100::STATUS_TXBUF_SEND_ERROR)
	{
	   targetConfigBase::sendStringToStderr("genericTestPGAM processEvent STATUS_TXBUF_SEND_ERROR\n");
	}

	else
	{
	   targetConfigBase::sendStringToStderr("genericTestPGAM processEvent unhandled event code \n");
	}
	// make sure the value of InstantGPS_mg4100::m_userErrorStatus is the same as the eventcode
	//m_userErrorStatusValue = m_PGAMdriver->m_userErrorStatus;

	// }}}USR
}
// }}}RME

// {{{RME operation 'genericTestPGAM(targetConfigBase *)'
genericTestPGAM::genericTestPGAM( targetConfigBase * hwPlatformConfig )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR

	genericTestBase::initConfig * hwconf = new genericTestBase::initConfig(hwPlatformConfig);

	init(hwconf);

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
