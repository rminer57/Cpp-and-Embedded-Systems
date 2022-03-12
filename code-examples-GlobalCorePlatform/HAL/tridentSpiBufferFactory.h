// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::trident::TridentPrivate::tridentSpiBufferFactory'

#ifndef tridentSpiBufferFactory_H
#define tridentSpiBufferFactory_H

#ifdef PRAGMA
#pragma interface "tridentSpiBufferFactory.h"
#endif

#include <rf_sequencer_comp.h>
#include <rfSpiManager.h>
#include <tridentSpiBuffer.h>
class Connection;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class tridentSpiBufferFactory : public rfSpiManager
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
	virtual ~tridentSpiBufferFactory( void );
	// }}}RME
	// {{{RME operation 'getSpiBuffers(unsigned int,unsigned int,Connection *,bool,bool)'
	static rfSpiBuffer * * getSpiBuffers( unsigned int numOfBuffers, unsigned int sizeOfEachBufferInBytes, Connection * conn, bool skipFirst = false, bool skipLast = false );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* tridentSpiBufferFactory_H */

// }}}RME
