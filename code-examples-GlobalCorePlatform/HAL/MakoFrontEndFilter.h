// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoFrontEndFilter'

#ifndef MakoFrontEndFilter_H
#define MakoFrontEndFilter_H

#ifdef PRAGMA
#pragma interface "MakoFrontEndFilter.h"
#endif

#include <HALtestLib_win32.h>
#include <DACDriver.h>
#include <frontEndFilter.h>
class Mako;
class bitfield;
class rfSpiBuffer;
class rf_audio_std_types;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <MakoPrivateBitfieldsReg6.h>


// }}}USR
// }}}RME

class MakoFrontEndFilter : public frontEndFilter, public DACDriver
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
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	MakoFrontEndFilter( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~MakoFrontEndFilter( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	MakoFrontEndFilter( const MakoFrontEndFilter & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	MakoFrontEndFilter & operator=( const MakoFrontEndFilter & rtg_arg );
	// }}}RME

protected:
	// {{{RME operation 'MakoFrontEndFilter(uint32_t *,rfSpiBuffer**,unsigned int,unsigned int)'
	MakoFrontEndFilter( uint32_t * dacData, rfSpiBuffer * * dacBuffers, unsigned int dacSelect, unsigned int numDACBuffers );
	// }}}RME

public:
	// {{{RME operation 'setFilter(Integer,Integer)'
	virtual Integer setFilter( Integer value, Integer rfState );
	// }}}RME
	// {{{RME operation 'setRFState(Integer)'
	virtual Integer setRFState( Integer rfState );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* MakoFrontEndFilter_H */

// }}}RME
