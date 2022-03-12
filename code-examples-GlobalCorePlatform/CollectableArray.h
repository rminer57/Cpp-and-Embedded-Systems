// {{{RME classifier 'Logical View::DataArray::CollectableArray'

#ifndef CollectableArray_H
#define CollectableArray_H

#ifdef PRAGMA
#pragma interface "CollectableArray.h"
#endif

#include <data_array.h>
#include <Array.h>
class Collectable;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class CollectableArray : public Array
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
	// {{{RME classAttribute 'COLLECTABLE_ARRAY'
	static const unsigned int COLLECTABLE_ARRAY;
	// }}}RME

protected:
	// {{{RME associationEnd 'm_array'
	Collectable ** m_array;
	// }}}RME

public:
	// {{{RME operation 'operator[](unsigned int)'
	virtual Collectable * operator[]( unsigned int index ) const;
	// }}}RME
	// {{{RME operation 'operator*()'
	virtual Collectable * * operator*( void );
	// }}}RME
	// {{{RME operation 'getType()'
	virtual ClassType getType( void ) const;
	// }}}RME
	// {{{RME operation 'isType(ClassType)'
	virtual bool isType( ClassType type ) const;
	// }}}RME
	// {{{RME operation 'CollectableArray(unsigned int,Collectable**)'
	CollectableArray( unsigned int length, Collectable * * data = 0 );
	// }}}RME
	// {{{RME operation '~CollectableArray()'
	virtual ~CollectableArray( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* CollectableArray_H */

// }}}RME
