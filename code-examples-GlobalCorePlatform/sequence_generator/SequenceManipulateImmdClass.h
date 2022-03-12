// SequenceManipulateImmdClass.h: interface for the SequenceManipulateImmdClass class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SEQUENCEMANIPULATEIMMDCLASS_H__540978D9_7D15_11D5_8C74_00C04F556625__INCLUDED_)
#define AFX_SEQUENCEMANIPULATEIMMDCLASS_H__540978D9_7D15_11D5_8C74_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SequenceManipulate.h"

class SequenceManipulateImmdClass : public SequenceManipulate  
{
public:
	void setArguement(int arg);
	int getArguement();
	SequenceManipulateImmdClass();
	virtual ~SequenceManipulateImmdClass();

private:
	int arguement;
};

#endif // !defined(AFX_SEQUENCEMANIPULATEIMMDCLASS_H__540978D9_7D15_11D5_8C74_00C04F556625__INCLUDED_)
