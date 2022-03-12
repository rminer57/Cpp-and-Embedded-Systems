// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::genericTests::genericTestBase'

#ifndef genericTestBase_H
#define genericTestBase_H

#ifdef PRAGMA
#pragma interface "genericTestBase.h"
#endif

#include <HALtestLib_win32.h>
#include <Connection.h>
#include <ListenerBase.h>
#include <SCharArray.h>
#include <Sem.h>
#include <targetConfigBase.h>
class TimeSpec;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'genericTestEnum_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'testConfig' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'testResult' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'initConfig' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'initResult' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class genericTestBase : public ListenerBase
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
	// {{{RME classifier 'genericTestEnum_t'
	enum genericTestEnum_t
	{
		FAIL
	  , PASS
	  , RUN_ONCE
	  , STOP
	  , RUN_FOREVER
	  , TEST_PGAM
	  , TEST_MAKO_USB
	  , TEST_UARTS
	  , TEST_SEQUENCER
	  , TEST_ALL
	  , TSTOUTPUT_TO_FILE
	  , TSTOUTPUT_TO_STDIO
	  , TSTINPUT_FR_STDIN
	  , TSTINPUT_FR_FILE
	};
	// }}}RME

public:
	// {{{RME classifier 'testConfig'
	class testConfig
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
		// {{{RME classAttribute 'm_testConfig'
		testConfig * m_testConfig;
		// }}}RME
	};
	// }}}RME
	// {{{RME classifier 'testResult'
	class testResult
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
		// {{{RME classAttribute 'm_testResult'
		testResult * m_testResult;
		// }}}RME
	};
	// }}}RME
	// {{{RME classifier 'initConfig'
	class initConfig
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
		// {{{RME classAttribute 'm_initConfigList'
		initConfig * m_initConfigList;
		// }}}RME
		// {{{RME classAttribute 'm_targetConfig'
		targetConfigBase * m_targetConfig;
		// }}}RME
		// {{{RME operation 'init()'
		void init( void );
		// }}}RME
		// {{{RME operation 'initConfig(targetConfigBase *)'
		initConfig( targetConfigBase * targetConfig );
		// }}}RME
		// {{{RME operation 'addNewinitConfigToList()'
		void addNewinitConfigToList( void );
		// }}}RME
	};
	// }}}RME
	// {{{RME classifier 'initResult'
	class initResult
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
		// {{{RME classAttribute 'm_initResult'
		initResult * m_initResult;
		// }}}RME
	};
	// }}}RME
	// {{{RME classAttribute 'm_testResultAll'
	genericTestEnum_t m_testResultAll;
	// }}}RME

protected:
	// {{{RME classAttribute 'm_initConfig_ptr'
	initConfig * m_initConfig_ptr;
	// }}}RME

public:
	// {{{RME operation 'execute(testConfig *)'
	virtual testResult * execute( testConfig * config = 0 ) = 0;
	// }}}RME
	// {{{RME operation 'init(genericTestBase::initConfig *)'
	virtual initResult * init( initConfig * config = 0 ) = 0;
	// }}}RME
	// {{{RME operation 'eventOccurred(const EventBase * const)'
	void eventOccurred( const EventBase * const event );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'genericTestEnum_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'testConfig' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'testResult' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'initConfig' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'initResult' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* genericTestBase_H */

// }}}RME
