#include "DecisionBehaviour.h"


void DecisionBehaviour::update(Agent * agent, float deltaTime)
{
	m_decision->makeDecision(agent, deltaTime);
}

DecisionBehaviour::DecisionBehaviour(Decision * decision)
{
	m_decision = decision;
}

DecisionBehaviour::DecisionBehaviour()
{
}
