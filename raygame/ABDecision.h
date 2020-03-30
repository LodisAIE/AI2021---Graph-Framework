#pragma once
#include "Condition.h"
#include "Decision.h"
class ABDecision : public Decision
{
private:
	Decision* A;
	Decision* B;
	virtual bool checkCondition(Agent * agent, float deltatime);
public:
	ABDecision();
	ABDecision(Decision* child1, Decision* child2);
	void makeDecision(Agent* agent, float deltatime) override;
};