// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::trident::TridentPrivate::tridentSpiBufferFactory'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "tridentSpiBufferFactory.h"
#endif

#include <rf_sequencer_comp.h>
#include <tridentSpiBufferFactory.h>
#include <Connection.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
tridentSpiBufferFactory::~tridentSpiBufferFactory( void )
{
}
// }}}RME

// {{{RME operation 'getSpiBuffers(unsigned int,unsigned int,Connection *,bool,bool)'
rfSpiBuffer * * tridentSpiBufferFactory::getSpiBuffers( unsigned int numOfBuffers, unsigned int sizeOfEachBufferInBytes, Connection * conn, bool skipFirst, bool skipLast )
{
	// {{{USR
		// allocate memory for an array of buffers. rfSpiBuffer is the parent class.
		rfSpiBuffer ** ret = new rfSpiBuffer * [numOfBuffers + 1];	

		//allocate a buffer of the given size, for each array element
		for ( unsigned int i = 0; i < numOfBuffers; i++)
		{
		    ret[i] = new tridentSpiBuffer(sizeOfEachBufferInBytes, conn, skipFirst, skipLast);
		}

		return ret;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
