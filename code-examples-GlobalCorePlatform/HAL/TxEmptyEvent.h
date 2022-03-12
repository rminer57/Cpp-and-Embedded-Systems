// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OMAP::Uart::Omap1610Uart::TxEmptyEvent'

#ifndef TxEmptyEvent_H
#define TxEmptyEvent_H

#ifdef PRAGMA
#pragma interface "TxEmptyEvent.h"
#endif

#include <serial_comp.h>
#include <EventBase.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class TxEmptyEvent : public EventBase
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

protected:
	// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

private:
	// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

public:
	// {{{RME classAttribute 'TX_EMPTY_EVENT'
	static const unsigned int TX_EMPTY_EVENT;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~TxEmptyEvent( void );
	// }}}RME
	// {{{RME operation 'TxEmptyEvent()'
	TxEmptyEvent( void );
	// }}}RME
	// {{{RME operation 'getEvent()'
	virtual unsigned int getEvent( void ) const;
	// }}}RME
	// {{{RME operation 'isType(ClassType)'
	virtual bool isType( ClassType type ) const;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* TxEmptyEvent_H */

// }}}RME
