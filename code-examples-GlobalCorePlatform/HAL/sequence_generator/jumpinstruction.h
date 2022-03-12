#ifndef CL_JUMPINST
#define CL_JUMPINST

#include "rfinstruction.h"
#include "lexana.h"

#define destJumpReg 4
#define destJumpOffset 5

//Class to handle Exec instructions
class JumpInstruction : public RfInstruction
{
private:

public:
	//Constructor
	JumpInstruction(char *str,unsigned char op,int ovr = 0);
	virtual char *form(char *args,SymbolTable *st,int pc = 0);
	virtual AsmInstruction *duplicate();					//Duplicate current instruction
};

#endif
