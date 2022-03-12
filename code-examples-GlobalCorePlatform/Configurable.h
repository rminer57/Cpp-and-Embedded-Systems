// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Connections::Configurable'

#ifndef Configurable_H
#define Configurable_H

#ifdef PRAGMA
#pragma interface "Configurable.h"
#endif

#include <conn.h>
#include <Serializable.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Option' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class Configurable
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
	// {{{RME classifier 'Option'
	class Option : public Serializable
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
		// {{{RME classAttribute 'CONFIGURABLE_OPTION'
		static const unsigned int CONFIGURABLE_OPTION;
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
		Option( void );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
		virtual ~Option( void );
		// }}}RME
		// {{{RME operation 'getType()'
		virtual ClassType getType( void ) const;
		// }}}RME
		// {{{RME operation 'isType(ClassType)'
		virtual bool isType( ClassType type ) const;
		// }}}RME
	};
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~Configurable( void );
	// }}}RME
	// {{{RME operation 'getOption(ClassType)'
	virtual Option * getOption( ClassType optionType ) const;
	// }}}RME
	// {{{RME operation 'setOption(Configurable::Option *)'
	virtual bool setOption( Option * option );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Option' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Configurable_H */

// }}}RME
