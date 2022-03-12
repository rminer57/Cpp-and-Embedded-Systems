#ifndef CL_KEYWORD
#define CL_KEYWORD

//This is an abstract base class for language keywords
class KeyWord
{
public:
	//Match on this keyword
	virtual bool match(char *str) = 0;
};

#endif
