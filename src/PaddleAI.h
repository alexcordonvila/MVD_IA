#pragma once
#include "ScriptSystem.h"
//#include "BallMovement.h"

class PaddleAI :
	public Script
{
public:
	PaddleAI(int owner) : Script(owner){}
	void update(float dt);
    //void init(BallMovement* ballmovement);
	
	float ypos = 0;
//	BallMovement* ballmovement_;

};