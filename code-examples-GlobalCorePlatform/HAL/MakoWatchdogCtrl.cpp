// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoWatchdogCtrl'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "MakoWatchdogCtrl.h"
#endif

#include <HALtestLib_win32.h>
#include <MakoWatchdogCtrl.h>
#include <Mako.h>
#include <MakoPrivateBitfieldsReg2.h>
#include <bitfield.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'MakoWatchdogCtrl(Mako *)'
MakoWatchdogCtrl::MakoWatchdogCtrl( Mako * parent )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_MakoParent( parent )
	// }}}USR
	// }}}RME
{
	// {{{USR
	  
	// }}}USR
}
// }}}RME

// {{{RME operation '~MakoWatchdogCtrl()'
MakoWatchdogCtrl::~MakoWatchdogCtrl( void )
{
	// {{{USR

		// deallocate the resource so that its again available.
		m_MakoParent->m_ResourceAvailableWatchdogCtrl = true;
	// }}}USR
}
// }}}RME

// {{{RME operation 'refresh()'
void MakoWatchdogCtrl::refresh( void )
{
	// {{{USR
		
	    // write 1 to refresh the watchdog timer.
		setBitField( &m_MakoParent->m_imageArrayIDCtrlReg[MAKO_WD_REGISTER_ADDRESS], MAKO_ID_CTRL_WD_TIC_BITFIELD, 1 );

		// select the address of the Mako DC Regulator settings register
		// and call wrRegister to send it out.
	    m_MakoParent->wrRegister(  MAKO_ID_CTRL_REGISTER_ADDR, m_MakoParent->m_imageArrayIDCtrlReg[MAKO_WD_REGISTER_ADDRESS] );
	 

	 


	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
