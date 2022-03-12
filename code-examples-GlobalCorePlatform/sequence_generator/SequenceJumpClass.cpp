// SequenceJumpClass.cpp: implementation of the SequenceJumpClass class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "SequenceJumpClass.h"
#include "SequenceGeneratorDoc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


const CString SequenceJumpClass::comparisonStrings[16] = {"Always", "Equal", "Not Equal", "Greater", "Less", "Greater or Equal", "Less or Equal", "Unused", "Unused", "Unused", "Unused", "Unused", "Unused", "Unused", "Unused", "Unused"};
const CString SequenceJumpClass::comparisonCommandStrings[16] = {"JA", "JEQ", "JNE", "JGT", "JLT", "JGE", "JLE", CSequenceGeneratorDoc::nullString,CSequenceGeneratorDoc::nullString,CSequenceGeneratorDoc::nullString,CSequenceGeneratorDoc::nullString,CSequenceGeneratorDoc::nullString,CSequenceGeneratorDoc::nullString,CSequenceGeneratorDoc::nullString,CSequenceGeneratorDoc::nullString,CSequenceGeneratorDoc::nullString};

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SequenceJumpClass::SequenceJumpClass()
{
  //Initialize member variables upon object creation
  //-1 = INVALID/UNINITIALIZED STATE
  
  //RegisterType operand1;
  operand1.num = -1;
  operand1.ext = -1;
  operand1.source_type = false;
  comparison = -1;
  offset = 0;
  d_offset_register.num = -1;
  d_offset_register.ext = -1;
  d_offset_register.source_type = false;
  //Jump Immediate member variables:
  immd_operand2 = -1;
  //Jump Non Immediate member variables:
  non_immd_operand2.num = -1;
  non_immd_operand2.ext = -1;
  non_immd_operand2.source_type = false;
  
  destinationLabel = CSequenceGeneratorDoc::nullString;
}

SequenceJumpClass::~SequenceJumpClass()
{
  
}

int SequenceJumpClass::getComparison()
{
  return comparison;
}

RegisterType SequenceJumpClass::getOperand1()
{
  return operand1;
}

void SequenceJumpClass::setComparison(int comp)
{
  comparison = comp;
}

void SequenceJumpClass::setOperand1(RegisterType s_register)
{
  operand1.ext = s_register.ext;
  operand1.num = s_register.num;
  operand1.source_type = s_register.source_type;
}

void SequenceJumpClass::setDOffsetRegister(RegisterType d_register)
{
  d_offset_register.ext = d_register.ext;
  d_offset_register.num = d_register.num;
  d_offset_register.source_type = d_register.source_type;
  
}

RegisterType SequenceJumpClass::getDOffsetRegister()
{
  return d_offset_register;
}

int SequenceJumpClass::getOffset()
{
  return offset;
}

void SequenceJumpClass::setOffset(int offset_num)
{
  offset = offset_num;
}



//Jump Immediate function implementations:

int SequenceJumpClass::getImmediateOperand2()
{
  return immd_operand2;
}


void SequenceJumpClass::setImmediateOperand2(int data)
{
  immd_operand2 = data;
}


//Jump Non-Immediate function implememtations:


RegisterType SequenceJumpClass::getNonImmdOperand2()
{	
  return non_immd_operand2;
}


void SequenceJumpClass::setNonImmdOperand2(RegisterType s_register2)
{	
  non_immd_operand2.ext = s_register2.ext;
  non_immd_operand2.num = s_register2.num;
  non_immd_operand2.source_type = s_register2.source_type;
}


void SequenceJumpClass::Serialize(CArchive &ar)
{
  //	CObject::Serialize(ar);
  if(ar.IsStoring())
  {
    //Serialize SequenceCommandBaseClass member variables
    SequenceCommandBaseClass::Serialize(ar);
    
    //Serialize SequenceJumpClass member variables
    ar << comparison;
    
    ar << d_offset_register.num;
    ar << d_offset_register.ext;
    ar << d_offset_register.source_type;
    
    ar << immd_operand2;
    ar << non_immd_operand2.num;
    ar << non_immd_operand2.ext;
    ar << non_immd_operand2.source_type;
    
    ar << offset;
    
    ar << operand1.num;
    ar << operand1.ext;
    ar << operand1.source_type;
    
  }
  else
  {
    //Serialize SequenceCommandBaseClass member variables
    SequenceCommandBaseClass::Serialize(ar);
    
    //Serialize SequenceJumpClass member variables
    int s_type;
    ar >> comparison;
    
    ar >> d_offset_register.num;
    ar >> d_offset_register.ext;
    ar >> s_type;
    d_offset_register.source_type = s_type!=0;
    
    ar >> immd_operand2;
    ar >> non_immd_operand2.num;
    ar >> non_immd_operand2.ext;
    ar >> s_type;
    non_immd_operand2.source_type = s_type!=0;
    
    ar >> offset;
    
    ar >> operand1.num;
    ar >> operand1.ext;
    ar >> s_type;
    operand1.source_type = s_type!=0;
  }
  
}


CString SequenceJumpClass::toString()
{
  CString comparString = getComparisonCommandString();
  CString operand1String = getOperand1String();
  CString operand2String = getOperand2String();
  CString destOffString = getDestOffString();
  
  return ((comparString == CSequenceGeneratorDoc::nullString) || ((comparison != 0) && ((operand1String == CSequenceGeneratorDoc::nullString) || (operand2String == CSequenceGeneratorDoc::nullString))) || (destOffString == CSequenceGeneratorDoc::nullString))?
    SequenceCommandBaseClass::invalidString:(comparString + (CString(" ") + ((comparison != 0)?(operand1String + "," + operand2String + CString(",")):CSequenceGeneratorDoc::nullString) + destOffString));
}

CString SequenceJumpClass::getComparisonString()
{
  return ((0 <= comparison) && (comparison <= 15))?comparisonStrings[comparison]:CSequenceGeneratorDoc::nullString;
}

CString SequenceJumpClass::getComparisonCommandString()
{
  return ((0 <= comparison) && (comparison <= 15))?comparisonCommandStrings[comparison]:CSequenceGeneratorDoc::nullString;
}

CString SequenceJumpClass::getOperand1String()
{
  return getRegString(operand1);
}

CString SequenceJumpClass::getOperand2String()
{
  CString tempString;
  char buf[10];
  
  if (immediate)
  {
    tempString = "#" + CString(itoa(immd_operand2, buf, 10));
  }
  else
  {
    tempString = getRegString(non_immd_operand2);
  }
  
  return tempString;
}

CString SequenceJumpClass::getDestOffString()
{
  CString tempString = getRegString(d_offset_register);
  return (tempString == CSequenceGeneratorDoc::nullString)?CString(itoa(offset, new char[3], 10)):(tempString + ":" + CString(itoa(offset, new char[3], 10)));
}

CString SequenceJumpClass::getOffsetString()
{
  return CString(itoa(offset, new char[3], 10));
}

CString SequenceJumpClass::getOffsetRegisterString()
{
  return getRegString(d_offset_register);
}