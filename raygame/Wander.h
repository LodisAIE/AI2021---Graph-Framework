#pragma once
#include "SteeringForce.h"
class WanderForce : public SteeringForce
{
private:
	Vector2 oldDisplacement;
	float GetRandomFloat(float min, float max);
	Vector2 GetAngle(Vector2 displacement, float wanderAngle);
public:
	WanderForce();
	virtual ~WanderForce();
	Vector2 GetForce(Agent*agent) override;
};