// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Logical::sequencer::sequencer'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "sequencer.h"
#endif

#include <HALtestLib_win32.h>
#include <sequencer.h>
#include <DataInterface.h>
#include <dataStore.h>
#include <sequencerComponent.h>
#include <sequencerTimer.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
// -----------------------------Bitfield Defines------------------------------
//defineBitField(name,type,off,start,len)
// runSequence
defineBitField(OPCODE, uint16_t, 0, 8, 8);
defineBitField(OPCODE_TYPE, uint16_t, 0, 12, 4);
defineBitField(OPCODE_SUBTYPE, uint16_t, 0, 8, 4);
// executeImmdOpcode / executeOpcode
defineBitField(COMPONENT, uint16_t, 0, 3, 5);
defineBitField(OP_TYPE, uint16_t, 0, 0, 3);
// manipulateImmdOpcode / manipulateOpcode
defineBitField(MAN_DESTINATION, uint16_t, 0, 0, 8);
// jumpImmdOpcode / jumpOpcode
defineBitField(JUMP_OPERAND1, uint16_t, 0, 0, 8);
defineBitField(JUMP_OPERAND2, uint16_t, 2, 0, 16);
defineBitField(JUMP_OFFSET_REG, uint16_t, 4, 8, 8);
defineBitField(JUMP_OFFSET, uint16_t, 4, 0, 8);
// getArguments
defineBitField(SOURCE1, uint16_t, 2, 8, 8);
defineBitField(SOURCE2, uint16_t, 2, 0, 8);
defineBitField(SOURCE3, uint16_t, 4, 8, 8);
defineBitField(SOURCE4, uint16_t, 4, 0, 8);
// getImmdData
defineBitField(DATA1, uint16_t, 2, 0, 16);
defineBitField(DATA2, uint16_t, 4, 0, 16);

// }}}USR
// }}}RME
// {{{RME classifier 'sequencerState' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'opcodeEnum_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'manipulationEnum_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'miscellaneousEnum_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'jumpEnum_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'argValue_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classifier 'sequencerState'

// {{{RME classAttribute 'GLOBAL'
const long sequencer::sequencerState::GLOBAL( 0 );
// }}}RME

// {{{RME classAttribute 'LOCAL'
const long sequencer::sequencerState::LOCAL( 1 );
// }}}RME

// {{{RME classAttribute 'NUM_EXT_GLOBALS'
const Integer sequencer::sequencerState::NUM_EXT_GLOBALS( 4 );
// }}}RME

// {{{RME classAttribute 'PSEUDO_LOCAL'
const Integer sequencer::sequencerState::PSEUDO_LOCAL( 2 );
// }}}RME

// {{{RME classAttribute 'PSEUDO_LOCAL_INDEX'
const Integer sequencer::sequencerState::PSEUDO_LOCAL_INDEX( 16 );
// }}}RME

// {{{RME classAttribute 'REGISTER_UNUSED'
const Integer sequencer::sequencerState::REGISTER_UNUSED( 0x7F );
// }}}RME

// {{{RME classAttribute 'WORD_SIZE'
const Integer sequencer::sequencerState::WORD_SIZE( 3 );
// }}}RME

// {{{RME classAttribute 'DATASTORE_REG_NUM_MASK'
const Integer sequencer::sequencerState::DATASTORE_REG_NUM_MASK( 0x0F );
// }}}RME

// {{{RME classAttribute 'DATASTORE_FLAG_MASK'
const Integer sequencer::sequencerState::DATASTORE_FLAG_MASK( 0x70 );
// }}}RME

// {{{RME classAttribute 'DATASTORE_S_FLAG_MASK'
const Integer sequencer::sequencerState::DATASTORE_S_FLAG_MASK( 0x80 );
// }}}RME

// {{{RME operation 'compareUpdateProgramCounter(Boolean,Integer,Integer)'
void sequencer::sequencerState::compareUpdateProgramCounter( Boolean compareResult, Integer offsetReg, Integer offset )
{
	// {{{USR
	  programCounter += (compareResult) ? ((offsetReg != REGISTER_UNUSED) ? (getDataSource(offsetReg)+offset) : offset) : 0;  
	// }}}USR
}
// }}}RME

