#include "BallMovement.h"
#include "extern.h"

bool hitFlag = true;
int CPUscore = 0;
int Playerscore = 0;
//Ball movement script
void BallMovement::update(float dt)
{

	Collider& collider_paddle = ECS.getComponentFromEntity<Collider>(owner_);
	Transform* transform;
	transform = &ECS.getComponentFromEntity<Transform>(owner_);
	float y_coll_point = collider_paddle.collision_point.y; //hit point bwteen paddles and puck
	y_pos = transform->position().y; //ball y position
	
	transform->translate(xspeed * dt, yspeed * dt, 0); //Ball movement
	this->paddleai_->ypos = transform->position().y; //AI paddle needs this variable
	if (input_->GetKey(GLFW_KEY_Z))
		//transform->translate(-1 * dt, 0, 0);
		transform->translate(0, -1 * dt, 0);
	if (input_->GetKey(GLFW_KEY_X))
		//transform->translate(1 * dt, 0, 0);
		transform->translate(0, 1 * dt, 0);
	//if the ball puck with the paddle at certain distance
	if (collider_paddle.collision_distance < 0.5f && hitFlag == true) {
		float diff = y_pos - y_coll_point;
		int dir; //set puck direction positive or negative
		int angledir = 1; //set angle positive or negative
		
		std::cout << "DIFF : " << diff << "\n";
		if (xspeed > 0) { dir = -1; }
					else { dir = 1; }
		if (diff > 0) { angledir = 1; }
					else { angledir = -1; }

		if (abs(diff) >= segment2 && abs(diff) <= segment3) {
			float angle = (angledir * 45 * M_PI) / 180;
			xspeed = dir * 5 * cos(angle);
			yspeed = dir * 5 * sin(angle);
		}
		if (abs(diff) >= segment1 && abs(diff) < segment2) {
			float angle = (angledir * 30 * M_PI) / 180;
			xspeed = dir * 5 * cos(angle);
			yspeed = dir * 5 * sin(angle);
		}
		if (abs(diff) >= segment0 && abs(diff) < segment1) {
			float angle = (angledir * 0 * M_PI) / 180;
			xspeed = dir * 5 * cos(angle);
			yspeed = dir * 5 * sin(angle);
		}
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
		if (transform->position().x > 3) Playerscore++;
		if (transform->position().x < -7) CPUscore++;
		reset(transform);
		
	}
	if (transform->position().y > 7 || transform->position().y < 0) {
		yspeed = yspeed * -1;
		//transform->position(-2.0f, 3.0f, -10.0f);
	}

	
}
//Returns the puck back to the center
void BallMovement::reset(Transform* transform) {
	//We generate random values 
	srand((unsigned)time(NULL));
	for (int i = 0; i < 5; i++) angle = (float)rand() / RAND_MAX; 
	cout << (float)rand() / RAND_MAX << endl;
	if (angle >0.5f) {
		xspeed = -5 * cos(angle * (M_PI / 4));
	//	yspeed = 5 * sin(angle * ((M_PI) / 4));
	}
	else {
		xspeed = 5 * cos(angle * (M_PI / 4));
	//	yspeed = 5 * sin(angle * ((M_PI) / 4));
	}
	
	std::cout << "Player Score : " << Playerscore << "\n";
	std::cout << "CPU Score : " << CPUscore << "\n";
	transform->position(-2.0f, 3.0f, -10.0f);
}
void BallMovement::init(PaddleAI* paddleai_)
{
	this->paddleai_ = paddleai_;
}