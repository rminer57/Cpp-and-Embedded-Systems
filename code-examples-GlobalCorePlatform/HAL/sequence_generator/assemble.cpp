#include <iostream.h>
#include <fstream.h>

#include <string.h>
#include <windows.h>

#include "regularexpression.h"
#include "lexana.h"
#include "statemachine.h"
#include "actions.h"
#include "symboltable.h"

#define BUFFER_SIZE 10240
#define OUT_BUFFER_SIZE 4096

//Get next block from file
//Returns TRUE if more in stream...
bool getBuffer(istream *source,char *buffer)
{
    source->read(buffer,BUFFER_SIZE);               //Load from stream

    int count = source->gcount();

    //Terminate buffer if input less than buffer size;
    if (count < BUFFER_SIZE)
    {
        buffer[count] = '\0';
        return false;                               //No more input...
    }
    return true;
    //Need to create some kind of sliding buffer window....
}

//Derive a name from the given name..
char *createName(char *name,char *ext)
{
    char *bname = new char[strlen(name)+1];

    strcpy(bname,name);                                 //Duplicate
    
    char *loc = strrchr(bname,'.');                     //find last '.'
    if (loc != NULL)
    {
        *loc = '\0';                                    //Truncate
    }
    strcat(loc,ext);                                    //Apply extension...
    return bname;
}

//Bracket a string
char *encapsulate(char *name,char *bracket)
{
	char *result = new char[strlen(name)+2*strlen(bracket)+1];
	*result = '\0';
	strcat(result,bracket);
	strcat(result,name);
	strcat(result,bracket);
	return result;
};

//Obtains the file size and modified date
//File must be already opened.
int getFileSize(HANDLE &file)
{
    BY_HANDLE_FILE_INFORMATION info;
    ::GetFileInformationByHandle(file,&info);			//Obtain info

	return info.nFileSizeLow;
}

//Enumerates of main events (mathces expressions below)
enum mainEvents
{
	WHITE_SPACE=0,
	CRLF,
	COMMENT_A,
	COMMENT_B,
	PREPROCESSOR,
	SENTENCE,
};

//Array of standard expressions.  These are matched IN ORDER
const RegularExpression * const mainParse[] =
{
    //White space (1 or more SPACE or TAB)
    new RegularExpression("( |\t)+"),

	//Cariage Return  (LF or CR,LF)
	new RegularExpression("(\n|\r\n)"),

    //A comment (type A, ; or // line end delimited)
    new RegularExpression("(;|//)[ -~\t]*"),

    //A comment (type B, /* */)
    new RegularExpression("(/%*)([ -%)%+-~\t\n\r]|%*[ -%.0-~\t\n\r])*(%*/)"),

    //A pre-processor directive
    new RegularExpression("(#)([A-Za-z_]+)(( |\t)+)([ -~]*)"),

    //A sentence (anything else...) 
    new RegularExpression("[ -~\t]*"),
};

const int numMainStates = 2;
const int numMainEvents = 6;

/*STATE MACHINE, TOP LEVEL

	State	Description
	0		Start of Line (not processed instructions)
	1		In line (waiting for CR)

	State	WHITE_SPACE			CRLF				COMMENT_A				COMMENT_B		PREPROCESSOR		SENTENCE					
	0		-					0 (EOL)				1D						- (CB)			1 (PREPROC)			1 (SENT)						
	1		-					0 (EOL)				- (ERROR)				- (CB)			- (ERROR)			- (ERROR)				
*/

Action * const mainTable[numMainStates*numMainEvents] =
{
	NO_STATE_CHANGE,			ActionEOL::evt,		DIRECT_SC(ST_IN_LINE),	ActionCB::evt,	ActionPREPROC::evt,	ActionSENT::evt,	
	NO_STATE_CHANGE,			ActionEOL::evt,		NO_STATE_CHANGE,		ActionCB::evt,	NO_STATE_CHANGE,	NO_STATE_CHANGE,
};

const int instructionSize = 6;

//Assemble the given file
int assemble(istream &in,ostream &out,ostream &log)
{
    LexAna lex((RegularExpression**)mainParse,sizeof(mainParse)/sizeof(RegularExpression*));
	StateMachine sm((Action **)mainTable,numMainStates,numMainEvents);

    //Parse the input
    bool available;
    int i,length;
    char *remainder;
	char *buffer = new char[BUFFER_SIZE];
	unsigned char *outputBuffer = new unsigned char[OUT_BUFFER_SIZE];

	SymbolTable *sym = new SymbolTable();
	ActionData *actData = new ActionData(sym);
	actData->buffer = outputBuffer;									//Destination for assembled code
	actData->errStream = &log;

	//On entry, the state machine is in state '0'
    do
    {
		available = getBuffer(&in,buffer);							//Read from stream
		remainder = buffer;

        while (remainder != NULL && *remainder != '\0')
        {
            actData->str = remainder;

			//Call parser.  'i' updated to matched 'event'
            remainder = lex.parse(remainder,i,length);

            //Successful match
			switch (i)
			{
				//Partial match
			case LexAna::PARTIAL_MATCH:
				{
					log << "Partial Match, need more data..." << endl;
				}
				break;

				//Miss match
			case LexAna::MISS_MATCH:
				{
					log << "NO MATCH" << endl;
					if (remainder != NULL)
					{
						remainder++;
					}
				}
				break;
				
				//Match found
			default:
				{
					char n;

					if (remainder != NULL)
					{
						n = *remainder;
						*remainder = '\0';
					}

					//Execute state machine
					int newState = sm.execute(i,actData);
					log.flush();
//					log << i << ": After : {" << start << "} New State : " << newState <<  endl;
            
					if (remainder != NULL)
					{
						*remainder = n;
					}
				}
			}
        }
    } while(available);                             //!!!! WON'T WORK YET

	log << "*****First Pass complete*****" << endl;
	
	//Retry held sentences...
	HeldSentence *current = actData->head;
	bool failedAssembly = false;

	while(current != NULL)
	{
		try
		{

			current->key->form(current->str,actData->symb,current->programCounter);
			
			unsigned char *temp = actData->buffer + current->programCounter;

			//Copy the data into the buffer
			for (int i=0;i<current->key->getSize();i++)
			{
				temp[i] = (*(current->key))[i];				//transfer data
			}
		}
		catch(Exception *except)
		{
			log << "Line " << current->lineNumber <<  " ERROR ==> " << except->getDesc() << endl;
			failedAssembly = true;
		}
		delete current->key;

		current = current->next;
	}
	
	if (!failedAssembly)
	{
		//Dump statistics
		log << "*****Assembly complete*****" << endl;
		log << "Total Instructions : " << actData->programCounter/instructionSize << " ( " << actData->programCounter << " bytes )" << endl;
		log << endl;
		log << "{" << endl;
		for (int s = 0;s<actData->programCounter;s+=instructionSize)
		{
			log << "   ";
			for (int i=0;i<instructionSize;i++)
			{
				log << "0x" << hex << short(outputBuffer[i+s]) << ", ";
			}
			log << dec << endl;
		}
		log << "};" << endl;

		out.write(outputBuffer,actData->programCounter);
	}
	else
	{
		log << "*****FAILED ASSEMBLY*****" << endl;
	}
	log << endl;
	log << "*****Symbol Table:" << endl;
	sym->dump(log);
	log << "*****End symbol table" << endl;

	return (failedAssembly?-1:0);
}
