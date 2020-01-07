#pragma once
#include "ScriptSystem.h"


class BallMovement :
	public Script
{
public:
	BallMovement(int owner) : Script(owner) {}
	void update(float dt);
	
	//OPTIONALLY override init
	void init();

	//add whatever custom funcitons and properties here!

};
