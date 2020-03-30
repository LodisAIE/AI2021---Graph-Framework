#pragma once
#include "Behaviour.h"
class Condition : public Behaviour
{
public:
	Condition();
	virtual ~Condition();
	virtual bool test(Agent* agent) { return true; };
	virtual bool execute(Agent* agent, float deltatime)
	{
		if (test(agent))
		{
			return true;
		}
		return false;
	}
};