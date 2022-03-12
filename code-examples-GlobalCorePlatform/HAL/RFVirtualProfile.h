// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Configurable RF Deck::Options::RFVirtualProfile'

#ifndef RFVirtualProfile_H
#define RFVirtualProfile_H

#ifdef PRAGMA
#pragma interface "RFVirtualProfile.h"
#endif

#include <hal.h>
#include <Profile.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class RFVirtualProfile : public Profile
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

protected:
	// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
	// {{{USR
	SERIAL_CLASS_CONFIG();
	// }}}USR
	// }}}RME

private:
	// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

public:
	// {{{RME classAttribute 'RF_VIRTUAL_BASE_PROFILE'
	static const unsigned int RF_VIRTUAL_BASE_PROFILE;
	// }}}RME
	// {{{RME classAttribute 'm_rxFrequency'
	unsigned long m_rxFrequency;
	// }}}RME
	// {{{RME classAttribute 'm_rxBandwidth'
	unsigned int m_rxBandwidth;
	// }}}RME
	// {{{RME classAttribute 'm_freqOffset'
	int m_freqOffset;
	// }}}RME
	// {{{RME classAttribute 'm_agcGain'
	unsigned int m_agcGain;
	// }}}RME
	// {{{RME classAttribute 'm_txFrequency'
	unsigned long m_txFrequency;
	// }}}RME
	// {{{RME classAttribute 'm_txDeviation'
	unsigned int m_txDeviation;
	// }}}RME
	// {{{RME classAttribute 'm_txPower'
	unsigned int m_txPower;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~RFVirtualProfile( void );
	// }}}RME
	// {{{RME operation 'getType()'
	virtual ClassType getType( void ) const;
	// }}}RME
	// {{{RME operation 'isType(ClassType)'
	virtual bool isType( ClassType type ) const;
	// }}}RME

protected:
	// {{{RME operation 'serialize(SerialObject*)'
	virtual void serialize( SerialObject * so );
	// }}}RME
	// {{{RME operation 'deserialize(SerialObject*)'
	virtual void deserialize( SerialObject * so );
	// }}}RME

public:
	// {{{RME operation 'RFVirtualProfile(SerialObject*)'
	RFVirtualProfile( SerialObject * so );
	// }}}RME
	// {{{RME operation 'RFVirtualProfile(unsigned long,unsigned int,int,unsigned int,unsigned long,unsigned int,unsigned int)'
	RFVirtualProfile( unsigned long rxFrequency, unsigned int rxBandwidth, int freqOffset, unsigned int gain, unsigned long txFrequency, unsigned int txPower, unsigned int txDeviation );
	// }}}RME
	// {{{RME operation 'getRxFrequency()'
	virtual unsigned long getRxFrequency( void ) const;
	// }}}RME
	// {{{RME operation 'putRxFrequency(unsigned long)'
	virtual void putRxFrequency( unsigned long rxFrequency );
	// }}}RME
	// {{{RME operation 'getTxFrequency()'
	virtual unsigned long getTxFrequency( void ) const;
	// }}}RME
	// {{{RME operation 'putTxFrequency(unsigned long)'
	virtual void putTxFrequency( unsigned long txFrequency );
	// }}}RME
	// {{{RME operation 'getRxBandwidth()'
	virtual unsigned int getRxBandwidth( void ) const;
	// }}}RME
	// {{{RME operation 'putRxBandwidth(unsigned int)'
	virtual void putRxBandwidth( unsigned int rxBandwidth );
	// }}}RME
	// {{{RME operation 'getFreqOffset()'
	virtual int getFreqOffset( void ) const;
	// }}}RME
	// {{{RME operation 'putFreqOffset(int)'
	virtual void putFreqOffset( int freqOffset );
	// }}}RME
	// {{{RME operation 'getAGCGain()'
	virtual unsigned int getAGCGain( void ) const;
	// }}}RME
	// {{{RME operation 'putAGCGain(unsigned int)'
	virtual void putAGCGain( unsigned int agc );
	// }}}RME
	// {{{RME operation 'getTxDeviation()'
	virtual unsigned int getTxDeviation( void ) const;
	// }}}RME
	// {{{RME operation 'putTxDeviation(unsigned int)'
	virtual void putTxDeviation( unsigned int deviation );
	// }}}RME
	// {{{RME operation 'getTxPower()'
	virtual unsigned int getTxPower( void ) const;
	// }}}RME
	// {{{RME operation 'putTxPower(unsigned int)'
	virtual void putTxPower( unsigned int power );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* RFVirtualProfile_H */

// }}}RME
