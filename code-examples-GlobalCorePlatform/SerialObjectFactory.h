// {{{RME classifier 'Logical View::SerializationBase::SerialObjectFactory'

#ifndef SerialObjectFactory_H
#define SerialObjectFactory_H

#ifdef PRAGMA
#pragma interface "SerialObjectFactory.h"
#endif

#include <serialbase.h>
class Array;
class SerialObject;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class SerialObjectFactory
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
	virtual ~SerialObjectFactory( void );
	// }}}RME
	// {{{RME operation 'getArray(SerialObject*)'
	virtual Array * getArray( SerialObject * s ) = 0;
	// }}}RME
	// {{{RME operation 'getBaseSize()'
	virtual unsigned int getBaseSize( void ) const = 0;
	// }}}RME
	// {{{RME operation 'getStore(Array*)'
	virtual SerialObject * getStore( Array * s ) const = 0;
	// }}}RME
	// {{{RME operation 'getStore(unsigned int)'
	virtual SerialObject * getStore( unsigned int s ) const = 0;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* SerialObjectFactory_H */

// }}}RME
