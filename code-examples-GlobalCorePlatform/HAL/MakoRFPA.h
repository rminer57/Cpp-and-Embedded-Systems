// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoRFPA'

#ifndef MakoRFPA_H
#define MakoRFPA_H

#ifdef PRAGMA
#pragma interface "MakoRFPA.h"
#endif

#include <HALtestLib_win32.h>
#include <DACDriver.h>
#include <powerAmplifier.h>
class Mako;
class MakoPrivate;
class MakoPrivateBitfieldsReg6;
class bitfield;
class rfSpiBuffer;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class MakoRFPA : public powerAmplifier, public DACDriver
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
	// {{{RME classAttribute 'm_dacSelect'
	unsigned int m_dacSelect;
	// }}}RME
	// {{{RME classAttribute 'm_numDACBuffers'
	unsigned int m_numDACBuffers;
	// }}}RME
	// {{{RME associationEnd 'm_dacCommonBuffers'
	rfSpiBuffer ** m_dacCommonBuffers;
	// }}}RME

public:
	// {{{RME operation 'setRFState(Integer)'
	virtual Integer setRFState( Integer rfState );
	// }}}RME

protected:
	// {{{RME operation 'MakoRFPA(uint32_t  *,rfSpiBuffer**,unsigned int,unsigned int)'
	MakoRFPA( uint32_t * dacData, rfSpiBuffer * * dacBuffers, unsigned int dacSelect, unsigned int numDACBuffers );
	// }}}RME

public:
	// {{{RME operation 'setPA(Integer,Integer)'
	virtual Integer setPA( Integer value, Integer rfState );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* MakoRFPA_H */

// }}}RME
