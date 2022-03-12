/*crc routines */
#include "crc.h"

static int table_initialized=0;
static unsigned short crc_table[256];

////**************************************************************
//// calculate crc for a stream of characters - from byte magazine
////**************************************************************

unsigned short compute_crc(register char *bufpntr, register short buflength,
			   register unsigned short crc)
{
     register int i;
     while (buflength--)          /* do for every location in the buffer */
     {

	crc=(unsigned short)(*bufpntr++) << 8;
	for(i=0; i<8; ++i)
	{
	  if(crc & 0x8000) /* if 1 is to be shifted out of the sign bit */
	  crc=(crc<<1) ^0x1021;  /* then shift and xor old crc with generator */
	  else
	  crc<<=1;             /* else left shift crc value by one */
	}
     }
  return(crc);
}


///**********************************************************
/// calculate crc of a stream of bytes using table -from byte magazine
/// table must already be set up before calling this routine.
/// call setup_crc_tables() for this purpose
///**********************************************************
unsigned short table_driven_crc(register unsigned char *bufptr,
				register short buflength,
				register unsigned short crc)
{
 if(!table_initialized)
 {
   setup_crc_table();       /* initialize the table */
   table_initialized = TRUE;
 }

 while(buflength--)
 crc=crc_table[ (crc>>8) ^(*bufptr++) ] ^(crc<<8);
 return(crc);
}

///**********************************************************
/// code to setup the crc lookup table -from byte magazine
///**********************************************************

void setup_crc_table(void)
{
 int count;
 char zero=0;
 for(count=0; count<256; count++)
   crc_table[count]=compute_crc(&zero,1,count<<8);
}

///**********************************************************
/// XMODEM routine for finding CRC from byte magazine
/// yet another crc16 routine
///**********************************************************
/* Calculate CRC on a block of data.
   Ptr points to block of characters, buflength gives the buffer's
   size.  Function returns the CRC of the block with the LSB
   of the CRC in the high bit of the result integer.
   XMODEM deviates from the CCITT standard in that it does not use
   the LSB of the data 1st, nor does it initialize the CRC to all
   ones as specified by the standard.  */

unsigned int get_crc16(unsigned char *bufptr, int buflength)
{
 int i;
 unsigned int crc=0xFFFF;   /* note, not 0xFFFF as in CCITT standard */
 while (--buflength >= 0)
 {
   i = (unsigned int) *bufptr++;   /* convert data char to int */
   i = i << 8;         /* shift char to high byte of integer variable */
   crc = crc ^i;       /* add current data to current remainder modifies */
		       /* only least significant 8 bits (high byte) of CRC */
   for (i=0; i<8; ++i) /* loop for each bit */
     if (crc & 0x8000) /* test D XOR R0 */
     {
      crc =( crc<<1 ); /* discard LSB of CRC and append zero */
      crc =crc ^0x1021; /* XOR with low 16 bits of CCITT polynomial */
			/* because CRC is stored LSB 1st, poly written */
			/* MSB first */
     }
     else
      crc = crc << 1;   /* discard LSB and append zero */
 }
 return (crc & 0xFFFF); /* 16 bit result for whole block */
}

///**********************************************************
/// CCITTC routine for calculating CRC's in C source code
/// yet another crc calculating routine
///**********************************************************
/// straightforward, non optimized CRC-CCITT routine
/// assumes 16 bit int variables
/// MSB of integer is MSB of CRC result
/// POLY = 1021 in bit reverse order

#define POLY 0x8408

/// PERFORM CRC ON A BLOCK OF DATA
/// inputs: pntr to block of data, lentht
unsigned int  BLKCRC(unsigned char *bufptr,unsigned int buflength,
		     unsigned int newcrc)
{
  int i;
  newcrc = 0;            /* for sdlc protocol, use 0xFFFF */
  for (i=1; i<=buflength; ++i, bufptr++) /* do for whole block */
    bytecrc(bufptr,newcrc);             /* crc of 1 char */
  return(newcrc);
}

 unsigned int bytecrc(unsigned char *bufptr, unsigned int newcrc)
{
  unsigned int j, ch, Q;
  ch = (unsigned int) *bufptr;
  for (j=1; j<=8; j++)                     /* do each bit LSB first */
  {
    Q = (newcrc & 0x0001) ^(ch & 0x0001);  /* Q=R0 XOR D */
    if (Q == 0x0001)                       /*  if Q is 1 */
    {
      newcrc = newcrc >> 1;              /* shift right one bit */
      newcrc = newcrc ^ POLY;            /* xor with number */
    }
    else                                   /* Q is zero */
      newcrc = newcrc >> 1;              /* shift without XOR */
    ch = ch >> 1;                          /* move next data bit */
  }                                        /* into position */
return ( newcrc);
}


