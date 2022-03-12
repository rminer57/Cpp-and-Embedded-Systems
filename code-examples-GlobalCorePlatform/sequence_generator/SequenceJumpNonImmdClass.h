// SequenceJumpNonImmdClass.h: interface for the SequenceJumpNonImmdClass class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SEQUENCEJUMPNONIMMDCLASS_H__540978DF_7D15_11D5_8C74_00C04F556625__INCLUDED_)
#define AFX_SEQUENCEJUMPNONIMMDCLASS_H__540978DF_7D15_11D5_8C74_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SequenceJumpClass.h"
#include "SequenceCommandBaseClass.h"	// Added by ClassView

class SequenceJumpNonImmdClass : public SequenceJumpClass  
{
public:
	void setDestinationRegister(RegisterType d_register);
	void setSourceRegister(RegisterType  s_register);
	RegisterType getDestinationRegister();
	RegisterType getSourceRegister();
	void setOffset(int offset_num);
	int getOffset();
	SequenceJumpNonImmdClass();
	virtual ~SequenceJumpNonImmdClass();

private:
	int offset;
	RegisterType destination_register;
	RegisterType source_register2;
};

#endif // !defined(AFX_SEQUENCEJUMPNONIMMDCLASS_H__540978DF_7D15_11D5_8C74_00C04F556625__INCLUDED_)
