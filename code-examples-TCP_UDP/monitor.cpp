/*******************************************************************************
*                         COPYRIGHT 1997 MOTOROLA
*                    MOTOROLA CONFIDENTIAL PROPRIETARY
********************************************************************************
*
* FILE NAME      :    monitor.c
* ORIGINATOR     :    Randy Miner (rdm)
* DATE OF ORIGIN :    8/17/96
*
*---------------------------------- PURPOSE -----------------------------------
* a monitor program for the Mcore RCE microprocessor system       
*
*--------------------------- PROJECT SPECIFIC DATA -----------------------------
*
*
*--------------------------------- REVISIONS -----------------------------------
* Date      Username      Description of Modification
* --------  ------------  -----------------------------------------------

*
*--------------------------- HEADER FILE INCLUDES ----------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "monitor.hpp"

#ifdef DOSUNIX_PLATFORM
#include <conio.h>
#include <iostream.h>
#endif

#ifdef EMBEDDED_PLATFORM
#include "mcore_ser_public.h"
#endif

/* default values */
#define DEFAULTLINESIZE 16 
#define MAXLINESIZE 16
#define DEFAULTBASE 16
#define NUMOFADDRESSDIGITS 8
#define SCREENLINESTOCLEAR 50
#define LEADINGZERODIGITS '0'
#define ECHO_RX_DATA


#ifdef DOSUNIX_PLATFORM
/* for development on a dos platform, this array will "simulate" */
/* memory since its not a good idea to write to the PC's memory */
unsigned char testmemory[1000];
#endif

/* this lets us define out unimplemented stuff so it wont */
/* show up and confuse the user at run time */
#define UNFINISHED

/* breakpoint defines - for the MOTOROLA MCORE RCE processor */
#define BKPT_INSTRUCTION (unsigned int)0
#define MCORE_BREAKPOINT_EXCEPTION_VECTOR   (unsigned long)0x01C
#define NUMOFBKPTS 8
#define NUMOFREGISTERS 16

/** ----------------------------
*	Data Structures
 ** ----------------------------*/

static int Gexitflag = 0;
static int Gdsize = DEFAULTLINESIZE;   /* line width for display memory */
static int Gbasemodulo = DEFAULTBASE;  /* base to display - default is hex */

/* arrays to store the saved instructions  */
//#ifdef EMBEDDED_PLATFORM
unsigned short bkptarray[NUMOFBKPTS]; /* save instruction at bkpt address */
unsigned short bkptid[NUMOFBKPTS];    /* save instruction at bkpt id addr */
unsigned int bkptaddr[NUMOFBKPTS];    /* save address of breakpoint */
unsigned short Gindex;                /* temp variable used by bkpt handler */
unsigned short Gtempa16;              /* temp variable used by bkpt handler */
unsigned short Gtempb16;              /* temp variable used by bkpt handler */
unsigned int register_storage[NUMOFREGISTERS];   /* user registers stored here */
unsigned int supreg_storage[6];       /* mcore supervisory registers stored here */
int breakpoint_enable = 0;            /* bkpt enable flag */
//#endif

char Gversion[] = {"2.0\n\r"};   /* program version */

const SPACE = 0x20;     /* ASCII space */
const NUL = 0x00;       /* ASCII NULL */
const BS_KEY = 0x08;    /* backspace key */
const DEL_KEY = 0x7f;   /* delete key */
const BELL = 0x07;      /* bell */
const ESC_KEY = 0x1b;   /* escape key */

unsigned char input[80]; /* array to hold keyboard input */

char unimplementedcmd[] ={" -unfinished command.\n\r"};


void (*func_pntr) ();    /* generic pointer, can point to any function which */

monitor :: monitor()
{
    int i = 0;
    
	commands = new cmdstruct_t[19];

/************************************************/
/* command table */
/************************************************/
  commands[i++].keyword = "read";  
  commands[i++].keyword = "write";
  commands[i++].keyword = "edit";
  commands[i++].keyword = "fill";
  commands[i++].keyword = "about";
  commands[i++].keyword = "help";
  commands[i++].keyword = "quit";
  commands[i++].keyword = "dsize";
  commands[i++].keyword = "goto";
  commands[i++].keyword = "call";
  commands[i++].keyword = "loopwr";
  commands[i++].keyword = "looprd";
  commands[i++].keyword = "setbkpt";
  commands[i++].keyword = "clrbkpt";
  commands[i++].keyword = "bkptson";
  commands[i++].keyword = "find";
  commands[i++].keyword = "tstmem";
  commands[i++].keyword = "user1";
  commands[i++].keyword = "crc";
  //add new commands here 

  
}

monitor :: ~monitor()
{
  delete [] commands;
}

void monitor :: start(void)
{
#ifdef DOSUNIX_PLATFORM
     /* for development of the monitor under dos */
     /* we need the testmemory array */
     /* init testmemory to known pattern */
     int x;
     unsigned char c=0x30;
     for(x=0; x < 50; x++)
     testmemory[x]=c++;
         
#else  /* enbedded system code would have its own main() */
     Mon_low_level_io_init();

     for(x=0; x < NUMOFBKPTS-1; x++)
     bkptarray[x] = 0;
#endif
    
     Gexitflag = 0;

     clrscr();           /* clear the screen */
     signon();           /* print signon message */

  for(;;)                /* endless loop, type quit to get out */
   {
     prompt();           /* print the prompt "cmd> " */
     getline(input);     /* get a line of input from kbd and store in input[80] */
     getcmd();	         /* parse the buffer for valid command and set pointer */
 

     if(Gexitflag)
     break;
   }


}

//* end page -    - new page */
/******************************************************************************* 
*
*   FUNCTION NAME :             getcmd   
*
*---------------------------------- PURPOSE ------------------------------------
*   
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: None.
*
*   PARAMETERS: None.
*
*   RETURN VALUE: 
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
* parses a command from the input array, compares the string to the list of
* keywords in the structure and if a match is found, sets the function
* pointer to the function name found in	the structure adjacent to the keyword.
********************************************************************************/

void monitor :: getcmd(void)
{
  int index;
  char cmd_entry[80];
  int numofcmds;

 
    numofcmds = 19;
	sscanf((const char *)input,"%s",&cmd_entry);

	/* search the commands[] array structure for */
	/* a command string which matches one in the input */
	/* buffer. */
	for (index=0; index < numofcmds; index++)
	{

	  if (strcmpi(cmd_entry,commands[index].keyword) == 0)
	  {
		switch (index)
		{
			case 0:
			
			monitor::readmem();
			break;
		
			case 1:
            
			monitor::writemem();
			break;
		
			case 2:
			monitor::edit();
			break;
			  
			case 3:
			monitor::fill();
			break;
	  
			case 4:
			monitor::signon();
			break;
	  
			case 5:
			
			monitor::helpcmd();
			break;
	  
			case 6:
			monitor::quit();	
			break;
	  
			case 7:
			monitor::dsize();
			break;
	  
			case 8:
			monitor::gotoaddr();
			break;
		  
			case 9:
			monitor::call();
			break;
	  
			case 10:
			monitor::loopwr();
			break;
	  
			case 11:
			monitor::looprd();
			break;
	  
			case 12:
			monitor::setbkpt();
			break;
	  	  
			case 13:
			monitor::clrbkpt();
			break;
	  
			case 14:
			monitor::bkptson();
			break;
	  
			case 15:
			monitor::find();
			break;
	  
			case 16:
			monitor::tstmem();
			break;
	  	  
			case 17:
			monitor::user1();
			break;
	  	  
			case 18:
			monitor::crc();
			break;

			default:
			cout << "ERROR default case in monitor::getcmd -- unrecognized entry";
			break;
		}	    
	  }

	}


}
/**********************************************************************
		   C O M M A N D	  F U N C T I O N S
***********************************************************************/

