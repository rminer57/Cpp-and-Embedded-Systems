// SequenceManipulate.cpp: implementation of the SequenceManipulate class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "SequenceManipulate.h"
#include "SequenceGeneratorDoc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

const CString SequenceManipulate::operationStrings[16] = {"LOAD", "ADD", "SUBTRACT", "AND", "OR", "XOR", "NOT", CSequenceGeneratorDoc::nullString, CSequenceGeneratorDoc::nullString, CSequenceGeneratorDoc::nullString, CSequenceGeneratorDoc::nullString, CSequenceGeneratorDoc::nullString, CSequenceGeneratorDoc::nullString, CSequenceGeneratorDoc::nullString, CSequenceGeneratorDoc::nullString, CSequenceGeneratorDoc::nullString};

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
SequenceManipulate::SequenceManipulate()
{
  //Initialize member variables upon object creation
  //-1 = INVALID/UNINITIALIZED STATE
  
  destination_register.ext = -1;
  destination_register.num = -1;
  destination_register.source_type = false;
  operation = -1;
  //Manipulate Immediate arguements:
  arguement = 0;
  //Manipulate Non-Immediate arguements:
  arg1.ext = -1;
  arg1.num = -1;
  arg1.source_type = false;
}

SequenceManipulate::~SequenceManipulate()
{
  
}


//////////////////////////////////////////////////////////////////////
// Get/Set Data functions
//////////////////////////////////////////////////////////////////////
int SequenceManipulate::getOperation()
{
  return operation;
}

RegisterType SequenceManipulate::getDestinationRegister()
{
  return destination_register;
}

void SequenceManipulate::setOperation(int op_num)
{
  operation = op_num;
}

void SequenceManipulate::setDestinationRegister(RegisterType d_register)
{
  destination_register.ext = d_register.ext;
  destination_register.num = d_register.num;
  destination_register.source_type = d_register.source_type;
}

//Manipulate Immediate member function implementation:
int SequenceManipulate::getArguement()
{
  return arguement;
}

void SequenceManipulate::setArguement(int arg)
{
  arguement = arg;
}

//Manipulate Non-Immediate member function implementation:
void SequenceManipulate::setSourceRegister(RegisterType source_reg)
{
  arg1.ext = source_reg.ext;
  arg1.num = source_reg.num;
  arg1.source_type = source_reg.source_type;
}

RegisterType SequenceManipulate::getSourceRegister()
{
  return arg1;
  
}


//////////////////////////////////////////////////////////////////////
// Serialize
//////////////////////////////////////////////////////////////////////
void SequenceManipulate::Serialize(CArchive &ar)
{
  if(ar.IsStoring())  //serialize data
  {
    //Serialize SequenceCommandBaseClass member variables
    SequenceCommandBaseClass::Serialize(ar);
    
    //Serialize SequenceManipulate member variables
    ar << arg1.num;
    ar << arg1.ext;
    ar << arg1.source_type;
    ar << arguement;
    ar << destination_register.num;
    ar << destination_register.ext;
    ar << destination_register.source_type;
    ar << operation;
  }
  else                // unserialize data
  {
    //Serialize SequenceCommandBaseClass member variables
    SequenceCommandBaseClass::Serialize(ar);
    
    //Serialize SequenceManipulate member variables
    int s_type;
    ar >> arg1.num;
    ar >> arg1.ext;
    ar >> s_type;
    arg1.source_type = s_type!=0;
    ar >> arguement;
    ar >> destination_register.num;
    ar >> destination_register.ext;
    ar >> s_type; 
    destination_register.source_type = s_type!=0;
    ar >> operation;
  }
}



//////////////////////////////////////////////////////////////////////
// String output functions
//////////////////////////////////////////////////////////////////////
CString SequenceManipulate::toString()
{
  CString opString = getOperationString();
  CString destString = getDestinationString();
  CString sourceString = getSourceString();
  
  return ((opString == CSequenceGeneratorDoc::nullString) || (destString == CSequenceGeneratorDoc::nullString) || (sourceString == CSequenceGeneratorDoc::nullString))?
    SequenceCommandBaseClass::invalidString:(opString + " " + destString + "," + sourceString);
}

CString SequenceManipulate::getOperationString()
{
  return ((0 <= operation) && (operation <= 6))?operationStrings[operation]:CSequenceGeneratorDoc::nullString;
}

CString SequenceManipulate::getDestinationString()
{
  return getRegString(destination_register);
}

CString SequenceManipulate::getSourceString()
{
  CString tempString;
  char buf[10];
  
  if (immediate)
  {
    tempString = "#" + CString(itoa(arguement, buf, 10));
  }
  else
  {
    tempString = getRegString(arg1);
  }
  
  return tempString;
}