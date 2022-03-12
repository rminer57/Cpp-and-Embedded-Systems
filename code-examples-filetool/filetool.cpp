/* filetool class  */
#include "filetool.hpp"
#define TESTfiletool  /// if test defined, main will be included

///size of pattern search BoyerMoore delta table, 256 is # of ascii chars
const size_t filetool::DeltaSize = 256;
const size_t filetool::maxfilebufsize = 16;  /// maximum allowable size

/********************************************************************
	FILETOOL CLASS DEFAULT CONSTRUCTOR FUNCTION FILETOOL
// if you use this constructor, you have to call the open function
// using the filename and file access mode as parameters
********************************************************************/
  filetool::filetool()       /// constructor
  {
    #ifdef DEBUGON
	cout << endl << " ** FILETOOL class constructor - verbose debug messages ON **";
    #endif
	Init_Ptrs_to_NULL();
	filename=0;         /// filename, used when autoopen is on
	afileisopen = NO;
	fileaccessmode = READWRITE;   /// default access mode for open.

  }
/********************************************************************
	FILETOOL CLASS CONSTRUCTOR FUNCTION FILETOOL
 If you use this constructor, supply the filename and file accessmode
 inside the parenthesis. If you don't give an accessmode, READ will
 be the default.
********************************************************************/
//  filetool::filetool(char *Filename, ACCESSMODE Fileaccessmode=READ)
  filetool::filetool(char *Filename, ACCESSMODE Fileaccessmode)
  {
	Init_Ptrs_to_NULL();
	fileaccessmode = Fileaccessmode;
	afileisopen = NO;
	setfilename(Filename);
	setaccessmode(Fileaccessmode);
  }

/********************************************************************
	FILETOOL CLASS DESTRUCTOR FUNCTION FILETOOL

********************************************************************/
  filetool::~filetool()      /// destructor
  {
    #ifndef USE_ANSI_FILE_IO
      fcloseall();
    #endif
   Free_Ptrs();
  }


/********************************************************************
	FILETOOL CLASS FUNCTION isBIGFILE
********************************************************************/
Boolean  filetool::isBIGFILE(void) /// is it a bigfile
  {
   if( filetool::filelength > maxfilebufsize)
	 return BOOL_TRUE;
   else
	 return BOOL_FALSE;
  }

/********************************************************************
	FILETOOL CLASS FUNCTION BIGFILEhandler
	handles variables on passes at bigfile
	returns a processing complete, BigFiledone as TRUE or FALSE
********************************************************************/
Boolean filetool::BIGFILEpasshandler(void)
{
   /// BIG FILE VARIABLES CHECK - CASE 1, not a bigfile
   if(!isBIGFILE())
     return (BOOL_FALSE); /// false means done

     readfrom_filebytes_pos += filetool::lastloadcount;
     remaining_filebytes -= filetool::lastloadcount;

   if(remaining_filebytes > 0)    ///BIG FILE
   {
     return(BOOL_TRUE);        /// true means more to do
   }
   else
     return(BOOL_FALSE);  /// false means done with bigfile
}

/*------------------------------------------------------------------
PRIVATE MEMBER FUNCTION BuildBooyerMooreDeltaTable
/// from the book C++ Components and Algorithms by Scott Robert Ladd
/// adapted for use here
-------------------------------------------------------------------*/
/// build boyer moore delta table from the pattern

void filetool::BuildBooyerMooreDeltaTable(char *pattern)
{
 Delta = new size_t [DeltaSize];

 if( Delta == 0)
   FatalError("BuildBooyerMooreDeltaTable()-Not enough memory to create Delta table", 100);

 size_t i, patlen = strlen(pattern);

 // get pattern length and store locally, we use it alot
 if( patlen < 1)    /// check value
   FatalError("BuildBooyerMooreDeltaTable()-  pattern length < 1", 101);

 for(i =0; i < DeltaSize; ++i)   Delta[i] = patlen;

 /// build the table values
 for (i = 1; i < patlen; ++i)   Delta[(size_t)pattern[i - 1]] = patlen - i;

 /// set value for the last pattern character
 Delta[(size_t)pattern[patlen - 1]] = 1;
}

