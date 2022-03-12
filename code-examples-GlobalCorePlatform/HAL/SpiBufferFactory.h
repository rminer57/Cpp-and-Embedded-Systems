// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::trident::TridentPrivate::SpiBufferFactory'

#ifndef SpiBufferFactory_H
#define SpiBufferFactory_H

#ifdef PRAGMA
#pragma interface "SpiBufferFactory.h"
#endif

#include <rf_sequencer_comp.h>
#include <SpiBuffer.h>
#include <rfSpiManager.h>
class Connection;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class SpiBufferFactory : public rfSpiManager
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
	virtual ~SpiBufferFactory( void );
	// }}}RME
	// {{{RME operation 'getSpiBuffers(unsigned int,unsigned int,Connection *,bool,bool)'
	static rfSpiBuffer * * getSpiBuffers( unsigned int numOfBuffers, unsigned int sizeOfEachBufferInBytes, Connection * conn, bool skipFirst = false, bool skipLast = false );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* SpiBufferFactory_H */

// }}}RME
