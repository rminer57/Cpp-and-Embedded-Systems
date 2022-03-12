// SequenceJumpImmdClass.cpp: implementation of the SequenceJumpImmdClass class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "SequenceJumpImmdClass.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SequenceJumpImmdClass::SequenceJumpImmdClass()
{

}

SequenceJumpImmdClass::~SequenceJumpImmdClass()
{

}

int SequenceJumpImmdClass::getOffset()
{
	return offset;
}

RegisterType SequenceJumpImmdClass::getDestinationRegister()
{
	return destination_register;
}

int SequenceJumpImmdClass::getSourceData()
{
	return source_data;
}

void SequenceJumpImmdClass::setOffset(int offset_value)
{
	offset = offset_value;
}

void SequenceJumpImmdClass::setDestinationRegister(RegisterType d_register)
{
	destination_register.ext = d_register.ext;
	destination_register.num = d_register.num;
	destination_register.source_type = d_register.source_type;
}

void SequenceJumpImmdClass::setSourceData(int data)
{
	source_data = data;
}
