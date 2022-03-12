// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoIntrCtrl'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "MakoIntrCtrl.h"
#endif

#include <HALtestLib_win32.h>
#include <MakoIntrCtrl.h>
#include <Mako.h>
#include <MakoPrivateBitfieldsReg2.h>
#include <bitfield.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'MakoIntrCtrl(Mako *,uint32_t)'
MakoIntrCtrl::MakoIntrCtrl( Mako * parent, uint32_t reginit )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_MakoParent( parent )
	// }}}USR
	// }}}RME
{
	// {{{USR
	 
	 wrIntrRegister(reginit);
	// }}}USR
}
// }}}RME

// {{{RME operation '~MakoIntrCtrl()'
MakoIntrCtrl::~MakoIntrCtrl( void )
{
	// {{{USR

		// deallocate the resource so that its again available.
		m_MakoParent->m_ResourceAvailableIntrCtrl = true;
	// }}}USR
}
// }}}RME

// {{{RME operation 'rdIntrRegister()'
uint32_t MakoIntrCtrl::rdIntrRegister( void )
{
	// {{{USR
	 	uint32_t rdData = 0;
	         
	    rdData = m_MakoParent->rdRegister( MAKO_ID_CTRL_REGISTER_ADDR, rdData);

	    // update image
	    m_MakoParent->m_imageArrayIDCtrlReg[MAKO_INT_REGISTER_ADDRESS] = rdData;
		
	    return rdData;
	// }}}USR
}
// }}}RME

// {{{RME operation 'wrIntrRegister(uint32_t)'
void MakoIntrCtrl::wrIntrRegister( uint32_t data )
{
	// {{{USR
	 	uint32_t wrData = 0;
	         
	    // save the init value provided by client.
		wrData = data;

		// select the address of the interrupt settings register
		// and call wrRegister to send it out.
		m_MakoParent->wrRegister( MAKO_ID_CTRL_REGISTER_ADDR, wrData );

	    m_MakoParent->m_imageArrayIDCtrlReg[MAKO_INT_REGISTER_ADDRESS] = wrData; 
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
