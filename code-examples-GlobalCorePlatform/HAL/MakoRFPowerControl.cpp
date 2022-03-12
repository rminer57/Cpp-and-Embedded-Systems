// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoRFPowerControl'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "MakoRFPowerControl.h"
#endif

#include <HALtestLib_win32.h>
#include <MakoRFPowerControl.h>
#include <Mako.h>
#include <MakoPrivate.h>
#include <MakoPrivateBitfieldsReg6.h>
#include <PowerConfiguration.h>
#include <bitfield.h>
#include <rfSpiBuffer.h>
#include <rf_audio_std_types.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'setRFState(Integer)'
Integer MakoRFPowerControl::setRFState( Integer rfState )
{
	// {{{USR
	Integer status = 0;
	bool newDAC3State;

	// LUT registers and attack times already programmed into Mako (done via setPowerLevel method).
	// All we need to do, here, is program the DAC power-up/power-down control bit (if necessary)
	// and the Rx/Tx control bit (to ramp-up/ramp-down the RF PA).

	// Only program Mako if rfState is less than number of allocated SPI buffers...
	if (rfState < m_numDACBuffers)
	   {
	// Update the power-down/power-up control bit ONLY if necessary. 
	   newDAC3State=m_powerConfig[rfState]->getPowerState();

	   if (m_dac3State ^ newDAC3State)                                                  // Check if different (XOR)
	      {
	//    DAC3 power-up/power-down control bit is different, so it must be updated.
	      m_dac3State = newDAC3State; 
	      m_dacCommonBuffers[rfState]->sync();                                         // DAC3 Power state programmed.
	      }

	// Set trigger configuration.
	   setBitField(*m_dac3Buffer, TX_RX, (m_powerConfig[rfState]->getTrigger()?1:0));
	   m_dac3Buffer->sync();                                                           // Trigger programmed.

	// Call parent to set state variables.
	   status = powerControl::setRFState(rfState);
	   }

	return status;
	// }}}USR
}
// }}}RME

// {{{RME operation 'MakoRFPowerControl(PowerConfiguration**,rfSpiBuffer**,rfSpiBuffer*,unsigned int)'
MakoRFPowerControl::MakoRFPowerControl( PowerConfiguration * * dacConfig, rfSpiBuffer * * dacCommonBuffers, rfSpiBuffer * dac3Buffer, unsigned int numDACBuffers )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	// Initialize class attributes.

	int j=0;

	m_powerConfig      = dacConfig;                                          // Client configuration data.
	m_dacCommonBuffers = dacCommonBuffers;                                   // Buffers shared by DAC1, DAC2, and DAC3
	m_numDACBuffers    = numDACBuffers;                                      // Number of common buffers
	m_dac3Buffer       = dac3Buffer;                                         // DAC3 dedicated buffer.
	m_dac3State        = false;                                              // Power-on reset state of DAC3 (powered-down)

	for(int i = 0; i < m_numDACBuffers; i++)
	   {
	   setBitField(*m_dacCommonBuffers[i], DAC_SELECT, DAC1);                // YES, DAC1 is correct! To access DAC3 power
	                                                                         // control bit, we must go through DAC1.
	   setBitField(*m_dacCommonBuffers[i], DAC3_STATE, (m_powerConfig[i]->getPowerState()?1:0)); // DAC3 state.
	   }

	// Initialize dedicated DAC3 buffer:
	*m_dac3Buffer[j] = 0;                                                    // Clear the buffer.
	setBitField(*m_dac3Buffer, READ_WRITE_CNTRL, MAKO_WRITE);                // Enable write.
	setBitField(*m_dac3Buffer, DAC_ADDRESS, DAC_REGISTER_ADDR);              // DAC Address.
	setBitField(*m_dac3Buffer, DAC_SELECT, DAC3);                            // The dedicated register will only be used for DAC3.
	// }}}USR
}
// }}}RME

// {{{RME operation 'setPowerLevel(Integer,Integer)'
Integer MakoRFPowerControl::setPowerLevel( Integer level, Integer rfState )
{
	// {{{USR
	unsigned int j;
	uint16_t       *envelope;

	// Only program Mako, if level is < number of PowerConfiguration entries.
	if (level < m_numDACBuffers)
	   {

	// NOTE: only the dedicated DAC3 buffer is used.

	// Clear the LUT registers latch bit. Mako hardware clears this bit when
	// the LUT registers are loaded; so just clear the bit in the buffer.
	   setBitField(*m_dac3Buffer, RDY2LOAD, CLEAR_LATCH);                           // Clear latch control bit.

	// Use selected power level configuration to program Mako's DAC3 attack time (ramp-up/ramp-down times).
	   setBitField(*m_dac3Buffer, LD_CLKDIV, ENABLE_CLOCK_LOAD);                    // Enable clock load.
	   setBitField(*m_dac3Buffer, CLKDIV, m_powerConfig[level]->getAttackTime() );  // Attack time.
	   m_dac3Buffer->sync();                                                        // Load attack time in Mako IC.
	                                                                                // NOTE: attack time is not used until setRFstate is invoked.
	// Reset clock load control (to prevent clock from being loaded again).
	   setBitField(*m_dac3Buffer, LD_CLKDIV, DISABLE_CLOCK_LOAD);                   // Clock is now write-protected.

	// Write to Mako to gain access to the LUT
	   setBitField(*m_dac3Buffer, LD_DATA, ENABLE_LUT_LOAD);                        // Enable LUT loading.
	   
	// Get pointer to power envelope.
	   envelope = m_powerConfig[level]->getPowerEnvelope();

	// Load first 30 LUT registers...
	// NOTE: load begins with 0, EVEN, and ends at 31, ODD!!!
	   for (j = 0; j < Mako::LUT_SIZE-2; j=j+2)
	      {
	      setBitField(*m_dac3Buffer, DAC_DATA_EVEN, envelope[j]);                   // LUT even data.
	      setBitField(*m_dac3Buffer, DAC_DATA_ODD,  envelope[j+1]);                 // LUT odd data.
	      m_dac3Buffer->sync();                                                     // Two LUT registers loaded.
	      }
	   
	// Last two LUT registers need to be programed with RDY2LOAD set to latch the data into the LUT registers.
	   setBitField(*m_dac3Buffer, RDY2LOAD, SET_LATCH);                             // Latch the data into the LUT registers.
	   setBitField(*m_dac3Buffer, DAC_DATA_EVEN, envelope[Mako::LUT_SIZE-2]);       // LUT odd data.
	   setBitField(*m_dac3Buffer, DAC_DATA_ODD,  envelope[Mako::LUT_SIZE-1]);       // LUT even data.
	   m_dac3Buffer->sync();                                                        // Last 2 LUT registers loaded.
	   
	// Disable LUT loading.
	   setBitField(*m_dac3Buffer, LD_DATA, DISABLE_LUT_LOAD);
	   m_dac3Buffer->sync();                                                        // LUT registers now write protected.
	}
	   
	// Power envelope now programmed into Mako.
	return level;
	// }}}USR
}
// }}}RME

// {{{RME operation 'replacePowerConfig(unsigned int,PowerConfiguration*)'
bool MakoRFPowerControl::replacePowerConfig( unsigned int level, PowerConfiguration * newPowerConfig )
{
	// {{{USR
	bool returnStatus = false;

	if (level < m_numDACBuffers)
	{

	   delete [] m_powerConfig[level];

	   m_powerConfig[level]=newPowerConfig;

	   setBitField(*m_dacCommonBuffers[level], DAC3_STATE, (m_powerConfig[level]->getPowerState()?1:0));

	   returnStatus = true;
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
