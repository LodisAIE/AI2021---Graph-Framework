#pragma once
#include "SteeringForce.h"
class FleeForce : public SteeringForce
{
public:
	Agent* target;
	FleeForce();
	virtual ~FleeForce();
	void SetTarget(Agent*agent);
	Vector2 GetForce(Agent*agent) override;
};
