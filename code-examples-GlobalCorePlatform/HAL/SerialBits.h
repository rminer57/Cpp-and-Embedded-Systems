// {{{RME classifier 'Logical View::SerializationBase::SerialBits'

#ifndef SerialBits_H
#define SerialBits_H

#ifdef PRAGMA
#pragma interface "SerialBits.h"
#endif

#include <serialbase.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class SerialBits
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
	// {{{RME classAttribute 'm_length'
	unsigned int m_length;
	// }}}RME
	// {{{RME classAttribute 'm_data'
	unsigned int m_data;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~SerialBits( void );
	// }}}RME
	// {{{RME operation 'SerialBits(unsigned int,unsigned int)'
	SerialBits( unsigned int length = 1, unsigned int data = 0 );
	// }}}RME
	// {{{RME operation 'set(unsigned int,unsigned int)'
	SerialBits & set( unsigned int length, unsigned int data = 0 );
	// }}}RME
	// {{{RME operation 'getData()'
	virtual unsigned int getData( void ) const;
	// }}}RME
	// {{{RME operation 'getLength()'
	virtual unsigned int getLength( void ) const;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* SerialBits_H */

// }}}RME
