// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::Trident::TridentWithDualPortConverter'

#ifndef TridentWithDualPortConverter_H
#define TridentWithDualPortConverter_H

#ifdef PRAGMA
#pragma interface "TridentWithDualPortConverter.h"
#endif

#include <rf_sequencer_comp.h>
#include <Connection.h>
#include <SIntArray.h>
#include <Trident.h>
#include <modulationBalanceAttenuator.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'TridentDualPortConfig' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#ifndef  TRIDENT_DPC_ConvertFactor_DEFINED
#define TRIDENT_DPC_ConvertPortFactor_DEFINED 1
// if x > 0.999999999534 then set x = 2^31 - 1
// else set x = 2^31
#define TRIDENT_DPC_ConvertFactor(x)  ((x>0.999999999534) ? (int32_t) (2147483647) : (int32_t) (x*2147483648) )
#endif

// }}}USR
// }}}RME
// {{{RME classifier 'tridentDualPortSettingsEnum_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'TridentDualPortDefines' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classifier 'TridentDualPortConfig' classAttribute 'TDPC_NOM_INPUTLEVEL_DEFAULT'
#define TDPC_NOM_INPUTLEVEL_DEFAULT 5898
// }}}RME

// {{{RME classifier 'TridentDualPortConfig' classAttribute 'TDPC_TXDEV_DEFAULT'
#define TDPC_TXDEV_DEFAULT 2830
// }}}RME

// {{{RME classifier 'TridentDualPortConfig' classAttribute 'TDPC_HIPORTPHASEOFFSET_DEFAULT'
#define TDPC_HIPORTPHASEOFFSET_DEFAULT 0
// }}}RME

// {{{RME classifier 'TridentDualPortConfig' classAttribute 'TDPC_LOWPORTSCALINGFACTOR_DEFAULT'
#define TDPC_LOWPORTSCALINGFACTOR_DEFAULT TRIDENT_DPC_ConvertFactor(0.09090)
// }}}RME

// {{{RME classifier 'TridentDualPortConfig' classAttribute 'TDPC_MODBALANCEATTEN_DEFAULT'
#define TDPC_MODBALANCEATTEN_DEFAULT 1
// }}}RME

// {{{RME classifier 'TridentDualPortConfig' classAttribute 'TDPC_MODLIMIT_DEFAULT'
#define TDPC_MODLIMIT_DEFAULT TDPC_FOSC_DEFAULT/512
// }}}RME

// {{{RME classifier 'TridentDualPortConfig' classAttribute 'TDPC_FOSC_DEFAULT'
#define TDPC_FOSC_DEFAULT 16800000
// }}}RME

// {{{RME classifier 'TridentDualPortConfig' classAttribute 'TDPC_LOWPORTPHASEOFFSET_DEFAULT'
#define TDPC_LOWPORTPHASEOFFSET_DEFAULT 4
// }}}RME

// {{{RME classifier 'TridentDualPortConfig' classAttribute 'TDPC_HIPORTSCALINGFACTOR_DEFAULT'
#define TDPC_HIPORTSCALINGFACTOR_DEFAULT TRIDENT_DPC_ConvertFactor(1)
// }}}RME

// {{{RME classifier 'TridentDualPortConfig' classAttribute 'TDPC_LOWPORTSSIDATASIZE_DEFAULT'
#define TDPC_LOWPORTSSIDATASIZE_DEFAULT 16
// }}}RME

// {{{RME classifier 'TridentDualPortConfig' classAttribute 'TDPC_HIPORTSSIDATASIZE_DEFAULT'
#define TDPC_HIPORTSSIDATASIZE_DEFAULT 16
// }}}RME

// {{{RME classifier 'TridentDualPortDefines' classAttribute 'MASKB3'
#define MASKB3  0xFFF0
// }}}RME

// {{{RME classifier 'TridentDualPortDefines' classAttribute 'TRIDENT_MULTIPLIER'
#define TRIDENT_MULTIPLIER 32813
// }}}RME

// {{{RME classifier 'TridentDualPortDefines' classAttribute 'BIT4'
#define BIT4 0x0010
// }}}RME

// {{{RME classifier 'TridentDualPortDefines' classAttribute 'BIT3'
#define BIT3 0x0008
// }}}RME

class TridentWithDualPortConverter : public Trident, public modulationBalanceAttenuator, public Connection
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

