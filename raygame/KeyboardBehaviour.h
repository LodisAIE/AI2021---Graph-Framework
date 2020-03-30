#pragma once
#include "SteeringForce.h"
class KeyboardBehaviour : public SteeringForce
{
public:
	KeyboardBehaviour();
	virtual ~KeyboardBehaviour();
	Vector2 GetForce(Agent*agent) override;
};