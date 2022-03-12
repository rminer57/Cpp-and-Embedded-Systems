// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::LAN::Ethernet::Smsc::LAN91C96I::Lan91c96i'

#ifndef Lan91c96i_H
#define Lan91c96i_H

#ifdef PRAGMA
#pragma interface "Lan91c96i.h"
#endif

#include <serial_comp.h>
#include <IOVirtualSerial.h>
#include <Lan91c96iCommon.h>
class Configurable;
class Lan91c96iBitFields;
class Lan91c96iConfig;
class Lan91c96iIntSource;
class SCharArray;
class peripheral_access;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR


// }}}USR
// }}}RME

class Lan91c96i : public IOVirtualSerial, public Lan91c96iCommon
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
	// {{{RME classAttribute 'MAX_FRAME_LENGTH'
	static const unsigned int MAX_FRAME_LENGTH;
	// }}}RME

public:
	// {{{RME associationEnd 'm_config'
	Lan91c96iConfig * m_config;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	Lan91c96i( void );
	// }}}RME
	// {{{RME operation 'Lan91c96i(Lan91c96iConfig*)'
	Lan91c96i( Lan91c96iConfig * config );
	// }}}RME
	// {{{RME operation 'activate()'
	virtual bool activate( void );
	// }}}RME
	// {{{RME operation 'send(Array*)'
	bool send( Array * payLoad );
	// }}}RME
	// {{{RME operation 'receive()'
	Array * receive( void );
	// }}}RME
	// {{{RME operation 'getOption(ClassType)'
	virtual Configurable::Option * getOption( ClassType optionType ) const;
	// }}}RME
	// {{{RME operation 'getStatus()'
	virtual Connection::Status * getStatus( void );
	// }}}RME
	// {{{RME operation 'setOption(Configurable::Option *)'
	virtual bool setOption( Configurable::Option * option );
	// }}}RME
	// {{{RME operation 'deactivate()'
	virtual bool deactivate( void );
	// }}}RME
	// {{{RME operation '~Lan91c96i()'
	~Lan91c96i( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Lan91c96i_H */

// }}}RME
