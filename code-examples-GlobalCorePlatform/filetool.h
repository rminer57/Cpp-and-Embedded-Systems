
#ifndef __filetool__
#define __filetool__

// if you define this, the ANSI file handling routines will be used for
// file I/O INSTEAD of the iostream I/O. If ANSIFILES is not defined then
// the iostream library will be used instead.
#define USE_ANSI_FILE_IO
#define DEBUGON
/************************************************************
NAME:	       filetool.hpp
PURPOSE:       provides functions to perform operations on files

NOTES:	       As new member functions are written and tested, I'll
	       enter version # date next to each item in "wish list"

CREDITS:       Code and or help was obtained from the following sources:

	       Frank J. Mitropoulos - Professor of Computer Science,
			              Nova University.

	       C++ Components and Algorithms book by Scott Robert Ladd.
	       Applying C++ book by Scott Robert Ladd.

REVISION HISTORY

VERSION  DATE     PGMER	    NOTES/CHANGES
-------  ----     -----     -------------
1.00     3/14/96  R.MINER  INITIAL VERSION

1.01	 3/15/96  R.MINER  added read file into internal buffer
1.02     3/15/96  R.MINER  added write internal buffer back to file
			   added private boyer moore find pattern function
			   added FindPattern user function
			   added display Version number to screen function

			   NOTE: ALL DELETE OPERATIONS WORK ON THE INTERNAL
			   BUFFER, NOT THE FILE. YOU MUST TO A WRITE TO
			   MAKE THE DELETIONS PERMANENT

			   added For first occurance of a pattern after
			   cur cursor pos, del n chars from beg pos of
			   pattern, searching till end of file.

1.03     4/03/96	   Added For all occurances of a pattern after the
			   current cursor position, del n chars from the
			   beginning position of the pattern, searching
			   till end of file.  Added FatalError and WarningError
			   handler functions. Added fileaccessmode and afileisopen
			   switches.  Modified open function to use the file
			   access mode switch setting. Added #define to use
			   ANSI file routines or STREAM LIBRARIES. Tested for single
			   and multiple occurances of pattern to be deleted, in
			   front, middle and end of file. It seems to work.

1.04	 TBD		   Add code to do a search/replace

1.05     TBD               Add code to process files too big to fit in memory.

1.06     TBD		   Add second constructor which takes filename as param.
			   and modify open function + overloaded open to handle this.
			   Turn the #ANSI define off (use streams) and test it.

			   del all occurances of a given character in file
			   del next n occurances of a given pattern in file

			   del next n occurances of given character in buffer
			   del char at current cursor position in buffer (file)
			   del all occ of given char from cur pos to EOF

			   make case sensitivity in finds controlled by the
			   following variable
			   Boolean case_sensitive_finds;
			   case_sensitive_on()   make these functions
			   case_sensitive_off()

			   insert char at front of file
			   insert char at rear of file
			   insert char in front of next occurance of target char
			   insert char behind next occurance of target char c
			   insert char in front of every occurance of target char
			   insert char behind every occurance of target char

			   NOTE: gotos WILL BE DONE ON THE BUFFER AND
			   POSITIONS FILEBUFFER POINTER TO THAT ITEM.
			   goto next occur of given character in buffer
			   goto a given pattern of characters in buffer
			   goto next line of file
			   goto line n of file
			   display next line of file
			   display line n of file
			   display next n lines of file
			   backup to start of current line

			   convert binary file to text (hex2ascii)
			   convert text file to binary (ascii2hex)

			   is file binary  isbinfile()
			   is file text    istextfile()

			   read file dos attributes
			   set file dos attributes
			   set file access mode for the filetool.open()
			   (default mode will be read and write)

			   overload + and & operators to concatenate two files
			   overload - operator to find and delete contents
					    of one file from another file.
			   overload >> operator to dump file to screen
			   overload << to read from keyboard to file
			   overload < operator to read from file to buffer
			   overload > operator to write buffer to file
			   overload = operator to set two filetool objects equal

			    overload the open function for different types of file access or we
			    might just want to have "flags" for different types of access that
			    must be set up before calling open. See the notes in open function
			    for access types

			    write date/timestamp/checksum to file
			    read  date/timestamp/checksum from file

			    encrypt file using IDEA algorithm
			    decrypt file using IDEA algorithm

			    compress file using PKZIP algorithm
			    decompress file using PKZIP algorithm

			    print file to line printer
			    dump file to serial port

--------------------------------------------------------------------------
BUG HISTORY

VERSION  FIXED IN	BUG # AND DESCRIPTION
-------  --------       ---------------------
1.03     TBD            1-When deleting a word several times in a multiline file,
			four extra garbage chars get put just before EOF.
			The length of chars being passed to the ostream write function
			is the correct value but nevertheless, 4 extra chars appear.
			A file consisting of 1 line with 1 or more occurances of the word,
			can have the occurances sucessfully deleted without the 4 xtra chars.


COMPILER INFO: USED BORLANDC++ VERSION 3.1
************************************************************/
#define Ver_num 1.04  // being modified and debugged

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream.h>
#include <fstream.h>
#include <conio.h>

