// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::Trident::Trident'

#ifndef Trident_H
#define Trident_H

#ifdef PRAGMA
#pragma interface "Trident.h"
#endif

#include <rf_sequencer_comp.h>
#include <IOVirtual.h>
#include <Omap1610Spi.h>
#include <TridentBitFieldDefs.h>
#include <TridentDefaultImages.h>
#include <TridentIOVirtualSerial.h>
#include <bbpControl.h>
#include <dataPoint.h>
#include <discreteDeviceControl.h>
#include <gainControl.h>
#include <generalPurposeOutput.h>
#include <generalPurposeOutputManager.h>
#include <icBaseClass.h>
#include <interpolationData.h>
#include <rfStatus.h>
#include <rf_audio_std_types.h>
#include <synthesizer.h>
#include <synthesizerAdjust.h>
#include <units.h>
class Connection;
class SIntArray;
class rfSpiBuffer_int16;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h> 

// }}}USR
// }}}RME
// {{{RME classifier 'tridentSettingsEnum_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'tridentBitFieldEnum_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'SPIAUX1'
#define SPIAUX1 1
// }}}RME

// {{{RME classAttribute 'SPIAUX2'
#define SPIAUX2 2
// }}}RME

// {{{RME classAttribute 'TRIDENT_ERRCODE_BADARG_RFSTATE'
#define TRIDENT_ERRCODE_BADARG_RFSTATE -700
// }}}RME

// {{{RME classAttribute 'TRIDENT_ERRCODE_BADARG_DEVICEID'
#define TRIDENT_ERRCODE_BADARG_DEVICEID -600
// }}}RME

// {{{RME classAttribute 'TRIDENT_ERRCODE_BADARG_SETTING'
#define TRIDENT_ERRCODE_BADARG_SETTING -800
// }}}RME

// {{{RME classAttribute 'TRIDENT_ERRCODE_NOERR'
#define TRIDENT_ERRCODE_NOERR 1
// }}}RME

// {{{RME classAttribute 'TRIDENT_ERRCODE_BADARG_ADDR'
#define TRIDENT_ERRCODE_BADARG_ADDR -500
// }}}RME

// {{{RME classAttribute 'TRIDENT_ERRCODE_CONNSPI'
#define TRIDENT_ERRCODE_CONNSPI -900
// }}}RME

// {{{RME classAttribute 'TRIDENT_IMAGE_SIZE'
#define TRIDENT_IMAGE_SIZE TRIDENT_IMAGE_SIZE_INT16
// }}}RME

// {{{RME classAttribute 'TRIDENT_ERRCODE_BADARG_BUFFER'
#define TRIDENT_ERRCODE_BADARG_BUFFER -1000
// }}}RME

// {{{RME classAttribute 'TRIDENT_ERRCODE_CONNSSI'
#define TRIDENT_ERRCODE_CONNSSI -1100
// }}}RME

// {{{RME classifier 'tridentSettingsEnum_t' classAttribute 'TRIDENT_GPO_LOW'
#define TRIDENT_GPO_LOW 0
// }}}RME

// {{{RME classifier 'tridentSettingsEnum_t' classAttribute 'TRIDENT_GPO_HIGH'
#define TRIDENT_GPO_HIGH 1
// }}}RME

