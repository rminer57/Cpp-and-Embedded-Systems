#ifndef CL_EXCEPTION
#define CL_EXCEPTION


#include <string.h>
class Exception
{
private:
	char *description;
public:
	Exception(char *str) : description(str)
	{};

	Exception(char *str,char *str1,int len = 0)
	{
		//Allocate storage
		len = len <= 0?strlen(str1):len;
		description = new char[strlen(str)+len+1];
		*description='\0';
		strcat(description,str);
		strncat(description,str1,len);
	};

	char *getDesc()
	{
		return description;
	}

	~Exception()
	{
		delete [] description;
	};
};

#endif