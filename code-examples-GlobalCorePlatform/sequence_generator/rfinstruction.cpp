#include "rfinstruction.h"

//Constructor
RfInstruction::RfInstruction(char *str,unsigned char op,int ovr) : AsmInstruction(str),opcode(op),overrides(ovr)
{
}

//Duplicate
AsmInstruction *RfInstruction::duplicate()
{
	return new RfInstruction(inst,opcode,overrides);
}

//Validate that min <= n <= max, throw exception with 'str' otherwise
void RfInstruction::validate(int n,int min,int max,char *str)
{
	if (n < min || n > max) 
	{
		throw new Exception("Register out-of-bounds, ",str);
	}
}

//Generate register encoding for given expression
unsigned char RfInstruction::generateRegister(char *exp,SymbolTable *st,int id)
{
	unsigned char ret = 0;

	switch (id)
	{
		case ARG_LOCAL:
			ret = Argument::getValue(lexStrip.parse(exp),st);	//Evaluate
			validate(ret,0,31,"Local only 0-31 allowed");
			ret += 0x10;										//Offset Global index
			break;
		case ARG_GLOBAL:
			ret = Argument::getValue(lexStrip.parse(exp),st);	//Evaluate
			validate(ret,0,15,"Global only 0-15 allowed");
			break;
		case ARG_DATA:
			{
				int length;
				char *temp = getArgument(exp,':');				//Split at the ':'
				ret = Argument::getValue(lexStrip.parse(exp),st);//Evaluate data store number
				validate(ret,0,15,"Data Store only 0-15 allowed");
				
				//ID must be either GLOBAL or LOCAL, this is a prerequisit of reaching here...
				lexArg.parse(temp,id,length);					//'id' updated to matched 'event'
				temp = lexStrip.parse(temp);					//Strip register prefix
				ret += (((*temp - '0') + ((id == ARG_LOCAL)?4:0)) << 4);
			}
			ret |= 0x80;										//Set S = 1
			break;
	}
	return (ret);
}

//Generate immediate encoding for given expression, using BIG ENDIAN order, size 'len'
int RfInstruction::generateImmediate(unsigned char *store,char *exp,SymbolTable *st,int len)
{
	int ret;

	ret =  Argument::getValue(lexStrip.parse(exp),st);			//Evaluate
	storeImmediate(store,ret,len);								//save
	return ret;
}

//Store immediate encoding, using BIG ENDIAN order, size 'len'
void RfInstruction::storeImmediate(unsigned char *store,int arg,int len)
{
	while(len-- > 0)
	{
		store[len] = arg & 0xFF;								//Keep low byte
		arg = arg >> 8;
	}
}

//Setup store for given size
void RfInstruction::setupBuffer()
{
	AsmInstruction::setupBuffer(instSize);						//Call base class method

	//Initialize instruction buffer
	(*this)[0] = 0xF0;
	(*this)[1] = 0x00;
	(*this)[2] = unusedReg;
	(*this)[3] = unusedReg;
	(*this)[4] = unusedReg;
	(*this)[5] = unusedReg;
}

//Form an instruction and get return the remaining string
char *RfInstruction::form(char *args,SymbolTable *st,int pc)
{
	//registers needed for instruction
	char *start;
	int length,id;
	bool immediate = false;									//flag for immediate data

	setupBuffer();											//Initialize buffer

	//Special case opcodes
	if ((overrides & NO_ARGS) != 0)
	{
		(*this)[0] = opcode;
		return args;
	}

	if (args == NULL) throw new Exception("Illegal number of parameters");

	//RF Instructions have two variants
	// A - dReg,Immediate data
	// B - dReg,sReg

	//Destination
	if ((overrides & NO_DESTINATION) == 0)
	{
		//get destination register...
		start = args;
		args = getArgument(args,',');							//Split at separator	
		lexArg.parse(start,id,length);							//'id' updated to matched 'event'

		//Determine register type
		switch (id)
		{
		case ARG_LOCAL:
		case ARG_GLOBAL:
			(*this)[destStart] = generateRegister(start,st,id);	//Setup destination reg
			break;
		default:
			throw new Exception("Unrecognized register format for destination:",start);
		}
	}

	//Source
	if ((overrides & NO_SOURCE) == 0)
	{
		//Determine source type
		start = args;
		args = getArgument(args,',');								//Split at separator	
		lexArg.parse(start,id,length);								//'id' updated to matched 'event'

		//Determine register type
		switch (id)
		{
		case ARG_LOCAL:
		case ARG_GLOBAL:
		case ARG_DATA:
			(*this)[operandStart] = generateRegister(start,st,id);
			break;
		case ARG_IMMEDIATE:
			generateImmediate(&(*this)[operandStart],start,st,(overrides & IMM_16BIT) == 0?4:2);
			immediate = true;
			break;
		default:
			throw new Exception("Unrecognized register format for source:",start);
		}
	}

	//Setup opcode, destination & component
	(*this)[0] = opcode + (immediate?0x00:nonImmediateFlag);

	return args;												//return remaining string
}

//Array of standard expressions.  These are matched IN ORDER
const RegularExpression * const RfInstruction::parseArg[] =
{
    //A Local register
    new RegularExpression("( |\t)*(L|l)[0-9]([0-9])?"),

	//A global register
	new RegularExpression("( |\t)*(G|g)[0-9]([0-9])?"),

	//An immediate
	new RegularExpression("( |\t)*(%#)"),

	//A data register
	new RegularExpression("( |\t)*(D|d)[0-9]([0-9])?( |\t)*:( |\t)*(((L|l)[0-3])|((G|g)[0-3]))"),
};

LexAna RfInstruction::lexArg((RegularExpression**)parseArg,sizeof(parseArg)/sizeof(RegularExpression*));

//Array of standard expressions.  These are matched IN ORDER
const RegularExpression * const RfInstruction::parseStrip[] =
{
    //A Local register
    new RegularExpression("( |\t)*((L|l)|(G|g)|(D|d)|(%#))"),
};

LexAna RfInstruction::lexStrip((RegularExpression**)parseStrip,sizeof(parseStrip)/sizeof(RegularExpression*));
