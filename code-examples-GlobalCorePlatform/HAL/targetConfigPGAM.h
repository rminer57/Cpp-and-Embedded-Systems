// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::targetConfigObjects::configMotorola_ICs::targetConfigPGAM'

#ifndef targetConfigPGAM_H
#define targetConfigPGAM_H

#ifdef PRAGMA
#pragma interface "targetConfigPGAM.h"
#endif

#include <HALtestLib_win32.h>
#include <targetConfigBase.h>
class GPSEventHandlerBase;
class InstantGPS_mg4100;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class targetConfigPGAM : public targetConfigBase
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
	// {{{RME classAttribute 'm_uart'
	IOVirtualSerial * m_uart;
	// }}}RME
	// {{{RME classAttribute 'm_resetPin'
	IOVirtual * m_resetPin;
	// }}}RME
	// {{{RME classAttribute 'm_timer'
	TimerVirtual * m_timer;
	// }}}RME
	// {{{RME classAttribute 'm_firmwareData'
	char * m_firmwareData;
	// }}}RME
	// {{{RME classAttribute 'm_numOfPages'
	int m_numOfPages;
	// }}}RME
	// {{{RME classAttribute 'm_clockstring'
	char * m_clockstring;
	// }}}RME
	// {{{RME classAttribute 'm_eventHandler'
	GPSEventHandlerBase * m_eventHandler;
	// }}}RME
	// {{{RME classAttribute 'm_pgam'
	InstantGPS_mg4100 * m_pgam;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	targetConfigPGAM( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~targetConfigPGAM( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	targetConfigPGAM( const targetConfigPGAM & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	targetConfigPGAM & operator=( const targetConfigPGAM & rtg_arg );
	// }}}RME
	// {{{RME operation 'init()'
	void init( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* targetConfigPGAM_H */

// }}}RME
