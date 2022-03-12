#include "asminstruction.h"
#include "exception.h"
#include <string.h>

//Constructor
AsmInstruction::AsmInstruction(char *str) : inst(str),store(NULL),size(0)
{
}

//Constructor
AsmInstruction::AsmInstruction() : inst(NULL),store(NULL),size(0)
{
}

//get an argument by splitting at given separator (case sensitive)
//Returns NULL if no separator is found
char *AsmInstruction::getArgument(char *args,char sep)
{
	char *ret = NULL;
	while (args != NULL && *args != '\0' && *args != sep)
	{
		args++;
	}
	if (args != NULL && *args == sep)
	{
		ret = args;
		*ret++ = '\0';										//terminate argument
	}
	return ret;
}

//Match routine (case insensitive on input string)
bool AsmInstruction::match(char *str)
{
	char *temp = inst;
	char s = *str;

	//Loop until end of string found
	while (*temp != '\0' && *str != '\0')
	{
		s = s >= 'a' && s <= 'z' ? s - 0x20:s;		//Convert to upper case
		if (*temp != s) break;						//If not matched, exit 
		temp++;
		s = *(++str);
	}
	return (*temp == s);
}

//Get current instruction size
int AsmInstruction::getSize()
{
	return size;
}

//destructor
AsmInstruction::~AsmInstruction()
{
	delete [] store;
}

//Setup store for given size
void AsmInstruction::setupBuffer(int s)
{
	size = s;
	store = new unsigned char[size];					//Array of data
}

//Accessor
unsigned char & AsmInstruction::operator [](int loc)
{
	if (loc < 0 || loc >= size) throw new Exception("out-of-bounds array access in instruction");
	return store[loc];
}
