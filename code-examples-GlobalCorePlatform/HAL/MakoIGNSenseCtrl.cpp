// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoIGNSenseCtrl'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "MakoIGNSenseCtrl.h"
#endif

#include <HALtestLib_win32.h>
#include <MakoIGNSenseCtrl.h>
#include <Mako.h>
#include <MakoPrivateBitfieldsReg2.h>
#include <bitfield.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'MakoIGNSenseCtrl(Mako *,unsigned int)'
MakoIGNSenseCtrl::MakoIGNSenseCtrl( Mako * parent, unsigned int ignmode )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_MakoParent( parent )
	// }}}USR
	// }}}RME
{
	// {{{USR
	     setIGNmode(ignmode);
	// }}}USR
}
// }}}RME

// {{{RME operation '~MakoIGNSenseCtrl()'
MakoIGNSenseCtrl::~MakoIGNSenseCtrl( void )
{
	// {{{USR

		// deallocate the resource so that its again available.
		m_MakoParent->m_ResourceAvailableIGNSenseCtrl = true;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setIGNmode(int)'
void MakoIGNSenseCtrl::setIGNmode( int ignmode )
{
	// {{{USR
	 
	    // valid values are 0 to 3, anything greater means client code has
	    // a bug, so reject the setting
	    
	    if( ignmode <= MAKO_IGN_MODE_MAXVAL )
	    {              
	    	         
	      // write the new ignition mode provided by client.
		  setBitField( &m_MakoParent->m_imageArrayIDCtrlReg[MAKO_IGNSENSE_REGISTER_ADDRESS], MAKO_ID_CTRL_IGN_MODE_BITFIELD, ignmode );

		  // select the address of the Mako register
		  // and call wrRegister to send it out.
		  m_MakoParent->wrRegister( MAKO_IGNSENSE_REGISTER_ADDRESS, m_MakoParent->m_imageArrayIDCtrlReg[MAKO_IGNSENSE_REGISTER_ADDRESS]); 
	    }
	// }}}USR
}
// }}}RME

// {{{RME operation 'getIGNpinState()'
uint32_t MakoIGNSenseCtrl::getIGNpinState( void )
{
	// {{{USR
		uint32_t rdData = 0;
	 
		// read the Mako register 
		rdData = m_MakoParent->rdRegister( MAKO_IGNSENSE_REGISTER_ADDRESS, rdData);
	         
	    // extract the bits of interest
	    rdData = getBitField( &rdData, MAKO_ID_CTRL_IGN_PIN_BITFIELD);
	    
	    return rdData;
	// }}}USR
}
// }}}RME

// {{{RME operation 'receive()'
unsigned int MakoIGNSenseCtrl::receive( void )
{
	// {{{USR

	return getIGNpinState();
	// }}}USR
}
// }}}RME

// {{{RME operation 'send(unsigned int)'
void MakoIGNSenseCtrl::send( unsigned int data )
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
