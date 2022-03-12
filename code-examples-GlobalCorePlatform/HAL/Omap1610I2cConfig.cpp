// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OMAP::I2c::OMAP1610I2c::Omap1610I2cConfig'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Omap1610I2cConfig.h"
#endif

#include <serial_comp.h>
#include <Omap1610I2cConfig.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
Omap1610I2cConfig::Omap1610I2cConfig( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
Omap1610I2cConfig::~Omap1610I2cConfig( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
Omap1610I2cConfig::Omap1610I2cConfig( const Omap1610I2cConfig & rtg_arg )
	: m_slaveAddress( rtg_arg.m_slaveAddress )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
Omap1610I2cConfig & Omap1610I2cConfig::operator=( const Omap1610I2cConfig & rtg_arg )
{
	if( this != &rtg_arg )
		m_slaveAddress = rtg_arg.m_slaveAddress;
	return *this;
}
// }}}RME

// {{{RME operation 'Omap1610I2cConfig(unsigned int)'
Omap1610I2cConfig::Omap1610I2cConfig( unsigned int slaveAddress )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	:m_slaveAddress(slaveAddress)
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