/*------------------------------------------------------------------
PRIVATE MEMBER FUNCTION BooyerMooreFind
/// from the book C++ Components and Algorithms by Scott Robert Ladd
/// adapted for use here
-------------------------------------------------------------------*/
/// search the filebuffer from current position to end of buffer
/// for the pattern
Boolean filetool::BoyerMooreFind(char pattern[], char * &bufcur, size_t bufLen, char terminator)
{
 int patlen = strlen(pattern);   // get pattern length
 size_t curbufindex;

     #ifdef DEBUGON
     char *bufst = filetool::filebufferstart;
    // check lower and upper limits of critical variables
    if( bufLen < 1)   FatalError("BoyerMooreFind buffer Len < 1 ", 110);
    if(bufst > bufcur) FatalError("BoyerMooreFind bufstart > bufcur ", 111);
    if( bufLen > filetool::filelength)
	FatalError("BoyerMooreFind buffer Len > filelength ", 112);
    if( patlen < 1)    /// check value
	FatalError("BoyerMooreFind pattern length < 1 , check pattern!", 113);
    #endif DEBUGON

    curbufindex = patlen; // curbufindex is index to buf we're searching

    while ( (curbufindex <= bufLen) && (bufcur[curbufindex] != terminator) )
    {
	   size_t patindex=patlen;  // patindex is an index into pattern

	   /// while corresponding characters match
	   while (pattern[patindex - 1] == bufcur[curbufindex - 1])
	   {
	       if (patindex > 1)   // move left on char for next comparison
	       {                   // remember, we start at rightmost char
		 patindex--;       // of pattern and move LEFT instead of
		 curbufindex--;    // left to right as "brute force does"
	       }
	       else
	       {
		 // patindex = 1, we've reached the beginning of the pattern
		 // which means we've sucessfully compared all the pattern
		 // chars against the target. Match is found, we're done!
		 // Set current buffer to this location.
		 for(int adj=0; adj <(curbufindex-1); adj++) bufcur++;
		 return(BOOL_TRUE);
	       }
	   } //end inner while
	     // the two compared chars don't match so adjust the index.
	     // move target index by delta value of mismatched character
	     // and then continue on with the hunt.
	     curbufindex += Delta[bufcur[ curbufindex - 1]];

    }// end outer while
   return BOOL_FALSE;  // here we've reached end of buffer or the user
		       // specified terminator. So exit false and quit.

}

/********************************************************************
	FILETOOL CLASS PUBLIC MEMBER FUNCTION clearEOF
	clears the end of file flag - only used for ifstream and ofsteam
********************************************************************/
#ifndef USE_ANSI_FILE_IO
void filetool::clearEOF()         /// clear the EOF flag
{
/// call ifstream::clear and extract any garbage until end of file
  filetool::fileobject->clear();
  char nextChar;
  while( (nextChar = filetool::fileobject->get()) != '\n' && nextChar != EOF) { }
  filetool::fileobject->clear();

}
#endif
/********************************************************************
	FILETOOL CLASS PUBLIC MEMBER FUNCTION CLOSE
	closes the file
********************************************************************/
  void filetool::close(void)      /// closes a file
  {
   /// see #define USE_ANSI_FILE_IO at top of filetool.hpp
   #ifndef USE_ANSI_FILE_IO  /// use istream and ostream libraries
     filetool::fileobject->close();
   #else              /// use ANSI file i/o libraries
      fclose(fileobject);
   #endif

   afileisopen = NO;
  }

/********************************************************************
	FILETOOL CLASS PUBLIC MEMBER FUNCTION del_all_pat_plusn
	finds every occurance of pattern and deletes n characters
	from start of that pattern.  This function operates on
	the file. Use del_all_pat_plusn_Buf for operations exclusively
	on the buffer.
********************************************************************/
Boolean filetool::del_all_pat_plusn_File(char *pattern, size_t nextnchars, char terminator)
{
   Boolean result=BOOL_FALSE;
   /// for debugging

   open("testfile.dat", READ);      /// open the input file for reading.

	 /// open tempory output file for writing
	 #ifndef USE_ANSI_FILE_IO
	    fstream *fout;
	    fout= new fstream("testfile.out", fout->ios::out);
	    if(fout->ios::bad())
	    FatalError("Can't open file for write", 720);
	 #else
	    FILE *fout;
	    setWRfilename("testfile.out");
	    if((fout=fopen("testfile.out","wb")) == 0)
	    FatalError("Can't open file for read", 730);
	 #endif

	 do
	 {
	   readintobuf();      /// read data into buffer

	   if(del_all_pat_plusn_Buf(pattern, nextnchars, terminator))  result=BOOL_TRUE;

	   #ifdef DEBUGON
	   if(filebufferstart == 0) FatalError("del_all_pat_plusn_File - filebuffer = 0", 900);
	   #endif

	   #ifndef USE_ANSI_FILE_IO
	   fout.write(filebufferstart,getbufferlength());
	   #else
	   writeto_filebytes_bufendpos=getbufferlength();  /// for now
	   fwrite(filebufferstart, sizeof(char),writeto_filebytes_bufendpos, fout);
	   #endif

	   /// end of first pass, if its a bigfile, set the input file pos
	   /// back by the length of the pattern so we will be sure to find
	   /// occurances which are streached across the boundary.
	   /// THIS DID NOT WORK BECAUSE NOW THE WRITE POSITION GETS
	   /// messed up
///	   if(isBIGFILE())  readfrom_filebytes_pos -= strlen(pattern);


	 } while( BIGFILEpasshandler() );


   #ifndef USE_ANSI_FILE_IO  /// use istream and ostream libraries
      fout.close();
   #else              /// use ANSI file i/o libraries
      fclose(fout);
   #endif
     close();                    /// close the input file

		     /// BEFORE EXITING, WE NEED TO SOMEHOW TAKE THE OUTPUT
		     /// FILE WHICH WAS A TEMPORARY, AND SUBSTITUTE IT
		     /// for the input file. A quick crude but effective
		     /// way would be to let dos to do this stuff
   return(result);
}
/********************************************************************
	FILETOOL CLASS PUBLIC MEMBER FUNCTION del_all_pat_plusn
	finds every occurance of pattern and deletes n characters
	from start of that pattern.  This function only operates on
	the filebuffer. It DOES NOT operate on a file. Use
	del_all_pat_plusn_file for operations on files.
********************************************************************/
Boolean filetool::del_all_pat_plusn_Buf(char *pattern, size_t nextnchars, char terminator)
{
   Boolean result=BOOL_FALSE;

	  while(del_pat_plusn(pattern, nextnchars, terminator) == BOOL_TRUE)
	 {
		result = BOOL_TRUE;
	 }

   return(result);
}

