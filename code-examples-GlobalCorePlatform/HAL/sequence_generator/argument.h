#ifndef CL_ARGUMENT
#define CL_ARGUMENT

#include "lexana.h"
#include "symboltable.h"
#include "exception.h"

//An exception occurs in an argument
class ArgumentException : public Exception
{
public:
	ArgumentException(char *str) : Exception(str)
	{}
	ArgumentException(char *str,char *str1,int len) : Exception(str,str1,len)
	{}
};

class Argument
{
private:
	static const RegularExpression * const parseExp[];
    static LexAna lex;								//Lexical analyser
	static const RegularExpression * const parseOp[];
    static LexAna lexop;							//Lexical analyser
	static const RegularExpression * const parseWS[];
    static LexAna lexws;							//Lexical analyser

	static const int precedence[]; 
	static const int parenthsisPrec;

	//Enumerates of main events (mathces expressions)
	static enum mainEvents
	{
		HEX_NUM1=0,
		HEX_NUM2,
		BIN_NUM,
		DEC_NUM,
		SYMBOL,
	};

	static enum opEvents
	{
		ADD=0,
		SUB,
		MULT,
		DIV,
		SHIFT_R,
		SHIFT_L,
		BIT_AND,
		BIT_OR,
		BIT_XOR,
		BIT_INVERT,
	};


	static char *evaluate(char *s,int &val,int &prec,SymbolTable *symb);//Evaluate an expression
	static char *data(char *s,int &val,SymbolTable *symb);				//Evaluate a data item
	static char *separator(char *s,int &sep);			//Find separator

	//Conversion routines
	static int binaryToInteger(char *s,int count);		//Ascii binary to integer
	static int hexToInteger(char *s,int count);			//Ascii hex to integer
	static int decimalToInteger(char *s,int count);		//Ascii decimal to integer

public:
	static int getValue(char *s,SymbolTable *st);		//evaluate expression
};


#endif