enum Boolean
    {
    BOOL_FALSE = 0,
    BOOL_TRUE  = 1
    };

enum ONOFF
    {
    OFF = 0,
    ON  = 1
    };

enum YESNO
    {
    NO = 0,
    YES  = 1
    };

enum ACCESSMODE   /// file access mode selections for use by the
    {             /// member function open.
    READ = 0,
    WRITE =1,
    READWRITE =2, /// this is the default switch, unless you
    APPEND = 4    /// call the setaccessmode function to override.
    };

class filetool
{
 public:
  //----------------------------------------------------------------------
  filetool();  ///  CONSTRUCTORS

//filetool(char *Filename, ACCESSMODE Fileaccessmode=READ);
  filetool(char *Filename, ACCESSMODE Fileaccessmode);
  //----------------------------------------------------------------------
  ~filetool();               /// destructor
  //----------------------------------------------------------------------


  void close(void);        /// closes a file
  #ifndef USE_ANSI_FILE_IO
    void clearEOF();         /// clear the fstream EOF flag
  #endif
  void dumpbuffer(); /// debug function - remove later
  void dumpfile(void);     /// displays file to screen
  void Delete(char * &bufstart, char * &bufcur,size_t &buflen ,size_t delcount);
  /// delete pattern plus next n chars from cur buf pos to EOF (end of buf)
  Boolean  del_pat_plusn(char pattern[], size_t nextnchars, char terminator);
  Boolean del_all_pat_plusn_Buf(char pattern[], size_t nextnchars, char terminator);
  Boolean del_all_pat_plusn_File(char pattern[], size_t nextnchars, char terminator);
  // substring methods at current buffer position
  //  void Delete(char oldbufcur[], size_t bufpos, size_t delcount);
  /// substring search method
  Boolean FindPattern(char pattern[], char * &bufcur, size_t bufLen, char terminator);
  Boolean SearchReplace(char searchstr[], char replacestr[], 
                        char * &bufcur, size_t bufLen, char terminator); 
  void FillBuffer(char array[], int data, int beg, int end);
  size_t getfilelength(void);  /// get length of the file (not the filebuffer)
  size_t getbufferlength(void);
  size_t getfilepos(void);  /// get file position
  size_t getbufpos(char *bufstart, char *bufcur); /// get position of filebuffer pointer
  void gotobeg(void);       /// goto beginning of file
  char * gotobufpos(char *bufst, size_t newpos, size_t buflen);     /// set position of filebuffer pointer
  void gotofilepos(size_t pos); /// goto absolute position 0 to n in file
  void Insert(char * &bufstart, size_t pos, char ch);
  void Insert(char * &bufstart, size_t pos, char *string);
  void movepos(size_t n=0);   /// move buffer position + or - n characters
  void open(char *fname, ACCESSMODE Fileaccessmode=READ);
  void open(void);
  void readintobuf(void); /// read file into buffer and return pointer
  void setaccessmode(ACCESSMODE file_access=READ);  /// sets access mode of file
//  void setbufmaxsize(size_t size);  // set maximum size of a buffer
  void Version(void);      /// displays filename,version number,date,time
  void writetofile(void);  /// write buffer to file and return pointer

 private: // variables
   #ifndef USE_ANSI_FILE_IO
     fstream * fileobject;                 /// pointer to fileobject
   #else
     FILE * fileobject;                    ///
   #endif
   char * filename;                /// filename used with second constructor
   char * WRfilename;              /// used in writing
   size_t filelength;              /// filelength
   size_t filebufferlen;           /// length of file buffer
   char * filebuffer;              /// buffer pointer (current location)
   char * filebufferstart;         /// start of filebuffer
   char * filebufferend;           /// start of filebuffer
   size_t * Delta;                 /// pointer to BoyerMoore delta table
   static const size_t DeltaSize;  ///size of Delta table, 256 for ASCII
   Boolean case_sensitive_finds;
   YESNO afileisopen;          /// indicates if file is open when = BOOL_TRUE
   ACCESSMODE fileaccessmode;  /// desired access file mode -def is READWRITE
   size_t lastloadcount;
   static const size_t maxfilebufsize;  /// the target max buffer size
   size_t  remaining_filebytes;         /// bytes left to process in BIGFILE
   size_t  readfrom_filebytes_pos;       /// next file read position
   size_t  writeto_filebytes_bufendpos;  //  next write to file buffer end pos

  private: // functions
   void BuildBooyerMooreDeltaTable(char pattern[]);
   Boolean BoyerMooreFind(char pattern[],char * &bufcur, size_t bufLen, char terminator);
   Boolean BIGFILEpasshandler(void);   // do before calling readintobuf
   void FatalError(char * message, int number);
   void Free_Ptrs(void);
   size_t getnextfilepos(void);       // access remaining_filebytes var
   size_t getnextbufsize(void);       /// access remaining_filebytes_pos
   Boolean isBIGFILE(void); /// is it a bigfile
   void Init_Ptrs_to_NULL(void);
   void setWRfilename(char *fname);
   void setfilename(char *fname);
   void UnderConstruction(char * message);
   void WarningError(char * message, int number);
 };



#endif

