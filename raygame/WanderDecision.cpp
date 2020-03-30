#include "WanderDecision.h"

void WanderDecision::makeDecision(Agent * agent, float deltatime)
{
	agent->AddForce(wander.GetForce(agent));
	ABDecision::makeDecision(agent, deltatime);
}

bool WanderDecision::checkCondition(Agent * agent, float deltatime)
{
	Vector2 distanceVec = targetAgent->GetPosition() - agent->GetPosition();
	if (distanceVec.Magnitude() < 20)
	{
		return true;
	}
	return false;
}

WanderDecision::WanderDecision(Agent * target,Decision* child1,Decision* child2) : ABDecision(child1,child2)
{
	targetAgent = target;
}

WanderDecision::WanderDecision()
{
}
