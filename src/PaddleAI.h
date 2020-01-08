#pragma once
#include "extern.h"
#include "ScriptSystem.h"
//#include "BallMovement.h"

class PaddleAI :
	public Script
{
public:
	PaddleAI(int owner) : Script(owner){}
	void update(float dt);
	void sense(float CPUpos, float ballpos, float playerpos, float dt);
	void think(float CPUpos, float ballpos, float playerpos, float dt);
	void act(float yspeed, float dir, float dt);
    //void init(BallMovement* ballmovement);
	Transform* transform = &ECS.getComponentFromEntity<Transform>(owner_);
	float ypos = 0.0f;
	float yspeed = 2.0f;
//	BallMovement* ballmovement_;

};