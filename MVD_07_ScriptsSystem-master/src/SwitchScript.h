#pragma once
#include "ScriptSystem.h"
#include "MoveScript.h"


class SwitchScript :
	public Script
{
public:
	SwitchScript(int owner) : Script(owner) {}
	void update(float dt);
	void init(MoveScript* movingFloor);


	MoveScript* movingFloor_;
	//later add custom stuff;


};

