#pragma once
#include "ScriptSystem.h"
#include "PaddleAI.h"
class MoveScript :
	public Script
{
public:
	MoveScript(int owner) : Script(owner) {}
	void update(float dt);
	void init(PaddleAI* paddleAI);
	float yspeed = 3.5;
	bool reset = false;
	PaddleAI* paddleai_;
};

