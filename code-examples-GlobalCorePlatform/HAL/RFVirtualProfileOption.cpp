// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Configurable RF Deck::Options::RFVirtualProfileOption'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "RFVirtualProfileOption.h"
#endif

#include <hal.h>
#include <RFVirtualProfileOption.h>
#include <Profile.h>
#include <RFVirtualProfile.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
SERIAL_CLASS_INITIALIZE(RFVirtualProfileOption);

// }}}USR
// }}}RME

// {{{RME classAttribute 'RF_VIRTUAL_PROFILE_OPTION'
const unsigned int RFVirtualProfileOption::RF_VIRTUAL_PROFILE_OPTION( 4103 );
// }}}RME

// {{{RME operation 'getType()'
ClassType RFVirtualProfileOption::getType( void ) const
{
	// {{{USR
	return RF_VIRTUAL_PROFILE_OPTION;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool RFVirtualProfileOption::isType( ClassType type ) const
{
	// {{{USR
	return (type == RF_VIRTUAL_PROFILE_OPTION)?true:RFVirtualOption::isType(type);
	// }}}USR
}
// }}}RME

// {{{RME operation 'serialize(SerialObject*)'
void RFVirtualProfileOption::serialize( SerialObject * so )
{
	// {{{USR
	bool childPresent = (m_profile != 0);

	*so << childPresent;

	if (childPresent)
	   {
	   *so << m_profile;
	   }

	RFVirtualOption::serialize(so);

	// }}}USR
}
// }}}RME

// {{{RME operation 'deserialize(SerialObject*)'
void RFVirtualProfileOption::deserialize( SerialObject * so )
{
	// {{{USR
	bool childPresent;
	unsigned int type;

	*so >> childPresent;

	// Verify a profile is contained:
	if (childPresent)
	   {
	   m_profile = new RFVirtualProfile(so);
	   }
	else
	   {
	   m_profile = 0;
	   }

	RFVirtualOption::deserialize(so);
	// }}}USR
}
// }}}RME

// {{{RME operation 'getProfile()'
Profile * RFVirtualProfileOption::getProfile( void )
{
	// {{{USR
	Profile *temp = m_profile;
	m_profile = 0;
	return temp;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setProfile(Profile*)'
void RFVirtualProfileOption::setProfile( Profile * profile )
{
	// {{{USR
	if (m_profile != 0)
	   {
	   delete m_profile;
	   }

	m_profile = profile;
	// }}}USR
}
// }}}RME

// {{{RME operation 'RFVirtualProfileOption()'
RFVirtualProfileOption::RFVirtualProfileOption( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_profile(0)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'RFVirtualProfileOption(Profile*)'
RFVirtualProfileOption::RFVirtualProfileOption( Profile * profile )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_profile(profile)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'RFVirtualProfileOption(SerialObject*)'
RFVirtualProfileOption::RFVirtualProfileOption( SerialObject * so )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	deserialize(so);
	// }}}USR
}
// }}}RME

// {{{RME operation '~RFVirtualProfileOption()'
RFVirtualProfileOption::~RFVirtualProfileOption( void )
{
	// {{{USR
	delete m_profile;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
