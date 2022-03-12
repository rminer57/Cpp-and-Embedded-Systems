// {{{RME classifier 'Logical View::HAL Instantiation::Timers::OMAP::OMAP_PWM'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "OMAP_PWM.h"
#endif

#include <timer_comp.h>
#include <OMAP_PWM.h>
#include <bitfield.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
// PWM Bitfields
//
// defineBitField(name,type,offset,start,len)
//
defineBitField(DMT_GPTIMER4_CLK_SEL_R,uint32_t,MOD_CONF_CTRL_1_OFFSET,4,2);  // clock select
defineBitField(DMT_EMUFREE,uint32_t,DMT_TIOCP_OFFSET,5,1);  // timer operation during emulation mode

defineBitField(DMT_ST,uint32_t,DMT_TCLR_OFFSET,0,1);    // start timer bit
defineBitField(DMT_AR,uint32_t,DMT_TCLR_OFFSET,1,1);    // Autoreload mode
defineBitField(DMT_PTV,uint32_t,DMT_TCLR_OFFSET,2,3);   // prescaler timer value
defineBitField(DMT_PRE,uint32_t,DMT_TCLR_OFFSET,5,1);   // prescaler enable
defineBitField(DMT_CE,uint32_t,DMT_TCLR_OFFSET,6,1);    // compare mode enable
defineBitField(DMT_SCPWM,uint32_t,DMT_TCLR_OFFSET,7,1); 
defineBitField(DMT_TCM,uint32_t,DMT_TCLR_OFFSET,8,2);   // capture mode
defineBitField(DMT_TRG,uint32_t,DMT_TCLR_OFFSET,10,2);  // trigger output mode
defineBitField(DMT_PT,uint32_t,DMT_TCLR_OFFSET,12,1);   // select pulse or toggle

// test these bit before writing to appropriate register when timer is in posted mode!!!
defineBitField(DMT_W_PEND_TCLR,uint32_t,DMT_TWPS_OFFSET,0,1);      
defineBitField(DMT_W_PEND_TCRR,uint32_t,DMT_TWPS_OFFSET,1,1);      
defineBitField(DMT_W_PEND_TLDR,uint32_t,DMT_TWPS_OFFSET,2,1);      
defineBitField(DMT_W_PEND_TTGR,uint32_t,DMT_TWPS_OFFSET,3,1);      
defineBitField(DMT_W_PEND_TMAR,uint32_t,DMT_TWPS_OFFSET,4,1);      

defineBitField(CONF_MOD_GPTIMER1_CLK_SEL_R,uint32_t,MOD_CONF_CTRL_1_OFFSET,0,2);      
defineBitField(CONF_MOD_GPTIMER2_CLK_SEL_R,uint32_t,MOD_CONF_CTRL_1_OFFSET,2,2);      
defineBitField(CONF_MOD_GPTIMER3_CLK_SEL_R,uint32_t,MOD_CONF_CTRL_1_OFFSET,4,2);      
defineBitField(CONF_MOD_GPTIMER4_CLK_SEL_R,uint32_t,MOD_CONF_CTRL_1_OFFSET,6,2);      


// }}}USR
// }}}RME

// {{{RME classAttribute 'PWM1_BASE_ADDR'
const uint32_t OMAP_PWM::PWM1_BASE_ADDR( 0xFFFB1C00 );
// }}}RME

// {{{RME classAttribute 'PWM2_BASE_ADDR'
const uint32_t OMAP_PWM::PWM2_BASE_ADDR( 0xFFFB2400 );
// }}}RME

// {{{RME classAttribute 'PWM0_BASE_ADDR'
const uint32_t OMAP_PWM::PWM0_BASE_ADDR( 0xFFFB1400 );
// }}}RME

// {{{RME classAttribute 'DEFAULT_LED_PERIOD'
const uint32_t OMAP_PWM::DEFAULT_LED_PERIOD( 3571430 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
OMAP_PWM::~OMAP_PWM( void )
{
}
// }}}RME

// {{{RME operation 'OMAP_PWM(uint32_t,uint32_t)'
OMAP_PWM::OMAP_PWM( uint32_t baseAddress, uint32_t ledPeriod )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_base_address(baseAddress), m_led_period(ledPeriod)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// Force TCLR to reset state.

	volatile_write_UINT32(m_base_address + DMT_TCLR_OFFSET,0x0000);  




	// }}}USR
}
// }}}RME

