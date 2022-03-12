// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::targetConfigObjects::targetConfigBase'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "targetConfigBase.h"
#endif

#include <HALtestLib_win32.h>
#include <targetConfigBase.h>
#include <IOVirtual.h>
#include <SCharArray.h>
#include <SoftTimerFactory.h>
#include <TimerVirtual.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

static int createdArrays = 0;
// }}}USR
// }}}RME
// {{{RME classifier 'targetConfigEnum_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'IOPinManager' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'IOPinManagerEnum_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'targetConfigEnumUarts_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'ICManager' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classifier 'IOPinManager'

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
targetConfigBase::IOPinManager::IOPinManager( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
targetConfigBase::IOPinManager::~IOPinManager( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
targetConfigBase::IOPinManager::IOPinManager( const IOPinManager & rtg_arg )
	: m_IOVirtualPinArray( rtg_arg.m_IOVirtualPinArray )
	, m_size( rtg_arg.m_size )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
targetConfigBase::IOPinManager & targetConfigBase::IOPinManager::operator=( const IOPinManager & rtg_arg )
{
	if( this != &rtg_arg )
	{
		m_IOVirtualPinArray = rtg_arg.m_IOVirtualPinArray;
		m_size = rtg_arg.m_size;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'getPin(int)'
IOVirtual * targetConfigBase::IOPinManager::getPin( int pinEnum )
{
	// {{{USR
	IOVirtual * retval = 0;

	if( pinEnum < m_size )
	{
	 retval = m_IOVirtualPinArray[pinEnum];
	}
	else
	{
	  sendStringToStderr("Err-Bad-Arg: targetConfigBase::IOPin::getPin()\n");
	}

	return retval;

	// }}}USR
}
// }}}RME

// {{{RME operation 'savePin(int,IOVirtual *)'
void targetConfigBase::IOPinManager::savePin( int pinEnum, IOVirtual * iovirtual )
{
	// {{{USR

	if( pinEnum < m_size )
	{
	 m_IOVirtualPinArray[pinEnum] = iovirtual;
	}
	else
	{
	  sendStringToStderr("Err-Bad-Arg: targetConfigBase::IOPin::setPin()\n");
	}
	// }}}USR
}
// }}}RME

// {{{RME operation 'IOPinManager(int)'
targetConfigBase::IOPinManager::IOPinManager( int howmanyPins )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	m_size = howmanyPins;

	m_IOVirtualPinArray = new IOVirtual *[m_size];


	// initialize to zero.
	for(int i = 0; i < m_size; i++)
	{
	  m_IOVirtualPinArray[i] = 0; 
	}
	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME classifier 'ICManager'

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
targetConfigBase::ICManager::ICManager( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
targetConfigBase::ICManager::~ICManager( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
targetConfigBase::ICManager::ICManager( const ICManager & rtg_arg )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
targetConfigBase::ICManager & targetConfigBase::ICManager::operator=( const ICManager & rtg_arg )
{
	if( this != &rtg_arg )
	{
	}
	return *this;
}
// }}}RME
// }}}RME

// {{{RME classAttribute 'm_platform_stderr'
IOVirtualSerial * targetConfigBase::m_platform_stderr;
// }}}RME

// {{{RME classAttribute 'm_uartArray'
IOVirtualSerial * * targetConfigBase::m_uartArray;
// }}}RME

// {{{RME classAttribute 'm_softTimerVirtual'
TimerVirtual * targetConfigBase::m_softTimerVirtual;
// }}}RME

// {{{RME classAttribute 'm_PinsGPIO'
targetConfigBase::IOPinManager * targetConfigBase::m_PinsGPIO;
// }}}RME

// {{{RME classAttribute 'm_targetConfigArray'
targetConfigBase * * targetConfigBase::m_targetConfigArray;
// }}}RME

// {{{RME classAttribute 'NUMofSUPPORTEDtargetConfigs'
const int targetConfigBase::NUMofSUPPORTEDtargetConfigs( 32 );
// }}}RME

// {{{RME classAttribute 'NUMofSUPPORTED_uarts'
const int targetConfigBase::NUMofSUPPORTED_uarts( 3 );
// }}}RME

// {{{RME classAttribute 'm_MakoSPI'
IOVirtualSerial * targetConfigBase::m_MakoSPI;
// }}}RME

// {{{RME classAttribute 'm_PGAMuart'
IOVirtualSerial * targetConfigBase::m_PGAMuart;
// }}}RME

// {{{RME classAttribute 'm_PGAMchipSelect'
IOVirtual * targetConfigBase::m_PGAMchipSelect;
// }}}RME

// {{{RME classAttribute 'm_MakochipSelect'
IOVirtual * targetConfigBase::m_MakochipSelect;
// }}}RME

// {{{RME classAttribute 'm_tomahawkchipSelect'
IOVirtual * targetConfigBase::m_tomahawkchipSelect;
// }}}RME

// {{{RME classAttribute 'm_abacuschipSelect'
IOVirtual * targetConfigBase::m_abacuschipSelect;
// }}}RME

// {{{RME classAttribute 'm_fracNchipSelect'
IOVirtual * targetConfigBase::m_fracNchipSelect;
// }}}RME

// {{{RME operation 'send_int16_ToStderr(int16_t)'
void targetConfigBase::send_int16_ToStderr( int16_t data )
{
	// {{{USR

	int16_t wrData = data;

	// note, don't perform the endian swap on windows because the
	// IOVirtualSimBase object does this.  On arm9, we'll be using
	// the Omap1610 uart driver, which will just send the data out.
	// In that case, Little Endian will be displayed incorrectly

#ifndef _WIN32 // arm9 or windows

	    wrData = EndianSwap_int16(wrData);

#endif 

	SIntArray * db = new SIntArray( 1, (int16_t *)&wrData);   

	if(m_platform_stderr != 0)
	{

	  m_platform_stderr->send(db);

	}
	// }}}USR
}
// }}}RME

// {{{RME operation 'targetConfigBase()'
targetConfigBase::targetConfigBase( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR

	if( createdArrays++ == 0)
	{
	  // create the array of target configs.
	  m_targetConfigArray = new targetConfigBase * [NUMofSUPPORTEDtargetConfigs];

	  // create the array of uart IOVirtualSerials
	  m_uartArray = new IOVirtualSerial *[3];
	  m_numof_uarts = 3;
	}



	// }}}USR
}
// }}}RME

// {{{RME operation 'receiveFromUartLineOfChars(unsigned char *,char,int)'
int targetConfigBase::receiveFromUartLineOfChars( unsigned char * buffer, char linetermination, int whichUart )
{
	// {{{USR
	int retval = 0;
	int numCharsToGet = 1;

	switch(whichUart)
	{
	   case 1:
	          
	          retval = (targetConfigBase::m_targetConfigArray[targetConfigBase::UART1])->receiveFromUart(buffer,numCharsToGet,whichUart);
	   break;

	   case 2:
	          retval = (targetConfigBase::m_targetConfigArray[targetConfigBase::UART2])->receiveFromUart(buffer,numCharsToGet,whichUart);
	   break;
	}


	return retval;

	  
	 
	// }}}USR
}
// }}}RME

// {{{RME operation 'receiveFromUart(unsigned char *,int,int)'
int targetConfigBase::receiveFromUart( unsigned char * buffer, int numCharsToGet, int whichUart )
{
	// {{{USR
	int retval = 0;

	switch(whichUart)
	{
	   case 1:
	          retval = (targetConfigBase::m_targetConfigArray[targetConfigBase::UART1])->receiveFromUart(buffer,numCharsToGet,whichUart);
	   break;

	   case 2:
	          retval = (targetConfigBase::m_targetConfigArray[targetConfigBase::UART2])->receiveFromUart(buffer,numCharsToGet,whichUart);
	   break;
	}


	return retval;

	  
	 
	// }}}USR
}
// }}}RME

// {{{RME operation 'sendStringToStderr(char *)'
void targetConfigBase::sendStringToStderr( char * string )
{
	// {{{USR

	if(m_platform_stderr != 0)
	{
	  // implement this later. Use an IOVirtualSerial as the
	  // output. The following code will work.

	  int len = 0;
	  char * temp = 0;
	  temp = string;

	  while( *temp != 0) { len++; temp++; }

	  SCharArray * txBuffer = new SCharArray(len, string);

	  m_platform_stderr->send(txBuffer);

	}
	// }}}USR
}
// }}}RME

// {{{RME operation 'send_uint32_ToStderr(uint32_t)'
void targetConfigBase::send_uint32_ToStderr( uint32_t data )
{
	// {{{USR

	uint32_t wrData = data;

	// note, don't perform the endian swap on windows because the
	// IOVirtualSimBase object does this.  On arm9, we'll be using
	// the Omap1610 uart driver, which will just send the data out.
	// In that case, Little Endian will be displayed incorrectly

#ifndef _WIN32 // arm9 or windows

	    wrData = EndianSwap_int32(wrData);

#endif 

	SIntArray * db = new SIntArray( 2, (int16_t *)&wrData);   

	// perform an Endian Swap if executing on arm9 or windows
#ifndef _WIN32 // arm9 or windows

	    // swap bytes in each int16_t
	    (*db)[0] = EndianSwap_int16( (*db)[0] );
	    (*db)[1] = EndianSwap_int16( (*db)[1] ); 
	   
#endif


	if(m_platform_stderr != 0)
	{

	  m_platform_stderr->send(db);

	}
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'targetConfigEnum_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'IOPinManager' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'IOPinManagerEnum_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'targetConfigEnumUarts_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'ICManager' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
