/*******************************************************************************
*                         COPYRIGHT 1997 MOTOROLA
*                    MOTOROLA CONFIDENTIAL PROPRIETARY
********************************************************************************
*
* FILE NAME      :    monitor.h
* ORIGINATOR     :    Randy Miner (rdm)
* DATE OF ORIGIN :    3/1/98
*
*---------------------------------- PURPOSE -----------------------------------  
* Header file to be included when using the debugger.
*--------------------------- PROJECT SPECIFIC DATA -----------------------------
*
*
*--------------------------------- REVISIONS -----------------------------------
* Date      Username      Description of Modification
* --------  ------------  -----------------------------------------------------*/

#ifndef monitor_h
#define monitor_h 1

/* comment out one of these. DOSUNIX_PLATFORM is used to allow */
/* development of high level functions from a dos environment */
//#define EMBEDDED_PLATFORM
#define DOSUNIX_PLATFORM

/*--------------------------- HEADER FILE INCLUDES ----------------------------*/

#include <iostream.h>

typedef struct		/* this declares a structure type which will hold */
{                   /* information about commands to be entered from keybd */
char * keyword;   /* command string-keyboard entry must match it */
//void (*fpntr) ();	/* function pointer-where to execute if match found */
}cmdstruct_t;

class monitor 
{

  public:

  cmdstruct_t * commands; //dispatch table

      monitor();
      ~monitor();
      void start(void);

	  /* THESE ARE "UTILITY" FUNCTIONS */
  void clrscr(void);	/* function to clear the screen */
  void signon(void);      /* function to print system signon messages */
  void prompt(void);      /* function to send prompt to user */
  void getline(unsigned char * input);     
  void getcmd (void);     /* reads the array, compares cmd string to structure */
   void ULTOA(unsigned long address, unsigned char * string, unsigned long radix);
  void printbyteinhex(int byte);
  void printaddress(unsigned long address);

/* THESE FUNCTIONS ARE THE SYSTEM COMMANDS */
  void readmem(void);   
  void writemem(void);      
  void edit(void);
  void fill(void);      
  void helpcmd(void);
  void about(void);
  void input_error();     
  void quit(void);        
  void find(void);
  void loopwr(void);
  void looprd(void);
  void tstmem(void);
  void user1(void);
  void dsize(void);
  void crc(void);
  void gotoaddr(void);
  void call(void);
  void setbkpt(void);
  void clrbkpt(void);
  void bkptson(void);

/* low level, requires modifications when porting */
  void          Mon_low_level_printstring(char * string);
  void          Mon_low_level_putch(unsigned char data);
  void          Mon_low_level_putint(int n, unsigned int putint_modulus);
  unsigned char Mon_low_level_getch(void);
  void          Mon_low_level_io_init(void);
  unsigned char Mon_low_level_rdmem(unsigned long address);
  void          Mon_low_level_wrmem(unsigned long address, unsigned char data);
  void          Mon_low_level_jump(unsigned int address);
  void          Mon_low_level_call(unsigned int address);
  void          Mon_low_level_bkpt_setup(void);
  void          Mon_low_level_bkpt_handler(void);
  void          mcore_breakpoint_except_wrp(void);
  char *        Mon_low_level_gets(char * string);
void                 Display_Registers(void);

  protected:
  

  private: 

};



#endif