/*******************************************************************************
*
*   FUNCTION NAME :             gotoaddr    
*
*---------------------------------- PURPOSE ------------------------------------
*  	
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: 
*
*   PARAMETERS:     
*                   
*   RETURN VALUE:   
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
*  goto <addr>
********************************************************************************/

void monitor :: gotoaddr(void)
{
  char usercommandstring[80];
  unsigned int address;  
  int numofitems;
  int data;

  numofitems = sscanf((const char *)input,"%s%x%x",&usercommandstring,&address,&data);
  if(numofitems < 2) return;

#ifdef EMBEDDED_PLATFORM
  Mon_low_level_jump(address);
#else
  Mon_low_level_printstring ("\n\r This command won't work under DOS!\n\r");
#endif
}

/* end page - eject   eject - new page */
/*******************************************************************************
*
*   FUNCTION NAME :             call    
*
*---------------------------------- PURPOSE ------------------------------------
*  	
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: 
*
*   PARAMETERS:     
*                   
*   RETURN VALUE:   
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
*  call <address>
********************************************************************************/

void monitor :: call(void)
{
  
  char usercommandstring[80];
  unsigned int address;
  int numofitems;
  int data;

  numofitems = sscanf((const char *)input,"%s%x%x",&usercommandstring,&address,&data);
  if(numofitems < 2) return;

#ifdef EMBEDDED_PLATFORM
  func_pntr= ( void(*)(void) )address;
  (*func_pntr) () ;
#else
  Mon_low_level_printstring ("\n\r This command won't work under DOS!\n\r");
#endif

}

/* end page - eject   eject - new page */
/*******************************************************************************
*
*   FUNCTION NAME :             bkptson    
*
*---------------------------------- PURPOSE ------------------------------------
*  	
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: 
*
*   PARAMETERS:     
*                   
*   RETURN VALUE:   
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
*  bkptson  Enable breakpoints. This caused the breakpoint vector of Mcore
*  to be loaded with the address of the breakpoint handler in monitor.c
********************************************************************************/
void monitor :: bkptson(void)
{    
  Mon_low_level_bkpt_setup();
  breakpoint_enable = 1;

}

/* end page - eject   eject - new page */
/*******************************************************************************
*
*   FUNCTION NAME :             setbkpt    
*
*---------------------------------- PURPOSE ------------------------------------
*  	
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: 
*
*   PARAMETERS:     
*                   
*   RETURN VALUE:   
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
* setbkpt <address> <optional #>
* sets a breakpoint at the specified address. An optional breakpoint number can
* be provided from 0 to 7. The default is 0 if no breakpoint number is given on
* the command line. After the breakpoint is set, the user enters <goto address>
* or <call address> to start execution. setbkpt is currently implemented for the
* Mcore processor.  A special breakpoint instruction is provided for this cpu
* as part of its assembly instruction set. It is a 16 bit NULL value (all 0's)
* When this special instruction is encountered during execution, a breakpoint
* exception will occur and the breakpoint handler will be called. In the handler,
* we restore the instruction at the breakpoint address as well as the breakpoint
* number which is stored in the next higher address. The values found at these
* two memory locations when setbkpt runs will be stored in two arrays defined
* at the top of this file. The breakpoint handler will restore the two instructions
* overwritten back to their original values. For example, if we set a breakpoint
* at address 1000 and specify breakpoint number 1 (setbkpt 1000 1) and then display
* address 1000 we would see:  00001000: 00 00 00 01 
* Breakpoint numbers are optional with
* 0 to 7 being valid.  If no number is supplied, zero is the default.  
********************************************************************************/

void monitor :: setbkpt(void)
{
  int bkptnumber;
  char usercommandstring[80];
  unsigned int address;
  
  int numofitems;
  
  bkptnumber = 0;

  if(breakpoint_enable != 1)
  {
    Mon_low_level_printstring ("\n\r  ERROR - breakpoints not enabled, see help! \n\r");
    return;    
  }
  
  numofitems = sscanf((const char *)input,"%s%x%i",&usercommandstring,&address,&bkptnumber);
  if(numofitems < 2) return;
 
  /* get the instruction at the breakpoint address and save it into the array       */
  /* then overwrite the instruction in memory with a breakpoint instruction         */
  /* when the program reaches this point, the breakpoint routine will be executed   */
  /* check to see if the user already set the breakpoint, otherwise trying to do it */
  /* twice in the same place will cause problems                                    */
#ifdef EMBEDDED_PLATFORM
  if( *( (unsigned short *)address ) != BKPT_INSTRUCTION )
  { 
    bkptarray[bkptnumber] = *( (unsigned short *)address );
    bkptaddr[bkptnumber] = (unsigned int)address;
    //Mon_low_level_bkptsaveinstr(bkptarray[bkptnumber]); 
    *( (unsigned short *)address ) = BKPT_INSTRUCTION;
    address += 2;
    bkptid[bkptnumber] = *( (unsigned short *)address );
    *( (unsigned short *)address ) = bkptnumber;  
  }
#else
  Mon_low_level_printstring ("\n\r This command won't work under DOS!\n\r");
#endif
  
  
}

/* end page - eject   eject - new page */
/*******************************************************************************
*
*   FUNCTION NAME :             clrbkpt    
*
*---------------------------------- PURPOSE ------------------------------------
*  	
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: 
*
*   PARAMETERS:     
*                   
*   RETURN VALUE:   
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
* clrbkpt <address> <optional #>
* clears (removes) unexecuted breakpoints. If a breakpoint is encountered in
* execution, it will be cleared automatically. This command is used when 
* multiple breakpoints are being set (such as in switch/case statements) and
* the unexecuted ones must be removed.  Breakpoint numbers are optional with
* 0 to 7 being valid.  If no number is supplied, zero is the default.
********************************************************************************/

void monitor :: clrbkpt(void)
{
  int bkptnumber;
  char usercommandstring[80];
  unsigned int address;
  int numofitems;
  
  if(breakpoint_enable != 1)
  {
    Mon_low_level_printstring ("\n\r  ERROR - breakpoints not enabled, see help! \n\r");
    return;    
  }
  
  
  bkptnumber = 0;
  
  numofitems = sscanf((const char *)input,"%s%x%x",&usercommandstring,&address,&bkptnumber);
  if(numofitems < 2) return;
 
  /* get saved instruction in the array and restore to the breakpoint address */
  /* check to see if the user already cleared the breakpoint, otherwise trying to do it */
  /* twice in the same place will cause problems */
#ifdef EMBEDDED_PLATFORM
  if( *( (unsigned short *)address ) == BKPT_INSTRUCTION )
  {    
    *( (unsigned short *)address ) = bkptarray[bkptnumber];
    bkptarray[bkptnumber] = BKPT_INSTRUCTION;
    bkptaddr[bkptnumber] = NULL;
    address += 2;
    *( (unsigned short *)address ) = bkptid[bkptnumber];  
  }
#else
  Mon_low_level_printstring ("\n\r This command won't work under DOS!\n\r");
#endif
  
}

