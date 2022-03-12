// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::genericTests::genericTestsMenuDriven::genericTestMenu'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "genericTestMenu.h"
#endif

#include <HALtestLib_win32.h>
#include <genericTestMenu.h>
#include <targetConfigBase.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
static char defaultPrompt[] = "(q to quit), enterCmd: ";
static char * defaultSignon = "***************************\nHAL Test Menu\n\n***************************\n";
// }}}USR
// }}}RME
// {{{RME classifier 'menuItem' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classifier 'menuItem'

// {{{RME operation 'menuItem(char *,char *,genericTestBase *)'
genericTestMenu::menuItem::menuItem( char * keyword, char * displayText, genericTestBase * testToExecute )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	    menuItem::m_keyword = keyword;

	    menuItem::m_displayText = displayText;

		menuItem::m_testToExecute = testToExecute;
	// }}}USR
}
// }}}RME

// {{{RME operation '~menuItem()'
genericTestMenu::menuItem::~menuItem( void )
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'executeIfEQKeyword(char *)'
int genericTestMenu::menuItem::executeIfEQKeyword( char * entry )
{
	// {{{USR
	  int retval = 1;
	  genericTestBase::testResult * testResultObj = 0;
	  //testResultObj->m_testResult

	  // compare user entry to the keyword. if equal, execute.
	  int i = 0;

	  // go through the whole string
	  while( m_keyword[i++] != 0 )
	  {
		 // check to see if keyword for this menu item 
		 // matches user input. If not, we're done.
	     if( m_keyword[i] != entry[i] )
		 {
		  // wrong command so return failure code.
		  retval = 0;
		  break;
		 }

	  }

	  if(retval != 0)
	  {

	   testResultObj = m_testToExecute->execute();

	   if(testResultObj == 0)
	   {
	       targetConfigBase::sendStringToStderr("Err02:executed test returned null object.\n\n");
	   }

	  }

	  return retval;
	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME operation 'init(genericTestBase::initConfig *)'
genericTestBase::initResult * genericTestMenu::init( genericTestBase::initConfig * config )
{
	// {{{USR

	if( config != 0)
	{
	  m_initConfig_ptr = config;

	  config->m_targetConfig->init();
	}

	return 0;

	// }}}USR
}
// }}}RME

// {{{RME operation 'execute(genericTestBase::testConfig *)'
genericTestBase::testResult * genericTestMenu::execute( genericTestBase::testConfig * config )
{
	// {{{USR
	    char * m_consoleInputArray = new char[80];

	    wrStringToOutputStream(m_signonMessage);

	    // *******************************************
	    // display the menus
	    // *******************************************
	    for(int i = 0; i < m_menuItemArrayLen; i++)
		{
	      wrStringToOutputStream(m_menuItemArray[i]->m_displayText);

		}
	    
		wrStringToOutputStream("\n");

	    // *******************************************
	    // loop on user input and process
	    // *******************************************
	   while(1)
	   {
	     int match = 0;

	     // ***********************************************
	     // display prompt message, user-defined or default
		 // ***********************************************
	     wrStringToOutputStream(m_prompt);

		 // **********************************************
		 //  get a line of input, or, return the exit char
		 // **********************************************
	     // cout << " Type a line terminated by carriage return\n>";
		 // c = cin.get(); // gets a character
		 //std::cin.getline( m_consoleInputArray, 80, '\n' );

		 if( m_consoleInputArray[0] == 'q' )
		 {
	        wrStringToOutputStream("\nuser aborted!\n"); 
			break;
		 }

		 // **********************************************
		 // process the user-input
		 // **********************************************
	     for(int i = 0; i < m_menuItemArrayLen; i++)
		 {
	        match |= m_menuItemArray[i]->executeIfEQKeyword(m_consoleInputArray);
		 }

		 if(match != 1)
		 {
	       wrStringToOutputStream("Err01:genericTestMenu:keyword-nomatch.\n\n");
		 }

	   }

	   delete [] m_consoleInputArray;

	   return 0;
	// }}}USR
}
// }}}RME

// {{{RME operation 'genericTestMenu(menuItem **,int)'
genericTestMenu::genericTestMenu( menuItem * * menuItemArray, int menuItemArrayLen )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	commonInit( menuItemArray, menuItemArrayLen);
	// }}}USR
}
// }}}RME

// {{{RME operation 'genericTestMenu()'
genericTestMenu::genericTestMenu( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	 // default menus - add more as needed.
	  #define NUMOFDEFAULTMENUS 3

	  m_defaultMenuItemArray = new genericTestMenu::menuItem *[NUMOFDEFAULTMENUS];
	  //m_defaultMenuItemArray[0] = new genericTestMenu::menuItem("hpd","hpd: generic HPD test\n", (genericTestBase *)new genericTestHPD() );
	  //m_defaultMenuItemArray[1] = new genericTestMenu::menuItem("ltd","ltd: LTD morphius Mako/USB test\n", (genericTestBase *)new genericTestMakoUSB() );
	  //m_defaultMenuItemArray[2] = new genericTestMenu::menuItem("pgam","pgam: PGAM test\n", (genericTestBase *)new genericTestPGAM() );

	  commonInit( m_defaultMenuItemArray, NUMOFDEFAULTMENUS);


	// }}}USR
}
// }}}RME

// {{{RME operation 'defineCustomSignonMsg(char *)'
void genericTestMenu::defineCustomSignonMsg( char * string )
{
	// {{{USR
	m_signonMessage = string;
	// }}}USR
}
// }}}RME

// {{{RME operation 'wrStringToOutputStream(char *)'
void genericTestMenu::wrStringToOutputStream( char * string )
{
	// {{{USR
		  int len = 0;
		  char * temp = 0;
		  temp = string;

		  while( *temp != 0) { len++; temp++; }

		  SCharArray * txBuffer = new SCharArray(len, string);

		  m_outputStream->send(txBuffer);
	// }}}USR
}
// }}}RME

// {{{RME operation 'commonInit(genericTestMenu::menuItem **,int)'
void genericTestMenu::commonInit( menuItem * * menuItemArray, int menuItemArrayLen )
{
	// {{{USR
	  m_signonMessage = defaultSignon;
	  m_prompt = defaultPrompt;

	  // set default streams - user can redefine
	  m_inputStream  = targetConfigBase::m_platform_stderr; 
	  m_outputStream = targetConfigBase::m_platform_stderr;

	  if( menuItemArray != 0 && menuItemArrayLen != 0 )
	  {
		  // make sure the number of menus is not excessively high.
		  if( menuItemArrayLen < 60 )
		  {
	          // save current size
			  m_menuItemArrayLen = menuItemArrayLen;

	          m_menuItemArray = new menuItem * [menuItemArrayLen];

			  // copy the menuItems
			  for(int i = 0; i < menuItemArrayLen; i++)
			  {
	            m_menuItemArray[i] = menuItemArray[i]; 
			  }
		  }
	  }
	// }}}USR
}
// }}}RME

// {{{RME operation '~genericTestMenu()'
genericTestMenu::~genericTestMenu( void )
{
	// {{{USR
	  delete [] m_menuItemArray;
	  delete m_defaultMenuItemArray;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'menuItem' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
