// SequenceExecuteClass.h: interface for the SequenceExecuteClass class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SEQUENCEEXECUTECLASS_H__540978D5_7D15_11D5_8C74_00C04F556625__INCLUDED_)
#define AFX_SEQUENCEEXECUTECLASS_H__540978D5_7D15_11D5_8C74_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SequenceCommandBaseClass.h"
#include "SequenceGeneratorDoc.h"

class SequenceExecuteClass : public SequenceCommandBaseClass 
{
public:
  SequenceExecuteClass();
	virtual ~SequenceExecuteClass();

	// Data get/set functions
	int getComponent();
	void setComponent(int component_function);
	
  int getInterface();
	void setInterface(int exec_interface);
	
  void setReturnRegister(int retRegister);
	int getReturnRegister();

	//Execute Immediate function definitions:
  int getArguement();
	void setArguement(int arg);
	//Execute Non-Immediate function definitions:
  RegisterType getArg4();
	RegisterType getArg3();
	RegisterType getArg2();
	RegisterType getArg1();
	void SetArg4(RegisterType arg_4);
	void SetArg3(RegisterType arg_3);
	void SetArg2(RegisterType arg_2);
	void SetArg1(RegisterType arg_1);

	// Save function(s)
	virtual void Serialize(CArchive& ar);

  // String output functions
  CString toString();
  CString getReturnRegisterString();
  CString getDataString();


protected:
	int execute_interface;
	int component;
	int return_register;
	//Execute Immediate aguement(s):
	int arguement;
	//Execute Non-Immediate arguement(s):
	RegisterType arg4;
	RegisterType arg3;
	RegisterType arg2;
	RegisterType arg1;


};

#endif // !defined(AFX_SEQUENCEEXECUTECLASS_H__540978D5_7D15_11D5_8C74_00C04F556625__INCLUDED_)