// {{{RME operation 'setIntensity(uint16_t)'
bool OMAP_PWM::setIntensity( uint16_t percentIntensity )
{
	// {{{USR

	uint32_t led_duty_cycle;

	bool return_val;


	led_duty_cycle = m_led_period * percentIntensity / 100;


	// check for out of range value (greater than 100%)

	if (percentIntensity > INTENSITY_MAX)
		{
		return_val = false;
		}

	else       // intensity is in valid range.
		{

		// check for "off condition".  If off, then shut down PWM and set output to low.

		if (percentIntensity == 0)
		{
			// stop clock and turn LED off!
	        while (testBitField((volatile uint32_t*)m_base_address,DMT_W_PEND_TCLR) != 0) {};
			volatile_write_UINT32(m_base_address + DMT_TCLR_OFFSET,0x0000);  
		}

		// Check for maximum condition (100%).  Due to OMAP requirements for counter distance between
		// match register value and overflow value, this condition is expanded to include [96%, 100%]
		// Clock is shutdown and output set to high.

		else if (percentIntensity > 95)
			{

			// stop clock and keep LED on!
	        while (testBitField((volatile uint32_t*)m_base_address,DMT_W_PEND_TCLR) != 0) {};
			volatile_write_UINT32(m_base_address + DMT_TCLR_OFFSET,0x0080);  

			}

		// percentIntensity is [1%, 95%].  Configure PWM for appropriate duty cycle.  Clock and SCPWM
		// will be properly configured by setPWM method.

		else
			{
			setPWM(m_led_period, led_duty_cycle);
			}

		return_val = true;

		}   

	return return_val;

	// }}}USR
}
// }}}RME

