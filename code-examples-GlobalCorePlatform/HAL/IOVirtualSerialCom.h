// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::TestSupportWin32::IOvirtualSerialComUartWin32Src::IOVirtualSerialCom::IOVirtualSerialCom'

#ifndef IOVirtualSerialCom_H
#define IOVirtualSerialCom_H

#ifdef PRAGMA
#pragma interface "IOVirtualSerialCom.h"
#endif

#include <HALtestLib_win32.h>
#include <Connection.h>
#include <IOVirtualSerial.h>
#include <Thread.h>
class DataBuffer;
class Mutex;
class OptionQuantizationUnit;
class SCharArray;
class Sem;
class UartConfig;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'MAX_COM_CHARS'
#define MAX_COM_CHARS 80
// }}}RME

class IOVirtualSerialCom : public IOVirtualSerial, public Thread, public Connection::Status
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
	// {{{RME classAttribute 'PortNumber'
	void * PortNumber;
	// }}}RME
	// {{{RME classAttribute 'PortName'
	char * PortName;
	// }}}RME
	// {{{RME classAttribute 'm_inIndex'
	unsigned int m_inIndex;
	// }}}RME
	// {{{RME classAttribute 'm_outIndex'
	unsigned int m_outIndex;
	// }}}RME
	// {{{RME classAttribute 'm_rxBuffer'
	char m_rxBuffer[ MAX_COM_CHARS ];
	// }}}RME
	// {{{RME classAttribute 'm_dataAvailable'
	bool m_dataAvailable;
	// }}}RME
	// {{{RME classAttribute 'm_readOverlapped'
	void * m_readOverlapped;
	// }}}RME
	// {{{RME classAttribute 'm_writeOverlapped'
	void * m_writeOverlapped;
	// }}}RME
	// {{{RME classAttribute 'm_baudrate'
	unsigned int m_baudrate;
	// }}}RME

public:
	// {{{RME associationEnd 'm_sem'
	Sem * m_sem;
	// }}}RME
	// {{{RME associationEnd 'm_mutex'
	Mutex * m_mutex;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	IOVirtualSerialCom( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	IOVirtualSerialCom( const IOVirtualSerialCom & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	IOVirtualSerialCom & operator=( const IOVirtualSerialCom & rtg_arg );
	// }}}RME
	// {{{RME operation 'IOVirtualSerialCom(unsigned long,char *)'
	IOVirtualSerialCom( unsigned long baudrate, char * portname );
	// }}}RME
	// {{{RME operation 'activate()'
	virtual bool activate( void );
	// }}}RME
	// {{{RME operation 'deactivate()'
	virtual bool deactivate( void );
	// }}}RME
	// {{{RME operation 'receive()'
	virtual Array * receive( void );
	// }}}RME
	// {{{RME operation 'send(Array *)'
	virtual bool send( Array * buffer );
	// }}}RME

protected:
	// {{{RME operation 'main()'
	virtual void * main( void );
	// }}}RME

public:
	// {{{RME operation '~IOVirtualSerialCom()'
	~IOVirtualSerialCom( void );
	// }}}RME
	// {{{RME operation 'isDataAvailable()'
	virtual bool isDataAvailable( void ) const;
	// }}}RME
	// {{{RME operation 'handleInformListeners()'
	void handleInformListeners( void );
	// }}}RME
	// {{{RME operation 'setIsDataAvailable(bool)'
	void setIsDataAvailable( bool state );
	// }}}RME
	// {{{RME operation 'getStatus()'
	virtual Connection::Status * getStatus( void );
	// }}}RME
	// {{{RME operation 'accumulateData(char *)'
	void accumulateData( char * rxChar );
	// }}}RME
	// {{{RME operation 'setOption(Configurable::Option *)'
	virtual bool setOption( Configurable::Option * option );
	// }}}RME
	// {{{RME operation 'getOption(ClassType)'
	virtual Configurable::Option * getOption( ClassType optionType ) const;
	// }}}RME
	// {{{RME operation 'sendString(char *)'
	void sendString( char * string );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* IOVirtualSerialCom_H */

// }}}RME
