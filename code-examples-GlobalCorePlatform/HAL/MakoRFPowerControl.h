// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoRFPowerControl'

#ifndef MakoRFPowerControl_H
#define MakoRFPowerControl_H

#ifdef PRAGMA
#pragma interface "MakoRFPowerControl.h"
#endif

#include <HALtestLib_win32.h>
#include <powerControl.h>
class Mako;
class MakoPrivate;
class MakoPrivateBitfieldsReg6;
class PowerConfiguration;
class bitfield;
class rfSpiBuffer;
class rf_audio_std_types;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class MakoRFPowerControl : public powerControl
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR
	friend class Mako;
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
	// {{{RME classAttribute 'm_numDACBuffers'
	unsigned int m_numDACBuffers;
	// }}}RME
	// {{{RME classAttribute 'm_dac3State'
	bool m_dac3State;
	// }}}RME
	// {{{RME associationEnd 'm_dacCommonBuffers'
	rfSpiBuffer ** m_dacCommonBuffers;
	// }}}RME
	// {{{RME associationEnd 'm_powerConfig'
	PowerConfiguration ** m_powerConfig;
	// }}}RME
	// {{{RME associationEnd 'm_dac3Buffer'
	rfSpiBuffer * m_dac3Buffer;
	// }}}RME

public:
	// {{{RME operation 'setRFState(Integer)'
	virtual Integer setRFState( Integer rfState );
	// }}}RME

protected:
	// {{{RME operation 'MakoRFPowerControl(PowerConfiguration**,rfSpiBuffer**,rfSpiBuffer*,unsigned int)'
	MakoRFPowerControl( PowerConfiguration * * dacConfig, rfSpiBuffer * * dacCommonBuffers, rfSpiBuffer * dac3Buffer, unsigned int numDACBuffers );
	// }}}RME

public:
	// {{{RME operation 'setPowerLevel(Integer,Integer)'
	virtual Integer setPowerLevel( Integer level, Integer rfState );
	// }}}RME
	// {{{RME operation 'replacePowerConfig(unsigned int,PowerConfiguration*)'
	bool replacePowerConfig( unsigned int level, PowerConfiguration * newPowerConfig );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* MakoRFPowerControl_H */

// }}}RME
