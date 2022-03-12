// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoOPTCTRL'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "MakoOPTCTRL.h"
#endif

#include <HALtestLib_win32.h>
#include <MakoOPTCTRL.h>
#include <Mako.h>
#include <MakoPrivateBitfieldsReg4.h>
#include <bitfield.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'MakoOPTCTRL(Mako *,uint32_t,uint32_t,uint32_t)'
MakoOPTCTRL::MakoOPTCTRL( Mako * parent, uint32_t opt1init, uint32_t opt2init, uint32_t opt3init )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_MakoParent( parent )
	// }}}USR
	// }}}RME
{
	// {{{USR
	     uint32_t wrData = 0;

	  
	     // *************************************************************************************
	     // initialize option select control register 1
	     // *************************************************************************************
	     wrData = opt1init; // write the data into the field. bits D23 to D0 contain the settings

	     // program the address of option control register 1 into bits D27 to D24
	     setBitField( &wrData, MAKO_OPT_CTRL_BITFIELD, MAKO_OPT_CTRL1_ADDRESS);

	     // write data to the OPT CTRL REGISTER subcomponent
	     m_MakoParent->wrRegister( OPT_CTRL_REGISTER_ADDR, wrData );

	     // *************************************************************************************
	     // initialize option select control register 2
	     // *************************************************************************************
	     wrData = opt2init; // write the data into the field. bits D23 to D0 contain the settings

	     // program the address of option control register 2 into bits D27 to D24
	     setBitField( &wrData, MAKO_OPT_CTRL_BITFIELD, MAKO_OPT_CTRL2_ADDRESS);

	     // write data to the OPT CTRL REGISTER subcomponent
	     m_MakoParent->wrRegister( OPT_CTRL_REGISTER_ADDR, wrData );

	  
	   // *************************************************************************************
	     // initialize option select control register 3
	     // *************************************************************************************
	     wrData = opt3init; // write the data into the field. bits D23 to D0 contain the settings

	     // program the address of option control register 2 into bits D27 to D24
	     setBitField( &wrData, MAKO_OPT_CTRL_BITFIELD, MAKO_OPT_CTRL3_ADDRESS);

	     // write data to the OPT CTRL REGISTER subcomponent
	     m_MakoParent->wrRegister( OPT_CTRL_REGISTER_ADDR, wrData );
	// }}}USR
}
// }}}RME

// {{{RME operation 'gpioSetConfigB(uint32_t)'
void MakoOPTCTRL::gpioSetConfigB( uint32_t config )
{
	// {{{USR
	     uint32_t wrData = 0;

	     // *************************************************************************************
	     // initialize option select control register OPT_CONFIGB
	     // *************************************************************************************
	     wrData = 0; 

	     // program the address of option control into bits D27 to D24
	     setBitField( &wrData, MAKO_OPT_CTRL_BITFIELD, MAKO_OPT_CTRL2_ADDRESS);

	     // program bits D6 to D4 with new configuration. 
	     setBitField( &wrData, MAKO_OPT_CONFIGB_BITFIELD, config );

	     // write data to the OPT CTRL REGISTER subcomponent
	     m_MakoParent->wrRegister( OPT_CTRL_REGISTER_ADDR, wrData );
	  
	  
	// }}}USR
}
// }}}RME

// {{{RME operation '~MakoOPTCTRL()'
MakoOPTCTRL::~MakoOPTCTRL( void )
{
	// {{{USR

		// write to the Mako object m_OPTResourceAvailable attribute to
		// deallocate the resource so that its again available.
		m_MakoParent->m_ResourceAvailableOPT = true;
	// }}}USR
}
// }}}RME

// {{{RME operation 'gpioSetDir(uint32_t)'
void MakoOPTCTRL::gpioSetDir( uint32_t config )
{
	// {{{USR
	     uint32_t wrData = 0;
	  
	 
	     // *************************************************************************************
	     // configure GPIO direction by writing to OPT_CTRL2[11:8] bits of control register 2
	     // *************************************************************************************
	     wrData = 0; 

	     // program the address of option control into bits D27 to D24
	     setBitField( &wrData, MAKO_OPT_CTRL_BITFIELD, MAKO_OPT_CTRL2_ADDRESS);

	     // program bits D11 to D8 with the GPIO directions. 
	     setBitField( &wrData, MAKO_GPIO_DIR_BITFIELD, config );

	     // write data to the OPT CTRL REGISTER subcomponent
	     m_MakoParent->wrRegister( OPT_CTRL_REGISTER_ADDR, wrData );
	  
	// }}}USR
}
// }}}RME

// {{{RME operation 'gpioSetConfigA(uint32_t)'
void MakoOPTCTRL::gpioSetConfigA( uint32_t config )
{
	// {{{USR
	     uint32_t wrData = 0;
	  
	     // *************************************************************************************
	     // initialize option select control register OPT_CONFIGA
	     // *************************************************************************************
	     wrData = 0; 

	     // program the address of option control into bits D27 to D24
	     setBitField( &wrData, MAKO_OPT_CTRL_BITFIELD, MAKO_OPT_CTRL2_ADDRESS);

	       // program bits D6 to D4 with new configuration. 
	     setBitField( &wrData, MAKO_OPT_CONFIGA_BITFIELD, config );

	     // write data to the OPT CTRL REGISTER subcomponent
	     m_MakoParent->wrRegister( OPT_CTRL_REGISTER_ADDR, wrData );
	  
	  
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
