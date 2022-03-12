// {{{RME classifier 'Logical View::HAL Instantiation::Timers::OMAP::OMAP_PWL'

#ifndef OMAP_PWL_H
#define OMAP_PWL_H

#ifdef PRAGMA
#pragma interface "OMAP_PWL.h"
#endif

#include <timer_comp.h>
#include <LED_CONTROL.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

#define volatile_read_UINT8(addr)        (*((volatile unsigned char*)((uint32_t)(addr))))
#define volatile_read_UINT16(addr)       (*((volatile uint16_t*)((uint32_t)(addr))))
#define volatile_read_UINT32(xaddr)      (*((volatile uint32_t*)((uint32_t)(addr))))
#define volatile_write_UINT8(addr,data)  (*((volatile unsigned char*)((uint32_t)(addr))))  =  (unsigned char)(data)
#define volatile_write_UINT16(addr,data) (*((volatile uint16_t*)((uint32_t)(addr)))) = (uint16_t)(data)
#define volatile_write_UINT32(addr,data) (*((volatile uint32_t*)((uint32_t)(addr)))) = (uint32_t)(data)

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

#define MOD_CONF_CTRL_1_OFFSET   0x110
#define OMAP_CONFIG_REG_BASE     (uint32_t*)0xFFFE1000
#define FUNC_MUX_CTRL_0_OFFSET	 0x00

// }}}USR
// }}}RME

class OMAP_PWL : public LED_CONTROL
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
	// {{{RME classAttribute 'm_pwl_base_address'
	uint32_t m_pwl_base_address;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~OMAP_PWL( void );
	// }}}RME
	// {{{RME operation 'setIntensity(uint16_t)'
	bool setIntensity( uint16_t percentIntensity );
	// }}}RME
	// {{{RME operation 'OMAP_PWL(uint32_t)'
	OMAP_PWL( uint32_t baseAddress = 0xFFFB5800 );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* OMAP_PWL_H */

// }}}RME
