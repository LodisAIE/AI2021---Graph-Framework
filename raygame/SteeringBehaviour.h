#pragma once
#include "SteeringForce.h"
#include "Behaviour.h"

class SteeringBehaviour : public Behaviour
{
public:
	SteeringBehaviour();
	SteeringBehaviour(SteeringForce* steeringForce);
	~SteeringBehaviour() override;
	SteeringForce* steeringForceObject;
	Vector2 force;
	void execute(Agent * agent);
	void update(Agent* agent, float deltatime) override;
};