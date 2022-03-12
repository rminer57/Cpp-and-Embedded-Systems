// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::PowerConfiguration'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "PowerConfiguration.h"
#endif

#include <HALtestLib_win32.h>
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

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
PowerConfiguration::PowerConfiguration( const PowerConfiguration & rtg_arg )
	: m_attackTime( rtg_arg.m_attackTime )
	, m_trigger( rtg_arg.m_trigger )
	, m_powerUp( rtg_arg.m_powerUp )
	, m_powerEnvelope( rtg_arg.m_powerEnvelope )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
PowerConfiguration & PowerConfiguration::operator=( const PowerConfiguration & rtg_arg )
{
	if( this != &rtg_arg )
	{
		m_attackTime = rtg_arg.m_attackTime;
		m_trigger = rtg_arg.m_trigger;
		m_powerUp = rtg_arg.m_powerUp;
		m_powerEnvelope = rtg_arg.m_powerEnvelope;
	}
	return *this;
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