/* end page - eject   eject - new page */
/*******************************************************************************
*
*   FUNCTION NAME :             dsize    
*
*---------------------------------- PURPOSE ------------------------------------
*  	
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: 
*
*   PARAMETERS:     
*                   
*   RETURN VALUE:   
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
* dsize <newsize1_to_16>
* allows change of the display width from 1 to 16.  If an invalid value less than
* 1 or greater than 16 is entered, the default value will be used instead.
********************************************************************************/

void monitor :: dsize(void)
{
  unsigned char usercmdstring[80];
  int numofitems;
  int size;

  /* read parameters from the input buffer */
  /* user usercmdstring is the command name, */
  /* this gets discarded but must be read to access */
  /* the next line parameter */
  numofitems = sscanf((const char *)input,"%s%i",&usercmdstring,&size);

  if(numofitems != 2) return;
  if( (size < 1) || (size > MAXLINESIZE))
  {
   size = DEFAULTLINESIZE;
  }

  Gdsize = size;
}

/* end page - eject   eject - new page */
/*******************************************************************************
*
*   FUNCTION NAME :             loopwr    
*
*---------------------------------- PURPOSE ------------------------------------
*  	
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: 
*
*   PARAMETERS:     
*                   
*   RETURN VALUE:   
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
* Writes to the memory location. syntax is: loopwr <address> <wrdata16> <loops>
* if loops is unspecified or is 0, endless loop will be assumed. Reset is
* necessary to escape the endless loop. However, a last opportunity to bail out 
* is given.
********************************************************************************/
void monitor :: loopwr(void)
{
  char usercommandstring[80];
  unsigned int address;
  int numofitems;
  int x;
  int wrdata16;
  int loops = 0;
  unsigned char YN;

  numofitems = sscanf((const char *)input,"%s%x%x%i",&usercommandstring,&address,&wrdata16, &loops );
  if(numofitems < 2) return;

  if(loops == 0) /* indicates a forever loop */
  {
     Mon_low_level_printstring("\n\rWarning, this will cause an endless write loop,\n\r");
     Mon_low_level_printstring("Reset or power clear will be required. Are you sure (y/n)? ");
     YN = Mon_low_level_getch();
     Mon_low_level_putch(YN);
     if( (YN != 'y') )
     return;
     
     Mon_low_level_printstring("  -Loop running! Reset is required to stop this loop."); 
     for(;;)
     {
#ifdef EMBEDDED_PLATFORM		 
        *( (unsigned short *)address ) = wrdata16;
#else

#endif		
     }
  }
  else
  {
     for(x=0; x < loops; x++)
     {
#ifdef EMBEDDED_PLATFORM
        *( (unsigned short *)address ) = wrdata16;
#else

#endif
     }
  }
  
}

/* end page - eject   eject - new page */
/*******************************************************************************
*
*   FUNCTION NAME :             looprd    
*
*---------------------------------- PURPOSE ------------------------------------
*  	
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: 
*
*   PARAMETERS:     
*                   
*   RETURN VALUE:   
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
*  looprd <address> <optional #loops>
********************************************************************************/
void monitor :: looprd(void)
{
  char usercommandstring[80];
  unsigned int address;
  int numofitems;
  int x;
  unsigned short rddata16;
  int loops = 0;
  char YN;
  
  numofitems = sscanf((const char *)input,"%s%x%i",&usercommandstring,&address, &loops );
  if(numofitems < 2) return;

  if(loops == 0) /* indicates a forever loop */
  {
     Mon_low_level_printstring("\n\rWarning, this will cause an endless read loop,\n\r");
     Mon_low_level_printstring("Reset or power clear will be required. Are you sure (y/n)? ");
     YN = Mon_low_level_getch();
     Mon_low_level_putch(YN);
     
     if( (YN != 'y'))
     {
        return;
     }
     
     Mon_low_level_printstring("\n\rDo you want to display the data as its read?\n\r");
     Mon_low_level_printstring("Note: Doing so increases read cycle time. Display (y/n)? ");
     YN = Mon_low_level_getch();
     Mon_low_level_putch(YN);
     
     if( (YN != 'y') )
     {
        Mon_low_level_printstring("  -Loop running! Reset is required to stop this loop."); 
        for(;;)  /* no display */
        {
#ifdef EMBEDDED_PLATFORM			
           rddata16 = *( (unsigned short *)address );
#else
           rddata16 = Mon_low_level_rdmem(address);
#endif
        }
        
     }
     else
     {
        Mon_low_level_printstring("\n\r");
        for(;;)  /* display */
        {
#ifdef EMBEDDED_PLATFORM			
           rddata16 = *( (unsigned short *)address );
#else
           rddata16 = Mon_low_level_rdmem(address);
#endif
           Mon_low_level_putint((unsigned short)rddata16, 16);
           Mon_low_level_printstring("\n\r");

        }
        
     }
     
  }
  else
  {
     Mon_low_level_printstring("\n\r");
     for(x=0; x < loops; x++)
     {
#ifdef EMBEDDED_PLATFORM
        rddata16 = *( (unsigned short *)address ); 
#else

#endif
        Mon_low_level_putint((unsigned short)rddata16, 16);
        Mon_low_level_printstring("\n\r");
     }
  }
  

}

/* end page - eject   eject - new page */
/*******************************************************************************
*
*   FUNCTION NAME :             find    
*
*---------------------------------- PURPOSE ------------------------------------
*  	
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: 
*
*   PARAMETERS:     
*                   
*   RETURN VALUE:   
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
* Unimplemented.
********************************************************************************/

void monitor :: find(void)
{
  Mon_low_level_printstring(unimplementedcmd);
}


/* end page - eject   eject - new page */
/*******************************************************************************
*
*   FUNCTION NAME :             crc    
*
*---------------------------------- PURPOSE ------------------------------------
*  	
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: 
*
*   PARAMETERS:     
*                   
*   RETURN VALUE:   
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
*   Unimplemented. - calculate and display the 32 bit crc of a block of data.
* This is usefull when someone needs to program the crc of some code (flash)
* and use it for powerup diagnostics
********************************************************************************/
void monitor :: crc(void)
{
  Mon_low_level_printstring(unimplementedcmd);
}

/* end page - eject   eject - new page */
/*******************************************************************************
*
*   FUNCTION NAME :             tstmem                 
*
*---------------------------------- PURPOSE ------------------------------------
*  	
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: 
*
*   PARAMETERS:     
*                   
*   RETURN VALUE:   
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
* Unimplemented. - non destructive memory (ram) test.
********************************************************************************/
void monitor :: tstmem(void)
{
  Mon_low_level_printstring(unimplementedcmd);
}


