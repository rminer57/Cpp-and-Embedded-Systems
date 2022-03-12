// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OMAP::I2c::OMAP1610I2c::Omap1610I2cConfig'

#ifndef Omap1610I2cConfig_H
#define Omap1610I2cConfig_H

#ifdef PRAGMA
#pragma interface "Omap1610I2cConfig.h"
#endif

#include <serial_comp.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class Omap1610I2cConfig
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
	// {{{RME classAttribute 'm_slaveAddress'
	unsigned int m_slaveAddress;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	Omap1610I2cConfig( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~Omap1610I2cConfig( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	Omap1610I2cConfig( const Omap1610I2cConfig & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	Omap1610I2cConfig & operator=( const Omap1610I2cConfig & rtg_arg );
	// }}}RME
	// {{{RME operation 'Omap1610I2cConfig(unsigned int)'
	Omap1610I2cConfig( unsigned int slaveAddress );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Omap1610I2cConfig_H */

// }}}RME
