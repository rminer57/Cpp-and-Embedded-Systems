// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::trident::TridentPrivate::tridentSpiBuffer'

#ifndef tridentSpiBuffer_H
#define tridentSpiBuffer_H

#ifdef PRAGMA
#pragma interface "tridentSpiBuffer.h"
#endif

#include <rf_sequencer_comp.h>
#include <SIntArray.h>
#include <rfSpiBuffer.h>
class Connection;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'STORAGEUNITSIZEINBYTES'
#define STORAGEUNITSIZEINBYTES 4
// }}}RME

class tridentSpiBuffer : public rfSpiBuffer
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
	// {{{RME classAttribute 'm_allocatedNumOfStorageUnits'
	int m_allocatedNumOfStorageUnits;
	// }}}RME
	// {{{RME classAttribute 'm_bSkipFirst'
	bool m_bSkipFirst;
	// }}}RME
	// {{{RME classAttribute 'm_buffer'
	uint32_t * m_buffer;
	// }}}RME
	// {{{RME classAttribute 'm_doEndianSwap'
	bool m_doEndianSwap;
	// }}}RME
	// {{{RME classAttribute 'm_sizeBytes'
	unsigned int m_sizeBytes;
	// }}}RME
	// {{{RME classAttribute 'm_connection'
	Connection * m_connection;
	// }}}RME
	// {{{RME classAttribute 'm_bSkipLast'
	bool m_bSkipLast;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	tridentSpiBuffer( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~tridentSpiBuffer( void );
	// }}}RME
	// {{{RME operation 'sync()'
	virtual void sync( void );
	// }}}RME
	// {{{RME operation 'operator[](int)'
	virtual uint32_t & operator[]( int index );
	// }}}RME
	// {{{RME operation 'operator uint32_t *()'
	virtual operator uint32_t *( void );
	// }}}RME
	// {{{RME operation 'setEndianSwap(bool)'
	void setEndianSwap( bool value );
	// }}}RME
	// {{{RME operation 'endianSwap(Array **)'
	void endianSwap( Array * * buf );
	// }}}RME
	// {{{RME operation 'tridentSpiBuffer(unsigned int,Connection *,bool,bool)'
	tridentSpiBuffer( unsigned int bufferSizeInBytes, Connection * conn, bool skipFirst = false, bool skipLast = false );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* tridentSpiBuffer_H */

// }}}RME
