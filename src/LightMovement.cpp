#include "LightMovement.h"
#include "extern.h"
//Player paddle movement script
void LightMovement::update(float dt)
{
	Transform* transform;


	Collider& collider_paddle = ECS.getComponentFromEntity<Collider>(owner_);

	transform = &ECS.getComponentFromEntity<Transform>(owner_);
	//transform->translate(xpos * dt, ypos * dt, 0); //Ball movement
	
}