/************************************************/
/* functions from Bill Saavedra's crc6 code     */
/************************************************/

unsigned short compute_alc_crc6( char *bufptr, short buflength,
				 unsigned char newcrc)
{
  int i;
  while(buflength--)
  {
    newcrc ^= (*bufptr++);
    for (i=0; i<6; ++i)
      {
	if (newcrc & 0x20)
	   newcrc = (newcrc<<1) ^0x21;
	else
	   newcrc = newcrc << 1;
      }
  }
  return (newcrc);

}

/* use data value as an index into table to lookup the crc */
unsigned short compute_table_crc6(char *bufptr, short buflength,
				  unsigned char tblcrc)
{
  while (buflength--)
  {
    tblcrc= ( crc_table[ (tblcrc^(*bufptr++) ) & 0x3f]  ^tblcrc) &0x3f;
  }
  return (tblcrc);

}

#ifdef __crc6testdriver__
/***************************************************
	CRC6 TEST DRIVER CODE .... enable it by
	putting the line #define __crc6testdriver__
	in crc.h and recompile crc.c
***************************************************/

unsigned char crc6_table[64];

void main(void)
{
  char crc, msg_crc,tbl_crc;
  int index;
  unsigned char x,y;

  char test_msg[18] = {0x03, 0x15, 0x06, 0x2A,
		       0x1A, 0x13, 0x38, 0x26,
		       0x29, 0x25, 0x1B, 0x25,
		       0x39, 0x22, 0x0C, 0x32,
		       0x0A, 0x1D };

/*  char test_msg2[18] = {0x0F, 0x15, 0x27, 0x2A,
		       0x29, 0x0D, 0x38, 0x26,
		       0x1A, 0x16, 0x09, 0x16,
		       0x18, 0x2E, 0x33, 0x2C,
		       0x2B, 0x11 };

  char test_msg3[6]  = {0x02, 0x01, 0x23, 0x26,
		       0x37, 0x1d };     */

  char test_msg4[18] = {0x01, 0x13, 0x31, 0x1c,
			0x02, 0x05, 0x34, 0x35,
			0x33, 0x1c, 0x23, 0x31,
			0x17, 0x24, 0x39, 0x31,
			0x0c, 0x1d };

  crc = 0;

  for (index = 0; index < 64; index++)
     {
       crc6_table[index] = compute_alc_crc6(&crc, 1,index);
     }

  msg_crc = compute_alc_crc6(&test_msg4[0], 18,crc);
  printf("\n MSGCRC: %2x \n", msg_crc);

  crc = 0;
  tbl_crc = compute_table_crc6(&test_msg[0], 18,crc);
  printf("\n TBLCRC: %2x  \n", tbl_crc);
  y=8;
  index=0;
  while (y !=0)
      {
      for (x=0; x<8; x++)
	     {
	     printf( "%2x ", crc6_table[index] );
	     index++;
	     }
      printf("\n");
      y--;
      }
}
#endif



#ifdef __crc16testdriver__
/***************************************************
	CRC16 TEST DRIVER CODE .... enable it by
	putting the line #define __crc16testdriver__
	in crc.h and recompile crc.c
***************************************************/

void main(void)
{
	FILE *FP;
	unsigned int crc;

	/* create a file, or overwrite existing file */
	FP=fopen("testcrc","w+");

	/* write some test data  */
	fprintf(FP,"1234567890abcdefghijklmnopqrstuvwxyz");
	fclose(FP);

	/* calculate crc and append 4 crc bytes to end of file */
	write_crc_tofile("testcrc");

	/* read the crc bytes from the end of the file */
	crc=read_file_crc("testcrc");

	printf("\n CRC BYTES AT END OF FILE ARE: %04X  \n",crc );

	/* verify file's embedded crc agrees with calculation on the data */
	if( !is_file_crc_ok("testcrc") )
	printf("\ntestcrc CRC bad, file is corrupted!");

}
#endif


