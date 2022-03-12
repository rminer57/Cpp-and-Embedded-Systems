// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::TestSupportWin32::IOVirtualPinSimulation'

#ifndef IOVirtualPinSimulation_H
#define IOVirtualPinSimulation_H

#ifdef PRAGMA
#pragma interface "IOVirtualPinSimulation.h"
#endif

#include <HALtestLib_win32.h>
#include <IOVirtual.h>
#include <IOVirtualSimBase.h>
#include <SIntArray.h>
class SCharArray;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'IOVirtualPinSimulation_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class IOVirtualPinSimulation : public IOVirtual, public IOVirtualSimBase
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
	// {{{RME classifier 'IOVirtualPinSimulation_t'
	enum IOVirtualPinSimulation_t
	{
		PGAM_CSPIN
	  , MAKO_CSPIN
	  , ABACUS_CSPIN
	  , TOMAHAWK_CSPIN
	  , FRACN_CSPIN
	};
	// }}}RME

private:
	// {{{RME classAttribute 'm_whichPin'
	IOVirtualPinSimulation_t m_whichPin;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	IOVirtualPinSimulation( void );
	// }}}RME
	// {{{RME operation 'IOVirtualPinSimulation( IOVirtualPinSimulation::IOVirtualPinSimulation_t)'
	IOVirtualPinSimulation( IOVirtualPinSimulation_t whichPin );
	// }}}RME
	// {{{RME operation 'send(unsigned int)'
	void send( unsigned int data );
	// }}}RME
	// {{{RME operation 'receive()'
	unsigned int receive( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'IOVirtualPinSimulation_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* IOVirtualPinSimulation_H */

// }}}RME