public:
	// {{{RME classifier 'TridentDualPortConfig'
	class TridentDualPortConfig : public Connection::ConnectionOption
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

	public:
		// {{{RME classAttribute 'm_lowPortScalingFactor'
		unsigned int m_lowPortScalingFactor;
		// }}}RME
		// {{{RME classAttribute 'm_hiPortPhaseOffset'
		int m_hiPortPhaseOffset;
		// }}}RME
		// {{{RME classAttribute 'm_modulationBalanceAtten'
		unsigned int m_modulationBalanceAtten;
		// }}}RME
		// {{{RME classAttribute 'm_modulationLimit'
		unsigned int m_modulationLimit;
		// }}}RME
		// {{{RME classAttribute 'm_fosc'
		unsigned int m_fosc;
		// }}}RME
		// {{{RME classAttribute 'm_TxDeviation'
		unsigned int m_TxDeviation;
		// }}}RME
		// {{{RME classAttribute 'm_nominalInputLevel'
		unsigned int m_nominalInputLevel;
		// }}}RME
		// {{{RME classAttribute 'TRIDENT_DUALPORTCONFIG_OPTION'
		static const unsigned int TRIDENT_DUALPORTCONFIG_OPTION;
		// }}}RME
		// {{{RME classAttribute 'm_lowPortPhaseOffset'
		int m_lowPortPhaseOffset;
		// }}}RME
		// {{{RME classAttribute 'm_hiPortScalingFactor'
		unsigned int m_hiPortScalingFactor;
		// }}}RME
		// {{{RME classAttribute 'm_hiPortRoundedSSIdataSize'
		unsigned int m_hiPortRoundedSSIdataSize;
		// }}}RME
		// {{{RME classAttribute 'm_lowPortRoundedSSIdataSize'
		unsigned int m_lowPortRoundedSSIdataSize;
		// }}}RME
		// {{{RME operation 'TridentDualPortConfig(unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int)'
		TridentDualPortConfig( unsigned int TxDeviation = TDPC_TXDEV_DEFAULT, unsigned int nominalInputLevel = TDPC_NOM_INPUTLEVEL_DEFAULT, unsigned int lowPortScalingFactor = TDPC_LOWPORTSCALINGFACTOR_DEFAULT, unsigned int lowPortPhaseOffset = TDPC_LOWPORTPHASEOFFSET_DEFAULT, unsigned int lowPortRoundedSSIdataSize = TDPC_LOWPORTSSIDATASIZE_DEFAULT, unsigned int hiPortScalingFactor = TDPC_HIPORTSCALINGFACTOR_DEFAULT, unsigned int hiPortPhaseOffset = TDPC_HIPORTPHASEOFFSET_DEFAULT, unsigned int hiPortRoundedSSIdataSize = TDPC_LOWPORTSSIDATASIZE_DEFAULT, unsigned int modulationBalanceAtten = TDPC_MODBALANCEATTEN_DEFAULT, unsigned int modulationLimit = TDPC_MODLIMIT_DEFAULT, unsigned int fosc = TDPC_FOSC_DEFAULT );
		// }}}RME
		// {{{RME operation 'TridentDualPortConfig(const TridentDualPortConfig &)'
		TridentDualPortConfig( const TridentDualPortConfig & rtg_arg );
		// }}}RME
		// {{{RME operation 'operator!=(const TridentDualPortConfig &)'
		bool operator!=( const TridentDualPortConfig & rtg_arg );
		// }}}RME
		// {{{RME operation 'operator==(const TridentDualPortConfig &)'
		bool operator==( const TridentDualPortConfig & rtg_arg );
		// }}}RME
		// {{{RME operation '~TridentDualPortConfig()'
		virtual ~TridentDualPortConfig( void );
		// }}}RME
		// {{{RME operation 'isType(ClassType)'
		virtual bool isType( ClassType type ) const;
		// }}}RME
		// {{{RME operation 'getType()'
		virtual ClassType getType( void ) const;
		// }}}RME
		// {{{RME operation 'operator=(const TridentDualPortConfig &)'
		TridentDualPortConfig & operator=( const TridentDualPortConfig & rtg_arg );
		// }}}RME
	};
	// }}}RME
	// {{{RME classifier 'tridentDualPortSettingsEnum_t'
	enum tridentDualPortSettingsEnum_t
	{
		TDPC_TXDEVIATION = TRIDENT_NUMOF_BITFIELDS + 210
	  , TDPC_HIPORTPHASEOFFSET = TRIDENT_NUMOF_BITFIELDS + 201
	  , TDPC_MODLIMIT = TRIDENT_NUMOF_BITFIELDS + 208
	  , TDPC_MODBALANCEATTEN = TRIDENT_NUMOF_BITFIELDS + 207
	  , TDPC_NOMINALINPUTLVL = TRIDENT_NUMOF_BITFIELDS + 209
	  , TDPC_LOWPORTSCALINGFACTOR = TRIDENT_NUMOF_BITFIELDS + 206
	  , TDPC_FOSC = TRIDENT_NUMOF_BITFIELDS + 200
	  , TDPC_HIPORTROUNDEDSSIDATASIZE = TRIDENT_NUMOF_BITFIELDS + 202
	  , TDPC_HIPORTSCALINGFACTOR = TRIDENT_NUMOF_BITFIELDS + 203
	  , TDPC_LOWPORTPHASEOFFSET = TRIDENT_NUMOF_BITFIELDS + 204
	  , TDPC_LOWPORTROUNDEDSSIDATASIZE = TRIDENT_NUMOF_BITFIELDS + 205
	};
	// }}}RME
	// {{{RME classifier 'TridentDualPortDefines'
	class TridentDualPortDefines
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
	};
	// }}}RME

