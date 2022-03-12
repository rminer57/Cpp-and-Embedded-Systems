// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Configurable RF Deck::Options::RFVirtualProfileOption'

#ifndef RFVirtualProfileOption_H
#define RFVirtualProfileOption_H

#ifdef PRAGMA
#pragma interface "RFVirtualProfileOption.h"
#endif

#include <hal.h>
#include <ConfigurableRFVirtual.h>
class Profile;
class RFVirtualProfile;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class RFVirtualProfileOption : public ConfigurableRFVirtual::RFVirtualOption
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

protected:
	// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
	// {{{USR
	SERIAL_CLASS_CONFIG_RESIZE();
	// }}}USR
	// }}}RME

private:
	// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

public:
	// {{{RME classAttribute 'RF_VIRTUAL_PROFILE_OPTION'
	static const unsigned int RF_VIRTUAL_PROFILE_OPTION;
	// }}}RME

protected:
	// {{{RME associationEnd 'm_profile'
	Profile * m_profile;
	// }}}RME

public:
	// {{{RME operation 'getType()'
	virtual ClassType getType( void ) const;
	// }}}RME
	// {{{RME operation 'isType(ClassType)'
	virtual bool isType( ClassType type ) const;
	// }}}RME

protected:
	// {{{RME operation 'serialize(SerialObject*)'
	virtual void serialize( SerialObject * so );
	// }}}RME
	// {{{RME operation 'deserialize(SerialObject*)'
	virtual void deserialize( SerialObject * so );
	// }}}RME

public:
	// {{{RME operation 'getProfile()'
	virtual Profile * getProfile( void );
	// }}}RME
	// {{{RME operation 'setProfile(Profile*)'
	void setProfile( Profile * profile );
	// }}}RME
	// {{{RME operation 'RFVirtualProfileOption()'
	RFVirtualProfileOption( void );
	// }}}RME
	// {{{RME operation 'RFVirtualProfileOption(Profile*)'
	RFVirtualProfileOption( Profile * profile );
	// }}}RME
	// {{{RME operation 'RFVirtualProfileOption(SerialObject*)'
	RFVirtualProfileOption( SerialObject * so );
	// }}}RME
	// {{{RME operation '~RFVirtualProfileOption()'
	virtual ~RFVirtualProfileOption( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* RFVirtualProfileOption_H */

// }}}RME
