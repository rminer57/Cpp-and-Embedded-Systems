// SequenceManipulate.h: interface for the SequenceManipulate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SEQUENCEMANIPULATE_H__540978D8_7D15_11D5_8C74_00C04F556625__INCLUDED_)
#define AFX_SEQUENCEMANIPULATE_H__540978D8_7D15_11D5_8C74_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SequenceCommandBaseClass.h"

class SequenceManipulate : public SequenceCommandBaseClass  
{
public:
  SequenceManipulate();
	virtual ~SequenceManipulate();

  // get/set data functions
  RegisterType getDestinationRegister();
	void setDestinationRegister(RegisterType d_register);
  int getOperation();
	void setOperation(int op_num);	

	//Manipulate Immediate function definitions:
	void setArguement(int arg);
	int getArguement();
	//Manipulate Non-Immediate function definitons:
	RegisterType getSourceRegister();
	void setSourceRegister(RegisterType source_reg);

	//Override Serialize method:
	virtual void Serialize(CArchive& ar);

  // String output functions
  CString toString();
  CString getOperationString();
  CString getDestinationString();
  CString getSourceString();

protected:
	RegisterType destination_register;
	int operation;
	//Manipulate Immediate arguements:
	int arguement;
	//Manipulate Non-Immediate arguements:
	RegisterType arg1;

  // String of operation names
  static const CString operationStrings[16];

};

#endif // !defined(AFX_SEQUENCEMANIPULATE_H__540978D8_7D15_11D5_8C74_00C04F556625__INCLUDED_)