protected:
	// {{{RME classAttribute 'm_dualPortRFStateArray'
	TridentDualPortConfig * * m_dualPortRFStateArray;
	// }}}RME
	// {{{RME classAttribute 'm_dualPortActiveConfig'
	TridentDualPortConfig * m_dualPortActiveConfig;
	// }}}RME
	// {{{RME associationEnd 'm_ssiConnection'
	Connection * m_ssiConnection;
	// }}}RME

public:
	// {{{RME operation 'send(Array *)'
	virtual bool send( Array * buffer );
	// }}}RME
	// {{{RME operation 'receive()'
	virtual Array * receive( void );
	// }}}RME
	// {{{RME operation 'setOption(Configurable::Option *)'
	virtual bool setOption( Configurable::Option * option );
	// }}}RME
	// {{{RME operation 'getStatus()'
	virtual Connection::Status * getStatus( void );
	// }}}RME
	// {{{RME operation 'setRFState(int32_t)'
	virtual int32_t setRFState( int32_t rfState );
	// }}}RME
	// {{{RME operation 'TridentWithDualPortConverter(TridentDefaultImages*,rfSpiBuffer_int16 **,int,int,int,int,Connection *,TridentDualPortConfig **)'
	TridentWithDualPortConverter( TridentDefaultImages * init, rfSpiBuffer_int16 * * spiBuffers, int numberOfRfStates, int numberOfDiscretes, int numberOfGPOs, int numberOfGains, Connection * ssiConnection, TridentDualPortConfig * * configArrayPtr = 0 );
	// }}}RME
	// {{{RME operation 'TridentWithDualPortConverter(TridentDefaultImages*,rfSpiBuffer_int16 **,int,Connection *,TridentDualPortConfig **)'
	TridentWithDualPortConverter( TridentDefaultImages * init, rfSpiBuffer_int16 * * spiBuffers, int numberOfRfStates, Connection * ssiConnection, TridentDualPortConfig * * configArrayPtr = 0 );
	// }}}RME
	// {{{RME operation 'getOption(ClassType)'
	virtual Configurable::Option * getOption( ClassType optionType ) const;
	// }}}RME
	// {{{RME operation 'setModBalance(Integer,Integer)'
	virtual Integer setModBalance( Integer attenuation, Integer rfState );
	// }}}RME
	// {{{RME operation '~TridentWithDualPortConverter()'
	virtual ~TridentWithDualPortConverter( void );
	// }}}RME
	// {{{RME operation 'setDeviceState(int,int,int)'
	virtual int setDeviceState( int setting, int deviceId, int rfState );
	// }}}RME
	// {{{RME operation 'getStatus(Integer,Integer)'
	virtual Integer getStatus( Integer deviceId, Integer rfState );
	// }}}RME

protected:
	// {{{RME operation 'cmnTridentWithDualPortConverterConstructor(TridentDualPortConfig **,int)'
	void cmnTridentWithDualPortConverterConstructor( TridentDualPortConfig * * configArrayPtr, int numberOfRfStates );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'TridentDualPortConfig' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'tridentDualPortSettingsEnum_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'TridentDualPortDefines' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* TridentWithDualPortConverter_H */

// }}}RME
