// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Utility::Light Weight Typing::TypedBaseClass'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "TypedBaseClass.h"
#endif

#include <utilgcp.h>
#include <TypedBaseClass.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'UNKNOWN'
const unsigned int TypedBaseClass::UNKNOWN( 0 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
TypedBaseClass::~TypedBaseClass( void )
{
}
// }}}RME

// {{{RME operation 'getType()'
ClassType TypedBaseClass::getType( void ) const
{
	// {{{USR
	return UNKNOWN;
	// }}}USR
}
// }}}RME

// {{{RME operation 'TypedBaseClass()'
TypedBaseClass::TypedBaseClass( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool TypedBaseClass::isType( ClassType type ) const
{
	// {{{USR
	return (type == UNKNOWN);
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
