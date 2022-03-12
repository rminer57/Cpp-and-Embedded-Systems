// {{{RME classifier 'Logical View::SerializationBase::SerialBits'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "SerialBits.h"
#endif

#include <serialbase.h>
#include <SerialBits.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
SerialBits::~SerialBits( void )
{
}
// }}}RME

// {{{RME operation 'SerialBits(unsigned int,unsigned int)'
SerialBits::SerialBits( unsigned int length, unsigned int data )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	set(length,data);
	// }}}USR
}
// }}}RME

// {{{RME operation 'set(unsigned int,unsigned int)'
SerialBits & SerialBits::set( unsigned int length, unsigned int data )
{
	// {{{USR
	m_length = length;
	m_data = data & ((0x1 << length) - 1);			//apply mask to constrain data to length
	return *this;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getData()'
unsigned int SerialBits::getData( void ) const
{
	// {{{USR
	return m_data;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getLength()'
unsigned int SerialBits::getLength( void ) const
{
	// {{{USR
	return m_length;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
