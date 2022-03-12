// SequenceExecuteNonImmdClass.h: interface for the SequenceExecuteNonImmdClass class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SEQUENCEEXECUTENONIMMDCLASS_H__540978D7_7D15_11D5_8C74_00C04F556625__INCLUDED_)
#define AFX_SEQUENCEEXECUTENONIMMDCLASS_H__540978D7_7D15_11D5_8C74_00C04F556625__INCLUDED_

#include "RegisterType.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SequenceExecuteClass.h"

class SequenceExecuteNonImmdClass : public SequenceExecuteClass  
{
public:
	void SetArg4(RegisterType arg_4);
	void SetArg3(RegisterType arg_3);
	void SetArg2(RegisterType arg_2);
	void SetArg1(RegisterType arg_1);
	RegisterType getArg4();
	RegisterType getArg3();
	RegisterType getArg2();
	RegisterType getArg1();

	SequenceExecuteNonImmdClass();
	virtual ~SequenceExecuteNonImmdClass();

private:
	RegisterType arg4;
	RegisterType arg3;
	RegisterType arg2;
	RegisterType arg1;

};

#endif // !defined(AFX_SEQUENCEEXECUTENONIMMDCLASS_H__540978D7_7D15_11D5_8C74_00C04F556625__INCLUDED_)