/* end page - eject   eject - new page */
/*******************************************************************************
*
*   FUNCTION NAME :             user1    
*
*---------------------------------- PURPOSE ------------------------------------
*  	
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: 
*
*   PARAMETERS:     
*                   
*   RETURN VALUE:   
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
* Unimplemented. The idea was to provide the user a way to specify a function
* of their own design to be executed. We could do this one of two ways. We could
* make the user modify this function or provide a way to specify a function 
* pointer to the users function which might live elsewhere.
********************************************************************************/
void monitor :: user1(void)
{
  Mon_low_level_printstring(unimplementedcmd);
}


/* end page - eject   eject - new page */
/*******************************************************************************
*
*   FUNCTION NAME :             readmem 
*
*---------------------------------- PURPOSE ------------------------------------
*
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: 
*
*   PARAMETERS:     
*                   
*   RETURN VALUE:   
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
*  	reads and displays memory contents in a formatted manner.
*   SYNTAX:
*           read <address>  
*   or
*           read <address>  <optional_length_1to31bytes>
********************************************************************************/
void monitor :: readmem(void)
{
  int i,k,x, numofitems, bytes2do;
  int length;
  unsigned long enteredstartaddr;
  unsigned long firstdisplayaddr;
  unsigned long currentaddress;
  unsigned char outputchar;
  char output[10];
  unsigned char temp[32];

  length = Gdsize; /* default */
  
  /* read parameters from the input buffer */
  numofitems = sscanf((const char *)input,"%s%lX%i",&temp,
		      &enteredstartaddr, &length);

  /* must be two items, read <startaddr> */
  /* or could be read <startaddr> <length> */
  if(numofitems < 2) return;

  /* now find address <= entered address which is modulo 16 */
  /* this will go into the address array */
  firstdisplayaddr = enteredstartaddr - (enteredstartaddr % Gdsize);

  /***********************************************
   display header line (unsigned long address, int dsize)
  ************************************************/

  /* first, display the row of numbers from 0 to 15 */
  Mon_low_level_printstring("\n\r\n\r");
  Mon_low_level_printstring("Address ");
  Mon_low_level_printstring("   ");

  outputchar = 0x30;

  for(x=0; x < Gdsize; x++)
  {
    Mon_low_level_putch(outputchar);
    Mon_low_level_printstring("  ");
    outputchar++;
    if( outputchar == 0x3A) outputchar = 0x41;
  }
  Mon_low_level_printstring("\n\r");

  /* now, display the == characters */
  Mon_low_level_printstring("========");
  Mon_low_level_printstring("  ");
  for(x=0; x < Gdsize; x++)
  {
    Mon_low_level_printstring("== ");
  }
  Mon_low_level_printstring("\n\r");


  /* display the memory to the screen */
  /* address display will start at firstdisplayaddr */
  /* but we will "blank out" the data until we reach */
  /* the enteredstartaddr which user in interested in */
  /* as we read and display bytes, we'll write the values */
  /* to a temp buffer so that characters can be displayed at */
  /* the end of the line */
  //data=Mon_low_level_rdmem(enteredstartaddr);
  //numofleadingzeros
   currentaddress = firstdisplayaddr;

   bytes2do = length + (enteredstartaddr - firstdisplayaddr) +1;

  for(i = 0; i < bytes2do; i++)
  {
    printaddress(currentaddress);
    Mon_low_level_printstring("  ");
    
    for(x = 0; x < Gdsize; x++)
    {
     outputchar = Mon_low_level_rdmem(currentaddress);
     if(currentaddress++ < enteredstartaddr)
     {
      Mon_low_level_printstring("  ");
      Mon_low_level_printstring(" ");
      temp[x] = ' ';
     }
     /* if end of line, display printable ascii */
     else
     {
       sprintf(output,"%2X",outputchar);
       Mon_low_level_printstring(output);
       Mon_low_level_printstring(" ");

       /* if printable, display it*/
       if(isprint(outputchar))
	   temp[x] = outputchar;

       /* otherwise display a period */
       else
	   temp[x] = '.';
     }

  }/* end of printing a line */
   i += Gdsize;
   Mon_low_level_printstring(" ");
   
   /* print the stuff at the right, saved in temp */
   for(k=0; k < Gdsize; k++)
   Mon_low_level_putch(temp[k]);

   Mon_low_level_printstring("\n\r");
 }

}

/* static void display_line(unsigned long address, int dsize) */

/* end page - eject   eject - new page */
/*******************************************************************************
*
*   FUNCTION NAME :             edit    
*
*---------------------------------- PURPOSE ------------------------------------
*  	
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: 
*
*   PARAMETERS:     
*                   
*   RETURN VALUE:   
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
*  edit <startaddress>
*  Provides for editing of memory.  After the initial  edit <startaddress> is
*  entered, the first memory address will be displayed as  aaaaaaaa:  hh = 
*  where aaaaaaaa is the address and hh is the hex value at that address. You
*  can enter a new value as two valid hex digits or return to terminate the 
*  command. If you enter a new value, the next memory location will then be
*  displayed.
********************************************************************************/
void monitor :: edit(void)
{
  unsigned char usercmdstring[80];
  int currentaddress;
  int numofitems;
  
  int outputchar;
  unsigned char newcharstr[80];

  numofitems = sscanf((const char *)input,"%s%x",&usercmdstring,&currentaddress);

  /* must be two items, edit <startaddr> */
  if(numofitems < 2) return;
  
  Mon_low_level_printstring("\n\r");
  
  do
  {
   printaddress(currentaddress);
   Mon_low_level_printstring(":  ");
   outputchar = Mon_low_level_rdmem(currentaddress);
   printbyteinhex(outputchar);
   Mon_low_level_printstring(" = ");
   getline(newcharstr);
   //Mon_low_level_printstring(newcharstr);
   
   sscanf((const char *)newcharstr,"%2X",&outputchar);

   if( strlen((const char *)newcharstr) > 0 )
   {
      Mon_low_level_wrmem(currentaddress,(unsigned char)outputchar);
      //Mon_low_level_putch(outputchar);
      Mon_low_level_printstring("\n\r");
      currentaddress++;
   }
   
  }while( strlen((const char *)newcharstr) > 0 );
}

/* end page - eject   eject - new page */
/*******************************************************************************
*
*   FUNCTION NAME :             writemem    
*
*---------------------------------- PURPOSE ------------------------------------
*  	
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: 
*
*   PARAMETERS:     
*                   
*   RETURN VALUE:   
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
*  writemem <addr> <writedata_hexvalue)
********************************************************************************/

void monitor :: writemem(void)
{
  char usercommandstring[80];
  int writeaddr;
  int numofitems;
  int data;

  numofitems = sscanf((const char *)input,"%s%x%x",&usercommandstring,&writeaddr,&data);
  if(numofitems < 3) return;

  /* write to the memory */
  Mon_low_level_wrmem(writeaddr,(unsigned char)data);

}

/* end page - eject   eject - new page */
/*******************************************************************************
*
*   FUNCTION NAME :             fill  
*
*---------------------------------- PURPOSE ------------------------------------
*  	
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: 
*
*   PARAMETERS:     
*                   
*   RETURN VALUE:   
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
*  fill <startaddr> <length> <hexvalue>
********************************************************************************/

