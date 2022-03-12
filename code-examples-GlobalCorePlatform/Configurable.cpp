// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Connections::Configurable'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Configurable.h"
#endif

#include <conn.h>
#include <Configurable.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Option' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
SERIAL_CLASS_INITIALIZE(Configurable::Option);		//Put here to prevent constant resizing
// }}}USR
// }}}RME

// {{{RME classifier 'Option'

// {{{RME classAttribute 'CONFIGURABLE_OPTION'
const unsigned int Configurable::Option::CONFIGURABLE_OPTION( 2 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
Configurable::Option::Option( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
Configurable::Option::~Option( void )
{
}
// }}}RME

// {{{RME operation 'getType()'
ClassType Configurable::Option::getType( void ) const
{
	// {{{USR
	return CONFIGURABLE_OPTION;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool Configurable::Option::isType( ClassType type ) const
{
	// {{{USR
	return (type == CONFIGURABLE_OPTION)?true:Serializable::isType(type);
	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
Configurable::~Configurable( void )
{
}
// }}}RME

// {{{RME operation 'getOption(ClassType)'
Configurable::Option * Configurable::getOption( ClassType optionType ) const
{
	// {{{USR
	return 0;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setOption(Configurable::Option *)'
bool Configurable::setOption( Option * option )
{
	// {{{USR
	return false;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Option' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
