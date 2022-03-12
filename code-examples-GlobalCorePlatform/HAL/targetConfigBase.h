// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::targetConfigObjects::targetConfigBase'

#ifndef targetConfigBase_H
#define targetConfigBase_H

#ifdef PRAGMA
#pragma interface "targetConfigBase.h"
#endif

#include <HALtestLib_win32.h>
#include <IOVirtualSerial.h>
#include <SIntArray.h>
class IOVirtual;
class SCharArray;
class SoftTimerFactory;
class TimerVirtual;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

#define EndianSwap_int32(x) ((x >> 16) & 0x0000FFFF) | ((x << 16) & 0xFFFF0000)

#define EndianSwap_int16(x) ((x >> 8) & 0x00FF) | ((x << 8) & 0xFF00)

// }}}USR
// }}}RME
// {{{RME classifier 'targetConfigEnum_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'IOPinManager' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'IOPinManagerEnum_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'targetConfigEnumUarts_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'ICManager' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class targetConfigBase
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

protected:
	// {{{RME classifier 'targetConfigEnum_t'
	enum targetConfigEnum_t
	{
		CONFIG_PGAM
	  , CONFIG_MAKO = 0
	  , CONFIG_UART1
	  , CONFIG_UART2
	  , CONFIG_UART3
	};
	// }}}RME

public:
	// {{{RME classifier 'IOPinManager'
	class IOPinManager
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
		// {{{RME classAttribute 'm_IOVirtualPinArray'
		IOVirtual * * m_IOVirtualPinArray;
		// }}}RME
		// {{{RME classAttribute 'm_size'
		int m_size;
		// }}}RME

	public:
		// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
		IOPinManager( void );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
		virtual ~IOPinManager( void );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
		IOPinManager( const IOPinManager & rtg_arg );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
		IOPinManager & operator=( const IOPinManager & rtg_arg );
		// }}}RME
		// {{{RME operation 'getPin(int)'
		IOVirtual * getPin( int pinEnum );
		// }}}RME
		// {{{RME operation 'savePin(int,IOVirtual *)'
		void savePin( int pinEnum, IOVirtual * iovirtual );
		// }}}RME
		// {{{RME operation 'IOPinManager(int)'
		IOPinManager( int howmanyPins );
		// }}}RME
	};
	// }}}RME
	// {{{RME classifier 'IOPinManagerEnum_t'
	enum IOPinManagerEnum_t
	{
		PGAM_RESET_PIN
	  , MAKO_SPI_CS
	  , MAKO_VBUS_GPIO
	  , ABACUS_SPI_CS = 0
	  , TOMAHAWK_SPI_CS
	  , LED_RED
	  , LED_YELLOW
	  , LED_GREEN
	};
	// }}}RME

protected:
	// {{{RME classifier 'targetConfigEnumUarts_t'
	enum targetConfigEnumUarts_t
	{
		UART1 = 0
	  , UART2 = 1
	  , UART3 = 2
	};
	// }}}RME

public:
	// {{{RME classifier 'ICManager'
	class ICManager
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
		// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
		ICManager( void );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
		virtual ~ICManager( void );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
		ICManager( const ICManager & rtg_arg );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
		ICManager & operator=( const ICManager & rtg_arg );
		// }}}RME
	};
	// }}}RME
	// {{{RME classAttribute 'm_platform_stderr'
	static IOVirtualSerial * m_platform_stderr;
	// }}}RME

protected:
	// {{{RME classAttribute 'm_uartArray'
	static IOVirtualSerial * * m_uartArray;
	// }}}RME

public:
	// {{{RME classAttribute 'm_softTimerVirtual'
	static TimerVirtual * m_softTimerVirtual;
	// }}}RME

protected:
	// {{{RME classAttribute 'm_numof_uarts'
	int m_numof_uarts;
	// }}}RME

public:
	// {{{RME classAttribute 'm_PinsGPIO'
	static IOPinManager * m_PinsGPIO;
	// }}}RME

protected:
	// {{{RME classAttribute 'm_targetConfigArray'
	static targetConfigBase * * m_targetConfigArray;
	// }}}RME

public:
	// {{{RME classAttribute 'NUMofSUPPORTEDtargetConfigs'
	static const int NUMofSUPPORTEDtargetConfigs;
	// }}}RME
	// {{{RME classAttribute 'NUMofSUPPORTED_uarts'
	static const int NUMofSUPPORTED_uarts;
	// }}}RME
	// {{{RME classAttribute 'm_MakoSPI'
	static IOVirtualSerial * m_MakoSPI;
	// }}}RME
	// {{{RME classAttribute 'm_tomahawkSPI'
	IOVirtualSerial * m_tomahawkSPI;
	// }}}RME
	// {{{RME classAttribute 'm_abacusSPI'
	IOVirtualSerial * m_abacusSPI;
	// }}}RME
	// {{{RME classAttribute 'm_PGAMuart'
	static IOVirtualSerial * m_PGAMuart;
	// }}}RME
	// {{{RME classAttribute 'm_PGAMchipSelect'
	static IOVirtual * m_PGAMchipSelect;
	// }}}RME
	// {{{RME classAttribute 'm_MakochipSelect'
	static IOVirtual * m_MakochipSelect;
	// }}}RME
	// {{{RME classAttribute 'm_tomahawkchipSelect'
	static IOVirtual * m_tomahawkchipSelect;
	// }}}RME
	// {{{RME classAttribute 'm_abacuschipSelect'
	static IOVirtual * m_abacuschipSelect;
	// }}}RME
	// {{{RME classAttribute 'm_fracNSPI'
	IOVirtualSerial * m_fracNSPI;
	// }}}RME
	// {{{RME classAttribute 'm_fracNchipSelect'
	static IOVirtual * m_fracNchipSelect;
	// }}}RME
	// {{{RME operation 'send_int16_ToStderr(int16_t)'
	static void send_int16_ToStderr( int16_t data );
	// }}}RME
	// {{{RME operation 'targetConfigBase()'
	targetConfigBase( void );
	// }}}RME
	// {{{RME operation 'init()'
	virtual void init( void ) = 0;
	// }}}RME
	// {{{RME operation 'receiveFromUartLineOfChars(unsigned char *,char,int)'
	static int receiveFromUartLineOfChars( unsigned char * buffer, char linetermination, int whichUart );
	// }}}RME
	// {{{RME operation 'receiveFromUart(unsigned char *,int,int)'
	static int receiveFromUart( unsigned char * buffer, int numCharsToGet, int whichUart );
	// }}}RME
	// {{{RME operation 'sendStringToStderr(char *)'
	static void sendStringToStderr( char * string );
	// }}}RME
	// {{{RME operation 'send_uint32_ToStderr(uint32_t)'
	static void send_uint32_ToStderr( uint32_t data );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'targetConfigEnum_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'IOPinManager' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'IOPinManagerEnum_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'targetConfigEnumUarts_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'ICManager' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* targetConfigBase_H */

// }}}RME
