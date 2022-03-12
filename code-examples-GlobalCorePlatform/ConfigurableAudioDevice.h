// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Audio Inputs & Outputs::ConfigurableAudioDevice'

#ifndef ConfigurableAudioDevice_H
#define ConfigurableAudioDevice_H

#ifdef PRAGMA
#pragma interface "ConfigurableAudioDevice.h"
#endif

#include <hal.h>
#include <Configurable.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class ConfigurableAudioDevice : public Configurable
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
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~ConfigurableAudioDevice( void );
	// }}}RME
	// {{{RME operation 'enable()'
	virtual void enable( void ) = 0;
	// }}}RME
	// {{{RME operation 'disable()'
	virtual void disable( void ) = 0;
	// }}}RME
	// {{{RME operation 'setLevel(int)'
	virtual int setLevel( int level ) = 0;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* ConfigurableAudioDevice_H */

// }}}RME
