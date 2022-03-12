// {{{RME classifier 'Logical View::DataArray::SIntArray'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "SIntArray.h"
#endif

#include <data_array.h>
#include <SIntArray.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'SIGNED_INT_ARRAY'
const unsigned int SIntArray::SIGNED_INT_ARRAY( 2 );
// }}}RME

// {{{RME operation 'operator[](unsigned int)'
int16_t & SIntArray::operator[]( unsigned int index ) const
{
	// {{{USR
	return m_array[index];
	// }}}USR
}
// }}}RME

// {{{RME operation 'operator*()'
int16_t * SIntArray::operator*( void )
{
	// {{{USR
	int16_t *returnArray = m_array; // Save array address.
	m_array = 0;                // This object no longer owns the array.
	m_length = 0;               // Therefore the array has no size.
	return returnArray;         // Return array to the caller.
	// }}}USR
}
// }}}RME

// {{{RME operation 'clone()'
Array * SIntArray::clone( void ) const
{
	// {{{USR
	return new SIntArray(*this);



	// }}}USR
}
// }}}RME

// {{{RME operation 'getType()'
ClassType SIntArray::getType( void ) const
{
	// {{{USR
	return SIGNED_INT_ARRAY;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool SIntArray::isType( ClassType type ) const
{
	// {{{USR
	return (type == SIGNED_INT_ARRAY?true:Array::isType(type));
	// }}}USR
}
// }}}RME

// {{{RME operation 'SIntArray(const SIntArray&)'
SIntArray::SIntArray( const SIntArray & array )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	m_length=array.getLength();
	m_array=new int16_t[m_length];
	memcpy(m_array, &array[0], m_length);

	// }}}USR
}
// }}}RME

// {{{RME operation 'SIntArray(unsigned int,int16_t)'
SIntArray::SIntArray( unsigned int length, int16_t init )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: Array(length)
	// }}}USR
	// }}}RME
{
	// {{{USR
	m_array = new int16_t[m_length];
	for (unsigned int i=0; i<m_length; i++)
	   {
	    m_array[i]=init;
	   }

	// }}}USR
}
// }}}RME

// {{{RME operation 'SIntArray(unsigned int,int16_t*,bool)'
SIntArray::SIntArray( unsigned int length, int16_t * buffer, bool consumeBuffer )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: Array(length)
	// }}}USR
	// }}}RME
{
	// {{{USR
	if (!consumeBuffer)
	   {
	   m_array = new int16_t[m_length];
	   if (buffer != 0)
	      {
	      memcpy(m_array, buffer, m_length);
	      }
	   }
	else
	   {
	   m_array=buffer;                                      // i.e., wrap up the given data into an SIntArray.
	   }




	// }}}USR
}
// }}}RME

// {{{RME operation 'memcpy(int16_t *,const int16_t*,unsigned int)'
void SIntArray::memcpy( int16_t * dest, const int16_t * src, unsigned int len )
{
	// {{{USR
	while (len-- > 0) *dest++ = *src++;
	// }}}USR
}
// }}}RME

// {{{RME operation '~SIntArray()'
SIntArray::~SIntArray( void )
{
	// {{{USR
	delete [] m_array;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
