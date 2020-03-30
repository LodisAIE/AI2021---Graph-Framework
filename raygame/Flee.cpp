#include "Flee.h"


FleeForce::FleeForce()
{
}

FleeForce::~FleeForce()
{
}

void FleeForce::SetTarget(Agent * agent)
{
	target = agent;
}

Vector2 FleeForce::GetForce(Agent * agent)
{
	Vector2 Force = { 0,0 };
	if (!agent)
	{
		return Force;
	}
	Vector2 agentPos = agent->GetPosition();
	Vector2 targetPos = target->GetPosition();
	Force = agentPos - targetPos ;
	Force = Force.Normalize();
	Force = (Force * agent->maxForce) - agent->GetVelocity();
	return Force;
}
