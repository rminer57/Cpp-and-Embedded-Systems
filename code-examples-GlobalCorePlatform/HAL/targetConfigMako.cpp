// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::targetConfigObjects::configMotorola_ICs::targetConfigMako'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "targetConfigMako.h"
#endif

#include <HALtestLib_win32.h>
#include <targetConfigMako.h>
#include <Mako.h>
#include <Mako1WireCtrl.h>
#include <MakoADC.h>
#include <MakoAudioInputCtrl.h>
#include <MakoAudioOutputCtrl.h>
#include <MakoDCPwrCtrl.h>
#include <MakoFrontEndFilter.h>
#include <MakoIGNSenseCtrl.h>
#include <MakoIntrCtrl.h>
#include <MakoOPTCTRL.h>
#include <MakoRFPA.h>
#include <MakoRFPowerControl.h>
#include <MakoUSBConstants.h>
#include <MakoUSBCtrl.h>
#include <MakoWatchdogCtrl.h>
#include <PowerConfiguration.h>
#include <USBIOVirtualHandler.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
targetConfigMako::targetConfigMako( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
targetConfigMako::~targetConfigMako( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
targetConfigMako::targetConfigMako( const targetConfigMako & rtg_arg )
	: targetConfigBase( rtg_arg )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
targetConfigMako & targetConfigMako::operator=( const targetConfigMako & rtg_arg )
{
	if( this != &rtg_arg )
		targetConfigBase::operator=( rtg_arg );
	return *this;
}
// }}}RME

// {{{RME operation 'init()'
void targetConfigMako::init( void )
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
