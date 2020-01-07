#include "BallMovement.h"
#include "extern.h"
float xspeed = 3;
float yspeed = 3;
bool hitFlag = true;
//Ball movement script
void BallMovement::update(float dt)
{
	
	Collider& collider_paddle = ECS.getComponentFromEntity<Collider>(owner_);
	Transform* transform;
	transform = &ECS.getComponentFromEntity<Transform>(owner_);
	printf("%f \n", collider_paddle.collision_distance);
	
	transform->translate(xspeed * dt, yspeed * dt, 0);
	if (input_->GetKey(GLFW_KEY_Z))
		transform->translate(-1 * dt, 0, 0);
	if (input_->GetKey(GLFW_KEY_X))
		transform->translate(1 * dt, 0, 0);

	if (collider_paddle.collision_distance < 1.0f && hitFlag == true) {
		printf("Choque Bola!! \n");
		xspeed = xspeed * -1;
		hitFlag = false;
	}
	else {
		//printf("No Choque Bola!! \n");
	}
	if (transform->position().x >3 || transform->position().x < -7) {
		xspeed = xspeed * -1;
		hitFlag = true;
		//printf("XSpeed= %f \n", xspeed);
		transform->position(-2.0f,3.0f,-10.0f);
	}
	if (transform->position().y > 7 || transform->position().y < 0) {
		yspeed = yspeed * -1;
		//transform->position(-2.0f, 3.0f, -10.0f);
	}

	
}

void BallMovement::init()
{

}