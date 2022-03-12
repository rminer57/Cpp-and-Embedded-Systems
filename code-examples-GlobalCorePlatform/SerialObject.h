// {{{RME classifier 'Logical View::SerializationBase::SerialObject'

#ifndef SerialObject_H
#define SerialObject_H

#ifdef PRAGMA
#pragma interface "SerialObject.h"
#endif

#include <serialbase.h>
#include <TypedBaseClass.h>
class SerialBits;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class SerialObject : public TypedBaseClass
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
	virtual ~SerialObject( void );
	// }}}RME
	// {{{RME operation 'operator <<(int)'
	virtual SerialObject & operator <<( int i ) = 0;
	// }}}RME
	// {{{RME operation 'operator <<(unsigned int)'
	virtual SerialObject & operator <<( unsigned int i ) = 0;
	// }}}RME
	// {{{RME operation 'operator <<(char)'
	virtual SerialObject & operator <<( char i ) = 0;
	// }}}RME
	// {{{RME operation 'operator <<(unsigned char)'
	virtual SerialObject & operator <<( unsigned char i ) = 0;
	// }}}RME
	// {{{RME operation 'operator <<(bool)'
	virtual SerialObject & operator <<( bool i ) = 0;
	// }}}RME
	// {{{RME operation 'operator >>(int&)'
	virtual SerialObject & operator >>( int & i ) = 0;
	// }}}RME
	// {{{RME operation 'operator >>(unsigned int&)'
	virtual SerialObject & operator >>( unsigned int & i ) = 0;
	// }}}RME
	// {{{RME operation 'operator >>(char&)'
	virtual SerialObject & operator >>( char & i ) = 0;
	// }}}RME
	// {{{RME operation 'operator >>(unsigned char&)'
	virtual SerialObject & operator >>( unsigned char & i ) = 0;
	// }}}RME
	// {{{RME operation 'operator >>(bool&)'
	virtual SerialObject & operator >>( bool & i ) = 0;
	// }}}RME
	// {{{RME operation 'setType(ClassType)'
	virtual void setType( ClassType t ) = 0;
	// }}}RME
	// {{{RME operation 'getType()'
	virtual ClassType getType( void ) const;
	// }}}RME
	// {{{RME operation 'getSerialType()'
	virtual ClassType getSerialType( void ) const;
	// }}}RME
	// {{{RME operation 'reset()'
	virtual void reset( void ) = 0;
	// }}}RME
	// {{{RME operation 'operator <<(SerialBits&)'
	virtual SerialObject & operator <<( SerialBits & i ) = 0;
	// }}}RME
	// {{{RME operation 'operator >>(SerialBits&)'
	virtual SerialObject & operator >>( SerialBits & i ) = 0;
	// }}}RME
	// {{{RME operation 'operator <<(long)'
	virtual SerialObject & operator <<( long i ) = 0;
	// }}}RME
	// {{{RME operation 'operator >>(long&)'
	virtual SerialObject & operator >>( long & i ) = 0;
	// }}}RME
	// {{{RME operation 'operator <<(unsigned long)'
	virtual SerialObject & operator <<( unsigned long i ) = 0;
	// }}}RME
	// {{{RME operation 'operator >>(unsigned long&)'
	virtual SerialObject & operator >>( unsigned long & i ) = 0;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* SerialObject_H */

// }}}RME
