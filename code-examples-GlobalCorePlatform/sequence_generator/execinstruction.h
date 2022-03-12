#ifndef CL_EXECINST
#define CL_EXECINST

#include "rfinstruction.h"
#include "lexana.h"

//Number of registers passed in Exec
#define maxPass 4

//Class to handle Exec instructions
class ExecInstruction : public RfInstruction
{
private:

public:
	//Constructor
	ExecInstruction();
	virtual char *form(char *args,SymbolTable *st,int pc = 0);
	virtual AsmInstruction *duplicate();					//Duplicate current instruction
};

#endif
