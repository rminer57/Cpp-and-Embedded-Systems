#ifndef CL_LEXANA
#define CL_LEXANA

#include "regularexpression.h"

//Lexical Analyzer class
class LexAna
{
private:
    RegularExpression **reg;                //Array of expressions
    int count;                              //Size of array

public:
	enum
	{
		MISS_MATCH = -1,
		PARTIAL_MATCH = -2
	};

	LexAna(RegularExpression **r,int c);	//constructor
	~LexAna();								//destructor
	char *parse(char *str,int &id,int &len);//parse
	char *parse(char *str);					//parse (consume)
};


#endif