// {{{RME operation 'setPWM(uint32_t,uint32_t)'
bool OMAP_PWM::setPWM( uint32_t period_ns, uint32_t pulseDuration_ns )
{
	// {{{USR

	// PWM - Pulse Width Modulator
	// 
	// PWM is based on a 32 bit counter which is part of Dual Mode TimerX.  There are 8 DMTs, and
	// three of these are available as PWMs on OMAP 1610/1611/1612 and OMAP 330.
	//
	// "PWM 0" uses "GP TIMER 1" which is really "dual mode timer 1"
	// "PWM 1" uses "GP TIMER 2" which is really "dual mode timer 2"  
	// "PWM 2" uses "GP TIMER 3" which is really "dual mode timer 3"
	//

	bool return_val;

	const uint32_t  omap_config_reg_base = 0xFFFE1000;

	const uint32_t  dmt_tick_ns_slow = 30518;    // 32 kHz clock -> 30.5 us -> 30518 ns period
	const uint32_t  dmt_tick_ns_fast = 83;       // 12 MHz clock -> 83ns period. UINT32 

	volatile uint32_t dmt_load_value;                     // load value on overflow
	volatile uint32_t dmt_match_value;                    // match value on overflow

	volatile uint32_t  dmt_tick_ns;                       // 32 kHz clock source, prescaler = div by 1 (disabled)

	const   uint32_t dmt_rollover = 0xFFFFFFFF;           // dual mode Timer is 32 bits


	if (pulseDuration_ns >= period_ns) 
		{
		return_val = false;                // error condition!
		}
	else if (!((m_base_address == OMAP_PWM::PWM0_BASE_ADDR) || (m_base_address == OMAP_PWM::PWM1_BASE_ADDR) || \
			(m_base_address == OMAP_PWM::PWM2_BASE_ADDR)))

		{
		return_val = false;                // error condition!
		}
	else
		{

		if ((period_ns < (dmt_tick_ns_slow * 100)) || (	pulseDuration_ns < (dmt_tick_ns_slow * 25)))
			{
			dmt_tick_ns = dmt_tick_ns_fast;
			}
		else
			{
			dmt_tick_ns = dmt_tick_ns_slow;
			}
		

		// dmt_tick_ns now contains the amount of time (ns) of each tick of dual mode timer.
		//
		// From rollover value, count backwards in ticks to find load value.  This is also the initial
		// value.
		//
		// From load value, count forward in ticks to find match value.  This is the point in the period where
		// the waveform goes for active to inactive.  The signal switches back again at the rollover point.
		//
		// OMAP will be configured for "toggle" mode and to toggle waveform on both match and rollover events.
		//

		dmt_load_value = dmt_rollover - (period_ns / dmt_tick_ns);
		dmt_match_value = dmt_load_value + (pulseDuration_ns / dmt_tick_ns);


		// Configure Module Config Control 1 Register (MOD_CONF_CTRL_1) to select appropriate
		// clock source:  32kHz or 12MHz clock.
		// Warning:  PWMx = GPTIMER(x+1) = Dual Mode Timer (x+1)!!!
	  

		if (m_base_address == OMAP_PWM::PWM0_BASE_ADDR)
			{
			if (dmt_tick_ns == dmt_tick_ns_slow)
				{		
	 	   		setBitField((volatile uint32_t*)omap_config_reg_base,CONF_MOD_GPTIMER1_CLK_SEL_R,1);  // select 32 kHz clock for DMT		
				}
			else
				{
			    setBitField((volatile uint32_t*)omap_config_reg_base,CONF_MOD_GPTIMER1_CLK_SEL_R,0);  // select ARMXOR clock for DMT
				}
			}
		else if (m_base_address == OMAP_PWM::PWM1_BASE_ADDR)
			{
			if (dmt_tick_ns == dmt_tick_ns_slow)
				{		
	 	   		setBitField((volatile uint32_t*)omap_config_reg_base,CONF_MOD_GPTIMER2_CLK_SEL_R,1);  // select 32 kHz clock for DMT		
				}
			else
				{
			    setBitField((volatile uint32_t*)omap_config_reg_base,CONF_MOD_GPTIMER2_CLK_SEL_R,0);  // select ARMXOR clock for DMT
				}
			}
		else if (m_base_address == OMAP_PWM::PWM2_BASE_ADDR)
			{
			if (dmt_tick_ns == dmt_tick_ns_slow)
				{		
	 	   		setBitField((volatile uint32_t*)omap_config_reg_base,CONF_MOD_GPTIMER3_CLK_SEL_R,1);  // select 32 kHz clock for DMT		
				}
			else
				{
			    setBitField((volatile uint32_t*)omap_config_reg_base,CONF_MOD_GPTIMER3_CLK_SEL_R,0);  // select ARMXOR clock for DMT
				}
			}


		// TIOCP Config Reg  - let timer run free in emulation mode
		setBitField((volatile uint32_t*)m_base_address,DMT_EMUFREE,1);

		// Depending on clock source, this peripheral may need to be in "posted" mode, which
		// creates time sync issues inside OMAP.  Registers may not be written unless special flag
		// bit has been cleared.  The OMAP automatically sets and clears this bit.

		// load initial value into Timer Counter Register
		while (testBitField((volatile uint32_t*)m_base_address,DMT_W_PEND_TCRR) != 0) {};
		volatile_write_UINT32(m_base_address + DMT_TCRR_OFFSET,dmt_load_value);

		// load overflow value into Timer Load Register 
		while (testBitField((volatile uint32_t*)m_base_address,DMT_W_PEND_TLDR) != 0) {};
		volatile_write_UINT32(m_base_address + DMT_TLDR_OFFSET,dmt_load_value);

		// load match value into Timer Match Register
		while (testBitField((volatile uint32_t*)m_base_address,DMT_W_PEND_TMAR) != 0) {};
		volatile_write_UINT32(m_base_address + DMT_TMAR_OFFSET,dmt_match_value);



		// TCLR - Timer control reg offset 0x24 (LSB)
		// 
		// Depending on clock source, this peripheral may need to be in "posted" mode, which
		// creates time sync issues inside OMAP.  TCLR may not be written unless special flag
		// bit has been cleared.  The OMAP automatically sets and clears this bit.
		//


		while (testBitField((volatile uint32_t*)m_base_address,DMT_W_PEND_TCLR) != 0) {};
		setBitField((volatile uint32_t*)m_base_address,DMT_PT,1);      // toggle on PWM output

		while (testBitField((volatile uint32_t*)m_base_address,DMT_W_PEND_TCLR) != 0) {};
		setBitField((volatile uint32_t*)m_base_address,DMT_TRG,2);     // trigger on overflow and match

		while (testBitField((volatile uint32_t*)m_base_address,DMT_W_PEND_TCLR) != 0) {};
		setBitField((volatile uint32_t*)m_base_address,DMT_SCPWM,0);   // active high pulse

		while (testBitField((volatile uint32_t*)m_base_address,DMT_W_PEND_TCLR) != 0) {};
		setBitField((volatile uint32_t*)m_base_address,DMT_CE,1);      // turn on compare mode

		while (testBitField((volatile uint32_t*)m_base_address,DMT_W_PEND_TCLR) != 0) {};
		setBitField((volatile uint32_t*)m_base_address,DMT_PRE,0);     // prescaler disable

		while (testBitField((volatile uint32_t*)m_base_address,DMT_W_PEND_TCLR) != 0) {};
		setBitField((volatile uint32_t*)m_base_address,DMT_PTV,0);     // set prescaler to 1 divider

		while (testBitField((volatile uint32_t*)m_base_address,DMT_W_PEND_TCLR) != 0) {};
		setBitField((volatile uint32_t*)m_base_address,DMT_AR,1);      // set for auto re-load mode

		while (testBitField((volatile uint32_t*)m_base_address,DMT_W_PEND_TCLR) != 0) {};
		setBitField((volatile uint32_t*)m_base_address,DMT_ST,1);      // turn on dual mode timer

		return_val = true;

		}

	return return_val;

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
