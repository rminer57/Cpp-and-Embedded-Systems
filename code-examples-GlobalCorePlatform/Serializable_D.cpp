// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Utility::Serializable_D'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Serializable_D.h"
#endif

#include <utilgcp.h>
#include <Serializable_D.h>
#include <Array.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
Serializable_D::Serializable_D( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
Serializable_D::~Serializable_D( void )
{
}
// }}}RME

// {{{RME operation 'getMaxSize()'
unsigned int Serializable_D::getMaxSize( void )
{
	// {{{USR
	return sizeof(Serializable_D);
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
