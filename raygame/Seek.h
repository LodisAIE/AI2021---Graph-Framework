#pragma once
#include "SteeringForce.h"
class SeekForce : public SteeringForce
{
private:
	Agent* m_target;
public:
	SeekForce();
	virtual ~SeekForce();
	void SetTarget(Agent*agent);
	Vector2 GetForce(Agent*agent) override;
};