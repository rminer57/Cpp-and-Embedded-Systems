// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::abacusIII::abacusIII'

#ifndef abacusIII_H
#define abacusIII_H

#ifdef PRAGMA
#pragma interface "abacusIII.h"
#endif

#include <HALtestLib_win32.h>
#include <abacusTuningDefault.h>
#include <bbpControl.h>
#include <bitfield.h>
#include <frequencyConversionReference.h>
class Connection;
class SIntArray;
class abacusDefault;
class rfSpiBuffer;
class rf_audio_std_types;
class sequencerTimer;
class units;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
// image size in uint32_t
#define ABACUS_IMAGE_SIZE_32 9
#include <stdint.h>  


// }}}USR
// }}}RME

class abacusIII : public frequencyConversionReference, public bbpControl
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
	// {{{RME classAttribute 'spi'
	rfSpiBuffer * * spi;
	// }}}RME
	// {{{RME classAttribute 'defaultData'
	abacusDefault * defaultData;
	// }}}RME
	// {{{RME classAttribute 'hwFref'
	Integer hwFref;
	// }}}RME
	// {{{RME classAttribute 'swFref'
	Integer swFref;
	// }}}RME
	// {{{RME classAttribute 'lor'
	Integer lor;
	// }}}RME
	// {{{RME classAttribute 'm_connection'
	Connection * m_connection;
	// }}}RME

public:
	// {{{RME classAttribute 'm_powerUpStatus'
	int m_powerUpStatus;
	// }}}RME

private:
	// {{{RME classAttribute 'seqTimer'
	sequencerTimer * seqTimer;
	// }}}RME

public:
	// {{{RME classAttribute 'm_abacus3_blk'
	abacus3_blk_t * m_abacus3_blk;
	// }}}RME

private:
	// {{{RME classAttribute 'm_spi4wireEnabled'
	bool m_spi4wireEnabled;
	// }}}RME

public:
	// {{{RME associationEnd 'abacusTuningDefaults'
	abacusTuningDefault abacusTuningDefaults;
	// }}}RME
	// {{{RME operation 'abacusIII(abacusDefault*,rfSpiBuffer**,int,abacus3_blk_t *,sequencerTimer *,Connection *,bool)'
	abacusIII( abacusDefault * init, rfSpiBuffer * * spiBuffers, int numberOfRfStates, abacus3_blk_t * cpImagePtr = 0, sequencerTimer * thesequencerTimer = 0, Connection * conn = 0, bool EnableSpi4Wire = false );
	// }}}RME
	// {{{RME operation 'setLO(Integer,Integer)'
	virtual Integer setLO( Integer freq, Integer rfState );
	// }}}RME
	// {{{RME operation 'setRFState(Integer)'
	virtual Integer setRFState( Integer rfState );
	// }}}RME
	// {{{RME operation 'setBBPFrequency(Integer,Integer)'
	virtual Integer setBBPFrequency( Integer frequency, Integer rfState );
	// }}}RME
	// {{{RME operation 'initAbacusIII(abacusDefault*,rfSpiBuffer**,Integer)'
	void initAbacusIII( abacusDefault * init, rfSpiBuffer * * spiBuffers, Integer numberOfRfStates );
	// }}}RME
	// {{{RME operation 'autotune()'
	void autotune( void );
	// }}}RME
	// {{{RME operation 'wrRegister(unsigned short,unsigned short)'
	void wrRegister( unsigned short reg_no, unsigned short reg_data );
	// }}}RME
	// {{{RME operation 'rdRegister(unsigned short int)'
	unsigned short int rdRegister( unsigned short int reg_no );
	// }}}RME

private:
	// {{{RME operation 'delay_usec(int)'
	void delay_usec( int delayuSec );
	// }}}RME
	// {{{RME operation 'memcpy(void *,const void *,int)'
	void memcpy( void * dst, const void * src, int len );
	// }}}RME
	// {{{RME operation 'program()'
	void program( void );
	// }}}RME

public:
	// {{{RME operation 'spiReadEnable()'
	void spiReadEnable( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* abacusIII_H */

// }}}RME
