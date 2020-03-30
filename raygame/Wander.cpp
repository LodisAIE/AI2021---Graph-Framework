#include "Wander.h"
#include <time.h>
float WanderForce::GetRandomFloat(float min, float max)
{
	
	float random = (float)(rand() / (float)(RAND_MAX));
	float diff = max - min;
	float randDifference = random * diff;
	return min + randDifference;
}
Vector2 WanderForce::GetAngle(Vector2 displacement, float wanderAngle)
{
	displacement.x = cos(wanderAngle);
	displacement.y = sin(wanderAngle);
	return displacement;
}
WanderForce::WanderForce()
{
	srand(time(NULL));
}

WanderForce::~WanderForce()
{
}

Vector2 WanderForce::GetForce(Agent * agent)
{
	float randAngle = GetRandomFloat(-270, 270);
	float radius = 5;
	Vector2 displacement = { 0,-1 };
	displacement = displacement * radius;
	displacement = GetAngle(displacement, randAngle);
	Vector2 agentVelocity = agent->GetVelocity();
	Vector2 circleCenter;
	float distance = 1;
	if (agent->GetVelocity().Magnitude() == 0)
	{
		circleCenter = agent->GetPosition().Normalize()* distance;
	}
	else
	{
		circleCenter = agentVelocity.Normalize()*distance;
	}
	if (displacement == oldDisplacement)
	{
		GetForce(agent);
	}
	else
	{
		oldDisplacement = displacement;
	}
	displacement = displacement * radius;
	Vector2 wanderForce = displacement + circleCenter;
	if (wanderForce.Magnitude() > agent->maxForce)
	{
		wanderForce = wanderForce.Normalize();
		wanderForce = (wanderForce * agent->maxForce) - agent->GetVelocity();
	}
	if (agent->GetPosition().x >= 800 || agent->GetPosition().x <= 0 || agent->GetPosition().y <= 0 || agent->GetPosition().y >= 450)
	{
		agent->ResetPosition();
	}
	return wanderForce;
}
