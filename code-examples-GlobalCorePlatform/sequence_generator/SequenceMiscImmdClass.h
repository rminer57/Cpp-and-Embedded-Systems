// SequenceMiscImmdClass.h: interface for the SequenceMiscImmdClass class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SEQUENCEMISCIMMDCLASS_H__540978E1_7D15_11D5_8C74_00C04F556625__INCLUDED_)
#define AFX_SEQUENCEMISCIMMDCLASS_H__540978E1_7D15_11D5_8C74_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SequenceMiscClass.h"

class SequenceMiscImmdClass : public SequenceMiscClass  
{
public:
	void setSourceData(int s_data);
	int getSourceData();
	SequenceMiscImmdClass();
	virtual ~SequenceMiscImmdClass();

private:
	int source_data;
};

#endif // !defined(AFX_SEQUENCEMISCIMMDCLASS_H__540978E1_7D15_11D5_8C74_00C04F556625__INCLUDED_)
