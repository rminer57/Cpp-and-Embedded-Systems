// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::targetConfigObjects::configMotorola_ICs::targetConfigMotICs'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "targetConfigMotICs.h"
#endif

#include <HALtestLib_win32.h>
#include <targetConfigMotICs.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
targetConfigMotICs::targetConfigMotICs( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
targetConfigMotICs::~targetConfigMotICs( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
targetConfigMotICs::targetConfigMotICs( const targetConfigMotICs & rtg_arg )
	: targetConfigBase( rtg_arg )
	, m_PGAMdriver( rtg_arg.m_PGAMdriver )
	, m_resetPinPGAM( rtg_arg.m_resetPinPGAM )
	, m_targetConfig( rtg_arg.m_targetConfig )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
targetConfigMotICs & targetConfigMotICs::operator=( const targetConfigMotICs & rtg_arg )
{
	if( this != &rtg_arg )
	{
		targetConfigBase::operator=( rtg_arg );
		m_PGAMdriver = rtg_arg.m_PGAMdriver;
		m_resetPinPGAM = rtg_arg.m_resetPinPGAM;
		m_targetConfig = rtg_arg.m_targetConfig;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'targetConfigMotICs(targetConfigBase *)'
targetConfigMotICs::targetConfigMotICs( targetConfigBase * targetConfig )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR


	m_targetConfig = targetConfig;
	// }}}USR
}
// }}}RME

// {{{RME operation 'init()'
void targetConfigMotICs::init( void )
{
	// {{{USR
	// targetConfigMotICs

	// }}}USR
}
// }}}RME

// {{{RME operation 'initPGAM()'
void targetConfigMotICs::initPGAM( void )
{
	// {{{USR
	// PGAMUserSupplieddata * pgamData = new PGAMUserSupplieddata();
	  
	//m_PGAMdriver = new InstantGPS_mg4100((Connection *)m_targetConfig->m_uart2_IOVirtualSerial, 
	//                                        m_targetConfig->m_resetPinPGAM, 
	//                                        m_targetConfig->m_timer, 
	//                                        (char *)pgamData->m_PGAM_Firmware_Array, 
	//                                        (int)pgamData->m_PGAM_Firmware_LenPage, 
	//                                        (char *)pgamData->m_PGAM_clockStringArray,this);
	// }}}USR
}
// }}}RME

// {{{RME operation 'processEvent(unsigned int,void *,int)'
void targetConfigMotICs::processEvent( unsigned int eventcode, void * optionaldata, int optionalarg )
{
	// {{{USR
	int STATUS_FIRMWARE_SUCCESScounter = 0;
	int STATUS_ERROR_GPS_COMMUNICATION_FAILUREcounter = 0;
	int STATUS_ERROR_FIRMWARE_CORRUPTcounter = 0;
	int STATUS_ERROR_DEVICE_NOT_DETECTEDcounter = 0;
	int STATUS_ERROR_DEVICE_BAUD_RATE_NOT_SETcounter = 0;
	int othercode = 0;

	volatile int eventargument = eventcode;
	volatile int m_userErrorStatusValue = 0;

	if(eventcode == InstantGPS_mg4100::STATUS_FIRMWARE_SUCCESS)
	{
	    STATUS_FIRMWARE_SUCCESScounter++;

	}

	else if(eventcode == InstantGPS_mg4100::STATUS_ERROR_GPS_COMMUNICATION_FAILURE)
	{
	    STATUS_ERROR_GPS_COMMUNICATION_FAILUREcounter++;

	}

	else if(eventcode == InstantGPS_mg4100::STATUS_ERROR_FIRMWARE_CORRUPT)
	{
	    STATUS_ERROR_FIRMWARE_CORRUPTcounter++;

	}
	else if(eventcode == InstantGPS_mg4100::STATUS_ERROR_DEVICE_NOT_DETECTED)
	{
	    STATUS_ERROR_DEVICE_NOT_DETECTEDcounter++;

	}
	else if(eventcode == InstantGPS_mg4100::STATUS_ERROR_DEVICE_BAUD_RATE_NOT_SET)
	{
	    STATUS_ERROR_DEVICE_BAUD_RATE_NOT_SETcounter++;

	}

	else
	{

	   othercode = eventcode;

	}

	// make sure the value of InstantGPS_mg4100::m_userErrorStatus is the same as the eventcode
	//m_userErrorStatusValue = m_targetConfig->m_PGAMdriver->m_userErrorStatus;

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
