// {{{RME classifier 'Logical View::HAL Instantiation::Timers::PWM::PWM'

#ifndef PWM_H
#define PWM_H

#ifdef PRAGMA
#pragma interface "PWM.h"
#endif

#include <timer_comp.h>
#include <StdTypes.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class PWM
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
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	PWM( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~PWM( void );
	// }}}RME
	// {{{RME operation 'setPWM(uint32_t,uint32_t)'
	virtual bool setPWM( uint32_t period_ns, uint32_t pulseDuration_ns ) = 0;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* PWM_H */

// }}}RME
