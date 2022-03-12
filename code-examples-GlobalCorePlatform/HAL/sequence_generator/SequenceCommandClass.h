//#include <afx.h>
#ifndef SEQUENCE_COMMAND_CLASS_H
#define SEQUENCE_COMMAND_CLASS_H 1

//User defined struct
struct RegisterType
{
	bool source_type;
	int ext;
	int num;
};


//User defined sequence data storage classes

//Sequence Command Base Class
class SequenceCommandBase //: public CObject
{
	protected:
		int opcode;
		bool immediate;
	public:
		SequenceCommandBase();
		~SequenceCommandBase();
		int getOpcode();
		bool getImmediate();
		void setOpcode(int operation);
		void setImmediate(bool immd);

};


//Execute Classes
class SequenceExecute : public SequenceCommandBase
{
	protected:
		int return_register;
		int component;
		int execute_interface;
	public:
		int getReturnRegister();
		int getComponent();
		int getInterface();
		void setReturnRegister(int retRegister);
		void setComponent(int component_function);
		void setInterface(int exec_interface);

};


class SequenceExecuteImmd : public SequenceExecute
{	
	private:
		int arguement;
	public:
		int getArguement();
		void setArguement(int arg);

};

class SequenceExecuteNonImmd : public SequenceExecute
{
	private:
		RegisterType arg1;
		RegisterType arg2;
		RegisterType arg3;
		RegisterType arg4;
	public:
		RegisterType getArg1();
		RegisterType getArg2();
		RegisterType getArg3();
		RegisterType getArg4();
		void SetArg1(RegisterType arg_1);
		void SetArg2(RegisterType arg_2);
		void SetArg3(RegisterType arg_3);
		void SetArg4(RegisterType arg_4);

};


#endif