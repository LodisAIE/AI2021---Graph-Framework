#pragma once
#include"ABDecision.h"
#include "Wander.h"
class WanderDecision : public ABDecision
{
private:
	WanderForce wander;
	Agent* targetAgent;
public:
	void makeDecision(Agent*agent, float deltatime);
	bool checkCondition(Agent* agent, float deltatime)override;
	WanderDecision(Agent*target,Decision* child1,Decision* child2);
	WanderDecision();
};