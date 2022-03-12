// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::genericTests::genericTestsMOTICs::genericTestsPGAM::genericTestPGAM'

#ifndef genericTestPGAM_H
#define genericTestPGAM_H

#ifdef PRAGMA
#pragma interface "genericTestPGAM.h"
#endif

#include <HALtestLib_win32.h>
#include <Connection.h>
#include <GPSEventHandlerBase.h>
#include <genericTestBase.h>
class IOVirtual;
class InstantGPS_mg4100;
class PGAMUserSupplieddata;
class SCharArray;
class TimerVirtual;
class targetConfigBase;
class targetConfigPGAM;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class genericTestPGAM : public genericTestBase, public GPSEventHandlerBase
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
	// {{{RME classAttribute 'm_targetConfigPgam'
	targetConfigBase * m_targetConfigPgam;
	// }}}RME

public:
	// {{{RME operation 'execute(genericTestBase::testConfig *)'
	genericTestBase::testResult * execute( genericTestBase::testConfig * config = 0 );
	// }}}RME
	// {{{RME operation 'init(genericTestBase::initConfig *)'
	genericTestBase::initResult * init( genericTestBase::initConfig * config = 0 );
	// }}}RME
	// {{{RME operation 'eventOccurred(const EventBase * const)'
	void eventOccurred( const EventBase * const event );
	// }}}RME
	// {{{RME operation 'processEvent(unsigned int,void *,int)'
	void processEvent( unsigned int eventcode, void * optionaldata, int optionalarg );
	// }}}RME
	// {{{RME operation 'genericTestPGAM(targetConfigBase *)'
	genericTestPGAM( targetConfigBase * hwPlatformConfig );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* genericTestPGAM_H */

// }}}RME
