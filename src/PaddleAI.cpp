#include "PaddleAI.h"
#include "extern.h"

void PaddleAI::update(float dt)
{
	//ypos is a variable modified from the puck to obtain its position constantly
	//We also want to know where the player's paddle is
	Transform* transform;
	transform = &ECS.getComponentFromEntity<Transform>(owner_);
	
	//transform->translate(0, ypos * dt, 0);

	//transform->position(transform->position().x, ypos, transform->position().z); //if alone, this is an unbeatable AI
	sense(transform->position().y, ypos, 0.0f,dt);
	/*if (ypos > transform->position().y) {
		transform->translate(0, yspeed * dt, 0);
	}
	if (ypos < transform->position().y) {
		transform->translate(0, -yspeed * dt, 0);
	}*/


}
void PaddleAI::sense(float CPUpos, float ballpos,float playerpos, float dt) //Here we only recieve data
{
	think(CPUpos, ballpos, playerpos, dt);
}
void PaddleAI::think(float CPUpos, float ballpos, float playerpos, float dt) //Here we only choose the behaviour
{
	if (ballpos >= CPUpos) {

		act(yspeed,1.0f,dt);
	}
	if (ballpos == CPUpos) {

		act(0.0, -1.0f, dt);
	}
	if (ballpos <= CPUpos) {

		act(yspeed, -1.0f, dt);
	}
}
void PaddleAI::act(float yspeed, float dir, float dt) //Here we only move the CPU paddle
{
	transform->translate(0, yspeed * dir * dt, 0);

	
}
//void PaddleAI::init(BallMovement* ballmovement)
//{
//	this->ballmovement_ = ballmovement;
//}