// {{{RME operation 'getDataSource(Integer)'
Integer sequencer::sequencerState::getDataSource( Integer source )
{
	// {{{USR
	  Integer sourceTypeValue = (source & DATASTORE_FLAG_MASK) >> 4; // either accessVal or regType
	  Integer sourceNumber    = (source & DATASTORE_REG_NUM_MASK);   // either dataStoreNum or regNum
	  
	  return ((source & DATASTORE_S_FLAG_MASK) == 1)?
	    (getDataStore(sourceTypeValue, sourceNumber)):
	    (getRegister(sourceTypeValue, sourceNumber));  
	// }}}USR
}
// }}}RME

// {{{RME operation 'getDataStore(Integer,Integer)'
Integer sequencer::sequencerState::getDataStore( Integer accessValue, Integer dataStoreNumber )
{
	// {{{USR
	  Integer getRegisterType;
	  Integer getRegisterValue;
	  Integer arguments[2];

	  if (accessValue < NUM_EXT_GLOBALS)
	  {
	    getRegisterType = GLOBAL;
	    getRegisterValue = accessValue;
	  }
	  else
	  {
	    getRegisterType = LOCAL;
	    getRegisterValue = accessValue - NUM_EXT_GLOBALS;
	  }

	  // set arguments
	  arguments[0] = dataStoreNumber;
	  arguments[1] = getRegister(getRegisterType, getRegisterValue);
	  
	  return dataStoreInterface->rfInterface(DataInterface::OP_GET_DATA, arguments, DataInterface::TWO_ARGUMENTS);
	// }}}USR
}
// }}}RME

// {{{RME operation 'getRegister(Integer,Integer)'
long sequencer::sequencerState::getRegister( Integer registerType, Integer registerNumber )
{
	// {{{USR
	  return (registerType == GLOBAL)?
	    globalRegisters[registerNumber]:
	    localRegisters[((registerType == PSEUDO_LOCAL)?PSEUDO_LOCAL_INDEX:0)+ registerNumber];  
	// }}}USR
}
// }}}RME

// {{{RME operation 'nextInstruction()'
void sequencer::sequencerState::nextInstruction( void )
{
	// {{{USR
	  currentInstruction = startInstruction + (WORD_SIZE * ++programCounter);  
	// }}}USR
}
// }}}RME

// {{{RME operation 'sequencerState(long *,sequencerComponent*,opwordPtr_t)'
sequencer::sequencerState::sequencerState( long * globalPtr, sequencerComponent * dataStoreInterfacePtr, opwordPtr_t startInstPtr )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	  globalRegisters = globalPtr;
	  dataStoreInterface = dataStoreInterfacePtr;

	  startInstruction = startInstPtr;
	  currentInstruction = startInstruction;
	  
	  // initialize PC to 0
	  programCounter = 0;
	  
	  // clear local registers
	  for (Integer i = 0; i < NUM_LOCAL_REG; i++)
	  {
	    localRegisters[i] = 0;
	  }

	  pseudoGlobals = &localRegisters[16];  
	// }}}USR
}
// }}}RME

// {{{RME operation 'setDataSource(Integer,Integer)'
void sequencer::sequencerState::setDataSource( Integer source, Integer value )
{
	// {{{USR
	  Integer registerType   = (source & DATASTORE_FLAG_MASK) >> 4;
	  Integer registerNumber = (source & DATASTORE_REG_NUM_MASK);
	  
	  if ((source & DATASTORE_S_FLAG_MASK) == 0)  // if s-flag clear
	  {
	    setRegister(registerType, registerNumber, value);
	  }  
	// }}}USR
}
// }}}RME

