#include "MoveScript.h"
#include "extern.h"
void MoveScript::update(float dt)
{
	Transform* trans;

	

	trans = &ECS.getComponentFromEntity<Transform>(owner_);
	if (input_->GetKey(GLFW_KEY_F))
		trans->translate(0, 1 * dt, 0);


	if (input_->GetKey(GLFW_KEY_V))
		trans->translate(0, -1 * dt, 0);
	/*
	if (input_->GetKey(GLFW_KEY_U))
		shouldMove = true;

	if (input_->GetKey(GLFW_KEY_J))
		shouldMove = false;

	if (shouldMove)
		trans->translate(1 * dt, 0, 0);
		*/
}




