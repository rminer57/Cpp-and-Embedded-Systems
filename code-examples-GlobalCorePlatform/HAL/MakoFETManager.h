// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoUSBSubsystem::FETmanager::MakoFETManager'

#ifndef MakoFETManager_H
#define MakoFETManager_H

#ifdef PRAGMA
#pragma interface "MakoFETManager.h"
#endif

#include <HALtestLib_win32.h>
#include <MakoUSBConstants.h>
class MakoUSBCtrl;
class Thread;
class TimeSpec;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>
// }}}USR
// }}}RME

class MakoFETManager
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

protected:
	// {{{RME classAttribute 'm_MakoUSBCtrlParent'
	MakoUSBCtrl * m_MakoUSBCtrlParent;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	MakoFETManager( void );
	// }}}RME
	// {{{RME operation 'MakoFETManager(MakoUSBCtrl *)'
	MakoFETManager( MakoUSBCtrl * parent );
	// }}}RME
	// {{{RME operation 'transceiverModeChange(int,int,int,int)'
	void transceiverModeChange( int oldUSB1state, int newUSB1state, int oldUSB2state, int newUSB2state );
	// }}}RME
	// {{{RME operation 'changeFETstate(int,int)'
	void changeFETstate( int newstate, int transceiver );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* MakoFETManager_H */

// }}}RME
