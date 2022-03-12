// {{{RME classifier 'Logical View::Serialization::SerialSizer'

#ifndef SerialSizer_H
#define SerialSizer_H

#ifdef PRAGMA
#pragma interface "SerialSizer.h"
#endif

#include <serialize_comp.h>
#include <AbstractSerialSizer.h>
class SerialBits;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class SerialSizer : public AbstractSerialSizer
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

protected:
	// {{{RME classAttribute 'm_length'
	unsigned int m_length;
	// }}}RME

public:
	// {{{RME operation 'operator <<(int)'
	SerialObject & operator <<( int i );
	// }}}RME
	// {{{RME operation 'operator <<(unsigned int)'
	SerialObject & operator <<( unsigned int i );
	// }}}RME
	// {{{RME operation 'operator <<(char)'
	SerialObject & operator <<( char i );
	// }}}RME
	// {{{RME operation 'operator <<(unsigned char)'
	SerialObject & operator <<( unsigned char i );
	// }}}RME
	// {{{RME operation 'operator <<(bool)'
	SerialObject & operator <<( bool i );
	// }}}RME
	// {{{RME operation 'operator >>(int&)'
	SerialObject & operator >>( int & i );
	// }}}RME
	// {{{RME operation 'operator >>(unsigned int&)'
	SerialObject & operator >>( unsigned int & i );
	// }}}RME
	// {{{RME operation 'operator >>(char&)'
	SerialObject & operator >>( char & i );
	// }}}RME
	// {{{RME operation 'operator >>(unsigned char&)'
	SerialObject & operator >>( unsigned char & i );
	// }}}RME
	// {{{RME operation 'operator >>(bool&)'
	SerialObject & operator >>( bool & i );
	// }}}RME
	// {{{RME operation 'setType(ClassType)'
	void setType( ClassType t );
	// }}}RME
	// {{{RME operation 'SerialSizer()'
	SerialSizer( void );
	// }}}RME
	// {{{RME operation 'getLength()'
	unsigned int getLength( void ) const;
	// }}}RME
	// {{{RME operation 'reset()'
	void reset( void );
	// }}}RME
	// {{{RME operation 'operator <<(SerialBits&)'
	virtual SerialObject & operator <<( SerialBits & i );
	// }}}RME
	// {{{RME operation 'operator >>(SerialBits&)'
	virtual SerialObject & operator >>( SerialBits & i );
	// }}}RME
	// {{{RME operation 'operator <<(long)'
	virtual SerialObject & operator <<( long i );
	// }}}RME
	// {{{RME operation 'operator >>(long&)'
	virtual SerialObject & operator >>( long & i );
	// }}}RME
	// {{{RME operation 'operator <<(unsigned long)'
	virtual SerialObject & operator <<( unsigned long i );
	// }}}RME
	// {{{RME operation 'operator >>(unsigned long&)'
	virtual SerialObject & operator >>( unsigned long & i );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* SerialSizer_H */

// }}}RME
