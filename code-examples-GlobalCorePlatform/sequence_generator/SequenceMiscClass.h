// SequenceMiscClass.h: interface for the SequenceMiscClass class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SEQUENCEMISCCLASS_H__540978E0_7D15_11D5_8C74_00C04F556625__INCLUDED_)
#define AFX_SEQUENCEMISCCLASS_H__540978E0_7D15_11D5_8C74_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SequenceCommandBaseClass.h"

class SequenceMiscClass : public SequenceCommandBaseClass  
{
public:
	SequenceMiscClass();
	virtual ~SequenceMiscClass();
  
  // get/set data functions
  int getOperation();
	void setOperation(int op_num);
	//Misc Immediate function definitions:
	int getSourceData();
  void setSourceData(int s_data);
	//Misc Non-Immediate function definitions:
	RegisterType getSourceRegister();
	void setSourceRegister(RegisterType s_register);

	//Override Serialize method:
	virtual void Serialize(CArchive& ar);

  CString toString();
  CString getOperationString();
  CString getArgString();

protected:
	int operation;
	//Misc Immediate member variables:
	int source_data;
	//Misc Non-Immediate member variable:
	RegisterType source_register;

private:
  static const CString miscStrings[16];
};

#endif // !defined(AFX_SEQUENCEMISCCLASS_H__540978E0_7D15_11D5_8C74_00C04F556625__INCLUDED_)
