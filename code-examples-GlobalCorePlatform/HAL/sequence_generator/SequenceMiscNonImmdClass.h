// SequenceMiscNonImmdClass.h: interface for the SequenceMiscNonImmdClass class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SEQUENCEMISCNONIMMDCLASS_H__540978E2_7D15_11D5_8C74_00C04F556625__INCLUDED_)
#define AFX_SEQUENCEMISCNONIMMDCLASS_H__540978E2_7D15_11D5_8C74_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SequenceMiscClass.h"
#include "SequenceCommandBaseClass.h"	// Added by ClassView

class SequenceMiscNonImmdClass : public SequenceMiscClass  
{
public:
	RegisterType getSourceRegister();
	void setSourceRegister(RegisterType s_register);
	SequenceMiscNonImmdClass();
	virtual ~SequenceMiscNonImmdClass();

private:
	RegisterType source_register;
};

#endif // !defined(AFX_SEQUENCEMISCNONIMMDCLASS_H__540978E2_7D15_11D5_8C74_00C04F556625__INCLUDED_)
