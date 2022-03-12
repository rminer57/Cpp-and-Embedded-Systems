// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::targetConfigObjects::configWin32::targetConfigWin32'

#ifndef targetConfigWin32_H
#define targetConfigWin32_H

#ifdef PRAGMA
#pragma interface "targetConfigWin32.h"
#endif

#include <HALtestLib_win32.h>
#include <ListenerBase.h>
#include <targetConfigBase.h>
#include <targetConfigUartWin32.h>
class Connection;
class IOVirtual;
class IOVirtualPinSimulation;
class IOVirtualSerial;
class IOVirtualSerialSimSPI;
class IOVirtualSerialSimulationStderr;
class OptionQuantizationUnit;
class RXThresholdEvent;
class SoftTimerFactory;
class TimerVirtual;
class TimerVirtualFactory;
class UartConfig;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>

// }}}USR
// }}}RME

class targetConfigWin32 : public targetConfigBase, public ListenerBase
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
	// {{{RME operation 'init()'
	void init( void );
	// }}}RME
	// {{{RME operation 'eventOccurred(const EventBase * const)'
	void eventOccurred( const EventBase * const event );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* targetConfigWin32_H */

// }}}RME
