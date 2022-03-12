/* crc header file */

#ifndef __crclibrary__
#define __crclibrary__

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <io.h>

#define CRC16LEN 4   /* CRC 16 is 4 bytes long */
#define TRUE 1

/* crc six (6 bit) test driver */
///#define __crc6testdriver__

/* 16 bit YMODEM/XMODEM crc test driver */
#define __crc16testdriver__  /* comment this out if not testing driver */

/****************************************************/
/* crc functions from "a fast crc" magazine article */
/****************************************************/

unsigned short compute_crc(register char *bufpntr, register short buflength,
			   register unsigned short crc);

void setup_crc_table(void);

unsigned short table_driven_crc(register unsigned char *bufptr,
				register short len,
				register unsigned short crc);

/************************************************/
/* crc16 functions from CCITTC                  */
/************************************************/
unsigned int BLKCRC(unsigned char *bufptr,unsigned int buflength,
		    unsigned int newcrc);

unsigned int bytecrc(unsigned char *bufptr, unsigned int newcrc);

/************************************************/
/* crc16 routine used by XMODEM protocol        */
/************************************************/

unsigned int get_crc16(unsigned char *ptr, int blklength);

/************************************************/
/* Bill Saavedra's crc6 functions               */
/************************************************/

unsigned short compute_alc_crc6(char *bufptr, short blklength,
				unsigned char newcrc);

unsigned short compute_table_crc6(char *bufptr, short blklength,
				  unsigned char tblcrc);


/***************************************************/
/* general purpose crc functions for use on a file */
/* modify generic_get_crc to use the algorithm of  */
/* your choice, now it uses the XMODEM non table   */
/* lookup crc16 routine                            */
/***************************************************/
int write_crc_tofile(char * filename);
int is_file_crc_ok(char * filename);
unsigned int read_file_crc(char * filename);
unsigned int generic_get_crc(unsigned char *bufptr,
			       unsigned int buflength);


#endif