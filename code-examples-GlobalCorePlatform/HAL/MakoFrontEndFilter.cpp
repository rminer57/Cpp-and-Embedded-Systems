// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoFrontEndFilter'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "MakoFrontEndFilter.h"
#endif

#include <HALtestLib_win32.h>
#include <MakoFrontEndFilter.h>
#include <Mako.h>
#include <bitfield.h>
#include <rfSpiBuffer.h>
#include <rf_audio_std_types.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
MakoFrontEndFilter::MakoFrontEndFilter( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
MakoFrontEndFilter::~MakoFrontEndFilter( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
MakoFrontEndFilter::MakoFrontEndFilter( const MakoFrontEndFilter & rtg_arg )
	: frontEndFilter( rtg_arg )
	, DACDriver( rtg_arg )
	, m_dacSelect( rtg_arg.m_dacSelect )
	, m_numDACBuffers( rtg_arg.m_numDACBuffers )
	, m_dacCommonBuffers( rtg_arg.m_dacCommonBuffers )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
MakoFrontEndFilter & MakoFrontEndFilter::operator=( const MakoFrontEndFilter & rtg_arg )
{
	if( this != &rtg_arg )
	{
		frontEndFilter::operator=( rtg_arg );
		DACDriver::operator=( rtg_arg );
		m_dacSelect = rtg_arg.m_dacSelect;
		m_numDACBuffers = rtg_arg.m_numDACBuffers;
		m_dacCommonBuffers = rtg_arg.m_dacCommonBuffers;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'MakoFrontEndFilter(uint32_t *,rfSpiBuffer**,unsigned int,unsigned int)'
MakoFrontEndFilter::MakoFrontEndFilter( uint32_t * dacData, rfSpiBuffer * * dacBuffers, unsigned int dacSelect, unsigned int numDACBuffers )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	int i;

	m_dacSelect        = dacSelect;
	m_dacCommonBuffers = dacBuffers;
	m_numDACBuffers    = numDACBuffers;

	// Initialize the Front End Filter buffer.
	for(i = 0; i < m_numDACBuffers; i++)
	   {
	   putDACBuffer(m_dacSelect, m_dacCommonBuffers[i], dacData[i]);
	   }

	// }}}USR
}
// }}}RME

// {{{RME operation 'setFilter(Integer,Integer)'
Integer MakoFrontEndFilter::setFilter( Integer value, Integer rfState )
{
	// {{{USR
	Integer returnStatus = 0;

	if (rfState < m_numDACBuffers)
	{
	// Input parameters are valid, so set return value to indicate success.
	   returnStatus = value;
	// Load requested data into DAC register buffer.
	   putDACBuffer(m_dacSelect, m_dacCommonBuffers[rfState], value);
	}

	return returnStatus;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setRFState(Integer)'
Integer MakoFrontEndFilter::setRFState( Integer rfState )
{
	// {{{USR
	Integer returnStatus = 0;

	if (rfState < m_numDACBuffers)

	   {
	// synchronize on state change.
	   m_dacCommonBuffers[rfState]->sync();

	// Call parent to set state variables.
	   returnStatus = frontEndFilter::setRFState(rfState);
	   }

	return returnStatus;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
