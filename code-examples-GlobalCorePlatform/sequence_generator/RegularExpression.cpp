#include "RegularExpression.h"
#include <string.h>

//Constructor
//Note, the string passed MUST remain for the lifetime of this Object.
RegSubExp::RegSubExp(char *base) : orLink(NULL), andLink(NULL), repeat(0)
{
    char *split;

    //Clean up the outer brackets (if any)
    base = cleanPair(base,COMPOUND_CHAR_START,COMPOUND_CHAR_END);

    //Find and split off any OR sub-expressions
    split = findSep(base,ALTERNATE_CHAR,COMPOUND_CHAR_START,COMPOUND_CHAR_END);
    if (split != NULL)
    {
        *split++ = '\0';                    //Split string
        orLink = new RegSubExp(split);
    }

    //Ok, now parse the expression, splitting off AND sub-exp..
    if (*base == COMPOUND_CHAR_START)
    {
        //Locate end of compound exp.
        split = findPair(base,COMPOUND_CHAR_END);
        *split++ = '\0';                    //Split string
        *base++ = '\0';                     //clean front
        
        //check for repeat..
        switch(*split)
        {
            case REPEAT_ZERO_PLUS:
            case REPEAT_ONE_PLUS:
            case REPEAT_ZERO_ONE:
                repeat = *split;
                *split++ = '\0';            //Remove character
        }

        //Forced to use another level...
        localValue = false;
        exp.subLink = new RegSubExp(base);

        //If any part of the string is left, create AND...
        if (*split != '\0')
        {
            andLink = new RegSubExp(split);
        }
    }

    //Ok, proceed with parsing...
    else
    {
        bool loopFlag = true;

        exp.value = base;
        localValue = true;

        //Scan for sub-expression (AND)
        while (loopFlag)
        {
            switch (*base)
            {
            case REPEAT_ZERO_PLUS:
            case REPEAT_ONE_PLUS:
            case REPEAT_ZERO_ONE:
                repeat = *base;
                *base++ = '\0';                  //Remove character

            case '\0':
            case COMPOUND_CHAR_START:
                //Terminate loop, possibly create new AND
                loopFlag = false;               //Exit
                break;

            default:
                //Adjust for escape character
                base = checkEscape(base);
                base++;
            }
        }

        //Generate any AND sub-expressions
        andLink = (*base == '\0')?NULL:new RegSubExp(base);
    }
}


//Accessor to check for match of string against expression
//Return -1 for miss-match, 0 for not equal, but not miss-match, 1 for equal
//In the case ret==0, returns remainder (or NULL) (only used by AND chains)
char *RegSubExp::match(char *str,int &ret)
{
    ret = -1;
    char *temp;

    //First check local expression...
    if (exp.value != NULL)
    {
        //Check sub-string
        temp = localValue?check(str,exp.value,ret):
                    exp.subLink->match(str,ret);

        //If partially matched...
        //2 conditions exist. len(str) < len(value) [temp==NULL]
        //or visa-versa [temp valid ->]
        //Check for Repeat conditions...
        if (ret == 0 && temp != NULL && 
            (repeat == REPEAT_ZERO_PLUS || repeat == REPEAT_ONE_PLUS))
        {
            char *loopTemp;
            do
            {
                //Try and consume more of the input
                loopTemp = temp;
                temp = localValue?check(loopTemp,exp.value,ret):
                            exp.subLink->match(loopTemp,ret);
            } while (ret == 0 && temp != NULL);
            
            //ret == 0 => temp == NULL => all comsumed...
            //ret == 1 => all consumed...
            //ret == -1 => last call not consumed, back up...
            if (ret == -1)
            {
                ret = 0;
                temp = loopTemp;            //Undo last call...
            }
        }

        //If this is optional (zero or more), ignore failure
        else if (ret == -1 && (repeat == REPEAT_ZERO_PLUS || repeat == REPEAT_ZERO_ONE))
        {
            ret = 0;
            temp = str;                     //restore
        }
    }

    //Check for conditions on AND...
    //Additional sub-expression:
    //ret == 1,           => ret = 0 (unless repeat for AND is 0+ )
    //ret == -1,          => ret = -1
    //ret == 0, temp == 0 => ret = 0
    //          temp != 0 => ret = AND(temp)
    
    //No Additional sub-expression:
    //ret == 1,           => ret = 1
    //ret == -1,          => ret = -1
    //ret == 0, temp == 0 => ret = 0
    //          temp != 0 => ret = -1 (condition detected by caller)

    //Now check AND link
    if (andLink != NULL)
    {
        switch (ret)
        {
            //If exact match already exists
        case 1:
            ret = (andLink->repeat == REPEAT_ZERO_PLUS || andLink->repeat == REPEAT_ZERO_ONE)?1:0;
            temp = NULL;                            //No remainder
            break;

            //Partial match at local level (see above for details)
        case 0:
            if (temp != NULL)
            {
                temp = andLink->match(temp,ret);
            }
        }
    }

    //If we have not matched yet, try OR condition
    if (ret != 1 && orLink != NULL)
    {
        int current;
        char *orTemp = orLink->match(str,current);

        //If a non-miss match is found, update temp and ret.
        if (current != -1)
        {
            temp = orTemp;             
            ret = current;
        }
    }

    return temp;
}