class Trident : public discreteDeviceControl, public generalPurposeOutputManager, public gainControl, public bbpControl, public synthesizer, public synthesizerAdjust, public rfStatus, public icBaseClass
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR
	friend class TridentIOVirtualSerial;
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
	// {{{RME classifier 'tridentSettingsEnum_t'
	enum tridentSettingsEnum_t
	{
		TRIDENT_SSI_MODE_IDEN = 0
	  , TRIDENT_SSI_MODE_TETRA = 1
	  , TRIDENT_SSI_MODE_CGISS = 2
	  , TRIDENT_SSI_MODE_SAM_50 = 3
	  , TRIDENT_SSI_MODE_SAM_100 = 4
	  , TRIDENT_SSI_MODE_SAM_150 = 5
	  , TRIDENT_SSI_MODE_IDEN_CEFM_24 = 6
	  , TRIDENT_SSI_MODE_IDEN_CEFM_48 = 7
	  , TRIDENT_SSI_MODE_SAM_50_CEFM = 8
	  , TRIDENT_SSI_MODE_SAM_100_CEFM = 9
	  , TRIDENT_SSI_MODE_SAM_150_CEFM = 10
	  , TRIDENT_ES_SEL2_VCOIN = 1
	  , TRIDENT_ES_SEL2_REFIN = 0
	  , TRIDENT_AGC_DAC_MODE_INCREASE = 0
	  , TRIDENT_AGC_DAC_MODE_DECREASE = 1
	};
	// }}}RME
	// {{{RME classifier 'tridentBitFieldEnum_t'
	enum tridentBitFieldEnum_t
	{
		DN_DLY = 1
	  , ABR_SEL
	  , ABF_SEL
	  , SSI_DLY
	  , SC_SEL
	  , OVSX
	  , TXC_REF
	  , ABW
	  , TXF_REF
	  , OVS_REF
	  , I_DCOFS
	  , GPO_TRIST1
	  , GPO_TRIST2
	  , GPO_TRIST3
	  , GPO_TRIST4
	  , GPO_TRIST5
	  , GPO_TRIST6
	  , WFG_REF
	  , DCOC_SIGN_EF
	  , TX_DCOC_SIGN
	  , X1DR0
	  , DC_CORRECT
	  , HP_SEL_BS
	  , ATT_SSI
	  , X1DR1
	  , EN_DLY_MUX
	  , X1DR2
	  , EN_OVS_DLYD
	  , X1DR3
	  , SYMB_REF
	  , X1DR4
	  , TRIST_PAB
	  , BSAVE_EF
	  , BSAVE_Q
	  , BSAVE_I
	  , BSAVE_WG
	  , X1DR5
	  , TXCONFIG
	  , X2DR0
	  , X2DR1
	  , X2DR2
	  , X2DR3
	  , X2DR4
	  , X2DR5
	  , X3DR0
	  , X3DR1
	  , X3DR2
	  , X3DR3
	  , X3DR4
	  , X3DR5
	  , X4DR0
	  , X4DR1
	  , X4DR2
	  , X4DR3
	  , X4DR4
	  , X4DR5
	  , DCOC_REF
	  , TM_BUF
	  , EF_SEL
	  , EF_DC_CORRECT
	  , EF_DLY
	  , TEST_MUX
	  , TR_LOWER
	  , TR_UPPER
	  , FIRCLK_SB
	  , LAST_INT
	  , IDC_DAC
	  , DC_DAC_GM
	  , QDC_DAC
	  , DCOCL_HOLD
	  , DCOC_LPF_BW
	  , KDLPT
	  , THP2
	  , THP1
	  , FHP3
	  , SM_AGC_EN
	  , FHP2
	  , FHP1
	  , SD_MODE
	  , PMA_BIAS
	  , SSI_TS
	  , AB_SEL
	  , DBW
	  , PMA_BP
	  , TRK_LOW
	  , FREE_RUN
	  , TRK_HIGH
	  , RXSC_SEL
	  , AGC_CLK
	  , RXDIG_DIV
	  , DEC_DIV
	  , BS_DLY_TMR
	  , ADPT_DLY_TMR
	  , FBC_TMR
	  , AGCFLAGEN
	  , SEQMGR_EN
	  , DC_CALEN
	  , AGC_MAX_A
	  , FE_OFF_A
	  , STEP_SLOT
	  , AGC_DAC_VREF
	  , STEP_THRESH
	  , STEP_OFFSET
	  , BW
	  , BB2P_Q
	  , AGC_STEP_CMP
	  , RAGC_PHASE
	  , RAGC_DIV
	  , FAGC_STEPS
	  , FAGC_DIV
	  , NAGC_DIV
	  , AGCLVL
	  , CIC_OFFSET
	  , AUTO_AGC
	  , RF_STEPEN
	  , AGC_DAC_MODE
	  , AUX_DAC
	  , AGCHIGH
	  , MCPTEST
	  , MCP_GAIN
	  , MADP_TMR
	  , MREF_DIV
	  , CLK_NUM
	  , MACC
	  , MLBPRCS_SEL
	  , CLK_ACC
	  , CLK_N
	  , CLK_R
	  , CLKCP_TEST
	  , BSAVE_CLKS_SYN
	  , CLK_DIV
	  , TCLK_OUT_EN
	  , CLK_OUT_EN
	  , TCLK_DIV_SEL
	  , TCLK_DIV
	  , BSAVE_CRS_DAC
	  , ES_CP_BIAS_EN
	  , ES_VCO_STEER
	  , ES_SEL3
	  , ES_NUD_MUL_BYP
	  , ES_NUD_BYP
	  , ES_D16_BYP
	  , ES_CP_EN
	  , ES_SEL1
	  , ES_DIV_TEST
	  , ES_BIAS_EN
	  , ES_STEER_EN
	  , ES_NUD_EN
	  , CLK_IN_SEL
	  , AGC_DAC
	  , TRACK_OSCEN
	  , RX_BB_BS
	  , FE_EN
	  , SD_BS
	  , AGC_BS
	  , RX_DIG_BS
	  , ADAPT
	  , AUXDAC_BS
	  , BUFGAIN
	  , AMP_AGC
	  , PMA_AGC
	  , RX_BS
	  , ADAPTEN
	  , AGC_PRELOAD
	  , FAST_AGC
	  , RF_STEP
	  , SSI_MODE
	  , MAINNUM
	  , MAINNUM_0_15
	  , MAINNUM_16_23
	  , MFADJ
	  , BSAVE_MAIN_SYN
	  , BSAVE_SYN_ALL
	  , BSAVE_ALL
	  , SF_BS
	  , SYN_ADAPTEN
	  , RXSM_ASPI_EN
	  , MAINND
	  , NUD
	  , ES_SEL2
	  , BSAVE_ESCORT
	  , GPO_1
	  , GPO_2
	  , GPO_3
	  , GPO_5
	  , GPO_6
	  , GPO_4
	  , CEFBEN
	  , BSAVE_TX
	  , ATTEN_Q
	  , ATTEN_I
	  , STATT_IQ
	  , EF_DC_UPDATE
	  , DC_UPDATE
	  , BSAVE_TXR
	  , PWRCTL
	  , A0_ENV
	  , A1_ENV
	  , A2_ENV
	  , AUXCEPOL
	  , AUXCLKDIV2
	  , AUXCLKDIV1
	  , RX_EVENT2
	  , RX_EVENT1
	  , HPDC_HOLD
	  , ESC_DIVSEL
	  , GPO_TRIST_ALL
	  , STATT_EF
	  , TXCLK_POL
	  , Q_DCOFS
	  , TX_POS_COMP
	  , TX_NEG_COMP
	  , DIAG_MODE
	  , DIAG_INADDR
	  , DIAG_TX_RX_EN
	  , DIAG_OUTADDR
	  , GPO_TEST_SEL
	  , DMO
	  , AGC_ATTN_ENUP
	  , FST_STP
	  , I_DAC_HOLD
	  , Q_DAC_HOLD
	  , DAC_SEL
	  , DAC_WORD
	  , NBMUX
	  , RXSDL_HI_C
	  , VMULT_SEL
	  , MN_SYN_TRK_SEL
	  , VMULT_DIV
	  , ESD2_EN
	  , MNLDADJ
	  , ADPT_TRKL_ST
	  , VSUP_OUT
	  , NTXBW
	  , GPO6_EN
	  , GPO7_EN
	  , GPO8_EN
	  , SSI_DRV
	  , REFIN_DS_EN
	  , REF_OSC_OUT_DS_EN
	  , AUXDAC_DS_EN
	  , SF_OUT_DS_EN
	  , CLK_SYN_DS_EN
	  , CLK_OUT_DS_EN
	  , VMULT_DS_EN
	  , TCLK_OUT_DS_EN
	  , REFIN_EN
	  , REF_OSC_OUT_EN
	  , AUXDAC_EN
	  , SF_OUT_EN
	  , CLK_SYN_EN
	  , VMULT_EN
	  , NAGC_DIV0
	  , NAGC_DIV1
	  , NAGC_DIV2
	  , NAGC_3DIV2_EN
	  , AGC_CLK_DIV_MSB
	  , RX4GEN
	  , AGC_LOW
	  , SOS_THRESH0
	  , SOS_THRESH1
	  , SOS_THRESH2
	  , PROG_THRESH_EN
	  , DIV_SEL
	  , JITTER_EN
	  , CNTR_EN
	  , HB_LB
	  , REF_DEL
	  , AUX_DACBIT0
	  , AUX_DACBIT10_1
	  , CLK_NUM_0_15
	  , CLK_NUM_16_23
	  , ADPT_TRKL_EN
	  , GPO
	  , GPO_7
	  , GPO_8
	  , GPO5_EN
	  , AGC_NAGC_DIV0
	  , AGC_NAGC_DIV1
	  , AGC_NAGC_DIV2
	  , AGC_NAGC_3DIV_EN
	  , AGC_PROG_THRESH_EN
	  , AGC_SOS_THRESH0
	  , AGC_SOS_THRESH1
	  , AGC_SOS_THRESH2
	  , M_ERROR
	};
	// }}}RME

