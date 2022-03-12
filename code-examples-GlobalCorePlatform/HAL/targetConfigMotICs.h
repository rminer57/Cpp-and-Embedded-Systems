// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::targetConfigObjects::configMotorola_ICs::targetConfigMotICs'

#ifndef targetConfigMotICs_H
#define targetConfigMotICs_H

#ifdef PRAGMA
#pragma interface "targetConfigMotICs.h"
#endif

#include <HALtestLib_win32.h>
#include <InstantGPS_mg4100.h>
#include <fractionalN.h>
#include <fractionalNDefault.h>
#include <targetConfigBase.h>
#include <tomahawk.h>
#include <tomahawkDefault.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class targetConfigMotICs : public targetConfigBase
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
	// {{{RME classAttribute 'm_PGAMdriver'
	InstantGPS_mg4100 * m_PGAMdriver;
	// }}}RME
	// {{{RME classAttribute 'm_resetPinPGAM'
	IOVirtual * m_resetPinPGAM;
	// }}}RME

private:
	// {{{RME classAttribute 'm_targetConfig'
	targetConfigBase * m_targetConfig;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	targetConfigMotICs( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~targetConfigMotICs( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	targetConfigMotICs( const targetConfigMotICs & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	targetConfigMotICs & operator=( const targetConfigMotICs & rtg_arg );
	// }}}RME
	// {{{RME operation 'targetConfigMotICs(targetConfigBase *)'
	targetConfigMotICs( targetConfigBase * targetConfig );
	// }}}RME
	// {{{RME operation 'init()'
	void init( void );
	// }}}RME
	// {{{RME operation 'initPGAM()'
	void initPGAM( void );
	// }}}RME
	// {{{RME operation 'processEvent(unsigned int,void *,int)'
	void processEvent( unsigned int eventcode, void * optionaldata, int optionalarg );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* targetConfigMotICs_H */

// }}}RME
