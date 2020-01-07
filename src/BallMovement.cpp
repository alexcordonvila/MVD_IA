#include "BallMovement.h"
#include "extern.h"
float xspeed = 1;
float yspeed = 1;
void BallMovement::update(float dt)
{
	
	Transform* transform;
	transform = &ECS.getComponentFromEntity<Transform>(owner_);
	

	transform->translate(xspeed * dt, yspeed * dt, 0);
	
	if (transform->position().x >3 || transform->position().x < -7) {
		xspeed = xspeed * -1;
	}
	if (transform->position().y > 7 || transform->position().y < 0) {
		yspeed = yspeed * -1;
	}
	
}

void BallMovement::init()
{

}