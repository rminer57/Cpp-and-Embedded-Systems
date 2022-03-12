// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Configurable RF Deck::Options::DesiredTxDevOption'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "DesiredTxDevOption.h"
#endif

#include <hal.h>
#include <DesiredTxDevOption.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'DESIRED_TX_DEV_OPTION'
const unsigned int DesiredTxDevOption::DESIRED_TX_DEV_OPTION = 6;
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
DesiredTxDevOption::~DesiredTxDevOption( void )
{
}
// }}}RME

// {{{RME operation 'getType()'
ClassType DesiredTxDevOption::getType( void ) const
{
	// {{{USR
	return DESIRED_TX_DEV_OPTION;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool DesiredTxDevOption::isType( ClassType type ) const
{
	// {{{USR
	return (type == DESIRED_TX_DEV_OPTION)?true:Option::isType(type);
	// }}}USR
}
// }}}RME

// {{{RME operation 'DesiredTxDevOption(unsigned int,unsigned int)'
DesiredTxDevOption::DesiredTxDevOption( unsigned int desiredTxDev, unsigned int nomInputLevel )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	:desiredTxDeviation(desiredTxDev),nominalInputLevel(nomInputLevel)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'serialize(SerialObject*)'
void DesiredTxDevOption::serialize( SerialObject * so )
{
	// {{{USR
	*so << desiredTxDeviation << nominalInputLevel;
	ConnectionOption::serialize(so);
	// }}}USR
}
// }}}RME

// {{{RME operation 'deserialize(SerialObject*)'
void DesiredTxDevOption::deserialize( SerialObject * so )
{
	// {{{USR
	*so >> desiredTxDeviation >> nominalInputLevel;
	ConnectionOption::deserialize(so);
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
