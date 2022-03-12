// SequenceCommandBaseClass.cpp: implementation of the SequenceCommandBaseClass class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "SequenceGeneratorDoc.h"
#include "SequenceCommandBaseClass.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


const CString SequenceCommandBaseClass::invalidString = "//INVALID INSTRUCTION";

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
SequenceCommandBaseClass::SequenceCommandBaseClass()
{
	//Initialize member variables upon object creation.
	immediate = false;
	opcode = -1;
	label_string = CSequenceGeneratorDoc::nullString;
	comment_string = CSequenceGeneratorDoc::nullString;
	isComplete = false;
	isSelected = false;
	group_num = -1;
}

SequenceCommandBaseClass::~SequenceCommandBaseClass()
{
}

//////////////////////////////////////////////////////////////////////
// Data get/set functions
//////////////////////////////////////////////////////////////////////
int SequenceCommandBaseClass::getOpcode()
{
	return opcode;
}

void SequenceCommandBaseClass::setOpcode(int operation)
{
	opcode = operation;
}

bool SequenceCommandBaseClass::getImmediate()
{
	return immediate;
}

void SequenceCommandBaseClass::setImmediate(bool immd)
{
	immediate = immd;
}

CString SequenceCommandBaseClass::getComment()
{
	return comment_string;
}

void SequenceCommandBaseClass::setComment(CString comment)
{
	comment_string = comment;
}

CString SequenceCommandBaseClass::getLabel()
{
	return label_string;
}

void SequenceCommandBaseClass::setLabel(CString label)
{
	label_string = label;
}

//////////////////////////////////////////////////////////////////////
// Save function(s)
//////////////////////////////////////////////////////////////////////
void SequenceCommandBaseClass::Serialize(CArchive& ar)
{

	if(ar.IsStoring())
	{
		ar << opcode;
		ar << comment_string;
		ar << immediate;
		ar << label_string;
		
	}
	else
	{
		int immd;
		ar >> comment_string;
		ar >> immd;
		ar >> label_string;
		

		immediate = immd!=0;
	}
}


//////////////////////////////////////////////////////////////////////
// String name functions
//////////////////////////////////////////////////////////////////////
CString SequenceCommandBaseClass::toString()
{
  // Returns an invalid entry because this function would only be called
  // if there are no derived objects.  If no derived objects, then no
  // additional data to return.
  return invalidString;
}

CString SequenceCommandBaseClass::getOpcodeName()
{
  CString retValue;
  switch(opcode)
  {
  case 0:
    retValue = "Execute";
    break;
  case 1:
    retValue = "Manipulate";
    break;
  case 2:
    retValue = "Jump";
    break;
  case 3:
    retValue = "Miscellaneous";
    break;
  default:
    retValue = CSequenceGeneratorDoc::nullString;
    break;
  }
  
  return retValue;
}

CString SequenceCommandBaseClass::getRegString(RegisterType regData)
{
  CString tempString = CSequenceGeneratorDoc::nullString;
  char buf[10];

  if ((regData.ext < 8) && (regData.ext >= 0))  // check if valid ext
    if ((regData.num >= 0) && ((regData.num < 16) || ((regData.num < 32) && (regData.ext == 1))))  // check if valid num
    {
      if (regData.source_type) // Data store
      {
        tempString = "D" + CString(itoa(regData.num, buf, 10)) + ":" + ((regData.ext <= 3)?("G" + CString(itoa(regData.ext, buf, 10))):("L" + CString(itoa((regData.ext-4), buf, 10))));
      }
      else if (regData.ext == 0) // global reg
      {
        tempString = "G" + CString(itoa(regData.num, buf, 10));
      }
      else                      // local reg
      {
        tempString = "L" + CString(itoa(regData.num, buf, 10));
      }
    }
  
  return tempString;
}

bool SequenceCommandBaseClass::getComplete()
{
	return isComplete;
}

void SequenceCommandBaseClass::setComplete(bool complete)
{
	isComplete = complete;
}

void SequenceCommandBaseClass::setIsSelected(bool selected)
{
	isSelected = selected;
}

bool SequenceCommandBaseClass::getIsSelected()
{
	return isSelected;
}


void SequenceCommandBaseClass::setGroupNum(int groupNum)
{
	group_num = groupNum;
}


int SequenceCommandBaseClass::getGroupNum()
{
	return group_num;
}
