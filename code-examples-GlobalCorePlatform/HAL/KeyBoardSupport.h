// {{{RME classifier 'Logical View::UsbPrivate::UsbOsFacade::KeyBoardSupport::KeyBoardSupport'

#ifndef KeyBoardSupport_H
#define KeyBoardSupport_H

#ifdef PRAGMA
#pragma interface "KeyBoardSupport.h"
#endif

#include <usbimp.h>
class DataQueue;
class UsbHidKeyBoard;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class KeyBoardSupport
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
	// {{{RME associationEnd 'm_keyBoardRef'
	UsbHidKeyBoard * m_keyBoardRef;
	// }}}RME
	// {{{RME associationEnd 'm_buffer'
	DataQueue * m_buffer;
	// }}}RME
	// {{{RME operation 'KeyBoardSupport()'
	KeyBoardSupport( void );
	// }}}RME
	// {{{RME operation 'enqueueData(uint8_t)'
	bool enqueueData( uint8_t data );
	// }}}RME
	// {{{RME operation 'deQueueData()'
	uint8_t deQueueData( void );
	// }}}RME
	// {{{RME operation 'setKeyBoardRef(UsbHidKeyBoard*)'
	void setKeyBoardRef( UsbHidKeyBoard * kbdRef );
	// }}}RME
	// {{{RME operation '~KeyBoardSupport()'
	~KeyBoardSupport( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* KeyBoardSupport_H */

// }}}RME
