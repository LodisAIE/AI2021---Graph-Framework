#pragma once
#include "Agent.h"
class Behaviour
{
public:
	Behaviour();
	virtual ~Behaviour();
	virtual void update(Agent* agent, float deltaTime) {};
};