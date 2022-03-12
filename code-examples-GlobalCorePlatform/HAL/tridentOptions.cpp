// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::trident::tridentOptions::tridentOptions'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "tridentOptions.h"
#endif

#include <rf_sequencer_comp.h>
#include <tridentOptions.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'TRIDENT_OPTION'
unsigned int tridentOptions::TRIDENT_OPTION( 4499 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
tridentOptions::tridentOptions( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
tridentOptions::~tridentOptions( void )
{
}
// }}}RME

// {{{RME operation 'getType()'
ClassType tridentOptions::getType( void ) const
{
	// {{{USR
	return TRIDENT_OPTION;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool tridentOptions::isType( ClassType type )
{
	// {{{USR
	return (type == TRIDENT_OPTION)?true:Option::isType(type);
	// }}}USR
}
// }}}RME

// {{{RME operation 'tridentOptions(unsigned int,unsigned int,unsigned int)'
tridentOptions::tridentOptions( unsigned int setting, unsigned int registerID, unsigned int rfState )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_setting(setting), m_registerID(registerID), m_rfState(rfState)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
