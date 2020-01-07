#include "BallMovement.h"
#include "extern.h"
//float xspeed = 3;
//float yspeed = 3;
bool hitFlag = true;
//Ball movement script
void BallMovement::update(float dt)
{
	
	Collider& collider_paddle = ECS.getComponentFromEntity<Collider>(owner_);
	Transform* transform;
	transform = &ECS.getComponentFromEntity<Transform>(owner_);

	y_pos = transform->position().y;
	transform->translate(xspeed * dt, yspeed * dt, 0);
	this->paddleai_->ypos = transform->position().y;
	if (input_->GetKey(GLFW_KEY_Z))
		//transform->translate(-1 * dt, 0, 0);
		transform->translate(0, -1 * dt, 0);
	if (input_->GetKey(GLFW_KEY_X))
		//transform->translate(1 * dt, 0, 0);
		transform->translate(0, 1 * dt, 0);

	if (collider_paddle.collision_distance < 1.0f && hitFlag == true) {
		
		xspeed = xspeed * -1;
		hitFlag = false;
	}
	else {
		//printf("No Choque Bola!! \n");
	}
	//Cuando la bola passa por la zona central reseteamos el hitflag
	if (transform->position().x > -4 && transform->position().x < 0) {
		hitFlag = true;
	}
	if (transform->position().x >3 || transform->position().x < -7) {
		xspeed = xspeed * -1;
		//printf("XSpeed= %f \n", xspeed);
		transform->position(-2.0f,3.0f,-10.0f);
	}
	if (transform->position().y > 7 || transform->position().y < 0) {
		yspeed = yspeed * -1;
		//transform->position(-2.0f, 3.0f, -10.0f);
	}

	
}

void BallMovement::init(PaddleAI* paddleai_)
{
	this->paddleai_ = paddleai_;
}