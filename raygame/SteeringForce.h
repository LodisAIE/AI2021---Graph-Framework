#pragma once
#include "Agent.h"
class SteeringForce
{
public:
	virtual Vector2 GetForce(Agent* agent) = 0;

};