protected:
	// {{{RME classAttribute 'm_rfSpiBuffer'
	rfSpiBuffer_int16 * * m_rfSpiBuffer;
	// }}}RME
	// {{{RME classAttribute 'm_defaultData'
	TridentDefaultImages * m_defaultData;
	// }}}RME
	// {{{RME classAttribute 'm_bwBB'
	interpolationData * m_bwBB;
	// }}}RME
	// {{{RME classAttribute 'm_bwDataTbl'
	dataPoint * * m_bwDataTbl;
	// }}}RME
	// {{{RME classAttribute 'm_ModifiedImage'
	bool * m_ModifiedImage;
	// }}}RME
	// {{{RME classAttribute 'm_ResetImage'
	bool * m_ResetImage;
	// }}}RME
	// {{{RME classAttribute 'm_currentRfState'
	int m_currentRfState;
	// }}}RME
	// {{{RME classAttribute 'm_SnippetStatus'
	TridentSnippetStatus_t * m_SnippetStatus;
	// }}}RME
	// {{{RME classAttribute 'm_SnippetSpiIndex'
	int m_SnippetSpiIndex;
	// }}}RME
	// {{{RME classAttribute 'm_icVersion'
	int m_icVersion;
	// }}}RME
	// {{{RME classAttribute 'm_numberOfRfStates'
	int32_t m_numberOfRfStates;
	// }}}RME

