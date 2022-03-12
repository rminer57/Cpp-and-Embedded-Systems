// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Utility::Light Weight Typing::TypedBaseClass'

#ifndef TypedBaseClass_H
#define TypedBaseClass_H

#ifdef PRAGMA
#pragma interface "TypedBaseClass.h"
#endif

#include <utilgcp.h>
#include <ClassType.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class TypedBaseClass
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
	// {{{RME classAttribute 'UNKNOWN'
	static const unsigned int UNKNOWN;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~TypedBaseClass( void );
	// }}}RME
	// {{{RME operation 'getType()'
	virtual ClassType getType( void ) const;
	// }}}RME
	// {{{RME operation 'TypedBaseClass()'
	TypedBaseClass( void );
	// }}}RME
	// {{{RME operation 'isType(ClassType)'
	virtual bool isType( ClassType type ) const;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* TypedBaseClass_H */

// }}}RME
