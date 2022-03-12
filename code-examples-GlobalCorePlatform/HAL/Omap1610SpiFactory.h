// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OMAP::Spi::OMAP1610Spi::Omap1610SpiFactory'

#ifndef Omap1610SpiFactory_H
#define Omap1610SpiFactory_H

#ifdef PRAGMA
#pragma interface "Omap1610SpiFactory.h"
#endif

#include <serial_comp.h>
#include <IOVirtualSerial.h>
#include <IrqHandler.h>
#include <OMAPSpiConfig.h>
class Omap1610Spi;
class SIntArray;
class bitfield;
class peripheral_access;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class Omap1610SpiFactory : public IrqHandler
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR
	friend class Omap1610Spi;
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
	unsigned int m_baseAddress;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	Omap1610SpiFactory( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~Omap1610SpiFactory( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	Omap1610SpiFactory( const Omap1610SpiFactory & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	Omap1610SpiFactory & operator=( const Omap1610SpiFactory & rtg_arg );
	// }}}RME
	// {{{RME operation 'getIOVirtualSerial(OMAPSpiConfig*)'
	IOVirtualSerial * getIOVirtualSerial( OMAPSpiConfig * config );
	// }}}RME
	// {{{RME operation 'Omap1610SpiFactory(unsigned int)'
	Omap1610SpiFactory( unsigned int spiBaseAddr );
	// }}}RME

private:
	// {{{RME operation 'configure(OMAPSpiConfig*)'
	void configure( OMAPSpiConfig * config );
	// }}}RME

public:
	// {{{RME operation 'handler()'
	void handler( void );
	// }}}RME

private:
	// {{{RME operation 'sendAndReceive(SIntArray *,bool,bool)'
	void sendAndReceive( SIntArray * buffer, bool skipFirstByte = false, bool skipLastByte = false );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Omap1610SpiFactory_H */

// }}}RME
