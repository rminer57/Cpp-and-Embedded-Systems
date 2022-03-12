#ifndef CL_RFINST
#define CL_RFINST

#include "asminstruction.h"
#include "lexana.h"

#define unusedReg 0x7F

//size of instructions
#define destStart 1
#define operandStart 2
#define instSize 6

#define nonImmediateFlag 0x10

class RfInstruction : public AsmInstruction
{
private:
	
	static const RegularExpression * const parseStrip[];
    static LexAna lexStrip;									//Lexical analyser

protected:
	unsigned char opcode;									//Opcode used for instruction
	int overrides;

	static const RegularExpression * const parseArg[];
    static LexAna lexArg;									//Lexical analyser

	//Enumerates of argument events (mathces expressions)
	static enum argEvents
	{
		ARG_LOCAL=0,
		ARG_GLOBAL,
		ARG_IMMEDIATE,
		ARG_DATA,
	};

public:
	void setupBuffer();										//Setup instruction to End of sequence
	void validate(int n,int min,int max,char *str);
	unsigned char generateRegister(char *exp,SymbolTable *st,int id);
	int generateImmediate(unsigned char *store,char *exp,SymbolTable *st,int len=4);
	void storeImmediate(unsigned char *store,int arg,int len);

	virtual char *form(char *args,SymbolTable *st,int pc = 0);
	RfInstruction(char *str,unsigned char op,int ovr = 0);	//Constructor
	virtual AsmInstruction *duplicate();					//Duplicate current instruction

	static enum instOverrides
	{
		NO_DESTINATION = 0x1,								//Ignore destination
		NO_SOURCE = 0x2,									//Ignore source
		IMM_16BIT = 0x4,									//Onlt 16 bit immediate allowed
		NO_ARGS = 0x8,										//No arguments
	};
};

#endif