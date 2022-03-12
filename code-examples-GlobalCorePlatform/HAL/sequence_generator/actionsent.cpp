#include "actions.h"
#include <string.h>
#include <iostream.h>
#include "keyword.h"
#include "exception.h"

//Instruction specific handlers
#include "execinstruction.h"
#include "jumpinstruction.h"

//Main event method
int ActionSENT::evt(StateMachineActionData *data,int count)
{
	ActionData *actData = (ActionData *)data;
	char *remainder = actData->str;
	int length,i = -1;
	

	//Parse out the various parts of the sentence
    while (i != LABEL_WORD && remainder != NULL && *remainder != '\0')
    {
        actData->str = remainder;
        remainder = lex.parse(remainder,i,length);			//'i' updated to matched 'event'
	}

	//If OPCODE or LABEL found, parse further
	if (i == LABEL_WORD)
	{
		bool found = false;
		AsmInstruction *key = NULL;								//Placeholder

		if (remainder != NULL)
		{
			*remainder++ = '\0';
		}

		//Check for opcode match
		for (int j=0;j<numInst && !found;j++)
		{
			//Check for match against instruction.  If found, derive arguments
			if (instSet[j]->match(actData->str))
			{
				key = instSet[j]->duplicate();
				found  = true;
			}
		}

		//If an opcode has been found, form an instruction
		if (found)
		{
			char *tempCopy = NULL;
			try
			{
				if (remainder != NULL)
				{
					tempCopy = new char[strlen(remainder)+1];
					strcpy(tempCopy,remainder);								//Used for error
				}

				key->form(remainder,actData->symb,actData->programCounter);
				
				unsigned char *temp = actData->buffer + actData->programCounter;

				//Copy the data into the buffer
				for (int i=0;i<key->getSize();i++)
				{
					temp[i] = (*key)[i];								//transfer data
				}
				actData->programCounter += key->getSize();				//Update PC
	
				delete [] tempCopy;										//Not needed
			}
			catch(...)
			{
				actData->addCurrentSentence(tempCopy,key);
				actData->programCounter += key->getSize();				//Update PC
				key = NULL;												//Prevent delete
			}
		}
		//A label or equate may be found.  Determine if valid assignment
		else
		{
			try
			{
				remainder = lexAssign.parse(remainder,i,length);	//'i' updated to matched 'event'
				if (i == 0)
				{
					actData->symb->add(new SymbolTableEntry(actData->str,
						Argument::getValue(remainder,actData->symb)));
				}
				else
				{
					actData->symb->add(new SymbolTableEntry(actData->str,actData->programCounter));
				}
			}
			catch(Exception *except)
			{
				(*actData->errStream) << "ERROR ==> " << except->getDesc() << endl;
			}	
		}
		
		if (key != NULL) delete key;
	}

	return ST_IN_LINE;											//Completed a sentence
}

//Array of standard expressions.  These are matched IN ORDER
const RegularExpression * const ActionSENT::parseExp[] =
{
	//White space + Cariage Return  (LF or CR,LF)
	new RegularExpression("( |\t)*(\n|\r\n)"),

	//White space (1 or more SPACE or TAB)
    new RegularExpression("( |\t)+"),

    //White space + A comment (type A, ; or // line end delimited)
    new RegularExpression("( |\t)*(;|//)[ -~\t]*(\n|\r\n)"),

	//A label (or word)
	new RegularExpression("([A-Za-z_%.])[A-Za-z0-9_]*:?"),
};

//Array of standard expressions.  These are matched IN ORDER
const RegularExpression * const ActionSENT::parseAssign[] =
{
	//White space (1 or more SPACE or TAB), assignment operator
    new RegularExpression("( |\t)*(=|equ)( |\t)*"),
};

LexAna ActionSENT::lex((RegularExpression**)parseExp,sizeof(parseExp)/sizeof(RegularExpression*));
LexAna ActionSENT::lexAssign((RegularExpression**)parseAssign,sizeof(parseAssign)/sizeof(RegularExpression*));

//List of supported instructions (USE UPPERCASE for names, to allow case insensitice search)
AsmInstruction * const ActionSENT::instSet[] =
{
	//Exec is a separate sub-class
	new ExecInstruction(),

	//Instruction [Name][Opcode]
	new RfInstruction("LOAD",0x80),
	new RfInstruction("ADD",0x81),
	new RfInstruction("SUB",0x82),
	new RfInstruction("AND",0x83),
	new RfInstruction("OR",0x84),
	new RfInstruction("XOR",0x85),

	new JumpInstruction("JA",0x40,RfInstruction::NO_SOURCE|RfInstruction::NO_DESTINATION),
	new JumpInstruction("JEQ",0x41),
	new JumpInstruction("JNE",0x42),
	new JumpInstruction("JGT",0x43),
	new JumpInstruction("JLT",0x44),
	new JumpInstruction("JGE",0x45),
	new JumpInstruction("JLE",0x46),

	new RfInstruction("DELAY",0xE0,RfInstruction::NO_DESTINATION),
	new RfInstruction("CALL",0xE1,RfInstruction::NO_DESTINATION),
	new RfInstruction("END",0xFF,RfInstruction::NO_ARGS),
};

const int ActionSENT::numInst = sizeof(instSet)/sizeof(KeyWord*);

