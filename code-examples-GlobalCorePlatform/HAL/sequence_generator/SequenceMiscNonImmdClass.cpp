// SequenceMiscNonImmdClass.cpp: implementation of the SequenceMiscNonImmdClass class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "SequenceMiscNonImmdClass.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SequenceMiscNonImmdClass::SequenceMiscNonImmdClass()
{

}

SequenceMiscNonImmdClass::~SequenceMiscNonImmdClass()
{

}

void SequenceMiscNonImmdClass::setSourceRegister(RegisterType s_register)
{
	source_register.ext = s_register.ext;
	source_register.num = s_register.num;
	source_register.source_type = s_register.source_type;
}

RegisterType SequenceMiscNonImmdClass::getSourceRegister()
{
	return source_register;
}
