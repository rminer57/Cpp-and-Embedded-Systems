// {{{RME classifier 'Logical View::Serialization::SerialSizerFactory'

#ifndef SerialSizerFactory_H
#define SerialSizerFactory_H

#ifdef PRAGMA
#pragma interface "SerialSizerFactory.h"
#endif

#include <serialize_comp.h>
#include <AbstractSerialSizerFactory.h>
class AbstractSerialSizer;
class SerialSizer;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class SerialSizerFactory : public AbstractSerialSizerFactory
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
	virtual ~SerialSizerFactory( void );
	// }}}RME
	// {{{RME operation 'getSizer()'
	virtual AbstractSerialSizer * getSizer( void ) const;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* SerialSizerFactory_H */

// }}}RME
