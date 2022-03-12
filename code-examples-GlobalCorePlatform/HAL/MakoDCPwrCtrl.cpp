// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoDCPwrCtrl'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "MakoDCPwrCtrl.h"
#endif

#include <HALtestLib_win32.h>
#include <MakoDCPwrCtrl.h>
#include <Mako.h>
#include <MakoPrivateBitfieldsReg1.h>
#include <MakoPrivateBitfieldsReg2.h>
#include <bitfield.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'MakoDCPwrCtrl(Mako *,unsigned int)'
MakoDCPwrCtrl::MakoDCPwrCtrl( Mako * parent, unsigned int reginit )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_MakoParent( parent )
	// }}}USR
	// }}}RME
{
	// {{{USR
	  	uint32_t wrData = 0;
	         
	    // save the DC REG DAT init value provided by client. D27 - D0 are used.
		wrData = reginit;

	    // according to Mako spec, CHCK bit D22 of the ID/Control register MUST always be set
	    // prior to making spi writes to the DC Regulator register, in order to protect the radio
	    // against accidental writes to the DC Regulator register, thereby possibly setting the power
	    // in a way that might damage the radio.
	    setCHCKbit(); 

		// select the address of the Mako DC Regulator settings register
		// and call wrRegister to send it out.
		m_MakoParent->wrRegister( MAKO_DCREG_REGISTER_ADDR, wrData );

	    // write the initial settings to the register image.
		m_MakoParent->m_imageDCRegulatorReg = wrData; 
	// }}}USR
}
// }}}RME

// {{{RME operation '~MakoDCPwrCtrl()'
MakoDCPwrCtrl::~MakoDCPwrCtrl( void )
{
	// {{{USR

		// deallocate the resource so that its again available.
		m_MakoParent->m_ResourceAvailableDCPwrCtrl = true;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setSwitcherFreq(int)'
void MakoDCPwrCtrl::setSwitcherFreq( int data )
{
	// {{{USR

	    // valid values are 0 to 7, anything greater means client code has
	    // a bug, so reject the setting
	    
	    if( data <= MAKO_DCREG_SW_CLKDIV_MAXVAL )
	    {  
	        // according to Mako spec, CHCK bit D22 of the ID/Control register MUST always be set
	        // prior to making spi writes to the DC Regulator register, in order to protect the radio
	        // against accidental writes to the DC Regulator register, thereby possibly setting the power
	        // in a way that might damage the radio.
	        setCHCKbit(); 
	            
	        // write the setting to the bitfield
		    setBitField( &m_MakoParent->m_imageDCRegulatorReg, MAKO_DCREG_SW_CLKDIV_BITFIELD, data );

		    // select the address of the Mako DC Regulator settings register
		    // and call wrRegister to send it out.
		    m_MakoParent->wrRegister( MAKO_DCREG_REGISTER_ADDR, m_MakoParent->m_imageDCRegulatorReg );


	        // clear the CHCK setting in the bitfield because hardware will do this also in the Mako IC
		    setBitField( &m_MakoParent->m_imageArrayIDCtrlReg[MAKO_CHCK_REGISTER_ADDRESS], MAKO_ID_CTRL_CHCK_BITFIELD, 0 );

		} 
	// }}}USR
}
// }}}RME

// {{{RME operation 'setCHCKbit()'
void MakoDCPwrCtrl::setCHCKbit( void )
{
	// {{{USR

	              
	    // write the setting to the bitfield
		setBitField( &m_MakoParent->m_imageArrayIDCtrlReg[MAKO_CHCK_REGISTER_ADDRESS], MAKO_ID_CTRL_CHCK_BITFIELD, 1 );

		// select the address of the Mako register containing the CHCK bit
		// and call wrRegister to send it out.
		m_MakoParent->wrRegister( MAKO_CHCK_REGISTER_ADDRESS, m_MakoParent->m_imageArrayIDCtrlReg[MAKO_CHCK_REGISTER_ADDRESS] );





	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
