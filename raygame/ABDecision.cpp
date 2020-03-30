#include "ABDecision.h"

void ABDecision::makeDecision(Agent* agent, float deltatime)
{
	if (checkCondition(agent, deltatime))
	{
		if (A)
		{
			A->makeDecision(agent, deltatime);
		}	
	}
	else
	{
		if (B)
		{
			B->makeDecision(agent, deltatime);
		}
		
	}
}

bool ABDecision::checkCondition(Agent* agent, float deltatime)
{
	return false;
}

ABDecision::ABDecision()
{
}

ABDecision::ABDecision(Decision* child1, Decision* child2)
{
	A = child1;
	B = child2;
}
