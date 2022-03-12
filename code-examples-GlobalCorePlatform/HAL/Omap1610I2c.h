// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OMAP::I2c::OMAP1610I2c::Omap1610I2c'

#ifndef Omap1610I2c_H
#define Omap1610I2c_H

#ifdef PRAGMA
#pragma interface "Omap1610I2c.h"
#endif

#include <serial_comp.h>
#include <IOVirtualSerial.h>
class DataBuffer;
class Omap1610I2cConfig;
class Omap1610I2cFactory;
class OptionQuantizationUnit;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class Omap1610I2c : public IOVirtualSerial
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
	// {{{RME classAttribute 'm_currentRxThreshold'
	unsigned int m_currentRxThreshold;
	// }}}RME
	// {{{RME associationEnd 'm_cfg'
	Omap1610I2cConfig * m_cfg;
	// }}}RME
	// {{{RME associationEnd 'm_parent'
	Omap1610I2cFactory * m_parent;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	Omap1610I2c( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~Omap1610I2c( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	Omap1610I2c( const Omap1610I2c & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	Omap1610I2c & operator=( const Omap1610I2c & rtg_arg );
	// }}}RME
	// {{{RME operation 'Omap1610I2c(Omap1610I2cConfig *,Omap1610I2cFactory *)'
	Omap1610I2c( Omap1610I2cConfig * config, Omap1610I2cFactory * parent );
	// }}}RME
	// {{{RME operation 'receive()'
	Array * receive( void );
	// }}}RME
	// {{{RME operation 'send(Array*)'
	bool send( Array * buf );
	// }}}RME
	// {{{RME operation 'activate()'
	bool activate( void );
	// }}}RME
	// {{{RME operation 'deactivate()'
	bool deactivate( void );
	// }}}RME
	// {{{RME operation 'setOption(Configurable::Option *)'
	bool setOption( Configurable::Option * option );
	// }}}RME
	// {{{RME operation 'getOption(ClassType)'
	Connection::Option * getOption( ClassType optionType );
	// }}}RME
	// {{{RME operation 'getStatus()'
	Connection::Status * getStatus( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Omap1610I2c_H */

// }}}RME
