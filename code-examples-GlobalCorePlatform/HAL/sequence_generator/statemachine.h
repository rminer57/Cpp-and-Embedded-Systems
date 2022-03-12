#ifndef CL_STATEMACHINE
#define CL_STATEMACHINE

#include <iostream.h>

//Base class for all data passed to actions
class StateMachineActionData
{
public:
	ostream *errStream;
};

typedef int (Action)(StateMachineActionData *data,int count);

//Base class for all actions
class StateMachineAction
{
public:
	StateMachineAction()							//Constructor
	{}

	static const int NO_CHANGE;

	//Returns new state number, or -1 for no change
	static int def(StateMachineActionData *data,int count = 0);
};

#define NO_STATE_CHANGE (Action *)StateMachine::NO_CHANGE
#define DIRECT_SC(x) (Action *)(StateMachine::DIRECT_STATE|x)

//Encapsulation of state machine
class StateMachine
{
private:
	int	state;
	int numState;
	int numEvents;
	Action **table;

public:
	static const int NO_CHANGE;
	static const int DIRECT_STATE;

	//Constructor
	StateMachine(Action **t,int ns,int ne,int s = 0);

	//Execute
	int execute(int event,StateMachineActionData *s = 0,int c = 0);
};


#endif