// SequenceJumpImmdClass.h: interface for the SequenceJumpImmdClass class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SEQUENCEJUMPIMMDCLASS_H__540978DE_7D15_11D5_8C74_00C04F556625__INCLUDED_)
#define AFX_SEQUENCEJUMPIMMDCLASS_H__540978DE_7D15_11D5_8C74_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SequenceJumpClass.h"
#include "SequenceCommandBaseClass.h"	// Added by ClassView

class SequenceJumpImmdClass : public SequenceJumpClass  
{
public:
	void setSourceData(int data);
	void setDestinationRegister(RegisterType d_register);
	void setOffset(int offset_value);
	int getSourceData();
	RegisterType getDestinationRegister();
	int getOffset();
	SequenceJumpImmdClass();
	virtual ~SequenceJumpImmdClass();

private:
	int offset;
	RegisterType destination_register;
	int source_data;
};

#endif // !defined(AFX_SEQUENCEJUMPIMMDCLASS_H__540978DE_7D15_11D5_8C74_00C04F556625__INCLUDED_)
