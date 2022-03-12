// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::deployment_utilities::gpo::generalPurposeOutputManager'

#ifndef generalPurposeOutputManager_H
#define generalPurposeOutputManager_H

#ifdef PRAGMA
#pragma interface "generalPurposeOutputManager.h"
#endif

#include <rf_sequencer_comp.h>
#include <rf_audio_std_types.h>
class generalPurposeOutput;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>
// }}}USR
// }}}RME

class generalPurposeOutputManager
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR
	friend class generalPurposeOutput;
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
	// {{{RME classAttribute 'GPOs'
	generalPurposeOutput * * GPOs;
	// }}}RME
	// {{{RME classAttribute 'numberGPOs'
	Integer numberGPOs;
	// }}}RME

protected:
	// {{{RME operation 'commitGPO(Integer,Integer)'
	virtual void commitGPO( Integer portNumber, Integer rfState ) = 0;
	// }}}RME

public:
	// {{{RME operation 'generalPurposeOutputManager(Integer)'
	generalPurposeOutputManager( Integer numPorts );
	// }}}RME
	// {{{RME operation 'getOutput(Integer)'
	generalPurposeOutput * getOutput( Integer num );
	// }}}RME

protected:
	// {{{RME operation 'setGPO(int16_t,int16_t,int16_t)'
	virtual void setGPO( int16_t portNumber, int16_t outputState, int16_t rfState ) = 0;
	// }}}RME

public:
	// {{{RME operation '~generalPurposeOutputManager()'
	~generalPurposeOutputManager( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* generalPurposeOutputManager_H */

// }}}RME
