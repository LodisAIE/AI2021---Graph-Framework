/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/
#include "Agent.h"
#include "KeyboardBehaviour.h"
#include "Seek.h"
#include "raylib.h"
#include "SteeringBehaviour.h"
#include "Flee.h"
#include "Wander.h"
#include "SeekDecision.h"
#include "WanderDecision.h"
#include "DecisionBehaviour.h"
int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;
	//initialize agents
	Agent* player;
	Agent* enemy;
	Vector2 playerpos;
	playerpos.x = 0;
	playerpos.y = 0;
	Vector2 enemyPos;
	enemyPos.x = 400;
	enemyPos.y = 200;
	//AI Behaviour test
	////intialize forces
	//KeyboardBehaviour* inputForce;
	//SteeringBehaviour* inputBehaviour;
	//SteeringBehaviour* seekBehaviour;
	//WanderForce* steeringForce;
	//
	//
	//player = new Agent();
	//player->SetPosition(playerpos);
	//inputForce = new KeyboardBehaviour();
	//inputBehaviour = new SteeringBehaviour(inputForce);
	//player->AddBehaviour(inputBehaviour);

	//enemy = new Agent();
	//enemy->SetPosition(enemyPos);
	//steeringForce = new WanderForce();
	////steeringForce->SetTarget(player);
	//seekBehaviour = new SteeringBehaviour(steeringForce);
	//enemy->AddBehaviour(seekBehaviour);

	//Decision Tree Test
	player = new Agent();
	KeyboardBehaviour* inputForce;
	SteeringBehaviour* inputBehaviour;
	SeekDecision*  seekDecision= new SeekDecision(player);
	WanderDecision* idleDecision = new WanderDecision();
	WanderDecision* wanderDecision = new WanderDecision();
	wanderDecision = new WanderDecision(player, seekDecision, nullptr);
	DecisionBehaviour* decisionBehaviour = new DecisionBehaviour(wanderDecision);
	
	player->SetPosition(playerpos);
	inputForce = new KeyboardBehaviour();
	inputBehaviour = new SteeringBehaviour(inputForce);
	player->AddBehaviour(inputBehaviour);
	
	enemy = new Agent();
	enemy->SetPosition(enemyPos);
	enemy->AddBehaviour(decisionBehaviour);
	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------
	float deltaTime;
	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		deltaTime = GetFrameTime();
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------
		player->Update(deltaTime);
		enemy->Update(deltaTime);
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
		player->Draw(RED);
		enemy->Draw(BLUE);
		ClearBackground(BLACK);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}