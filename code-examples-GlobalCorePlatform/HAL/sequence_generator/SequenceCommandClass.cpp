#include "SequenceCommandClass.h"



//SequenceCommandBase implementation

SequenceCommandBase::SequenceCommandBase()
{
    
}

SequenceCommandBase::~SequenceCommandBase()
{
    
}

int SequenceCommandBase::getOpcode()
{
    return opcode;
}


bool SequenceCommandBase::getImmediate()
{
    return immediate;
}


void SequenceCommandBase::setOpcode(int operation)
{
    opcode = operation; 
}


void SequenceCommandBase::setImmediate(bool immd)
{
    immediate = immd;
}


/*
//SequenceExecute implementation
int SequenceExecute::getReturnRegister()
{
	return return_register;
}

int SequenceExecute::getComponent()
{
	return component;
}

int SequenceExecute::getInterface()
{
    return execute_interface;
}

void SequenceExecute::setReturnRegister(int retRegister)
{
	return_register = retRegister;
}
void SequenceExecute::setComponent(int component_function)
{
	component = component_function;
}

void SequenceExecute::setInterface(int exec_interface)
{
	execute_interface = exec_interface;
}

//SequenceExecuteImmd implementation
int SequenceExecuteImmd::getArguement()
{
	return arguement;
}

void SequenceExecuteImmd::setArguement(int arg)
{
	arguement = arg;
}


//SequenceExecuteNonImmd implementation

RegisterType SequenceExecuteNonImmd::getArg1()
{
	return arg1;
}

RegisterType SequenceExecuteNonImmd::getArg2()
{
	return arg2;
}

RegisterType SequenceExecuteNonImmd::getArg3()
{
	return arg3;
}

RegisterType SequenceExecuteNonImmd::getArg4()
{
	return arg4;
}

void SequenceExecuteNonImmd::SetArg1(RegisterType arg_1)
{
	arg1.ext = arg_1.ext;
	arg1.num = arg_1.num;
	arg1.source_type = arg_1.source_type;
}

void SequenceExecuteNonImmd::SetArg2(RegisterType arg_2)
{
	arg2.ext = arg_2.ext;
	arg2.num = arg_2.num;
	arg2.source_type = arg_2.source_type;
}

void SequenceExecuteNonImmd::SetArg3(RegisterType arg_3)
{
	arg3.ext = arg_3.ext;
	arg3.num = arg_3.num;
	arg3.source_type = arg_3.source_type;
}

void SequenceExecuteNonImmd::SetArg4(RegisterType arg_4)
{
	arg4.ext = arg_4.ext;
	arg4.num = arg_4.num;
	arg4.source_type = arg_4.source_type;
}*/
