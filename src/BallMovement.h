#pragma once
#include "ScriptSystem.h"
#include "PaddleAI.h"

class BallMovement :
	public Script
{
public:
	BallMovement(int owner) : Script(owner) {}
	void update(float dt);
	void init(PaddleAI* paddleAI);
	//OPTIONALLY override init
	
	float y_pos = 3.0f;
	float xspeed = 3.0f;
	float yspeed = 3.0f;
	PaddleAI* paddleai_;
	//add whatever custom funcitons and properties here!

};
