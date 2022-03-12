// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::TestSupportWin32::IOVirtualPinSimulation'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "IOVirtualPinSimulation.h"
#endif

#include <HALtestLib_win32.h>
#include <IOVirtualPinSimulation.h>
#include <SCharArray.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'IOVirtualPinSimulation_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
IOVirtualPinSimulation::IOVirtualPinSimulation( void )
{
}
// }}}RME

// {{{RME operation 'IOVirtualPinSimulation( IOVirtualPinSimulation::IOVirtualPinSimulation_t)'
IOVirtualPinSimulation::IOVirtualPinSimulation( IOVirtualPinSimulation_t whichPin )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR

	m_whichPin = whichPin;
	// }}}USR
}
// }}}RME

// {{{RME operation 'send(unsigned int)'
void IOVirtualPinSimulation::send( unsigned int data )
{
	// {{{USR
	char c;


	switch (data)
	{
	  // writing zero
	  case 0:

	  if(m_whichPin == PGAM_CSPIN)
	  {
	      IOVirtualSimBase::send("Please manually reset the PGAM using blue wire and hit any key when done\n");

	      c = IOVirtualSimBase::getch();

	      IOVirtualSimBase::send("thank you\n");    
	  }
	  else if(m_whichPin == MAKO_CSPIN)
	  {
	      IOVirtualSimBase::send("writing 0 mako cs pin: ");
	  }
	  else
	  {
	      IOVirtualSimBase::send("writing 0 to gpio pin: ");
	  }

	  break;


	  case 1:

	      IOVirtualSimBase::send("writing 1 to gpio pin: ");

	  break;


	      IOVirtualSimBase::send(data);
	      IOVirtualSimBase::sendENDL();
	};



	// }}}USR
}
// }}}RME

// {{{RME operation 'receive()'
unsigned int IOVirtualPinSimulation::receive( void )
{
	// {{{USR


	return 0;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'IOVirtualPinSimulation_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
