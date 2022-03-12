#include "statemachine.h"

const int StateMachineAction::NO_CHANGE = 0xFFFFFFFF;	//No state change

int StateMachineAction::def(StateMachineActionData *data,int count)
{
	return NO_CHANGE;
}

StateMachine::StateMachine(Action **t,int ns,int ne,int s) : table(t),
	numState(ns),numEvents(ne),state(s)
{
}

//Execute
int StateMachine::execute(int event,StateMachineActionData *s,int c)
{
	int temp;
	Action *tempAct = table[state*numEvents + event];

	//If a handler exists
	if (((int)tempAct & DIRECT_STATE) != DIRECT_STATE)
	{
		//Invoke handler
		temp = tempAct(s,c);
		state = (temp != StateMachineAction::NO_CHANGE)?temp:state;
	}
	else
	{
		//Directly go to given state
		state = (int)tempAct == NO_CHANGE ? state:(int)tempAct & (~DIRECT_STATE);
	}

	return state;
}


const int StateMachine::NO_CHANGE = 0xFFFFFFFF;				//No state change
const int StateMachine::DIRECT_STATE = 0xFFFF0000;			//Direct state change
