// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Utility::Collections::Collection'

#ifndef Collection_H
#define Collection_H

#ifdef PRAGMA
#pragma interface "Collection.h"
#endif

#include <utilgcp.h>
class Collectable;
class Iterator;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class Collection
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR
	friend class LinkedListIterator;
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
	// {{{RME classAttribute 'END'
	static const unsigned int END;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~Collection( void );
	// }}}RME
	// {{{RME operation 'add(Collectable*,unsigned int)'
	virtual bool add( Collectable * obj, unsigned int index = 0 ) = 0;
	// }}}RME
	// {{{RME operation 'clear()'
	virtual void clear( void ) = 0;
	// }}}RME
	// {{{RME operation 'isEmpty()'
	virtual bool isEmpty( void ) const = 0;
	// }}}RME
	// {{{RME operation 'getSize()'
	virtual unsigned int getSize( void ) const = 0;
	// }}}RME
	// {{{RME operation 'contains(Collectable*)'
	virtual bool contains( Collectable * item ) const = 0;
	// }}}RME
	// {{{RME operation 'remove(Collectable *)'
	virtual Collectable * remove( Collectable * item ) = 0;
	// }}}RME
	// {{{RME operation 'remove(unsigned int)'
	virtual Collectable * remove( unsigned int index = 0 ) = 0;
	// }}}RME
	// {{{RME operation 'getIterator()'
	virtual Iterator * getIterator( void ) = 0;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Collection_H */

// }}}RME
