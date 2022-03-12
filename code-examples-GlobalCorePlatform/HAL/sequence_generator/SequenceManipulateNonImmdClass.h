// SequenceManipulateNonImmdClass.h: interface for the SequenceManipulateNonImmdClass class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SEQUENCEMANIPULATENONIMMDCLASS_H__540978DD_7D15_11D5_8C74_00C04F556625__INCLUDED_)
#define AFX_SEQUENCEMANIPULATENONIMMDCLASS_H__540978DD_7D15_11D5_8C74_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SequenceManipulate.h"
#include "RegisterType.h"	// Added by ClassView
#include "SequenceCommandBaseClass.h"	// Added by ClassView

class SequenceManipulateNonImmdClass : public SequenceManipulate  
{
public:
	RegisterType getSourceRegister();
	void setSourceRegister(RegisterType source_reg);
	SequenceManipulateNonImmdClass();
	virtual ~SequenceManipulateNonImmdClass();


private:
	RegisterType arg1;

};

#endif // !defined(AFX_SEQUENCEMANIPULATENONIMMDCLASS_H__540978DD_7D15_11D5_8C74_00C04F556625__INCLUDED_)
