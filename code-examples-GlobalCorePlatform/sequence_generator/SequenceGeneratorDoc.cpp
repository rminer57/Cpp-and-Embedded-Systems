// SequenceGeneratorDoc.cpp : implementation of the CSequenceGeneratorDoc class
//

//***********************************************************************************
//Sequence Generator Doc Class:
//Implemented by Mark Antilla and Mohammad Sheikh
//***********************************************************************************

#include <Afxcoll.h>
#include <string.h>

#include <process.h>


#include "stdafx.h"
#include "SequenceGenerator.h"
#include "SequenceGeneratorDoc.h"
#include "SequenceGeneratorView.h"
#include "SequenceCommandBaseClass.h"
#include "EnterComponentDialog.h"

//include any dialogs, if necessary
#include "ErrorMessageDialog.h"

//include iostream headers
#include <iostream.h>
#include <fstream.h>

//#include <string.h>
//#include <windows.h>


//include assembler file(s)


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CFile ArCompFile;
char * ArCompFileName = "MotSeqGenCompFile.arc";


//assembler function header
int assemble(istream &in,ostream &out,ostream &log);


//Store current directory to execute rfasm.exe
//CString currentDirectory;
//char  currentDirectory[256];

//This value stores any messages that should be displayed when compiling.
CString errorMessage = "";

// Default empty string
const CString CSequenceGeneratorDoc::nullString = "";

// 2D Array of component and interface names.
// each row corresponds to a component (0-31 possible), whose name is located in col 0 of that row.
// the other cols correspond to the interface names (0-7 possible interfaces)
CString CSequenceGeneratorDoc::compIntStrings[32][9] =
{{"synthesizer",                "setRFState", "setFrequency",       "getFrequency", "getError", nullString, nullString, nullString, nullString},
{"synthesizerAdjust",           "setRFState", "setWarp",            nullString,     nullString, nullString, nullString, nullString, nullString}, 
{"modulationBalanceAttenuator", "setRFState", "setModBalance",      nullString,     nullString, nullString, nullString, nullString, nullString},
{"modulator",                   "setRFState", "setModSensitivity",  nullString,     nullString, nullString, nullString, nullString, nullString}, 
{"modulationAttenuator",        "setRFState", "setModAttenuation",  nullString,     nullString, nullString, nullString, nullString, nullString}, 
{"powerAmplifier",              "setRFState", "setPA",              nullString,     nullString, nullString, nullString, nullString, nullString},
{"powerControl",                "setRFState", "setPowerLevel",      nullString,     nullString, nullString, nullString, nullString, nullString},
{"antennaSwitch",               "setRFState", "setAS",              nullString,     nullString, nullString, nullString, nullString, nullString},
{"frontEndFilter",              "setRFState", "setFilter",          nullString,     nullString, nullString, nullString, nullString, nullString},
{"switchCapacitorFilter",       "setRFState", "setSwitchCapFilter", nullString,     nullString, nullString, nullString, nullString, nullString},
{"vcoControl",                  "setRFState", "setMode",            nullString,     nullString, nullString, nullString, nullString, nullString},
{"frequencyConversionReference","setRFState", "setLO",              nullString,     nullString, nullString, nullString, nullString, nullString},
{"synchronousSerialInterface",  "setRFState", nullString,           nullString,     nullString, nullString, nullString, nullString, nullString},
{"rfStatus",                    nullString,   "getStatus",          nullString,     nullString, nullString, nullString, nullString, nullString},
{nullString,                    nullString,   nullString,           nullString,     nullString, nullString, nullString, nullString, nullString},
{nullString,                    nullString,   nullString,           nullString,     nullString, nullString, nullString, nullString, nullString},
{nullString,                    nullString,   nullString,           nullString,     nullString, nullString, nullString, nullString, nullString},
{nullString,                    nullString,   nullString,           nullString,     nullString, nullString, nullString, nullString, nullString},
{nullString,                    nullString,   nullString,           nullString,     nullString, nullString, nullString, nullString, nullString},
{nullString,                    nullString,   nullString,           nullString,     nullString, nullString, nullString, nullString, nullString},
{nullString,                    nullString,   nullString,           nullString,     nullString, nullString, nullString, nullString, nullString},
{nullString,                    nullString,   nullString,           nullString,     nullString, nullString, nullString, nullString, nullString},
{nullString,                    nullString,   nullString,           nullString,     nullString, nullString, nullString, nullString, nullString},
{nullString,                    nullString,   nullString,           nullString,     nullString, nullString, nullString, nullString, nullString},
{nullString,                    nullString,   nullString,           nullString,     nullString, nullString, nullString, nullString, nullString},
{nullString,                    nullString,   nullString,           nullString,     nullString, nullString, nullString, nullString, nullString},
{nullString,                    nullString,   nullString,           nullString,     nullString, nullString, nullString, nullString, nullString},
{nullString,                    nullString,   nullString,           nullString,     nullString, nullString, nullString, nullString, nullString},
{nullString,                    nullString,   nullString,           nullString,     nullString, nullString, nullString, nullString, nullString},
{nullString,                    nullString,   nullString,           nullString,     nullString, nullString, nullString, nullString, nullString},
{nullString,                    nullString,   nullString,           nullString,     nullString, nullString, nullString, nullString, nullString},
{nullString,                    nullString,   nullString,           nullString,     nullString, nullString, nullString, nullString, nullString}};

