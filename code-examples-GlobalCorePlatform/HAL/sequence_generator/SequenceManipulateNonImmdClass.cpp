// SequenceManipulateNonImmdClass.cpp: implementation of the SequenceManipulateNonImmdClass class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "SequenceManipulateNonImmdClass.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SequenceManipulateNonImmdClass::SequenceManipulateNonImmdClass()
{

}

SequenceManipulateNonImmdClass::~SequenceManipulateNonImmdClass()
{

}

void SequenceManipulateNonImmdClass::setSourceRegister(RegisterType source_reg)
{
	arg1.ext = source_reg.ext;
	arg1.num = source_reg.num;
	arg1.source_type = source_reg.source_type;
}

RegisterType SequenceManipulateNonImmdClass::getSourceRegister()
{
	return arg1;

}
