// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Utility::Collections::Iterator'

#ifndef Iterator_H
#define Iterator_H

#ifdef PRAGMA
#pragma interface "Iterator.h"
#endif

#include <utilgcp.h>
class Collectable;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class Iterator
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
	virtual ~Iterator( void );
	// }}}RME
	// {{{RME operation 'hasNext()'
	virtual bool hasNext( void ) const = 0;
	// }}}RME
	// {{{RME operation 'next()'
	virtual const Collectable * next( void ) = 0;
	// }}}RME
	// {{{RME operation 'remove()'
	virtual Collectable * remove( void ) = 0;
	// }}}RME
	// {{{RME operation 'reset()'
	virtual void reset( void ) = 0;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Iterator_H */

// }}}RME