const CString CSequenceGeneratorDoc::buildSelected = "BUILD";
CString CSequenceGeneratorDoc::buildFileName = nullString;

/////////////////////////////////////////////////////////////////////////////
// CSequenceGeneratorDoc

IMPLEMENT_DYNCREATE(CSequenceGeneratorDoc, CDocument)

BEGIN_MESSAGE_MAP(CSequenceGeneratorDoc, CDocument)
//{{AFX_MSG_MAP(CSequenceGeneratorDoc)
ON_COMMAND(ID_EDIT_ADD_COMMAND, OnEditAddCommand)
ON_COMMAND(ID_EDIT_REMOVE_COMMAND, OnEditRemoveCommand)
ON_COMMAND(ID_BUILD_BUTTON, OnBuildButton)
ON_COMMAND(ID_ASSEMBLE_BUTTON, OnAssembleButton)
ON_COMMAND(ID_COMPILE_BUTTON, OnCompileButton)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSequenceGeneratorDoc construction/destruction
/////////////////////////////////////////////////////////////////////////////
CSequenceGeneratorDoc::CSequenceGeneratorDoc()
{
	CheckAndLoadComponentArchiveFile();
	
}

CSequenceGeneratorDoc::~CSequenceGeneratorDoc()
{
}

BOOL CSequenceGeneratorDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	
	sequenceCommandList.~SequencerList();
	
	buildFileName = nullString;

	return TRUE;
}
//*****************************************************************
//*****************************************************************
void CSequenceGeneratorDoc::WriteCompArchiveFile()
{
  CFileException e;

 // for use in displaying exceptions
  CString tempCString("CSequenceGeneratorDoc::WriteCompArchiveFile() ");


  try
  {
    // Execute some code that might throw an exception.
    // if config file does not exhist, create it. If it exhists, open as rd/wr
    if( !ArCompFile.Open( ArCompFileName, CFile::modeNoTruncate | CFile::modeCreate | CFile::modeWrite, &e ) )
    {

     //afxDump << "File could not be opened " << e.m_cause << "\n";
	 AfxMessageBox("File could not be opened");

	}
	else
	{
      CArchive myarchive(&ArCompFile, CArchive::store);
	  CompSerialize(myarchive);
	  myarchive.Close();
      ArCompFile.Close();
	  AfxMessageBox("archive saved.");
	  //afxDump << "archive saved. " "\n";
	}
  }
  catch( CMemoryException* e )
  {
//	int exception_errorcode = e->m_cause ;

    tempCString += " unhandled CMemoryException code ";
    AfxMessageBox(tempCString, MB_ICONSTOP);
  }
  catch( CFileException* e )
  {
	int exception_errorcode = e->m_cause ;

     // CFileException::none   No error occurred.
     // CFileException::generic   An unspecified error occurred.
     // CFileException::fileNotFound   The file could not be located.
     // CFileException::badPath   All or part of the path is invalid.
     // CFileException::tooManyOpenFiles   The permitted number of open files was exceeded.
     // CFileException::accessDenied   The file could not be accessed.
     // CFileException::invalidFile   There was an attempt to use an invalid file handle.
     // CFileException::removeCurrentDir   The current working directory cannot be removed.
     // CFileException::directoryFull   There are no more directory entries.
     // CFileException::badSeek   There was an error trying to set the file pointer.
     // CFileException::hardIO   There was a hardware error.
     // CFileException::sharingViolation   SHARE.EXE was not loaded, or a shared region was locked.
     // CFileException::lockViolation   There was an attempt to lock a region that was already locked.
     // CFileException::diskFull   The disk is full.
     // CFileException::endOfFile   The end of file was reached. 

    tempCString += " unhandled CFileException code ";
    AfxMessageBox(tempCString, MB_ICONSTOP);
  }
  catch( CArchiveException * e)
  {
	int exception_errorcode = e->m_cause ;

    switch(exception_errorcode) // read the exception enumeration code
	{
	    case CArchiveException::generic:

          tempCString += " Unspecified CArchiveException error ";
	      AfxMessageBox(tempCString, MB_ICONSTOP);
		break;

		case CArchiveException::readOnly:

          tempCString += " CArchiveException write attempted on a read only archive ";
	      AfxMessageBox(tempCString, MB_ICONSTOP);
		break;

		case CArchiveException::endOfFile:

          tempCString += " CArchiveException archive end of file while reading";
	      AfxMessageBox(tempCString, MB_ICONSTOP);
		break;

		case CArchiveException::writeOnly:

          tempCString += " CArchiveException read attempted on an archive opened for storing ";
	      AfxMessageBox(tempCString, MB_ICONSTOP);
		break;

		case CArchiveException::badIndex:

          tempCString += " CArchiveException Invalid file format";
	      AfxMessageBox(tempCString, MB_ICONSTOP);
		break;

		case CArchiveException::badClass:

          tempCString += " CArchiveException Tried to read object into object of the wrong type";
	      AfxMessageBox(tempCString, MB_ICONSTOP);
		break;

		case CArchiveException::badSchema:

          tempCString += " CArchiveException Tried to read object with different class version";
	      AfxMessageBox(tempCString, MB_ICONSTOP);
		break;

        default:
          tempCString += " unhandled CArchiveException code ";
	      AfxMessageBox(tempCString, MB_ICONSTOP);
		break;
    }

  }
  catch( CException* e )
  {
//	int exception_errorcode = e->m_cause ;

    tempCString += " unhandled CArchiveException code ";
	AfxMessageBox(tempCString, MB_ICONSTOP);
  }
  
      
}

