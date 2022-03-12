#include "symboltable.h"

#include <string.h>
#include "exception.h"

//constructor
SymbolTable::SymbolTable() : head(NULL)
{

}

//Add an entry to the list (keeps entries unique)
bool SymbolTable::add(SymbolTableEntry *ent)
{
	//If this entry already exists, throw an exception...
	if (find(ent->name) == NULL)
	{
		ent->next = head;
		head = ent;
	}
	else
	{
		throw new Exception("Duplicate Symbol : ",ent->name);
	}
	return true;
}

//Search for an entry
SymbolTableEntry * SymbolTable::find(char *key,int len)
{
	SymbolTableEntry *current = head;
	while (current != NULL)
	{
		if (current->match(key,len)) break;
		current = current->next;
	}
	return current;
}

//Dump all Symbols
void SymbolTable::dump(ostream &log)
{
	SymbolTableEntry *current = head;
	while (current != NULL)
	{
		log << current->name << "==" << current->value << endl;
		current = current->next;
	}
}

/**************************************************************************************/
#include "argument.h"

//Match an entry to given key
bool SymbolTableEntry::match(char *key,int len)
{
	return (len == -1?strcmp(key,name):(len == nameLen?strncmp(key,name,len):1)) == 0;
}

//Constructor
SymbolTableEntry::SymbolTableEntry(char *key, int val) : value(val)
{
	nameLen = strlen(key);
	name = new char[nameLen + 1];
	strcpy(name,key);
}

//Destructor
SymbolTableEntry::~SymbolTableEntry()
{
	delete [] name;
}

//Return current value
int SymbolTableEntry::getValue()
{
	return value;
}
