// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Configurable RF Deck::Options::ReceiveBandwidth'

#ifndef ReceiveBandwidth_H
#define ReceiveBandwidth_H

#ifdef PRAGMA
#pragma interface "ReceiveBandwidth.h"
#endif

#include <hal.h>
#include <ConfigurableRFVirtual.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class ReceiveBandwidth : public ConfigurableRFVirtual::RFVirtualOption
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

protected:
	// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
	// {{{USR
	SERIAL_CLASS_CONFIG();
	// }}}USR
	// }}}RME

private:
	// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

public:
	// {{{RME classAttribute 'RECEIVE_BANDWIDTH_OPTION'
	static const unsigned int RECEIVE_BANDWIDTH_OPTION;
	// }}}RME

private:
	// {{{RME classAttribute 'm_rxBandwidth'
	unsigned int m_rxBandwidth;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~ReceiveBandwidth( void );
	// }}}RME
	// {{{RME operation 'getType()'
	virtual ClassType getType( void ) const;
	// }}}RME
	// {{{RME operation 'isType(ClassType)'
	virtual bool isType( ClassType type ) const;
	// }}}RME
	// {{{RME operation 'getBandwidth()'
	unsigned int getBandwidth( void ) const;
	// }}}RME

protected:
	// {{{RME operation 'serialize(SerialObject*)'
	virtual void serialize( SerialObject * so );
	// }}}RME
	// {{{RME operation 'deserialize(SerialObject*)'
	virtual void deserialize( SerialObject * so );
	// }}}RME

public:
	// {{{RME operation 'ReceiveBandwidth(unsigned int)'
	ReceiveBandwidth( unsigned int rxBandwidth );
	// }}}RME
	// {{{RME operation 'ReceiveBandwidth(SerialObject*)'
	ReceiveBandwidth( SerialObject * so );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* ReceiveBandwidth_H */

// }}}RME