//*****************************************************************
// this method is called upon startup of the app
// it checks the current directory for the component config
// file.  If it exhists, the components are loaded.
// if not found,the default components are used.
//*****************************************************************
BOOL CSequenceGeneratorDoc::CheckAndLoadComponentArchiveFile()
{
  CFileException e;
  BOOL retval = 0;

  // for use in displaying exceptions
  CString tempCString("CSequenceGeneratorDoc::CheckAndLoadComponentArchiveFile() ");

	// step 1. try to open the file.
	//         if file does not exhist, exit and do nothing
  
  try
  {
    // Execute some code that might throw an exception.
    // if config file does not exhist, create it. If it exhists, open as rd/wr
    if( !ArCompFile.Open( ArCompFileName, CFile::modeRead, &e ) )
    {

     //afxDump << "File could not be opened " << e.m_cause << "\n";
	 //AfxMessageBox("File could not be opened");
     // we could actually create the file and archive to it.
	}
	else
	{
      CArchive myarchive(&ArCompFile, CArchive::load);
	  CompSerialize(myarchive);
	  myarchive.Close();
      ArCompFile.Close();
	  //AfxMessageBox("archive read.");
	  retval = 1;
	}
  }
  catch( CMemoryException* e )
  {
// 	int exception_errorcode = e->m_cause ;
    tempCString += " unhandled CMemoryException code ";
	AfxMessageBox(tempCString, MB_ICONSTOP);
  }
  catch( CFileException* e )
  {
	int exception_errorcode = e->m_cause ;
    tempCString += " unhandled CFileException code ";
	AfxMessageBox(tempCString, MB_ICONSTOP);
   }
  catch( CArchiveException * e)
  {
	int exception_errorcode = e->m_cause ;

    switch(exception_errorcode) // read the exception enumeration code
	{
	    case CArchiveException::generic:

          tempCString += " Unspecified CArchiveException error ";
	      AfxMessageBox(tempCString, MB_ICONSTOP);
		break;

		case CArchiveException::readOnly:

          tempCString += " CArchiveException write attempted on a read only archive ";
	      AfxMessageBox(tempCString, MB_ICONSTOP);
		break;

		case CArchiveException::endOfFile:

          tempCString += " CArchiveException archive end of file while reading";
	      AfxMessageBox(tempCString, MB_ICONSTOP);
		break;

		case CArchiveException::writeOnly:

          tempCString += " CArchiveException read attempted on an archive opened for storing ";
	      AfxMessageBox(tempCString, MB_ICONSTOP);
		break;

		case CArchiveException::badIndex:

          tempCString += " CArchiveException Invalid file format";
	      AfxMessageBox(tempCString, MB_ICONSTOP);
		break;

		case CArchiveException::badClass:

          tempCString += " CArchiveException Tried to read object into object of the wrong type";
	      AfxMessageBox(tempCString, MB_ICONSTOP);
		break;

		case CArchiveException::badSchema:

          tempCString += " CArchiveException Tried to read object with different class version";
	      AfxMessageBox(tempCString, MB_ICONSTOP);
		break;

        default:
          tempCString += " unhandled CArchiveException code ";
	      AfxMessageBox(tempCString, MB_ICONSTOP);
		break;
	}
	  
 
    //AfxMessageBox("EnterComponentDialog::CheckAndLoadComponentArchiveFile CArchiveException exception");

  }
  catch( CException* e )
  {
//	int exception_errorcode = e->m_cause ;
    tempCString += " unhandled CException code ";
	AfxMessageBox(tempCString, MB_ICONSTOP);
  }  


  return retval;
}


