// SequenceManipulateImmdClass.cpp: implementation of the SequenceManipulateImmdClass class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "SequenceManipulateImmdClass.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SequenceManipulateImmdClass::SequenceManipulateImmdClass()
{

}

SequenceManipulateImmdClass::~SequenceManipulateImmdClass()
{

}

int SequenceManipulateImmdClass::getArguement()
{
	return arguement;
}

void SequenceManipulateImmdClass::setArguement(int arg)
{
	arguement = arg;
}
