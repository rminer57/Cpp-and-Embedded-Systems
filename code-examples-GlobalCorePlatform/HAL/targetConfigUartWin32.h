// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::targetConfigObjects::configWin32::targetConfigUartWin32'

#ifndef targetConfigUartWin32_H
#define targetConfigUartWin32_H

#ifdef PRAGMA
#pragma interface "targetConfigUartWin32.h"
#endif

#include <HALtestLib_win32.h>
#include <IOVirtualSerial.h>
#include <IOVirtualSerialCom.h>
#include <IOVirtualSerialSimulationStderr.h>
#include <ListenerBase.h>
#include <RXThresholdEvent.h>
#include <targetConfigBase.h>
class Mako;
class abacusIII;
class fractionalN;
class targetConfigAbacus;
class targetConfigLvFracN;
class targetConfigMako;
class targetConfigPGAM;
class targetConfigTomahawk;
class tomahawk;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class targetConfigUartWin32 : public targetConfigBase, public ListenerBase
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
	static IOVirtualSerial * m_uart;
	// }}}RME
	// {{{RME classAttribute 'm_uartcfg'
	UartConfig * m_uartcfg;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	targetConfigUartWin32( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~targetConfigUartWin32( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	targetConfigUartWin32( const targetConfigUartWin32 & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	targetConfigUartWin32 & operator=( const targetConfigUartWin32 & rtg_arg );
	// }}}RME
	// {{{RME operation 'init()'
	void init( void );
	// }}}RME
	// {{{RME operation 'receiveFromUart(unsigned char *,int,int)'
	int receiveFromUart( unsigned char * buffer, int numCharsToGet, int whichUart );
	// }}}RME
	// {{{RME operation 'init(unsigned int)'
	void init( unsigned int whichUart );
	// }}}RME
	// {{{RME operation 'targetConfigUartWin32(unsigned int)'
	targetConfigUartWin32( unsigned int whichUart );
	// }}}RME
	// {{{RME operation 'getIOVirtualSerial()'
	IOVirtualSerial * getIOVirtualSerial( void );
	// }}}RME
	// {{{RME operation 'eventOccurred(const EventBase * const)'
	void eventOccurred( const EventBase * const event );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* targetConfigUartWin32_H */

// }}}RME
