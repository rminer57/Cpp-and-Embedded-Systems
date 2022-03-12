#ifndef CL_REGEXP
#define CL_REGEXP

/* regular Expression matching
	Note: REPEAT clauses apply to ALL non-compound preceeding characters,
	
		#[a-z]* should be written as (#)[a-z]* if the '*' applies to only the range
		{this is for parsing efficiency}
		otherwise, the '*' is applied to '#[a-z]'

		compound blocks should always be used to ensure correct evaluation
		(they are removed during construction, and therefore do NOT impose overhead).	
*/

#define ALTERNATE_CHAR '|'
#define ESCAPE_CHAR '%'
#define COMPOUND_CHAR_START '('
#define COMPOUND_CHAR_END ')'
#define RANGE_CHAR_START '['
#define RANGE_CHAR_END ']'
#define RANGE_CHAR_SEP '-'
#define REPEAT_ZERO_PLUS '*'
#define REPEAT_ONE_PLUS '+'
#define REPEAT_ZERO_ONE '?'
#define MATCH_WILD '.'
#define MATCH_NOT '^'

//Holds 1 regular expression
class RegSubExp
{
private:
    char repeat;                                //Repeat flags
    bool localValue;                            //Flag to determine local pointer

    RegSubExp *orLink;                          //Sub-expression pointer
    RegSubExp *andLink;                         //Sub-expression pointer

    //Local vs. alternate level sub-expression (localValue controls)
    union
    {
        RegSubExp *subLink;                     //Sub-expression pointer
        char *value;                            //current sub-expression value
    } exp;

public:

    //Constructor
    //Note, the string passed MUST remain for the lifetime of this Object.
    RegSubExp(char *base);

    //Accessor to check for match of string against expression
    //Return -1 for miss-match, 0 for not equal, but not miss-match, 1 for equal
    //In the case ret==0, returns remainder (or NULL) (only used by AND chains)
    char *match(char *str,int &ret);
    
    //Destructor
    ~RegSubExp();

private:

    //Find a separator in a string (bypassing compound exp)
    //If found returns ->, otherwise NULL
    char *findSep(char *str,char sep,char compStart,char compEnd);

    //Check a string against an expression.
    //Return -1 for miss-match, 0 for not equal, but not miss-match, 1 for equal
    //returns update of "str" if exceeds "exp", else NULL
    char *check(char *str,char *exp,int &ret);

    //Checks a character against a given range exp 
    bool checkRange(char c,char *exp);

    //Adjusts for escape character
    char *checkEscape(char *str);

    //Strips away any redundant outer compound enclosure
    char *cleanPair(char *str,char start, char end);

    //Locates a matching terminator to a bracket (start) in *str
    //Returns pointer to -> or NULL
    char *findPair(char *str,char term);

};

//Master class
class RegularExpression
{
private:
    char *base;
    RegSubExp *exp;

public:
    //constructor
    RegularExpression(char *str);

    //call match on sub-expressions
    char *match(char *str,int &ret);

    //Destructor
    ~RegularExpression();
};



#endif