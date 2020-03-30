#include "KeyboardBehaviour.h"

KeyboardBehaviour::KeyboardBehaviour()
{
}

KeyboardBehaviour::~KeyboardBehaviour()
{
}


Vector2 KeyboardBehaviour::GetForce(Agent * agent)
{
	Vector2 force = { 0,0 };
	if (IsKeyDown(KEY_W))
	{
		force.y = -500;
	}
	if (IsKeyDown(KEY_S))
	{
		force.y = 500;
	}
	if (IsKeyDown(KEY_A))
	{
		force.x = -500;
	}
	if (IsKeyDown(KEY_D))
	{
		force.x = 500;
	}
	return force;
}
