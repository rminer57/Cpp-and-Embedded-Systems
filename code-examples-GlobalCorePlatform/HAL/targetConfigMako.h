// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::targetConfigObjects::configMotorola_ICs::targetConfigMako'

#ifndef targetConfigMako_H
#define targetConfigMako_H

#ifdef PRAGMA
#pragma interface "targetConfigMako.h"
#endif

#include <HALtestLib_win32.h>
#include <targetConfigBase.h>
class Mako;
class Mako1WireCtrl;
class MakoADC;
class MakoAudioInputCtrl;
class MakoAudioOutputCtrl;
class MakoDCPwrCtrl;
class MakoFrontEndFilter;
class MakoIGNSenseCtrl;
class MakoIntrCtrl;
class MakoOPTCTRL;
class MakoRFPA;
class MakoRFPowerControl;
class MakoUSBConstants;
class MakoUSBCtrl;
class MakoWatchdogCtrl;
class PowerConfiguration;
class USBIOVirtualHandler;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class targetConfigMako : public targetConfigBase
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
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	targetConfigMako( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~targetConfigMako( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	targetConfigMako( const targetConfigMako & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	targetConfigMako & operator=( const targetConfigMako & rtg_arg );
	// }}}RME
	// {{{RME operation 'init()'
	void init( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* targetConfigMako_H */

// }}}RME
