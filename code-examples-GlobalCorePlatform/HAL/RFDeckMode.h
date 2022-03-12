// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Configurable RF Deck::Options::RFDeckMode'

#ifndef RFDeckMode_H
#define RFDeckMode_H

#ifdef PRAGMA
#pragma interface "RFDeckMode.h"
#endif

#include <hal.h>
#include <ConfigurableRFVirtual.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class RFDeckMode : public ConfigurableRFVirtual::RFVirtualOption
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

protected:
	// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
	// {{{USR
	SERIAL_CLASS_CONFIG();
	// }}}USR
	// }}}RME

private:
	// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

public:
	// {{{RME classAttribute 'RF_DECK_MODE'
	static const unsigned int RF_DECK_MODE;
	// }}}RME
	// {{{RME classAttribute 'M_CONTINUOUS'
	static const unsigned int M_CONTINUOUS;
	// }}}RME
	// {{{RME classAttribute 'M_TIME_DIVISION'
	static const unsigned int M_TIME_DIVISION;
	// }}}RME

private:
	// {{{RME classAttribute 'm_mode'
	unsigned int m_mode;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~RFDeckMode( void );
	// }}}RME
	// {{{RME operation 'getType()'
	virtual ClassType getType( void ) const;
	// }}}RME
	// {{{RME operation 'isType(ClassType)'
	virtual bool isType( ClassType type ) const;
	// }}}RME
	// {{{RME operation 'getMode()'
	unsigned int getMode( void ) const;
	// }}}RME

protected:
	// {{{RME operation 'serialize(SerialObject*)'
	virtual void serialize( SerialObject * so );
	// }}}RME
	// {{{RME operation 'deserialize(SerialObject*)'
	virtual void deserialize( SerialObject * so );
	// }}}RME

public:
	// {{{RME operation 'RFDeckMode(SerialObject*)'
	RFDeckMode( SerialObject * so );
	// }}}RME
	// {{{RME operation 'RFDeckMode(unsigned int)'
	RFDeckMode( unsigned int mode );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* RFDeckMode_H */

// }}}RME
