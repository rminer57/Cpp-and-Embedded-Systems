#ifndef CL_ACTIONS
#define CL_ACTIONS

#include "lexana.h"
#include "statemachine.h"
#include "asminstruction.h"
#include "keyword.h"
#include "symboltable.h"

const int ST_NOCHANGE = -1;
const int ST_START = 0;
const int ST_IN_LINE = 1;

class HeldSentence
{
public:
	HeldSentence *next;									//next in link

	int	programCounter;
	int lineNumber;
	char *str;
	AsmInstruction *key;								//Placeholder
};

//Common data class passed to all action handlers
class ActionData : public StateMachineActionData
{
public:
	int	programCounter;
	int lineNumber;
	char *str;
	unsigned char *buffer; 
	SymbolTable *symb;
	HeldSentence *head;

	addCurrentSentence(char *sentence,AsmInstruction *k);	//Add current sentence to list
	ActionData(SymbolTable *st,int pc = 0,int ln = 1);
};

////////////////////////////////////////////////////////////////////////////////
//Invoked when the end-of-line is encountered
class ActionEOL : public StateMachineAction
{
public:
	static int evt(StateMachineActionData *data,int count=0);
};
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//Invoked when a type B (multi-line) comment is found, to determine number of embedded EOL's
class ActionCB : public StateMachineAction
{
private:
	static const RegularExpression * const parseExp[];
    static LexAna *lex;
public:
	static int evt(StateMachineActionData *data,int count=0);
};

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
class ActionPREPROC : public StateMachineAction
{
public:
	static int evt(StateMachineActionData *data,int count=0);
};
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//This handler deals with a 'sentence' (NOTE, sentence has NO preceeding white space)
class ActionSENT : public StateMachineAction
{
private:
	static const RegularExpression * const parseExp[];
	static const RegularExpression * const parseAssign[];
    static LexAna lex;								//Lexical analyser
    static LexAna lexAssign;						//Lexical analyser
	static AsmInstruction * const instSet[];
	static const int numInst;

	//Enumerates of main events (mathces expressions below)
	enum mainEvents
	{
		CRLF=0,
		WHITE_SPACE,
		COMMENT_A,
		LABEL_WORD,
	};

public:
	static int evt(StateMachineActionData *data,int count=0);
};

////////////////////////////////////////////////////////////////////////////////
#endif