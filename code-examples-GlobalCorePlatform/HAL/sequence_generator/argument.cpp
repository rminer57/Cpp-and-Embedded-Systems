#include "argument.h"
#include <string.h>

/////////////////////////////////////////////////////////////////////////////
//Return the value of the argument expression
int Argument::getValue(char *s,SymbolTable *st)
{
	char *remainder = s;
	int prec = 0;
	int value = 0;

	//Evaluate expression
	remainder = evaluate(remainder,value,prec,st);

	//If prec is not ZERO, then nesting error
	return value;
}

//Evaluate an expression, returning updated position and value
char *Argument::evaluate(char *s,int &value,int &prec,SymbolTable *symb)
{	
	//Evaluate the expression
	char *remainder = s, *start;
	int op1;
	int operand2 = 0;

	//Check for parentesized expression...
	remainder = lexws.parse(remainder);			//Consume WS
	if (remainder != NULL && *remainder == '(')
	{
		remainder++;
		prec -= parenthsisPrec;					//Reduce effective precedence level
	}

	//Check for leading unary operator
	remainder = separator(remainder,op1);
	
	if (op1 != LexAna::MISS_MATCH)
	{
		//Adjust for leading operators (unary)
		prec += precedence[op1];
		remainder = evaluate(remainder,value,prec,symb);
		switch(op1)
		{
		case SUB:
			value = -value;
			break;
		case BIT_INVERT:
			value = ~value;
			break;
		}
		prec -= precedence[op1];
	}
	else
	{
		remainder = data(remainder,value,symb);
	}

	//Check for parentesized expression...
	remainder = lexws.parse(remainder);			//Consume WS
	if (remainder != NULL && *remainder == ')')
	{
		remainder++;
		prec += parenthsisPrec;					//Increase effective precedence level
	}

	//Parse out the various parts of the expression
    while (remainder != NULL && *remainder != '\0' )
    {
		//Get operator (if any)
		start = remainder;
		remainder = separator(remainder,op1);

		if (op1 != LexAna::MISS_MATCH)
		{
			//If the precedence of this operator is higher than last..
			if (precedence[op1] > prec)
			{
				prec += precedence[op1];						//Set new precedence level

				//Get second operand (recursive call)
				remainder = evaluate(remainder,operand2,prec,symb);

				//Determine action based on separator found
				switch(op1)
				{
				case ADD:
					value += operand2;
					break;
				case SUB:
					value -= operand2;
					break;
				case MULT:
					value *= operand2;
					break;
				case DIV:
					value /= operand2;
					break;
				case SHIFT_R:
					value = (value >> operand2);
					break;
				case SHIFT_L:
					value = (value << operand2);
					break;
				case BIT_AND:
					value = (value & operand2);
					break;
				case BIT_OR:
					value = (value | operand2);
					break;
				case BIT_XOR:
					value = (value ^ operand2);
					break;
				default:
					throw new Exception("Unknown operation : ",start);
				}

				prec -= precedence[op1];						//Bring back precedence
			}
			else
			{
				remainder = start;								//Go back prior to operator
				break;
			}
		}
		else
		{
			if (remainder != NULL)
			{
				throw new Exception("Unknown expression : ",start);
			}
		}
	}

	return remainder;
}

//Evaluate an expression, returning updated position and value
char *Argument::data(char *s, int &val, SymbolTable *symb)
{	
	//Evaluate the expression
	char *remainder=s,*start;
	int i;
	int length;
	
	//Parse out the various parts of the sentence
	remainder = lexws.parse(remainder);				//Consume WS
	
	start = remainder;
	remainder = lex.parse(remainder,i,length);		//'i' updated to matched 'event'

	//Determine action based on item found
	switch(i)
	{
	case DEC_NUM:
		val = decimalToInteger(start,length);
		break;
	case HEX_NUM1:
		val = hexToInteger(start+2,length-2);
		break;
	case HEX_NUM2:
		val = hexToInteger(start+1,length-1);
		break;
	case BIN_NUM:
		val = binaryToInteger(start+1,length-1);
		break;
	case SYMBOL:
		{
			//Search for symbol, and determine value
			SymbolTableEntry *ent = symb->find(start,length);
			if (ent != NULL)
			{
				val = ent->getValue();
			}
			else
			{
				throw new ArgumentException("Symbol not found : ",start,length);
			}
		}
		break;
	default:
		val = 0;
		break;
	}

	return remainder;
}

