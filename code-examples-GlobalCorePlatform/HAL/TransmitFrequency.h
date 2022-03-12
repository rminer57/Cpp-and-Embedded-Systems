// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Configurable RF Deck::Options::TransmitFrequency'

#ifndef TransmitFrequency_H
#define TransmitFrequency_H

#ifdef PRAGMA
#pragma interface "TransmitFrequency.h"
#endif

#include <hal.h>
#include <ConfigurableRFVirtual.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class TransmitFrequency : public ConfigurableRFVirtual::RFVirtualOption
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
	// {{{RME classAttribute 'TRANSMIT_FREQUENCY_OPTION'
	static const unsigned int TRANSMIT_FREQUENCY_OPTION;
	// }}}RME

private:
	// {{{RME classAttribute 'm_txFrequency'
	unsigned long m_txFrequency;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~TransmitFrequency( void );
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
	// {{{RME operation 'TransmitFrequency(unsigned long)'
	TransmitFrequency( unsigned long txFrequency );
	// }}}RME
	// {{{RME operation 'TransmitFrequency(SerialObject*)'
	TransmitFrequency( SerialObject * so );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* TransmitFrequency_H */

// }}}RME