/********************************************************************
	FILETOOL CLASS PUBLIC MEMBER FUNCTION del_pat_plusn
	beginning from the current cursor position, the next occurance
	of the given pattern is found and is deleted along with the
	next n characters in filebuffer. for example, the call:
	del_pat_plusn_curtoeof("randy", 5); would find the pattern
	randy in the file, would delete it along with the next 5
	characters following the pattern. The private variables
	filebufferstart and filebufferend will be altered as the
	function will reallocate a new filebuffer which is smaller
	by the number of characters deleted.

********************************************************************/
Boolean filetool::del_pat_plusn(char * pattern, size_t nextnchars, char terminator)
{
   size_t patlen;

   /// allocate some space for the pattern buffer and copy pattern into it
   if( (patlen = strlen(pattern) + 1) == 0)    /// get pattern length
   {
     FatalError("patternbuffer creation failed in del_pat",20);
   }

   char * patternbuffer = new char[(size_t)patlen];
   strcpy(patternbuffer,pattern);

   /// next find the pattern in the filebuffer - filebuffer points to it.
       if((FindPattern(patternbuffer, filebuffer, (size_t)filebufferlen, terminator))==BOOL_FALSE)
       {
	 delete [] patternbuffer;
	 gotobeg();
	 return(BOOL_FALSE); // if pattern not found, this is how we exit
       }
       else  /// found pattern so delete it
       {
	/// delete number of chars indicated.
///	#ifdef DEBUGON
///	   pos =getbufpos(filebufferstart,filebuffer);
///	   if( pos > filebufferlen)
///	   {
///	    cout << endl << "del_pat_plusn() filebufferlen:" << filebufferlen
///		 << " getbufpos: " << getbufpos(filetool::filebufferstart,filetool::filebuffer);
///	    FatalError("del_pat_plusn getpos > filebufferlen", 21);
///	   }
///	#endif
	Delete(filebufferstart,filebuffer, filebufferlen , nextnchars);
	#ifdef DEBUGON
	   cout << endl << " ** del_pat_plusn() deleted pattern \"" << patternbuffer << "\" from buffer, "
		<< " Pos: " << getfilepos();
	#endif
       }
       delete [] patternbuffer;
       return(BOOL_TRUE);

}

/********************************************************************
	FILETOOL CLASS PUBLIC MEMBER FUNCTION DELETE

	substring deletion at current buffer position
	buffer is pointer to buffer to delete from,
	pos is the index of first character to be deleted and
	count is the number of characters to delete
********************************************************************/
void filetool::Delete(char * &bufstart, char * &bufcur,
		      size_t &buflen, size_t delcount)
{
    size_t delpos;
    delpos = filetool::getbufpos(filetool::filebufferstart,filetool::filebuffer);

    if(delcount == 0) return; /// nothing to delete so exit

    if ( (bufstart == 0) || (bufcur == 0) || (buflen == 0))
      FatalError("filetool::Delete- bufstart, bufcur or buflen was NULL",10);

    size_t newbufLen, oldbufindex ;

    #ifdef DEBUGON
//    if( delpos > buflen )
//    {
//      cout << "delpos: " << delpos;
//      FatalError("filetool::Delete - delpos out of range",11);
//    }
    // error if deleting outside of original filesize - program must have a bug!
    if ((delpos + delcount - 1) > filetool::filelength)
    {
      cout << "delcount: " << delcount;
      FatalError("filetool::Delete - numof chars to delete > buflen",12);
    }
    #endif

    // length of new buffer after deletion
    newbufLen = getbufferlength() - delcount;

	// create new buffer
	char * newbuf = new char[newbufLen + 3];
	if (newbuf == 0)    FatalError("Delete - newbuf allocation error",13);

	char * newbuf_ptr = newbuf;

	// copy chars from old buf to new buff, skipping over pattern to be deleted.
	for (oldbufindex = 0; oldbufindex < newbufLen + delcount; oldbufindex++)
	    {
	      // when count is reached, skip deleted characters
	      if (oldbufindex == delpos)
	      {
		oldbufindex += delcount;
		bufcur = newbuf_ptr;
	      }
	      *newbuf_ptr = filebufferstart[oldbufindex];
	      newbuf_ptr++;
	    }
	    newbuf[newbufLen] = 0;  /// terminate buffer with null

	// delete old filebuffer buffer, newbuf contains the new stuff
	delete [] bufstart;

	// assign new buffer
	buflen =  newbufLen;  // should set filetool::filebufferlen
	bufstart= &newbuf[0];     ///bufstart should be same as filebufferstart
    }