//Evaluate an expression, returning updated position and operator
char * Argument::separator(char *s, int &sep)
{	
	//Evaluate the expression
	char *remainder = s;
	int length;

	//Parse out the various parts of the sentence
	remainder = lexws.parse(remainder);				//Consume WS
	remainder = lexop.parse(remainder,sep,length);	//'i' updated to matched 'event'

	return remainder;
}

//Array of standard expressions.  These are matched IN ORDER
const RegularExpression * const Argument::parseExp[] =
{
	//A hex number (one or more digits)
	new RegularExpression("(0x)([0-9A-Fa-f]+)"),

	//A hex number (one or more digits)
	new RegularExpression("(%$)([0-9A-Fa-f]+)"),

	//A binary number (one or more digits)
	new RegularExpression("(%%)([0-1]+)"),

	//A decimal number (one or more digits)
	new RegularExpression("[0-9]+"),

	//A symbol
	new RegularExpression("([A-Za-z_$.]+)([A-Za-z0-9_$.]*)"),

	//Anything else...
    new RegularExpression("[ -~\t]*"),
};

LexAna Argument::lex((RegularExpression**)parseExp,sizeof(parseExp)/sizeof(RegularExpression*));

//Array of standard expressions.  These are matched IN ORDER
const RegularExpression * const Argument::parseOp[] =
{
	//ADD
	new RegularExpression("%+"),
	//SUB
	new RegularExpression("%-"),
	//MULT
	new RegularExpression("%*"),
	//DIV
	new RegularExpression("%/"),
	//SHIFT_R
	new RegularExpression("%>%>"),
	//SHIFT_L
	new RegularExpression("%<%<"),
	//BIT_AND
	new RegularExpression("%&"),
	//BIT_OR
	new RegularExpression("%|"),
	//BIT_XOR
	new RegularExpression("%^"),
	//BIT_INVERT
	new RegularExpression("%~"),
};

const int Argument::parenthsisPrec = 5;

//Precedence level of operators (matches enum and list above)
const int Argument::precedence[] = 
{
	1,
	1,
	2,
	2,
	3,
	3,
	1,
	1,
	1,
	1,
};

LexAna Argument::lexop((RegularExpression**)parseOp,sizeof(parseOp)/sizeof(RegularExpression*));

//White space consumer
const RegularExpression * const Argument::parseWS[] =
{
    //A comment (type A, ; or // line end delimited)
    new RegularExpression("( |\t)+(;|//)[ -~\t]*"),

		//White space (1 or more SPACE or TAB)
    new RegularExpression("( |\t)+"),

};

LexAna Argument::lexws((RegularExpression**)parseWS,sizeof(parseWS)/sizeof(RegularExpression*));

//Convert an Ascii decimal (length count) to an integer
int Argument::decimalToInteger(char *s,int count)
{
	int ret = 0;

	while (count--)
	{
		ret *= 10;								//Scale up return
		ret += (*s++ - '0');
	}

	return ret;
}

//Convert an Ascii hexadecimal (length count) to an integer
int Argument::hexToInteger(char *s,int count)
{
	int ret = 0;

	while (count--)
	{
		ret *= 16;								//Scale up return
		if (*s >= '0' && *s <= '9')
		{
			ret += (*s++ - '0');
		}
		else
		{
			ret += ((*s++ & (~0x20)) - 'A' + 10);
		}
	}

	return ret;
}

//Convert an Ascii binary (length count) to an integer
int Argument::binaryToInteger(char *s,int count)
{
	int ret = 0;

	while (count--)
	{
		ret *= 2;								//Scale up return
		ret += (*s++ - '0');
	}

	return ret;
}
