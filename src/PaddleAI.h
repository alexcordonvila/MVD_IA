#pragma once
#include "extern.h"
#include "ScriptSystem.h"
#include <time.h> 
//#include "MoveScript.h"

class PaddleAI :
	public Script
{
public:
	PaddleAI(int owner) : Script(owner){}
	void update(float dt);
	void sense(float CPUpos, float ballpos, float playerpos, float dt);
	void think(float CPUpos, float ballpos, float playerpos, float dt);
	void act(float yspeed, float dir, float dt);
	void act2(float yspeed, int zone, float CPUpos, float ballpos,  float dt);
  //  void init(MoveScript* ballmovement);
	Transform* transform = &ECS.getComponentFromEntity<Transform>(owner_);
	float ypos = 0.0f; //This is the y position of the puck
	float y_player_pos = 0.0f; //This is the y position of the player
	float yspeed = 3.5f; //This is the y speed of the AI 
	float cpu_player_dist = 0.0f; // Y distance difference between cpu and player
	float random_val;
	int ball_direction = 1;
	bool reset = false;
	//MoveScript* movescript_;
};