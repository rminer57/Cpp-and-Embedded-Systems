// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Configurable RF Deck::Options::TransmitDeviation'

#ifndef TransmitDeviation_H
#define TransmitDeviation_H

#ifdef PRAGMA
#pragma interface "TransmitDeviation.h"
#endif

#include <hal.h>
#include <ConfigurableRFVirtual.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class TransmitDeviation : public ConfigurableRFVirtual::RFVirtualOption
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
	// {{{RME classAttribute 'TRANSMIT_DEVIATION_OPTION'
	static const unsigned int TRANSMIT_DEVIATION_OPTION;
	// }}}RME

private:
	// {{{RME classAttribute 'm_txDeviation'
	unsigned int m_txDeviation;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~TransmitDeviation( void );
	// }}}RME
	// {{{RME operation 'getType()'
	virtual ClassType getType( void ) const;
	// }}}RME
	// {{{RME operation 'isType(ClassType)'
	virtual bool isType( ClassType type ) const;
	// }}}RME
	// {{{RME operation 'getDeviation()'
	unsigned int getDeviation( void ) const;
	// }}}RME

protected:
	// {{{RME operation 'serialize(SerialObject*)'
	virtual void serialize( SerialObject * so );
	// }}}RME
	// {{{RME operation 'deserialize(SerialObject*)'
	virtual void deserialize( SerialObject * so );
	// }}}RME

public:
	// {{{RME operation 'TransmitDeviation(unsigned int)'
	TransmitDeviation( unsigned int txDeviation );
	// }}}RME
	// {{{RME operation 'TransmitDeviation(SerialObject*)'
	TransmitDeviation( SerialObject * so );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* TransmitDeviation_H */

// }}}RME