void monitor :: fill(void)
{
  char usercommandstring[80];
  unsigned long address;
  int length;
  int data;
  int numofitems;
  int x;

  numofitems = sscanf((const char *)input,"%s%lX%i%x",&usercommandstring,&address,&length,&data);
  if(numofitems != 4) return;

  /* write to the memory */
  for(x=0; x < length; x++)
  {
   Mon_low_level_wrmem(address,(unsigned char)data);
   address++;
  }
}

/* end page - eject   eject - new page */
/*******************************************************************************
*
*   FUNCTION NAME :             quit    
*
*---------------------------------- PURPOSE ------------------------------------
*  	
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: 
*
*   PARAMETERS:     
*                   
*   RETURN VALUE:   
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
*
********************************************************************************/
void monitor :: quit (void)
{
  Mon_low_level_printstring("\n\ruser aborted\n\r");

  Gexitflag = 1;
}

/* end page - eject   eject - new page */
/*******************************************************************************
*
*   FUNCTION NAME :             helpcmd    
*
*---------------------------------- PURPOSE ------------------------------------
*  	
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: 
*
*   PARAMETERS:     
*                   
*   RETURN VALUE:   
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
*
********************************************************************************/
void monitor :: helpcmd(void)
{
	
Mon_low_level_printstring ("\n\rcommands are \n\r");
Mon_low_level_printstring ("     read     - display memory: read <start addr> <length>\n\r");
Mon_low_level_printstring ("     write    - modify memory: write <address> <value>\n\r");
Mon_low_level_printstring ("     edit     - edit memory <esc><return> to end: edit address\n\r");
Mon_low_level_printstring ("     fill     - fill memory: fill <startaddr> <length> <hexvalue)\n\r");
Mon_low_level_printstring ("     dsize    - set display size (1 to 16): dsize <size> \n\r");
Mon_low_level_printstring ("     help     - display this list of commands\n\r");
Mon_low_level_printstring ("     about    - prints details about monitor\n\r");
Mon_low_level_printstring ("     quit     - quit this program\n\r");
Mon_low_level_printstring ("     goto     - branch to address: goto <addr>\n\r");
Mon_low_level_printstring ("     call     - call to address: call <addr>\n\r");
Mon_low_level_printstring ("     bkptson  - enable breakpoint system \n");
Mon_low_level_printstring ("     setbkpt  - set breakpoint: setbkpt1 <addr>\n\r");
Mon_low_level_printstring ("     clrbkpt  - clr breakpoint: clrbkpt1 <addr>\n\r");
Mon_low_level_printstring ("     loopwr  -  loopwr <address> <wrdata16> <optional #loops> \n\r");
Mon_low_level_printstring ("     looprd  -  looprd <address> <optional #loops> \n\r");

#ifndef UNFINISHED
Mon_low_level_printstring ("     find    - find pattern in memory\n\r");
Mon_low_level_printstring ("     crc     - calculates 16 bit crc on mem block \n\r");
Mon_low_level_printstring ("     user1   - user menu\n\r");
Mon_low_level_printstring ("     tstmem  - test memory\n\r");
#endif
}

void monitor :: about(void)
{
  signon();
}



/**********************************************************************
		   U T I L I T Y	  F U N C T I O N S
***********************************************************************/

/* end page - eject   eject - new page */
/*******************************************************************************
*
*   FUNCTION NAME :             printbyteinhex    
*
*---------------------------------- PURPOSE ------------------------------------
*  	
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: 
*
*   PARAMETERS:                 int byte     
*                   
*   RETURN VALUE:   
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
*  Displays a byte as two hexidecimal digits. Any leading zero is printed.
*  To change the leading zero printing, modify #define LEADINGZERODIGITS
********************************************************************************/
void monitor :: printbyteinhex(int byte)
{
  int x;
  int numofleadingzeros;

  unsigned char byte_string[40];
  ULTOA((unsigned long)byte , byte_string, Gbasemodulo);

  numofleadingzeros = 2 - strlen((const char *)byte_string);
  for(x = 0; x < numofleadingzeros; x++ )
  {
   /* print the leading zeroes */
       Mon_low_level_putch(LEADINGZERODIGITS);

  }
  /* print the address */
    Mon_low_level_printstring((char *)byte_string);

}

/* end page - eject   eject - new page */
/*******************************************************************************
*
*   FUNCTION NAME :             printaddress    
*
*---------------------------------- PURPOSE ------------------------------------
* Display an address (or any eight hex digit value to the screen) 	
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: 
*
*   PARAMETERS:                 unsigned long address     
*                   
*   RETURN VALUE:   
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
*  Prints an eight hex digit value to the terminal screen. It was designed to be
*  used for address display but will work for anything.  It always displays an
*  eight character hexidecimal value with leading zeros being inserted. The
*  smallest value it will display is 00000000 and the greatest value is FFFFFFFF
*  To change the leading zero printing, modify #define LEADINGZERODIGITS
********************************************************************************/
void monitor :: printaddress(unsigned long address)
{
  int x;
  int numofleadingzeros;

  unsigned char address_string[80];
  ULTOA(address,address_string,Gbasemodulo);

  numofleadingzeros = NUMOFADDRESSDIGITS - strlen((const char *)address_string);
  for(x = 0; x < numofleadingzeros; x++ )
  {
   /* print the leading zeroes */
       Mon_low_level_putch(LEADINGZERODIGITS);

  }
  /* print the significant address digit(s) */
    Mon_low_level_printstring((char *)address_string);

}

/* end page - eject   eject - new page */
/*******************************************************************************
*
*   FUNCTION NAME :             clrscr    
*
*---------------------------------- PURPOSE ------------------------------------
*  	
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: 
*
*   PARAMETERS:     
*                   
*   RETURN VALUE:   
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
*   clears the terminal screen
********************************************************************************/
void monitor :: clrscr(void) /* clears the screen */
{
  int x;
  for (x=1; x<=SCREENLINESTOCLEAR; x++)
    {
      Mon_low_level_printstring("  \n\r");
    }
}

/* end page - eject   eject - new page */
/*******************************************************************************
*
*   FUNCTION NAME :             signon    
*
*---------------------------------- PURPOSE ------------------------------------
*  	
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: 
*
*   PARAMETERS:     
*                   
*   RETURN VALUE:   
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
* Output signon message to terminal
********************************************************************************/

void monitor :: signon(void)
{
  Mon_low_level_printstring("\n\r**********************************\n\r");
  Mon_low_level_printstring("Mcore RCE Monitor version ");
  Mon_low_level_printstring(Gversion);
  Mon_low_level_printstring("Archimedes Apollo Project\n\r");
  Mon_low_level_printstring("Type help for command list\n\r");
  Mon_low_level_printstring("**********************************\n\r");

}

/* end page - eject   eject - new page */
/*******************************************************************************
*
*   FUNCTION NAME :              prompt    
*
*---------------------------------- PURPOSE ------------------------------------
*  	
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: 
*
*   PARAMETERS:     
*                   
*   RETURN VALUE:   
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
* displays command prompt message to terminal
********************************************************************************/

void monitor :: prompt(void)
{
  Mon_low_level_printstring ("\n\rcmd> ");
}


