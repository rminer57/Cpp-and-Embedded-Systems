// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Keypad::KeypadVirtual'

#ifndef KeypadVirtual_H
#define KeypadVirtual_H

#ifdef PRAGMA
#pragma interface "KeypadVirtual.h"
#endif

#include <hal.h>
#include <NotifierBase.h>
class KeypadVirtualEvent;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'RowColumn' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class KeypadVirtual : public NotifierBase
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
	// {{{RME classifier 'RowColumn'
	class RowColumn
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
		// {{{RME classAttribute 'm_row'
		unsigned int m_row;
		// }}}RME
		// {{{RME classAttribute 'm_column'
		unsigned int m_column;
		// }}}RME
		// {{{RME classAttribute 'm_flag'
		bool m_flag;
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
		virtual ~RowColumn( void );
		// }}}RME
		// {{{RME operation 'RowColumn()'
		RowColumn( void );
		// }}}RME
	};
	// }}}RME

protected:
	// {{{RME associationEnd 'm_rowCol'
	RowColumn m_rowCol;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~KeypadVirtual( void );
	// }}}RME
	// {{{RME operation 'receive()'
	virtual RowColumn & receive( void ) = 0;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'RowColumn' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* KeypadVirtual_H */

// }}}RME
