// {{{RME classifier 'Logical View::Serialization::SerialStoreFactory'

#ifndef SerialStoreFactory_H
#define SerialStoreFactory_H

#ifdef PRAGMA
#pragma interface "SerialStoreFactory.h"
#endif

#include <serialize_comp.h>
#include <SerialObjectFactory.h>
class SerialStore;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class SerialStoreFactory : public SerialObjectFactory
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
	virtual ~SerialStoreFactory( void );
	// }}}RME
	// {{{RME operation 'getStore(unsigned int)'
	virtual SerialObject * getStore( unsigned int s ) const;
	// }}}RME
	// {{{RME operation 'getBaseSize()'
	virtual unsigned int getBaseSize( void ) const;
	// }}}RME
	// {{{RME operation 'getArray(SerialObject*)'
	virtual Array * getArray( SerialObject * s );
	// }}}RME
	// {{{RME operation 'getStore(Array*)'
	virtual SerialObject * getStore( Array * s ) const;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* SerialStoreFactory_H */

// }}}RME
