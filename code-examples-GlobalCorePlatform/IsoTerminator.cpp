// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Connections::IsoTerminator'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "IsoTerminator.h"
#endif

#include <conn.h>
#include <IsoTerminator.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'ISO_TERM_DESCRIPTOR_TYPE'
const unsigned int IsoTerminator::ISO_TERM_DESCRIPTOR_TYPE( 3 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
IsoTerminator::~IsoTerminator( void )
{
}
// }}}RME

// {{{RME operation 'getType()'
ClassType IsoTerminator::getType( void ) const
{
	// {{{USR
	return ISO_TERM_DESCRIPTOR_TYPE;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool IsoTerminator::isType( ClassType type ) const
{
	// {{{USR
	return (type == ISO_TERM_DESCRIPTOR_TYPE?true:ArrayDescriptor::isType(type));
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