//************************************************
//
// This method is used to store or retrieve objects
// to/from an archive file.  These objects are the
// 32 logical sequencer components and 8 interface
// methods supported by the sequencer.
// this method requires that the CFile and its
// associated archive object, are already opened.
// It is up to the caller to close them.
//************************************************
void CSequenceGeneratorDoc::CompSerialize(CArchive& ar)
{
    CFileException e;	
	int i, j;
	CString tempString;
	//CObject::Serialize(ar);
	
    CFile CompTxTFile;
    char * CompTxTFileName = "MotSeqGenCompFile.txt";
    	
	if (ar.IsStoring()) // archive initialized for storing if nonzero
	{

		CompTxTFile.Open( CompTxTFileName, CFile::modeReadWrite | CFile::modeCreate, &e);
		
		// serialize the components (write to archive file)
		for (i = 0; i < 32; i++)
		{
			// serialize the interface methods
			for (j=-1; j < 8; j++)
			{
				// write to a text file, so people can read it if desired
				tempString = CSequenceGeneratorDoc::getCompInterface(i,j);
                tempString += "\n";
				
				CompTxTFile.Write(tempString, tempString.GetLength() );

                // write to the archive file
				ar << CSequenceGeneratorDoc::getCompInterface(i,j);
			}
		}


	
	}
	else
	{
		// un-serialize the components (read from archive file)
		for (i = 0; i < 32; i++)
		{
			// the interface methods
			for (j=-1; j < 8; j++)
			{
				ar >> tempString;
				CSequenceGeneratorDoc::setCompInterface(i,j, tempString);
			}
		}
		
	}

	
	
}


/////////////////////////////////////////////////////////////////////////////
// CSequenceGeneratorDoc serialization
/////////////////////////////////////////////////////////////////////////////
void CSequenceGeneratorDoc::Serialize(CArchive& ar)
{
	int i, j;
	CString tempString;
	CObject::Serialize(ar);
	
	
	if (ar.IsStoring())
	{
		// serialize the symbols
		for (i = 0; i < 32; i++)
		{
			for (j=-1; j < 8; j++)
			{
				ar << getCompInterface(i,j);
			}
		}
		
		// serialize the list
		sequenceCommandList.Serialize(ar);
		
		// rename the file
		//    if ((ar.GetFile()->GetFileName().Find(".sg")) == -1)
		//      ar.GetFile()->Rename(ar.GetFile()->GetFileName(), ar.GetFile()->GetFileName() + ".sg"); 
		
	}
	else
	{
		// un-serialize the symbols
		for (i = 0; i < 32; i++)
		{
			for (j=-1; j < 8; j++)
			{
				ar >> tempString;
				setCompInterface(i,j, tempString);
			}
		}
		
		//Remove the current contents of the list (if any)
		while(sequenceCommandList.getSize() > 0)
		{
			sequenceCommandList.removeFromTail();
		}
		// un-serialize the list
		sequenceCommandList.Serialize(ar);
	}

	buildFileName = ar.GetFile()->GetFilePath();
	
	
}

/////////////////////////////////////////////////////////////////////////////
// CSequenceGeneratorDoc diagnostics
/////////////////////////////////////////////////////////////////////////////
#ifdef _DEBUG
void CSequenceGeneratorDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSequenceGeneratorDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSequenceGeneratorDoc commands
/////////////////////////////////////////////////////////////////////////////
int CSequenceGeneratorDoc::getNumOfCommands()
{
	// return the size of the command list
	return sequenceCommandList.getSize();
}

void CSequenceGeneratorDoc::DeleteContents() 
{
	CDocument::DeleteContents();
}

void CSequenceGeneratorDoc::OnEditAddCommand() 
{
	// TODO: Add your command handler code here
	SequenceCommandBaseClass *temp = new SequenceCommandBaseClass();
	
	sequenceCommandList.addToTail(temp);


	
	UpdateAllViews(NULL);
}

