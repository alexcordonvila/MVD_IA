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
	if (collider_paddle.collision_distance < 1.0f && hitFlag == true) {
		//std::cout << "collision at : " <<collider_paddle.collision_point.y << "\n";
		//std::cout << "Ball Position Y : " << transform->position().y << "\n";
		xspeed = xspeed * -1;
		if (round(y_pos)  > round(y_coll_point)) {
			yspeed = yspeed * -1;
		}
		else if(round(y_pos) <= round(y_coll_point)){
			//yspeed = yspeed * -1;
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
		yspeed = 5 * sin(angle * ((M_PI) / 4));
	}
	else {
		xspeed = 5 * cos(angle * (M_PI / 4));
		yspeed = 5 * sin(angle * ((M_PI) / 4));
	}
	
	std::cout << "Player Score : " << Playerscore << "\n";
	std::cout << "CPU Score : " << CPUscore << "\n";
	transform->position(-2.0f, 3.0f, -10.0f);
}
void BallMovement::init(PaddleAI* paddleai_)
{
	this->paddleai_ = paddleai_;
}