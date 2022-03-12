// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::TestSupportWin32::IOVirtualSerialSimulationStderr'

#ifndef IOVirtualSerialSimulationStderr_H
#define IOVirtualSerialSimulationStderr_H

#ifdef PRAGMA
#pragma interface "IOVirtualSerialSimulationStderr.h"
#endif

#include <HALtestLib_win32.h>
#include <IOVirtualSerial.h>
#include <IOVirtualSimBase.h>
#include <SIntArray.h>
class Array;
class SCharArray;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

#ifdef _WIN32
#include <iostream>

#include <stdio.h>            /* Needed for printf() */
#include <stdlib.h>           /* Needed for malloc and free */
#include <conio.h>            /* Needed for getch() */
#include <stdarg.h>           /* variable arguments for printf */

#define BYTEMASK 0x80
#define WORDMASK 0x8000
#define DWORDMASK 0x80000000
#define BITSPERBYTE 8
#define BITSPERWORD 16
#define BITSPERDWORD 32


enum ONOFF
    {
    OFF = 0,
    ON  = 1
    };

enum YESNO
    {
    NO = 0,
    YES  = 1
    };

enum ACCESSMODE   /// file access mode selections for use by the
    {             /// member function open.
    READ = 0,
    WRITE =1,
    READWRITE =2, /// this is the default switch, unless you
    APPEND = 4    /// call the setaccessmode function to override.
    };



#endif
// }}}USR
// }}}RME

class IOVirtualSerialSimulationStderr : public IOVirtualSerial, public IOVirtualSimBase
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
	// {{{RME classAttribute 'm_valueToBeReturnedByReceive'
	unsigned int m_valueToBeReturnedByReceive;
	// }}}RME
	// {{{RME classAttribute 'm_valueOfSendLastOutput'
	unsigned int m_valueOfSendLastOutput;
	// }}}RME
	// {{{RME operation 'IOVirtualSerialSimulationStderr()'
	IOVirtualSerialSimulationStderr( void );
	// }}}RME
	// {{{RME operation 'activate()'
	bool activate( void );
	// }}}RME
	// {{{RME operation 'deactivate()'
	bool deactivate( void );
	// }}}RME
	// {{{RME operation 'getStatus()'
	Connection::Status * getStatus( void );
	// }}}RME
	// {{{RME operation 'receive()'
	Array * receive( void );
	// }}}RME
	// {{{RME operation 'send(Array *)'
	bool send( Array * buffer );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* IOVirtualSerialSimulationStderr_H */

// }}}RME
