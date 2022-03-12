// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::deployment_utilities::gpi::generalPurposeInputManager'

#ifndef generalPurposeInputManager_H
#define generalPurposeInputManager_H

#ifdef PRAGMA
#pragma interface "generalPurposeInputManager.h"
#endif

#include <HALtestLib_win32.h>
#include <rf_audio_std_types.h>
class generalPurposeInput;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class generalPurposeInputManager
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR
	friend class generalPurposeInput;
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
	// {{{RME classAttribute 'GPIs'
	generalPurposeInput * * GPIs;
	// }}}RME
	// {{{RME classAttribute 'numberGPIs'
	Integer numberGPIs;
	// }}}RME

public:
	// {{{RME operation 'generalPurposeInputManager(Integer)'
	generalPurposeInputManager( Integer numPorts );
	// }}}RME

protected:
	// {{{RME operation 'getGPI(Integer,Integer)'
	virtual Integer getGPI( Integer portNumber, Integer rfState ) = 0;
	// }}}RME

public:
	// {{{RME operation 'getInput(Integer)'
	generalPurposeInput * getInput( Integer num );
	// }}}RME

protected:
	// {{{RME operation 'updateGPI(Integer,Integer)'
	virtual void updateGPI( Integer portNumber, Integer rfState ) = 0;
	// }}}RME

public:
	// {{{RME operation '~generalPurposeInputManager()'
	~generalPurposeInputManager( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* generalPurposeInputManager_H */

// }}}RME
