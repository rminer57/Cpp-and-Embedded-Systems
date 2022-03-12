// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoRFPA'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "MakoRFPA.h"
#endif

#include <HALtestLib_win32.h>
#include <MakoRFPA.h>
#include <Mako.h>
#include <MakoPrivate.h>
#include <MakoPrivateBitfieldsReg6.h>
#include <bitfield.h>
#include <rfSpiBuffer.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'setRFState(Integer)'
Integer MakoRFPA::setRFState( Integer rfState )
{
	// {{{USR
	Integer returnStatus=0;

	// Update IC only if rfState is valid.
	if (rfState < m_numDACBuffers)
	   {
	// synchronize on state change.
	   m_dacCommonBuffers[rfState]->sync();

	// Call parent to set state variables.
	   returnStatus = powerAmplifier::setRFState(rfState);
	   }

	return returnStatus;

	// }}}USR
}
// }}}RME

// {{{RME operation 'MakoRFPA(uint32_t  *,rfSpiBuffer**,unsigned int,unsigned int)'
MakoRFPA::MakoRFPA( uint32_t * dacData, rfSpiBuffer * * dacBuffers, unsigned int dacSelect, unsigned int numDACBuffers )
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

	// Initialize RF PA buffer.
	for(i = 0; i < m_numDACBuffers; i++)
	   {
	   putDACBuffer(m_dacSelect, m_dacCommonBuffers[i], dacData[i]);
	   }

	// }}}USR
}
// }}}RME

// {{{RME operation 'setPA(Integer,Integer)'
Integer MakoRFPA::setPA( Integer value, Integer rfState )
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

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
