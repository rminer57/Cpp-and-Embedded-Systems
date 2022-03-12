// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::TestSupportWin32::IOVirtualSimBase'

#ifndef IOVirtualSimBase_H
#define IOVirtualSimBase_H

#ifdef PRAGMA
#pragma interface "IOVirtualSimBase.h"
#endif

#include <HALtestLib_win32.h>
class Array;
class SCharArray;
class SIntArray;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>
#include <iostream>
#include <iomanip>
#include <fstream>

#define EndianSwap_int32(x) \
	((x >> 16) & 0x0000FFFF) | ((x << 16) & 0xFFFF0000)

#define EndianSwap_int16(x) \
	((x >> 8) & 0x00FF) | ((x << 8) & 0xFF00)


// }}}USR
// }}}RME

class IOVirtualSimBase
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
	// {{{RME classAttribute 'm_outputBase'
	static int m_outputBase;
	// }}}RME
	// {{{RME classAttribute 'OUTPUT_MODE_DEFAULT'
	static const unsigned int OUTPUT_MODE_DEFAULT;
	// }}}RME
	// {{{RME classAttribute 'OUTPUT_MODE_HEX'
	static const unsigned int OUTPUT_MODE_HEX;
	// }}}RME
	// {{{RME classAttribute 'OUTPUT_MODE_BIN'
	static const unsigned int OUTPUT_MODE_BIN;
	// }}}RME

private:
	// {{{RME classAttribute 'm_isLogFileOpen'
	bool m_isLogFileOpen;
	// }}}RME

public:
	// {{{RME operation 'getch()'
	char getch( void );
	// }}}RME
	// {{{RME operation 'send(char)'
	void send( char characterToSend );
	// }}}RME
	// {{{RME operation 'send(char *)'
	void send( char * string );
	// }}}RME
	// {{{RME operation 'send(int16_t)'
	void send( int16_t data );
	// }}}RME
	// {{{RME operation 'sendFLUSH()'
	void sendFLUSH( void );
	// }}}RME
	// {{{RME operation 'sendENDL()'
	void sendENDL( void );
	// }}}RME
	// {{{RME operation 'getOutputBase()'
	unsigned int getOutputBase( void );
	// }}}RME
	// {{{RME operation 'LogFileOpen(char *)'
	int LogFileOpen( char * filename );
	// }}}RME
	// {{{RME operation 'LogFileClose()'
	void LogFileClose( void );
	// }}}RME
	// {{{RME operation 'IOVirtualSimBase()'
	IOVirtualSimBase( void );
	// }}}RME
	// {{{RME operation 'setOutputBase(int)'
	static void setOutputBase( int base );
	// }}}RME
	// {{{RME operation 'send(Array *)'
	bool send( Array * buffer );
	// }}}RME
	// {{{RME operation 'binaryPrint8(char)'
	void binaryPrint8( char dvalue );
	// }}}RME
	// {{{RME operation 'binaryPrint32(uint32_t)'
	void binaryPrint32( uint32_t dvalue );
	// }}}RME
	// {{{RME operation 'binaryPrint16(uint16_t)'
	void binaryPrint16( uint16_t dvalue );
	// }}}RME
	// {{{RME operation 'send(unsigned int)'
	void send( unsigned int data );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* IOVirtualSimBase_H */

// }}}RME
