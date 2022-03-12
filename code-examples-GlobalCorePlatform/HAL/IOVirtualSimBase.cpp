// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::TestSupportWin32::IOVirtualSimBase'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "IOVirtualSimBase.h"
#endif

#include <HALtestLib_win32.h>
#include <IOVirtualSimBase.h>
#include <Array.h>
#include <SCharArray.h>
#include <SIntArray.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
using namespace std;



// }}}USR
// }}}RME

// {{{RME classAttribute 'm_outputBase'
int IOVirtualSimBase::m_outputBase( OUTPUT_MODE_HEX );
// }}}RME

// {{{RME classAttribute 'OUTPUT_MODE_DEFAULT'
const unsigned int IOVirtualSimBase::OUTPUT_MODE_DEFAULT( 2 );
// }}}RME

// {{{RME classAttribute 'OUTPUT_MODE_HEX'
const unsigned int IOVirtualSimBase::OUTPUT_MODE_HEX( 3 );
// }}}RME

// {{{RME classAttribute 'OUTPUT_MODE_BIN'
const unsigned int IOVirtualSimBase::OUTPUT_MODE_BIN( 0 );
// }}}RME

// {{{RME operation 'getch()'
char IOVirtualSimBase::getch( void )
{
	// {{{USR

	char c;

	std::cin >> c;

	return c;


	//Once a file is opened, it may be used exactly as std::cin is used.
	//std::ifstream someVarName("data.txt");
	//float fl;
	//char temp[100];
	//someVarName.getline(temp, 100);
	//fl=strtof(temp);
	//int i;
	//someVarName >> i;

	//Getline can be told to stop grabbing input at any designated character
	//char temp[100];
	//std::cin.getline(temp, 100, '|')

	//How to set the width of a printing field
	//Given: int one=4, two=44; 
	  //std::cout << one << std::endl.; 
	  //output:  "4"

	  //std::cout << setw(2) << one << std::endl.;
	  //output:  " 4"

	  //std::cout.fill('X');
	  //std::cout << setw(2) << one << std::endl.;
	  //output:  "X4"

	  //std::cout.fill('X');
	  //std::cout << setw(2) << two << std::endl.;
	  //output:  "44"


	// }}}USR
}
// }}}RME

// {{{RME operation 'send(char)'
void IOVirtualSimBase::send( char characterToSend )
{
	// {{{USR

	if( getOutputBase() == IOVirtualSimBase::OUTPUT_MODE_HEX )
	{
	     
	      std::cout << std::setw(2) << std::setfill('0') << std::hex << (((unsigned short int)characterToSend) & 0x00FF);
	  
	}

	else if( getOutputBase() == IOVirtualSimBase::OUTPUT_MODE_DEFAULT )
	{
	   std::cout << characterToSend;
	}

	else if( getOutputBase() == IOVirtualSimBase::OUTPUT_MODE_BIN )
	{
	   binaryPrint8(characterToSend);
	}
	// }}}USR
}
// }}}RME

// {{{RME operation 'send(char *)'
void IOVirtualSimBase::send( char * string )
{
	// {{{USR
	char c;

	setOutputBase(OUTPUT_MODE_DEFAULT);

	while( (c = (char)*string++) != 0 )
	{
	   IOVirtualSimBase::send( c );
	}
	// }}}USR
}
// }}}RME

// {{{RME operation 'send(int16_t)'
void IOVirtualSimBase::send( int16_t data )
{
	// {{{USR

	int16_t temp = data;

	char * byteptr = (char *)&temp;

	setOutputBase(OUTPUT_MODE_HEX);

	for(int i = 0; i < 2; i++)
	{
	   IOVirtualSimBase::send( *byteptr );
	   byteptr++;
	}


	// }}}USR
}
// }}}RME

// {{{RME operation 'sendFLUSH()'
void IOVirtualSimBase::sendFLUSH( void )
{
	// {{{USR

	std::cout << std::flush;
	// }}}USR
}
// }}}RME

