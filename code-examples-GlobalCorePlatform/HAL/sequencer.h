// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer::sequencer'

#ifndef sequencer_H
#define sequencer_H

#ifdef PRAGMA
#pragma interface "sequencer.h"
#endif

#include <HALtestLib_win32.h>
#include <RFVirtual.h>
#include <bitfield.h>
#include <rf_audio_std_types.h>
class DataInterface;
class dataStore;
class sequencerComponent;
class sequencerTimer;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>

// -------------------------------Macro Defines-------------------------------
#define MAX_ARGUMENTS  4
#define NUM_LOCAL_REG  32
#define NUM_GLOBAL_REG 16

// }}}USR
// }}}RME
// {{{RME classifier 'sequencerState' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'opcodeEnum_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'manipulationEnum_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'miscellaneousEnum_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'jumpEnum_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'argValue_t' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class sequencer : public RFVirtual
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR
	typedef uint16_t * opwordPtr_t;

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
	// {{{RME classifier 'sequencerState'
	class sequencerState
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
		// {{{RME classAttribute 'currentInstruction'
		opwordPtr_t currentInstruction;
		// }}}RME
		// {{{RME classAttribute 'dataStoreInterface'
		sequencerComponent * dataStoreInterface;
		// }}}RME
		// {{{RME classAttribute 'GLOBAL'
		static const long GLOBAL;
		// }}}RME

	private:
		// {{{RME classAttribute 'globalRegisters'
		long * globalRegisters;
		// }}}RME

	public:
		// {{{RME classAttribute 'LOCAL'
		static const long LOCAL;
		// }}}RME

	private:
		// {{{RME classAttribute 'localRegisters'
		long localRegisters[ NUM_LOCAL_REG ];
		// }}}RME
		// {{{RME classAttribute 'NUM_EXT_GLOBALS'
		static const Integer NUM_EXT_GLOBALS;
		// }}}RME
		// {{{RME classAttribute 'programCounter'
		Integer programCounter;
		// }}}RME
		// {{{RME classAttribute 'PSEUDO_LOCAL'
		static const Integer PSEUDO_LOCAL;
		// }}}RME
		// {{{RME classAttribute 'PSEUDO_LOCAL_INDEX'
		static const Integer PSEUDO_LOCAL_INDEX;
		// }}}RME

	public:
		// {{{RME classAttribute 'pseudoGlobals'
		long * pseudoGlobals;
		// }}}RME
		// {{{RME classAttribute 'REGISTER_UNUSED'
		static const Integer REGISTER_UNUSED;
		// }}}RME

	private:
		// {{{RME classAttribute 'startInstruction'
		opwordPtr_t startInstruction;
		// }}}RME
		// {{{RME classAttribute 'WORD_SIZE'
		static const Integer WORD_SIZE;
		// }}}RME
		// {{{RME classAttribute 'DATASTORE_REG_NUM_MASK'
		static const Integer DATASTORE_REG_NUM_MASK;
		// }}}RME
		// {{{RME classAttribute 'DATASTORE_FLAG_MASK'
		static const Integer DATASTORE_FLAG_MASK;
		// }}}RME
		// {{{RME classAttribute 'DATASTORE_S_FLAG_MASK'
		static const Integer DATASTORE_S_FLAG_MASK;
		// }}}RME

	public:
		// {{{RME operation 'compareUpdateProgramCounter(Boolean,Integer,Integer)'
		void compareUpdateProgramCounter( Boolean compareResult, Integer offsetReg, Integer offset );
		// }}}RME
		// {{{RME operation 'getDataSource(Integer)'
		Integer getDataSource( Integer source );
		// }}}RME
		// {{{RME operation 'getDataStore(Integer,Integer)'
		Integer getDataStore( Integer accessValue, Integer dataStoreNumber );
		// }}}RME
		// {{{RME operation 'getRegister(Integer,Integer)'
		long getRegister( Integer registerType, Integer registerNumber );
		// }}}RME
		// {{{RME operation 'nextInstruction()'
		void nextInstruction( void );
		// }}}RME
		// {{{RME operation 'sequencerState(long *,sequencerComponent*,opwordPtr_t)'
		sequencerState( long * globalPtr, sequencerComponent * dataStoreInterfacePtr, opwordPtr_t startInstPtr );
		// }}}RME
		// {{{RME operation 'setDataSource(Integer,Integer)'
		void setDataSource( Integer source, Integer value );
		// }}}RME
		// {{{RME operation 'setRegister(Integer,Integer,long)'
		void setRegister( Integer registerType, Integer registerNumber, long value );
		// }}}RME
	};
	// }}}RME
	// {{{RME classifier 'opcodeEnum_t'
	enum opcodeEnum_t
	{
		EXECUTEI = 0
	  , EXECUTE = 1
	  , JUMPI = 4
	  , JUMP = 5
	  , MANIPI = 8
	  , MANIP = 9
	  , MISCI = 14
	  , MISC = 15
	};
	// }}}RME
	// {{{RME classifier 'manipulationEnum_t'
	enum manipulationEnum_t
	{
		LOAD = 0
	  , ADD = 1
	  , SUBTRACT = 2
	  , AND = 3
	  , OR = 4
	  , XOR = 5
	  , NOT = 6
	};
	// }}}RME
	// {{{RME classifier 'miscellaneousEnum_t'
	enum miscellaneousEnum_t
	{
		DELAY = 0
	  , CALL = 1
	};
	// }}}RME
	// {{{RME classifier 'jumpEnum_t'
	enum jumpEnum_t
	{
		ALWAYS = 0
	  , EQUAL = 1
	  , NOTEQUAL = 2
	  , GREATER = 3
	  , LESS = 4
	  , GREATEREQ = 5
	  , LESSEQ = 6
	};
	// }}}RME
	// {{{RME classifier 'argValue_t'
	class argValue_t
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
		// {{{RME classAttribute 'data'
		int32_t data[ MAX_ARGUMENTS ];
		// }}}RME
		// {{{RME classAttribute 'number'
		int number;
		// }}}RME
	};
	// }}}RME
	// {{{RME classAttribute 'componentTable'
	sequencerComponent * * componentTable;
	// }}}RME
	// {{{RME classAttribute 'DATA_INTERFACE_COMPONENT_INDEX'
	static const Integer DATA_INTERFACE_COMPONENT_INDEX;
	// }}}RME
	// {{{RME classAttribute 'ENDSEQ'
	static const Integer ENDSEQ;
	// }}}RME
	// {{{RME classAttribute 'globalRegisters'
	long globalRegisters[ NUM_GLOBAL_REG ];
	// }}}RME
	// {{{RME classAttribute 'MAX_JUMP_ARG'
	static const Integer MAX_JUMP_ARG;
	// }}}RME
	// {{{RME classAttribute 'sequences'
	opwordPtr_t * sequences;
	// }}}RME
	// {{{RME classAttribute 'sequenceTimer'
	sequencerTimer * sequenceTimer;
	// }}}RME
	// {{{RME operation 'call(Integer,long *,sequencerComponent*)'
	void call( Integer sequenceID, long * globalPtr, sequencerComponent * dataStoreInterfacePtr );
	// }}}RME
	// {{{RME operation 'compareSwitch(Integer,Integer,Integer)'
	Boolean compareSwitch( Integer comparison, Integer operand1, Integer operand2 );
	// }}}RME
	// {{{RME operation 'compEqual(Integer,Integer)'
	Boolean compEqual( Integer operand1, Integer operand2 );
	// }}}RME
	// {{{RME operation 'compGreater(Integer,Integer)'
	Boolean compGreater( Integer operand1, Integer operand2 );
	// }}}RME
	// {{{RME operation 'compGreaterEq(Integer,Integer)'
	Boolean compGreaterEq( Integer operand1, Integer operand2 );
	// }}}RME
	// {{{RME operation 'compLess(Integer,Integer)'
	Boolean compLess( Integer operand1, Integer operand2 );
	// }}}RME
	// {{{RME operation 'compLessEq(Integer,Integer)'
	Boolean compLessEq( Integer operand1, Integer operand2 );
	// }}}RME
	// {{{RME operation 'compNotEqual(Integer,Integer)'
	Boolean compNotEqual( Integer operand1, Integer operand2 );
	// }}}RME
	// {{{RME operation 'delay(UInteger)'
	void delay( UInteger time );
	// }}}RME
	// {{{RME operation 'executeImmdOpcode(Integer,sequencerState*)'
	void executeImmdOpcode( Integer returnRegister, sequencerState * currentState );
	// }}}RME
	// {{{RME operation 'executeOpcode(Integer,sequencerState*)'
	void executeOpcode( Integer returnRegister, sequencerState * currentState );
	// }}}RME
	// {{{RME operation 'getArguments(sequencerState*,Integer)'
	argValue_t getArguments( sequencerState * currentState, Integer numSources );
	// }}}RME
	// {{{RME operation 'getImmdData(opwordPtr_t)'
	Integer getImmdData( opwordPtr_t sequencerWord );
	// }}}RME
	// {{{RME operation 'jumpImmdOpcode(Integer,sequencerState*)'
	void jumpImmdOpcode( Integer comparison, sequencerState * currentState );
	// }}}RME
	// {{{RME operation 'jumpOpcode(Integer,sequencerState*)'
	void jumpOpcode( Integer comparison, sequencerState * currentState );
	// }}}RME
	// {{{RME operation 'manipAdd(Integer,Integer)'
	Integer manipAdd( Integer destinationData, Integer sourceData );
	// }}}RME
	// {{{RME operation 'manipAnd(Integer,Integer)'
	Integer manipAnd( Integer destinationData, Integer sourceData );
	// }}}RME
	// {{{RME operation 'manipLoad(Integer,Integer)'
	Integer manipLoad( Integer destinationData, Integer sourceData );
	// }}}RME
	// {{{RME operation 'manipNot(Integer)'
	Integer manipNot( Integer destinationData );
	// }}}RME
	// {{{RME operation 'manipOr(Integer,Integer)'
	Integer manipOr( Integer destinationData, Integer sourceData );
	// }}}RME
	// {{{RME operation 'manipSubtract(Integer,Integer)'
	Integer manipSubtract( Integer destinationData, Integer sourceData );
	// }}}RME
	// {{{RME operation 'manipulateImmdOpcode(Integer,sequencerState*)'
	void manipulateImmdOpcode( Integer operation, sequencerState * currentState );
	// }}}RME
	// {{{RME operation 'manipulateOpcode(Integer,sequencerState*)'
	void manipulateOpcode( Integer operation, sequencerState * currentState );
	// }}}RME
	// {{{RME operation 'manipulateSwitch(Integer,Integer,Integer)'
	Integer manipulateSwitch( Integer operation, Integer operand1, Integer operand2 );
	// }}}RME
	// {{{RME operation 'manipXor(Integer,Integer)'
	Integer manipXor( Integer destinationData, Integer sourceData );
	// }}}RME
	// {{{RME operation 'miscellaneousImmdOpcode(Integer,sequencerState*)'
	void miscellaneousImmdOpcode( Integer operation, sequencerState * currentState );
	// }}}RME
	// {{{RME operation 'miscellaneousOpcode(Integer,sequencerState*)'
	void miscellaneousOpcode( Integer operation, sequencerState * currentState );
	// }}}RME
	// {{{RME operation 'miscSwitch(Integer,Integer,sequencerState*)'
	void miscSwitch( Integer operation, Integer arguments, sequencerState * currentState );
	// }}}RME
	// {{{RME operation 'opcodeSwitch(Integer,sequencerState*)'
	void opcodeSwitch( Integer opcode, sequencerState * currentState );
	// }}}RME
	// {{{RME operation 'runSequence(sequencerState*)'
	void runSequence( sequencerState * currentState );
	// }}}RME

public:
	// {{{RME operation 'sequencer(opwordPtr_t*,sequencerComponent**,sequencerTimer*)'
	sequencer( opwordPtr_t * sequencePtr, sequencerComponent * * componentTablePtr, sequencerTimer * timerPtr );
	// }}}RME
	// {{{RME operation '~sequencer()'
	~sequencer( void );
	// }}}RME
	// {{{RME operation 'executeSequence(unsigned int)'
	virtual bool executeSequence( unsigned int sequenceID );
	// }}}RME
	// {{{RME operation 'setRegister(unsigned int,long)'
	virtual void setRegister( unsigned int reg, long value );
	// }}}RME
	// {{{RME operation 'getRegister(unsigned int)'
	virtual long getRegister( unsigned int reg );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'sequencerState' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'opcodeEnum_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'manipulationEnum_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'miscellaneousEnum_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'jumpEnum_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'argValue_t' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* sequencer_H */

// }}}RME
