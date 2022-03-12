// {{{RME classifier 'Logical View::SerializationBase::SerialObject'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "SerialObject.h"
#endif

#include <serialbase.h>
#include <SerialObject.h>
#include <SerialBits.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
SerialObject::~SerialObject( void )
{
}
// }}}RME

// {{{RME operation 'getType()'
ClassType SerialObject::getType( void ) const
{
	// {{{USR
	return UNKNOWN;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getSerialType()'
ClassType SerialObject::getSerialType( void ) const
{
	// {{{USR
	return 0;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
