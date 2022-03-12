#include "actions.h"
#include <string.h>
#include <iostream.h>

//Constructor
ActionData::ActionData(SymbolTable *st,int pc,int ln) : symb(st),programCounter(pc),lineNumber(ln),head(NULL)
{
}

//Add a sentence to held list
ActionData::addCurrentSentence(char *sentence,AsmInstruction *k)
{
	HeldSentence *temp = new HeldSentence;
	temp->programCounter = programCounter;
	temp->lineNumber = lineNumber;
	temp->str = sentence;
	temp->next = head;
	temp->key = k;
	head = temp;
}

////////////////////////////////////////////////////////////////////////////////
int ActionEOL::evt(StateMachineActionData *data,int count)
{
	ActionData *actData = (ActionData *)data;
	actData->lineNumber++;						//Increment line
	return ST_START;							//Force to state
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
int ActionCB::evt(StateMachineActionData *data,int count)
{
	ActionData *actData = (ActionData *)data;
	char *remainder = actData->str;
    int i,length;

	//determine the number of LF
	while (remainder != NULL && *remainder != '\0')
    {
		//Call parser.  'i' updated to matched 'event'
        remainder = lex->parse(remainder,i,length);

        //Increment based on Successful match
		actData->lineNumber += (i == LexAna::MISS_MATCH || i == LexAna::PARTIAL_MATCH)?0:1;
	}
	return ST_NOCHANGE;							//force to state
}

//Array of standard expressions.  These are matched IN ORDER
const RegularExpression * const ActionCB::parseExp[] =
{
    //any number of characters, followed by Carriage Return (LF or LF,CR)
    new RegularExpression("[ -~\t]*(\n|\r\n)"),
};

LexAna *ActionCB::lex = new LexAna((RegularExpression**)parseExp,sizeof(parseExp)/sizeof(RegularExpression*));
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
int ActionPREPROC::evt(StateMachineActionData *data,int count)
{
	ActionData *actData = (ActionData *)data;
//	cout << "PREPROCESSOR : " << actData->str << endl;
	return ST_IN_LINE;
}
////////////////////////////////////////////////////////////////////////////////
