#include "execinstruction.h"

//Constructor (Opcode 0x0, variant 0x0)
ExecInstruction::ExecInstruction() : RfInstruction("EXEC",0x0)
{}

//Duplicate
AsmInstruction *ExecInstruction::duplicate()
{
	return new ExecInstruction();
}

//Form an instruction and get return the size
char *ExecInstruction::form(char *args,SymbolTable *st,int pc)
{
	//registers needed for instruction
	char *start;
	int length,id;
	int destReg;											//The destination of the exec
	int component;											//The component
	int method;												//The interface
	int passCount = 0;										//Number of registers to pass
	bool immediate = false;									//flag for immediate data

	setupBuffer();											//Initialize buffer

	if (args == NULL) throw new Exception("Illegal number of parameters");

	//Exec has two variants (both start with dReg,comp:op)
	// A - Immediate data
	// B - upto 4 parameters

	//Extract destination register
	start = args;
	args = getArgument(args,',');							//Split at separator	
	lexArg.parse(start,id,length);							//'id' updated to matched 'event'

	//Generate error if not local
	if (id != ARG_LOCAL && id != LexAna::MISS_MATCH) throw new Exception("Invalid parameter, must be Local Register");

	//Local register may be implicit in this case...
	destReg =  Argument::getValue((*start == 'L' || *start == 'l')?start+1:start,st);
	validate(destReg,0,15,"destination only 0-15 allowed");

	//Identify component
	start = args;
	args = getArgument(args,':');							//Split at separator	
	component = Argument::getValue(start,st);
	validate(component,0,31,"component only 0-31 allowed");

	//Identify method
	start = args;
	args = getArgument(args,',');							//Split at separator	
	method = Argument::getValue(start,st);
	validate(method,0,7,"interface only 0-7 allowed");

	while (!immediate && args != NULL && passCount < maxPass)
	{
		//Determine if this is an immediate or a register...
		start = args;
		args = getArgument(args,',');							//Split at separator	
		lexArg.parse(start,id,length);							//'id' updated to matched 'event'
	
		//Determine register type
		switch (id)
		{
		case ARG_LOCAL:
		case ARG_GLOBAL:
		case ARG_DATA:
			(*this)[operandStart + passCount++] = generateRegister(start,st,id);
			break;
		case ARG_IMMEDIATE:
			generateImmediate(&(*this)[operandStart],start,st);
			immediate = true;									//end loop
			break;
		default:
			throw new Exception("Unrecognized register format :",start);
		}
	}

	//Setup opcode, destination & component
	(*this)[0] = opcode + (immediate?0x00:nonImmediateFlag) + destReg;
	(*this)[1] = (component << 3) + method;

	return args;												//return remaining string
}


