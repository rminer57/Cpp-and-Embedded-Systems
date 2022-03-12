// SequenceExecuteImmdClass.h: interface for the SequenceExecuteImmdClass class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SEQUENCEEXECUTEIMMDCLASS_H__540978D6_7D15_11D5_8C74_00C04F556625__INCLUDED_)
#define AFX_SEQUENCEEXECUTEIMMDCLASS_H__540978D6_7D15_11D5_8C74_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SequenceExecuteClass.h"

class SequenceExecuteImmdClass : public SequenceExecuteClass  
{
public:
	void setArguement(int arg);
	int getArguement();
	SequenceExecuteImmdClass();
	virtual ~SequenceExecuteImmdClass();

private:
	int arguement;
};

#endif // !defined(AFX_SEQUENCEEXECUTEIMMDCLASS_H__540978D6_7D15_11D5_8C74_00C04F556625__INCLUDED_)
