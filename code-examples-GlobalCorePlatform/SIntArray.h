// {{{RME classifier 'Logical View::DataArray::SIntArray'

#ifndef SIntArray_H
#define SIntArray_H

#ifdef PRAGMA
#pragma interface "SIntArray.h"
#endif

#include <data_array.h>
#include <Array.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>
// }}}USR
// }}}RME

class SIntArray : public Array
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
	// {{{RME classAttribute 'SIGNED_INT_ARRAY'
	static const unsigned int SIGNED_INT_ARRAY;
	// }}}RME

protected:
	// {{{RME classAttribute 'm_array'
	int16_t * m_array;
	// }}}RME

public:
	// {{{RME operation 'operator[](unsigned int)'
	virtual int16_t & operator[]( unsigned int index ) const;
	// }}}RME
	// {{{RME operation 'operator*()'
	virtual int16_t * operator*( void );
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
	// {{{RME operation 'SIntArray(const SIntArray&)'
	SIntArray( const SIntArray & array );
	// }}}RME
	// {{{RME operation 'SIntArray(unsigned int,int16_t)'
	SIntArray( unsigned int length, int16_t init );
	// }}}RME
	// {{{RME operation 'SIntArray(unsigned int,int16_t*,bool)'
	SIntArray( unsigned int length, int16_t * buffer = 0, bool consumeBuffer = false );
	// }}}RME

protected:
	// {{{RME operation 'memcpy(int16_t *,const int16_t*,unsigned int)'
	void memcpy( int16_t * dest, const int16_t * src, unsigned int len );
	// }}}RME

public:
	// {{{RME operation '~SIntArray()'
	virtual ~SIntArray( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* SIntArray_H */

// }}}RME
