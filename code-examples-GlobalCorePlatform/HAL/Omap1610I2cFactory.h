// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OMAP::I2c::OMAP1610I2c::Omap1610I2cFactory'

#ifndef Omap1610I2cFactory_H
#define Omap1610I2cFactory_H

#ifdef PRAGMA
#pragma interface "Omap1610I2cFactory.h"
#endif

#include <serial_comp.h>
class IOVirtualSerial;
class Omap1610I2c;
class Omap1610I2cConfig;
class bitfield;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class Omap1610I2cFactory
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR
	friend class Omap1610I2c;
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
	// {{{RME classAttribute 'm_baseAddress'
	volatile unsigned short * m_baseAddress;
	// }}}RME
	// {{{RME classAttribute 'm_prescaler'
	unsigned int m_prescaler;
	// }}}RME
	// {{{RME classAttribute 'm_ownAddress'
	unsigned int m_ownAddress;
	// }}}RME
	// {{{RME classAttribute 'm_slowSpeed'
	bool m_slowSpeed;
	// }}}RME
	// {{{RME classAttribute 'm_numTimesToPollRDYFlags'
	unsigned int m_numTimesToPollRDYFlags;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	Omap1610I2cFactory( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~Omap1610I2cFactory( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	Omap1610I2cFactory( const Omap1610I2cFactory & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	Omap1610I2cFactory & operator=( const Omap1610I2cFactory & rtg_arg );
	// }}}RME
	// {{{RME operation 'getIOVirtualSerial(Omap1610I2cConfig*)'
	IOVirtualSerial * getIOVirtualSerial( Omap1610I2cConfig * config );
	// }}}RME
	// {{{RME operation 'Omap1610I2cFactory(volatile unsigned short*,unsigned int,unsigned int,bool,unsigned int)'
	Omap1610I2cFactory( volatile unsigned short * i2cBaseAddress, unsigned int prescaler, unsigned int ownAddress = 1, bool slowSpeed = true, unsigned int numTimesToPollRDYFlags = 10000 );
	// }}}RME
	// {{{RME operation 'send(Omap1610I2cConfig*,unsigned char *,unsigned int)'
	bool send( Omap1610I2cConfig * config, unsigned char * buffer, unsigned int size );
	// }}}RME
	// {{{RME operation 'receive(Omap1610I2cConfig*,unsigned int)'
	unsigned char * receive( Omap1610I2cConfig * config, unsigned int size );
	// }}}RME

private:
	// {{{RME operation 'i2cReset()'
	void i2cReset( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Omap1610I2cFactory_H */

// }}}RME