/* end page - eject   eject - new page */
/*******************************************************************************
*
*   FUNCTION NAME :             getline    
*
*---------------------------------- PURPOSE ------------------------------------
*  	
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS:  input buffer must be declared as input[80]
*
*   POSTCONDITIONS: 
*
*   PARAMETERS:                 unsigned char * input     
*                   
*   RETURN VALUE:   
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
*  gets up to 79 characters from the terminal and stores in input[].
*  input is terminated either when input is full or when user pushes <return>
*  The return is NOT stored in the array.The following keys are recognized:
*  backspace  moves cursor back one and
*	          and erases last character(repl
*  delete	  with whitespace
********************************************************************************/

void monitor :: getline(unsigned char * input)
{
  unsigned char c;
  int x;

  for (x=0; x<=80; x++)   /* clear the buffer by */
    {			  /* inserting nulls in all positions */
      input[x] = '\0';
    }

  x=0;
  while ((c=Mon_low_level_getch()) != ('\r'))
								  /* while no <return> is pushed, */
    {    			              /* keep getting characters */

      if ( ( (c==BS_KEY) || (c==DEL_KEY) ) && (x > 0) )
	{
	  Mon_low_level_putch(BS_KEY);   /* send backspace to terminal to back it up */
	  Mon_low_level_putch(SPACE);    /* write over what was there with whitespace */
	  Mon_low_level_putch(BS_KEY);   /* write reposition cursor at whitespace */
	  x--;	           /* backup the buffer pointer */
	  input[x] = '\0';  /* write a null into current buffer position */

	}
      else
	{
		if ( (c !=BS_KEY) && (c !=DEL_KEY) )
		{
		    Mon_low_level_putch(c);
		    input[x] = c;
		    x++;
		}
	}
    }

}




/* end page -    - new page */
/******************************************************************************* 
*
*   FUNCTION NAME :              input_error   
*
*---------------------------------- PURPOSE ------------------------------------
*  handles unrecognized command entries 
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: None.
*
*   PARAMETERS: None.
*
*   RETURN VALUE: 
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
*
********************************************************************************/

void monitor :: input_error()
{
Mon_low_level_printstring ("\n\r   ERROR - COMMAND NOT FOUND Type help for list of cmds! \n\r");

}

/* end page -    - new page */
/******************************************************************************* 
*
*   FUNCTION NAME :             ULTOA
*
*---------------------------------- PURPOSE ------------------------------------
*  Convert unsigned long integer to a printable ascii string 
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS:  None.
*
*   POSTCONDITIONS:             None.
*
*   PARAMETERS:                 unsigned long address  - number to be converted.
*                               unsigned char * string - destination array where
*                                                        ascii string will be put
*                               unsigned long radix    - output radix, use
*                                                        10  for decimal
*                                                         8  for octal
*                                                        0xF for hexidecimal
*   RETURN VALUE:               none.
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
* Convert an unsigned long to string for printing. The original algorithm for  
* doing this was obtained from page 64 void itoa(int n, char s[]) of Kernighan 
* and Ritchie ANSI C manual.  It was modified to handle a bigger address value
* and to handle any radix up to hexidecimal.
********************************************************************************/
void monitor :: ULTOA(unsigned long address, unsigned char * string, unsigned long radix)
{
    unsigned long i;
    unsigned long swap;
    unsigned long j;
    unsigned long temp;
    
    i = 0;

    /* generate digits in reverse order */
    /* since we don't know how big the number is */
    do
    {
     /* divide by radix, get remainder and convert to ascii (add 0x30) */
     temp = address % radix + '0';
     
     /* there is a gap in ascii table from 9 to A */
     /* this is only an issue for radix hex (0xF) */
     if(temp > 0x39) temp += 7; 
     
	 string[i++] = (unsigned char)temp;   /* get next digit */

    }while ((address /= radix) > 0);    /* delete it */

    string[i] = '\0';

    /* now reverse the string for printing since */
    /* we print the most significant digit first */
    for (i = 0, j = strlen((const char *)string) - 1; i < j; i++, j-- )
    {
	swap = string[i];
	string[i] = string[j];
	string[j] = (unsigned char)swap;
    }

}

/* end page -    - new page */
/******************************************************************************* 
*
*   FUNCTION NAME :             Mon_low_level_io_init
*
*---------------------------------- PURPOSE ------------------------------------
*   
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: None.
*
*   PARAMETERS: None.
*
*   RETURN VALUE: 
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
*
********************************************************************************/

void monitor :: Mon_low_level_io_init(void)
{
#ifdef EMBEDDED_PLATFORM
  mcore_ser_DUARTch1_Open(BAUD9600, SER8BITS, NOPARITY, ONESTOP, POLLED_MODE); /*init the serial port */
#endif
}

/* end page -    - new page */
/******************************************************************************* 
*
*   FUNCTION NAME :             Mon_low_level_printstring
*
*---------------------------------- PURPOSE ------------------------------------
*   
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: None.
*
*   PARAMETERS:                 unsigned char * string
*
*   RETURN VALUE: 
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
*
********************************************************************************/
void monitor :: Mon_low_level_printstring(char * string)
{
#ifdef DOSUNIX_PLATFORM
  printf("%s", string);
#endif

#ifdef EMBEDDED_PLATFORM
  mcore_ser_DUARTch1_putstring(string);
#endif
}

/* end page -    - new page */
/******************************************************************************* 
*
*   FUNCTION NAME :         Mon_low_level_putch
*
*---------------------------------- PURPOSE ------------------------------------
*   
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS:
*
*   POSTCONDITIONS: None.
*
*   PARAMETERS:             unsigned char data
*
*   RETURN VALUE: 
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
*
********************************************************************************/
void monitor :: Mon_low_level_putch(unsigned char data)
{
#ifdef DOSUNIX_PLATFORM
  putch(data);
#endif

#ifdef EMBEDDED_PLATFORM
  mcore_ser_DUARTch1_putchar(data);
#endif

}

/* end page -    - new page */
/******************************************************************************* 
*
*   FUNCTION NAME :         Mon_low_level_putint
*
*---------------------------------- PURPOSE ------------------------------------
*   
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: None.
*
*   PARAMETERS:             int n, unsigned int putint_modulus.
*
*   RETURN VALUE: 
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
*
********************************************************************************/
void monitor :: Mon_low_level_putint(int n, unsigned int putint_modulus)
{
#ifdef DOSUNIX_PLATFORM
  if(putint_modulus == 16)
     printf("%x",n);
  else
     printf("%i",n);
    
#endif

#ifdef EMBEDDED_PLATFORM
  mcore_ser_DUARTch1_putint(n, putint_modulus);
#endif

}




/* end page -    - new page */
/******************************************************************************* 
*
*   FUNCTION NAME :         Mon_low_level_getch
*
*---------------------------------- PURPOSE ------------------------------------
*   
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: None.
*
*   PARAMETERS: None.
*
*   RETURN VALUE: 
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
*
********************************************************************************/

unsigned char monitor :: Mon_low_level_getch(void)
{
 unsigned char data;
 
#ifdef DOSUNIX_PLATFORM
  data = getch();  
  return ( data );
#endif

#ifdef EMBEDDED_PLATFORM
  mcore_ser_DUARTch1_GetNextChar(&data); /* getchar */
  return (data );
#endif
}

/* end page -    - new page */
/******************************************************************************* 
*
*   FUNCTION NAME :             Mon_low_level_gets
*
*---------------------------------- PURPOSE ------------------------------------
*   
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: None.
*
*   PARAMETERS:                 char * string
*
*   RETURN VALUE:               same pointer passed in or null on failure
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
*
********************************************************************************/

