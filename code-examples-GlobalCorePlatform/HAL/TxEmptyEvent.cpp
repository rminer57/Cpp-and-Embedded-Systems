// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OMAP::Uart::Omap1610Uart::TxEmptyEvent'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "TxEmptyEvent.h"
#endif

#include <serial_comp.h>
#include <TxEmptyEvent.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'TX_EMPTY_EVENT'
const unsigned int TxEmptyEvent::TX_EMPTY_EVENT( 300 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
TxEmptyEvent::~TxEmptyEvent( void )
{
}
// }}}RME

// {{{RME operation 'TxEmptyEvent()'
TxEmptyEvent::TxEmptyEvent( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	:EventBase(TX_EMPTY_EVENT)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'getEvent()'
unsigned int TxEmptyEvent::getEvent( void ) const
{
	// {{{USR
	return TX_EMPTY_EVENT;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool TxEmptyEvent::isType( ClassType type ) const
{
	// {{{USR
	return (type == TX_EMPTY_EVENT ? true : EventBase::isType(type));

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
