// {{{RME classifier 'Logical View::HAL Instantiation::IO Devices::Logical::KeypadScanner::KeypadScanner'

#ifndef KeypadScanner_H
#define KeypadScanner_H

#ifdef PRAGMA
#pragma interface "KeypadScanner.h"
#endif

#include <iodev_comp.h>
#include <IOVirtual.h>
#include <KeypadVirtual.h>
#include <KeypadVirtualEvent.h>
#include <ListenerBase.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class KeypadScanner : public ListenerBase, public KeypadVirtual
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

protected:
	// {{{RME classAttribute 'm_numRows'
	unsigned int m_numRows;
	// }}}RME
	// {{{RME classAttribute 'm_numCols'
	unsigned int m_numCols;
	// }}}RME
	// {{{RME associationEnd 'm_rowArray'
	IOVirtual ** m_rowArray;
	// }}}RME
	// {{{RME associationEnd 'm_colArray'
	IOVirtual ** m_colArray;
	// }}}RME
	// {{{RME associationEnd 'm_eventPtr'
	KeypadVirtualEvent m_eventPtr;
	// }}}RME

public:
	// {{{RME operation 'KeypadScanner(unsigned int,unsigned int,IOVirtual**,IOVirtual**)'
	KeypadScanner( unsigned int numRows, unsigned int numCols, IOVirtual * * rowArrayPtr, IOVirtual * * colArrayPtr );
	// }}}RME
	// {{{RME operation 'receive()'
	virtual KeypadVirtual::RowColumn & receive( void );
	// }}}RME
	// {{{RME operation '~KeypadScanner()'
	~KeypadScanner( void );
	// }}}RME
	// {{{RME operation 'eventOccurred(const EventBase* const)'
	virtual void eventOccurred( const EventBase * const event );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* KeypadScanner_H */

// }}}RME
