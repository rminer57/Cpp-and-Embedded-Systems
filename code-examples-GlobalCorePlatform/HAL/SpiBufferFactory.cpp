// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::trident::TridentPrivate::SpiBufferFactory'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "SpiBufferFactory.h"
#endif

#include <rf_sequencer_comp.h>
#include <SpiBufferFactory.h>
#include <Connection.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
SpiBufferFactory::~SpiBufferFactory( void )
{
}
// }}}RME

// {{{RME operation 'getSpiBuffers(unsigned int,unsigned int,Connection *,bool,bool)'
rfSpiBuffer * * SpiBufferFactory::getSpiBuffers( unsigned int numOfBuffers, unsigned int sizeOfEachBufferInBytes, Connection * conn, bool skipFirst, bool skipLast )
{
	// {{{USR
		// allocate memory for an array of buffers. rfSpiBuffer is the parent class.
		rfSpiBuffer ** ret = new rfSpiBuffer * [numOfBuffers + 1];	

		//allocate a buffer of the given size, for each array element
		for ( unsigned int i = 0; i < numOfBuffers; i++)
		{
		    ret[i] = new SpiBuffer(sizeOfEachBufferInBytes, conn, skipFirst, skipLast);
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