void CSequenceGeneratorDoc::OnEditRemoveCommand() 
{
	if(!sequenceCommandList.isEmpty())
		sequenceCommandList.removeFromTail();
	
	//Update view to redraw command stack
	UpdateAllViews(NULL);
}

SequencerList * CSequenceGeneratorDoc::getList()
{
	return &sequenceCommandList;
}

void CSequenceGeneratorDoc::OnBuildButton() 
{
	// Build = Compile + Assemble
//	buildFileName = buildSelected;

	OnCompileButton();
	OnAssembleButton();
	//buildFileName = nullString;
}

void CSequenceGeneratorDoc::OnAssembleButton() 
{
	
	
	CFile compileFile;
	CString asmFileName;
	CString binFileName; 
	CString mapFileName;

	
	static char szFilter[] = 
		"Assembly Files (*.asm)|*.asm|All Files (*.*)|*.*||";
	CFileDialog dlg (TRUE, NULL, asmFileName, NULL, szFilter);
	dlg.m_ofn.lpstrTitle = "Select Compiled File:";
	
	int isOK;
	if (buildFileName == nullString)
	{
		
		isOK = dlg.DoModal();
		if (isOK == IDOK)
		{
			asmFileName = dlg.GetPathName();
		}
	}
	else
	{
		asmFileName = buildFileName;
		if(asmFileName.Find(".sg",asmFileName.GetLength() - 3))
		{
			asmFileName.Delete(asmFileName.GetLength() - 3,3);
			asmFileName+=".asm";
		}
	//	else if(!asmFileName.Find(".asm",asmFileName.GetLength() - 4))
		//	asmFileName+=".asm";
	}
	
	
	if(asmFileName != nullString && isOK != IDCANCEL)
	{
		binFileName = asmFileName;
		mapFileName = asmFileName;
		
		binFileName.Delete(binFileName.GetLength() - 3, 3);
		binFileName += "bin";
		
		mapFileName.Delete(mapFileName.GetLength() - 3, 3);
		mapFileName += "map";
		
		/*binFileName.Insert(0,"\"");
		binFileName.Insert(binFileName.GetLength(),"\"");
		
		asmFileName.Insert(0,'"');
		asmFileName.Insert(asmFileName.GetLength(), '"');
		  
		mapFileName.Insert(0,"\"");
		mapFileName.Insert(mapFileName.GetLength(),"\"");*/
		
		//char *dest = (LPCTSTR)binFileName;
		//char *in = (LPCTSTR)asmFileName;
		//char *log = (LPCTSTR) mapFileName;
		
		//char *in = NULL;
		//char *out = NULL;
		//char *logFileName = NULL;
		
		//strcpy(in,(LPCTSTR)asmFileName);
		//strcpy(out,(LPCTSTR)binFileName);
		//strcpy(logFileName,(LPCTSTR)mapFileName);
		
		ifstream file;
		ofstream outFile,log;
		
		
		file.open((LPCTSTR)asmFileName/*in*/);
		outFile.open((LPCTSTR)binFileName/*out*/, ios::binary | ios::out);
		log.open((LPCTSTR)mapFileName/*logFileName*/);
		
		log << "Assembling: " << asmFileName << "..." << endl;
		assemble(file,outFile,log);
		
		//Close streams
		outFile.close();
		file.close();
		log.close();
		
		
		
		/*for(int i = 0; i < binFileName.GetLength(); i++)
		{
		if(binFileName[i] == '\\')
		{
		binFileName.Insert(i,"\\");
		i++;
		}
		
		  }
		  
			for(int j = 0; j < asmFileName.GetLength(); j++)
			{
			if(asmFileName[j] == '\\')
			{
			asmFileName.Insert(j,"\\");
			j++;
			}
		}*/
		
		
		//AfxMessageBox(binFileName);
		//AfxMessageBox(asmFileName);
		
		// Spawn the assembler - _spawnl(mode, command name, arg0, arg1, null)
		//	CString rfasmPath = currentDirectory;
		//	rfasmPath+="\\rfasm.exe";
		//rfasmPath.Insert(0,"\"");
		//rfasmPath.Insert(rfasmPath.GetLength(),"\"");
		
		
		//_spawnl(_P_WAIT, rfasmPath,asmFileName,binFileName, NULL);
		
		//_spawnl(_P_WAIT, rfasmPath,asmFileName,NULL);
		//_execl("rfasm.exe",asmFileName,binFileName,NULL);
		//_spawnl(_P_WAIT, "TestExecl", asmFileName, binFileName, NULL);
		
		/*	CFile temp_batchFile;
		if (!(temp_batchFile.Open("temp.bat", CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite)))
		{
		AfxMessageBox("Error Compiling file, please try again.");
		return;
		}
		else
		{
		temp_batchFile.Write(rfasmPath, rfasmPath.GetLength());
		temp_batchFile.Write(" ",1);
		temp_batchFile.Write(asmFileName,asmFileName.GetLength());
		temp_batchFile.Close();
		_spawnl(_P_WAIT,"temp",NULL);
		}*/
		
		AfxMessageBox("Assembly Successful");
		
		//buildFileName = nullString;
  }
  
}

