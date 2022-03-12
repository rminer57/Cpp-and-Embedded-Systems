// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Connections::IsoTerminator'

#ifndef IsoTerminator_H
#define IsoTerminator_H

#ifdef PRAGMA
#pragma interface "IsoTerminator.h"
#endif

#include <conn.h>
#include <ArrayDescriptor.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class IsoTerminator : public ArrayDescriptor
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
	// {{{RME classAttribute 'ISO_TERM_DESCRIPTOR_TYPE'
	static const unsigned int ISO_TERM_DESCRIPTOR_TYPE;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~IsoTerminator( void );
	// }}}RME
	// {{{RME operation 'getType()'
	virtual ClassType getType( void ) const;
	// }}}RME
	// {{{RME operation 'isType(ClassType)'
	virtual bool isType( ClassType type ) const;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* IsoTerminator_H */

// }}}RME
