#include "PaddleAI.h"
#include "extern.h"

void PaddleAI::update(float dt)
{
	//ypos is a variable modified from the puck to obtain its position constantly
	//We also want to know where the player's paddle is
	Transform* transform;
	transform = &ECS.getComponentFromEntity<Transform>(owner_);

	//transform->position(transform->position().x, ypos, transform->position().z); //if alone, this is an unbeatable AI
	sense(transform->position().y, ypos, y_player_pos, dt);

	if (reset == true) {
		transform->position(2.0f, 3.0f, -10.0f);
		reset = false;
	}
}
void PaddleAI::sense(float CPUpos, float ballpos, float playerpos, float dt) //Here we only recieve data
{
	//printf("Ditancia Enemic i bola = %f\n", (CPUpos - ballpos));
	if (ball_direction == 1) {
		think(CPUpos, ballpos, playerpos, dt);
	}
}
void PaddleAI::think(float CPUpos, float ballpos, float playerpos, float dt) //Here we only choose the behaviour
{
	cpu_player_dist = abs(playerpos - CPUpos); // Y distance difference between cpu and player

	//if cpu_player_dist is greater than 0.5 -> change hit puck strategy
	if (cpu_player_dist <= 0.4f) { //If player and CPU are in a near "y" position
		if (CPUpos > 4.0f) { // if we are avobe of the "y" screen center
			act2(yspeed, 1, CPUpos, ballpos, dt); //The AI tries to hit the ball downward
		}
		if (CPUpos < 2.5f) { // if we are beyond of the "y" screen center
			act2(yspeed, 0, CPUpos, ballpos, dt); //The AI tries to hit the ball upward
		}
		if (CPUpos >= 2.5f && CPUpos <= 4.0f) {
			//TODO: CREATE A RANDOM VALUE BETWEEN 0 and 1
			srand((unsigned)time(NULL));
			for (int i = 0; i < 5; i++) random_val = (float)rand() / RAND_MAX;
			if (random_val > 0.5f) {
				act2(yspeed, 3, CPUpos, ballpos, dt); //The AI tries to hit the ball upward or downward randomly
			}
			else {
				act2(yspeed, 3, CPUpos, ballpos, dt);
			}
		}
	}
	else {			//If player and CPU are in a far "y" position AI try to hit the ball forward
		if (ballpos >= CPUpos) {

			act(yspeed, 1.0f, dt);
		}
		if (ballpos == CPUpos) {

			act(0.0, -1.0f, dt);
		}
		if (ballpos <= CPUpos) {

			act(yspeed, -1.0f, dt);
		}
	}

}
void PaddleAI::act(float yspeed, float dir, float dt) //Here we only move the CPU paddle
{
	transform->translate(0, yspeed * dir * dt, 0);
	
}
void PaddleAI::act2(float yspeed, int zone, float CPUpos, float ballpos, float dt) //Here we move the CPU paddle to hit with the zone 3 thepuck
{
	float cpu_ball_dist = abs(CPUpos - ballpos);
	if (zone == 1) {
		if (cpu_ball_dist > 0.5f) {
			transform->translate(0, yspeed * 1.0 * dt, 0);
		}else if (cpu_ball_dist < 0.5f) {
			transform->translate(0, yspeed * -1.0 * dt, 0);
		}
	}
	if (zone == 0) {
		if (cpu_ball_dist < 0.5f) {
			transform->translate(0, yspeed * 1.0 * dt, 0);
		}
		else if (cpu_ball_dist > 0.5f) {
			transform->translate(0, yspeed * -1.0 * dt, 0);
		}
		else {

		}
	}
	if (zone == 3) {
			if (cpu_ball_dist < 0.4f) { 
				float rnd = rand() % 100 + 1;
				if (rnd >50) {
					transform->translate(0, yspeed * -1.0 * dt, 0);
				}
				else {
					transform->translate(0, yspeed * 1.0 * dt, 0);
				}
			}
			else  {
				if ((CPUpos - ballpos) > 0){
					transform->translate(0, yspeed * -1.0 * dt, 0);
				}
				else if ((CPUpos - ballpos) < 0) {
					transform->translate(0, yspeed * 1.0 * dt, 0);
				}
			}
	}
}

//void PaddleAI::init(MoveScript* movescript_)
//{
//	this->movescript_ = movescript_;
//}
