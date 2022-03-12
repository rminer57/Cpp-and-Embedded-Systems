// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::genericTests::genericTestsMenuDriven::genericTestMenu'

#ifndef genericTestMenu_H
#define genericTestMenu_H

#ifdef PRAGMA
#pragma interface "genericTestMenu.h"
#endif

#include <HALtestLib_win32.h>
#include <IOVirtualSerial.h>
#include <genericTestBase.h>
class targetConfigBase;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
//#include <genericTestHPD.h>
//#include <genericTestMakoUSB.h>
//#include <genericTestPGAM.h>

// }}}USR
// }}}RME
// {{{RME classifier 'menuItem' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class genericTestMenu : public genericTestBase
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
	// {{{RME classifier 'menuItem'
	class menuItem
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
		// {{{RME classAttribute 'm_displayText'
		char * m_displayText;
		// }}}RME
		// {{{RME classAttribute 'm_keyword'
		char * m_keyword;
		// }}}RME
		// {{{RME classAttribute 'm_testToExecute'
		genericTestBase * m_testToExecute;
		// }}}RME
		// {{{RME classAttribute 'm_passFail'
		int m_passFail;
		// }}}RME
		// {{{RME operation 'menuItem(char *,char *,genericTestBase *)'
		menuItem( char * keyword, char * displayText, genericTestBase * testToExecute );
		// }}}RME
		// {{{RME operation '~menuItem()'
		~menuItem( void );
		// }}}RME
		// {{{RME operation 'executeIfEQKeyword(char *)'
		int executeIfEQKeyword( char * entry );
		// }}}RME
	};
	// }}}RME

protected:
	// {{{RME classAttribute 'm_signonMessage'
	char * m_signonMessage;
	// }}}RME
	// {{{RME classAttribute 'm_prompt'
	char * m_prompt;
	// }}}RME
	// {{{RME classAttribute 'm_menuItemArray'
	menuItem * * m_menuItemArray;
	// }}}RME
	// {{{RME classAttribute 'm_defaultMenuItemArray'
	menuItem * * m_defaultMenuItemArray;
	// }}}RME
	// {{{RME classAttribute 'm_menuItemArrayLen'
	int m_menuItemArrayLen;
	// }}}RME

public:
	// {{{RME classAttribute 'm_inputStream'
	IOVirtualSerial * m_inputStream;
	// }}}RME
	// {{{RME classAttribute 'm_outputStream'
	IOVirtualSerial * m_outputStream;
	// }}}RME
	// {{{RME operation 'init(genericTestBase::initConfig *)'
	genericTestBase::initResult * init( genericTestBase::initConfig * config );
	// }}}RME
	// {{{RME operation 'execute(genericTestBase::testConfig *)'
	genericTestBase::testResult * execute( genericTestBase::testConfig * config = 0 );
	// }}}RME
	// {{{RME operation 'genericTestMenu(menuItem **,int)'
	genericTestMenu( menuItem * * menuItemArray, int menuItemArrayLen );
	// }}}RME
	// {{{RME operation 'genericTestMenu()'
	genericTestMenu( void );
	// }}}RME
	// {{{RME operation 'defineCustomSignonMsg(char *)'
	void defineCustomSignonMsg( char * string );
	// }}}RME
	// {{{RME operation 'wrStringToOutputStream(char *)'
	void wrStringToOutputStream( char * string );
	// }}}RME

protected:
	// {{{RME operation 'commonInit(genericTestMenu::menuItem **,int)'
	void commonInit( menuItem * * menuItemArray, int menuItemArrayLen );
	// }}}RME

public:
	// {{{RME operation '~genericTestMenu()'
	~genericTestMenu( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'menuItem' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* genericTestMenu_H */

// }}}RME