// {{{RME operation 'sendENDL()'
void IOVirtualSimBase::sendENDL( void )
{
	// {{{USR

	std::cout << std::endl;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getOutputBase()'
unsigned int IOVirtualSimBase::getOutputBase( void )
{
	// {{{USR

	return m_outputBase;
	// }}}USR
}
// }}}RME

// {{{RME operation 'LogFileOpen(char *)'
int IOVirtualSimBase::LogFileOpen( char * filename )
{
	// {{{USR
		int retval = -1;

#ifdef _WIN32

	    // m_logfile_ptr is declared in the implementation preface and is
	    // conditionalized around #ifdef _WIN32

	    //m_logfile_ptr = fopen(filename, "wt");

		//if(m_logfile_ptr != NULL) 
		//{ 
		//	retval = 1;
	    //    m_isLogFileOpen = true; 
		//}

#endif

		return retval;
	// }}}USR
}
// }}}RME

// {{{RME operation 'LogFileClose()'
void IOVirtualSimBase::LogFileClose( void )
{
	// {{{USR
		

#ifdef _WIN32

	//   fclose(m_logfile_ptr);

#endif


	// }}}USR
}
// }}}RME

// {{{RME operation 'IOVirtualSimBase()'
IOVirtualSimBase::IOVirtualSimBase( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	:m_isLogFileOpen( false )
	// }}}USR
	// }}}RME
{
	// {{{USR

	// set base default to hexidecimal

	setOutputBase(IOVirtualSimBase::OUTPUT_MODE_DEFAULT);


	// }}}USR
}
// }}}RME

// {{{RME operation 'setOutputBase(int)'
void IOVirtualSimBase::setOutputBase( int base )
{
	// {{{USR

	m_outputBase = base;
	// }}}USR
}
// }}}RME

// {{{RME operation 'send(Array *)'
bool IOVirtualSimBase::send( Array * buffer )
{
	// {{{USR
	int16_t temp0 = 0;
	int16_t temp1 = 0;

	if (buffer->isType(SCharArray::SIGNED_CHAR_ARRAY))
	{
	   // We got a data buffer.  Handle it.
	   SCharArray * db = (SCharArray*)buffer;

	   setOutputBase(OUTPUT_MODE_DEFAULT);
	   
	   for(int i = 0; i < db->getLength(); i++)
	   {
	     IOVirtualSimBase::send( (*db)[i] );
	   }

	   // We sent the data.  Consume the DataBuffer that was given to us.
	   delete buffer;

	}
	else if (buffer->isType(SIntArray::SIGNED_INT_ARRAY))
	{
	   // We got a data buffer.  Handle it.
	   SIntArray * db = (SIntArray*)buffer;

	  if( getOutputBase() == IOVirtualSimBase::OUTPUT_MODE_BIN)
	   {
	          
	     if( db->getLength() == 1) // single 16 bit value for display
	     {

	         binaryPrint16( (*db)[0] );        

	     }
	     else if( db->getLength() == 2 ) // two 16 bit integers
	     {

	       uint32_t temp = 0;
	       int16_t * temp_ptr = (int16_t *)&temp;

	       *temp_ptr =  (*db)[0];

	        temp_ptr++;

	       *temp_ptr =  (*db)[1];

	       binaryPrint32(temp);       
	     }
	   
	   }
	   else // not a binary display
	   {
	     // print numbers in hex
	     IOVirtualSimBase::setOutputBase(IOVirtualSimBase::OUTPUT_MODE_HEX);

	     if( db->getLength() == 1) // single 16 bit value for display
	     {

	// actually, IOVirtualSimBase should ONLY be used in a windows build
	// for arm9, we'd be using the uart driver for console output. For arm9,
	// the targetConfigBase class will do the Endian=ness swapping

	       temp0 = (*db)[0];

#ifdef _WIN32

	       temp0 = EndianSwap_int16( temp0 );
#endif
	       IOVirtualSimBase::send( temp0 );
	     }
	     else if( db->getLength() == 2) // 32 bit value for display
	     {
	       temp0 = (*db)[0];
	       temp1 = (*db)[1];

#ifdef _WIN32
	       int16_t tmp;

	       temp0 =  EndianSwap_int16( temp0 );
	       temp1 =  EndianSwap_int16( temp1 );
	       tmp = temp0;
	       temp0 = temp1;
	       temp1 = tmp;

#endif
	       IOVirtualSimBase::send( temp0 );
	       IOVirtualSimBase::send( temp1 );
	     }
	     else // length greater than 2
	     {
	   		for(int k = 0; k < db->getLength(); k++)
	     	{
	            temp0 = (*db)[k];
#ifdef _WIN32
	            temp0 = EndianSwap_int16( temp0 );      		
#endif
	            IOVirtualSimBase::send( temp0 );
	     	}
	     }

	  
	   }

	   // We sent the data.  Consume the DataBuffer that was given to us.
	   delete buffer;


	}


	return true;
	// }}}USR
}
// }}}RME

// {{{RME operation 'binaryPrint8(char)'
void IOVirtualSimBase::binaryPrint8( char dvalue )
{
	// {{{USR
		unsigned char mask;

		send("D7<");


	        mask = 0x80;

			for(int j = 7; j >= 0; j--)
			{

			   if( (dvalue & mask) == mask )
			   {
			     send("1");
			   }
			   else
			   {
	             send("0");
			   }

			   mask = mask >> 1; // move to next bit

			   if( j == 4 ) 
			   {
	              send(" ");
			   }


			}

	    send(">D0\n\r");	
	// }}}USR
}
// }}}RME

// {{{RME operation 'binaryPrint32(uint32_t)'
void IOVirtualSimBase::binaryPrint32( uint32_t dvalue )
{
	// {{{USR
		uint32_t value = dvalue;

		unsigned char * byte_ptr;
		unsigned char mask;

		byte_ptr = (unsigned char *)&value;

		send("D31<");

		for(int i = 4; i > 0; i--)
		{
	        mask = 0x80;

			for(int j = 7; j >= 0; j--)
			{

			   if( (*byte_ptr & mask) == mask )
			   {
			     send("1");
			   }
			   else
			   {
	             send("0");
			   }

			   mask = mask >> 1; // move to next bit

			   if( (j == 4 || j == 0) && i != 0) 
			   {
	              send(" ");
			   }
			}

			byte_ptr++;

		}

	    send(">D0\n\r");
	// }}}USR
}
// }}}RME

// {{{RME operation 'binaryPrint16(uint16_t)'
void IOVirtualSimBase::binaryPrint16( uint16_t dvalue )
{
	// {{{USR
		unsigned char * byte_ptr;
		unsigned char mask;

		uint16_t value = dvalue;

		byte_ptr = (unsigned char *)&value;

		send("D15<");

		for(int i = 2; i > 0; i--)
		{
	        mask = 0x80;

			for(int j = 7; j >= 0; j--)
			{

			   if( (*byte_ptr & mask) == mask )
			   {
			     send("1");
			   }
			   else
			   {
	             send("0");
			   }

			   mask = mask >> 1; // move to next bit

			   if( (j == 2 || j == 0) && i != 0) 
			   {
	              send(" ");
			   }
			}

			byte_ptr++;

		}

	    send(">D0\n\r");	
	// }}}USR
}
// }}}RME

// {{{RME operation 'send(unsigned int)'
void IOVirtualSimBase::send( unsigned int data )
{
	// {{{USR

	// unsigned ints are 32bits wide on windows

	int32_t temp = data;

	char * byteptr = (char *)&temp;

	setOutputBase(OUTPUT_MODE_HEX);

	for(int i = 0; i < 4; i++)
	{
	   IOVirtualSimBase::send( *byteptr );
	   byteptr++;
	}


	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
