// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::tomahawk::TomahawkWithDualPortConverter'

#ifndef TomahawkWithDualPortConverter_H
#define TomahawkWithDualPortConverter_H

#ifdef PRAGMA
#pragma interface "TomahawkWithDualPortConverter.h"
#endif

#include <HALtestLib_win32.h>
#include <Connection.h>
#include <SIntArray.h>
#include <tomahawk.h>
class DelayBase;
class DesiredTxDevOption;
class INT32DivideBase;
class LongFract;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#define BIT3 0x0008
#define MASKB3 0xFFF0
#define BIT4 0x0010
#define TOMAHAWK_MULTIPLIER 32813
// }}}USR
// }}}RME

class TomahawkWithDualPortConverter : public tomahawk, public Connection
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
	// {{{RME classAttribute 'm_lowPortScaler'
	int32_t m_lowPortScaler;
	// }}}RME
	// {{{RME classAttribute 'm_desiredTxDeviation'
	unsigned int m_desiredTxDeviation;
	// }}}RME
	// {{{RME classAttribute 'm_maxInputLevel'
	signed int m_maxInputLevel;
	// }}}RME
	// {{{RME classAttribute 'm_nominalInputLevel'
	signed int m_nominalInputLevel;
	// }}}RME
	// {{{RME classAttribute 'm_maxDev'
	unsigned int m_maxDev;
	// }}}RME
	// {{{RME classAttribute 'm_rfState'
	int32_t m_rfState;
	// }}}RME

protected:
	// {{{RME associationEnd 'm_ssiConnection'
	Connection * m_ssiConnection;
	// }}}RME
	// {{{RME associationEnd 'dividePtr'
	INT32DivideBase * dividePtr;
	// }}}RME
	// {{{RME associationEnd 'm_delay'
	DelayBase * m_delay;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~TomahawkWithDualPortConverter( void );
	// }}}RME
	// {{{RME operation 'send(Array *)'
	virtual bool send( Array * buffer );
	// }}}RME
	// {{{RME operation 'receive()'
	virtual Array * receive( void );
	// }}}RME
	// {{{RME operation 'setOption(Configurable::Option *)'
	virtual bool setOption( Configurable::Option * option );
	// }}}RME
	// {{{RME operation 'getOption(ClassType)'
	virtual Configurable::Option * getOption( ClassType optionType ) const;
	// }}}RME
	// {{{RME operation 'getStatus()'
	virtual Connection::Status * getStatus( void );
	// }}}RME
	// {{{RME operation 'setRFState(int32_t)'
	virtual int32_t setRFState( int32_t rfState );
	// }}}RME
	// {{{RME operation 'TomahawkWithDualPortConverter(tomahawkDefault*,rfSpiBuffer**,int,int,int,int,DelayBase *,INT32DivideBase *,Connection *,signed int,signed int,int32_t)'
	TomahawkWithDualPortConverter( tomahawkDefault * init, rfSpiBuffer * * spiBuffers, int numberOfRfStates, int numberOfDiscretes, int numberOfGPOs, int numberOfGains, DelayBase * delayPtr, INT32DivideBase * divPtr, Connection * ssiConnection, signed int maxInputLevel = 32767, signed int nominalInputLevel = 16384, int32_t rfState = 0 );
	// }}}RME
	// {{{RME operation 'TomahawkWithDualPortConverter(tomahawkDefault*,rfSpiBuffer**,int,DelayBase *,INT32DivideBase *,Connection *,signed int,signed int,int32_t)'
	TomahawkWithDualPortConverter( tomahawkDefault * init, rfSpiBuffer * * spiBuffers, int numberOfRfStates, DelayBase * delayPtr, INT32DivideBase * divPtr, Connection * ssiConnection, signed int maxInputLevel = 32767, signed int nominalInputLevel = 16384, int32_t rfState = 0 );
	// }}}RME
	// {{{RME operation 'calculateLowPortScaler(int32_t,int32_t)'
	bool calculateLowPortScaler( int32_t mrefDiv, int32_t lpAdd );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* TomahawkWithDualPortConverter_H */

// }}}RME
