#include "SteeringBehaviour.h"

SteeringBehaviour::SteeringBehaviour()
{
}

SteeringBehaviour::SteeringBehaviour(SteeringForce * steeringForce)
{
	steeringForceObject = steeringForce;
}

SteeringBehaviour::~SteeringBehaviour()
{
}

void SteeringBehaviour::execute(Agent* agent)
{
	force = steeringForceObject->GetForce(agent);
}

void SteeringBehaviour::update(Agent * agent, float deltatime)
{
	execute(agent);
	agent->AddForce(force);
}
