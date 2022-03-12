// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::targetConfigObjects::configMotorola_ICs::targetConfigPGAM'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "targetConfigPGAM.h"
#endif

#include <HALtestLib_win32.h>
#include <targetConfigPGAM.h>
#include <GPSEventHandlerBase.h>
#include <InstantGPS_mg4100.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
targetConfigPGAM::targetConfigPGAM( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
targetConfigPGAM::~targetConfigPGAM( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
targetConfigPGAM::targetConfigPGAM( const targetConfigPGAM & rtg_arg )
	: targetConfigBase( rtg_arg )
	, m_uart( rtg_arg.m_uart )
	, m_resetPin( rtg_arg.m_resetPin )
	, m_timer( rtg_arg.m_timer )
	, m_firmwareData( rtg_arg.m_firmwareData )
	, m_numOfPages( rtg_arg.m_numOfPages )
	, m_clockstring( rtg_arg.m_clockstring )
	, m_eventHandler( rtg_arg.m_eventHandler )
	, m_pgam( rtg_arg.m_pgam )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
targetConfigPGAM & targetConfigPGAM::operator=( const targetConfigPGAM & rtg_arg )
{
	if( this != &rtg_arg )
	{
		targetConfigBase::operator=( rtg_arg );
		m_uart = rtg_arg.m_uart;
		m_resetPin = rtg_arg.m_resetPin;
		m_timer = rtg_arg.m_timer;
		m_firmwareData = rtg_arg.m_firmwareData;
		m_numOfPages = rtg_arg.m_numOfPages;
		m_clockstring = rtg_arg.m_clockstring;
		m_eventHandler = rtg_arg.m_eventHandler;
		m_pgam = rtg_arg.m_pgam;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'init()'
void targetConfigPGAM::init( void )
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
