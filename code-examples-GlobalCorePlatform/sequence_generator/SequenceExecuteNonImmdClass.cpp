// SequenceExecuteNonImmdClass.cpp: implementation of the SequenceExecuteNonImmdClass class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "SequenceExecuteNonImmdClass.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SequenceExecuteNonImmdClass::SequenceExecuteNonImmdClass()
{

}

SequenceExecuteNonImmdClass::~SequenceExecuteNonImmdClass()
{

}

RegisterType SequenceExecuteNonImmdClass::getArg1()
{
	return arg1;
}

RegisterType SequenceExecuteNonImmdClass::getArg2()
{
	return arg2;
}

RegisterType SequenceExecuteNonImmdClass::getArg3()
{
	return arg3;
}

RegisterType SequenceExecuteNonImmdClass::getArg4()
{
	return arg4;
}



void SequenceExecuteNonImmdClass::SetArg1(RegisterType arg_1)
{	
	arg1.ext = arg_1.ext;
	arg1.num = arg_1.num;
	arg1.source_type = arg_1.source_type;
}

void SequenceExecuteNonImmdClass::SetArg2(RegisterType arg_2)
{
	arg2.ext = arg_2.ext;
	arg2.num = arg_2.num;
	arg2.source_type = arg_2.source_type;
}

void SequenceExecuteNonImmdClass::SetArg3(RegisterType arg_3)
{
	arg3.ext = arg_3.ext;
	arg3.num = arg_3.num;
	arg3.source_type = arg_3.source_type;
}

void SequenceExecuteNonImmdClass::SetArg4(RegisterType arg_4)
{
	arg4.ext = arg_4.ext;
	arg4.num = arg_4.num;
	arg4.source_type = arg_4.source_type;
}
