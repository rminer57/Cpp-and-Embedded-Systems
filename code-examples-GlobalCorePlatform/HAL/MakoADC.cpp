// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoADC'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "MakoADC.h"
#endif

#include <HALtestLib_win32.h>
#include <MakoADC.h>
#include <Mako.h>
#include <MakoPrivateBitfieldsReg7.h>
#include <bitfield.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'MakoADC(Mako *,unsigned int,uint32_t)'
MakoADC::MakoADC( Mako * parent, unsigned int adcSelect, uint32_t adcConfig )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_MakoParent(parent), m_adcSelect( adcSelect )
	// }}}USR
	// }}}RME
{
	// {{{USR
	     uint32_t wrData = 0;

	     wrData = adcConfig;

	    // set selected A/D channel D27 - D24
	    setBitField( &wrData, MAKO_AD_CH_BITFIELD, adcSelect);

	    // set state of ADEN bit to enabled
	    setBitField( &wrData, MAKO_ADEN_BITFIELD, MAKO_AD_ENABLE);

	    // set state of MAKO_ASC bit, 0->1 rising edge starts conversion .
	    setBitField( &wrData, MAKO_ASC_BITFIELD, MAKO_ASC_STARTCONVERSION );

	    // write data to the ADC subcomponent
	    m_MakoParent->wrRegister( ADC_REGISTER_ADDR, wrData ); 

	// }}}USR
}
// }}}RME

// {{{RME operation 'send(unsigned int)'
void MakoADC::send( unsigned int data )
{
	// {{{USR

	 
	// }}}USR
}
// }}}RME

// {{{RME operation 'receive()'
unsigned int MakoADC::receive( void )
{
	// {{{USR
	  
	    unsigned int retval = 0; 
	    uint32_t tempData = 0;
	    uint32_t rdData = m_adcSelect<<MAKO_AD_CH_FIELD_LSBBIT_24;
	 
	    // *******************************
	    // read the A to D data.
	    // *******************************
	    rdData = m_MakoParent->rdRegister(ADC_REGISTER_ADDR, rdData);
	   
	    // extract the 10 bits of adc data    
	    rdData = getBitField( &rdData, MAKO_AD_DATA_BITFIELD);

	    // *********************************************
	    // start the next A to D conversion to save time
	    // *********************************************

	    // set state of MAKO_ASC bit, 0->1 rising edge starts conversion.
	    // start the conversion again, so that on the next receive call, valid
	    // data will be available w/o the need to wait for it.
	    setBitField( &tempData, MAKO_ASC_BITFIELD, MAKO_ASC_STARTCONVERSION );

		// Need to set ADEN bit every time need to trigger the ADC sampling.
	    // This is an undocumented problem with the Mako hardware
		setBitField( &tempData, MAKO_ADEN_BITFIELD, 1);

	    // write data to the ADC subcomponent
	    m_MakoParent->wrRegister( ADC_REGISTER_ADDR, tempData ); 

	    // shift the 10 bits of A_D data, returned from Mako in D13-D4, down to D9-D0
	    // also cast the uint32_t to an unsigned int.  This MAY result in a truncation of the
	    // upper 16 bits if an unsigned int is of size 16 bits on the target.  That is acceptable.
	    retval = (unsigned int) rdData >> 4;
	    retval &= 0x3FF;

	    return retval;
	// }}}USR
}
// }}}RME

// {{{RME operation '~MakoADC()'
MakoADC::~MakoADC( void )
{
	// {{{USR

	// write to the Mako object adc available array
	m_MakoParent->m_adcAvailable[m_adcSelect] = true;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setState(bool)'
void MakoADC::setState( bool state )
{
	// {{{USR
	    uint32_t wrData = 0;

	    // set selected AD channel D27 - D24
	    setBitField( &wrData, MAKO_AD_CH_BITFIELD, m_adcSelect);

	    // set state of ADEN bit
	    setBitField( &wrData, MAKO_ADEN_BITFIELD, state);

	    // write data to the ADC subcomponent, address 7
	    m_MakoParent->wrRegister( ADC_REGISTER_ADDR, wrData ); 
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
