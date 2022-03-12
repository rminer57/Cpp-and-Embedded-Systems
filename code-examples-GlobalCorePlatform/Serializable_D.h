// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Utility::Serializable_D'

#ifndef Serializable_D_H
#define Serializable_D_H

#ifdef PRAGMA
#pragma interface "Serializable_D.h"
#endif

#include <utilgcp.h>
#include <TypedBaseClass.h>
class Array;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class Serializable_D : public TypedBaseClass
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
	Serializable_D( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~Serializable_D( void );
	// }}}RME
	// {{{RME operation 'serialize()'
	virtual Array * serialize( void ) = 0;
	// }}}RME
	// {{{RME operation 'unserialize(Array *)'
	virtual bool unserialize( Array * buf ) = 0;
	// }}}RME
	// {{{RME operation 'getMaxSize()'
	static unsigned int getMaxSize( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Serializable_D_H */

// }}}RME
