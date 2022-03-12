// {{{RME classifier 'Logical View::DataArray::SCharArray'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "SCharArray.h"
#endif

#include "data_array.h"
#include "SCharArray.h"

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'SIGNED_CHAR_ARRAY'
const unsigned int SCharArray::SIGNED_CHAR_ARRAY( 3 );
// }}}RME

// {{{RME operation 'operator[](unsigned int)'
char & SCharArray::operator[]( unsigned int index ) const
{
	// {{{USR
	return m_array[index];
	// }}}USR
}
// }}}RME

// {{{RME operation 'operator*()'
char * SCharArray::operator*( void )
{
	// {{{USR
	char *returnArray = m_array;    // Save array address.
	m_array = 0;                           // This object no longer owns the array.
	m_length = 0;               // Therefore the array has no size.
	return returnArray;                    // Return array to the caller.
	// }}}USR
}
// }}}RME

// {{{RME operation 'clone()'
Array * SCharArray::clone( void ) const
{
	// {{{USR
	return new SCharArray(*this);


	// }}}USR
}
// }}}RME

// {{{RME operation 'getType()'
ClassType SCharArray::getType( void ) const
{
	// {{{USR
	return SIGNED_CHAR_ARRAY;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool SCharArray::isType( ClassType type ) const
{
	// {{{USR
	return (type == SIGNED_CHAR_ARRAY?true:Array::isType(type));
	// }}}USR
}
// }}}RME

// {{{RME operation 'SCharArray(const SCharArray&)'
SCharArray::SCharArray( const SCharArray & array )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	m_length=array.getLength();
	m_array=new char[m_length];
	memcpy(m_array, &array[0], m_length);

	// }}}USR
}
// }}}RME

// {{{RME operation 'SCharArray(unsigned int,char)'
SCharArray::SCharArray( unsigned int length, char init )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: Array(length)
	// }}}USR
	// }}}RME
{
	// {{{USR
	m_array = new char[m_length];
	for (unsigned int i=0; i<m_length; i++)
	   {
	    m_array[i]=init;
	   }

	// }}}USR
}
// }}}RME

// {{{RME operation 'SCharArray(unsigned int,char*,bool)'
SCharArray::SCharArray( unsigned int length, char * buffer, bool consumeBuffer )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: Array(length)
	// }}}USR
	// }}}RME
{
	// {{{USR
	if (!consumeBuffer)
	   {
	   m_array = new char[m_length];
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

// {{{RME operation 'memcpy(char*,const char*,unsigned int)'
void SCharArray::memcpy( char * dest, const char * src, unsigned int len )
{
	// {{{USR
	while (len-- > 0) *dest++ = *src++;
	// }}}USR
}
// }}}RME

// {{{RME operation '~SCharArray()'
SCharArray::~SCharArray( void )
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
