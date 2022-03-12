// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoUSBSubsystem::USBIOVirtualHandler'

#ifndef USBIOVirtualHandler_H
#define USBIOVirtualHandler_H

#ifdef PRAGMA
#pragma interface "USBIOVirtualHandler.h"
#endif

#include <HALtestLib_win32.h>
#include <IOVirtual.h>
#include <MakoUSBConstants.h>
class MakoUSBCtrl;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class USBIOVirtualHandler : public IOVirtual
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
	// {{{RME classAttribute 'm_whichIOVirtual'
	int m_whichIOVirtual;
	// }}}RME
	// {{{RME classAttribute 'm_whichTransceiver'
	int m_whichTransceiver;
	// }}}RME
	// {{{RME classAttribute 'm_MakoUSBCtrl_parent'
	MakoUSBCtrl * m_MakoUSBCtrl_parent;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	USBIOVirtualHandler( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~USBIOVirtualHandler( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	USBIOVirtualHandler( const USBIOVirtualHandler & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	USBIOVirtualHandler & operator=( const USBIOVirtualHandler & rtg_arg );
	// }}}RME
	// {{{RME operation 'USBIOVirtualHandler(int,int,MakoUSBCtrl *)'
	USBIOVirtualHandler( int type, int transceiver, MakoUSBCtrl * parent );
	// }}}RME
	// {{{RME operation 'receive()'
	unsigned int receive( void );
	// }}}RME
	// {{{RME operation 'send(unsigned int)'
	void send( unsigned int data );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* USBIOVirtualHandler_H */

// }}}RME
