// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OMAP::Spi::OMAP1610Spi::Omap1610Spi'

#ifndef Omap1610Spi_H
#define Omap1610Spi_H

#ifdef PRAGMA
#pragma interface "Omap1610Spi.h"
#endif

#include <serial_comp.h>
#include <ArrayDescriptor.h>
#include <IOVirtualSerial.h>
class ChipSelect;
class DataBuffer;
class OMAPSpiConfig;
class Omap1610SpiFactory;
class SIntArray;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'SIntDesc' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class Omap1610Spi : public IOVirtualSerial
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
	// {{{RME classifier 'SIntDesc'
	class SIntDesc : public ArrayDescriptor
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
		// {{{RME classAttribute 'SINT_ARRAY_DESCRIPTOR_SPI'
		static const unsigned int SINT_ARRAY_DESCRIPTOR_SPI;
		// }}}RME

	private:
		// {{{RME classAttribute 'm_skipFirst'
		bool m_skipFirst;
		// }}}RME
		// {{{RME classAttribute 'm_skipLast'
		bool m_skipLast;
		// }}}RME

	public:
		// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
		virtual ~SIntDesc( void );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
		SIntDesc( const SIntDesc & rtg_arg );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
		SIntDesc & operator=( const SIntDesc & rtg_arg );
		// }}}RME
		// {{{RME operation 'isType(ClassType)'
		virtual bool isType( ClassType type ) const;
		// }}}RME
		// {{{RME operation 'getType()'
		virtual ClassType getType( void ) const;
		// }}}RME
		// {{{RME operation 'isSkipLast()'
		bool isSkipLast( void ) const;
		// }}}RME
		// {{{RME operation 'SIntDesc(bool,bool)'
		SIntDesc( bool skipFirst = false, bool skipLast = false );
		// }}}RME
		// {{{RME operation 'isSkipFirst()'
		bool isSkipFirst( void ) const;
		// }}}RME
	};
	// }}}RME
	// {{{RME associationEnd 'm_rxSpiBuffer'
	SIntArray * m_rxSpiBuffer;
	// }}}RME
	// {{{RME associationEnd 'm_cfg'
	OMAPSpiConfig * m_cfg;
	// }}}RME

private:
	// {{{RME associationEnd 'm_parent'
	Omap1610SpiFactory * m_parent;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	Omap1610Spi( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	Omap1610Spi( const Omap1610Spi & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	Omap1610Spi & operator=( const Omap1610Spi & rtg_arg );
	// }}}RME
	// {{{RME operation 'Omap1610Spi(OMAPSpiConfig *,Omap1610SpiFactory*)'
	Omap1610Spi( OMAPSpiConfig * config, Omap1610SpiFactory * parent );
	// }}}RME
	// {{{RME operation 'receive()'
	Array * receive( void );
	// }}}RME
	// {{{RME operation 'send(Array*)'
	bool send( Array * buf );
	// }}}RME
	// {{{RME operation 'deactivate()'
	virtual bool deactivate( void );
	// }}}RME
	// {{{RME operation 'activate()'
	virtual bool activate( void );
	// }}}RME
	// {{{RME operation '~Omap1610Spi()'
	~Omap1610Spi( void );
	// }}}RME
	// {{{RME operation 'getOption()'
	Configurable::Option * getOption( void ) const;
	// }}}RME
	// {{{RME operation 'getStatus()'
	Connection::Status * getStatus( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'SIntDesc' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Omap1610Spi_H */

// }}}RME
