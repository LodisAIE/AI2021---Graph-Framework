#pragma once
#include "Decision.h"
#include "SteeringBehaviour.h"
class DecisionBehaviour : public SteeringBehaviour
{
private:
	Decision* m_decision;
public:
	virtual void update(Agent* agent, float deltaTime) override;
	DecisionBehaviour(Decision*);
	DecisionBehaviour();
};