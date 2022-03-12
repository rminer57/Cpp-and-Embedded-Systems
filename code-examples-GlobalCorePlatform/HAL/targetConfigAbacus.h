// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::targetConfigObjects::configMotorola_ICs::targetConfigAbacus'

#ifndef targetConfigAbacus_H
#define targetConfigAbacus_H

#ifdef PRAGMA
#pragma interface "targetConfigAbacus.h"
#endif

#include <HALtestLib_win32.h>
#include <targetConfigBase.h>
class abacusDefault;
class abacusIII;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class targetConfigAbacus : public targetConfigBase
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
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	targetConfigAbacus( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~targetConfigAbacus( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	targetConfigAbacus( const targetConfigAbacus & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	targetConfigAbacus & operator=( const targetConfigAbacus & rtg_arg );
	// }}}RME
	// {{{RME operation 'init()'
	void init( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* targetConfigAbacus_H */

// }}}RME