public:
	// {{{RME classAttribute 'm_error'
	int m_error;
	// }}}RME
	// {{{RME operation 'Trident(TridentDefaultImages*,rfSpiBuffer_int16 **,int,int,int,int)'
	Trident( TridentDefaultImages * init, rfSpiBuffer_int16 * * spiBuffers, int numberOfRfStates, int numberOfDiscretes, int numberOfGPOs, int numberOfGains );
	// }}}RME

protected:
	// {{{RME operation 'cmnTridentConstructor(TridentDefaultImages*,rfSpiBuffer_int16 **,int)'
	void cmnTridentConstructor( TridentDefaultImages * init, rfSpiBuffer_int16 * * spiBuffers, int numberOfRfStates );
	// }}}RME

public:
	// {{{RME operation '~Trident()'
	virtual ~Trident( void );
	// }}}RME
	// {{{RME operation 'setRFState(int32_t)'
	virtual int32_t setRFState( int32_t rfState );
	// }}}RME
	// {{{RME operation 'setGPO(int16_t,int16_t,int16_t)'
	virtual void setGPO( int16_t portNumber, int16_t outputState, int16_t rfState );
	// }}}RME
	// {{{RME operation 'setDeviceState(int,int,int)'
	virtual int setDeviceState( int setting, int deviceId, int rfState );
	// }}}RME
	// {{{RME operation 'setGain(int,int,int)'
	virtual int setGain( int gainNumber, int gain, int rfState );
	// }}}RME
	// {{{RME operation 'setBBPFrequency(int,int)'
	virtual int setBBPFrequency( int frequencyKhz, int rfState );
	// }}}RME
	// {{{RME operation 'setSynthFrequency(int32_t,int16_t,int32_t,int32_t)'
	virtual int32_t setSynthFrequency( int32_t synthFrequencyHz, int16_t rfState, int32_t resolution, int32_t refFrequencyHz );
	// }}}RME

