// SequenceExecuteClass.cpp: implementation of the SequenceExecuteClass class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "SequenceExecuteClass.h"
#include "SequenceGeneratorDoc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SequenceExecuteClass::SequenceExecuteClass()
{
  //Initialize member variables upon object creation
  //-1 = INVALID/UNINITIALIZED STATE
  execute_interface = -1;
  component = -1;
  return_register = -1;
  
  //Execute Immediate aguement(s):
  arguement = 0;
  
  //Execute Non-Immediate arguement(s):
  arg4.ext = -1;
  arg4.num = -1;
  arg4.source_type = false;
  arg3.ext = -1;
  arg3.num = -1;
  arg3.source_type = false;
  arg2.ext = -1;
  arg2.num = -1;
  arg2.source_type = false;
  arg1.ext = -1;
  arg1.num = -1;
  arg1.source_type = false;
}

SequenceExecuteClass::~SequenceExecuteClass()
{
}


//Basic Execute Function Implementations:
int SequenceExecuteClass::getReturnRegister()
{
  return return_register;
}

int SequenceExecuteClass::getComponent()
{
  return component;
}

int SequenceExecuteClass::getInterface()
{
  return execute_interface;
}

void SequenceExecuteClass::setReturnRegister(int retRegister)
{
  return_register = retRegister;
}

void SequenceExecuteClass::setComponent(int component_function)
{
  component = component_function;
}	

void SequenceExecuteClass::setInterface(int exec_interface)
{
  execute_interface = exec_interface;
}

//Execute Immediate function implementations:
int SequenceExecuteClass::getArguement()
{
  return arguement;
}

void SequenceExecuteClass::setArguement(int arg)
{
  arguement = arg;
}

//Execute Non-Immediate function implementations:
RegisterType SequenceExecuteClass::getArg1()
{
  return arg1;
}

RegisterType SequenceExecuteClass::getArg2()
{
  return arg2;
}

RegisterType SequenceExecuteClass::getArg3()
{
  return arg3;
}

RegisterType SequenceExecuteClass::getArg4()
{
  return arg4;
}

void SequenceExecuteClass::SetArg1(RegisterType arg_1)
{	
  arg1.ext = arg_1.ext;
  arg1.num = arg_1.num;
  arg1.source_type = arg_1.source_type;
}

void SequenceExecuteClass::SetArg2(RegisterType arg_2)
{
  arg2.ext = arg_2.ext;
  arg2.num = arg_2.num;
  arg2.source_type = arg_2.source_type;
}

void SequenceExecuteClass::SetArg3(RegisterType arg_3)
{
  arg3.ext = arg_3.ext;
  arg3.num = arg_3.num;
  arg3.source_type = arg_3.source_type;
}

void SequenceExecuteClass::SetArg4(RegisterType arg_4)
{
  arg4.ext = arg_4.ext;
  arg4.num = arg_4.num;
  arg4.source_type = arg_4.source_type;
}


//Serialize method
void SequenceExecuteClass::Serialize(CArchive &ar)
{
  //	CObject::Serialize(ar);
  if(ar.IsStoring())
  {
    //Serialize SequenceCommandBaseClass member variables
    SequenceCommandBaseClass::Serialize(ar);
    
    //Serialize SequenceExecuteClass member variables
    ar << arg1.num;
    ar << arg1.ext;
    ar << arg1.source_type;

    ar << arg2.num;
    ar << arg2.ext;
    ar << arg2.source_type;

    ar << arg3.num;
    ar << arg3.ext;
    ar << arg3.source_type;

    ar << arg4.num;
    ar << arg4.ext;
    ar << arg4.source_type;

    ar << arguement;
    ar << component;
    ar << execute_interface;
    ar << return_register;
  }
  else
  {
    
    //Serialize SequenceCommandBaseClass member variables
    SequenceCommandBaseClass::Serialize(ar);
    
    //Serialize SequenceExecuteClass member variables
    int s_type;
    ar >> arg1.num;
    ar >> arg1.ext;
    ar >> s_type;
    arg1.source_type = s_type!=0;
    
    ar >> arg2.num;
    ar >> arg2.ext;
    ar >> s_type;
    arg2.source_type = s_type!=0;
    
    ar >> arg3.num;
    ar >> arg3.ext;
    ar >> s_type;
    arg3.source_type = s_type!=0;
    
    ar >> arg4.num;
    ar >> arg4.ext;
    ar >> s_type;
    arg4.source_type = s_type!=0;
    
    ar >> arguement;
    ar >> component;
    ar >> execute_interface;
    ar >> return_register;
    
  }
}

CString SequenceExecuteClass::toString()
{
  CString opString = "EXEC";
  CString compString = CSequenceGeneratorDoc::getCompInterface(component, -1);
  CString intString = CSequenceGeneratorDoc::getCompInterface(component, execute_interface);
  CString retString = getReturnRegisterString();
  CString dataString = getDataString();
  
  return ((compString == CSequenceGeneratorDoc::nullString) || (intString == CSequenceGeneratorDoc::nullString) || (retString == CSequenceGeneratorDoc::nullString) || (dataString == CSequenceGeneratorDoc::nullString))?
    SequenceCommandBaseClass::invalidString:(opString + " " + retString + "," + compString + ":" + intString + "," + dataString);
}

CString SequenceExecuteClass::getReturnRegisterString()
{
  char buf[10];

  return ((0 <= return_register) && (15 >= return_register))?CString("L" + CString(itoa(return_register, buf, 10))):CSequenceGeneratorDoc::nullString;
}

CString SequenceExecuteClass::getDataString()
{
  CString tempString = CSequenceGeneratorDoc::nullString;
  CString tempArg;
  char buf[10];

  if (immediate)
  {
    tempString = "#" + CString(itoa(arguement, buf, 10));
  }
  else
  {
    tempArg = getRegString(arg1);
    if (tempArg != CSequenceGeneratorDoc::nullString)
    {
      tempString = tempArg;
      tempArg = getRegString(arg2);
      if (tempArg != CSequenceGeneratorDoc::nullString)
      {
        tempString += "," + tempArg;
        tempArg = getRegString(arg3);
        if (tempArg != CSequenceGeneratorDoc::nullString)
        {
          tempString += "," + tempArg;
          tempArg = getRegString(arg4);
          if (tempArg != CSequenceGeneratorDoc::nullString)
          {
            tempString += "," + tempArg;
          }
        }
      }
    }
  }
  
  return tempString;
}
