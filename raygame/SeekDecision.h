#pragma once
#include"Decision.h"
#include "Seek.h"
class SeekDecision : public Decision
{
private:
	SeekForce seek;
public:
	void makeDecision(Agent*agent, float deltatime) override;
	SeekDecision(Agent*target);
	SeekDecision();
};