void CSequenceGeneratorDoc::OnCompileButton() 
{
	
	
	//Check to see if the List is compilable.  If so, compile, otherwise, do not compile.
	if(isCompilable())
	{
		//AfxMessageBox(errorMessage);
		ErrorMessageDialog *errorMessageDlg = new ErrorMessageDialog;
		errorMessageDlg->setErrorMessage(errorMessage);
		
		CString compileFileName;  // assembly file name
		CString tempOutputString; // temp string for outputting
		CFile compileFile;        // assembly file
		int i, j;	                // loop variables
		SequenceCommandBaseClass *tempCommand;
		char buf[2];              // for itoa command
		

		//int isOK;
		if(buildFileName == "")
		{
			static char szFilter[] = 
				"Assembler Files (*.asm)|*.asm|All Files (*.*)|*.*||";
			CFileDialog dlg (FALSE, NULL, compileFileName, NULL, szFilter);
			dlg.m_ofn.lpstrTitle = "Select Compile File Name:";
			
		//	isOk = dlg.DoModal();
			if (/*isOk*/dlg.DoModal() ==IDOK/*!= IDCANCEL*/)
			{
				compileFileName = dlg.GetPathName();
			//	buildFileName = compileFileName;		
			}//added
		}
		else
		{
			compileFileName = buildFileName;
			if(compileFileName.Find(".sg",compileFileName.GetLength() - 3))
				compileFileName.Delete(compileFileName.GetLength() - 3,3);
		}

		
			//Add .asm extension
			if (compileFileName.Find(".asm") == -1)
				compileFileName += ".asm";
			
			// set global build variable if build was selected (asm file dialog not needed)
			//if (buildFileName == buildSelected)
			//	buildFileName = compileFileName;
			//else
			//	buildFileName = nullString;
			
			if (!(compileFile.Open(compileFileName, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite)))
			{
				return;
			}
			
			// Print symbol header
			tempOutputString = CString("/*---Begin symbolic information---*/") + "\r\n";
			compileFile.Write(tempOutputString, tempOutputString.GetLength());
			
			// put in defines for symbolic information
			for (i = 0; i <= 31; i++)
			{
				// print component names
				tempOutputString = getCompInterface(i,-1);
				if (tempOutputString != nullString)
				{
					
					tempOutputString += " = " + CString(itoa(i, buf, 10)) + "\t// C" + CString(itoa(i, buf, 10)) + "\r\n";
					compileFile.Write(tempOutputString, tempOutputString.GetLength());
				}
				
				for (j = 0; j <= 7; j++)
				{
					// print interface names
					tempOutputString = getCompInterface(i,j);
					if (tempOutputString != nullString)
					{
						tempOutputString += " = " +  CString(itoa(j, buf, 10)) + CString("\t\t// C") + CString(itoa(i, buf, 10)) + ",I" + CString(itoa(j, buf, 10)) + "\r\n";
						compileFile.Write(tempOutputString, tempOutputString.GetLength());
					}
				}
			}
			
			// Print symbol footer
			tempOutputString = CString("/*---End symbolic information---*/") + "\r\n" + "\r\n";
			compileFile.Write(tempOutputString, tempOutputString.GetLength());
			
			
			// Print code header
			tempOutputString = CString("/*---Begin code---*/") + "\r\n";
			compileFile.Write(tempOutputString, tempOutputString.GetLength());
			
			// Print out each command in assembly
			for (i = 1; i <= sequenceCommandList.getSize(); i++)
			{
				// get current command
				tempCommand = sequenceCommandList.getAt(i);
				
				// check if label
				tempOutputString = tempCommand->getLabel() + "\r\n";
				if (tempOutputString != (nullString + "\r\n"))
					compileFile.Write(tempOutputString, tempOutputString.GetLength());
				
				// check if comments
				tempOutputString = "//" + tempCommand->getComment() + "\r\n";
				if (tempOutputString != ("//" + nullString + "\r\n"))
					compileFile.Write(tempOutputString, tempOutputString.GetLength());
				
				// print out command
				tempOutputString = "\t" + sequenceCommandList.getAt(i)->toString() + "\r\n";
				compileFile.Write(tempOutputString, tempOutputString.GetLength());
			}
			
			// print END command
			tempOutputString = CString("\tEND") + "\r\n";
			compileFile.Write(tempOutputString, tempOutputString.GetLength());
			
			// Print code footer
			tempOutputString = CString("/*---End code---*/") + "\r\n";
			compileFile.Write(tempOutputString, tempOutputString.GetLength());
			
			compileFile.Close();
			
			AfxMessageBox("Compilation Successful.");
	
		
	}
	else
	{
		//AfxMessageBox(errorMessage);
		ErrorMessageDialog *errorMessageDlg = new ErrorMessageDialog;
		errorMessageDlg->setErrorMessage(errorMessage);
		
		
	}
	
	
}

