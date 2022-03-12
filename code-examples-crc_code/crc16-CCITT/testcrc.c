/**************************************************************************
//
// main() - test driver for crc16 function
//
**************************************************************************/
 
#include <stdio.h>
#include <stdint.h>
#include <string.h>

extern uint16_t crc16(int8_t* data_p, uint16_t length);
extern int crc_ok; 
 
int main(int argc, char** argv)
{
    //unsigned short crc;
    static int8_t string[40];
    string[0] = 'T';
    string[1] = (unsigned char)0xd9;
    string[2] = (unsigned char)0xe4;
    string[3] = '\0';
     
    printf ("The crc of \"T\" is 0xD9E4. crc16 returned 0x%X.\r\n\n", crc16(string, (uint16_t)1)); 
    printf ("The crc of \"T 0xD9 0xE4\" is %x. The value of crc_ok is 0x%X.\r\n\n", crc16(string, (uint16_t)3), crc_ok);
     
    strcpy((char *)string, "THE,QUICK,BROWN,FOX,0123456789");
    printf("The crc of \"%s\" is 0x6E20. crc16 returned 0x%X.\r\n\n", string, crc16(string, strlen((char *)string)));
     
    string[0] = (unsigned char)0x03;
    string[1] = (unsigned char)0x3F;
    puts("CCITT Recommendation X.25 (1984) Appendix I example:");
    printf("\tThe crc of 0x033F is 0x5BEC. crc16 returned 0x%X.\r\n\n", crc16(string, 2));

	if (argc > 1)
	{
		printf("crc of passed in data (or string): 0x%X\n",crc16((int8_t *)argv[1],strlen(argv[1])));
	}
}