/********************************************************************
	FILETOOL CLASS PUBLIC MEMBER FUNCTION DISPLAY
	displays the file contents to the screen
********************************************************************/
  void filetool::dumpfile(void)   /// displays it
  {
    char data;

    #ifndef USE_ANSI_FILE_IO
      fileobject->seekg(0);         /// back to beginning of file
      fileobject->clear();          /// clear stream state
      while( fileobject->get(data) != 0 )   cout << data;
    #else
      rewind(fileobject);            /// goto beginning
      while( (data=fgetc(fileobject)) != EOF )   cout << data;
    #endif

  }

/********************************************************************
	FILETOOL CLASS PUBLIC MEMBER FUNCTION dumpbuffer
	dumps the file contents to the screen
********************************************************************/
void filetool::dumpbuffer()
{
  int count = 1;
  cout << endl << "buffer contents: " << endl;

  for(int x=0; x < filetool::filebufferlen; x++,count++)
  {
   printf("%02X%c",filebufferstart[x],' ');
   if(count == 16) cout << endl;

  }
  exit(1);
}

/*------------------------------------------------------------------
PRIVATE MEMBER FUNCTION  Free_Ptrs
-------------------------------------------------------------------*/
void filetool::Free_Ptrs(void)
{
   if(filebufferstart != 0)
   {
    delete [] filebufferstart;
    filebufferstart = 0;
   }


}
/*------------------------------------------------------------------
PRIVATE MEMBER FUNCTION FatalError
-------------------------------------------------------------------*/
void filetool::FatalError(char * message, int number)
{
  cerr << endl << "Fatal Error  " << number << ": " << message
       << " ABORTING!" << endl;
  Free_Ptrs();
  exit(1);
}

/********************************************************************
	FILETOOL CLASS PUBLIC MEMBER FUNCTION FillBuffer

********************************************************************/
void filetool::FillBuffer(char array[], int data, int beg, int end)
{
  for(int x=beg; x <=end; x++) array[x] = data;
}

/********************************************************************
	FILETOOL CLASS PUBLIC MEMBER FUNCTION FindPattern
	displays the file contents to the screen
********************************************************************/
   Boolean filetool::FindPattern(char pattern[], char * &bufcur, size_t bufLen, char terminator)
   {
     Boolean result = BOOL_TRUE;

     // check to see if pattern size bigger than file or if it's zero
     if( (strlen(pattern) == 0) || (strlen(pattern) > filetool::filelength))
     return(BOOL_FALSE);


     /// check to see if we are at the end of buffer
     if( (getbufpos(filetool::filebufferstart,filetool::filebuffer) + strlen(pattern)) >=  getbufferlength() )
     {
       #ifdef DEBUGON
	     cout << endl
		  << "FindPattern() end of buffer reached, bufpos:"
		  << getbufpos(filetool::filebufferstart,filetool::filebuffer) << "  Patlen:" << strlen(pattern);
       #endif
       return(BOOL_FALSE);
     }

     #ifdef DEBUGON
     if(bufcur == 0) FatalError("FindPattern buffer pntr passed in is NULL", 30);
     if(bufLen == 0) FatalError("FindPattern buffer Len passed in is NULL", 31);
     #endif

     BuildBooyerMooreDeltaTable(pattern);  /// build Delta table

	if(!BoyerMooreFind(pattern, bufcur, bufLen, terminator) )  /// if pattern not found
	{
	  result = BOOL_FALSE;  /// pattern not found so set result to fals	  buffer=tempbuffer;  ///restore original filepointer
	}

     if(Delta != 0)
     {
	delete [] Delta;  /// free up BoyerMoore delta table
	Delta = 0;        /// set it to NULL for good practice.
     }
     else
     {
	cerr << endl << "Warning: Delta table pointer should not be zero";
	cerr << "Check how you're using the member functions?" << endl;
     }
     return(result);
   }

