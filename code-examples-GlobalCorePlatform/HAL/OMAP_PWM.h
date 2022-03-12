// {{{RME classifier 'Logical View::HAL Instantiation::Timers::OMAP::OMAP_PWM'

#ifndef OMAP_PWM_H
#define OMAP_PWM_H

#ifdef PRAGMA
#pragma interface "OMAP_PWM.h"
#endif

#include <timer_comp.h>
#include <LED_CONTROL.h>
#include <PWM.h>
class bitfield;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

#define MOD_CONF_CTRL_1_OFFSET   0x110 
#define OMAP_CONFIG_REG_BASE     (uint32_t*)0xFFFE1000
#define FUNC_MUX_CTRL_0_OFFSET	 0x00

#define DMT_TIDR_OFFSET    0x00
#define DMT_TIOCP_OFFSET   0x10
#define DMT_TISTAT_OFFSET  0x14
#define DMT_TIER_OFFSET    0x1C
#define DMT_TCLR_OFFSET    0x24
#define DMT_TCRR_OFFSET    0x28
#define DMT_TLDR_OFFSET    0x2C
#define DMT_TMAR_OFFSET    0x38

#define DMT_REG_BASE       (uint32_t*)0xFFFB1400
#define DMT_TIDR_OFFSET    0x00
#define DMT_TIOCP_OFFSET   0x10
#define DMT_TISTAT_OFFSET  0x14
#define DMT_TIER_OFFSET    0x1C
#define DMT_TCLR_OFFSET    0x24
#define DMT_TCRR_OFFSET    0x28
#define DMT_TLDR_OFFSET    0x2C
#define DMT_TMAR_OFFSET    0x38
#define DMT_TWPS_OFFSET  0x34


// }}}USR
// }}}RME

class OMAP_PWM : public LED_CONTROL, public PWM
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
	// {{{RME classAttribute 'm_base_address'
	volatile uint32_t m_base_address;
	// }}}RME
	// {{{RME classAttribute 'm_led_period'
	uint32_t m_led_period;
	// }}}RME

public:
	// {{{RME classAttribute 'PWM1_BASE_ADDR'
	static const uint32_t PWM1_BASE_ADDR;
	// }}}RME
	// {{{RME classAttribute 'PWM2_BASE_ADDR'
	static const uint32_t PWM2_BASE_ADDR;
	// }}}RME
	// {{{RME classAttribute 'PWM0_BASE_ADDR'
	static const uint32_t PWM0_BASE_ADDR;
	// }}}RME
	// {{{RME classAttribute 'DEFAULT_LED_PERIOD'
	static const uint32_t DEFAULT_LED_PERIOD;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~OMAP_PWM( void );
	// }}}RME
	// {{{RME operation 'OMAP_PWM(uint32_t,uint32_t)'
	OMAP_PWM( uint32_t baseAddress, uint32_t ledPeriod );
	// }}}RME
	// {{{RME operation 'setIntensity(uint16_t)'
	virtual bool setIntensity( uint16_t percentIntensity );
	// }}}RME
	// {{{RME operation 'setPWM(uint32_t,uint32_t)'
	virtual bool setPWM( uint32_t period_ns, uint32_t pulseDuration_ns );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* OMAP_PWM_H */

// }}}RME
