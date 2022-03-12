// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::trident::tridentOptions::tridentOptions'

#ifndef tridentOptions_H
#define tridentOptions_H

#ifdef PRAGMA
#pragma interface "tridentOptions.h"
#endif

#include <rf_sequencer_comp.h>
#include <Configurable.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class tridentOptions : public Configurable::Option
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
	// {{{RME classAttribute 'TRIDENT_OPTION'
	static unsigned int TRIDENT_OPTION;
	// }}}RME
	// {{{RME classAttribute 'm_setting'
	unsigned int m_setting;
	// }}}RME
	// {{{RME classAttribute 'm_registerID'
	unsigned int m_registerID;
	// }}}RME
	// {{{RME classAttribute 'm_rfState'
	unsigned int m_rfState;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	tridentOptions( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~tridentOptions( void );
	// }}}RME
	// {{{RME operation 'getType()'
	virtual ClassType getType( void ) const;
	// }}}RME
	// {{{RME operation 'isType(ClassType)'
	bool isType( ClassType type );
	// }}}RME
	// {{{RME operation 'tridentOptions(unsigned int,unsigned int,unsigned int)'
	tridentOptions( unsigned int setting, unsigned int registerID, unsigned int rfState );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* tridentOptions_H */

// }}}RME
