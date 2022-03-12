// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Configurable RF Deck::Options::TxPowerOption'

#ifndef TxPowerOption_H
#define TxPowerOption_H

#ifdef PRAGMA
#pragma interface "TxPowerOption.h"
#endif

#include <hal.h>
#include <ConfigurableRFVirtual.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class TxPowerOption : public ConfigurableRFVirtual::RFVirtualOption
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
	// {{{RME classAttribute 'RF_POWER_OPTION'
	static const unsigned int RF_POWER_OPTION;
	// }}}RME

private:
	// {{{RME classAttribute 'm_rfPower'
	unsigned int m_rfPower;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~TxPowerOption( void );
	// }}}RME
	// {{{RME operation 'getType()'
	virtual ClassType getType( void ) const;
	// }}}RME
	// {{{RME operation 'isType(ClassType)'
	virtual bool isType( ClassType type ) const;
	// }}}RME
	// {{{RME operation 'getPower()'
	unsigned int getPower( void ) const;
	// }}}RME

protected:
	// {{{RME operation 'serialize(SerialObject*)'
	virtual void serialize( SerialObject * so );
	// }}}RME
	// {{{RME operation 'deserialize(SerialObject*)'
	virtual void deserialize( SerialObject * so );
	// }}}RME

public:
	// {{{RME operation 'TxPowerOption(unsigned int)'
	TxPowerOption( unsigned int power );
	// }}}RME
	// {{{RME operation 'TxPowerOption(SerialObject*)'
	TxPowerOption( SerialObject * so );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* TxPowerOption_H */

// }}}RME