// Static function to return component/interface symbolic name
CString CSequenceGeneratorDoc::getCompInterface(int compNum, int intNum)
{
	return ((compNum >= 0) && (compNum <= 31) && (intNum >= -1) && (intNum <= 7))?compIntStrings[compNum][intNum+1]:nullString;
}


// Static function to set component/interface symbolic name
void CSequenceGeneratorDoc::setCompInterface(int compNum, int intNum, CString newString)
{
	compIntStrings[compNum][intNum+1] = newString;
}


//This method checks if the current sequence is compilable.  It returns true if it is, otherwise it returns
//false
bool CSequenceGeneratorDoc::isCompilable()
{
	
	//Re-initialize errorMessage each time this function is called.
	errorMessage = "";
	
	SequenceCommandBaseClass *tempCommand = NULL;
	for(int i = 1; i <= sequenceCommandList.getSize(); i++)
	{
		CString commandNum;
		commandNum.Format("%d", i);
		tempCommand = sequenceCommandList.getAt(i);
		switch(tempCommand->getOpcode())
		{
		case 0:
			{
				SequenceExecuteClass *tempExecute = (SequenceExecuteClass *)tempCommand;
				if(tempExecute->getComponent() < 0)
				{
					//AfxMessageBox("Error, sequence command number " + commandNum + " has incorrect\nComponent.");
					errorMessage+= "Error, sequence command number " + commandNum + " has incorrect Component.\r\n";
					tempExecute->setComplete(false);
					sequenceCommandList.setAt(i,tempExecute);
				}
				else if (tempExecute->getInterface() < 0)
				{
					//AfxMessageBox("Error, sequence command number " + commandNum + " has incorrect\nInterface.");
					errorMessage+= "Error, sequence command number " + commandNum + " has incorrect Interface.\r\n";
					tempExecute->setComplete(false);
					sequenceCommandList.setAt(i,tempExecute);
				}
				else if (tempExecute->getReturnRegister() < 0)
				{
					//AfxMessageBox("Error, sequence command number " + commandNum + " has incorrect\nReturn Register.");
					errorMessage+= "Error, sequence command number " + commandNum + " has incorrect Return Register.\r\n";
					tempExecute->setComplete(false);
					sequenceCommandList.setAt(i,tempExecute);
				}
				else
				{
					if(!tempExecute->getImmediate())
					{
						if(tempExecute->getArg1().num < 0 || tempExecute->getArg1().ext < 0)
						{
							//AfxMessageBox("Error, sequence command number " + commandNum + " has incorrect\nData register inputs");
							errorMessage+= "Error, sequence command number " + commandNum + " has incorrect Data register inputs.\r\n";
							tempExecute->setComplete(false);
							sequenceCommandList.setAt(i,tempExecute);
						}
						else
						{
							tempExecute->setComplete(true);
							sequenceCommandList.setAt(i,tempExecute);
						}
					}
					else
					{
						tempExecute->setComplete(true);
						sequenceCommandList.setAt(i,tempExecute);
					}
					
					
				}
			}
			break;
		case 1:
			{
				SequenceManipulate *tempManip = (SequenceManipulate *)tempCommand;
				if(tempManip->getOperation() < 0)
				{
					//AfxMessageBox("Error, sequence command number " + commandNum + " has incorrect \nManipulate operation.");
					errorMessage += "Error, sequence command number " + commandNum + " has incorrect Manipulate operation.\r\n";
					tempManip->setComplete(false);
					sequenceCommandList.setAt(i, tempManip);
				}
				else if(tempManip->getDestinationRegister().num < 0 || tempManip->getDestinationRegister().ext < 0)
				{
					//AfxMessageBox("Error, sequence command number " + commandNum + " has incorrect \ndestination register information");
					errorMessage+= "Error, sequence command number " + commandNum + " has incorrect destination register information.\r\n";
					tempManip->setComplete(false);
					sequenceCommandList.setAt(i, tempManip);
				}
				else
				{
					if(!tempManip->getImmediate())
					{
						if(tempManip->getSourceRegister().num < 0 || tempManip->getSourceRegister().ext < 0)
						{
							//AfxMessageBox("Error, sequence command number " + commandNum + " has incorrect\nData.");
							errorMessage += "Error, sequence command number " + commandNum + " has incorrect Data.\r\n";
							tempManip->setComplete(false);
							sequenceCommandList.setAt(i, tempManip);
						}
						else
						{
							tempManip->setComplete(true);
							sequenceCommandList.setAt(i, tempManip);
						}
						
					}
					else
					{
						tempManip->setComplete(true);
						sequenceCommandList.setAt(i, tempManip);
					}
				}
				
			}
			break;
		case 2:
			{
				SequenceJumpClass *tempJump = (SequenceJumpClass *)tempCommand;
				if(tempJump->getComparison() < 0)
				{
					//AfxMessageBox("Error, sequence command number " + commandNum + " has incorrect Jump\ncomparison information.");
					errorMessage+= "Error, sequence command number " + commandNum + " has incorrect Jump comparison information.\r\n";
					tempJump->setComplete(false);
					sequenceCommandList.setAt(i,tempJump);
				}
				else if(tempJump->getOperand1().num < 0 || tempJump->getOperand1().ext < 0)
				{
					//AfxMessageBox("Error, sequence command number " + commandNum + " has incorrect Jump\noperand 1");
					errorMessage+= "Error, sequence command number " + commandNum + " has incorrect Jump operand 1.\r\n";
					tempJump->setComplete(false);
					sequenceCommandList.setAt(i,tempJump);
				}
				else 
				{
					if(!tempJump->getImmediate())
					{
						if(tempJump->getNonImmdOperand2().num < 0 || tempJump->getNonImmdOperand2().ext < 0)
						{
							//AfxMessageBox("Error, sequence command number " + commandNum + " has incorrect\nnon-immediate operand 2.");
							errorMessage+= "Error, sequence command number " + commandNum + " has incorrect non-immediate operand 2.\r\n";
							tempJump->setComplete(false);
							sequenceCommandList.setAt(i,tempJump);
						}
						else
						{
							tempJump->setComplete(true);
							sequenceCommandList.setAt(i,tempJump);
						}
						
					}
					else
					{
						tempJump->setComplete(true);
						sequenceCommandList.setAt(i,tempJump);
					}
				}
			}
			break;
		case 3:
			{
				SequenceMiscClass *tempMisc = (SequenceMiscClass *)tempCommand;
				if(tempMisc->getOperation() < 0)
				{
					//AfxMessageBox("Error, sequence command number " + commandNum + " has incorrect Misc\n operation information.");
					errorMessage+= "Error, sequence command number " + commandNum + " has incorrect Misc operation information.\r\n";
					tempMisc->setComplete(false);
					sequenceCommandList.setAt(i,tempMisc);
				}
				else
				{
					if(!tempMisc->getImmediate())
					{
						if(tempMisc->getOperation() == 2)
						{
							tempMisc->setComplete(true);
							sequenceCommandList.setAt(i, tempMisc);
						}
						else if(tempMisc->getSourceRegister().num < 0 || tempMisc->getSourceRegister().ext < 0)
						{
							//AfxMessageBox("Error, sequence command number " + commandNum + " has incorrect\nnon-immediate information.");
							errorMessage+= "Error, sequence command number " + commandNum + " has incorrect non-immediate information.\r\n";
							tempMisc->setComplete(false);
							sequenceCommandList.setAt(i, tempMisc);
						}
						else
						{
							tempMisc->setComplete(true);
							sequenceCommandList.setAt(i, tempMisc);
						}
					}
					else
					{
						tempMisc->setComplete(true);
						sequenceCommandList.setAt(i, tempMisc);
					}
					
				}
				
			}
			break;
		default:
			{
				tempCommand->setComplete(false);
				sequenceCommandList.setAt(i, tempCommand);
				errorMessage+="Error, sequence command number " + commandNum + " is not a command.\r\n";
				
			}
			break;
		}
		
	}
	
	if(errorMessage == "" && sequenceCommandList.getSize() > 0)
	{
		//AfxMessageBox("No Errors.  Press \"Ok\" to continue.");
		errorMessage+="No Errors...\r\n";
		return true;
	}
	else
	{
		//AfxMessageBox("Could not compile, please correct errors.\nThe following errors occured:\n" + errorMessage);
		errorMessage.Insert(0, "Could not compile, please correct errors.\r\nThe following errors occured:\r\n");
		return false;
	}
}