protected:
	// {{{RME operation 'setFreqParams(int32_t,int32_t,int32_t,int16_t)'
	virtual void setFreqParams( int32_t synthFrequencyHz, int32_t refFrequencyHz, int32_t resolution, int16_t rfState );
	// }}}RME
	// {{{RME operation 'LogSnippetMod(int,int)'
	void LogSnippetMod( int RfState, int SnippetID );
	// }}}RME

public:
	// {{{RME operation 'ResetRFState(int)'
	virtual void ResetRFState( int rfState );
	// }}}RME
	// {{{RME operation 'commitGPO(Integer,Integer)'
	void commitGPO( Integer portNumber, Integer rfState );
	// }}}RME
	// {{{RME operation 'writeImage(int,int,int)'
	virtual void writeImage( int rfState, int deviceId, int setting );
	// }}}RME
	// {{{RME operation 'wrRegister(int16_t,int16_t,int)'
	virtual void wrRegister( int16_t addr, int16_t data, int rfState = 0 );
	// }}}RME
	// {{{RME operation 'ResetCompImage(int)'
	virtual void ResetCompImage( int rfState );
	// }}}RME
	// {{{RME operation 'readImage(int,int)'
	virtual int32_t readImage( int deviceId, int rfState = 0 );
	// }}}RME
	// {{{RME operation 'rdRegister(int16_t,int)'
	virtual int16_t rdRegister( int16_t addr, int rfState = 0 );
	// }}}RME
	// {{{RME operation 'setWarp(int,int)'
	virtual int setWarp( int warp, int rfState );
	// }}}RME
	// {{{RME operation 'getStatus(Integer,Integer)'
	virtual Integer getStatus( Integer deviceId, Integer rfState );
	// }}}RME
	// {{{RME operation 'getICVersion()'
	int getICVersion( void );
	// }}}RME
	// {{{RME operation 'Trident(TridentDefaultImages*,rfSpiBuffer_int16 **,int)'
	Trident( TridentDefaultImages * init, rfSpiBuffer_int16 * * spiBuffers, int numberOfRfStates );
	// }}}RME
	// {{{RME operation 'getIOVirtualSerial(unsigned int,bool,bool)'
	IOVirtualSerial * getIOVirtualSerial( unsigned int whichIOVirtualSerial = SPIAUX1, bool auxSpiBufferSizeNormal = true, bool spiMode4wire = true );
	// }}}RME

protected:
	// {{{RME operation 'cmnRdWrPrimitiveAccessor(int,int,int,bool,bool)'
	virtual int cmnRdWrPrimitiveAccessor( int setting, int deviceId, int rfState, bool readORwrite = TRIDENT_WRITE, bool imageORIC = TRIDENT_ACCESS_IMAGE );
	// }}}RME
	// {{{RME operation 'errorCheckParams(int,int,int,int)'
	virtual bool errorCheckParams( int min, int max, int setting, int increment = 1 );
	// }}}RME

public:
	// {{{RME operation 'internalReadBack()'
	virtual SIntArray * internalReadBack( void );
	// }}}RME

protected:
	// {{{RME operation 'sendAndReceiveSPI(SIntArray *)'
	virtual SIntArray * sendAndReceiveSPI( SIntArray * buf = 0 );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'tridentSettingsEnum_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'tridentBitFieldEnum_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Trident_H */

// }}}RME
