#include "SwitchScript.h"
#include "extern.h"


void SwitchScript::update(float dt)
{
	
	Collider& collider_down = ECS.getComponentFromEntity<Collider>(owner_);
	if (collider_down.colliding) {
		this->movingFloor_->shouldMove = true;
	}
	else {
		this->movingFloor_->shouldMove = false;
	}

}

void SwitchScript::init(MoveScript* movingFloor)
{
	this->movingFloor_ = movingFloor;
}
