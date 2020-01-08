#pragma once
#include "ScriptSystem.h"

class MoveScript :
	public Script
{
public:
	MoveScript(int owner) : Script(owner) {}
	void update(float dt);
	float yspeed = 3;
	//void init();

	//later add custom stuff;

	//bool shouldMove = false;

};