// {{{RME operation 'setRegister(Integer,Integer,long)'
void sequencer::sequencerState::setRegister( Integer registerType, Integer registerNumber, long value )
{
	// {{{USR
	  (registerType == GLOBAL)?
		  globalRegisters[registerNumber]:
		  localRegisters[((registerType == PSEUDO_LOCAL)?PSEUDO_LOCAL_INDEX:0)+ registerNumber] = value;
	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME classifier 'argValue_t'

// }}}RME

// {{{RME classAttribute 'DATA_INTERFACE_COMPONENT_INDEX'
const Integer sequencer::DATA_INTERFACE_COMPONENT_INDEX( 0 );
// }}}RME

// {{{RME classAttribute 'ENDSEQ'
const Integer sequencer::ENDSEQ( 255 );
// }}}RME

// {{{RME classAttribute 'MAX_JUMP_ARG'
const Integer sequencer::MAX_JUMP_ARG( 2 );
// }}}RME

// {{{RME operation 'call(Integer,long *,sequencerComponent*)'
void sequencer::call( Integer sequenceID, long * globalPtr, sequencerComponent * dataStoreInterfacePtr )
{
	// {{{USR
	  sequencerState* nextScope = new sequencerState(globalPtr, dataStoreInterfacePtr, sequences[sequenceID]);
	  runSequence(nextScope);
	  delete nextScope;

	// }}}USR
}
// }}}RME

// {{{RME operation 'compareSwitch(Integer,Integer,Integer)'
Boolean sequencer::compareSwitch( Integer comparison, Integer operand1, Integer operand2 )
{
	// {{{USR
	  Boolean retValue = false;
	  
	  switch(comparison)
	  {
	  case ALWAYS:    // 0000
	    {
	      retValue = true;
	      break;
	    }
	  case EQUAL:     // 0001
	    {
	      retValue = compEqual(operand1, operand2);
	      break;
	    }
	  case NOTEQUAL:  // 0010
	    {
	      retValue = compNotEqual(operand1, operand2);
	      break;
	    }
	  case GREATER:   // 0011
	    {
	      retValue = compGreater(operand1, operand2);
	      break;
	    }
	  case LESS:      // 0100
	    {
	      retValue = compLess(operand1, operand2);
	      break;
	    }
	  case GREATEREQ: // 0101
	    {
	      retValue = compGreaterEq(operand1, operand2);
	      break;
	    }
	  case LESSEQ:    // 0110
	    {
	      retValue = compLessEq(operand1, operand2);
	      break;
	    }
	  default: 
	    {
	      break;
	    }
	  }
	  
	  return retValue;  

	// }}}USR
}
// }}}RME

// {{{RME operation 'compEqual(Integer,Integer)'
Boolean sequencer::compEqual( Integer operand1, Integer operand2 )
{
	// {{{USR
	  return (operand1 == operand2);  

	// }}}USR
}
// }}}RME

// {{{RME operation 'compGreater(Integer,Integer)'
Boolean sequencer::compGreater( Integer operand1, Integer operand2 )
{
	// {{{USR
	  return (operand1 > operand2);  

	// }}}USR
}
// }}}RME

// {{{RME operation 'compGreaterEq(Integer,Integer)'
Boolean sequencer::compGreaterEq( Integer operand1, Integer operand2 )
{
	// {{{USR
	  return (operand1 >= operand2);  

	// }}}USR
}
// }}}RME

// {{{RME operation 'compLess(Integer,Integer)'
Boolean sequencer::compLess( Integer operand1, Integer operand2 )
{
	// {{{USR
	  return (operand1 < operand2);  

	// }}}USR
}
// }}}RME

// {{{RME operation 'compLessEq(Integer,Integer)'
Boolean sequencer::compLessEq( Integer operand1, Integer operand2 )
{
	// {{{USR
	  return (operand1 <= operand2);  

	// }}}USR
}
// }}}RME

// {{{RME operation 'compNotEqual(Integer,Integer)'
Boolean sequencer::compNotEqual( Integer operand1, Integer operand2 )
{
	// {{{USR
	  return (operand1 != operand2);  

	// }}}USR
}
// }}}RME

// {{{RME operation 'delay(UInteger)'
void sequencer::delay( UInteger time )
{
	// {{{USR
	  sequenceTimer->delay(time);

	// }}}USR
}
// }}}RME

// {{{RME operation 'executeImmdOpcode(Integer,sequencerState*)'
void sequencer::executeImmdOpcode( Integer returnRegister, sequencerState * currentState )
{
	// {{{USR
	  // Create a new array arguments and initalized the array with the current immediate data.  
	  Integer arguments[] = {getImmdData(currentState->currentInstruction)};
	  
	  // update returnRegister's value with result of execution
	  currentState->setRegister(sequencerState::LOCAL, returnRegister, 
	    componentTable[getBitField(currentState->currentInstruction, COMPONENT)] // call selected component's
	      ->rfInterface(getBitField(currentState->currentInstruction, OP_TYPE),  // rfInterface with interface,
	                    arguments, 1));                                          // immediate argument data, and 1 data parameter  

	// }}}USR
}
// }}}RME

// {{{RME operation 'executeOpcode(Integer,sequencerState*)'
void sequencer::executeOpcode( Integer returnRegister, sequencerState * currentState )
{
	// {{{USR
	  argValue_t arguments = getArguments(currentState, MAX_ARGUMENTS);
	  
	  // update returnRegister's value with result of execution
	  currentState->setRegister(sequencerState::LOCAL, returnRegister, 
	    componentTable[getBitField(currentState->currentInstruction, COMPONENT)] // call selected component's
	      ->rfInterface(getBitField(currentState->currentInstruction, OP_TYPE),  // rfInterface with interface, 
	                    (Integer*)arguments.data, arguments.number));                      // argument data, and the number of arguments.

	// }}}USR
}
// }}}RME

// {{{RME operation 'getArguments(sequencerState*,Integer)'
sequencer::argValue_t sequencer::getArguments( sequencerState * currentState, Integer numSources )
{
	// {{{USR
	  opwordPtr_t argumentWord = currentState->currentInstruction;
	  argValue_t argValueReturn;
	  Integer currentDataSource;
	  
	  argValueReturn.data[0] = getBitField(argumentWord,SOURCE1);
	  argValueReturn.data[1] = getBitField(argumentWord,SOURCE2);
	  argValueReturn.data[2] = getBitField(argumentWord,SOURCE3);
	  argValueReturn.data[3] = getBitField(argumentWord,SOURCE4);
	  
	  for (currentDataSource = 0; (currentDataSource < numSources) && (argValueReturn.data[currentDataSource] != sequencerState::REGISTER_UNUSED); currentDataSource++)
	  {
	    argValueReturn.data[currentDataSource] = currentState->getDataSource(argValueReturn.data[currentDataSource]);
	  }
	  
	  argValueReturn.number = currentDataSource;
	  return argValueReturn;

	// }}}USR
}
// }}}RME

// {{{RME operation 'getImmdData(opwordPtr_t)'
Integer sequencer::getImmdData( opwordPtr_t sequencerWord )
{
	// {{{USR
	  return (getBitField(sequencerWord, DATA1) << 16) + getBitField(sequencerWord, DATA2);

	// }}}USR
}
// }}}RME

// {{{RME operation 'jumpImmdOpcode(Integer,sequencerState*)'
void sequencer::jumpImmdOpcode( Integer comparison, sequencerState * currentState )
{
	// {{{USR
	  // if compare result is true, then update program counter for jump
	  currentState->compareUpdateProgramCounter(compareSwitch(comparison, currentState->getDataSource(getBitField(currentState->currentInstruction, JUMP_OPERAND1)), (int)((int16_t)getBitField(currentState->currentInstruction, JUMP_OPERAND2))), getBitField(currentState->currentInstruction, JUMP_OFFSET_REG), (int)((signed char)getBitField(currentState->currentInstruction, JUMP_OFFSET)));  

	// }}}USR
}
// }}}RME

// {{{RME operation 'jumpOpcode(Integer,sequencerState*)'
void sequencer::jumpOpcode( Integer comparison, sequencerState * currentState )
{
	// {{{USR
	  currentState->compareUpdateProgramCounter(compareSwitch(comparison, currentState->getDataSource(getBitField(currentState->currentInstruction, JUMP_OPERAND1)), (getArguments(currentState, MAX_JUMP_ARG)).data[0]), getBitField(currentState->currentInstruction, JUMP_OFFSET_REG), (int)((signed char)getBitField(currentState->currentInstruction, JUMP_OFFSET)));  

	// }}}USR
}
// }}}RME

// {{{RME operation 'manipAdd(Integer,Integer)'
Integer sequencer::manipAdd( Integer destinationData, Integer sourceData )
{
	// {{{USR
	  return (destinationData + sourceData);  

	// }}}USR
}
// }}}RME

// {{{RME operation 'manipAnd(Integer,Integer)'
Integer sequencer::manipAnd( Integer destinationData, Integer sourceData )
{
	// {{{USR
	  return (destinationData & sourceData);  

	// }}}USR
}
// }}}RME

// {{{RME operation 'manipLoad(Integer,Integer)'
Integer sequencer::manipLoad( Integer destinationData, Integer sourceData )
{
	// {{{USR
	  return sourceData;  

	// }}}USR
}
// }}}RME

// {{{RME operation 'manipNot(Integer)'
Integer sequencer::manipNot( Integer destinationData )
{
	// {{{USR
	  return (~destinationData);  

	// }}}USR
}
// }}}RME

// {{{RME operation 'manipOr(Integer,Integer)'
Integer sequencer::manipOr( Integer destinationData, Integer sourceData )
{
	// {{{USR
	  return (destinationData | sourceData);  

	// }}}USR
}
// }}}RME

// {{{RME operation 'manipSubtract(Integer,Integer)'
Integer sequencer::manipSubtract( Integer destinationData, Integer sourceData )
{
	// {{{USR
	  return destinationData - sourceData;  

	// }}}USR
}
// }}}RME

// {{{RME operation 'manipulateImmdOpcode(Integer,sequencerState*)'
void sequencer::manipulateImmdOpcode( Integer operation, sequencerState * currentState )
{
	// {{{USR
	  Integer destination = getBitField(currentState->currentInstruction, MAN_DESTINATION);
	  
	  // set destination with result of manipulation
	  currentState->setDataSource(destination, manipulateSwitch(operation, currentState->getDataSource(destination), getImmdData(currentState->currentInstruction)));

	// }}}USR
}
// }}}RME

// {{{RME operation 'manipulateOpcode(Integer,sequencerState*)'
void sequencer::manipulateOpcode( Integer operation, sequencerState * currentState )
{
	// {{{USR
	  Integer destination = getBitField(currentState->currentInstruction, MAN_DESTINATION);
	  
	  // set destination with result of manipulation
	  currentState->setDataSource(destination, manipulateSwitch(operation, currentState->getDataSource(destination), (getArguments(currentState, MAX_ARGUMENTS)).data[0]));  

	// }}}USR
}
// }}}RME

// {{{RME operation 'manipulateSwitch(Integer,Integer,Integer)'
Integer sequencer::manipulateSwitch( Integer operation, Integer operand1, Integer operand2 )
{
	// {{{USR
	  Integer retValue;
	  
	  switch(operation)
	  {
	  case LOAD:     // 0000
	    {
	      retValue = manipLoad(operand1, operand2);
	      break;
	    }
	  case ADD:      // 0001
	    {
	      retValue = manipAdd(operand1, operand2);
	      break;
	    }
	  case SUBTRACT: // 0010
	    {
	      retValue = manipSubtract(operand1, operand2);
	      break;
	    }
	  case AND:      // 0011
	    {
	      retValue = manipAnd(operand1, operand2);
	      break;
	    }
	  case OR:       // 0100
	    {
	      retValue = manipOr(operand1, operand2);
	      break;
	    }
	  case XOR:      // 0101
	    {
	      retValue = manipXor(operand1, operand2);
	      break;
	    }
	  case NOT:    // 0110
	    {
	      retValue = manipNot(operand1);
	      break;
	    }
	  default: break;
	  }
	  
	  return retValue;  

	// }}}USR
}
// }}}RME

// {{{RME operation 'manipXor(Integer,Integer)'
Integer sequencer::manipXor( Integer destinationData, Integer sourceData )
{
	// {{{USR
	  return (destinationData ^ sourceData);  

	// }}}USR
}
// }}}RME

// {{{RME operation 'miscellaneousImmdOpcode(Integer,sequencerState*)'
void sequencer::miscellaneousImmdOpcode( Integer operation, sequencerState * currentState )
{
	// {{{USR
	  miscSwitch(operation, getImmdData(currentState->currentInstruction), currentState);  

	// }}}USR
}
// }}}RME

// {{{RME operation 'miscellaneousOpcode(Integer,sequencerState*)'
void sequencer::miscellaneousOpcode( Integer operation, sequencerState * currentState )
{
	// {{{USR
	  miscSwitch(operation, (getArguments(currentState, MAX_ARGUMENTS)).data[0], currentState);  

	// }}}USR
}
// }}}RME

// {{{RME operation 'miscSwitch(Integer,Integer,sequencerState*)'
void sequencer::miscSwitch( Integer operation, Integer arguments, sequencerState * currentState )
{
	// {{{USR
	  switch(operation)
	  {
	  case DELAY:
	    {
	      delay((UInteger)arguments);
	      break;
	    }
	  case CALL:
	    {
	      call(arguments, currentState->pseudoGlobals, currentState->dataStoreInterface);
	    }
	  default:
	    {
	      break;
	    }
	  }  

	// }}}USR
}
// }}}RME

// {{{RME operation 'opcodeSwitch(Integer,sequencerState*)'
void sequencer::opcodeSwitch( Integer opcode, sequencerState * currentState )
{
	// {{{USR
	  Integer subType = getBitField(currentState->currentInstruction, OPCODE_SUBTYPE);
	  
	  switch(opcode)
	  {
	  case EXECUTEI: // 0000
	    {
	      executeImmdOpcode(subType, currentState);
	      break;
	    }
	  case EXECUTE:  // 0001
	    {
	      executeOpcode(subType, currentState);
	      break;
	    }
	  case JUMPI:    // 0100
	    {
	      jumpImmdOpcode(subType, currentState);
	      break;
	    }
	  case JUMP:     // 0101
	    {
	      jumpOpcode(subType, currentState);
	      break;
	    }
	  case MANIPI:   // 1000
	    {
	      manipulateImmdOpcode(subType, currentState);
	      break;
	    }
	  case MANIP:    // 1001
	    {
	      manipulateOpcode(subType, currentState);
	      break;
	    }
	  case MISCI:    // 1110
	    {
	      miscellaneousImmdOpcode(subType, currentState);
	      break;
	    }
	  case MISC:     // 1111
	    {
	      miscellaneousOpcode(subType, currentState);
	      break;
	    }
	  default: break;
	  }  

	// }}}USR
}
// }}}RME

// {{{RME operation 'runSequence(sequencerState*)'
void sequencer::runSequence( sequencerState * currentState )
{
	// {{{USR
	  // execute instructions and get new instructions while not at end of sequence
	  while (getBitField(currentState->currentInstruction, OPCODE) != ENDSEQ)
	  {
	    // do operation indexed by opcode
	    opcodeSwitch(getBitField(currentState->currentInstruction, OPCODE_TYPE),
	                 currentState);
	    
	    // get next sequence instruction
	    currentState->nextInstruction();
	  }  

	// }}}USR
}
// }}}RME

// {{{RME operation 'sequencer(opwordPtr_t*,sequencerComponent**,sequencerTimer*)'
sequencer::sequencer( opwordPtr_t * sequencePtr, sequencerComponent * * componentTablePtr, sequencerTimer * timerPtr )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	  sequences = sequencePtr;             // table of sequences
	  componentTable = componentTablePtr;  // table of sequencerComponent subclasses
	  sequenceTimer = timerPtr;            // pointer to timer object  

	// }}}USR
}
// }}}RME

// {{{RME operation '~sequencer()'
sequencer::~sequencer( void )
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'executeSequence(unsigned int)'
bool sequencer::executeSequence( unsigned int sequenceID )
{
	// {{{USR
	  // Call the new sequence using the top level global registers and data stores.
	  call(sequenceID, globalRegisters, componentTable[DATA_INTERFACE_COMPONENT_INDEX]);

	return true;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setRegister(unsigned int,long)'
void sequencer::setRegister( unsigned int reg, long value )
{
	// {{{USR
	  globalRegisters[reg] = value; 
	// }}}USR
}
// }}}RME

// {{{RME operation 'getRegister(unsigned int)'
long sequencer::getRegister( unsigned int reg )
{
	// {{{USR
	  return globalRegisters[reg]; 
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'sequencerState' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'opcodeEnum_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'manipulationEnum_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'miscellaneousEnum_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'jumpEnum_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'argValue_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
