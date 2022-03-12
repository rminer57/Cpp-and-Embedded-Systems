// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Connections::ConnectionManager'

#ifndef ConnectionManager_H
#define ConnectionManager_H

#ifdef PRAGMA
#pragma interface "ConnectionManager.h"
#endif

#include <conn.h>
#include <Connection.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class ConnectionManager
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
	// {{{RME classAttribute 'ASYNCHRONOUS'
	static const unsigned int ASYNCHRONOUS;
	// }}}RME
	// {{{RME classAttribute 'ISOCHRONOUS'
	static const unsigned int ISOCHRONOUS;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~ConnectionManager( void );
	// }}}RME
	// {{{RME operation 'getConnection(unsigned int,Connection::Option *)'
	virtual Connection * getConnection( unsigned int type = 0, Connection::Option * option = 0 ) = 0;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* ConnectionManager_H */

// }}}RME
