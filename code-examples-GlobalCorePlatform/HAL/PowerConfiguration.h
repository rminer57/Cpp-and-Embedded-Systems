// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::PowerConfiguration'

#ifndef PowerConfiguration_H
#define PowerConfiguration_H

#ifdef PRAGMA
#pragma interface "PowerConfiguration.h"
#endif

#include <HALtestLib_win32.h>
#include <MakoPrivate.h>
class Mako;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>
// }}}USR
// }}}RME

class PowerConfiguration
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
	// {{{RME classAttribute 'm_attackTime'
	unsigned char m_attackTime;
	// }}}RME
	// {{{RME classAttribute 'm_trigger'
	bool m_trigger;
	// }}}RME
	// {{{RME classAttribute 'm_powerUp'
	bool m_powerUp;
	// }}}RME
	// {{{RME classAttribute 'm_powerEnvelope'
	uint16_t * m_powerEnvelope;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	PowerConfiguration( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~PowerConfiguration( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	PowerConfiguration( const PowerConfiguration & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	PowerConfiguration & operator=( const PowerConfiguration & rtg_arg );
	// }}}RME
	// {{{RME operation 'getAttackTime()'
	virtual unsigned char getAttackTime( void ) const;
	// }}}RME
	// {{{RME operation 'getPowerState()'
	virtual bool getPowerState( void ) const;
	// }}}RME
	// {{{RME operation 'getTrigger()'
	virtual bool getTrigger( void ) const;
	// }}}RME
	// {{{RME operation 'getPowerEnvelope()'
	virtual uint16_t * getPowerEnvelope( void ) const;
	// }}}RME
	// {{{RME operation 'PowerConfiguration(uint16_t *,unsigned int,bool,bool)'
	PowerConfiguration( uint16_t * powerEnvelope, unsigned int attackTime, bool trigger, bool powerUp );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* PowerConfiguration_H */

// }}}RME
