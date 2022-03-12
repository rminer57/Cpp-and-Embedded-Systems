// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Configurable RF Deck::Options::ReceiveFrequency'

#ifndef ReceiveFrequency_H
#define ReceiveFrequency_H

#ifdef PRAGMA
#pragma interface "ReceiveFrequency.h"
#endif

#include <hal.h>
#include <ConfigurableRFVirtual.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class ReceiveFrequency : public ConfigurableRFVirtual::RFVirtualOption
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
	// {{{RME classAttribute 'RECEIVE_FREQUENCY_OPTION'
	static const unsigned int RECEIVE_FREQUENCY_OPTION;
	// }}}RME

private:
	// {{{RME classAttribute 'm_rxFrequency'
	unsigned long m_rxFrequency;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~ReceiveFrequency( void );
	// }}}RME
	// {{{RME operation 'getType()'
	virtual ClassType getType( void ) const;
	// }}}RME
	// {{{RME operation 'isType(ClassType)'
	virtual bool isType( ClassType type ) const;
	// }}}RME
	// {{{RME operation 'getFrequency()'
	unsigned long getFrequency( void ) const;
	// }}}RME

protected:
	// {{{RME operation 'serialize(SerialObject*)'
	virtual void serialize( SerialObject * so );
	// }}}RME
	// {{{RME operation 'deserialize(SerialObject*)'
	virtual void deserialize( SerialObject * so );
	// }}}RME

public:
	// {{{RME operation 'ReceiveFrequency(unsigned long)'
	ReceiveFrequency( unsigned long rxFrequency );
	// }}}RME
	// {{{RME operation 'ReceiveFrequency(SerialObject*)'
	ReceiveFrequency( SerialObject * so );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* ReceiveFrequency_H */

// }}}RME