/********************************************************************
	FILETOOL CLASS PUBLIC MEMBER FUNCTION SearchReplace
	Searches for a searchstring and replaces first occurance
        with the replacement string
********************************************************************/
Boolean filetool::SearchReplace(char searchstr[], char replacestr[],
                                char * &bufcur, size_t bufLen, char terminator)
{
     Boolean result = BOOL_TRUE;

}
/********************************************************************
	FILETOOL CLASS PUBLIC MEMBER FUNCTION GETBUFPOS
	returns file position
********************************************************************/
size_t filetool::getbufpos(char *bufstart, char *bufcur)   /// get position
{
  char * temp_pntr;
  temp_pntr=bufstart;
  size_t pos=0;
  if(bufstart==bufcur) return 0;
  if(bufstart > bufcur) FatalError("getbufpos() filebufferstart > filebuffer ", 60);
  if(bufcur==0)      FatalError("getbufpos() filebuffer is NULL", 61);
  if(bufstart==0) FatalError("getbufpos() filebufferstart is NULL", 62);
  while(temp_pntr < bufcur)
  {
    temp_pntr++;
    pos++;
  }
  return(pos);
}

/*------------------------------------------------------------------
	FILETOOL CLASS PUBLIC MEMBER FUNCTION getbufferlength
-------------------------------------------------------------------*/
size_t filetool::getbufferlength()
{
  return(filetool::filebufferlen);
}

/********************************************************************
	FILETOOL CLASS PUBLIC MEMBER FUNCTION getnextbufsize

********************************************************************/
size_t filetool::getnextbufsize(void)
{
    /// if file not too big for our available memory, allocate it all
    if(!isBIGFILE()) return(filetool::filelength);

    else   /// it's a BIGFILE
    {
     if(filetool::remaining_filebytes > maxfilebufsize) // more to do
     return(maxfilebufsize);                 // use max allowable memory

     else

     // last pass, only allocate what we need
     return(remaining_filebytes);

    }
}

/********************************************************************
	FILETOOL CLASS PUBLIC MEMBER FUNCTION getfilelength
	returns length of the file - alters the filepointer
********************************************************************/
  size_t filetool::getfilelength(void) /// get length of the file
  {
    size_t len=0, curpos;
    char ch;
    if(afileisopen !=YES)  FatalError("no files are open - getfilelength invalid", 40);

    #ifndef USE_ANSI_FILE_IO
       curpos=(size_t)fileobject->tellg();
       fileobject->clear();                     /// clear any errors or EOF
//       fileobject->seekg(0,ios::end);         /// goto end of file
//       len=(size_t)fileobject->tellg();       /// write length
	  do
	  {
	    fileobject->get(ch);        /// this does not work because
	     if( ch != EOF)             /// for some reason, it ignores
	     {                          /// 0D and 0A, which I must count.
	     len++;                     /// thus the length count is wrong.
	     }
	  }while(ch != EOF);

       fileobject->clear();                   /// clear any errors or EOF
       fileobject->seekg(curpos);             /// back to orig. position
       cout << endl << "fstream len is: " << len;
    #else
       curpos=(size_t)ftell(fileobject);      /// save current position
       rewind(fileobject);

	  do
	  {
	    ch = fgetc(fileobject);  /// reads every character inc 0D and 0A
	    if(ch != EOF) len++;
	  }while(ch != EOF);
       fseek(fileobject,curpos,SEEK_SET);     /// return to original position
    #endif
    filetool::filelength=len;  /// set the length variable
    return(len);
  }

/********************************************************************
	FILETOOL CLASS PUBLIC MEMBER FUNCTION GETFILE
	returns file position
********************************************************************/
size_t filetool::getfilepos(void)   /// get position
{
  long curpos;

  #ifndef USE_ANSI_FILE_IO
       curpos=(size_t)fileobject->tellg();
  #else
       curpos=(size_t)ftell(fileobject);
       if(curpos == -1)  FatalError("Error in getpos, returned -1", 50);
  #endif

  return((size_t)curpos);

}
/********************************************************************
	FILETOOL CLASS PUBLIC MEMBER FUNCTION getnextfilepos
	returns the next fileposition to be read or written to
********************************************************************/
size_t filetool::getnextfilepos(void)
{
    return(readfrom_filebytes_pos);
}


/********************************************************************
	FILETOOL CLASS PUBLIC MEMBER FUNCTION GOTOBEG
	goto beginning of file
********************************************************************/
void filetool::gotobeg(void)      /// goto beginning of file
{
  #ifndef USE_ANSI_FILE_IO
    fileobject->clear();
    fileobject->seekg(0);
  #else
    rewind(fileobject);  /// goto beginning
  #endif
}

/********************************************************************
	FILETOOL CLASS PUBLIC MEMBER FUNCTION gotobufpos
	bufstart = start of the buffer  (filebufferstart)
	newpos = new position to set current buffer pointer to
	buflen = length of buffer, used for error checking only
	RETURNS: new current buffer pointer (filebuffer)
********************************************************************/
/// set position of filebuffer pointer
char * filetool::gotobufpos(char *bufst, size_t newpos, size_t buflen)
{
   char *bufcu;
   bufcu = bufst;
   if(newpos > buflen) FatalError("FILETOOL::read- filelength <= 0", 89);

   for(int x=0; x < newpos; x++)
   bufcu++;
   return(bufcu);
}
/********************************************************************
	FILETOOL CLASS PUBLIC MEMBER FUNCTION gotofilepos
	goto indicated position in file, first position is zero
********************************************************************/
void filetool::gotofilepos(size_t pos)   /// set position in file
{
    #ifndef USE_ANSI_FILE_IO
       fileobject->seekg(pos);
    #else
       rewind(fileobject);
       fseek(fileobject,pos,SEEK_SET);
    #endif

}

