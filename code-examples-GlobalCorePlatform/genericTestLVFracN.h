// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::genericTests::genericTestsMOTICs::genericTestsLVFracN::genericTestLVFracN'

#ifndef genericTestLVFracN_H
#define genericTestLVFracN_H

#ifdef PRAGMA
#pragma interface "genericTestLVFracN.h"
#endif

#include <HALtestLib_win32.h>
#include <genericTestBase.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class genericTestLVFracN : public genericTestBase
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
	genericTestLVFracN( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~genericTestLVFracN( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	genericTestLVFracN( const genericTestLVFracN & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	genericTestLVFracN & operator=( const genericTestLVFracN & rtg_arg );
	// }}}RME
	// {{{RME operation 'execute(genericTestBase::testConfig *)'
	genericTestBase::testResult * execute( genericTestBase::testConfig * config = 0 );
	// }}}RME
	// {{{RME operation 'init(genericTestBase::initConfig *)'
	genericTestBase::initResult * init( genericTestBase::initConfig * config = 0 );
	// }}}RME
	// {{{RME operation 'oldTest()'
	void oldTest( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* genericTestLVFracN_H */

// }}}RME
