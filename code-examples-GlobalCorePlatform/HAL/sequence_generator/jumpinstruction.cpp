#include "jumpinstruction.h"
#include <string.h>
#include <iostream.h>

//Constructor (Opcode 0x0, variant 0x0)
JumpInstruction::JumpInstruction(char *str,unsigned char op,int ovr) : RfInstruction(str,op,ovr|RfInstruction::IMM_16BIT)
{
}

//Duplicate
AsmInstruction *JumpInstruction::duplicate()
{
	return new JumpInstruction(inst,opcode,overrides);
}

//Form an instruction and get return the size
char *JumpInstruction::form(char *args,SymbolTable *st,int pc)
{
	//registers needed for instruction
	char *start;
	int length,id;
	bool immediate = false;									//flag for immediate data

	args = RfInstruction::form(args,st);						//Build Source and Dest data + opcode

	if (args == NULL) throw new Exception("No destination specified");

	//Now determine jump destination...
	//Rn:offset or offset

	//Determine source type
	start = args;
	args = getArgument(args,':');								//Split at separator	
	lexArg.parse(start,id,length);								//'id' updated to matched 'event'

	//Determine register type
	switch (id)
	{
	case ARG_LOCAL:
	case ARG_GLOBAL:
	case ARG_DATA:
		(*this)[destJumpReg] = generateRegister(start,st,id);
		break;
	//Assume that this is an offset...
	default:
		//Offset = Offset - PC - 1 (in instructions, so divide by size)
		int imm = (Argument::getValue(start,st) - pc)/getSize() - 1;
		storeImmediate(&(*this)[destJumpOffset],imm,1);//A single byte offset
		immediate = true;
		break;
	}

	//If the first argument was NOT immediate, then force an immediate (defaults to 0)
	if (!immediate)
	{
		storeImmediate(&(*this)[destJumpOffset],Argument::getValue(args,st),1);//A single byte offset
	}

	return args;
}


