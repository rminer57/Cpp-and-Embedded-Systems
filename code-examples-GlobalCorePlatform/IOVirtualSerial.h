// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Serial IO::IOVirtualSerial'

#ifndef IOVirtualSerial_H
#define IOVirtualSerial_H

#ifdef PRAGMA
#pragma interface "IOVirtualSerial.h"
#endif

#include <hal.h>
#include <Connection.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class IOVirtualSerial : public Connection
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
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~IOVirtualSerial( void );
	// }}}RME
	// {{{RME operation 'deactivate()'
	virtual bool deactivate( void ) = 0;
	// }}}RME
	// {{{RME operation 'activate()'
	virtual bool activate( void ) = 0;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* IOVirtualSerial_H */

// }}}RME
