// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Utility::Unserializer_D'

#ifndef Unserializer_D_H
#define Unserializer_D_H

#ifdef PRAGMA
#pragma interface "Unserializer_D.h"
#endif

#include <utilgcp.h>
#include <ClassType.h>
class Array;
class Serializable_D;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class Unserializer_D
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
	virtual ~Unserializer_D( void );
	// }}}RME
	// {{{RME operation 'unserialize(Serializable_D **,Array *)'
	virtual ClassType unserialize( Serializable_D * * obj, Array * buf ) = 0;
	// }}}RME
	// {{{RME operation 'getMaxSize()'
	virtual unsigned int getMaxSize( void ) const = 0;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Unserializer_D_H */

// }}}RME
