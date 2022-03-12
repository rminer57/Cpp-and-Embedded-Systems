// {{{RME classifier 'Logical View::DataArray::SCharArray'

#ifndef SCharArray_H
#define SCharArray_H

#ifdef PRAGMA
#pragma interface "SCharArray.h"
#endif

#include <data_array.h>
#include <Array.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class SCharArray : public Array
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
	// {{{RME classAttribute 'SIGNED_CHAR_ARRAY'
	static const unsigned int SIGNED_CHAR_ARRAY;
	// }}}RME

protected:
	// {{{RME classAttribute 'm_array'
	char * m_array;
	// }}}RME

public:
	// {{{RME operation 'operator[](unsigned int)'
	virtual char & operator[]( unsigned int index ) const;
	// }}}RME
	// {{{RME operation 'operator*()'
	virtual char * operator*( void );
	// }}}RME
	// {{{RME operation 'clone()'
	virtual Array * clone( void ) const;
	// }}}RME
	// {{{RME operation 'getType()'
	virtual ClassType getType( void ) const;
	// }}}RME
	// {{{RME operation 'isType(ClassType)'
	virtual bool isType( ClassType type ) const;
	// }}}RME
	// {{{RME operation 'SCharArray(const SCharArray&)'
	SCharArray( const SCharArray & array );
	// }}}RME
	// {{{RME operation 'SCharArray(unsigned int,char)'
	SCharArray( unsigned int length, char init );
	// }}}RME
	// {{{RME operation 'SCharArray(unsigned int,char*,bool)'
	SCharArray( unsigned int length, char * buffer = 0, bool consumeBuffer = false );
	// }}}RME

protected:
	// {{{RME operation 'memcpy(char*,const char*,unsigned int)'
	void memcpy( char * dest, const char * src, unsigned int len );
	// }}}RME

public:
	// {{{RME operation '~SCharArray()'
	virtual ~SCharArray( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* SCharArray_H */

// }}}RME
