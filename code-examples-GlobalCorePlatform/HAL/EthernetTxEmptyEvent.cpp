// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::LAN::Ethernet::Smsc::LAN91C96I::EthernetTxEmptyEvent'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "EthernetTxEmptyEvent.h"
#endif

#include <serial_comp.h>
#include <EthernetTxEmptyEvent.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'ETHERNET_TX_EMPTY_EVENT'
const unsigned int EthernetTxEmptyEvent::ETHERNET_TX_EMPTY_EVENT( 351 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
EthernetTxEmptyEvent::~EthernetTxEmptyEvent( void )
{
}
// }}}RME

// {{{RME operation 'EthernetTxEmptyEvent()'
EthernetTxEmptyEvent::EthernetTxEmptyEvent( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	:EventBase(ETHERNET_TX_EMPTY_EVENT)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'getEvent()'
unsigned int EthernetTxEmptyEvent::getEvent( void ) const
{
	// {{{USR
	return ETHERNET_TX_EMPTY_EVENT;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool EthernetTxEmptyEvent::isType( ClassType type ) const
{
	// {{{USR
	return (type == ETHERNET_TX_EMPTY_EVENT ? true : EventBase::isType(type));
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
