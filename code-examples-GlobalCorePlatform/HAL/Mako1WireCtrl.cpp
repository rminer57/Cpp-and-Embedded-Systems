// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::Mako1WireCtrl'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Mako1WireCtrl.h"
#endif

#include <HALtestLib_win32.h>
#include <Mako1WireCtrl.h>
#include <Mako.h>
#include <MakoPrivateBitfieldsReg2.h>
#include <bitfield.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'Mako1WireCtrl(Mako *)'
Mako1WireCtrl::Mako1WireCtrl( Mako * parent )
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

// {{{RME operation '~Mako1WireCtrl()'
Mako1WireCtrl::~Mako1WireCtrl( void )
{
	// {{{USR

		// deallocate the resource so that its again available.
		m_MakoParent->m_ResourceAvailable1Wire = true;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setStateOneWireEN2Bus(bool)'
void Mako1WireCtrl::setStateOneWireEN2Bus( bool state )
{
	// {{{USR

		              
	    // write the setting to the bitfield
		setBitField( &m_MakoParent->m_imageArrayIDCtrlReg[MAKO_1WIRE_REGISTER_ADDRESS], MAKO_ID_CTRL_ONE_WIRE_EN2_BITFIELD, state );

		// select the address of the Mako one wire settings register
		// and call wrRegister to send it out.
		m_MakoParent->wrRegister( MAKO_ID_CTRL_REGISTER_ADDR, m_MakoParent->m_imageArrayIDCtrlReg[MAKO_1WIRE_REGISTER_ADDRESS] );


	// }}}USR
}
// }}}RME

// {{{RME operation 'setStateBatBus(bool)'
void Mako1WireCtrl::setStateBatBus( bool state )
{
	// {{{USR
	    // write the setting to the bitfield
		setBitField( &m_MakoParent->m_imageArrayIDCtrlReg[MAKO_1WIRE_REGISTER_ADDRESS], MAKO_ID_CTRL_BAT_BUS_EN_BITFIELD, state );

		// select the address of the Mako one wire settings register
		// and call wrRegister to send it out.
		m_MakoParent->wrRegister( MAKO_ID_CTRL_REGISTER_ADDR, m_MakoParent->m_imageArrayIDCtrlReg[MAKO_1WIRE_REGISTER_ADDRESS] );
	              
		

	// }}}USR
}
// }}}RME

// {{{RME operation 'setStateOneWireEN1Bus(bool)'
void Mako1WireCtrl::setStateOneWireEN1Bus( bool state )
{
	// {{{USR
	    // write the setting to the bitfield
		setBitField( &m_MakoParent->m_imageArrayIDCtrlReg[MAKO_1WIRE_REGISTER_ADDRESS], MAKO_ID_CTRL_ONE_WIRE_EN1_BITFIELD, state );

		// select the address of the Mako one wire settings register
		// and call wrRegister to send it out.
		m_MakoParent->wrRegister( MAKO_ID_CTRL_REGISTER_ADDR, m_MakoParent->m_imageArrayIDCtrlReg[MAKO_1WIRE_REGISTER_ADDRESS] );

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
