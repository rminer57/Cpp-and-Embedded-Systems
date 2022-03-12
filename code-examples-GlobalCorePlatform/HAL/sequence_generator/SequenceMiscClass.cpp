// SequenceMiscClass.cpp: implementation of the SequenceMiscClass class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "SequenceMiscClass.h"
#include "SequenceGeneratorDoc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

// Array of miscellaneous commands
const CString SequenceMiscClass::miscStrings[16] = {"DELAY", "CALL", "END", CSequenceGeneratorDoc::nullString,
CSequenceGeneratorDoc::nullString,CSequenceGeneratorDoc::nullString,CSequenceGeneratorDoc::nullString,
CSequenceGeneratorDoc::nullString,CSequenceGeneratorDoc::nullString,CSequenceGeneratorDoc::nullString,
CSequenceGeneratorDoc::nullString,CSequenceGeneratorDoc::nullString,CSequenceGeneratorDoc::nullString,
CSequenceGeneratorDoc::nullString,CSequenceGeneratorDoc::nullString,CSequenceGeneratorDoc::nullString};

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
SequenceMiscClass::SequenceMiscClass()
{
	//Initialize member variables upon object creation
	//-1 = INVALID/UNINITIALIZED STATE
	operation = -1;
	//Misc Immediate member variables:
	source_data = 0;
	//Misc Non-Immediate member variable:
	source_register.ext = -1;
	source_register.num = -1;
	source_register.source_type = false;

}

SequenceMiscClass::~SequenceMiscClass()
{

}


//////////////////////////////////////////////////////////////////////
// Get/Set Data Functions
//////////////////////////////////////////////////////////////////////
int SequenceMiscClass::getOperation()
{
	return operation;
}

void SequenceMiscClass::setOperation(int op_num)
{
	operation = op_num;
}


//Misc Immediate function implementation:
int SequenceMiscClass::getSourceData()
{
	return source_data;
}

void SequenceMiscClass::setSourceData(int s_data)
{
	source_data = s_data;
}

//Misc Non-Immediate function implementation:
void SequenceMiscClass::setSourceRegister(RegisterType s_register)
{
	source_register.ext = s_register.ext;
	source_register.num = s_register.num;
	source_register.source_type = s_register.source_type;
}

RegisterType SequenceMiscClass::getSourceRegister()
{
	return source_register;
}

//Serialize member function
void SequenceMiscClass::Serialize(CArchive &ar)
{
	//CObject::Serialize(ar);
	if(ar.IsStoring())
	{
		//Serialize SequenceCommandBaseClass member variables
		SequenceCommandBaseClass::Serialize(ar);
		

		//Serialize SequenceMiscClass member variables
		ar << operation;
		ar << source_data;
		ar << source_register.num;
		ar << source_register.ext;
		ar << source_register.source_type;
	}
	else
	{
		//Serialize SequenceCommandBaseClass member variables
		SequenceCommandBaseClass::Serialize(ar);

		//Serialize SequenceMiscClass member variables
		int s_type;
		ar >> operation;
		ar >> source_data;
		ar >> source_register.num;
		ar >> source_register.ext;
		ar >> s_type;
		source_register.source_type = s_type!=0;
	}
}


//////////////////////////////////////////////////////////////////////
// String Output Functions
//////////////////////////////////////////////////////////////////////
CString SequenceMiscClass::toString()
{
  CString opString = getOperationString();
  CString argString = getArgString();
  
  return ((opString == CSequenceGeneratorDoc::nullString) || ((operation != 2) && (argString == CSequenceGeneratorDoc::nullString)))?
    SequenceCommandBaseClass::invalidString:(opString + (" " + argString));
}

CString SequenceMiscClass::getOperationString()
{
  return ((0 <= operation) && (operation <= 15))?miscStrings[operation]:CSequenceGeneratorDoc::nullString;
}

CString SequenceMiscClass::getArgString()
{
  CString tempString;
  char buf[20];
  if (immediate)
  {
    tempString = "#" + CString(itoa(source_data, buf, 10));
  }
  else
  {
    tempString = getRegString(source_register);
  }
  
  return tempString;
}