/*------------------------------------------------------------------
PRIVATE MEMBER FUNCTION  Init_Ptrs_to_NULL
-------------------------------------------------------------------*/
void filetool::Init_Ptrs_to_NULL(void)
{
	remaining_filebytes=0;
	readfrom_filebytes_pos=0;  /// unprocessed file bytes
	filelength=0;       /// filelength
	filebufferlen=0;    /// length of file buffer
	filebuffer=0;       /// buffer pointer (current location)
	fileobject=0;       /// pointer to fileobject
	filebufferstart=0;  /// start of filebuffer
	filebufferend=0;    /// start of filebuffer
	Delta=0;            /// pointer to BoyerMoore delta table
	filename=0;         /// filename pointer 2nd constructor
	WRfilename=0;       /// write filename

}

/********************************************************************
	FILETOOL CLASS PUBLIC MEMBER FUNCTION insert
********************************************************************/
// substring insertion methods
void filetool::Insert(char * &bufstart, size_t pos, char ch)
    {
      UnderConstruction("Insert(char *buffer, size_t pos, char ch)");
      return; /// this will cause "unreachable code" warning, ignore for now

    if (pos > filebufferlen)    cerr << "invalid ins. len";
///	ErrorHandler(SE_INVALID);

    if (bufstart == 0)
	{

	bufstart = new char [2];

	if (bufstart == 0)   cerr << "insert allocation failure";
///	    String::ErrorHandler(SE_ALLOC);

	bufstart[0] = ch;
	bufstart[1] = '\000';
	}
    else
	{
	size_t newLen = (size_t)filebufferlen + 1;
	size_t i;


	    // create temporary buffer
	    char * temp = new char[newLen];
	    char * newbuf_ptr = temp;

	    if (temp == 0)             cerr << "insert allocation err";
///		ErrorHandler(SE_ALLOC);

	    // copy in old buffer, inserting ch when needed
	    for (i = 0; i <= filebufferlen; ++i)
		{
		if (i == pos)
		    {
		    *newbuf_ptr = ch;
		    ++newbuf_ptr;
		    }

		*newbuf_ptr = bufstart[i];
		++newbuf_ptr;
		}

	    // delete old buffer
	    delete [] bufstart;

	    // assign new buffer and length
	    bufstart = temp;
	    filebufferlen = newLen;

	    // slide characters right
	    for (i = newLen; i > pos; --i)
		bufstart[i] = bufstart[i-1];

	    // insert character
	    bufstart[pos] = ch;

	    // adjust length
	    filebufferlen = newLen;
	}
    }

/********************************************************************
	FILETOOL CLASS PUBLIC MEMBER FUNCTION insert
/// from the book C++ Components and Algorithms by Scott Robert Ladd
/// adapted for use here
********************************************************************/
void filetool::Insert(char * &bufstart, size_t pos, char *string)
    {

    UnderConstruction("Insert(char *buffer, size_t pos, char *string)");
    return; /// this will cause "unreachable code" warning, ignore for now

    if (string == 0)
	return;

    if (pos > filebufferlen)      cerr << "Insert string invalid pos";
///	ErrorHandler(SE_INVALID);

    if (bufstart == 0)
	{
	cerr << "Err attempting to insert string into empty filebuffer";
	// empty string = str
///	*this = bufstart;
	}
    else
	{
	// calculate new length
	size_t strlength = strlen(string);
	unsigned long totalLen = strlength + filebufferlen;

///	if (totalLen > UINT_MAX)      cerr << "Insert string err - string too long";
///	    ErrorHandler(SE_TOO_LONG);

	size_t i, j;

	// if new  length > current size
	if (totalLen > filebufferlen)
	    {
	    // allocate new buffer
	    filebufferlen = (size_t)totalLen;

	    char * temp = new char [(size_t)filebufferlen];
	    char * newbuf_ptr = temp;

	    // copy buffers from source strings
	    for (i = 0; i <= filebufferlen; ++i)
		{
		if (i == pos)
		    {
		    for (j = 0; j < strlength; ++j)
			{
			*newbuf_ptr = string[j];
			++newbuf_ptr;
			}
		    }

		*newbuf_ptr = bufstart[i];
		++newbuf_ptr;
		}

	    // delete old buffer
	    delete [] bufstart;

	    // assign new buffer
	    bufstart = temp;
	    }
	else
	    {
	    // slide section old buffer to right
	    for (i = (size_t)filebufferlen + strlength; i > pos + strlength; --i)
		bufstart[i] = bufstart[i - strlength];

	    // insert new string
	    for (i = 0; i < strlength; ++i)
		bufstart[pos + i] = string[i];
	    }

	filebufferlen = (size_t)totalLen;
	}
    }

