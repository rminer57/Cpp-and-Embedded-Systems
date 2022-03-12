// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Configurable RF Deck::Options::RFVirtualProfile'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "RFVirtualProfile.h"
#endif

#include <hal.h>
#include <RFVirtualProfile.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
SERIAL_CLASS_INITIALIZE(RFVirtualProfile);

// }}}USR
// }}}RME

// {{{RME classAttribute 'RF_VIRTUAL_BASE_PROFILE'
const unsigned int RFVirtualProfile::RF_VIRTUAL_BASE_PROFILE( 21 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
RFVirtualProfile::~RFVirtualProfile( void )
{
}
// }}}RME

// {{{RME operation 'getType()'
ClassType RFVirtualProfile::getType( void ) const
{
	// {{{USR
	return RF_VIRTUAL_BASE_PROFILE;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool RFVirtualProfile::isType( ClassType type ) const
{
	// {{{USR
	return (type == RF_VIRTUAL_BASE_PROFILE)?true:Profile::isType(type);
	// }}}USR
}
// }}}RME

// {{{RME operation 'serialize(SerialObject*)'
void RFVirtualProfile::serialize( SerialObject * so )
{
	// {{{USR
	*so << m_rxFrequency << m_rxBandwidth << m_freqOffset << m_agcGain;  // Receive parameters
	*so << m_txFrequency << m_txPower << m_txDeviation;                  // Transmit parameters

	Profile::serialize(so);
	// }}}USR
}
// }}}RME

// {{{RME operation 'deserialize(SerialObject*)'
void RFVirtualProfile::deserialize( SerialObject * so )
{
	// {{{USR
	*so >> m_rxFrequency >> m_rxBandwidth >> m_freqOffset >> m_agcGain; // Receive parameters
	*so >> m_txFrequency >> m_txPower >> m_txDeviation;                 // Transmit parameters

	Profile::deserialize(so);

	// }}}USR
}
// }}}RME

// {{{RME operation 'RFVirtualProfile(SerialObject*)'
RFVirtualProfile::RFVirtualProfile( SerialObject * so )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	deserialize(so);
	// }}}USR
}
// }}}RME

// {{{RME operation 'RFVirtualProfile(unsigned long,unsigned int,int,unsigned int,unsigned long,unsigned int,unsigned int)'
RFVirtualProfile::RFVirtualProfile( unsigned long rxFrequency, unsigned int rxBandwidth, int freqOffset, unsigned int gain, unsigned long txFrequency, unsigned int txPower, unsigned int txDeviation )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_rxFrequency(rxFrequency),m_rxBandwidth(rxBandwidth),m_freqOffset(freqOffset),m_agcGain(gain),m_txFrequency(txFrequency), m_txPower(txPower), m_txDeviation(txDeviation)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'getRxFrequency()'
unsigned long RFVirtualProfile::getRxFrequency( void ) const
{
	// {{{USR
	return m_rxFrequency;
	// }}}USR
}
// }}}RME

// {{{RME operation 'putRxFrequency(unsigned long)'
void RFVirtualProfile::putRxFrequency( unsigned long rxFrequency )
{
	// {{{USR
	m_rxFrequency = rxFrequency;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getTxFrequency()'
unsigned long RFVirtualProfile::getTxFrequency( void ) const
{
	// {{{USR
	return m_txFrequency;
	// }}}USR
}
// }}}RME

// {{{RME operation 'putTxFrequency(unsigned long)'
void RFVirtualProfile::putTxFrequency( unsigned long txFrequency )
{
	// {{{USR
	m_txFrequency = txFrequency;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getRxBandwidth()'
unsigned int RFVirtualProfile::getRxBandwidth( void ) const
{
	// {{{USR
	return m_rxBandwidth;
	// }}}USR
}
// }}}RME

// {{{RME operation 'putRxBandwidth(unsigned int)'
void RFVirtualProfile::putRxBandwidth( unsigned int rxBandwidth )
{
	// {{{USR
	m_rxBandwidth = rxBandwidth;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getFreqOffset()'
int RFVirtualProfile::getFreqOffset( void ) const
{
	// {{{USR
	return m_freqOffset;
	// }}}USR
}
// }}}RME

// {{{RME operation 'putFreqOffset(int)'
void RFVirtualProfile::putFreqOffset( int freqOffset )
{
	// {{{USR
	m_freqOffset = freqOffset;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getAGCGain()'
unsigned int RFVirtualProfile::getAGCGain( void ) const
{
	// {{{USR
	return m_agcGain;
	// }}}USR
}
// }}}RME

// {{{RME operation 'putAGCGain(unsigned int)'
void RFVirtualProfile::putAGCGain( unsigned int agc )
{
	// {{{USR
	m_agcGain = agc;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getTxDeviation()'
unsigned int RFVirtualProfile::getTxDeviation( void ) const
{
	// {{{USR
	return m_txDeviation;
	// }}}USR
}
// }}}RME

// {{{RME operation 'putTxDeviation(unsigned int)'
void RFVirtualProfile::putTxDeviation( unsigned int deviation )
{
	// {{{USR
	m_txDeviation = deviation;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getTxPower()'
unsigned int RFVirtualProfile::getTxPower( void ) const
{
	// {{{USR
	return m_txPower;
	// }}}USR
}
// }}}RME

// {{{RME operation 'putTxPower(unsigned int)'
void RFVirtualProfile::putTxPower( unsigned int power )
{
	// {{{USR
	m_txPower = power;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
