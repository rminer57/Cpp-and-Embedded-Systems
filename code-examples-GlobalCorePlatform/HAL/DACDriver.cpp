// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::DACDriver'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "DACDriver.h"
#endif

#include <HALtestLib_win32.h>
#include <DACDriver.h>
#include <MakoPrivateBitfieldsReg6.h>
#include <rfSpiBuffer.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
DACDriver::DACDriver( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
DACDriver::~DACDriver( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
DACDriver::DACDriver( const DACDriver & rtg_arg )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
DACDriver & DACDriver::operator=( const DACDriver & rtg_arg )
{
	if( this != &rtg_arg )
	{
	}
	return *this;
}
// }}}RME

// {{{RME operation 'putDACBuffer(uint32_t,rfSpiBuffer*,int)'
void DACDriver::putDACBuffer( uint32_t dac, rfSpiBuffer * buffer, int value )
{
	// {{{USR
	// Initialize DAC1, if selected.
	if (dac == Mako::MAKO_DAC_1)
	   {
	   setBitField(*buffer,  DAC_SELECT, DAC1);                               // DAC1 selected.
	   setBitField(*buffer, DAC1_STATE, (Mako::DAC_POWER_DOWN == value?0:1)); // If true, power down DAC; else power it up
	   setBitField(*buffer, DAC_DATA_1, value);                               // DAC1 data.
	   }

	// Initialize DAC2.
	else if (dac == Mako::MAKO_DAC_2)
	   {
	   setBitField(*buffer, DAC_SELECT, DAC2);                                // DAC2 selected.
	   setBitField(*buffer, DAC2_STATE, (Mako::DAC_POWER_DOWN == value?0:1)); // If true, power down DAC; else power it up
	   setBitField(*buffer, DAC_DATA_2, value);                               // DAC2 data
	   }
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
