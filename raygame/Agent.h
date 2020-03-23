#pragma once
#include "raylib.h"
class Agent
{
protected:
	Vector2 position;
	Vector2 velocity;
public:
	void Update(float deltaTime);
	void Draw();
	void SetPosition(Vector2 position);
	Vector2 GetPosition();
	void SetVelocity(Vector2 velocity);
	Vector2 GetVelocity();
};