#pragma once
#include "ScriptSystem.h"
#include "BallMovement.h"
class LightMovement :
	public Script
{
public:
	LightMovement(int owner) : Script(owner) {}
	void update(float dt);
	float xpos;
	float ypos;
	
};