/*************************************************/
/* write crc to end of a file                  */
/* calculates a crc of a file and then writes it */
/* to the end of file                            */
/*************************************************/
int write_crc_tofile(char * filename)
{
  FILE *FP;
  unsigned int crc;
  unsigned int file_length=0;
  unsigned char *buffer=NULL;                 /* pointer to buffer*/

	if ((FP = fopen(filename,"rt")) == NULL)
	  {
	    printf ("\n\rError: Can't find file %s\n",filename);
	    fclose(FP);
	    exit(1);
	  }

	/* buflength number of bytes in the test file */
	while (fgetc(FP) != EOF)  /*get bytes till EOF */
	  {
	    file_length++;
	  }
	rewind(FP);

		/* allocate space for the buffer */
	buffer= (unsigned char *)malloc( (size_t)file_length);

		/* read bytes from srcfile into buffer */
	fread(&buffer[0], sizeof(buffer[0]),file_length,FP);
	fclose(FP);

	crc= generic_get_crc(buffer, file_length );

	if ((FP = fopen(filename,"a+t")) == NULL)
	  {
	    printf ("\n\rError: Can't find file %s\n",filename);
	    fclose(FP);
	    exit(1);
	  }

	fprintf(FP,"%04X",crc);
	fclose(FP);
	free(buffer);  /* free up memory */

return 1;
}

/************************************************/
/*  read crc (last 4 bytes of file)            */
/************************************************/
unsigned int read_file_crc(char * filename)
{
  fpos_t filepos;
  FILE *FP;
  unsigned int file_embedded_crc;

	if ((FP = fopen(filename,"rt")) == NULL)
	  {
	    printf ("\n\rError: Can't find file %s\n",filename);
	    fclose(FP);
	    exit(1);
	  }

	/* goto end of file */
	while (fgetc(FP) != EOF)  /*get bytes till EOF */

	fgetpos(FP,&filepos);
	filepos=filepos-CRC16LEN;   /* backup 4 bytes */

	if(fsetpos(FP, &filepos)==0) /* positioning went ok */
	{
	  fscanf(FP, "%04X",&file_embedded_crc);
	}
	else
	{
	    printf ("\n\rError: file positioning error in %s\n",filename);
	    fclose(FP);
	    exit(1);
	}
return(file_embedded_crc);

}
/************************************************/
/*  verify crc (last 4 bytes of file) matches */
/*  calculated value for that file              */
/************************************************/
int is_file_crc_ok(char * filename)
{
  FILE *FP;
  unsigned int file_embedded_crc;
  unsigned int crc_calc;
  long unsigned int file_length=0;
  unsigned char *buffer=NULL;                 /* pointer to buffer*/

  /* get crc recorded in the file */
  file_embedded_crc=read_file_crc(filename);  /* read file's CRC */

	if ((FP = fopen(filename,"rt")) == NULL)
	  {
	    printf ("\n\rError: Can't find file %s\n",filename);
	    fclose(FP);
	    exit(1);
	  }

	/* buflength number of bytes in the test file */
	while (fgetc(FP) != EOF)  /*get bytes till EOF */
	  {
	    file_length++;
	  }
	rewind(FP);

		/* allocate space for the buffer */
	buffer= (unsigned char *)malloc( (size_t)file_length);

		/* read bytes from srcfile into buffer */
	fread(&buffer[0], sizeof(buffer[0]),(size_t)file_length,FP);

	/* calculate crc, don't include the 4 byte crc at end of file */
	crc_calc= generic_get_crc(buffer,(unsigned)file_length-CRC16LEN );
	fclose(FP);
	free(buffer);  /* free up memory */

	if(crc_calc == file_embedded_crc)
	return TRUE;
	else
	return !TRUE;
}

/*************************************************/
/*           generic_get_crc                   */
/* this function is provided so that if you want */
/* to change which crc algorithm is in use,    */
/* it need only be done in one place....here!    */
/*************************************************/
unsigned int generic_get_crc(unsigned char *bufptr, unsigned int buflength)
{
 return get_crc16(bufptr, (unsigned int)buflength);    /* XMODEM crc16 routine */

/// return BLKCRC(bufptr, buflength, unsigned int *crc)   /* CCITT algorithm */
/* byte magazine on the fly crc */
/// return (unsigned)compute_crc(register char *bufpntr,
///				 register short buflength,
///				 register unsigned short crc)

/* byte magazine table driven version - said to be faster than on the fly */
/// return (unsigned)table_driven_crc(register unsigned char *bufptr,
///				      register short buflength,
///     			      register unsigned short crc)

}


