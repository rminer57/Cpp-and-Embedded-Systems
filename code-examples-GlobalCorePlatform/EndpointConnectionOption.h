// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Endpoints::EndpointConnectionOption'

#ifndef EndpointConnectionOption_H
#define EndpointConnectionOption_H

#ifdef PRAGMA
#pragma interface "EndpointConnectionOption.h"
#endif

#include <endpoints_comp.h>
#include <Endpoint.h>
class Connection;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class EndpointConnectionOption : public Endpoint::EndpointOption
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
	// {{{RME classAttribute 'ENDPOINT_CONNOPTION'
	static const unsigned int ENDPOINT_CONNOPTION;
	// }}}RME

private:
	// {{{RME associationEnd 'm_connection'
	Connection * m_connection;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~EndpointConnectionOption( void );
	// }}}RME
	// {{{RME operation 'getType()'
	virtual ClassType getType( void ) const;
	// }}}RME
	// {{{RME operation 'isType(ClassType)'
	virtual bool isType( ClassType type ) const;
	// }}}RME
	// {{{RME operation 'EndPointConnectionOption(Connection*)'
	void EndPointConnectionOption( Connection * conn );
	// }}}RME
	// {{{RME operation 'getConnection()'
	virtual Connection * getConnection( void ) const;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* EndpointConnectionOption_H */

// }}}RME