char * monitor ::  Mon_low_level_gets(char * string)
{
#ifdef EMBEDDED_PLATFORM

 unsigned char data;
 
 while( (data = Mon_low_level_getch() ) != '\n')
 {
   *string++ = data; 
 }
 
 string = '\0';
 return(string);
#else
return gets(string);
#endif    
}


/* end page -    - new page */
/******************************************************************************* 
*
*   FUNCTION NAME :              Mon_low_level_rdmem
*
*---------------------------------- PURPOSE ------------------------------------
*   
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: None.
*
*   PARAMETERS:                 unsigned long address
*
*   RETURN VALUE: 
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
*
********************************************************************************/

unsigned char  monitor ::  Mon_low_level_rdmem(unsigned long address)
{
 unsigned char data;

#ifdef DOSUNIX_PLATFORM
 data = testmemory[address];
#endif

#ifdef EMBEDDED_PLATFORM
data = *( (unsigned char *)address );
#endif
 
 return data;
}

/* end page -    - new page */
/******************************************************************************* 
*
*   FUNCTION NAME :             Mon_low_level_wrmem
*
*---------------------------------- PURPOSE ------------------------------------
*   
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: None.
*
*   PARAMETERS:                 unsigned long address, unsigned char data
*
*   RETURN VALUE: 
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
*
********************************************************************************/

void monitor ::  Mon_low_level_wrmem(unsigned long address, unsigned char data)
{
#ifdef DOSUNIX_PLATFORM
  testmemory[address] = data;
#endif

#ifdef EMBEDDED_PLATFORM
  *( (unsigned char *)address ) = data;
#endif


}

/* end page -    - new page */
/******************************************************************************* 
*
*   FUNCTION NAME :             Mon_low_level_jump
*
*---------------------------------- PURPOSE ------------------------------------
*   
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS:             None.
*
*   PARAMETERS:                 unsigned int address
*
*   RETURN VALUE: 
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
*
********************************************************************************/

 void monitor ::  Mon_low_level_jump(unsigned int address)
{
#ifdef EMBEDDED_PLATFORM
asm (" jmp r2");
#endif    

}

/* end page -    - new page */
/******************************************************************************* 
*
*   FUNCTION NAME :             Mon_low_level_call
*
*---------------------------------- PURPOSE ------------------------------------
*   
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: None.
*
*   PARAMETERS: None.
*
*   RETURN VALUE: 
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
*
********************************************************************************/

void monitor ::  Mon_low_level_call(unsigned int address)
{
#ifdef EMBEDDED_PLATFORM
asm (" jsr r2");
#endif    

}

/* end page -    - new page */
/******************************************************************************* 
*
*   FUNCTION NAME :             Mon_low_level_bkpt_setup
*
*---------------------------------- PURPOSE ------------------------------------
*   
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: None.
*
*   PARAMETERS: None.
*
*   RETURN VALUE: 
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
*
********************************************************************************/

 void monitor ::  Mon_low_level_bkpt_setup(void)
{
#ifdef EMBEDDED_PLATFORM
 *( ( unsigned long *)MCORE_BREAKPOINT_EXCEPTION_VECTOR) = (unsigned long)Mon_low_level_bkpt_handler;
#endif    

}

/* end page -    - new page */
/******************************************************************************* 
*
*   FUNCTION NAME :             Mon_low_level_bkpt_handler
*
*---------------------------------- PURPOSE ------------------------------------
*   
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: None.
*
*   PARAMETERS: None.
*
*   RETURN VALUE: 
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
*
********************************************************************************/

#ifdef EMBEDDED_PLATFORM
asm("mcore_breakpoint_except_wrp:");
/* Jump to "C" portion of interrupt service routine */
asm(" jsri Mon_low_level_bkpt_handler");   
asm(" rte") ;  /* Return from a "normal" (not fast) interrupt */
#endif

// Upon entering a service routine, MCORE saves the PC in the EPC register,
// and the PSR in the EPSR, and then clears the EE(exception enable)
// bit in the PSR(processor status register) to prevent future
// exception-caused writes to the EPC register and EPSR.

// Save the state of the normal interrupt/exception program counter and
// status registers, EPC(cr4), and EPSR(cr2), respectively, 
// so if a debugger intentionally causes an exception, EPC and EPSR
// can be written to.  A debugger might intentially insert an illegal
// opcode to cause an illegal opcode exception at the address of a desired
// breakpoint, and then handle the breakpoint through a service routine
// for the illegal opcode exception.  The values of 
// PC and PSR will still be saved by hardware to the EPC(cr4) and EPSR(cr2),
// respectively, even if the illegal opcode (breakpoint) is encountered in
// an interrupt service routine.