/********************************************************************
	FILETOOL CLASS PUBLIC MEMBER FUNCTION SKIP
		skip past n characters
********************************************************************/
   /// see #define USE_ANSI_FILE_IO at top of filetool.hpp
   /// add some checking later to insure n will not move us outside of file
   /// and check the return values of the I/O functions.

 void filetool::movepos(size_t n)   /// move filebuffer position + or - n
 {
   if(n==0) return;   /// just do nothing.
   #ifndef USE_ANSI_FILE_IO  /// use istream and ostream libraries

      if(n > 0)
	  fileobject->ignore(n,'\n');
      else // n < 0
	fileobject->seekg(-n,ios::cur);

   #else              /// use ANSI file i/o libraries
      long pos=ftell(fileobject);
      if(n > 0)  pos +=n;
      else       pos -=n;
       rewind(fileobject);
       fseek(fileobject,n,SEEK_SET);
       pos=ftell(fileobject);
       rewind(fileobject);
       fseek(fileobject,pos,SEEK_SET);
   #endif


 }


/********************************************************************
	FILETOOL CLASS PUBLIC MEMBER FUNCTION OPEN
	opens the file
// create another overloaded version of open which accepts no parameters
// but rather uses the fname and fileaccessmodes set by the constructor
// which takes parameters. Make this change in V1.05
****************************************************************************/
  void filetool::open(char * fname, ACCESSMODE Fileaccessmode)
  {
     switch (Fileaccessmode)
     {
       case READ:
	 #ifndef USE_ANSI_FILE_IO
	    fileobject = new fstream(fname, fileobject->ios::in);
	    if(fileobject->ios::bad())
	    FatalError("Can't open file for read", 70);
	 #else
	    if((fileobject=fopen(fname,"rb")) == 0)
	    FatalError("Can't open file for read", 71);
	 #endif
       break;

       case WRITE:
	 #ifndef USE_ANSI_FILE_IO
	    fileobject = new fstream(fname, fileobject->ios::out);
	    if(fileobject->ios::bad())
	    FatalError("Can't open file for write", 72);
	 #else
	    if((fileobject=fopen(fname,"wb")) == 0)
	    FatalError("Can't open file for write", 73);
	 #endif
       break;

       case READWRITE:
	 #ifndef USE_ANSI_FILE_IO
	  fileobject = new fstream(fname, fileobject->ios::in | fileobject->ios::out);
	  if(!fileobject)
	      FatalError("Can't open file for read/write", 74);
	 #else
	    if((fileobject=fopen(fname,"w+")) == 0)
	    FatalError("Can't open file for read", 75);
	 #endif
       break;

       default:
	  cerr << "bad filemode parameter in accessmode flag";
     }
    filetool::afileisopen = YES;

    filetool::gotobeg();                  /// goto beginning of file

    /// get the length of the file and save it
    filelength=filetool::getfilelength();     /// write length

    ///BIGFILE CALACULATIONS
       remaining_filebytes=filelength;   /// readtobuf uses this
       readfrom_filebytes_pos=0;     /// readtobuf uses this
       filetool::lastloadcount=0;
  }

void filetool::open()
{
  if(afileisopen == NO)
  open(filetool::filename, filetool::fileaccessmode);
}

/********************************************************************
	FILETOOL CLASS PUBLIC MEMBER FUNCTION READ
	create a buffer big enough to hold file, read the file into
	the buffer and return the pointer to the user.
	In V1.05, modify this so it opens a file if not already open
	but parameters were specified by constructor. Also create an
	overloaded readintobuf which takes a filename as parameter.
********************************************************************/
void filetool::readintobuf(void)    /// read file into buffer and return pointer
{
   size_t rdfilepos=getfilepos();                       /// for debug
   size_t bufpos=getbufpos(filebufferstart,filebuffer); /// for debug

  size_t thisloadsize=getnextbufsize();
  size_t thisfilepos= getnextfilepos();

   if(getfilelength() <= 0) FatalError("FILETOOL::Read- Filelength <= 0", 80);
   if(!afileisopen) FatalError("FILETOOL::Read- no files open!", 81);

   if(filebufferstart != 0)
   {
    delete [] filebufferstart;
    filebufferstart = 0;
   }

   if(thisloadsize==0) /// no more to do
   {
       return;
   }
   /// allocate some memory to the filebuffer
   if((filebufferstart= new char[(size_t)(thisloadsize + 1) * sizeof(char)])==0)
   {
    FatalError("FILETOOL::Read- Insufficient memory for Filebufferstart ", 82);
   }
   else
   {
    gotofilepos(thisfilepos);
    filebuffer=filebufferstart;             /// filebuffer is current pointer
    filebufferlen=thisloadsize;    /// set file buffer length

   rdfilepos=getfilepos();                       /// for debug
   bufpos=getbufpos(filebufferstart,filebuffer); /// for debug

    /// fill buffer with nulls
    FillBuffer(filebufferstart, 0, 0, filelength+1);
    filebufferstart[getnextbufsize()] = 0;  /// terminate end of buf with 0

    #ifndef USE_ANSI_FILE_IO
       fileobject->read(filebuffer,thisloadsize);
    #else
      fread(filebuffer, sizeof(char), thisloadsize, fileobject);
    #endif
   }
   filetool::lastloadcount=thisloadsize;
   filetool::writeto_filebytes_bufendpos=thisloadsize;
}
/********************************************************************
	FILETOOL CLASS PUBLIC MEMBER FUNCTION setaccessmode
		sets file access mode
********************************************************************/
void filetool::setaccessmode(ACCESSMODE file_access)
{
 filetool::fileaccessmode = file_access;
}

