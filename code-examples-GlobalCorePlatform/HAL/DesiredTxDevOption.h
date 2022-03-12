// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Configurable RF Deck::Options::DesiredTxDevOption'

#ifndef DesiredTxDevOption_H
#define DesiredTxDevOption_H

#ifdef PRAGMA
#pragma interface "DesiredTxDevOption.h"
#endif

#include <hal.h>
#include <Connection.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class DesiredTxDevOption : public Connection::ConnectionOption
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
	// {{{RME classAttribute 'DESIRED_TX_DEV_OPTION'
	static const unsigned int DESIRED_TX_DEV_OPTION;
	// }}}RME
	// {{{RME classAttribute 'desiredTxDeviation'
	unsigned int desiredTxDeviation;
	// }}}RME
	// {{{RME classAttribute 'nominalInputLevel'
	unsigned int nominalInputLevel;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~DesiredTxDevOption( void );
	// }}}RME
	// {{{RME operation 'getType()'
	virtual ClassType getType( void ) const;
	// }}}RME
	// {{{RME operation 'isType(ClassType)'
	virtual bool isType( ClassType type ) const;
	// }}}RME
	// {{{RME operation 'DesiredTxDevOption(unsigned int,unsigned int)'
	DesiredTxDevOption( unsigned int desiredTxDev, unsigned int nomInputLevel );
	// }}}RME

protected:
	// {{{RME operation 'serialize(SerialObject*)'
	virtual void serialize( SerialObject * so );
	// }}}RME
	// {{{RME operation 'deserialize(SerialObject*)'
	virtual void deserialize( SerialObject * so );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* DesiredTxDevOption_H */

// }}}RME