void monitor ::  Mon_low_level_bkpt_handler(void)
{
#ifdef EMBEDDED_PLATFORM
    asm(" subi r0,32") ;                     /* save regs on stack */
    asm(" subi r0,28") ;
    asm(" stm r1-r15,(r0)");  
    
    asm(" mtcr r1, SS1");                    /* save R1 to scratchpad 1 */
    
    asm(" subi r0, 4");                      /* Allocate 4 bytes of stack space. */
    asm(" mfcr r1, EPC");                    /* Get copy of EPC(cr4).            */
    asm(" stw  r1, (r0,0)" );                /* Store EPC(cr4) on the stack.     */
    asm(" mtcr r1, SS3");               /* also save EPC in scratchpad register 3 */
                                        /* this is used to resolve the breakpoint */

    asm(" subi r0, 4") ;                     /* Allocate 4 bytes of stack space. */
    asm(" mfcr r1, EPSR");                    /* Get copy of EPSR(cr2).           */
    asm(" stw  r1, (r0,0)" );                /* Store EPSR(cr2) on the stack.    */
 
    /* Since we have saved both the EPC and the EPSR, we can now set the           */
    /* EE bit in the PSR to allow the processor to write to both registers         */
    /* in response to an exception.                                                */
    asm(" mfcr r1,PSR");                     /* Set the EE, exception    */
    asm(" bseti r1,8");                      /* enable bit in the PSR    */
    asm(" mtcr r1,PSR");                     /* to 1 to cause the PSR    */
                                             /* and the PC to be copied  */
                                             /* to the EPSR and the      */
                                             /* EPC, respectively.       */

    /* The IE (interrupt enable) bit is cleared by hardware upon entry  */
    /* to this interrupt service routine.  Consequently, software does  */
    /* not have to perform this task.                                   */ 
    
                                        /* save registers in array for printing */
    asm(" mtcr r0, SS0");               /* save stack pointer to scratchpad 0 */                                        
    asm(" mfcr r1, PSR");               /* get the PSR */
    asm(" mtcr r1, SS2");               /* save PSR in scratchpad 2 */
    
    asm(" lrw r1,  register_storage");  /* point R1 to register_storage array */
    asm(" mov r0,r1");                  /* point stack pointer to register array */
    asm(" mfcr r1, SS1");               /* restore R1 from scratchpad 1 */
    
    
    asm(" stm r1-r15,(r0)");                /* write R1-R15 to register_storage array */
    
                                            /* now write the stack pointer */
    asm(" lrw r1,  register_storage");      /* point R1 to register_storage array */
    asm(" addi r1,32");                     /*             */
    asm(" addi r1,28");                     /* point to register_storage[15] */
    asm(" mfcr r2,SS0");                    /* get value of saved stack pointer */
    asm(" addi r2,32");                     /* adjust it to point to where it was */
    asm(" addi r2,32");                     /* before the bkpt exception */
    asm(" st.w r2, (r1,0)");                /* write stack address to register_storage[15] */    
    
                                            /* now write the supervisor registers */
    asm(" lrw r1,  supreg_storage");        /* point R1 to supreg_storage array */
    asm(" mov r0,r1");                      /* point stack pointer to register array */
    asm(" mfcr r10, PSR");                   /* Get PSR            */
    asm(" mfcr r11, EPSR");                  /* Get EPSR            */
    asm(" mfcr r12, FPSR");                  /* Get FPSR            */
    asm(" mfcr r13, EPC");                   /* Get EPC            */
    asm(" mfcr r14, FPC");                   /* Get FPC            */
    asm(" mfcr r15, VBR");                   /* Get VBR            */
    asm(" stm r10-r15,(r0)");                /* write R1-R15 to register_storage array */
                                           
     
    /*******************/
    asm(" mfcr r0, SS0");                   /* recover stack pointer */
    
      
   /****************************************************************************/
    /* YOUR USER DEFINED HANDLER CODE STARTS HERE                               */
    /****************************************************************************/
          
                               /* RESTORE BKPT INSTRUCTION and bkpt id  */
                               /* R1 points to the breakpoint address */
                               /* R2 points to the bkpt id value */
                               
    asm(" mfcr r1, SS3");      /* get breakpoint address from scratchpad 3 */
                               /* this was saved when first entering the */
                               /* breakpoint exception handler */
    asm(" mov r2,r1");         /* copy R1 bkpt address to R2 */
    asm(" addi r2,2");         /* add 2 so that R2 points to bkpt id */
    asm(" ld.h r4, (r2,0)");   /* read bkpt id from memory into R4 */ 
    
    asm(" lrw r3, Gindex");    /* point R3 to address of Gindex variable */
    asm(" st.h r4, (r3,0)");   /* write bkpt id to Gindex variable */    
    
    Gtempa16 = bkptarray[Gindex]; /* get the saved bkpt instruction into temp */     
    Gtempb16 = bkptid[Gindex];    /* get the saved instr at id address into temp */
    
    asm(" lrw r5, Gtempa16");  /* point R5 to address of Gtempa16 variable */
    asm(" ld.h r5, (r5,0)");   /* get saved bkpt instruction into r5 */ 
    asm(" lrw r6, Gtempb16");  /* point R6 to address of Gtempb16 variable */
    asm(" ld.h r6, (r6,0)");   /* get saved instr at id address into r6 */ 

    asm(" mfcr r1, SS3");      /* get breakpoint address from scratchpad 3 */
    asm(" mov r2,r1");         /* copy R1 bkpt address to R2 */
    asm(" addi r2,2");         /* add 2 so that R2 points to bkpt id address */


    asm(" st.h r5,(r1,0)");    /* restore saved instruction (in R5) to bkpt address */
    asm(" st.h r6,(r2,0)");    /* restore saved instruction (in R6) to bkptid addr */
    
    mcore_7segdispl_wr(LED_PATBP);
    Mon_low_level_printstring("\n\r  Breakpoint found, address = ");
    printaddress(bkptaddr[Gindex]);
    Mon_low_level_printstring("    bkpt number = ");
    printbyteinhex((int)Gindex);
    Mon_low_level_printstring("\n\r");

    Display_Registers();
    
    /****************************************************************************/
    /* YOUR USER DEFINED HANDLER CODE ENDS HERE                                 */
    /****************************************************************************/
    /* Copy the memory-saved values for the interrupt/exception program counter,  */
    /* EPC(cr4), and processor status register, EPSR(cr2), back to their respective */
    /* registers.                                                   */

    asm(" ldw r1,(r0,0)");      /* Get the saved EPSR from the stack.  */
    asm(" mtcr r1,EPSR");        /* Copy value to EPSR (register).      */
    
    asm(" addi r0,4");          /* Point stack pointer to EPC value.        */
    asm(" ldw r1,(r0,0)");      /* Get the saved EPC value from the stack.  */
    asm(" mtcr r1,EPC");        /* Copy value to EPC register.          */
    
                               
    asm(" addi r0,4");          /* Point stack pointer to saved epsr  */                            
    asm(" ldm r1-r15,(r0)");    /* Restore registers from memory.     */
    asm(" addi r0,32");         /* Restore stack pointer.             */
    asm(" addi r0,28");

#endif    
}

/* end page -    - new page */
/******************************************************************************* 
*
*   FUNCTION NAME :   Display_Registers
*
*---------------------------------- PURPOSE ------------------------------------
*   
*---------------------------------- SYNOPSIS -----------------------------------
*
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS: None.
*
*   PARAMETERS: None.
*
*   RETURN VALUE: 
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
*
********************************************************************************/

void  monitor ::  Display_Registers(void)
{
  int x;
  
  Mon_low_level_printstring("Registers: ");
  for (x=0; x < NUMOFREGISTERS -1 ;x++ )
  {
     Mon_low_level_putch('R');
     Mon_low_level_putint(x+1, 10);  /* start with R1 */
     
     /* do this for formatting to make it look nice */
     if(x < 9)
     Mon_low_level_printstring(":  ");
     else
     Mon_low_level_printstring(": "); 
     
    /* printaddress is used because it will print all 32 bits */
    /* as unsigned and will print leading zeros so its idea for */
    /* this purpose. Nevertheless, we are printing register */
    /* contents, not addresses so don't be confused by the name */
    /* printaddress */ 
     printaddress(register_storage[x]);
     
     Mon_low_level_putch(' ');
     
     if(x == 7) /* put 8 registers on a line */
     {
       Mon_low_level_printstring("\n\r           ");   
     }
  }
   //Mon_low_level_printstring("\n\r");
   
   /* now show the stack */
   Mon_low_level_printstring("\n\r           SP/R0: ");
   printaddress(register_storage[15]);
   
   /* now print the supervisory registers PSR,EPSR,FPSR,EPC,FPC,VBR supreg_storage */
   Mon_low_level_printstring(" PSR: ");
   printaddress(supreg_storage[0]);  
   Mon_low_level_printstring(" EPSR: ");
   printaddress(supreg_storage[1]);  
   Mon_low_level_printstring(" FPSR: ");
   printaddress(supreg_storage[2]);  
   Mon_low_level_printstring(" EPC: ");
   printaddress(supreg_storage[3]);  
   Mon_low_level_printstring(" FPC: ");
   printaddress(supreg_storage[4]);  
   Mon_low_level_printstring(" VBR: ");
   printaddress(supreg_storage[5]);  
   
   
   Mon_low_level_printstring("\n\r");  
}    

//#define TESTITM

//#ifdef TESTIT

#include "monitor.hpp"
#include <iostream.h>

int main(void)
{
 monitor monitorobj;

 monitorobj.start();


 cout << endl << " monitor done" << endl;

 return 0;
}


//#endif