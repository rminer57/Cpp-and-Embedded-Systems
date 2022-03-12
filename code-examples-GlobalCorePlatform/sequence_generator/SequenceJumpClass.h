// SequenceJumpClass.h: interface for the SequenceJumpClass class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SEQUENCEJUMPCLASS_H__540978DB_7D15_11D5_8C74_00C04F556625__INCLUDED_)
#define AFX_SEQUENCEJUMPCLASS_H__540978DB_7D15_11D5_8C74_00C04F556625__INCLUDED_

#include "RegisterType.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SequenceCommandBaseClass.h"

class SequenceJumpClass : public SequenceCommandBaseClass  
{
public:
  // Constructor/Destructor
  SequenceJumpClass();
	virtual ~SequenceJumpClass();

  // Get/Set data functions
  RegisterType getOperand1();
	void setOperand1(RegisterType s_register);

  int getComparison();
	void setComparison(int comp);
	
  RegisterType getDOffsetRegister();
	void setDOffsetRegister(RegisterType d_register);
	
  int getOffset();
  void setOffset(int offset_num);
	
	//Jump Immediate function definitions:
	int getImmediateOperand2();
	void setImmediateOperand2(int data);
	
	//Jump Non-Immediate function definitions:
	RegisterType getNonImmdOperand2();
	void setNonImmdOperand2(RegisterType s_register2);

	//Override Serialize method:
	virtual void Serialize(CArchive& ar);

  //String output functions
  CString toString();
  CString getComparisonString();
  CString getComparisonCommandString();
  CString getOperand1String();
  CString getOperand2String();
  CString getDestOffString();
  CString getOffsetString();
  CString getOffsetRegisterString();

protected:
	int comparison;
  RegisterType operand1;
	int immd_operand2;              //immediate operand
	RegisterType non_immd_operand2; //non-immediate operand
  int offset;
	RegisterType d_offset_register;

  CString destinationLabel;
	
private:
  static const CString comparisonStrings[16];
  static const CString comparisonCommandStrings[16];
};

#endif // !defined(AFX_SEQUENCEJUMPCLASS_H__540978DB_7D15_11D5_8C74_00C04F556625__INCLUDED_)
