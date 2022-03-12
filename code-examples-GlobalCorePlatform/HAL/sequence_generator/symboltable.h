#ifndef CL_SYMBOLTABLE
#define CL_SYMBOLTABLE

#include <iostream.h>

//Class to represent a single entry in a Symbol Table
class SymbolTableEntry
{
private:
	char *name;
	int value;
	int nameLen;
	SymbolTableEntry *next;

	friend class SymbolTable;
public:
	SymbolTableEntry(char *key,int value);				//Constructor
	~SymbolTableEntry();								//Destructor
	bool match(char *key,int len = -1);
	int getValue();
};

//Class to represent a Symbol Table
class SymbolTable
{
private:
	SymbolTableEntry *head;
public:
	void dump(ostream &log);
	SymbolTableEntry *find(char *key,int len = -1);		//Locate an entry
	bool add(SymbolTableEntry *ent);					//Add a new entry (fail if exists)
	SymbolTable();										//Constructor
};

#endif
