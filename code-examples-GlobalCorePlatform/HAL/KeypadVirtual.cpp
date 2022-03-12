// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Keypad::KeypadVirtual'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "KeypadVirtual.h"
#endif

#include <hal.h>
#include <KeypadVirtual.h>
#include <KeypadVirtualEvent.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'RowColumn' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classifier 'RowColumn'

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
KeypadVirtual::RowColumn::~RowColumn( void )
{
}
// }}}RME

// {{{RME operation 'RowColumn()'
KeypadVirtual::RowColumn::RowColumn( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_row(0), m_column(0), m_flag(false)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
KeypadVirtual::~KeypadVirtual( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'RowColumn' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
