#pragma once
#include <vector>
#include "raylib.h"
class SteeringBehaviour;
class Agent
{
protected:
	Vector2 position;
	Vector2 velocity;
	
	std::vector<SteeringBehaviour*> m_BehaviourList;
public:
	float maxSpeed;
	float maxForce;
	Agent();
	virtual ~Agent();
	virtual void AddForce(Vector2 force);
	virtual void Update(float deltaTime);
	virtual void Draw(Color color);
	void SetPosition(Vector2 position);
	Vector2 GetPosition();
	void SetVelocity(Vector2 velocity);
	Vector2 GetVelocity();
	void ResetPosition();
	void AddBehaviour(SteeringBehaviour* behaviour);
};