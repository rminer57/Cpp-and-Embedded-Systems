// {{{RME classifier 'Logical View::HAL Instantiation::Timers::OMAP::OMAP_PWL'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "OMAP_PWL.h"
#endif

#include <timer_comp.h>
#include <OMAP_PWL.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
#define PWL_BASE_REG             0xFFFB5800
#define PWL_LEVEL_OFFSET         0x00
#define PWL_CLK_ENABLE_OFFSET    0x04
#define PWL_CLOCK_DISABLE        0x00
#define PWL_CLOCK_ENABLE         0x01

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
OMAP_PWL::~OMAP_PWL( void )
{
}
// }}}RME

// {{{RME operation 'setIntensity(uint16_t)'
bool OMAP_PWL::setIntensity( uint16_t percentIntensity )
{
	// {{{USR

	bool return_val;

	// 		PWL


	// 
	// percentIntensity is [0,100] percent and is approximate.
	//
	// 100% will not provide a constant "on" signal, but will be a pseudo-random
	// waveform that is "high" over 99% of the time.
	//
	// return success or failure.
	//


	if (percentIntensity == 0)
		{
		volatile_write_UINT8(PWL_BASE_REG + PWL_LEVEL_OFFSET,0x00); 	                // SET PWL LEVEL to zero
		volatile_write_UINT8(PWL_BASE_REG + PWL_CLK_ENABLE_OFFSET,PWL_CLOCK_DISABLE);   // DISABLE PWL CLOCK

		return_val = true;
		}


	else if ((percentIntensity > 0 ) && (percentIntensity <= 100))
		{
		volatile_write_UINT8(PWL_BASE_REG + PWL_LEVEL_OFFSET,(unsigned char)(percentIntensity * 10 / 4));  // SET PWL LEVEL
		volatile_write_UINT8(PWL_BASE_REG + PWL_CLK_ENABLE_OFFSET,PWL_CLOCK_ENABLE); 	           // ENABLE PWL CLOCK

		return_val = true;
		}

	else
		{
		return_val = false;
		}


	return return_val;

	// }}}USR
}
// }}}RME

// {{{RME operation 'OMAP_PWL(uint32_t)'
OMAP_PWL::OMAP_PWL( uint32_t baseAddress )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_pwl_base_address(baseAddress)

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
