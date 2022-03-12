// SequenceMiscImmdClass.cpp: implementation of the SequenceMiscImmdClass class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "SequenceMiscImmdClass.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SequenceMiscImmdClass::SequenceMiscImmdClass()
{

}

SequenceMiscImmdClass::~SequenceMiscImmdClass()
{

}

int SequenceMiscImmdClass::getSourceData()
{
	return source_data;
}

void SequenceMiscImmdClass::setSourceData(int s_data)
{
	source_data = s_data;
}