/********************************************************************
	FILETOOL CLASS PUBLIC MEMBER FUNCTION setWRfilename

********************************************************************/
void filetool::setfilename(char *fname)
{
  filetool::filename = new char[strlen(fname)];
  if(filename == 0)
    FatalError("setfilename() new returned null", 1200);
  else
    strcpy(filename,fname);
    filename[strlen(fname)] = 0; /// terminate with null
}

/********************************************************************
	FILETOOL CLASS PUBLIC MEMBER FUNCTION setWRfilename

********************************************************************/
void filetool::setWRfilename(char *fname)
{
  filetool::WRfilename = new char[strlen(fname)];
  if(WRfilename == 0)
    FatalError("setWRfilename() new returned null", 1200);
  else
    strcpy(WRfilename,fname);
    WRfilename[strlen(fname)] = 0; /// terminate with null
}


/*------------------------------------------------------------------
PRIVATE MEMBER FUNCTION UnderConstruction
-------------------------------------------------------------------*/
void filetool::UnderConstruction(char * message)
{
  cerr << endl << " ** Sorry, " << message
       << " under construction **" << endl;
}


/********************************************************************
	FILETOOL CLASS PUBLIC MEMBER FUNCTION VERSION
		Displays name of this file "FILETOOL.CPP",
		Displays version control number (in filetool.hpp)
		Displays time and date of last compile
		Useful in identifing what you've got.
__FILE__ __DATE__ __TIME are generated by Borland C++
********************************************************************/
void filetool::Version(void)
{
 float ver = Ver_num;   /// Version is a #define in filetool.hpp
			/// I bump it up each time I mod the .cpp or .hpp
			/// file. It represents the revision of the whole
			/// package
 cout << endl << " ** File: " __FILE__ << " V" << ver
      << "  Compiled: " << __DATE__ << " at " << __TIME__ << " **";
}


/********************************************************************
	FILETOOL CLASS PUBLIC MEMBER FUNCTION writetofile
	In V1.05, make an overloaded writetofile which accepts a
	filename as parameter. It will open that filename if not already
	open.
********************************************************************/
void filetool::writetofile(void)    /// writes buffer back to file
{

  if(filebufferstart == 0) FatalError("writetofile - filebuffer = NULL", 90);

#ifndef USE_ANSI_FILE_IO
  fileobject->write(filebufferstart,getbufferlength());
#else
  #ifdef DEBUGON
     cout << endl << "writetofile() writing " << filebufferlen  << "  bytes";
  #endif
//  fwrite(filebufferstart, sizeof(char), getbufferlength(), fileobject);
  fwrite(filebufferstart, sizeof(char), writeto_filebytes_bufendpos, fileobject);

#endif
}



/*------------------------------------------------------------------
PRIVATE MEMBER FUNCTION WarningError
-------------------------------------------------------------------*/
void filetool::WarningError(char * message, int number)
{
  cerr << endl << "Warning  " << number << ": " << message << endl;
}

/********************************************************************
	FILETOOL DEMO PROGRAM
	shows how to use some of the member functions
********************************************************************/
#ifdef TESTfiletool

int main()
{
     system("cls");
     cout << endl << " *****************************************************************" ;
     cout << endl << " ** FILETOOL class test cases , Randy Miner 1996 **";
     filetool myfile;  /// filetool class object
     myfile.Version();

//     myfile.open("testfile.dat", READ);      /// open the file for reading.
//     myfile.readintobuf();            /// read into buffer
//     cout << endl << endl << " File contents before delete:" << endl << endl;
//     myfile.dumpfile();
//     cout << endl;
//     myfile.close();

     myfile.del_all_pat_plusn_File("unto",4,EOF);

//     myfile.open("testfile.out",WRITE); /// open the output file
//     myfile.writetofile();              /// write the changes from buffer
     cout << endl << endl << "done!";

return 1;

}

#endif