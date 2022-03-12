//Lexical Analyzer class
#include "lexana.h"
#include <string.h>

#ifndef NULL
#define NULL 0
#endif

//Constructor
LexAna::LexAna(RegularExpression **r,int c) : reg(r), count(c)
{
}

//Parse the input (returns ID of matching expression, or -1 miss-match, -2 partial)
//If match found, len is updated
char *LexAna::parse(char *str,int &id,int &len)
{
    int ret;
    char *temp;
	id = MISS_MATCH;							//Initialize for failure case

	if (str != NULL)
	{
		//Send input to each of the available RE's in turn.  Stop when one finishes...
		for (id = 0;id<count;id++)
		{
			temp = reg[id]->match(str,ret);     //Send to RE...
			if (ret == 1)                       //A perfect match???
			{
				len = strlen(str);				//Get length
				str = NULL;                     //Stop loop
				break;
			}
			else if (ret == 0)
			{
				len = temp - str;				//Compute length
				str = temp;
				id = (str == NULL)?PARTIAL_MATCH:id; //Partial match ?
				break;
			}
		}
		id = (id < count)?id:MISS_MATCH;        //Adjust ID (loop termination)
	}
	return str;
}

//Parse the input (consume if match)
char *LexAna::parse(char *str)
{
    int ret;
	int id;
    char *temp;

	if (str != NULL)
	{
		//Send input to each of the available RE's in turn.  Stop when one finishes...
		for (id = 0;id<count;id++)
		{
			temp = reg[id]->match(str,ret);     //Send to RE...
			if (ret == 1)                       //A perfect match???
			{
				str = NULL;                     //Stop loop
				break;
			}
			else if (ret == 0)
			{
				str = temp;
				break;
			}
		}
	}
	return str;
}

//Destructor
LexAna::~LexAna()
{
}
