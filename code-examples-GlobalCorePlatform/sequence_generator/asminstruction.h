#ifndef CL_ASMINST
#define CL_ASMINST

#include "keyword.h"
#include "argument.h"
//This is an sub class for language keywords in x86 assembly
class AsmInstruction : public KeyWord
{
private:

protected:
	unsigned char *store;									//data for instruction
	int size;												//size of store
	char *inst;												//instruction label

public:
	void setupBuffer(int size);
	AsmInstruction(char *str);								//Constructor (used for instruction set lists)
	AsmInstruction();										//Constructor
	~AsmInstruction();										//Destructor

	bool match(char *str);									//Match on this keyword
	char *getArgument(char *args,char sep = ',');			//Split at separator

	//Form an instruction (sub-class only), returning array of data length
	virtual char *form(char *args,SymbolTable *st,int pc = 0) = 0;
	int getSize();											//Get current size
	unsigned char & AsmInstruction::operator [](int loc);	//Accessor
	virtual AsmInstruction *duplicate() = 0;				//Duplicate current instruction
};

#endif
