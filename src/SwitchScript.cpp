#include "SwitchScript.h"
#include "extern.h"


void SwitchScript::update(float dt)
{
	
	Collider& collider_down = ECS.getComponentFromEntity<Collider>(owner_);
	//this->movingFloor_->
	if (collider_down.colliding) {
		//this->movingFloor_->shouldMove = true;
		printf("Paddle Collision \n");
	}
	else {
		//this->movingFloor_->shouldMove = false;
	}

}

void SwitchScript::init(MoveScript* movingFloor)
{
	this->movingFloor_ = movingFloor;
}
