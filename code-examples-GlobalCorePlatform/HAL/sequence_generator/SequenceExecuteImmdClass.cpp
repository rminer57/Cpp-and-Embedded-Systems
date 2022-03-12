// SequenceExecuteImmdClass.cpp: implementation of the SequenceExecuteImmdClass class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "SequenceExecuteImmdClass.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


SequenceExecuteImmdClass::SequenceExecuteImmdClass()
{

}

SequenceExecuteImmdClass::~SequenceExecuteImmdClass()
{

}


int SequenceExecuteImmdClass::getArguement()
{
	return arguement;
}

void SequenceExecuteImmdClass::setArguement(int arg)
{
	arguement = arg;
}
