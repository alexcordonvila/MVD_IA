#include "MoveScript.h"
#include "extern.h"
//Player paddle movement script
void MoveScript::update(float dt)
{
	Transform* transform;
	
	
	Collider& collider_paddle = ECS.getComponentFromEntity<Collider>(owner_);
	
	transform = &ECS.getComponentFromEntity<Transform>(owner_);

	if (collider_paddle.colliding) {
	}
	else {
	}
	if (input_->GetKey(GLFW_KEY_W))
	//	if (transform->position().y >= 2 && transform->position().y <= 6) 
			transform->translate(0, yspeed * dt, 0);
	
	if (input_->GetKey(GLFW_KEY_S))
		//if (transform->position().y >= 2 && transform->position().y <= 6) 
			transform->translate(0, -yspeed * dt, 0);	
}




