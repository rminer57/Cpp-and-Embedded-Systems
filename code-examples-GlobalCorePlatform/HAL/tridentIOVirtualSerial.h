// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::Trident::TridentPrivate::TridentIOVirtualSerial'

#ifndef TridentIOVirtualSerial_H
#define TridentIOVirtualSerial_H

#ifdef PRAGMA
#pragma interface "TridentIOVirtualSerial.h"
#endif

#include <rf_sequencer_comp.h>
#include <IOVirtualSerial.h>
class SIntArray;
class Trident;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'TRIDENT_SPIAUX1_HEADER4WIRE'
#define TRIDENT_SPIAUX1_HEADER4WIRE 0x60
// }}}RME

// {{{RME classAttribute 'TRIDENT_SPIAUX2_HEADER4WIRE'
#define TRIDENT_SPIAUX2_HEADER4WIRE 0x70
// }}}RME

// {{{RME classAttribute 'TRIDENT_SPIAUX_NON4WIREADDROFFSET'
#define TRIDENT_SPIAUX_NON4WIREADDROFFSET 0x08
// }}}RME

class TridentIOVirtualSerial : public IOVirtualSerial
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
	// {{{RME classAttribute 'm_headerAddress'
	int16_t m_headerAddress;
	// }}}RME
	// {{{RME classAttribute 'm_auxSpiBufferSizeNormal'
	bool m_auxSpiBufferSizeNormal;
	// }}}RME
	// {{{RME classAttribute 'm_spiMode4wire'
	bool m_spiMode4wire;
	// }}}RME

public:
	// {{{RME associationEnd 'm_tridentParent'
	Trident * m_tridentParent;
	// }}}RME
	// {{{RME operation 'activate()'
	virtual bool activate( void );
	// }}}RME
	// {{{RME operation 'deactivate()'
	virtual bool deactivate( void );
	// }}}RME
	// {{{RME operation 'getStatus()'
	virtual Connection::Status * getStatus( void );
	// }}}RME
	// {{{RME operation 'receive()'
	virtual Array * receive( void );
	// }}}RME
	// {{{RME operation 'send(Array *)'
	virtual bool send( Array * buf );
	// }}}RME
	// {{{RME operation 'TridentIOVirtualSerial(int,Trident *,bool,bool)'
	TridentIOVirtualSerial( int whichIOVirtualSerial, Trident * tridentParent, bool auxSpiBufferSizeNormal = true, bool spiMode4wire = true );
	// }}}RME
	// {{{RME operation '~TridentIOVirtualSerial()'
	virtual ~TridentIOVirtualSerial( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* TridentIOVirtualSerial_H */

// }}}RME
