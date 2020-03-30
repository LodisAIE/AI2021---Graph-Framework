#include "Seek.h"


SeekForce::SeekForce()
{
}

SeekForce::~SeekForce()
{
}

void SeekForce::SetTarget(Agent * agent)
{
	m_target = agent;
}

Vector2 SeekForce::GetForce(Agent * agent)
{
	Vector2 Force = { 0,0 };
	if (!agent)
	{
		return Force;
	}
	Vector2 agentPos = agent->GetPosition();
	Vector2 targetPos = m_target->GetPosition();
	Force = targetPos - agentPos;
	if (Force.Magnitude() > agent->maxForce)
	{
		Force = Force.Normalize();
		Force = (Force * agent->maxForce) - agent->GetVelocity();
	}
	
	return Force;
}

