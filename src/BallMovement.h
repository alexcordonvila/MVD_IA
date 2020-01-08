#pragma once
#include "ScriptSystem.h"
#include "PaddleAI.h"
#include "extern.h"
#include <time.h> 

class BallMovement :
	public Script
{
public:
	BallMovement(int owner) : Script(owner) {}
	void update(float dt);
	void init(PaddleAI* paddleAI);
	//add whatever custom funcitons and properties here!
	void reset(Transform* transform);
	
	float  PI = 3.141f;  /* pi */

	float segment3 = 0.8;
	float segment2 = 0.5;
	float segment1 = 0.2;
	float segment0 = 0.0;
	float angle;
	float y_pos = 3.0f ;
	float xspeed = 3.0f;
	float yspeed = 0.0f;
	bool hitFlag = true;
	int CPUscore = 0;
	int Playerscore = 0;
	float timeleft = 1.0f;
	bool canMove = true; //makes the ball stop until "timeleft" 
	PaddleAI* paddleai_;
	
	
};