//Find a separator in a string (bypassing compound exp)
//If found returns ->, otherwise NULL
char *RegSubExp::findSep(char *str,char sep,char compStart,char compEnd)
{
    //Split string into sub-expressions (find outer OR's)
    while (*str != '\0')
    {
        if (*str == compStart)
        {
            //skip over..
            str = findPair(str,compEnd) + 1;
        }
        else if (*str == sep)
        {
            return str;                         //Found
        }
        else
        {
            str = checkEscape(str) + 1;
        }
    }
    return NULL;
}

//Check a string against an expression.
//Return -1 for miss-match, 0 for not equal, but not miss-match, 1 for equal
//returns update of "str" if exceeds "exp", else NULL
char *RegSubExp::check(char *str,char *exp,int &ret)
{
    while (*str != '\0' && *exp != '\0')
    {

		//test for ranges
        if (*exp == RANGE_CHAR_START)
        {
            if (!checkRange(*str,exp + 1))
            {
                ret = -1;                       //Miss match
                return NULL;                    //exit
            }
            exp = findPair(exp,RANGE_CHAR_END); //Update exp to skip range
        }
		//test for NOT match
		else if (*exp == MATCH_NOT)
		{
			exp++;
			exp = checkEscape(exp);
            if (*str == *exp)
            {
                ret = -1;                       //Miss match
                return NULL;                    //exit
            }
		}
        //Check current character
        else if (*exp != MATCH_WILD)
        {
			exp = checkEscape(exp);
            if (*str != *exp)
            {
                ret = -1;                       //Miss match
                return NULL;                    //exit
            }
        }
        str++;
        exp++;
    }

    //Determine return values
    ret = ((*str == *exp)?1:0);                 //Return positive result
    
    if (ret == 0 && *exp == '\0')
    {
        return str;                             //Return updated value
    }
    else
    {
        return NULL;                            //Return NULL
    }
}

//Checks a character against a given range exp 
bool RegSubExp::checkRange(char c,char *exp)
{
    while (*exp != RANGE_CHAR_END)
    {
        if (*exp == RANGE_CHAR_SEP)             //check for range separator
        {
            if ((unsigned char)c > (unsigned char)*(exp-1) 
                && (unsigned char)c <= (unsigned char)*(exp+1))
            {
                return true;
            }
            exp++;                              //skip separator
        }
		//test for NOT match
		else if (*exp == MATCH_NOT)
		{
			exp++;
			exp = checkEscape(exp);
            if (c == *exp)
            {
                return false;                    //exit
            }
		}
        else
		{
			exp = checkEscape(exp);
			if (c == *exp)
			{
				return true;                       //found
			}
		}
        exp++;
    }
    return false;                               //Failed
}

//Adjusts for escape character
char *RegSubExp::checkEscape(char *str)
{
    return (*str == ESCAPE_CHAR)?str+1:str;
}

//Strips away any redundant outer compound enclosure
char *RegSubExp::cleanPair(char *str,char start, char end)
{
    if (*str == start)
    {
        char *temp = findPair(str,end);
        //If this is the outer edge, strip away
        if (temp == str + strlen(str) -1)
        {
            *temp = '\0';                           //Remove end delimiter
            *str = '\0';
            str = cleanPair(str + 1,start,end);     //recursive call
        }
    }
    return str;
}

//Locates a matching terminator to a bracket (start) in *str
//Returns pointer to -> or NULL
char *RegSubExp::findPair(char *str,char term)
{
    int depth=0;
    char start=*str;
    
    //Search
    while (*str != '\0')
    {
        if (*str == term)
        {
            if (--depth == 0) return str;       //Found
        }
        else if (*str == start)                 //start?
        {
            depth++;
        }
        else
        {
			str = checkEscape(str);
        }
        str++;                                  //next char
    }
    return NULL;
}

//Destructor
RegSubExp::~RegSubExp()
{
    if (andLink != NULL)
    {
        delete andLink;
    }
    if (orLink != NULL)
    {
        delete orLink;
    }
    if (localValue == false && exp.subLink != NULL)
    {
        delete exp.subLink;
    }
} 

//constructor
RegularExpression::RegularExpression(char *str)
{
    base = new char[strlen(str) + 1];
    strcpy(base,str);
    exp = new RegSubExp(base);
}

//call match on sub-expressions
//Ret      1 for exact match
//        -1 for miss-match
//        0 for partial match (return NULL if all consumed, otherwise what is left)
char *RegularExpression::match(char *str,int &ret)
{
    return exp->match(str,ret);
}

//Destructor
RegularExpression::~RegularExpression()
{
    delete exp;
    delete[] base;
}

