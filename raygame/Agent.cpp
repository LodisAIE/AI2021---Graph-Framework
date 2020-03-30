#include "Agent.h"
#include "SteeringBehaviour.h"
Agent::Agent()
{
	maxSpeed = 50;
	maxForce = 20;
}

Agent::~Agent()
{
}

void Agent::AddForce(Vector2 force)
{
	if (force.Magnitude() > maxForce)
	{
		force = force.Normalize();
		force = force * maxForce;
	}
	velocity += force;
}

void Agent::Update(float deltaTime)
{
	Vector2 Force;
	m_BehaviourList.size();
	for (std::vector<SteeringBehaviour*>::iterator iter = m_BehaviourList.begin(); iter != m_BehaviourList.end(); ++iter)
	{
		(*iter)->update(this, deltaTime);
		if (velocity.Magnitude() > maxSpeed)
		{
			velocity = velocity.Normalize() * maxSpeed;
		}
		position += (velocity*deltaTime);
	}
}

void Agent::Draw(Color color)
{
	DrawRectangle(position.x, position.y, 10, 10, color);
}

void Agent::SetPosition(Vector2 newPos)
{
	position = newPos;
}

Vector2 Agent::GetPosition()
{
	return position;
}

void Agent::SetVelocity(Vector2 newVelocity)
{
	velocity = newVelocity;
}

Vector2 Agent::GetVelocity()
{
	return velocity;
}

void Agent::ResetPosition()
{
	position.x = 400;
	position.y = 200;
}

void Agent::AddBehaviour(SteeringBehaviour * behaviour)
{
	m_BehaviourList.push_back(behaviour);
}
