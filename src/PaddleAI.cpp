#include "PaddleAI.h"
#include "extern.h"

void PaddleAI::update(float dt)
{

	Transform* transform;
	transform = &ECS.getComponentFromEntity<Transform>(owner_);
	transform->translate(0, ypos * dt, 0);

	transform->position(transform->position().x,
		ypos,
		transform->position().z);
	//if (collider_down.colliding) {
	//	//this->movingFloor_->shouldMove = true;
	//	printf("Paddle Collision \n");
	//}
	//else {
	//	//this->movingFloor_->shouldMove = false;
	//}

}

//void PaddleAI::init(BallMovement* ballmovement)
//{
//	this->ballmovement_ = ballmovement;
//}