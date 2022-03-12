// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::deployment_utilities::gpo::generalPurposeOutput'

#ifndef generalPurposeOutput_H
#define generalPurposeOutput_H

#ifdef PRAGMA
#pragma interface "generalPurposeOutput.h"
#endif

#include <HALtestLib_win32.h>
#include <rf_audio_std_types.h>
class generalPurposeOutputManager;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class generalPurposeOutput
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR
	friend class generalPurposeOutputManager;
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
	// {{{RME classAttribute 'outputManager'
	generalPurposeOutputManager * outputManager;
	// }}}RME
	// {{{RME classAttribute 'portNumber'
	Integer portNumber;
	// }}}RME

public:
	// {{{RME operation 'commit(Integer)'
	void commit( Integer rfState );
	// }}}RME

protected:
	// {{{RME operation 'generalPurposeOutput(Integer,generalPurposeOutputManager*)'
	generalPurposeOutput( Integer port, generalPurposeOutputManager * managerPtr );
	// }}}RME

public:
	// {{{RME operation 'set(Integer,Integer)'
	void set( Integer outputState, Integer rfState );
	// }}}RME
	// {{{RME operation '~generalPurposeOutput()'
	~generalPurposeOutput( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* generalPurposeOutput_H */

// }}}RME
