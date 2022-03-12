// SequenceJumpNonImmdClass.cpp: implementation of the SequenceJumpNonImmdClass class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "SequenceJumpNonImmdClass.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SequenceJumpNonImmdClass::SequenceJumpNonImmdClass()
{

}

SequenceJumpNonImmdClass::~SequenceJumpNonImmdClass()
{

}



int SequenceJumpNonImmdClass::getOffset()
{
	return offset;
}

void SequenceJumpNonImmdClass::setOffset(int offset_num)
{
	offset = offset_num;
}

RegisterType SequenceJumpNonImmdClass::getSourceRegister()
{	
	return source_register;
}

RegisterType SequenceJumpNonImmdClass::getDestinationRegister()
{
	return destination_register;
}

void SequenceJumpNonImmdClass::setSourceRegister(RegisterType s_register)
{	
	source_register.ext = s_register.ext;
	source_register.num = s_register.num;
	source_register.source_type = s_register.source_type;

}

void SequenceJumpNonImmdClass::setDestinationRegister(RegisterType d_register)
{
	destination_register.ext = d_register.ext;
	destination_register.num = d_register.num;
	destination_register.source_type = d_register.source_type;

}
