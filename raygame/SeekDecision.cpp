#include "SeekDecision.h"

void SeekDecision::makeDecision(Agent * agent, float deltatime)
{
	agent->AddForce(seek.GetForce(agent));
}

SeekDecision::SeekDecision(Agent * target)
{
	seek.SetTarget(target);
}

SeekDecision::SeekDecision()
{
}
