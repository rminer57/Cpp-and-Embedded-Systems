// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::PowerConfiguration'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "PowerConfiguration.h"
#endif

#include <rf_sequencer_comp.h>
#include <PowerConfiguration.h>
#include <Mako.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
PowerConfiguration::PowerConfiguration( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
PowerConfiguration::~PowerConfiguration( void )
{
}
// }}}RME

// {{{RME operation 'getAttackTime()'
unsigned char PowerConfiguration::getAttackTime( void ) const
{
	// {{{USR
	return m_attackTime;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getPowerState()'
bool PowerConfiguration::getPowerState( void ) const
{
	// {{{USR
	return m_powerUp;     // true, if powered-up.
	// }}}USR
}
// }}}RME

// {{{RME operation 'getTrigger()'
bool PowerConfiguration::getTrigger( void ) const
{
	// {{{USR
	return m_trigger;           // true, to ramp-up the RF PA.
	// }}}USR
}
// }}}RME

// {{{RME operation 'getPowerEnvelope()'
uint16_t * PowerConfiguration::getPowerEnvelope( void ) const
{
	// {{{USR
	return m_powerEnvelope;
	// }}}USR
}
// }}}RME

// {{{RME operation 'PowerConfiguration(uint16_t *,unsigned int,bool,bool)'
PowerConfiguration::PowerConfiguration( uint16_t * powerEnvelope, unsigned int attackTime, bool trigger, bool powerUp )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_powerEnvelope(powerEnvelope), m_attackTime(attackTime), m_trigger(trigger), m_powerUp(powerUp)
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
