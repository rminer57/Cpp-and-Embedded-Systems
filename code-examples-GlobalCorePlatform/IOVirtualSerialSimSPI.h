// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::TestSupportWin32::IOVirtualSerialSimSPI'

#ifndef IOVirtualSerialSimSPI_H
#define IOVirtualSerialSimSPI_H

#ifdef PRAGMA
#pragma interface "IOVirtualSerialSimSPI.h"
#endif

#include <HALtestLib_win32.h>
#include <IOVirtualSerial.h>
#include <IOVirtualSimBase.h>
#include <SIntArray.h>
class SCharArray;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>

// }}}USR
// }}}RME
// {{{RME classifier 'serialSimSPIdevices_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class IOVirtualSerialSimSPI : public IOVirtualSerial, public IOVirtualSimBase
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
	// {{{RME classifier 'serialSimSPIdevices_t'
	enum serialSimSPIdevices_t
	{
		ABACUS
	  , TOMAHAWK
	  , MAKO
	  , FRACN
	};
	// }}}RME
	// {{{RME classAttribute 'm_lastDataSent'
	Array * m_lastDataSent;
	// }}}RME

private:
	// {{{RME classAttribute 'm_whichIC'
	serialSimSPIdevices_t m_whichIC;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	IOVirtualSerialSimSPI( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~IOVirtualSerialSimSPI( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	IOVirtualSerialSimSPI( const IOVirtualSerialSimSPI & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	IOVirtualSerialSimSPI & operator=( const IOVirtualSerialSimSPI & rtg_arg );
	// }}}RME
	// {{{RME operation 'IOVirtualSerialSimSPI(IOVirtualSerialSimSPI::serialSimSPIdevices_t)'
	IOVirtualSerialSimSPI( serialSimSPIdevices_t whichIC );
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
// {{{RME classifier 'serialSimSPIdevices_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* IOVirtualSerialSimSPI_H */

// }}}RME
